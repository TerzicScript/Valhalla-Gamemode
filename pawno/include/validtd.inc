/*
	Textdraws Include (validtd.inc)
	* Now validity functions for player textdraws and global textdraws!

 	Author: (creator)
	* Gammix

	(c) Copyright 2015
  	* This file is provided as is (no warranties).
*/
/*
FUNCTIONS:
native IsValidTextDraw(Text:text);
native IsValidPlayerTextDraw(playerid, PlayerText:text);
*/

stock static TD_Set(id, set)
{
	new
	    s_String[40]
	;

	format(s_String, sizeof(s_String), "TD_%i", id);

	return setproperty(.name = s_String, .value = set);
}

stock static TD_Get(id)
{
	new
	    s_String[40]
	;

	format(s_String, sizeof(s_String), "TD_%i", id);

	return getproperty(.name = s_String);
}

stock static PTD_Set(playerid, id, set)
{
	new
	    s_String[40]
	;

	format(s_String, sizeof(s_String), "PTD_%i", id);

	return SetPVarInt(playerid, s_String, set);
}

stock static PTD_Get(id)
{
	new
	    s_String[40]
	;

	format(s_String, sizeof(s_String), "PTD_%i", id);

	return GetPVarInt(playerid, s_String);
}

stock Text:TD_TextDrawCreate(Float:x, Float:y, string[])
{
	static
		Text:g_TD  = TextDrawCreate(x, y, string);
	;

	TD_Set(_:g_TD, true);
	
    return g_TD;
}
#if defined _ALS_TextDrawCreate
    #undef TextDrawCreate
#else
    #define _ALS_TextDrawCreate
#endif
#define TextDrawCreate TD_TextDrawCreate

stock PlayerText:TD_CreatePlayerTextDraw(playerid, Float:x, Float:y, string[])
{
	static
		PlayerText:g_TD = CreatePlayerTextDraw(playerid, x, y, string)
	;

	PTD_Set(playerid, _:g_TD, true);
	
    return g_TD;
}
#if defined _ALS_CreatePlayerTextDraw
    #undef CreatePlayerTextDraw
#else
    #define _ALS_CreatePlayerTextDraw
#endif
#define CreatePlayerTextDraw TD_CreatePlayerTextDraw

stock TD_TextDrawDestroy(Text:text)
{
	if(! TD_Get(_:text))
	{
		return false;
	}
		
	TD_Set(_:text, false);
	
    return TextDrawDestroy(text);
}
#if defined _ALS_TextDrawDestroy
    #undef TextDrawDestroy
#else
    #define _ALS_TextDrawDestroy
#endif
#define TextDrawDestroy TD_TextDrawDestroy

stock TD_PlayerTextDrawDestroy(playerid, PlayerText:text)
{
	if(! PTD_Get(playerid, _:text))
	{
		return false;
	}
	
	PTD_Set(playerid, _:text, false);
    return PlayerTextDrawDestroy(playerid, text);
}
#if defined _ALS_PlayerTextDrawDestroy
    #undef PlayerTextDrawDestroy
#else
    #define _ALS_PlayerTextDrawDestroy
#endif
#define PlayerTextDrawDestroy TD_PlayerTextDrawDestroy

stock IsValidTextDraw(Text:text)
{
	return TD_Get(_:text);
}

stock IsValidPlayerTextDraw(playerid, PlayerText:text)
{
	return PTD_Get(playerid, _:text);
}

#if ! defined FILTERSCRIPT

	public OnGameModeExit()
	{
		for(new i; i < MAX_TEXT_DRAWS; i++)
		{
		    TextDrawDestroy(Text:i);
		}

    	#if defined TD_OnGameModeExit
        	return TD_OnGameModeExit();
	    #else
	    	return 1;
	    #endif
	}
	#if defined _ALS_OnGameModeExit
	    #undef OnGameModeExit
	#else
	    #define _ALS_OnGameModeExit
	#endif
	#define OnGameModeExit TD_OnGameModeExit
	#if defined TD_OnGameModeExit
	    forward TD_OnGameModeExit();
	#endif
	
#endif