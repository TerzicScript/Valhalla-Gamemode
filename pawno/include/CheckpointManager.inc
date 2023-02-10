#if defined CP_INCLUDED__
	#error You have already included the CP Managment system elsewhere in this script.
#endif
#define CP_INCLUDED__

stock __SetPlayerCheckpoint(playerid, Float:cx, Float:cy, Float:cz, Float:size) //Creates the checkpoint
{
	SetPVarFloat(playerid, "CP_x", cx); SetPVarFloat(playerid, "CP_y", cy); SetPVarFloat(playerid, "CP_z", cz); SetPVarFloat(playerid, "CP_size", size);
	SetPVarInt(playerid, "CP_en", 1);
	SetPlayerCheckpoint(playerid, cx, cy, cz, size);
	return 1;
}

stock __DisablePlayerCheckpoint(playerid) //Disables the checkpoint
{
	if(GetPVarInt(playerid, "CP_en") != 1) return 0;
	DeletePVar(playerid, "CP_x"); DeletePVar(playerid, "CP_y"); DeletePVar(playerid, "CP_z"); DeletePVar(playerid, "CP_size");
	DisablePlayerCheckpoint(playerid);
	SetPVarInt(playerid, "CP_en", 0);
	return 1;
}

#define SetPlayerCheckpoint __SetPlayerCheckpoint
#define DisablePlayerCheckpoint __DisablePlayerCheckpoint

stock GetPlayerCheckpointPos(playerid, &Float:__x, &Float:__y, &Float:__z) //Return the checkpoint co-ordinates
{
	if(GetPVarInt(playerid, "CP_en") != 1) return 0;
	__x = GetPVarFloat(playerid, "CP_x");
	__y = GetPVarFloat(playerid, "CP_y");
	__z = GetPVarFloat(playerid, "CP_z");
	return 1;
}

stock GetPlayerCheckpointSize(playerid, &Float:__size) //Return the checkpoint size
{
	if(GetPVarInt(playerid, "CP_en") != 1) return 0;
	__size = GetPVarFloat(playerid, "CP_size");
	return 1;
}

stock IsPlayerInRangeOfCheckpoint(playerid, Float:range) //Are they in range of the checkpoint?
{
	if(GetPVarInt(playerid, "CP_en") != 1) return -1;
	if(IsPlayerInRangeOfPoint(playerid, range, GetPVarFloat(playerid, "CP_x"), GetPVarFloat(playerid, "CP_y"), GetPVarFloat(playerid, "CP_z")) return 1;
	return 0;
}

stock IsPlayerInOthersCheckpoint(playerid, playerid2) //Are they in another players checkpoint (Cheeky little player)
{
	if(GetPVarInt(playerid2, "CP_en") != 1) return -1;
	if(IsPlayerInRangeOfPoint(playerid, GetPVarFloat(playerid2, "CP_size"), GetPVarFloat(playerid2, "CP_x"), GetPVarFloat(playerid2, "CP_y"), GetPVarFloat("CP_z")) return 1;
	return 0;
}

stock SetPlayerCPAsPlayerCP(playerid, setplayerid) //Change a players checkpoint to another players
{
	if(GetPVarInt(playerid, "CP_en") != 1) return -1;
	SetPlayerCheckpoint(setplayerid, GetPVarFloat(playerid, "CP_x"), GetPVarFloat(playerid, "CP_y"), GetPVarFloat(playerid, "CP_z"), GetPVarFloat(playerid, "CP_size"));
	return 1;
}

/*
stock Float:GetDistanceToPlayerCheckpoint(playerid) //Get a distance to the checkpoint
{
	new Float:ax_, Float:ay_, Float:az_, Float:result;
	GetPlayerPos(playerid, ax_, ay_, az_);
	result = floatsqroot(floatpower(floatsub(ax_,GetPVarFloat(playerid, "CP_x")),2)+floatpower(floatsub(ay_,GetPVarFloat(playerid, "CP_y")),2)+floatpower(floatsub(az_,GetPVarFloat(playerid, "CP_z")),2));
	return result;
}
*/

stock CreateCheckpointHere(playerid, Float:size) //Not sure what this'd be used for though
{
	new Float:x_, Float:y_, Float:z_;
	GetPlayerPos(playerid, x_, y_, z_);
	SetPlayerCheckpoint(playerid, x_, y_, x_, size);
	return 1;
}
