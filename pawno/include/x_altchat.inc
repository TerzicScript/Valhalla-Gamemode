/*
	Alternative chat
	Author: Xunder

	* Functions:
	native sendAltChatMessage(playerid, message[]);
        - Salje poruku igracu
        - Return 1 (uspjesno) : 0 (nije prikazan alt-chat/ne salje poruku)

    native createAltChat(playerid);
        - Kreira textdrawove za igraca
        - Return: 1 (uspjesno)

    native destroyAltChat(playerid);
        - Unistava textdrawove za igraca
        - Return: 1 (uspjesno)
        
    native toggleAltChat(playerid, bool: toggle = true);
        - Prikazuje/brise textdrawove za igraca
        - Return: 1 (uspjesno)

    native resetAltChat(playerid);
        - "Brise" svaki red u chatu
        - Return: 1 (uspjesno)

    native isAltChatToggled(playerid);
        - Dobijate povratnu informaciju da li je chat prikazan
        - Return: 1 (prikazan) : 0 (nije prikazan)
	
v1.1
* Promijenjena hook metoda
v1.2
* Nove funkcije za dodatno manipulisanje
*/
#if !defined _samp_included
	#error include a_samp first
#endif

#if !defined MAX_LINES
	#define MAX_LINES                               10
#endif

new PlayerText: AltChatTD_Player[MAX_LINES],
    AltChatTD_Text[MAX_PLAYERS][MAX_LINES][128],
    altchatToggled[MAX_PLAYERS] = false;

stock sendAltChatMessage(playerid, message[]) {
    if (!altchatToggled[playerid]) 
        return 0;

    for(new i = 0; i < MAX_LINES; i ++) {
        if (i == MAX_LINES - 1) {
            strmid(AltChatTD_Text[playerid][i], message, 0, 128);
            break;
        }
        strmid(AltChatTD_Text[playerid][i], AltChatTD_Text[playerid][i + 1], 0, 128);
    }

    for(new i = 0; i < MAX_LINES; i ++) {
        PlayerTextDrawSetString(playerid, AltChatTD_Player[i], AltChatTD_Text[playerid][i]);
    }
    return 1;
}

stock createAltChat(playerid) {
    new Float: AltChat_posY = 229.573348;
    
    for(new i = 0; i < MAX_LINES; i ++) {
        AltChatTD_Player[i] = CreatePlayerTextDraw(playerid, 35.599971, AltChat_posY, " ");
        PlayerTextDrawLetterSize(playerid, AltChatTD_Player[i], 0.21, 0.9);
        PlayerTextDrawAlignment(playerid, AltChatTD_Player[i], 1);
        PlayerTextDrawColor(playerid, AltChatTD_Player[i], -1);
        PlayerTextDrawSetOutline(playerid, AltChatTD_Player[i], 1);
        PlayerTextDrawBackgroundColor(playerid, AltChatTD_Player[i], 255);
        PlayerTextDrawFont(playerid, AltChatTD_Player[i], 1);
        PlayerTextDrawSetProportional(playerid, AltChatTD_Player[i], 1);

        AltChat_posY += (240.026733 - 229.573348);
    }

    altchatToggled[playerid] = false;

    return 1;
}

stock destroyAltChat(playerid) {
    for(new i = 0; i < MAX_LINES; i ++) {
        PlayerTextDrawDestroy(playerid, AltChatTD_Player[i]);
        AltChatTD_Player[i] = INVALID_TEXT_DRAW;
    }

    altchatToggled[playerid] = false;

    return 1;
}

stock resetAltChat(playerid) {
    for(new i = 0; i < MAX_LINES; i ++) {
        strmid(AltChatTD_Text[playerid][i], " ", 0, 2, 2);
        if (_: AltChatTD_Player[i] != INVALID_TEXT_DRAW) PlayerTextDrawSetString(playerid, AltChatTD_Player[i], " ");
    }

    return 1;
}

stock toggleAltChat(playerid, bool: toggle = true) {
    if (toggle) for(new i = 0; i < MAX_LINES; i ++) PlayerTextDrawShow(playerid, AltChatTD_Player[i]);
    else for(new i = 0; i < MAX_LINES; i ++) PlayerTextDrawHide(playerid, AltChatTD_Player[i]);

    altchatToggled[playerid] = toggle;
    return 1;
}

stock isAltChatToggled(playerid) {
    if (altchatToggled[playerid]) return 1;
    return 0;
}