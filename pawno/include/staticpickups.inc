/*
	Extended static pickups (staticpickups.inc)
	* Generate a working static pickup with custom data in one line!

 	Author: (creator)
	* Gammix

 	Contributors:
	* Incognito - Streamer plugin, used dynamic areas

	(c) Copyright 2015
  	* This file is provided as is (no warranties).
*/
/*
FUNCTIONS:
native CreateStaticPickup(Float:x, Float:y, Float:z, model, ammount, interior = -1, virtualworld = -1, expiretime = 0);
native DestroyStaticPickup(pickupid);
native IsValidStaticPickup(pickupid);
*/

#include <streamer>

#define MAX_STATIC_PICKUPS	1000//this is the maximum amount of static pickups yur server can have, can be extended to whatever value you want

//These are just defination of pickup models, just for ease
#define PICKUP_MODEL_ARMOR		1242
#define PICKUP_MODEL_HEALTH		1240
#define PICKUP_MODEL_CASH		1274
#define PICKUP_MODEL_CASHBAG  	1550
#define PICKUP_MODEL_PARACHUTE	1310
//static pickup types ^^
//You can also create weapons with their model ids

enum StaticPickupEnum
{
	E_model,
	E_ammount,
	E_pickupid,
	E_type,
	E_timer
}
static gStaticPickup[MAX_STATIC_PICKUPS][StaticPickupEnum];

//Note: if you use this in a filterscript, please define "FILTERSCRIPT" in your script
#if defined FILTERSCRIPT// if used in a filterscript

	public OnFilterScriptInit()
	{
	    for(new i = 0; i < MAX_STATIC_PICKUPS; i++)
		{
		    gStaticPickup[i][E_model] = -1;
		    gStaticPickup[i][E_ammount] = -1;
		    gStaticPickup[i][E_pickupid] = -1;
		    gStaticPickup[i][E_type] = -1;
		    gStaticPickup[i][E_timer] = -1;
	    }

        #if defined PICK_OnFilterScriptInit
        	return PICK_OnFilterScriptInit();
	    #else
	    	return 1;
	    #endif
	}
	#if defined _ALS_OnFilterScriptInit
	    #undef OnFilterScriptInit
	#else
	    #define _ALS_OnFilterScriptInit
	#endif
	#define OnFilterScriptInit PICK_OnFilterScriptInit
	#if defined PICK_OnFilterScriptInit
	    forward PICK_OnFilterScriptInit();
	#endif

	public OnFilterScriptExit()
	{
	    for(new i = 0; i < MAX_STATIC_PICKUPS; i++)
		{
			if(IsValidStaticPickup(i))
			{
	    		DestroyStaticPickup(i);
	    	}
	    }

	    #if defined PICK_OnFilterScriptExit
        	return PICK_OnFilterScriptExit();
	    #else
	    	return 1;
	    #endif
	}
	#if defined _ALS_OnFilterScriptExit
	    #undef OnFilterScriptExit
	#else
	    #define _ALS_OnFilterScriptExit
	#endif
	#define OnFilterScriptExit PICK_OnFilterScriptExit
	#if defined PICK_OnFilterScriptExit
	    forward PICK_OnFilterScriptExit();
	#endif

#else// if used in a gamemode

	public OnGameModeInit()
	{
	    for(new i = 0; i < MAX_STATIC_PICKUPS; i++)
		{
		    gStaticPickup[i][E_model] = -1;
		    gStaticPickup[i][E_ammount] = -1;
		    gStaticPickup[i][E_pickupid] = -1;
		    gStaticPickup[i][E_type] = -1;
		    gStaticPickup[i][E_timer] = -1;
	    }

	    #if defined PICK_OnGameModeInit
        	return PICK_OnGameModeInit();
	    #else
	    	return 1;
	    #endif
	}
	#if defined _ALS_OnGameModeInit
	    #undef OnGameModeInit
	#else
	    #define _ALS_OnGameModeInit
	#endif
	#define OnGameModeInit PICK_OnGameModeInit
	#if defined PICK_OnGameModeInit
	    forward PICK_OnGameModeInit();
	#endif

	public OnGameModeExit()
	{
	    for(new i = 0; i < MAX_STATIC_PICKUPS; i++)
		{
			if(IsValidStaticPickup(i))
			{
	    		DestroyStaticPickup(i);
	    	}
	    }

	    #if defined PICK_OnGameModeExit
        	return PICK_OnGameModeExit();
	    #else
	    	return 1;
	    #endif
	}
	#if defined _ALS_OnGameModeExit
	    #undef OnGameModeExit
	#else
	    #define _ALS_OnGameModeExit
	#endif
	#define OnGameModeExit PICK_OnGameModeExit
	#if defined PICK_OnGameModeExit
	    forward PICK_OnGameModeExit();
	#endif

#endif

stock CreateStaticPickup(Float:x, Float:y, Float:z, model, ammount, interior = -1, virtualworld = -1, expiretime = 0)
{
	for(new i = 0; i < MAX_STATIC_PICKUPS; i++)
	{
	    if(gStaticPickup[i][E_model] == -1)
		{
			gStaticPickup[i][E_model] = model;
    		gStaticPickup[i][E_ammount] = ammount;
 			gStaticPickup[i][E_pickupid] = CreateDynamicPickup(model, 1, x, y, z, virtualworld, interior);
    		if(expiretime > 0)//if you use '-1' in 'expiretime', it means the pickup wont destroy by a timer!
			{
				gStaticPickup[i][E_timer] = SetTimerEx("OnAutoPickupDestroy", expiretime, false, "i", i);
    		}
			return i;//return the static pickup id
    	}
    }
    return -1;//will return -1 if  no static pickup was created
}

stock DestroyStaticPickup(pickupid)
{
	DestroyDynamicPickup(gStaticPickup[pickupid][E_pickupid]);
	gStaticPickup[pickupid][E_pickupid] = -1;
    gStaticPickup[pickupid][E_model] = -1;
    gStaticPickup[pickupid][E_ammount] = -1;
    gStaticPickup[pickupid][E_type] = -1;
    if(gStaticPickup[pickupid][E_timer] != -1) KillTimer(gStaticPickup[pickupid][E_timer]);
	gStaticPickup[pickupid][E_timer] = -1;
   	return true;
}

stock IsValidStaticPickup(pickupid)
{
    if(gStaticPickup[pickupid][E_model] == -1) return false;
    return true;
}

stock static GetModelWeaponID(weaponid)//this gives you the weapon id of the model specified; if its incorrect, then simply returns -1;
{
	switch(weaponid)
	{
	    case 331: return 1;
	    case 333: return 2;
	    case 334: return 3;
	    case 335: return 4;
	    case 336: return 5;
	    case 337: return 6;
	    case 338: return 7;
	    case 339: return 8;
	    case 341: return 9;
	    case 321: return 10;
	    case 322: return 11;
	    case 323: return 12;
	    case 324: return 13;
	    case 325: return 14;
	    case 326: return 15;
	    case 342: return 16;
	    case 343: return 17;
	    case 344: return 18;
	    case 346: return 22;
	    case 347: return 23;
	    case 348: return 24;
	    case 349: return 25;
	    case 350: return 26;
	    case 351: return 27;
	    case 352: return 28;
	    case 353: return 29;
	    case 355: return 30;
	    case 356: return 31;
	    case 372: return 32;
	    case 357: return 33;
	    case 358: return 34;
	    case 359: return 35;
	    case 360: return 36;
	    case 361: return 37;
	    case 362: return 38;
	    case 363: return 39;
	    case 364: return 40;
	    case 365: return 41;
	    case 366: return 42;
	    case 367: return 43;
	    case 368: return 44;
	    case 369: return 45;
	    case 371: return 46;
	}
	return -1;
}

forward OnAutoPickupDestroy(pickupid);
public OnAutoPickupDestroy(pickupid)
{
	return DestroyStaticPickup(pickupid);
}

public OnPlayerPickUpDynamicPickup(playerid, pickupid)
{
	for(new i = 0; i < MAX_STATIC_PICKUPS; i++)
	{
	    if(IsValidStaticPickup(i))
	    {
		    if(pickupid == gStaticPickup[i][E_pickupid])
		    {
				switch(gStaticPickup[i][E_model])
				{
				    case 331,333..341,321..326,342..355,372,356..371: GivePlayerWeapon(playerid, GetModelWeaponID(gStaticPickup[i][E_model]), gStaticPickup[i][E_ammount]);

				    case PICKUP_MODEL_ARMOR:
				    {
				        new Float:value;
				        GetPlayerArmour(playerid, value);
				        if(value + gStaticPickup[i][E_ammount] >= 100) SetPlayerArmour(playerid, 100.0);
	     				else if(value + gStaticPickup[i][E_ammount] < 100) SetPlayerArmour(playerid, (value + gStaticPickup[i][E_ammount]));
				    }

				    case PICKUP_MODEL_HEALTH:
				    {
				        new Float:value;
				        GetPlayerArmour(playerid, value);
				        if(value + gStaticPickup[i][E_ammount] >= 100) SetPlayerHealth(playerid, 100.0);
						else if(value + gStaticPickup[i][E_ammount] < 100) SetPlayerHealth(playerid, (value + gStaticPickup[i][E_ammount]));
				    }

				    case PICKUP_MODEL_CASH: GivePlayerMoney(playerid, gStaticPickup[i][E_ammount]);

					case PICKUP_MODEL_CASHBAG: GivePlayerMoney(playerid, gStaticPickup[i][E_ammount] + (1/5 * gStaticPickup[i][E_ammount]));

					case PICKUP_MODEL_PARACHUTE: GivePlayerWeapon(playerid, 46, gStaticPickup[i][E_ammount]);
				}
				if(gStaticPickup[i][E_type] == 3) DestroyStaticPickup(i);
		    }
		}
	}

	#if defined PICK_OnPlayerPickUpDynamicPick
       	return PICK_OnPlayerPickUpDynamicPick(playerid, pickupid);
    #else
    	return 1;
    #endif
}
#if defined _ALS_OnPlayerPickUpDynamicPick
    #undef OnPlayerPickUpDynamicPickup
#else
    #define _ALS_OnPlayerPickUpDynamicPick
#endif
#define OnPlayerPickUpDynamicPickup PICK_OnPlayerPickUpDynamicPick
#if defined PICK_OnPlayerPickUpDynamicPick
    forward PICK_OnPlayerPickUpDynamicPick(playerid, pickupid);
#endif