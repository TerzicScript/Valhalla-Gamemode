#include <a_samp>
#include <Dini>
new PlayerVip[MAX_PLAYERS];
#if defined _PlayerVipRock_included
#endinput
#endif
#define _PlayerVipRock_included
#define red 0xFF0000AA
new name2[MAX_PLAYER_NAME];
//========================Load Vip=====================
stock
    LoadPlayerVip(playerid)
{
new ppp[MAX_PLAYER_NAME];
GetPlayerName(playerid,ppp, MAX_PLAYER_NAME);
if(dini_Isset("PlayerVip.ini",ppp)) PlayerVip[playerid] = dini_Int("PlayerVip.ini",ppp);
}
//========================Save Vip=====================
stock
    SavePlayerVip(playerid)
{
new ppp[MAX_PLAYER_NAME];
GetPlayerName(playerid,ppp, MAX_PLAYER_NAME);
dini_IntSet("PlayerVip.ini",ppp,PlayerVip[playerid]);
return ;
}
//========================Get Vip =====================
stock
    GetPlayerVip(playerid)
{
new ppp[MAX_PLAYER_NAME];
GetPlayerName(playerid,ppp, MAX_PLAYER_NAME);
PlayerVip[playerid] =0;
return 1;
}
//========================Set Vip=====================
stock
    SetPlayerVip(playerid)
{
new ppp[MAX_PLAYER_NAME];
GetPlayerName(playerid,ppp, MAX_PLAYER_NAME);
PlayerVip[playerid]=1;
return true;
}
//========================IsNumeric=====================
stock IsNumeric(string[])
{
	for (new i = 0, j = strlen(string); i < j; i++)
	{
		if (string[i] > '9' || string[i] < '0') return 0;
	}
	return 1;
}
//========================ReturnPlayerID=====================
stock ReturnPlayerID(PlayerName[])
{
	for(new i = 0; i < MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i))
		{
			if(strfind(pName(i),PlayerName,true)!=-1) return i;
		}
	}
	return INVALID_PLAYER_ID;
}
//========================pName=====================
stock pName(playerid)
{
  new name[MAX_PLAYER_NAME];
  GetPlayerName(playerid, name, sizeof(name));
  return name;
}
//========================PlayerName2=====================
stock PlayerName2(playerid) {
  GetPlayerName(playerid, name2, sizeof(name2));
  return name2;
}
//========================MaxAmmo=====================
MaxAmmo(playerid)
{
	new slot, weap, ammo;
	for (slot = 0; slot < 14; slot++)
	{
    	GetPlayerWeaponData(playerid, slot, weap, ammo);
		if(IsValidWeapon(weap))
		{
		   	GivePlayerWeapon(playerid, weap, 99999);
		}
	}
	return 1;
}
//========================IsValidWeapon=====================
stock IsValidWeapon(weaponid)
{
    if (weaponid > 0 && weaponid < 19 || weaponid > 21 && weaponid < 47) return 1;
    return 0;
}
//========================Car Spawner=====================

forward CarSpawner(playerid,model);
public CarSpawner(playerid,model)
{
	if(IsPlayerInAnyVehicle(playerid)) SendClientMessage(playerid, red, "Deja conduci o masina !");
 	else
	{
    	new Float:x, Float:y, Float:z, Float:angle;
	 	GetPlayerPos(playerid, x, y, z);
	 	GetPlayerFacingAngle(playerid, angle);
	    new vehicleid=CreateVehicle(model, x, y, z, angle, -1, -1, -1);
		PutPlayerInVehicle(playerid, vehicleid, 0);
		SetVehicleVirtualWorld(vehicleid, GetPlayerVirtualWorld(playerid));
		LinkVehicleToInterior(vehicleid, GetPlayerInterior(playerid));
		ChangeVehicleColor(vehicleid,0,0);
	}
	return 1;
}
//========================Vip Commands=====================
VCommands()
{
    new Commands[1024];
    Commands[0]='\0';
    strcat(Commands, "{FF0202}->/vipgoto [playerid]{EFED7A} use {FF0202}/vipgoto [playerid]{EFED7A} to teleport to other players\n", 1024 );
    strcat(Commands, "{FF0202}->/maxammo {EFED7A} use {FF0202}/maxammo{EFED7A} to get infinite ammo\n", 1024 );
    strcat(Commands, "{FF0202}->/spawnme {EFED7A} use {FF0202}/spawnme{EFED7A} to spawn yourself\n", 1024 );
    strcat(Commands, "{FF0202}->/vclub {EFED7A} use {FF0202}/vclub{EFED7A} to teleport to Vip Club\n", 1024 );
    strcat(Commands, "{FF0202}->/vips {EFED7A} use {FF0202}/vips{EFED7A} to see all online vips\n", 1024 );
    strcat(Commands, "{FF0202}->/vcar {EFED7A} use {FF0202}/vcar{EFED7A} to get VipCar\n\n", 1024 );
    strcat(Commands, "{EFED7A}Use {FF0202}! {EFED7A}for Vip Chat. Ex : {FF0202}!{EFED7A} hello", 1024 );
    return Commands;
}
//========================Count Vip Commands=====================
stock VipCommands() {
    new
        cmdBuffer[32],
        commandCount;

    for(new it = 0; it < Scripting_GetPublicsCount(); it++) {
        Scripting_GetPublic(it, cmdBuffer);

        if(!strcmp(cmdBuffer, "cmd_", false, 4)) {
            commandCount++;
        }
    }

    return commandCount;
}