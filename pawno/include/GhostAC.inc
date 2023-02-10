//nj ac by Ghost

#include <a_players>
#include <foreach>
#pragma tabsize 0
stock ghostac_ResetPlayerMoney(playerid)
{
	ResetPlayerMoney(playerid);
	SetPVarInt(playerid, "SiguranNovac", 1);
	return 1;
}
stock ghostac_SetPlayerVirtualWorld(playerid, vw)
{
	SetPVarFloat(playerid,"ZastitaTeleporta",1);
	SetPlayerVirtualWorld(playerid,vw);
	SetPVarInt(playerid, "SiguranVW", vw);
	return 1;
}
stock ghostac_SetPlayerInterior(playerid, intid)
{
	SetPVarFloat(playerid,"ZastitaTeleporta",1);
	SetPlayerInterior(playerid, intid);
	SetPVarInt(playerid, "SiguranInt", intid);
	return 1;
}
stock ghostac_GivePlayerMoney(playerid, novac)
{
	GivePlayerMoney(playerid, novac);
	SetPVarInt(playerid, "SiguranNovac", 1);
	return 1;
}
stock ghostac_SetPlayerPos(playerid, Float:xx, Float:yy, Float:zz)
{
	SetPVarFloat(playerid,"ZastitaTeleporta",1);
	SetPlayerPos(playerid, xx,yy,zz);
	SetPVarInt(playerid, "SiguranTeleport", 1);
	return 1;
}
#define acime "[NJ:AC]:"
stock ghostac_SetPlayerHealth(playerid,Float:helti)
{
	SetPVarFloat(playerid,"ZastitaHelta",1);
	SetPlayerHealth(playerid,helti);
	SetPVarFloat(playerid,"SigurniHelti",helti);
}
stock ghostac_SetPlayerArmour(playerid,Float:armor)
{
	SetPVarFloat(playerid,"ZastitaArmora",1);
	SetPlayerArmour(playerid,armor);
	SetPVarFloat(playerid,"SigurniArmor",armor);
}
stock ghostac_PutPlayerInVehicle(playerid, vozilo, sediste)
{
	SetPVarFloat(playerid,"ZastitaTeleporta",1);
	PutPlayerInVehicle(playerid, vozilo, sediste);
	SetPVarInt(playerid, "SiguranTeleport", 1);
}
stock ghostac_SetVehicleToRespawn(idvozila)
{
    	foreach(Player, i)
    	{
    	    	new idvoz = GetPlayerVehicleID(i);
    	    	if(idvoz == idvozila)
    	    	{
	    	    	SetPVarInt(i, "PopravkaVozila", 1);
	    	    	SetVehicleToRespawn(idvozila);
	    	    	SetPVarInt(i, "PopravkaVozila", 1);
	    	    	return 1;
    	    	}
    	}
return 1;
}
