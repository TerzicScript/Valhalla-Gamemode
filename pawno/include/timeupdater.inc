/*
	Timeupdate Include/Timer (timeupdater.inc)
	* Just use these callbacks for all gloabl and player updates!

 	Author: (creator)
	* Gammix

	(c) Copyright 2015
  	* This file is provided as is (no warranties).
*/

/*
FUNCTIONS:
native GetConnectedTime(&hours, &minutes, &seconds);

CALLBACKS:
public OnPlayerTimeUpdate(playerid, hours, minutes, seconds)
public OnTimeUpdate(hours, minutes, seconds)
*/

static gPlayerSecondsTimer[MAX_PLAYERS];
static gGlobalSecondsTimer;
static gTimeCount[3];

//Note: if you use this in a filterscript, please define "FILTERSCRIPT" in your script
#if defined FILTERSCRIPT// if used in a filterscript

	public OnFilterScriptInit()
	{
	    if(funcidx("OnTimeUpdate") != -1)
	    {
	    	gGlobalSecondsTimer = SetTimer("OnTimeUpdate", (1 * 1000), true);
		}
		else
		{
		    gGlobalSecondsTimer = -1;
		}
	
	    return CallLocalFunction("TIMER_OnFilterScriptInit", "");
	}
	#if defined _ALS_OnFilterScriptInit
		#undef OnFilterScriptInit
	#else
		#define _ALS_OnFilterScriptInit
	#endif
	#define OnFilterScriptInit TIMER_OnFilterScriptInit
	forward TIMER_OnFilterScriptInit();

	public OnFilterScriptExit()
	{
	    KillTimer(gGlobalSecondsTimer);

	    return CallLocalFunction("TIMER_OnFilterScriptExit", "");
	}
	#if defined _ALS_OnFilterScriptExit
		#undef OnFilterScriptExit
	#else
		#define _ALS_OnFilterScriptExit
	#endif
	#define OnFilterScriptExit TIMER_OnFilterScriptExit
	forward TIMER_OnFilterScriptExit();

#else// if used in a gamemode

	public OnGameModeInit()
	{
	    if(funcidx("OnTimeUpdate") != -1)
	    {
	    	gGlobalSecondsTimer = SetTimer("OnTimeUpdate", (1 * 1000), true);
		}
		else
		{
		    gGlobalSecondsTimer = -1;
		}

	    return CallLocalFunction("TIMER_OnGameModeInit", "");
	}
	#if defined _ALS_OnGameModeInit
		#undef OnGameModeInit
	#else
		#define _ALS_OnGameModeInit
	#endif
	#define OnGameModeInit TIMER_OnGameModeInit
	forward TIMER_OnGameModeInit();

	public OnGameModeExit()
	{
	    KillTimer(gGlobalSecondsTimer);

	    return CallLocalFunction("TIMER_OnGameModeExit", "");
	}
	#if defined _ALS_OnGameModeExit
		#undef OnGameModeExit
	#else
		#define _ALS_OnGameModeExit
	#endif
	#define OnGameModeExit TIMER_OnGameModeExit
	forward TIMER_OnGameModeExit();

#endif

public OnPlayerConnect(playerid)
{
    if(funcidx("OnPlayerTimeUpdate") != -1)
    {
		gPlayerSecondsTimer[playerid] = SetTimerEx("OnPlayerTimeUpdate", (1* 1000), true, "i", playerid);
	}
	else
	{
		gPlayerSecondsTimer[playerid] = -1;
	}
	return CallLocalFunction("TIMER_OnPlayerConnect", "i", playerid);
}
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect TIMER_OnPlayerConnect
forward TIMER_OnPlayerConnect(playerid);

public OnPlayerDisconnect(playerid, reason)
{
    KillTimer(gPlayerSecondsTimer[playerid]);
	return CallLocalFunction("TIMER_OnPlayerDisconnect", "ii", playerid, reason);
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect TIMER_OnPlayerDisconnect
forward TIMER_OnPlayerDisconnect(playerid, reason);
//----
forward OnPlayerTimeUpdate(playerid);
//
forward OnTimeUpdate();
//---
public OnTimeUpdate()
{
    gTimeCount[2] += 1;
    if(gTimeCount[2] >= 60)
	{
	    gTimeCount[2] = 0;
	    gTimeCount[1] += 1;

	    if(gTimeCount[1] >= 60)
	    {
	        gTimeCount[1] = 0;
	        gTimeCount[0] += 1;
	    }
	}

	return CallLocalFunction("TIMER_OnTimeUpdate", "");
}
#if defined _ALS_OnTimeUpdate
	#undef OnTimeUpdate
#else
	#define _ALS_OnTimeUpdate
#endif
#define OnTimeUpdate TIMER_OnTimeUpdate
forward TIMER_OnTimeUpdate(hours, minutes, seconds);

stock GetConnectedTime(&hours, &minutes, &seconds)
{
	hours = gTimeCount[0];
	minutes = gTimeCount[1];
	seconds = gTimeCount[2];
	return true;
}