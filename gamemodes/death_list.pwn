#include <YSI\y_hooks>

new deathCount;
new killerList[140];
new victimList[140];
new Text:tdDeathList[3];
new gDeathList[MAX_PLAYERS];

hook OnGameModeInit()
{
    deathCount = 0;
    killerList[0] = victimList[0] = EOS;

    tdDeathList[0] = TextDrawCreate(555.735290, 289.970428, "_");
    TextDrawLetterSize(tdDeathList[0], 0.168999, 1.056592);
    TextDrawAlignment(tdDeathList[0], 3);
    TextDrawColor(tdDeathList[0], -1);
    TextDrawSetShadow(tdDeathList[0], 0);
    TextDrawSetOutline(tdDeathList[0], -1);
    TextDrawBackgroundColor(tdDeathList[0], 255);
    TextDrawFont(tdDeathList[0], 1);
    TextDrawSetProportional(tdDeathList[0], 1);

    tdDeathList[1] = TextDrawCreate(564.203735, 289.970428, "_");
    TextDrawLetterSize(tdDeathList[1], 0.168999, 1.056592);
    TextDrawTextSize(tdDeathList[1], 0.000000, 500.000000);
    TextDrawAlignment(tdDeathList[1], 2);
    TextDrawColor(tdDeathList[1], -16776961);
    TextDrawSetShadow(tdDeathList[1], 0);
    TextDrawSetOutline(tdDeathList[1], -1);
    TextDrawBackgroundColor(tdDeathList[1], 255);
    TextDrawFont(tdDeathList[1], 1);
    TextDrawSetProportional(tdDeathList[1], 1);

    tdDeathList[2] = TextDrawCreate(571.401977, 289.970428, "_");
    TextDrawLetterSize(tdDeathList[2], 0.168999, 1.056592);
    TextDrawTextSize(tdDeathList[2], 500.000000, 0.000000);
    TextDrawAlignment(tdDeathList[2], 1);
    TextDrawColor(tdDeathList[2], -1);
    TextDrawSetShadow(tdDeathList[2], 0);
    TextDrawSetOutline(tdDeathList[2], -1);
    TextDrawBackgroundColor(tdDeathList[2], 255);
    TextDrawFont(tdDeathList[2], 1);
    TextDrawSetProportional(tdDeathList[2], 1);

    return true;
}

hook OnPlayerConnect(playerid)
{
    gDeathList[playerid] = true;
    return true;
}

hook OnPlayerSpawn(playerid)
{
    if (gDeathList[playerid])
    {
        TextDrawShowForPlayer(playerid, tdDeathList[0]);
        TextDrawShowForPlayer(playerid, tdDeathList[1]);
        TextDrawShowForPlayer(playerid, tdDeathList[2]);
    }
    return true;
}

hook OnPlayerDeath(playerid, killerid, reason)
{
    if (playerid != INVALID_PLAYER_ID && killerid != INVALID_PLAYER_ID)
    {
        deathCount ++;

        if (deathCount <= 5)
        {
            // Formatiranje iksica
            new str[21];
            str[0] = EOS;
            for (new i = 0; i < deathCount; i++)
            {
                format(str, sizeof str, "%sx~N~", str);
            }
            // Nakon 5 ubistava, vise se nece ni formatirati, vec ce ih uvek biti 5 (iksica)
            TextDrawSetString(tdDeathList[1], str);
        }
        if (deathCount > 5)
        {
            // Preko 5 smrti, brisemo prvo ime, pa tek onda dodajemo novo na kraj
            new delPos; 

            delPos = strfind(killerList, "~N~") + 3; // "+3" jer brise celo "~N~"
            strdel(killerList, 0, delPos);

            delPos = strfind(victimList, "~N~") + 3; // "+3" jer brise celo "~N~"
            strdel(victimList, 0, delPos);
        }
        
        format(killerList, sizeof killerList, "%s%s~N~", killerList, ImeIgraca(killerid));
        TextDrawSetString(tdDeathList[0], killerList);

        format(victimList, sizeof victimList, "%s%s~N~", victimList, ImeIgraca(playerid));
        TextDrawSetString(tdDeathList[2], victimList);
    }
    return true;
}

CMD:ubistva(playerid)
{
    if (!gDeathList[playerid])
    {
        SendInfoMessage(playerid, "* Ukljucili ste globalne poruke o ubistvima.");

        TextDrawShowForPlayer(playerid, tdDeathList[0]);
        TextDrawShowForPlayer(playerid, tdDeathList[1]);
        TextDrawShowForPlayer(playerid, tdDeathList[2]);
    }
    else
    {
        SendInfoMessage(playerid, "* Iskljucili ste globalne poruke o ubistvima.");
        
        TextDrawHideForPlayer(playerid, tdDeathList[0]);
        TextDrawHideForPlayer(playerid, tdDeathList[1]);
        TextDrawHideForPlayer(playerid, tdDeathList[2]);
    }

    gDeathList[playerid] = !gDeathList[playerid];
    return 1;
}