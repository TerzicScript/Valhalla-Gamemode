/*
	Delayed kick & ban Include (delaykickban.inc)
	* Now fixes kick & ban functions
	* Allow you to show messages, textdraws and so on with kick/ban functions

 	Author: (creator)
	* Gammix

	(c) Copyright 2015
  	* This file is provided as is (no warranties).
*/
/*
FUNCTIONS:
native Kick(playerid, delay = -1);
native Ban(playerid, delay = -1);
native BanEx(playerid, reason[], delay = -1);
*/

#define DELAY_DEBUG

stock Delay_Kick(playerid, delay = -1)
{
	if(GetPVarType(playerid, "Delay_Timer") != -1)
 	{
  		KillTimer(GetPVarInt(playerid, "Delay_Timer"));
    }

    new
		time_established = ((delay == -1) ? (GetPlayerPing(playerid) + 10) : delay),
		player_name[MAX_PLAYER_NAME]
	;
	GetPlayerName(playerid, player_name, MAX_PLAYER_NAME);
	SetPVarInt(playerid, "Delay_Timer", SetTimerEx("Delay_PlayerTimer", time_established, false, "iis", playerid, 1, "-"));

	#if defined DELAY_DEBUG
		printf("[Delaykickban.inc] Player %s has been kicked from the server (time established to disconnect: %i)", player_name, time_established);
	#endif
	
	return true;
}

stock Delay_Ban(playerid, delay = -1)
{
	if(GetPVarType(playerid, "Delay_Timer") != -1)
 	{
  		KillTimer(GetPVarInt(playerid, "Delay_Timer"));
    }

    new
		time_established = ((delay == -1) ? (GetPlayerPing(playerid) + 10) : delay),
		player_name[MAX_PLAYER_NAME]
	;
	GetPlayerName(playerid, player_name, MAX_PLAYER_NAME);
	SetPVarInt(playerid, "Delay_Timer", SetTimerEx("Delay_PlayerTimer", time_established, false, "iis", playerid, 2, "-"));

	#if defined DELAY_DEBUG
		printf("[Delaykickban.inc] Player %s has been banned from the server (time established to disconnect: %i)", player_name, time_established);
	#endif
	
	return true;
}

stock Delay_BanEx(playerid, const reason[], delay = -1)
{
	if(GetPVarType(playerid, "Delay_Timer") != -1)
 	{
  		KillTimer(GetPVarInt(playerid, "Delay_Timer"));
    }

    new
		time_established = ((delay == -1) ? (GetPlayerPing(playerid) + 10) : delay),
		player_name[MAX_PLAYER_NAME]
	;
	GetPlayerName(playerid, player_name, MAX_PLAYER_NAME);
	SetPVarInt(playerid, "Delay_Timer", SetTimerEx("Delay_PlayerTimer", time_established, false, "iis", playerid, 3, reason));

	#if defined DELAY_DEBUG
		printf("[Delaykickban.inc] Player %s has been banned from the server (time established to disconnect: %i | reason: %s)", player_name, time_established, reason);
	#endif
	
	return true;
}

forward Delay_PlayerTimer(playerid, type, reason[]);
public Delay_PlayerTimer(playerid, type, reason[])
{
	DeletePVar(playerid, "Delay_Timer");

	switch(type)
	{
		case 1: Kick(playerid);
		case 2: Ban(playerid);
		case 3: BanEx(playerid, reason);
	}
	return 1;
}

static Delay_IsPlayerThrown(playerid)
{
	return bool:(GetPVarType(playerid, "Delay_Timer") != -1);
}

public OnPlayerText(playerid, text[])
{
	if(Delay_IsPlayerThrown(playerid))
	{
		return 0;
	}
	
	#if defined Delay_OnPlayerText
       	return Delay_OnPlayerText(playerid, text[]);
	#else
	   	return 1;
	#endif
}
#if defined _ALS_OnPlayerText
    #undef OnPlayerText
#else
    #define _ALS_OnPlayerText
#endif
#define OnPlayerText Delay_OnPlayerText
#if defined Delay_OnPlayerText
    forward Delay_OnPlayerText(playerid, text[]);
#endif

public OnPlayerCommandText(playerid, cmdtext[])
{
	if(Delay_IsPlayerThrown(playerid))
	{
		return 0;
	}
	
	#if defined Delay_OnPlayerCommandText
       	return Delay_OnPlayerCommandText(playerid, cmdtext[]);
	#else
	   	return 1;
	#endif
}
#if defined _ALS_OnPlayerCommandText
    #undef OnPlayerCommandText
#else
    #define _ALS_OnPlayerCommandText
#endif
#define OnPlayerCommandText Delay_OnPlayerCommandText
#if defined Delay_OnPlayerCommandText
    forward Delay_OnPlayerCommandText(playerid, cmdtext[]);
#endif

// Hook Kick function
#if defined _ALS_Kick
    #undef Kick
#else
    #define _ALS_Kick
#endif
#define Kick Delay_Kick

// Hook Ban function
#if defined _ALS_Ban
    #undef Ban
#else
    #define _ALS_Ban
#endif
#define Ban Delay_Ban

// Hook BanEx function
#if defined _ALS_BanEx
    #undef BanEx
#else
    #define _ALS_BanEx
#endif
#define BanEx Delay_BanEx