/*
	GAdmin Include (gadmin.inc)
	* For the users using GAdmin filterscript, may use this include to implement useful functions in their other scripts.
	* Very useful include for integrating purposes and getting player statics from SQL base to scripts.

 	Author: (creator)
	* Gammix

	(c) Copyright 2015
  	* This file is provided as is (no warranties).
*/
/*
FUNCTIONS:
native GAdmin_IsValidPlayer(playerid, username[] = "");
native GAdmin_GetPlayerInt(playerid, const column[], username[] = "");
native Float:GAdmin_GetPlayerFloat(playerid, const column[], username[] = "");
native GAdmin_GetPlayerString(playerid, const column[], str[], len = sizeof(str), username[] = "");
native GAdmin_SetPlayerInt(playerid, const column[], set, username[] = "");
native GAdmin_SetPlayerFloat(playerid, const column[], Float:set, username[] = "");
native GAdmin_SetPlayerString(playerid, const column[], str[], len = sizeof(str), username[] = "");
native GAdmin_IsPlayerAdmin(playerid, username[] = "");
native GAdmin_IsPlayerVip(playerid, username[] = "");
native GAdmin_IsPlayerRegistered(playerid, username[] = "");
native GAdmin_IsPlayerLoggedIn(playerid, username[] = "");
native GAdmin_IsPlayerGuest(playerid, username[] = "");
native GAdmin_IsPlayerMuted(playerid, username[] = "");
native GAdmin_IsPlayerCMDMuted(playerid, username[] = "");
native GAdmin_IsPlayerJailed(playerid, username[] = "");
native GAdmin_IsPlayerGod(playerid, username[] = "");
native GAdmin_IsPlayerOnDuty(playerid, username[] = "");
native GAdmin_IsPlayerDND(playerid, username[] = "");

CALLBACKS:
public GAdmin_OnPlayerRegister(playerid)
public GAdmin_OnPlayerLogin(playerid)
public GAdmin_OnPlayerGuest(playerid)
public GAdmin_OnPlayerLogout(playerid)
*/

#include <BUD> //Slice

#define LOCATION_DATABASE 		"GAdmin/server.db" //the ADMIN_DATABASE name

enum e_ACCOUNT_DATA
{
	e_CHECK_TIMER,
	bool:e_CHECK_REGISTER
};
static
	g_AccountInfo[MAX_PLAYERS][e_ACCOUNT_DATA]
;


#define GAdmin_VerifyColoumn \
			BUD::VerifyColumn

stock static GAdmin_ReturnPlayerName(playerid)
{
	new
		s_Name[MAX_PLAYER_NAME]
	;

	GetPlayerName(playerid, s_Name, MAX_PLAYER_NAME);

	return s_Name;
}

stock static GAdmin_ReturnUserID(username[])
{
	return BUD::GetNameUID(username);
}

stock static GAdmin_ReturnPlayerID(username[])
{
	new
	    s_Name[MAX_PLAYER_NAME]
	;
	for(new i = 0, j = GetPlayerPoolSize(); i <= j; i++)
	{
	    if(IsPlayerConnected(i))
	    {
	        GetPlayerName(i, s_Name, MAX_PLAYER_NAME);

	        if(! strcmp(username, s_Name, false))
	        {
	            return i;
	        }
	    }
	}
	return INVALID_PLAYER_ID;
}

stock GAdmin_IsValidPlayer(playerid, username[] = "")
{
	if(! username[0])
	{
	    format(username, MAX_PLAYER_NAME, GAdmin_ReturnPlayerName(playerid));
	}
	return BUD::IsNameRegistered(username);
}

stock GAdmin_GetPlayerInt(playerid, const column[], username[] = "")
{
	if(! username[0])
	{
	    format(username, MAX_PLAYER_NAME, GAdmin_ReturnPlayerName(playerid));
	}
	return BUD::GetIntEntry(GAdmin_ReturnUserID(username), column);
}

stock Float:GAdmin_GetPlayerFloat(playerid, const column[], username[] = "")
{
	if(! username[0])
	{
	    format(username, MAX_PLAYER_NAME, GAdmin_ReturnPlayerName(playerid));
	}
	return BUD::GetFloatEntry(GAdmin_ReturnUserID(username), column);
}

stock GAdmin_GetPlayerString(playerid, const column[], str[], len = sizeof(str), username[] = "")
{
	if(! username[0])
	{
	    format(username, MAX_PLAYER_NAME, GAdmin_ReturnPlayerName(playerid));
	}
	BUD::GetStringEntry(GAdmin_ReturnUserID(username), column, str, len);
	return;	
}

stock GAdmin_SetPlayerInt(playerid, const column[], set, username[] = "")
{
	if(! username[0])
	{
	    format(username, MAX_PLAYER_NAME, GAdmin_ReturnPlayerName(playerid));
	}
	return BUD::SetIntEntry(GAdmin_ReturnUserID(username), column, set);
}

stock GAdmin_SetPlayerFloat(playerid, const column[], Float:set, username[] = "")
{
	if(! username[0])
	{
	    format(username, MAX_PLAYER_NAME, GAdmin_ReturnPlayerName(playerid));
	}
	return BUD::SetFloatEntry(GAdmin_ReturnUserID(username), column, set);
}

stock GAdmin_SetPlayerString(playerid, const column[], str[], len = sizeof(str), username[] = "")
{
	if(! username[0])
	{
	    format(username, MAX_PLAYER_NAME, GAdmin_ReturnPlayerName(playerid));
	}
	BUD::SetStringEntry(GAdmin_ReturnUserID(username), column, str, len);
	return;
}

stock GAdmin_IsPlayerAdmin(playerid, username[] = "")
{
	if(GAdmin_GetPlayerInt(playerid, "admin", username) >= 1)
	{
	    return true;
	}
	return false;
}

stock GAdmin_IsPlayerVip(playerid, username[] = "")
{
	if(GAdmin_GetPlayerInt(playerid, "vip", username) >= 1)
	{
	    return true;
	}
	return false;
}

stock GAdmin_IsPlayerRegistered(playerid, username[] = "")
{
	if(username[0])
	{
	    playerid = GAdmin_ReturnPlayerID(username);

	    if(playerid == INVALID_PLAYER_ID)
	    {
	        return false;
	    }
	}
	return g_AccountInfo[playerid][e_CHECK_REGISTER];
}

stock GAdmin_IsPlayerLoggedIn(playerid, username[] = "")
{
	if(username[0])
	{
	    playerid = GAdmin_ReturnPlayerID(username);

	    if(playerid == INVALID_PLAYER_ID)
	    {
	        return false;
	    }
	}
	if(GetPVarType(playerid, "GAdmin_Loggedin") != PLAYER_VARTYPE_NONE)
	{
	    return true;
	}
	return false;
}

stock GAdmin_IsPlayerGuest(playerid, username[] = "")
{
	if(username[0])
	{
	    playerid = GAdmin_ReturnPlayerID(username);

	    if(playerid == INVALID_PLAYER_ID)
	    {
	        return false;
	    }
	}
	if(GetPVarType(playerid, "GAdmin_Guest") != PLAYER_VARTYPE_NONE)
	{
	    return true;
	}
	return false;
}

stock GAdmin_IsPlayerMuted(playerid, username[] = "")
{
	if(username[0])
	{
	    playerid = GAdmin_ReturnPlayerID(username);

	    if(playerid == INVALID_PLAYER_ID)
	    {
	        return false;
	    }
	}
	if(GetPVarType(playerid, "GAdmin_Muted") != PLAYER_VARTYPE_NONE)
	{
	    return true;
	}
	return false;
}

stock GAdmin_IsPlayerCMDMuted(playerid, username[] = "")
{
	if(username[0])
	{
	    playerid = GAdmin_ReturnPlayerID(username);

	    if(playerid == INVALID_PLAYER_ID)
	    {
	        return false;
	    }
	}
	if(GetPVarType(playerid, "GAdmin_CMDMuted") != PLAYER_VARTYPE_NONE)
	{
	    return true;
	}
	return false;
}

stock GAdmin_IsPlayerJailed(playerid, username[] = "")
{
	if(username[0])
	{
	    playerid = GAdmin_ReturnPlayerID(username);

	    if(playerid == INVALID_PLAYER_ID)
	    {
	        return false;
	    }
	}
	if(GetPVarType(playerid, "GAdmin_Jailed") != PLAYER_VARTYPE_NONE)
	{
	    return true;
	}
	return false;
}

stock GAdmin_IsPlayerGod(playerid, username[] = "")
{
	if(username[0])
	{
	    playerid = GAdmin_ReturnPlayerID(username);

	    if(playerid == INVALID_PLAYER_ID)
	    {
	        return false;
	    }
	}
	if(GetPVarType(playerid, "GAdmin_God") != PLAYER_VARTYPE_NONE)
	{
	    return true;
	}
	return false;
}

stock GAdmin_IsPlayerOnDuty(playerid, username[] = "")
{
	if(username[0])
	{
	    playerid = GAdmin_ReturnPlayerID(username);

	    if(playerid == INVALID_PLAYER_ID)
	    {
	        return false;
	    }
	}
	if(GetPVarType(playerid, "GAdmin_Onduty") != PLAYER_VARTYPE_NONE)
	{
	    return true;
	}
	return false;
}

stock GAdmin_IsPlayerDND(playerid, username[] = "")
{
	if(username[0])
	{
	    playerid = GAdmin_ReturnPlayerID(username);

	    if(playerid == INVALID_PLAYER_ID)
	    {
	        return false;
	    }
	}
	if(GetPVarType(playerid, "GAdmin_Nopm") != PLAYER_VARTYPE_NONE)
	{
	    return true;
	}
	return false;
}

//lets open our DATABASE, make sure you have the same location of DB as in filterscripts
//Note: if you use this in a filterscript, please define "FILTERSCRIPT" in your script
#if defined FILTERSCRIPT// if used in a filterscript

	public OnFilterScriptInit()
	{
		BUD::Setting(opt.Database, LOCATION_DATABASE);
		BUD::Setting(opt.KeepAliveTime, 3000);
		BUD::Initialize();

	    #if defined ADMIN_OnFilterScriptInit
			return ADMIN_OnFilterScriptInit();
		#else
			return 1;
		#endif
	}
	#if defined _ALS_OnFilterScriptInit
		#undef OnFilterScriptInit
	#else
		#define _ALS_OnFilterScriptInit
	#endif
	#define OnFilterScriptInit ADMIN_OnFilterScriptInit
	#if defined ADMIN_OnFilterScriptInit
		forward ADMIN_OnFilterScriptInit();
	#endif

	public OnFilterScriptExit()
	{
		BUD::Exit();

	    #if defined ADMIN_OnFilterScriptExit
			return ADMIN_OnFilterScriptExit();
		#else
			return 1;
		#endif
	}
	#if defined _ALS_OnFilterScriptExit
		#undef OnFilterScriptExit
	#else
		#define _ALS_OnFilterScriptExit
	#endif
	#define OnFilterScriptExit ADMIN_OnFilterScriptExit
	#if defined ADMIN_OnFilterScriptExit
		forward ADMIN_OnFilterScriptExit();
	#endif

#else// if used in a gamemode

	public OnGameModeInit()
	{
		BUD::Setting(opt.Database, LOCATION_DATABASE);
		BUD::Setting(opt.KeepAliveTime, 3000);
		BUD::Initialize();

	    #if defined ADMIN_OnGameModeInit
			return ADMIN_OnGameModeInit();
		#else
			return 1;
		#endif
	}
	#if defined _ALS_OnGameModeInit
		#undef OnGameModeInit
	#else
		#define _ALS_OnGameModeInit
	#endif
	#define OnGameModeInit ADMIN_OnGameModeInit
	#if defined ADMIN_OnGameModeInit
		forward ADMIN_OnGameModeInit();
	#endif

	public OnGameModeExit()
	{
		BUD::Exit();

	    #if defined ADMIN_OnGameModeExit
			return ADMIN_OnGameModeExit();
		#else
			return 1;
		#endif
	}
	#if defined _ALS_OnGameModeExit
		#undef OnGameModeExit
	#else
		#define _ALS_OnGameModeExit
	#endif
	#define OnGameModeExit ADMIN_OnGameModeExit
	#if defined ADMIN_OnGameModeExit
		forward ADMIN_OnGameModeExit();
	#endif

#endif

public OnPlayerConnect(playerid)
{
	g_AccountInfo[playerid][e_CHECK_TIMER] = SetTimerEx("GAdmin_OnPlayerUpdate", 250, true, "i", playerid);
	g_AccountInfo[playerid][e_CHECK_REGISTER] = BUD::IsNameRegistered(GAdmin_ReturnPlayerName(playerid));

    #if defined ADMIN_OnPlayerConnect
		return ADMIN_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect ADMIN_OnPlayerConnect
#if defined ADMIN_OnPlayerConnect
	forward ADMIN_OnPlayerConnect(playerid);
#endif

public OnPlayerDisconnect(playerid, reason)
{
	if(g_AccountInfo[playerid][e_CHECK_TIMER] != -1)
	{
		KillTimer(g_AccountInfo[playerid][e_CHECK_TIMER]);
	}
	g_AccountInfo[playerid][e_CHECK_TIMER] = -1;

	if(g_AccountInfo[playerid][e_CHECK_REGISTER])
	{
	    CallLocalFunction("GAdmin_OnPlayerLogout", "i", playerid);
		g_AccountInfo[playerid][e_CHECK_REGISTER] = false;
	}

    #if defined ADMIN_OnPlayerDisconnect
		return ADMIN_OnPlayerDisconnect(playerid, reason);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect ADMIN_OnPlayerDisconnect
#if defined ADMIN_OnPlayerDisconnect
	forward ADMIN_OnPlayerDisconnect(playerid, reason);
#endif

forward GAdmin_OnPlayerLogout(playerid);

forward GAdmin_OnPlayerUpdate(playerid);
public GAdmin_OnPlayerUpdate(playerid)
{
	if(GetPVarType(playerid, "GAdmin_Loggedin") != PLAYER_VARTYPE_NONE)
	{
		if(! g_AccountInfo[playerid][e_CHECK_REGISTER])
	  	{
	  	    g_AccountInfo[playerid][e_CHECK_REGISTER] = true;
		    CallLocalFunction("GAdmin_OnPlayerRegister", "i", playerid);

		    KillTimer(g_AccountInfo[playerid][e_CHECK_TIMER]);
			g_AccountInfo[playerid][e_CHECK_TIMER] = -1;
   		}
	    else
		{
	  	    g_AccountInfo[playerid][e_CHECK_REGISTER] = true;
		 	CallLocalFunction("GAdmin_OnPlayerLogin", "i", playerid);

	        KillTimer(g_AccountInfo[playerid][e_CHECK_TIMER]);
			g_AccountInfo[playerid][e_CHECK_TIMER] = -1;
	 	}
	}
	else if(GetPVarType(playerid, "GAdmin_Guest") != PLAYER_VARTYPE_NONE)
	{
  		g_AccountInfo[playerid][e_CHECK_REGISTER] = false;
	 	CallLocalFunction("GAdmin_OnPlayerGuest", "i", playerid);

        KillTimer(g_AccountInfo[playerid][e_CHECK_TIMER]);
		g_AccountInfo[playerid][e_CHECK_TIMER] = -1;
	}

	return 1;
}

forward GAdmin_OnPlayerRegister(playerid);
forward GAdmin_OnPlayerLogin(playerid);
forward GAdmin_OnPlayerGuest(playerid);