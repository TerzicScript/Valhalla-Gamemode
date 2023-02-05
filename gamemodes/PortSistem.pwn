new odabranaPortVrsta[MAX_PLAYERS];

#define PORTING_FILE         "Portovi/Port_%d.ini"

#define MAX_PORTING 150

enum adminPortovi {

    portIme[64],
    Float:portPos[3],
    portVrsta
}

new portInfo[MAX_PORTING][adminPortovi];

forward UcitajPortove(portID, name[], value[]);
public UcitajPortove(portID, name[], value[])
{
    INI_String("portIme", portInfo[portID][portIme], 64);
    INI_Float("portPosX", portInfo[portID][portPos][0]);
    INI_Float("portPosY", portInfo[portID][portPos][1]);
    INI_Float("portPosZ", portInfo[portID][portPos][2]);
    INI_Int("portVrsta", portInfo[portID][portVrsta]);
    return 1;
}

SacuvajPort(portID)
{
    new fFile[128];
    format(fFile, 128, PORTING_FILE, portID);
    new INI:File = INI_Open(fFile);

    INI_WriteString(File, "portIme", portInfo[portID][portIme]);
    INI_WriteFloat(File, "portPosX", portInfo[portID][portPos][0]);
    INI_WriteFloat(File, "portPosY", portInfo[portID][portPos][1]);
    INI_WriteFloat(File, "portPosZ", portInfo[portID][portPos][2]);
    INI_WriteInt(File, "portVrsta", portInfo[portID][portVrsta]);

    INI_Close(File);
    return 1;
}

stock SledeciIDPort(const len) {
    new id = (-1);
    for( new loop = ( 0 ), provjera = ( -1 ), Data_[ 64 ] = "\0"; loop != len; ++ loop ) {
       provjera = ( loop+1 );
       format( Data_, ( sizeof Data_ ), PORTING_FILE, provjera );
       if(!fexist(Data_)) {
          id = ( provjera );
          break; } }
    return ( id );
}

GetNearestPort( playerid ) {
    for( new b = 0; b < sizeof(portInfo); b++) {
        if( IsPlayerInRangeOfPoint( playerid, 3.0, portInfo[b][portPos][0], portInfo[b][portPos][1], portInfo[b][portPos][2] ) ) return b; }
    return -1;
}

//////////////////////////////////////////

ShowPlayerDialog(playerid, dialog_portCreateVrsta, DIALOG_STYLE_LIST, "Odaberite Vrstu", "Beograd\nPoslovi\nOrganizacije\nSarajevo\nZagreb", "Odaberi", "Odustani");

//////////////////////////

if(listitem == 21) {

    new portID = GetNearestPort(playerid);
    if(portID == -1) return SendErrorMessage(playerid, "Nisi blizu nijednog porta!");

    new wFile[40], portNaziv[64];
    format(portNaziv, 64, "%s", portInfo[portID][portIme]);
    format(wFile, 40, PORTING_FILE, portID);
    if(fexist(wFile)) {

        fremove(wFile);
    }
    SendInfoMessage(playerid, "Port %s uspesno obrisan!", portNaziv);
}

////////////////////////////////////////

if(dialogid == dialog_selectPort && response) {

    new tmpcar = GetPlayerVehicleID( playerid );

    for(new id = 1; id < MAX_PORTING; id++)
    {

        new wFile[40];
        format(wFile, 40, PORTING_FILE, id);
        if(fexist(wFile))
        {

            if(!strcmp( portInfo[id][portIme], inputtext, true )) {

                if( GetPlayerState( playerid ) == 2 ) {
                    KGEyes_SetVehiclePos( tmpcar, portInfo[id][portPos][0], portInfo[id][portPos][1], portInfo[id][portPos][2] );
                    GameTextForPlayer( playerid, "Ucitavanje ...", 6000, 4 );
                    SetTimerEx("SlobodnoSada", 6000, false, "i", playerid );
                    SetCameraBehindPlayer( playerid );
                    TogglePlayerControllable( playerid, 0 );
                }
                else {
                    KGEyes_SetPlayerPos( playerid, portInfo[id][portPos][0], portInfo[id][portPos][1], portInfo[id][portPos][2] );
                }
                SetPlayerInterior( playerid, 0 );
                SetPlayerVirtualWorld( playerid, 0 );
                SendInfoMessage( playerid, "Teleportovao si kod %s.", portInfo[ id ][ portIme ] );

                if(PlayerInfo[playerid][xVIPLevel] >= 1) {

                    new time;
                    switch(PlayerInfo[playerid][xVIPLevel]) {

                        case 1: 
                            time = 180;
                        case 2, 3, 4:
                            time = 60;
                        case 5:
                            time = 45;
                        case 6:
                            time = 30;
                    }
                    VIPPort[ playerid ] = time;
                    SendInfoMessage(playerid, "Sledeci port mozete koristiti za %d sekundi!", time);
                }
                if(PlayerInfo[playerid][xPromoter] >= 1) {

                    PromoterPort[ playerid ] = 180;
                    SendInfoMessage(playerid, "Sledeci port mozete koristiti za 180 sekundi!");
                }

                return 1;
            }
        }
    }
    return 1;
}

if(dialogid == dialog_portCreateVrsta && response) {

    odabranaPortVrsta[playerid] = listitem + 1;

    ShowPlayerDialog(playerid, dialog_portCreateIme, DIALOG_STYLE_INPUT, "Naziv Porta", "Unesite ime porta koji kreirate", "Odaberi", "Odustani");

    return 1;
}

if(dialogid == dialog_portCreateIme) {

    if(!response) return odabranaPortVrsta[playerid] = -1;
    if(response) {

        new portID = SledeciIDPort(MAX_PORTING);
        if(portID == -1) return SendErrorMessage(playerid, "Dostignut je maksimum kreiranih portova!");

        new imePorta[64];
        if(sscanf(inputtext, "s[64]", imePorta)) return ShowPlayerDialog(playerid, dialog_portCreateIme, DIALOG_STYLE_INPUT, "Naziv Porta", "Unesite ime porta koji kreirate", "Odaberi", "Odustani");

        new Float:Pos[3];
        GetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);

        portInfo[portID][portPos][0] = Pos[0];
        portInfo[portID][portPos][1] = Pos[1];
        portInfo[portID][portPos][2] = Pos[2];
        portInfo[portID][portVrsta] = odabranaPortVrsta[playerid];

        strmid(portInfo[portID][portIme], imePorta, 0, strlen( imePorta ), 64 );

        SacuvajPort(portID);

        SendInfoMessage(playerid, "Port je uspesno kreiran!");

        return 1;
    }

    return 1;
}

if(dialogid == dialog_portVrsta && response) {

    if(listitem == 0) { //Beograd

        new string[128], BigString[2000];
        for(new id = 0; id < MAX_PORTING; id++)
        {
            new wFile[40];
            format(wFile, 40, PORTING_FILE, id);
            if(fexist(wFile))
            {
                if(portInfo[id][portVrsta] == 1) {

                    format(string, sizeof(string), "%s\n", portInfo[id][portIme]);
                    strcat(BigString, string);
                }
            }
        }
        if(isnull(BigString)) return SendErrorMessage(playerid, "Nema kreiranih portova!");

        ShowPlayerDialog(playerid, dialog_selectPort, DIALOG_STYLE_LIST, "Odaberi Port", BigString, "Odaberi", "Odustani");

        return 1;
    }
    if(listitem == 3) { //Poslovi

        new string[128], BigString[2000];
        for(new id = 0; id < MAX_PORTING; id++)
        {
            new wFile[40];
            format(wFile, 40, PORTING_FILE, id);
            if(fexist(wFile))
            {
                if(portInfo[id][portVrsta] == 2) {

                    format(string, sizeof(string), "%s\n", portInfo[id][portIme]);
                    strcat(BigString, string);
                }
            }
        }
        if(isnull(BigString)) return SendErrorMessage(playerid, "Nema kreiranih portova!");

        ShowPlayerDialog(playerid, dialog_selectPort, DIALOG_STYLE_LIST, "Odaberi Port", BigString, "Odaberi", "Odustani");

        return 1;
    }
    if(listitem == 4) { //Organizacije port

        new string[128], BigString[2000];
        for(new id = 0; id < MAX_PORTING; id++)
        {
            new wFile[40];
            format(wFile, 40, PORTING_FILE, id);
            if(fexist(wFile))
            {
                if(portInfo[id][portVrsta] == 3) {

                    format(string, sizeof(string), "%s\n", portInfo[id][portIme]);
                    strcat(BigString, string);
                }
            }
        }
        if(isnull(BigString)) return SendErrorMessage(playerid, "Nema kreiranih portova!");

        ShowPlayerDialog(playerid, dialog_selectPort, DIALOG_STYLE_LIST, "Odaberi Port", BigString, "Odaberi", "Odustani");

        return 1;
    }
    if(listitem == 1) { //Sarajevo

        new string[128], BigString[2000];
        for(new id = 0; id < MAX_PORTING; id++)
        {
            new wFile[40];
            format(wFile, 40, PORTING_FILE, id);
            if(fexist(wFile))
            {
                if(portInfo[id][portVrsta] == 4) {

                    format(string, sizeof(string), "%s\n", portInfo[id][portIme]);
                    strcat(BigString, string);
                }
            }
        }
        if(isnull(BigString)) return SendErrorMessage(playerid, "Nema kreiranih portova!");

        ShowPlayerDialog(playerid, dialog_selectPort, DIALOG_STYLE_LIST, "Odaberi Port", BigString, "Odaberi", "Odustani");

        return 1;
    }
    if(listitem == 2) { //Zagreb

        new string[128], BigString[2000];
        for(new id = 0; id < MAX_PORTING; id++)
        {
            new wFile[40];
            format(wFile, 40, PORTING_FILE, id);
            if(fexist(wFile))
            {
                if(portInfo[id][portVrsta] == 5) {

                    format(string, sizeof(string), "%s\n", portInfo[id][portIme]);
                    strcat(BigString, string);
                }
            }
        }
        if(isnull(BigString)) return SendErrorMessage(playerid, "Nema kreiranih portova!");

        ShowPlayerDialog(playerid, dialog_selectPort, DIALOG_STYLE_LIST, "Odaberi Port", BigString, "Odaberi", "Odustani");

        return 1;
    }

    return 1;
}
//////////////////////////////////////////

ShowPlayerDialog(playerid, dialog_portVrsta, DIALOG_STYLE_LIST, "Odaberi Vrstu", "Beograd\nSarajevo\nZagreb\nPoslovi\nOrganizacije", "Odaberi", "Odustani");


CMD:port(playerid) {

    if(PlayerInfo[playerid][xAdmin] >= 1) {

        if( PlayerInfo[ playerid ][ xAdmin ] < 7 ) {
            if( UzeoOpremu[ playerid ] == true ) return SendErrorMessage( playerid, "Ne mozes koristi ovu komandu dok radis posao ili imas uniformu posla." );
            if( PlayerInfo[ playerid ][ xWanted ] != 0 ) return SendErrorMessage( playerid, "Ne mozes koristi ovu komandu dok imas wanted level." );
            if( PlayerInfo[ playerid ][ xZatvor ] != 0 ) return SendErrorMessage( playerid, "Ne mozes koristi ovu komandu dok si u jailu." );
        }

        ShowPlayerDialog(playerid, dialog_portVrsta, DIALOG_STYLE_LIST, "Odaberi Vrstu", "Beograd\nSarajevo\nZagreb\nPoslovi\nOrganizacije", "Odaberi", "Odustani");

        return 1;
    }

    else if(PlayerInfo[playerid][xSupporter] >= 1) {

        // if( !AdminDuty[ playerid ] ) return SendErrorMessage( playerid, "Da bi koristili ovu komandu morate biti supp na duznosti." );
        if( NaDmEventu[ playerid ] == true ) return SendErrorMessage( playerid, "Ne mozes koristiti ovu komandu dok si u DM Zoni." );
        if( UzeoOpremu[ playerid ] == true ) return SendErrorMessage( playerid, "Ne mozes koristi ovu komandu dok radis posao ili imas uniformu posla." );
        if( PlayerInfo[ playerid ][ xWanted ] != 0 ) return SendErrorMessage( playerid, "Ne mozes koristi ovu komandu dok imas wanted level." );
        if( PlayerInfo[ playerid ][ xZatvor ] != 0 ) return SendErrorMessage( playerid, "Ne mozes koristi ovu komandu dok si u jailu." );
        
        ShowPlayerDialog(playerid, dialog_portVrsta, DIALOG_STYLE_LIST, "Odaberi Vrstu", "Beograd\nSarajevo\nZagreb\nPoslovi\nOrganizacije", "Odaberi", "Odustani");

        return 1;
    }

    else if(PlayerInfo[playerid][xVIPLevel] >= 1) {

        if( ProcesSvercanja[ playerid ] > 0 ) return SendErrorMessage( playerid, "Ne mozes se portati dok svercas." );
        if( NaUtrci[ playerid ] ) return SendErrorMessage( playerid, "Ne mozes dok si na trci." );
        if( NaDmEventu[ playerid ] == true ) return SendErrorMessage( playerid, "Ne mozes koristiti ovu komandu dok si na CS:DM." );
        if( WARPInfo[ playerid ][ WARIgrac ] != -1 ) return SendErrorMessage( playerid, "Ne mozes ovo dok si u waru." );
        if( tdm_player_info[ playerid ][ tdm_Team ] != 0 ) return SendErrorMessage( playerid, "Ne mozes ovo dok si na tdm eventu." );
        if( PoliceDuty[ playerid ] == true ) return SendErrorMessage( playerid, "Ne mozes koristi ovu komandu dok si na duznosti." );
        if( UzeoOpremu[ playerid ] == true ) return SendErrorMessage( playerid, "Ne mozes koristi ovu komandu dok radis posao ili imas uniformu posla." );
        if( ulazAuto[ playerid ] > gettime() ) return SendErrorMessage(playerid, "Ne mozes to dok ulazis/izlazis iz vozila, pokusaj opet za par sekundi!");
        if( PlayerInfo[ playerid ][ xZatvor ] != 0 ) return SendErrorMessage( playerid, "Ne mozes koristi ovu komandu dok si u jailu." );

        if( PlayerCP[ playerid ] > 0 ) return SendErrorMessage( playerid, "Ne mozes dok si na eventu." );
        if( naDeagle[ playerid ] > 0 ) return SendErrorMessage( playerid, "Ne mozes dok si na eventu." );
        if( PlayerInvited[ playerid ] > 0 ) return SendErrorMessage( playerid, "Ne mozes dok si na eventu." );

        if( VIPPort[ playerid ] != 0 ) return SendErrorMessage( playerid, "Jos %d sekundi do sledeceg porta.", VIPPort[ playerid ] );

        ShowPlayerDialog(playerid, dialog_portVrsta, DIALOG_STYLE_LIST, "Odaberi Vrstu", "Beograd\nSarajevo\nZagreb\nPoslovi\nOrganizacije", "Odaberi", "Odustani");

        return 1;
    }

    else if(PlayerInfo[playerid][xPromoter] >= 1) {

        if( ProcesSvercanja[ playerid ] > 0 ) return SendErrorMessage( playerid, "Ne mozes se portati dok svercas." );
        if( NaUtrci[ playerid ] ) return SendErrorMessage( playerid, "Ne mozes dok si na trci." );
        if( NaDmEventu[ playerid ] == true ) return SendErrorMessage( playerid, "Ne mozes koristiti ovu komandu dok si na CS:DM." );
        if( WARPInfo[ playerid ][ WARIgrac ] != -1 ) return SendErrorMessage( playerid, "Ne mozes ovo dok si u waru." );
        if( naDeagle[ playerid ] > 0 ) return SendErrorMessage( playerid, "Ne mozes dok si na eventu." );
        if( tdm_player_info[ playerid ][ tdm_Team ] != 0 ) return SendErrorMessage( playerid, "Ne mozes ovo dok si na tdm eventu." );
        if( PoliceDuty[ playerid ] == true ) return SendErrorMessage( playerid, "Ne mozes koristi ovu komandu dok si na duznosti." );
        if( ulazAuto[ playerid ] > gettime() ) return SendErrorMessage(playerid, "Ne mozes to dok ulazis/izlazis iz vozila, pokusaj opet za par sekundi!");
        if( UzeoOpremu[ playerid ] == true ) return SendErrorMessage( playerid, "Ne mozes koristi ovu komandu dok radis posao ili imas uniformu posla." );
        if( PlayerInfo[ playerid ][ xZatvor ] != 0 ) return SendErrorMessage( playerid, "Ne mozes koristi ovu komandu dok si u jailu." );
        if( PljackaUToku || ZlataraUToku ) return SendErrorMessage( playerid, "Ne mozes se portati dok je pljacka u toku." );
        if( uInterijeru[ playerid ] != -1 ) return SendErrorMessage( playerid, "Ne mozes da se portas dok si u interijeru.");

        if( PromoterPort[ playerid ] != 0 ) return SendErrorMessage( playerid, "Jos %d sekundi do sledeceg porta.", PromoterPort[ playerid ] );

        ShowPlayerDialog(playerid, dialog_portVrsta, DIALOG_STYLE_LIST, "Odaberi Vrstu", "Beograd\nSarajevo\nZagreb\nPoslovi\nOrganizacije", "Odaberi", "Odustani");

        return 1;
    }

    else return SendErrorMessage(playerid, "Nisi ovlascen!");
}