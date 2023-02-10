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
native GAdmin_VerifyColoumn(name[], BUD::type);
native _
native GAdmin_IsValidUser(username[]);
native GAdmin_ReturnUserID(username[]);
native GAdmin_RetrieveUserData(username[], fmat[], ...);
native GAdmin_ChangeUserData(username[], fmat[], ...);
native GAdmin_GetUserInt(username[], columnname[]);
native GAdmin_GetUserFloat(username[], columnname[]);
native GAdmin_GetUserString(username[], columnname[], str[], len = sizeof(str));
native GAdmin_SetUserInt(username[], columnname[], set);
native GAdmin_SetUserFloat(username[], columnname[], Float:set);
native GAdmin_SetUserString(username[], columnname[], str[], len = sizeof(str));
native GAdmin_DeleteUser(username[]);
native GAdmin_CreateUser(username[], password[]);
native GAdmin_IsUserAdmin(username[]);
native GAdmin_GetUserAdminLevel(username[]);
native GAdmin_SetUserAdminLevel(username[], level);
native GAdmin_IsUserVip(username[]);
native GAdmin_GetUserVipLevel(username[]);
native GAdmin_SetUserVipLevel(username[], level);
native GAdmin_IsUserLoggedIn(username[]);

CALLBACKS:
public GAdmin_OnPlayerRegister(playerid)
public GAdmin_OnPlayerLogin(playerid)
public GAdmin_OnPlayerLogout(playerid)
*/

#include <timeupdater> //Gammix
#include <BUD> //Slice

enum e_Player_Data
{
	bool:g_Logged_In,
	bool:g_Registered
};
static
	g_Player_Data[MAX_PLAYERS][e_Player_Data]
;

//------------------------------------------------

#define LOCATION_DATABASE 	"GAdmin/server.db"//the ADMIN_DATABASE name

//------------------------------------------------

//Database function(s)
#define GAdmin_VerifyColoumn \
		BUD::VerifyColumn

//some functions
stock GAdmin_IsValidUser(username[])
{
	return BUD::IsNameRegistered(username);
}

stock GAdmin_ReturnUserID(username[])
{
	return BUD::GetNameUID(username);
}

#define GAdmin_RetrieveUserData(%1,%2,%3) \
			BUD::MultiGet(GAdmin_ReturnUserID(%1),%2,%3)

#define GAdmin_ChangeUserData(%1,%2,%3) \
			BUD::MultiSet(GAdmin_ReturnUserID(%1),%2,%3)

stock GAdmin_GetUserInt(username[], columnname[])
{
	return BUD::GetIntEntry(GAdmin_ReturnUserID(username), columnname);
}

stock Float:GAdmin_GetUserFloat(username[], columnname[])
{
	return BUD::GetFloatEntry(GAdmin_ReturnUserID(username), columnname);
}

stock GAdmin_GetUserString(username[], columnname[], str[], len = sizeof(str))
{
	BUD::GetStringEntry(GAdmin_ReturnUserID(username), columnname, str, len);
	return true;
}

stock GAdmin_SetUserInt(username[], columnname[], set)
{
	return BUD::SetIntEntry(GAdmin_ReturnUserID(username), columnname, set);
}

stock GAdmin_SetUserFloat(username[], columnname[], Float:set)
{
	return BUD::SetFloatEntry(GAdmin_ReturnUserID(username), columnname, set);
}

stock GAdmin_SetUserString(username[], columnname[], str[], len = sizeof(str))
{
	BUD::SetStringEntry(GAdmin_ReturnUserID(username), columnname, str, len);
	return true;
}

stock GAdmin_DeleteUser(username[])
{
	return BUD::UnregisterName(username);
}

stock GAdmin_CreateUser(username[], password[])
{
	return BUD::RegisterName(username, password);
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
	new
		g_Player_Name[MAX_PLAYER_NAME]
	;
	GetPlayerName(playerid, g_Player_Name, MAX_PLAYER_NAME);

 	g_Player_Data[playerid][g_Logged_In] = false;
 	g_Player_Data[playerid][g_Registered] = bool:GAdmin_IsValidUser(g_Player_Name);

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
	if(g_Player_Data[playerid][g_Logged_In])
	{
		CallLocalFunction("GAdmin_OnPlayerLogout", "i", playerid);
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

public OnPlayerTimeUpdate(playerid)
{
	new
		g_Player_Name[MAX_PLAYER_NAME]
	;
	GetPlayerName(playerid, g_Player_Name, MAX_PLAYER_NAME);

	if(! g_Player_Data[playerid][g_Logged_In])
	{
	    if(GAdmin_IsUserLoggedIn(g_Player_Name))
		{
			g_Player_Data[playerid][g_Logged_In] = true;
			if(! g_Player_Data[playerid][g_Registered])
	  		{
	  		    g_Player_Data[playerid][g_Registered] = true;
		        CallLocalFunction("GAdmin_OnPlayerRegister", "i", playerid);
		    }
	     	else
		 	{
		 		CallLocalFunction("GAdmin_OnPlayerLogin", "i", playerid);
		 	}
		}
	}
	#if defined ADMIN_OnPlayerTimeUpdate
		return ADMIN_OnPlayerTimeUpdate(playerid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerTimeUpdate
	#undef OnPlayerTimeUpdate
#else
	#define _ALS_OnPlayerTimeUpdate
#endif
#define OnPlayerTimeUpdate ADMIN_OnPlayerTimeUpdate
#if defined ADMIN_OnPlayerTimeUpdate
	forward ADMIN_OnPlayerTimeUpdate(playerid);
#endif

forward GAdmin_OnPlayerRegister(playerid);
forward GAdmin_OnPlayerLogin(playerid);

stock GAdmin_IsUserAdmin(username[])
{
    new USERID = BUD::GetNameUID(username);
    if(BUD::GetIntEntry(USERID, "admin") > 0)
	{
		return true;
	}
	return false;
}

stock GAdmin_GetUserAdminLevel(username[])
{
    new USERID = BUD::GetNameUID(username);
    return BUD::GetIntEntry(USERID, "admin");
}

stock GAdmin_SetUserAdminLevel(username[], level)
{
    return GAdmin_ChangeUserData(username, "i", "admin", level);
}

stock GAdmin_IsUserVip(username[])
{
    new USERID = BUD::GetNameUID(username);
    if(BUD::GetIntEntry(USERID, "vip") > 0)
	{
		return true;
	}
	return false;
}

stock GAdmin_GetUserVipLevel(username[])
{
    new USERID = BUD::GetNameUID(username);
    return BUD::GetIntEntry(USERID, "vip");
}

stock GAdmin_SetUserVipLevel(username[], level)
{
    return GAdmin_ChangeUserData(username, "i", "vip", level);
}

stock GAdmin_IsUserLoggedIn(username[])
{
	new USERID = BUD::GetNameUID(username);
    if(BUD::GetIntEntry(USERID, "logged"))
	{
		return true;
	}
	return false;
}