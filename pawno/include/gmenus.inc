/*
	GMenus Include (gmenus.inc)
	* I am good in textdraws and here i represent you my unique menus include.
	* Scheme similar to GTA SA menus but design relevant to GTA V!
	* And customizable per player!

 	Author: (creator)
	* Gammix

	(c) Copyright 2015
  	* This file is provided as is (no warranties).
*/

/*
FUNCTIONS:
native Menu_Create(title[], headercolor = -1);
native Menu_IsValid(menuid);
native Menu_Destroy(menuid);
native Menu_AddItem(menuid, itemtext[]);
native Menu_EditItem(menuid, itemid, itemtext[]);
native Menu_EditTitle(menuid, newtitle[]);
native Menu_Show(playerid, menuid, selectioncolor = 0x0000AAFF);
native Menu_Hide(playerid);
native _
native GetPlayerMenuID(playerid);
native GetPlayerMenuLisitemID(playerid);

CALLBACKS:
public OnMenuResponse(playerid, menuid, response, listitem)
*/

#define MAX_G_MENUS     		10 //maximum menus your script can have
#define MAX_MENU_ITEMS  		25 //maximum listitems a menu can have
#define MAX_MENU_PAGE_ITEMS  	10 //maximum lines/lisitems shown in a menu's single page
#define INVALID_MENU_ID 		-1 //not to change

#define MENU_RESPONSE_UP      	0 //when a player press KEY_UP and select the previous item
#define MENU_RESPONSE_DOWN      1 //when a player press KEY_DOWN and select the next item
#define MENU_RESPONSE_CLOSE     2 //when a player press KEY_SECONDARY_ATTACK or KEY_ENTER to exit the menu
#define MENU_RESPONSE_SELECT    3 //when a player press KEY_SPRINT ot KEY_SPACE to select the respected item

#define MENU_SOUND_UP      		1054 //sound heard when player go UP
#define MENU_SOUND_DOWN      	1054 //sound heard when player go DOWN
#define MENU_SOUND_CLOSE     	1084 //sound heard when player close menu
#define MENU_SOUND_SELECT    	1083 //sound heard when player select an item

enum PlayerMenuEnum
{
	PM_MENUID,
	PM_LISTITEM,
	PM_LISTITEM_FIRST,
	PM_LISTITEM_LAST,
	PM_SELECTION_COLOR,
	PM_TICK
}
static gPlayerMenu[MAX_PLAYERS][PlayerMenuEnum];

enum MenuEnum
{
	bool:M_EXIST,
	M_HEADER[18],
	M_LISTITEMS,
	M_HEADER_COLOR,
}
static gMenu[MAX_G_MENUS][MenuEnum];
static gMenuItems[MAX_G_MENUS][MAX_MENU_ITEMS][35];

static Text:gMenuGlobalTD[2];
static PlayerText:gMenuPlayerItemsTD[MAX_PLAYERS][MAX_MENU_PAGE_ITEMS];
static PlayerText:gMenuPlayerTD[MAX_PLAYERS][2];

//internal functions
stock static MENU_iseven(num)
{
	new r = (num % 2);
 	if(r > 0) return true;
  	return false;
}

stock static MENU_isnegative(num)
{
 	if(num < 0) return true;
  	return false;
}

stock static MENU_SetTransparency(color, alpha = 0xFF)
{
    static newcolor;

    alpha = clamp(alpha, 0x00, 0xFF);

    newcolor = (color & ~0xFF) | alpha;
    return newcolor;
}

stock static Text:MENU_TextDrawAdd(Float:posX, Float:posY, string[], bgcolor, font, Float:lettersizeX, Float:lettersizeY, textcolor, allign = 0, outline = 1, bool:proportional = true, shadow = 1, bool:usebox = false, boxcolor = 0, Float:textsizeX = -1.0, Float:textsizeY = -1.0, model = 0, Float:rotX = 0.0, Float:rotY = 0.0, Float:rotZ = 0.0, Float:zoom = 1.0)
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

stock static PlayerText:MENU_PlayerTextDrawAdd(playerid, Float:posX, Float:posY, string[], bgcolor, font, Float:lettersizeX, Float:lettersizeY, textcolor, allign = 0, outline = 1, bool:proportional = true, shadow = 1, bool:usebox = false, boxcolor = 0, Float:textsizeX = -1.0, Float:textsizeY = -1.0, model = 0, Float:rotX = 0.0, Float:rotY = 0.0, Float:rotZ = 0.0, Float:zoom = 1.0, selectable = 0)
{
	static PlayerText:gTextDraw;
    gTextDraw = CreatePlayerTextDraw(playerid, posX, posY, string);
	PlayerTextDrawBackgroundColor(playerid, gTextDraw, bgcolor);
	PlayerTextDrawFont(playerid, gTextDraw, font);
	PlayerTextDrawLetterSize(playerid, gTextDraw, lettersizeX, lettersizeY);
	PlayerTextDrawColor(playerid, gTextDraw, textcolor);
 	PlayerTextDrawAlignment(playerid, gTextDraw, allign);
	PlayerTextDrawSetOutline(playerid, gTextDraw, outline);
	PlayerTextDrawSetProportional(playerid, gTextDraw, proportional);
	PlayerTextDrawSetShadow(playerid, gTextDraw, shadow);
	PlayerTextDrawUseBox(playerid, gTextDraw, usebox);
	if(usebox) PlayerTextDrawBoxColor(playerid, gTextDraw, boxcolor);
	if(textsizeX != -1.0 && textsizeY != -1.0) PlayerTextDrawTextSize(playerid, gTextDraw, textsizeX, textsizeY);
	if(font == 5)
	{
		PlayerTextDrawSetPreviewModel(playerid, gTextDraw, model);
		PlayerTextDrawSetPreviewRot(playerid, gTextDraw, rotX, rotY, rotZ, zoom);
	}
	PlayerTextDrawSetSelectable(playerid, gTextDraw, selectable);
	return gTextDraw;
}

static Menu_CreateGlobalTDs()
{
    gMenuGlobalTD[0] = MENU_TextDrawAdd(20.000000, 158.000000, "header", 255, 1, 0.000000, 3.000000, -1, 1, 0, true, 1, true, 1678379670, 150.000000, 0.000000);
    gMenuGlobalTD[1] = MENU_TextDrawAdd(20.000000, 191.000000, "Interaction Menu", 255, 1, 0.150000, 0.599999, -1, 1, 0, true, 1, true, 169090710, 150.000000, 0.000000);
    return true;
}

static Menu_DestroyGlobalTDs()
{
	TextDrawDestroy(gMenuGlobalTD[0]);
	TextDrawDestroy(gMenuGlobalTD[1]);
    return true;
}

//Note: if you use this in a filterscript, please define "FILTERSCRIPT" in your script
#if defined FILTERSCRIPT// if used in a filterscript

	public OnFilterScriptInit()
	{
		Menu_CreateGlobalTDs();

		for(new i; i < MAX_G_MENUS; i++)
		{
		    gMenu[i][M_EXIST] = false;
		    format(gMenu[i][M_HEADER], 18, "");
		    gMenu[i][M_LISTITEMS] = 0;
		    gMenu[i][M_HEADER_COLOR] = -1;

		    for(new x; x < MAX_MENU_ITEMS; x++) format(gMenuItems[i][x], 35, "");
		}

        #if defined Menu_OnFilterScriptInit
        	return Menu_OnFilterScriptInit();
	    #else
	    	return 1;
	    #endif
	}
	#if defined _ALS_OnFilterScriptInit
	    #undef OnFilterScriptInit
	#else
	    #define _ALS_OnFilterScriptInit
	#endif
	#define OnFilterScriptInit Menu_OnFilterScriptInit
	#if defined Menu_OnFilterScriptInit
	    forward Menu_OnFilterScriptInit();
	#endif

	public OnFilterScriptExit()
	{
		Menu_DestroyGlobalTDs();

	    #if defined Menu_OnFilterScriptExit
        	return Menu_OnFilterScriptExit();
	    #else
	    	return 1;
	    #endif
	}
	#if defined _ALS_OnFilterScriptExit
	    #undef OnFilterScriptExit
	#else
	    #define _ALS_OnFilterScriptExit
	#endif
	#define OnFilterScriptExit Menu_OnFilterScriptExit
	#if defined Menu_OnFilterScriptExit
	    forward Menu_OnFilterScriptExit();
	#endif

#else// if used in a gamemode

	public OnGameModeInit()
	{
		Menu_CreateGlobalTDs();

		for(new i; i < MAX_G_MENUS; i++)
		{
		    gMenu[i][M_EXIST] = false;
		    format(gMenu[i][M_HEADER], 18, "");
		    gMenu[i][M_LISTITEMS] = 0;
		    gMenu[i][M_HEADER_COLOR] = -1;

		    for(new x; x < MAX_MENU_ITEMS; x++) format(gMenuItems[i][x], 35, "");
		}

	    #if defined Menu_OnGameModeInit
        	return Menu_OnGameModeInit();
	    #else
	    	return 1;
	    #endif
	}
	#if defined _ALS_OnGameModeInit
	    #undef OnGameModeInit
	#else
	    #define _ALS_OnGameModeInit
	#endif
	#define OnGameModeInit Menu_OnGameModeInit
	#if defined Menu_OnGameModeInit
	    forward Menu_OnGameModeInit();
	#endif

	public OnGameModeExit()
	{
		Menu_DestroyGlobalTDs();

	    #if defined Menu_OnGameModeExit
        	return Menu_OnGameModeExit();
	    #else
	    	return 1;
	    #endif
	}
	#if defined _ALS_OnGameModeExit
	    #undef OnGameModeExit
	#else
	    #define _ALS_OnGameModeExit
	#endif
	#define OnGameModeExit Menu_OnGameModeExit
	#if defined Menu_OnGameModeExit
	    forward Menu_OnGameModeExit();
	#endif

#endif

stock Menu_Create(title[], headercolor = -1)
{
	for(new i; i < MAX_G_MENUS; i++)
	{
	    if(! gMenu[i][M_EXIST])
	    {
			gMenu[i][M_EXIST] = true;
			format(gMenu[i][M_HEADER], 18, title);
			gMenu[i][M_LISTITEMS] = 0;
			gMenu[i][M_HEADER_COLOR] = headercolor;
			return i;
		}
	}
	return -1;
}

stock Menu_IsValid(menuid)
{
    return gMenu[menuid][M_EXIST];
}

stock Menu_Destroy(menuid)
{
	format(gMenu[menuid][M_HEADER], 18, "");
	gMenu[menuid][M_LISTITEMS] = 0;
	gMenu[menuid][M_HEADER_COLOR] = -1;

    gMenu[menuid][M_EXIST] = false;

    for(new i; i < MAX_MENU_ITEMS; i++) format(gMenuItems[menuid][i], 35, "");
    return true;
}

stock Menu_AddItem(menuid, itemtext[])
{
	new index = (gMenu[menuid][M_LISTITEMS] + 1);

    if(index > MAX_MENU_ITEMS) return -1;

    index -= 1;
	format(gMenuItems[menuid][index], 35, itemtext);
	gMenu[menuid][M_LISTITEMS] += 1;
    return index;
}

stock Menu_EditItem(menuid, itemid, itemtext[])
{
    if(itemid > MAX_MENU_ITEMS) return -1;

	format(gMenuItems[menuid][itemid], 35, itemtext);
    return true;
}

stock Menu_EditTitle(menuid, newtitle[])
{
	format(gMenu[menuid][M_HEADER], 18, newtitle);
    return true;
}

stock Menu_Show(playerid, menuid, selectioncolor = 0x0000AAFF)
{
	if(GetPlayerMenuID(playerid) != INVALID_MENU_ID) Menu_Hide(playerid);

    gPlayerMenu[playerid][PM_MENUID] = menuid;
    gPlayerMenu[playerid][PM_LISTITEM] = 0;
    gPlayerMenu[playerid][PM_LISTITEM_FIRST] = 0;
    gPlayerMenu[playerid][PM_SELECTION_COLOR] = selectioncolor;

	TextDrawColor(gMenuGlobalTD[0], gMenu[menuid][M_HEADER_COLOR]);
	for(new i; i < 2; i++) TextDrawShowForPlayer(playerid, gMenuGlobalTD[i]);

	if(gMenu[menuid][M_LISTITEMS] > 0)
	{
		for(new i = 0; i < MAX_MENU_PAGE_ITEMS; i++)
		{
		    if(i > gMenu[menuid][M_LISTITEMS]) break;
			if(MENU_iseven(i))
			{
				gMenuPlayerItemsTD[playerid][i] = MENU_PlayerTextDrawAdd(playerid, 20.000000, 202.000000 + (i * 10), gMenuItems[menuid][i], 255, 1, 0.150000, 0.599999, -1, 1, 0, true, 1, true, 150, 150.000000, 0.000000);
				if(i == 0) PlayerTextDrawBoxColor(playerid, gMenuPlayerItemsTD[playerid][i], MENU_SetTransparency(selectioncolor, 150));
			}
			else
			{
				gMenuPlayerItemsTD[playerid][i] = MENU_PlayerTextDrawAdd(playerid, 20.000000, 202.000000 + (i * 10), gMenuItems[menuid][i], 255, 1, 0.150000, 0.599999, -1, 1, 0, true, 1, true, 100, 150.000000, 0.000000);
				if(i == 0) PlayerTextDrawBoxColor(playerid, gMenuPlayerItemsTD[playerid][i], MENU_SetTransparency(selectioncolor, 100));
			}
			PlayerTextDrawShow(playerid, gMenuPlayerItemsTD[playerid][i]);
    		gPlayerMenu[playerid][PM_LISTITEM_LAST] = i;
		}
	}

	gMenuPlayerTD[playerid][0] = MENU_PlayerTextDrawAdd(playerid, 83.000000, 162.000000, gMenu[menuid][M_HEADER], 0, 1, 0.470000, 1.900000, -1, 2, 1, true);
	PlayerTextDrawShow(playerid, gMenuPlayerTD[playerid][0]);

	new menustr[10];
	format(menustr, sizeof(menustr), "1/%i", (gMenu[menuid][M_LISTITEMS] + 1));
	gMenuPlayerTD[playerid][1] = MENU_PlayerTextDrawAdd(playerid, 149.000000, 189.000000, menustr, 255, 1, 0.170000, 0.800000, -1, 3, 0, true);
	PlayerTextDrawShow(playerid, gMenuPlayerTD[playerid][1]);
	return true;
}

stock Menu_Hide(playerid)
{
	if(GetPlayerMenuID(playerid) == INVALID_MENU_ID) return false;

	gPlayerMenu[playerid][PM_MENUID] = INVALID_MENU_ID;
    gPlayerMenu[playerid][PM_LISTITEM] = 0;
    gPlayerMenu[playerid][PM_LISTITEM_FIRST] = 0;
    gPlayerMenu[playerid][PM_LISTITEM_LAST] = 0;
    gPlayerMenu[playerid][PM_SELECTION_COLOR] = -1;
    gPlayerMenu[playerid][PM_TICK] = 0;

	for(new i; i < 2; i++) TextDrawHideForPlayer(playerid, gMenuGlobalTD[i]);

	for(new i = 0; i < MAX_MENU_PAGE_ITEMS; i++) PlayerTextDrawHide(playerid, gMenuPlayerItemsTD[playerid][i]), PlayerTextDrawDestroy(playerid, gMenuPlayerItemsTD[playerid][i]);

	PlayerTextDrawHide(playerid, gMenuPlayerTD[playerid][0]);
	PlayerTextDrawDestroy(playerid, gMenuPlayerTD[playerid][0]);
	PlayerTextDrawHide(playerid, gMenuPlayerTD[playerid][1]);
	PlayerTextDrawDestroy(playerid, gMenuPlayerTD[playerid][1]);
	return true;
}

stock GetPlayerMenuID(playerid) return gPlayerMenu[playerid][PM_MENUID];

stock GetPlayerMenuLisitemID(playerid) return gPlayerMenu[playerid][PM_LISTITEM];

public OnPlayerConnect(playerid)
{
    gPlayerMenu[playerid][PM_MENUID] = INVALID_MENU_ID;
    gPlayerMenu[playerid][PM_LISTITEM] = 0;
    gPlayerMenu[playerid][PM_LISTITEM_FIRST] = 0;
    gPlayerMenu[playerid][PM_LISTITEM_LAST] = 0;
    gPlayerMenu[playerid][PM_SELECTION_COLOR] = -1;
    gPlayerMenu[playerid][PM_TICK] = GetTickCount();

    #if defined Menu_OnPlayerConnect
       	return Menu_OnPlayerConnect(playerid);
	#else
	   	return 1;
	#endif
}
#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect Menu_OnPlayerConnect
#if defined Menu_OnPlayerConnect
    forward Menu_OnPlayerConnect(playerid);
#endif

public OnPlayerUpdate(playerid)
{
	new keys, updown, leftright;
	GetPlayerKeys(playerid, keys, updown, leftright);

	if(updown == KEY_DOWN)
	{
	    if(GetPlayerMenuID(playerid) != INVALID_MENU_ID)
		{
			// only allow new selection every ~200 ms
			if((GetTickCount() - gPlayerMenu[playerid][PM_TICK]) < 200) return 1;
    		gPlayerMenu[playerid][PM_TICK] = GetTickCount();

			new index = (gPlayerMenu[playerid][PM_LISTITEM] + 1);

			//if the player have reached the end of list/menu; Push the selection from begining
   			if(index > (gMenu[GetPlayerMenuID(playerid)][M_LISTITEMS] - 1))
			{
			   	if(CallLocalFunction("OnMenuResponse", "iiii", playerid, GetPlayerMenuID(playerid), MENU_RESPONSE_DOWN, 0))
				{
					gPlayerMenu[playerid][PM_LISTITEM] = 0;
				   	gPlayerMenu[playerid][PM_LISTITEM_FIRST] = 0;
				   	gPlayerMenu[playerid][PM_LISTITEM_LAST] = (0 + MAX_MENU_PAGE_ITEMS);

				   	PlayerPlaySound(playerid, MENU_SOUND_UP, 0.0, 0.0, 0.0);
				}
				else return 1;
			}
			//if the player have reached the end of page; push the player to next page!
			else if(index > gPlayerMenu[playerid][PM_LISTITEM_LAST])
			{
				if(CallLocalFunction("OnMenuResponse", "iiii", playerid, GetPlayerMenuID(playerid), MENU_RESPONSE_DOWN, (gPlayerMenu[playerid][PM_LISTITEM_LAST] + 1)))
				{
					gPlayerMenu[playerid][PM_LISTITEM] = (gPlayerMenu[playerid][PM_LISTITEM_LAST] + 1);
				   	gPlayerMenu[playerid][PM_LISTITEM_FIRST] = gPlayerMenu[playerid][PM_LISTITEM];
				   	gPlayerMenu[playerid][PM_LISTITEM_LAST] = (gPlayerMenu[playerid][PM_LISTITEM_FIRST] + MAX_MENU_PAGE_ITEMS);

				   	PlayerPlaySound(playerid, MENU_SOUND_UP, 0.0, 0.0, 0.0);
				}
				else return 1;
			}
			//if on the same list but requesting for next item; then highlight the next item !
			else
			{
				if(CallLocalFunction("OnMenuResponse", "iiii", playerid, GetPlayerMenuID(playerid), MENU_RESPONSE_DOWN, (gPlayerMenu[playerid][PM_LISTITEM] + 1)))
				{
					index = (gPlayerMenu[playerid][PM_LISTITEM] - gPlayerMenu[playerid][PM_LISTITEM_FIRST]);

					if(MENU_iseven(index)) PlayerTextDrawBoxColor(playerid, gMenuPlayerItemsTD[playerid][index], 150);
					else PlayerTextDrawBoxColor(playerid, gMenuPlayerItemsTD[playerid][index], 100);
					PlayerTextDrawShow(playerid, gMenuPlayerItemsTD[playerid][index]);

				   	gPlayerMenu[playerid][PM_LISTITEM] += 1;//+

					index = (gPlayerMenu[playerid][PM_LISTITEM] - gPlayerMenu[playerid][PM_LISTITEM_FIRST]);

					new menustr[10];
					format(menustr, sizeof(menustr), "%i/%i", (gPlayerMenu[playerid][PM_LISTITEM] + 1), gMenu[GetPlayerMenuID(playerid)][M_LISTITEMS]);
					PlayerTextDrawSetString(playerid, gMenuPlayerTD[playerid][1], menustr);

					if(MENU_iseven(index)) PlayerTextDrawBoxColor(playerid, gMenuPlayerItemsTD[playerid][index], MENU_SetTransparency(gPlayerMenu[playerid][PM_SELECTION_COLOR], 150));
					else PlayerTextDrawBoxColor(playerid, gMenuPlayerItemsTD[playerid][index], MENU_SetTransparency(gPlayerMenu[playerid][PM_SELECTION_COLOR], 100));
					PlayerTextDrawShow(playerid, gMenuPlayerItemsTD[playerid][index]);

				   	PlayerPlaySound(playerid, MENU_SOUND_UP, 0.0, 0.0, 0.0);
				}
				//end
				return 1;
			}

			//if the first 2 conditons apply (any one)
			for(new i = gPlayerMenu[playerid][PM_LISTITEM]; i < (gPlayerMenu[playerid][PM_LISTITEM] + MAX_MENU_PAGE_ITEMS); i++)
			{
				index = (i - gPlayerMenu[playerid][PM_LISTITEM_FIRST]);

			    if(i > gMenu[GetPlayerMenuID(playerid)][M_LISTITEMS]) PlayerTextDrawHide(playerid, gMenuPlayerItemsTD[playerid][index]);
				else
				{
					PlayerTextDrawSetString(playerid, gMenuPlayerItemsTD[playerid][index], gMenuItems[GetPlayerMenuID(playerid)][i]);
					if(MENU_iseven(index))
					{
						if(i == gPlayerMenu[playerid][PM_LISTITEM]) PlayerTextDrawBoxColor(playerid, gMenuPlayerItemsTD[playerid][index], MENU_SetTransparency(gPlayerMenu[playerid][PM_SELECTION_COLOR], 150));
						else PlayerTextDrawBoxColor(playerid, gMenuPlayerItemsTD[playerid][index], 150);
					}
					else
					{
						if(i == gPlayerMenu[playerid][PM_LISTITEM]) PlayerTextDrawBoxColor(playerid, gMenuPlayerItemsTD[playerid][index], MENU_SetTransparency(gPlayerMenu[playerid][PM_SELECTION_COLOR], 100));
                        else PlayerTextDrawBoxColor(playerid, gMenuPlayerItemsTD[playerid][index], 100);
					}
					PlayerTextDrawShow(playerid, gMenuPlayerItemsTD[playerid][index]);

					new menustr[10];
					format(menustr, sizeof(menustr), "%i/%i", (gPlayerMenu[playerid][PM_LISTITEM] + 1), gMenu[GetPlayerMenuID(playerid)][M_LISTITEMS]);
					PlayerTextDrawSetString(playerid, gMenuPlayerTD[playerid][1], menustr);

					gPlayerMenu[playerid][PM_LISTITEM_LAST] = i;
				}
			}
		}
	}
	else if(updown == KEY_UP)
	{
	    if(GetPlayerMenuID(playerid) != INVALID_MENU_ID)
		{
			// only allow new selection every ~200 ms
			if((GetTickCount() - gPlayerMenu[playerid][PM_TICK]) < 200) return 1;
    		gPlayerMenu[playerid][PM_TICK] = GetTickCount();

			new index = (gPlayerMenu[playerid][PM_LISTITEM] - 1);

			//if the player have reached the first item of first page, then stop updating menu!
   			if(MENU_isnegative(index))
   			{
                if(CallLocalFunction("OnMenuResponse", "iiii", playerid, GetPlayerMenuID(playerid), MENU_RESPONSE_UP, gPlayerMenu[playerid][PM_LISTITEM]))
				{
				   	PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
				}
				else return 1;
			   	return 1;
			}
			//if the player have reached the first item of page; push the player to previous page!
			else if(index < gPlayerMenu[playerid][PM_LISTITEM_FIRST])
			{
				if(CallLocalFunction("OnMenuResponse", "iiii", playerid, GetPlayerMenuID(playerid), MENU_RESPONSE_UP, (gPlayerMenu[playerid][PM_LISTITEM_FIRST] - 1)))
				{
					gPlayerMenu[playerid][PM_LISTITEM] = (gPlayerMenu[playerid][PM_LISTITEM_FIRST] - 1);
				   	gPlayerMenu[playerid][PM_LISTITEM_FIRST] = ((gPlayerMenu[playerid][PM_LISTITEM] + 1) - MAX_MENU_PAGE_ITEMS);
				   	gPlayerMenu[playerid][PM_LISTITEM_LAST] = gPlayerMenu[playerid][PM_LISTITEM];

				   	PlayerPlaySound(playerid, MENU_SOUND_DOWN, 0.0, 0.0, 0.0);
				}
			}
			//if on the same list but requesting for next item; then highlight the next item !
			else
			{
				if(CallLocalFunction("OnMenuResponse", "iiii", playerid, GetPlayerMenuID(playerid), MENU_RESPONSE_UP, (gPlayerMenu[playerid][PM_LISTITEM] - 1)))
				{
					index = (gPlayerMenu[playerid][PM_LISTITEM] - gPlayerMenu[playerid][PM_LISTITEM_FIRST]);

					if(MENU_iseven(index)) PlayerTextDrawBoxColor(playerid, gMenuPlayerItemsTD[playerid][index], 150);
					else PlayerTextDrawBoxColor(playerid, gMenuPlayerItemsTD[playerid][index], 100);
					PlayerTextDrawShow(playerid, gMenuPlayerItemsTD[playerid][index]);

				   	gPlayerMenu[playerid][PM_LISTITEM] -= 1;//-

					index = (gPlayerMenu[playerid][PM_LISTITEM] - gPlayerMenu[playerid][PM_LISTITEM_FIRST]);

					new menustr[10];
					format(menustr, sizeof(menustr), "%i/%i", (gPlayerMenu[playerid][PM_LISTITEM] + 1), gMenu[GetPlayerMenuID(playerid)][M_LISTITEMS]);
					PlayerTextDrawSetString(playerid, gMenuPlayerTD[playerid][1], menustr);

					if(MENU_iseven(index)) PlayerTextDrawBoxColor(playerid, gMenuPlayerItemsTD[playerid][index], MENU_SetTransparency(gPlayerMenu[playerid][PM_SELECTION_COLOR], 150));
					else PlayerTextDrawBoxColor(playerid, gMenuPlayerItemsTD[playerid][index], MENU_SetTransparency(gPlayerMenu[playerid][PM_SELECTION_COLOR], 100));
					PlayerTextDrawShow(playerid, gMenuPlayerItemsTD[playerid][index]);

				   	PlayerPlaySound(playerid, MENU_SOUND_DOWN, 0.0, 0.0, 0.0);
				}
				//end
				return 1;
			}

			//if the first conditon apply (any one)
			for(new i = gPlayerMenu[playerid][PM_LISTITEM]; i > (gPlayerMenu[playerid][PM_LISTITEM]  - MAX_MENU_PAGE_ITEMS); i--)
			{
				index = (i - gPlayerMenu[playerid][PM_LISTITEM_FIRST]);

			    PlayerTextDrawSetString(playerid, gMenuPlayerItemsTD[playerid][index], gMenuItems[GetPlayerMenuID(playerid)][i]);
				if(MENU_iseven(index))
				{
					if(i == gPlayerMenu[playerid][PM_LISTITEM]) PlayerTextDrawBoxColor(playerid, gMenuPlayerItemsTD[playerid][index], MENU_SetTransparency(gPlayerMenu[playerid][PM_SELECTION_COLOR], 150));
					else PlayerTextDrawBoxColor(playerid, gMenuPlayerItemsTD[playerid][index], 150);
				}
				else
				{
					if(i == gPlayerMenu[playerid][PM_LISTITEM]) PlayerTextDrawBoxColor(playerid, gMenuPlayerItemsTD[playerid][index], MENU_SetTransparency(gPlayerMenu[playerid][PM_SELECTION_COLOR], 100));
                    else PlayerTextDrawBoxColor(playerid, gMenuPlayerItemsTD[playerid][index], 100);
				}
				PlayerTextDrawShow(playerid, gMenuPlayerItemsTD[playerid][index]);

				new menustr[10];
				format(menustr, sizeof(menustr), "%i/%i", (gPlayerMenu[playerid][PM_LISTITEM] + 1), gMenu[GetPlayerMenuID(playerid)][M_LISTITEMS]);
				PlayerTextDrawSetString(playerid, gMenuPlayerTD[playerid][1], menustr);
			}
		}
	}

	if(keys == KEY_SECONDARY_ATTACK)
	{
	    if(GetPlayerMenuID(playerid) != INVALID_MENU_ID)
		{
		    if(CallLocalFunction("OnMenuResponse", "iiii", playerid, GetPlayerMenuID(playerid), MENU_RESPONSE_CLOSE, gPlayerMenu[playerid][PM_LISTITEM]))
			{
			    Menu_Hide(playerid);
				PlayerPlaySound(playerid, MENU_SOUND_CLOSE, 0.0, 0.0, 0.0);
			}
		}
	}
	else if(keys == KEY_SPRINT)
	{
	    if(GetPlayerMenuID(playerid) != INVALID_MENU_ID)
		{
		    if(CallLocalFunction("OnMenuResponse", "iiii", playerid, GetPlayerMenuID(playerid), MENU_RESPONSE_SELECT, gPlayerMenu[playerid][PM_LISTITEM]))
			{
			    Menu_Hide(playerid);
				PlayerPlaySound(playerid, MENU_SOUND_SELECT, 0.0, 0.0, 0.0);
			}
		}
	}

	#if defined Menu_OnPlayerUpdate
       	return Menu_OnPlayerUpdate(playerid);
	#else
	   	return 1;
	#endif
}
#if defined _ALS_OnPlayerUpdate
    #undef OnPlayerUpdate
#else
    #define _ALS_OnPlayerUpdate
#endif
#define OnPlayerUpdate Menu_OnPlayerUpdate
#if defined Menu_OnPlayerUpdate
    forward Menu_OnPlayerUpdate(playerid);
#endif

forward OnMenuResponse(playerid, menuid, response, listitem);