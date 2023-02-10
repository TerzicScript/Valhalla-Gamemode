/**
  * Name: Dynamic Rent 
  * Author: V01D
  * Date: 9th August
  * Git: 
  * Important: For this include to work you need to create folder RentLocations inside scriptfiles
  * Copyright (C) 2020
  */

#if defined _DynamicRentVoid_INCLUDED
    #endinput
#endif
#define _DynamicRentVoid_INCLUDED

#include <a_samp>
#tryinclude <YSI\y_hooks>
#tryinclude <YSI\y_timers>
#tryinclude <YSI\y_ini>
#tryinclude <streamer>

//  <Defines>
#if defined RENTLOCATION_FILE
    #undef RENTLOCATION_FILE
#else
    #define RENTLOCATION_FILE "RentLocations/Rent_%d.ini"
#endif

#if defined MAX_RENTL
    #undef MAX_RENTL
#else
    #define MAX_RENTL 30
#endif


#define WhiteRentColor                         "{FFFFFF}"
#define RedRentColor                           "{FF0000}"

//  <Variables>
static
    bool:Rentao[MAX_PLAYERS char],
    Timer:RentingTimer[MAX_PLAYERS],
    RentVozilo[MAX_PLAYERS];

//  <Enum>
enum {
    dialog_TakeRent
}

enum RentLokacije {
    Float:rPosX,
    Float:rPosY,
    Float:rPosZ
};

new RentInfo[MAX_RENTL][RentLokacije];
new RentPickup[sizeof(RentInfo)];
new Text3D:RentLabel[sizeof(RentInfo)];

//  <Rent Locations Loading>
forward LoadRentLocations(idrent, name[], value[]);
public LoadRentLocations(idrent, name[], value[]) {
    INI_Float("X", RentInfo[idrent][rPosX]);
    INI_Float("Y", RentInfo[idrent][rPosY]);
    INI_Float("Z", RentInfo[idrent][rPosZ]);
    return 1;
}

//  <Rent Location Save>

stock SaveRentLocation(rentid) {
    new fFile[30];
    format(fFile, 30, RENTLOCATION_FILE, rentid);
    new INI:File = INI_Open(fFile);

    INI_WriteFloat(File,"X", RentInfo[rentid][rPosX]);
    INI_WriteFloat(File,"Y", RentInfo[rentid][rPosY]);
    INI_WriteFloat(File,"Z", RentInfo[rentid][rPosZ]);
    INI_Close(File);
    return 1;
}

//  <Functions>

stock RemoveRentLoc(playerid, rentid) {
    new fFile[30];
    format(fFile, 30, RENTLOCATION_FILE, rentid);
    if(fexist(fFile)) {
        fremove(fFile);
        DestroyDynamic3DTextLabel(RentLabel[rentid]);
        DestroyDynamicPickup(RentPickup[rentid]);
        va_SendClientMessage(playerid, -1, "Rent Location (ID:%d) deleted successfully!", rentid);
    }
    else return va_SendClientMessage(playerid, -1, "Rent Location (ID:%d) doesn't exist!", rentid);
    return 1;
}

stock CreateRentLoc(playerid, rentid) {
    new Float:X, Float:Y, Float:Z;
    GetPlayerPos(playerid, X, Y, Z);
    new rfile[30], string[85];
    format(rfile, sizeof(rfile), RENTLOCATION_FILE, rentid);
    if(fexist(rfile)) return va_SendClientMessage(playerid, -1, "Rent (ID:%d) already exists!", rentid);
    
    RentInfo[rentid][rPosX] = X; 
    RentInfo[rentid][rPosY] = Y; 
    RentInfo[rentid][rPosZ] = Z;

    format(string, 85, ""RedRentColor"[ RENT VEHICLE ]\nID: "WhiteRentColor"%d\n"RedRentColor"[ /rent ]", rentid);
    RentLabel[rentid] = CreateDynamic3DTextLabel(string, 0x33CCFFAA, X, Y, Z, 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1, -1, 30.0, -1, 0);
    RentPickup[rentid] = CreateDynamicPickup(19135, 1, X, Y, Z, -1, -1, -1, 30.0, -1, 0);

    SaveRentLocation(rentid);
    
    va_SendClientMessage(playerid, 0xF81414FF, "Rent Location (ID:%d) created successfully!", rentid);
    return 1;
}

stock IniLoadRentLocations() {
    new brojac;
    for(new rentid = 0; rentid < sizeof(RentInfo); rentid++) {
        new fFile[30], string[80];
        format(fFile, 30, RENTLOCATION_FILE, rentid);
        if(fexist(fFile)) {
            INI_ParseFile(fFile, "LoadRentLocations", .bExtra = true, .extra = rentid);
            format(string, 80, ""RedRentColor"[ RENT VOZILA ]\nID: "WhiteRentColor"%d\n"RedRentColor"[ /rent ]", rentid);
            RentLabel[rentid] = CreateDynamic3DTextLabel(string, 0x33CCFFAA, RentInfo[rentid][rPosX], RentInfo[rentid][rPosY], RentInfo[rentid][rPosZ], 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1, -1, 30.0, -1, 0);
            RentPickup[rentid] = CreateDynamicPickup(19135, 1, RentInfo[rentid][rPosX], RentInfo[rentid][rPosY], RentInfo[rentid][rPosZ], -1, -1, -1, 30.0, -1, 0);
            brojac++;
        }
    }
    printf("%d Rent Locations by V01D Loaded successfully!", brojac);
    return 1;
}

stock RentVehicle(playerid) {
    if(Rentao{playerid}) return SendClientMessage(playerid, -1, "You already rented vehicle! Use /unrent");
    for(new r=0; r < MAX_RENTL; r++)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, RentInfo[r][rPosX], RentInfo[r][rPosY], RentInfo[r][rPosZ])) {
            ShowPlayerDialog(playerid, dialog_TakeRent, DIALOG_STYLE_TABLIST_HEADERS, "Rent Location", "Vehicle\tPrice\nFaggio\t300$\nSentinel\t500$", "Ok", "Cancel");
        }
    }
    return 1;
}

stock UnRentVehicle(playerid) {
    if(!Rentao{playerid}) return SendClientMessage(playerid, -1, "You didn't rent any vehicle!");
    DestroyVehicle(RentVozilo[playerid]);
    Rentao{playerid} = false;
    RentVozilo[playerid] = 0;
    SendClientMessage(playerid, -1, "You don't rent vehicle anymore!");
    return 1;
}

//  <Timers>
timer RentTimer[240000](playerid)
{
    SendClientMessage(playerid, -1, "You didn't enter vehicle in time! Rent is now destroyed!");
    DestroyVehicle(RentVozilo[playerid]);
    Rentao{playerid} = false;
    RentVozilo[playerid] = 0;
    return 1;
}

//  <Callbacks>

hook OnPlayerDisconnect(playerid, reason) {
    if(Rentao{playerid})
    {
        DestroyVehicle(RentVozilo[playerid]);
    }
}

hook OnPlayerStateChange(playerid, newstate, oldstate) {
    if(newstate == PLAYER_STATE_ONFOOT && oldstate == PLAYER_STATE_DRIVER) {
        if(Rentao{playerid}) {
            RentingTimer[playerid] = defer RentTimer(playerid);
            SendClientMessage(playerid, -1, "You have 3 minutes to get back in vehicle or it will be destroyed!");
        }
    }
    if(newstate == PLAYER_STATE_DRIVER) {
        if(Rentao{playerid}) {
            stop RentingTimer[playerid];
        }
    }
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) {
    if(dialogid == dialog_TakeRent) {
        if(!response) return 0;
        if(response) {
            switch(listitem) {
                case 0: {
                    if(GetPlayerMoney(playerid) < 300) return SendClientMessage(playerid, -1, "You don't have enough money!");

                    new Float:X, Float:Y, Float:Z;
                    GetPlayerPos(playerid, X,Y,Z);

                    RentVozilo[playerid] = CreateVehicle(462, X, Y, Z, 0, 0, 0, -1);
                    PutPlayerInVehicle(playerid, RentVozilo[playerid], 0);

                    Rentao{playerid} = true;
                    GivePlayerMoney(playerid, -300);
                    SendClientMessage(playerid, 0xF81414FF, "You rented Fagio for 300$! You can use /unrent");
                    return 1;
                }
                case 1:
                {
                    if(GetPlayerMoney(playerid) < 500) return SendClientMessage(playerid, -1, "You don't have enough money!");

                    new Float:X, Float:Y, Float:Z;
                    GetPlayerPos(playerid, X,Y,Z);
                    
                    RentVozilo[playerid] = CreateVehicle(405, X, Y, Z, 0, 0, 0, -1);
                    PutPlayerInVehicle(playerid, RentVozilo[playerid], 0);

                    Rentao{playerid} = true;
                    GivePlayerMoney(playerid, -500);
                    SendClientMessage(playerid, 0xF81414FF, "You rented Sentinel for 500$! You can use /unrent");
                    return 1;
                }
            }
        }
    }
    return 0;
}
