/*
	Ban Include (gban.inc)
	* A simple SQLITE based BAN system; Works for IP as well as Username
	* If 'days' param is set to 0, that means a permanent BAN!

 	Author: (creator)
	* Gammix

	(c) Copyright 2015
  	* This file is provided as is (no warranties).
*/

/*
FUNCTIONS:
native BanPlayer(playername[], days = 0, reason[], banby[] = "Server");
native IsPlayerBanned(playername[]);
native UnbanPlayer(playername[]);
native RetrievePlayerBan(playername[], ip[], banby[], reason[], banon[], &type, &expire);
native BanIP(ip[], days = 0, reason[], banby[] = "Server");
native IsIPBanned(ip[]);
native UnbanIP(ip[]);
native RetrieveIPBan(ip[], playername[], banby[], reason[], banon[], &type, &expire);

CALLBACKS:
public OnBannedPlayerConnect(playerid, bantype)
public OnBannedIPConnect(ip[], bantype)
*/

#define LOCATION_BANS       "bans.db"//the database name where all the bans will be saved!

#define BAN_TYPE_PERMENANT  0
#define BAN_TYPE_TEMPORARY  1

static DB:Database;
static DBResult:Result;

//internal functions
stock static BAN_ReturnPlayerName(playerid)
{
	new player_name[MAX_PLAYER_NAME];
	GetPlayerName(playerid, player_name, MAX_PLAYER_NAME);
	return player_name;
}

stock static BAN_ReturnPlayerIP(playerid)
{
	new player_ip[18];
	GetPlayerIp(playerid, player_ip, sizeof(player_ip));
	return player_ip;
}

//delay kick
stock static DelayKick(playerid) return SetTimerEx("OnPlayerKicked", (100 + GetPlayerPing(playerid)), false, "i", playerid);

forward OnPlayerKicked(playerid);
public OnPlayerKicked(playerid) return Kick(playerid);

//Note: if you use this in a filterscript, please define "FILTERSCRIPT" in your script
#if defined FILTERSCRIPT// if used in a filterscript

	public OnFilterScriptInit()
	{
	    Database = db_open(LOCATION_BANS);
		Result = db_query(	Database,
							"CREATE TABLE IF NOT EXISTS `bans` \
							(`name` TEXT, \
							`ip` TEXT, \
							`banby` TEXT, \
							`banon` TEXT, \
							`reason` TEXT, \
							`expire` NUMERIC)"
						);
		db_free_result(Result);

	    return CallLocalFunction("BAN_OnFilterScriptInit", "");
	}
	#if defined _ALS_OnFilterScriptInit
		#undef OnFilterScriptInit
	#else
		#define _ALS_OnFilterScriptInit
	#endif
	#define OnFilterScriptInit BAN_OnFilterScriptInit
	forward BAN_OnFilterScriptInit();

	public OnFilterScriptExit()
	{
		db_close(Database);

	    return CallLocalFunction("BAN_OnFilterScriptExit", "");
	}
	#if defined _ALS_OnFilterScriptExit
		#undef OnFilterScriptExit
	#else
		#define _ALS_OnFilterScriptExit
	#endif
	#define OnFilterScriptExit BAN_OnFilterScriptExit
	forward BAN_OnFilterScriptExit();

#else// if used in a gamemode

	public OnGameModeInit()
	{
	    Database = db_open(LOCATION_BANS);
		Result = db_query(	Database,
							"CREATE TABLE IF NOT EXISTS `bans` \
							(`name` TEXT, \
							`ip` TEXT, \
							`banby` TEXT, \
							`banon` TEXT, \
							`reason` TEXT, \
							`expire` NUMERIC)"
						);
		db_free_result(Result);

	    return CallLocalFunction("BAN_OnGameModeInit", "");
	}
	#if defined _ALS_OnGameModeInit
		#undef OnGameModeInit
	#else
		#define _ALS_OnGameModeInit
	#endif
	#define OnGameModeInit BAN_OnGameModeInit
	forward BAN_OnGameModeInit();

	public OnGameModeExit()
	{
		db_close(Database);

	    return CallLocalFunction("BAN_OnGameModeExit", "");
	}
	#if defined _ALS_OnGameModeExit
		#undef OnGameModeExit
	#else
		#define _ALS_OnGameModeExit
	#endif
	#define OnGameModeExit BAN_OnGameModeExit
	forward BAN_OnGameModeExit();

#endif

stock BanPlayer(playername[], days = 0, reason[], banby[] = "Server")
{
    static bandate[18], date[3], Query[256], time;
	getdate(date[0], date[1], date[2]);
	format(bandate, sizeof(bandate), "%02i/%02i/%i", date[2], date[1], date[0]);

	if(days == 0) time = 0;
	else time = ((days * 24 * 60 * 60) + gettime());

	format(	Query,
			sizeof(Query),
			"INSERT INTO `bans` (`name`, `ip`, `banby`, `banon`, `reason`, `expire`) VALUES ('%s','%s','%s','%s','%s','%d')",
			playername,
			"",
			banby,
			bandate,
			reason,
			time
		);
 	Result = db_query(Database, Query);
	db_free_result(Result);
	return DelayKick(playerid);
}

stock IsPlayerBanned(playername[])
{
    static Query[198];
	format(	Query,
			sizeof(Query),
			"SELECT * FROM `bans` WHERE `name` = '%s'",
			playername
		);
	Result = db_query(Database, Query);

	if(! db_num_rows(Result))
	{
		db_free_result(Result);
		return false;
	}
	db_free_result(Result);
	return true;
}

stock UnbanPlayer(playername[])
{
    static Query[198];
	format(	Query,
			sizeof(Query),
			"DELETE FROM `bans` WHERE `name` = '%s'",
			playername
		);
	Result = db_query(Database, Query);
	db_free_result(Result);
	return true;
}

stock RetrievePlayerBan(playername[], ip[], banby[], reason[], banon[], &type, &expire)
{
    static Query[256];
	format(	Query,
			sizeof(Query),
			"SELECT * FROM `bans` WHERE `name` = '%s'",
			playername
		);
	Result = db_query(Database, Query);

	if(! db_num_rows(Result)) return false;

	db_get_field_assoc(Result, "ip", ip, 18);
	banby = db_get_field_assoc(Result, "banby", banby, 24);
	reason = db_get_field_assoc(Result, "reason" ,reason, 35);
	banon = db_get_field_assoc(Result, "banon" ,banon, 18);
	new Value[56];
	db_get_field_assoc(Result, "expire" ,Value, 10);
    expire = strval(Value);
	if(strval(Value) == 0) type = BAN_TYPE_PERMENANT;
	else type = BAN_TYPE_TEMPORARY;
	return true;
}

stock BanIP(ip[], days = 0, reason[], banby[] = "Server")
{
    static bandate[18], date[3], Query[256], time;
	getdate(date[0], date[1], date[2]);
	format(bandate, sizeof(bandate), "%02i/%02i/%i", date[2], date[1], date[0]);

	if(days == 0) time = 0;
	else time = ((days * 24 * 60 * 60) + gettime());

	format(	Query,
			sizeof(Query),
			"INSERT INTO `bans` (`name`, `ip`, `banby`, `banon`, `reason`, `expire`) VALUES ('N/A','%s','%s','%s','%s','%d')",
			ip,
			banby,
			bandate,
			reason,
			time
		);
 	Result = db_query(Database, Query);
	db_free_result(Result);
	
	for(new i; i < MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i))
		{
		    if(! strcmp(ip, BAN_ReturPlayerIP(i)))
		    {
		        return DelayKick(playerid);
		    }
		}
	}
	return true;
}

stock IsIPBanned(ip[])
{
    static Query[198];
	format(	Query,
			sizeof(Query),
			"SELECT * FROM `bans` WHERE `ip` = '%s'",
			ip
		);
	Result = db_query(Database, Query);

	if(! db_num_rows(Result))
	{
		db_free_result(Result);
		return false;
	}
	db_free_result(Result);
	return true;
}

stock UnbanIP(ip[])
{
    static Query[198];
	format(	Query,
			sizeof(Query),
			"DELETE FROM `bans` WHERE `ip` = '%s'",
			ip
		);
	Result = db_query(Database, Query);
	db_free_result(Result);
	return true;
}

stock RetrieveIPBan(ip[], playername[], banby[], reason[], banon[], &type, &expire)
{
    static Query[256];
	format(	Query,
			sizeof(Query),
			"SELECT * FROM `bans` WHERE `ip` = '%s'",
			ip
		);
	Result = db_query(Database, Query);

	if(! db_num_rows(Result)) return false;

	db_get_field_assoc(Result, "name", playername, MAX_PLAYER_NAME);
	db_get_field_assoc(Result, "banby", banby, MAX_PLAYER_NAME);
	db_get_field_assoc(Result, "reason" ,reason, 35);
	db_get_field_assoc(Result, "banon" ,banon, 18);
	new Value[56];
	db_get_field_assoc(Result, "expire" , Value, 10);
    expire = strval(Value);
	if(strval(Value) == 0) type = BAN_TYPE_PERMENANT;
	else type = BAN_TYPE_TEMPORARY;
	return true;
}

public OnPlayerConnect(playerid)
{
    static Query[256], Value[56];
	format(	Query,
			sizeof(Query),
			"SELECT * FROM `bans` WHERE `name` = '%s'",
			BAN_ReturnPlayerName(playerid)
		);
	Result = db_query(Database, Query);

	if(db_num_rows(Result))//if the player is banned
	{
		db_get_field_assoc(Result, "expire", Value, 10);
		if(	strval(Value) < gettime() &&
			strval(Value) != 0)
		{
		    if(CallLocalFunction("OnBannedPlayerConnect", "ii", playerid, BAN_TYPE_TEMPORARY)) return DelayKick(playerid);
			return 1;
		}
		else if(strval(Value) == 0)
		{
		    if(CallLocalFunction("OnBannedPlayerConnect", "ii", playerid, BAN_TYPE_PERMENANT)) return DelayKick(playerid);
			return 1;
		}
		else//if player ban has expired
		{
		    db_free_result(Result);
		    format(	Query,
					sizeof(Query),
					"DELETE FROM `bans` WHERE `name` = '%s'",
					BAN_ReturnPlayerName(playerid)
    			);
		    Result = db_query(Database, Query);
		}
	}

	format(	Query,
			sizeof(Query),
			"SELECT * FROM `bans` WHERE `ip` = '%s'",
			BAN_ReturnPlayerIP(playerid)
		);
	Result = db_query(Database, Query);

	if(db_num_rows(Result))//if the player is banned
	{
		db_get_field_assoc(Result, "expire", Value, 10);
		if(	strval(Value) < gettime() &&
			strval(Value) != 0)
		{
		    if(CallLocalFunction("OnBannedIPConnect", "sii", BAN_ReturnPlayerIP(playerid), playerid, BAN_TYPE_TEMPORARY)) return DelayKick(playerid);
			return 1;
		}
		else if(strval(Value) == 0)
		{
		    if(CallLocalFunction("OnBannedIPConnect", "sii", BAN_ReturnPlayerIP(playerid), playerid, BAN_TYPE_PERMENANT)) return DelayKick(playerid);
			return 1;
		}
		else//if player ban has expired
		{
		    db_free_result(Result);
		    format(	Query,
					sizeof(Query),
					"DELETE FROM `bans` WHERE `ip` = '%s'",
					BAN_ReturnPlayerIP(playerid)
    			);
		    Result = db_query(Database, Query);
		}
	}
	return CallLocalFunction("BAN_OnPlayerConnect", "i", playerid);
}
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect BAN_OnPlayerConnect
forward BAN_OnPlayerConnect(playerid);

//system callbacks
forward OnBannedPlayerConnect(playerid, bantype);
forward OnBannedIPConnect(ip[], bantype);