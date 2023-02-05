#if defined _fakeplayers_included
	#endinput
#endif
#define _fakeplayers_included

// ------------------------------------------------------------------------------------------------------------------------ //

#include <YSF>
#include <YSI_Core\y_utils>
#include <YSI_Data\y_iterate>
#include <YSI_Coding\y_hooks>

// ------------------------------------------------------------------------------------------------------------------------ //

#define			FAKEPLAYERS_PING			(130)
#define			FAKEPLAYERS_PING_AVG		(10)
#define			FAKEPLAYERS_SCRIPT			"fakeplayer"
#define			FAKEPLAYERS_ALLOW_BINDED_IP // Allow binded IP to connect NPCs.

enum E_FAKEPLAYERS
{
	Ping,
	Avg,
}

new FakePlayer[MAX_PLAYERS][E_FAKEPLAYERS];

#if defined FAKEPLAYERS_ALLOW_BINDED_IP
static bind_ip[16];
#endif

forward OnFakePlayerConnect(playerid);
forward OnFakePlayerDisconnect(playerid, reason);
//forward OnFakePlayerUpdate(playerid);
forward OnFakePlayerSpawn(playerid);

// ------------------------------------------------------------------------------------------------------------------------ //

stock ReturnNPCCommandLine(npcid)
{
	new npcscript[2000];
	GetNPCCommandLine(npcid, npcscript);
	return npcscript;
}

stock bool: IsValidNPC(playerid)
{
#if defined FAKEPLAYERS_ALLOW_BINDED_IP
	return (IsPlayerNPC(playerid) && (GetIP(playerid) == 0x7F000001 || GetIP(playerid) == IPToInt(bind_ip)));
#else
	return (IsPlayerNPC(playerid) && GetIP(playerid) == 0x7F000001);
#endif
}

stock bool: IsFakePlayer(playerid)
{
	if (IS_WINDOWS) return IsValidNPC(playerid);

	return(IsValidNPC(playerid) && strfind(ReturnNPCCommandLine(playerid), "-m "FAKEPLAYERS_SCRIPT"", true) != -1); // TODO: Fix.
}

stock ConnectBot(const name[])
	return ConnectNPC(name, FAKEPLAYERS_SCRIPT);

stock SetFakePlayerPing(playerid, ping)
{
	if (!IsValidNPC(playerid)) return 0;
	FakePlayer[playerid][Ping] = ping;
	return 1;
}

stock SetFakePlayerPingAvg(playerid, avg)
{
	if (!IsValidNPC(playerid)) return 0;
	FakePlayer[playerid][Avg] = avg;
	return 1;
}

// ------------------------------------------------------------------------------------------------------------------------ //

#if defined FILTERSCRIPT
hook OnFilterScripInit()
#else
hook OnGameModeInit()
#endif
{
#if defined FAKEPLAYERS_ALLOW_BINDED_IP
	GetConsoleVarAsString("bind", bind_ip, sizeof(bind_ip));
#endif
	YSF_ToggleNPCOnScoreboard(1);
	YSF_ToggleNPCOnQuery(1);
}

#if defined FILTERSCRIPT
hook OnFilterScripExit()
#else
hook OnGameModeExit()
#endif
{
	foreach (new i : NPC)
		Kick(i);
}

hook OnPlayerSpawn(playerid)
{
	if (IsValidNPC(playerid))
		CallLocalFunction("OnFakePlayerSpawn", "d", playerid);
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerConnect(playerid)
{
	if (IsValidNPC(playerid))
	{
		TogglePlayerFakePing(playerid, true);
		FakePlayer[playerid][Ping] = FAKEPLAYERS_PING;
		FakePlayer[playerid][Avg] = FAKEPLAYERS_PING_AVG;
		CallLocalFunction("OnFakePlayerConnect", "d", playerid);
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerDisconnect(playerid, reason)
{
	if (IsValidNPC(playerid))
		CallLocalFunction("OnFakePlayerDisconnect", "dd", playerid, reason);
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerUpdate(playerid)
{
	//CallLocalFunction("OnFakePlayerUpdate", "d", playerid);
	if (IsValidNPC(playerid))
		SetPlayerFakePing(playerid, Random(FakePlayer[playerid][Ping] - FakePlayer[playerid][Avg], FakePlayer[playerid][Ping] + FakePlayer[playerid][Avg] + 1));
	return Y_HOOKS_CONTINUE_RETURN_1;
}
