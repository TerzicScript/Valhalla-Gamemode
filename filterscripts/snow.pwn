#include <a_samp>
#include <streamer>
#include <Pawn.CMD>
 
 
#define MAX_SNOW_OBJECTS    3
#define UPDATE_INTERVAL     750
#define SNOW_RADIUS         1
 
#define CB:%0(%1)           forward %0(%1); public %0(%1)
 
new bool:snowOn[MAX_PLAYERS],
        snowObject[MAX_PLAYERS][MAX_SNOW_OBJECTS],
        updateTimer[MAX_PLAYERS];
 
public OnFilterScriptExit()
{
        foreach(Player, i)
        {
            if(snowOn[i])
            {
                for(new j = 0; j < MAX_SNOW_OBJECTS; j++) DestroyDynamicObject(snowObject[i][j]);
                KillTimer(updateTimer[i]);
                }
        }
        return 1;
}
 
public OnPlayerDisconnect(playerid)
{
        if(snowOn[playerid])
        {
            for(new i = 0; i < MAX_SNOW_OBJECTS; i++) DestroyDynamicObject(snowObject[playerid][i]);
            snowOn[playerid] = false;
            KillTimer(updateTimer[playerid]);
        }
        return 1;
}
 
forward UpdateSnow(playerid);
public UpdateSnow(playerid)
{
        if(!snowOn[playerid]) return 0;
        new Float:pPos[3];
        GetPlayerPos(playerid, pPos[0], pPos[1], pPos[2]);
        for(new i = 0; i < MAX_SNOW_OBJECTS; i++) SetDynamicObjectPos(snowObject[playerid][i], pPos[0] + random(SNOW_RADIUS), pPos[1] + random(SNOW_RADIUS), pPos[2] - 5);
        return 1;
}
 
stock CreateSnow(playerid)
{
        if(snowOn[playerid]) return 0;
        new Float:pPos[3];
        GetPlayerPos(playerid, pPos[0], pPos[1], pPos[2]);
        for(new i = 0; i < MAX_SNOW_OBJECTS; i++) snowObject[playerid][i] = CreateDynamicObject(18864, pPos[0] + random(SNOW_RADIUS), pPos[1] + random (SNOW_RADIUS), pPos[2] - 5, random(100), random(100), random(100), -1, -1, playerid);
        snowOn[playerid] = true;
        updateTimer[playerid] = SetTimerEx("UpdateSnow", UPDATE_INTERVAL, true, "i", playerid);
        return 1;
}
 
stock DeleteSnow(playerid)
{
        if(!snowOn[playerid]) return 0;
        for(new i = 0; i < MAX_SNOW_OBJECTS; i++) DestroyDynamicObject(snowObject[playerid][i]);
        KillTimer(updateTimer[playerid]);
        snowOn[playerid] = false;
        return 1;
}
 
CMD:snow(playerid, params[])
{
        if(snowOn[playerid])
        {
            DeleteSnow(playerid);
            SendClientMessage(playerid, 0x00FF00AA, "* It's not snowing anymore now.");
        }
        else
        {
            CreateSnow(playerid);
            SendClientMessage(playerid, 0x00FF00AA, "* Let it snow, let it snow, let it snow!");
        }
        return 1;
}
 