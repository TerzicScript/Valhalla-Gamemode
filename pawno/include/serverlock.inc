#include <a_samp>

/*
	Server lock Include (serverlock.inc)
	* Is your server locked or under maintanace(!) or any other status, try this include. Its creative!

 	Author: (creator)
	* Gammix

	(c) Copyright 2015
  	* This file is provided as is (no warranties).
*/

/*
FUNCTIONS:
native ToggleLock(bool:toggle, desc[] = "~r~Server Locked", style = 0);
native IsLockToggled();

CALLBACKS:
public OnPlayerForcedLock(playerid)
*/

static bool:gServerStatus;
static Text:gServerStatusTD[3];

//internal function
static stock Text:LOCK_TextDrawAdd(Float:posX, Float:posY, string[], bgcolor, font, Float:lettersizeX, Float:lettersizeY, textcolor, allign = 0, outline = 1, bool:proportional = true, shadow = 1, bool:usebox = false, boxcolor = 0, Float:textsizeX = -1.0, Float:textsizeY = -1.0, model = 0, Float:rotX = 0.0, Float:rotY = 0.0, Float:rotZ = 0.0, Float:zoom = 1.0)
{
	static Text:gTextDraw;
    gTextDraw = TextDrawCreate(posX, posY, string);
	TextDrawBackgroundColor(gTextDraw, bgcolor);
	TextDrawFont(gTextDraw, font);
	TextDrawLetterSize(gTextDraw, lettersizeX, lettersizeY);
	TextDrawColor(gTextDraw, textcolor);
	TextDrawAlignment(gTextDraw, allign);
	TextDrawSetOutline(gTextDraw, outline);
	TextDrawSetProportional(gTextDraw, proportional);
	TextDrawSetShadow(gTextDraw, shadow);
	TextDrawUseBox(gTextDraw, usebox);
	if(usebox) TextDrawBoxColor(gTextDraw, boxcolor);
	if(textsizeX != -1.0 && textsizeY != -1.0) TextDrawTextSize(gTextDraw, textsizeX, textsizeY);
	if(font == 5)
	{
		TextDrawSetPreviewModel(gTextDraw, model);
		TextDrawSetPreviewRot(gTextDraw, rotX, rotY, rotZ, zoom);
	}
	return gTextDraw;
}

//Note: if you use this in a filterscript, please define "FILTERSCRIPT" in your script
#if defined FILTERSCRIPT// if used in a filterscript

	public OnFilterScriptExit()
	{
	    for(new i; i < 3; i++)
		{
		    TextDrawHideForAll(gServerStatusTD[i]);
		    TextDrawDestroy(gServerStatusTD[i]);
		}

	    #if defined Lock_OnFilterScriptExit
        	return Lock_OnFilterScriptExit();
	    #else
	    	return 1;
	    #endif
	}
	#if defined _ALS_OnFilterScriptExit
	    #undef OnFilterScriptExit
	#else
	    #define _ALS_OnFilterScriptExit
	#endif
	#define OnFilterScriptExit Lock_OnFilterScriptExit
	#if defined Lock_OnFilterScriptExit
	    forward Lock_OnFilterScriptExit();
	#endif

#else// if used in a gamemode

	public OnGameModeExit()
	{
	    for(new i; i < 3; i++)
		{
		    TextDrawHideForAll(gServerStatusTD[i]);
		    TextDrawDestroy(gServerStatusTD[i]);
		}

	    #if defined Lock_OnGameModeExit
        	return Lock_OnGameModeExit();
	    #else
	    	return 1;
	    #endif
	}
	#if defined _ALS_OnGameModeExit
	    #undef OnGameModeExit
	#else
	    #define _ALS_OnGameModeExit
	#endif
	#define OnGameModeExit Lock_OnGameModeExit
	#if defined Lock_OnGameModeExit
	    forward Lock_OnGameModeExit();
	#endif

#endif

public OnPlayerConnect(playerid)
{
	if(gServerStatus)
	{
	    if(CallLocalFunction("OnPlayerForcedLock", "i", playerid))
     	{
			TogglePlayerSpectating(playerid, true);
   			for(new x; x < 3; x++) TextDrawShowForPlayer(playerid, gServerStatusTD[x]);
      	}
	}
	
    #if defined Lock_OnPlayerConnect
       	return Lock_OnPlayerConnect(playerid);
	#else
	   	return 1;
	#endif
}
#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect Lock_OnPlayerConnect
#if defined Lock_OnPlayerConnect
    forward Lock_OnPlayerConnect(playerid);
#endif

public OnPlayerDisconnect(playerid, reason)
{
	for(new i; i < 3; i++) TextDrawHideForPlayer(playerid, gServerStatusTD[i]);
	
	#if defined Lock_OnPlayerDisconnect
       	return Lock_OnPlayerDisconnect(playerid, reason);
	#else
	   	return 1;
	#endif
}
#if defined _ALS_OnPlayerDisconnect
    #undef OnPlayerDisconnect
#else
    #define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect Lock_OnPlayerDisconnect
#if defined Lock_OnPlayerDisconnect
    forward Lock_OnPlayerDisconnect(playerid, reason);
#endif

stock ToggleLock(bool:toggle, desc[] = "~r~Server Locked", style = 0)
{
	if(gServerStatus)
	{
		for(new i; i < 3; i++)
		{
		    TextDrawHideForAll(gServerStatusTD[i]);
		    TextDrawDestroy(gServerStatusTD[i]);
		}
	}
	if(toggle)
	{
	    //background black
	    gServerStatusTD[0] = LOCK_TextDrawAdd(0.000000, 0.000000, "bg", 255, 1, 0.000000, 51.000000, -1, 1, 0, true, 1, true, 255, 650.000000, 0.000000);
		//model
		switch(style)
		{
		    case 0: gServerStatusTD[1] = LOCK_TextDrawAdd(170.000000, 170.000000, "model", 0, 5, 0.500000, 1.000000, -1, 1, 0, true, 1, true, 0, 281.000000, 271.000000, 1423, 0.0, 0.0, 0.0, 1.0);
		    case 1: gServerStatusTD[1] = LOCK_TextDrawAdd(170.000000, 170.000000, "model", 0, 5, 0.500000, 1.000000, -1, 1, 0, true, 1, true, 0, 281.000000, 271.000000, 1427, 0.0, 0.0, 0.0, 1.0);
		    case 2: gServerStatusTD[1] = LOCK_TextDrawAdd(170.000000, 170.000000, "model", 0, 5, 0.500000, 1.000000, -1, 1, 0, true, 1, true, 0, 281.000000, 271.000000, 1424, 0.0, 0.0, 0.0, 1.0);
		}
		//description
		switch(style)
		{
		    case 0: gServerStatusTD[2] = LOCK_TextDrawAdd(313.000000, 300.000000, desc, 255, 2, 0.220000, 1.799999, -1, 2, 1);
		    case 1: gServerStatusTD[2] = LOCK_TextDrawAdd(313.000000, 268.000000, desc, 255, 2, 0.220000, 1.799999, -1, 2, 1);
		    case 2: gServerStatusTD[2] = LOCK_TextDrawAdd(313.000000, 263.000000, desc, 255, 2, 0.220000, 1.799999, -1, 2, 1);
		}

		for(new i; i < MAX_PLAYERS; i++)
		{
		    if(IsPlayerConnected(i))
		    {
		        if(CallLocalFunction("OnPlayerForcedLock", "i", i))
		        {
				TogglePlayerSpectating(i, true);
				for(new x; x< 3; x++) TextDrawShowForPlayer(i, gServerStatusTD[x]);	            
		        }
		    }
		}
	}
	else
	{
        for(new i; i < MAX_PLAYERS; i++)
		{
		    if(IsPlayerConnected(i))
		    {
		        TogglePlayerSpectating(i, false);
		    }
		}
	}
	gServerStatus = toggle;
	return true;
}

stock IsLockToggled()
{
	return gServerStatus;
}

forward OnPlayerForcedLock(playerid);