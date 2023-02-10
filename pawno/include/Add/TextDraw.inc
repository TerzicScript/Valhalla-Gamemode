#if defined _textdrawload
#endinput
#endif
#define _textdrawload
new PlayerText: KeysF[MAX_PLAYERS];
new PlayerText: Banned[MAX_PLAYERS][6];
new PlayerText: Killed[MAX_PLAYERS][9]; new PlayerText: NWSE[MAX_PLAYERS][14];
new PlayerText: LobbyMenu[MAX_PLAYERS][10];
new PlayerText: Registration[MAX_PLAYERS][5]; new PlayerText: RewMenu[MAX_PLAYERS][6];
new PlayerText: Indicators[MAX_PLAYERS][11];new PlayerText: TDProcess[MAX_PLAYERS][2]; new PlayerText: AdmSystem[MAX_PLAYERS][2];
new PlayerText: StatMenu[MAX_PLAYERS][11]; new PlayerText: SetMenu[MAX_PLAYERS][7];new PlayerText: CharMenu[MAX_PLAYERS][25];
new PlayerText: InvGun[MAX_PLAYERS][14]; new PlayerText: InvSlot[MAX_PLAYERS][89]; new PlayerText: InvStat[MAX_PLAYERS][10]; new PlayerText: TeamMatesHP[MAX_PLAYERS][6];
new PlayerText: Speedometr[MAX_PLAYERS][2]; new PlayerText: Sliders[MAX_PLAYERS][10]; new PlayerText: TeammateSearch[MAX_PLAYERS];
new PlayerText: HUD[MAX_PLAYERS][5]; new PlayerText: MAP[MAX_PLAYERS][3];
TextDrawLoad(playerid) {
	InvStat[playerid][0] = CreatePlayerTextDraw(playerid, 641.531494, 46.500000, "usebox");
	PlayerTextDrawLetterSize(playerid, InvStat[playerid][0], 0.360980, 1.448332);
	PlayerTextDrawAlignment(playerid, InvStat[playerid][0], 1);
	PlayerTextDrawColor(playerid, InvStat[playerid][0], 0);
	PlayerTextDrawUseBox(playerid, InvStat[playerid][0], true);
	PlayerTextDrawBoxColor(playerid, InvStat[playerid][0], 353703248);
	PlayerTextDrawSetShadow(playerid, InvStat[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, InvStat[playerid][0], 0);
	PlayerTextDrawFont(playerid, InvStat[playerid][0], 0);

	InvStat[playerid][1] = CreatePlayerTextDraw(playerid, 322.0, 90.0, "Alex_Dyson");
	PlayerTextDrawLetterSize(playerid, InvStat[playerid][1], 0.5, 1);
	PlayerTextDrawAlignment(playerid, InvStat[playerid][1], 2);
	PlayerTextDrawColor(playerid, InvStat[playerid][1], -1);
	PlayerTextDrawSetShadow(playerid, InvStat[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, InvStat[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, InvStat[playerid][1], 51);
	PlayerTextDrawFont(playerid, InvStat[playerid][1], 1);
	PlayerTextDrawSetProportional(playerid, InvStat[playerid][1], 1);
	PlayerTextDrawSetPreviewModel(playerid, InvStat[playerid][1], 0);
	PlayerTextDrawSetPreviewRot(playerid, InvStat[playerid][1], 0.000000, 0.000000, 0.000000, 0.000000);

	InvStat[playerid][2] = CreatePlayerTextDraw(playerid, 250.0, 103.991683, "New Textdraw");
	InvStat[playerid][3] = CreatePlayerTextDraw(playerid, 250.0, 183.075042, "New Textdraw");
	InvStat[playerid][4] = CreatePlayerTextDraw(playerid, 250.0, 220.183349, "New Textdraw");
	InvStat[playerid][5] = CreatePlayerTextDraw(playerid, 250.0, 257.933532, "New Textdraw");
	for(new td=2;td<6;td++) {
		PlayerTextDrawLetterSize(playerid, InvStat[playerid][td], 0.449999, 1.600000);
		PlayerTextDrawTextSize(playerid, InvStat[playerid][td], 30.000000, 35.000000);
		PlayerTextDrawAlignment(playerid, InvStat[playerid][td], 1);
		PlayerTextDrawColor(playerid, InvStat[playerid][td], -1);
		PlayerTextDrawUseBox(playerid, InvStat[playerid][td], true);
		PlayerTextDrawBoxColor(playerid, InvStat[playerid][td], 0);
		PlayerTextDrawSetShadow(playerid, InvStat[playerid][td], 0);
		PlayerTextDrawSetOutline(playerid, InvStat[playerid][td], 1);
		PlayerTextDrawBackgroundColor(playerid, InvStat[playerid][td], 353703280);
		PlayerTextDrawFont(playerid, InvStat[playerid][td], 5);
		PlayerTextDrawSetProportional(playerid, InvStat[playerid][td], 1);
		PlayerTextDrawSetSelectable(playerid, InvStat[playerid][td], true);
		PlayerTextDrawSetPreviewModel(playerid, InvStat[playerid][td], 1649);
		PlayerTextDrawSetPreviewRot(playerid, InvStat[playerid][td], 90.000000, 0.000000, 0.000000, 1.000000);
	}

	InvStat[playerid][6] = CreatePlayerTextDraw(playerid, 244.0, 183.416656, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, InvStat[playerid][6], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, InvStat[playerid][6], 4.216690, 109.666656);
	PlayerTextDrawAlignment(playerid, InvStat[playerid][6], 1);
	PlayerTextDrawColor(playerid, InvStat[playerid][6], 353703423);
	PlayerTextDrawSetShadow(playerid, InvStat[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, InvStat[playerid][6], 0);
	PlayerTextDrawFont(playerid, InvStat[playerid][6], 4);

	InvStat[playerid][7] = CreatePlayerTextDraw(playerid, 244.115524, 292.983551, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, InvStat[playerid][7], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, InvStat[playerid][7], 4.000000, -0.000000);
	PlayerTextDrawAlignment(playerid, InvStat[playerid][7], 1);
	PlayerTextDrawColor(playerid, InvStat[playerid][7], -1061109505);
	PlayerTextDrawSetShadow(playerid, InvStat[playerid][7], 0);
	PlayerTextDrawSetOutline(playerid, InvStat[playerid][7], 0);
	PlayerTextDrawFont(playerid, InvStat[playerid][7], 4);

	InvStat[playerid][8] = CreatePlayerTextDraw(playerid, 250.0, 138.991683, "New Textdraw");
	InvStat[playerid][9] = CreatePlayerTextDraw(playerid, 250.0, 218.075042, "New Textdraw");
	for(new td=8;td<10;td++) {
		PlayerTextDrawLetterSize(playerid, InvStat[playerid][td], 0.449999, 1.600000);
		PlayerTextDrawTextSize(playerid, InvStat[playerid][td], 30.000000, -35.000000);
		PlayerTextDrawAlignment(playerid, InvStat[playerid][td], 1);
		PlayerTextDrawColor(playerid, InvStat[playerid][td], -1);
		PlayerTextDrawUseBox(playerid, InvStat[playerid][td], true);
		PlayerTextDrawBoxColor(playerid, InvStat[playerid][td], 0);
		PlayerTextDrawSetShadow(playerid, InvStat[playerid][td], 0);
		PlayerTextDrawSetOutline(playerid, InvStat[playerid][td], 1);
		PlayerTextDrawBackgroundColor(playerid, InvStat[playerid][td], -16777136);
		PlayerTextDrawFont(playerid, InvStat[playerid][td], 5);
		PlayerTextDrawSetProportional(playerid, InvStat[playerid][td], 1);
		PlayerTextDrawSetSelectable(playerid, InvStat[playerid][td], true);
		PlayerTextDrawSetPreviewModel(playerid, InvStat[playerid][td], 1649);
		PlayerTextDrawSetPreviewRot(playerid, InvStat[playerid][td], 90.000000, 0.000000, 0.000000, 1.000000);
	}

	InvSlot[playerid][0] = CreatePlayerTextDraw(playerid, 30.641342, 103.216674, "New Textdraw");
	InvSlot[playerid][1] = CreatePlayerTextDraw(playerid, 30.563743, 136.358337, "New Textdraw");
	InvSlot[playerid][2] = CreatePlayerTextDraw(playerid, 30.720405, 169.733314, "New Textdraw");
	InvSlot[playerid][3] = CreatePlayerTextDraw(playerid, 30.689659, 203.166671, "New Textdraw");
	InvSlot[playerid][4] = CreatePlayerTextDraw(playerid, 30.658912, 237.066680, "New Textdraw");
	InvSlot[playerid][5] = CreatePlayerTextDraw(playerid, 30.534461, 270.325042, "New Textdraw");
	InvSlot[playerid][6] = CreatePlayerTextDraw(playerid, 30.550567, 303.933349, "New Textdraw");
	InvSlot[playerid][7] = CreatePlayerTextDraw(playerid, 30.613525, 337.308288, "New Textdraw");
	InvSlot[playerid][8] = CreatePlayerTextDraw(playerid, 30.629631, 371.208221, "New Textdraw");
	InvSlot[playerid][9] = CreatePlayerTextDraw(playerid, 30.692588, 405.174591, "New Textdraw");
	InvSlot[playerid][10] = CreatePlayerTextDraw(playerid, 140.478897, 103.216674, "New Textdraw");
	InvSlot[playerid][11] = CreatePlayerTextDraw(playerid, 140.478897, 136.358337, "New Textdraw");
	InvSlot[playerid][12] = CreatePlayerTextDraw(playerid, 140.478897, 169.733314, "New Textdraw");
	InvSlot[playerid][13] = CreatePlayerTextDraw(playerid, 140.478897, 203.166671, "New Textdraw");
	InvSlot[playerid][14] = CreatePlayerTextDraw(playerid, 140.478897, 237.066680, "New Textdraw");
	InvSlot[playerid][15] = CreatePlayerTextDraw(playerid, 140.478897, 270.325042, "New Textdraw");
	InvSlot[playerid][16] = CreatePlayerTextDraw(playerid, 140.478897, 303.933349, "New Textdraw");
	InvSlot[playerid][17] = CreatePlayerTextDraw(playerid, 140.478897, 337.308288, "New Textdraw");
	InvSlot[playerid][18] = CreatePlayerTextDraw(playerid, 140.478897, 371.208221, "New Textdraw");
	InvSlot[playerid][19] = CreatePlayerTextDraw(playerid, 140.478897, 405.174591, "New Textdraw");
	for(new td=0;td<20;td++) {
		PlayerTextDrawLetterSize(playerid, InvSlot[playerid][td], 0.449999, 1.600000);
		PlayerTextDrawTextSize(playerid, InvSlot[playerid][td], 25.000000, 30.000000);
		PlayerTextDrawAlignment(playerid, InvSlot[playerid][td], 1);
		PlayerTextDrawColor(playerid, InvSlot[playerid][td], -1);
		PlayerTextDrawUseBox(playerid, InvSlot[playerid][td], true);
		PlayerTextDrawBoxColor(playerid, InvSlot[playerid][td], 0);
		PlayerTextDrawSetShadow(playerid, InvSlot[playerid][td], 0);
		PlayerTextDrawSetOutline(playerid, InvSlot[playerid][td], 0);
		PlayerTextDrawBackgroundColor(playerid, InvSlot[playerid][td], -208);
		PlayerTextDrawFont(playerid, InvSlot[playerid][td], 5);
		PlayerTextDrawSetProportional(playerid, InvSlot[playerid][td], 1);
		PlayerTextDrawSetSelectable(playerid, InvSlot[playerid][td], true);
		PlayerTextDrawSetPreviewModel(playerid, InvSlot[playerid][td], 1649);
		PlayerTextDrawSetPreviewRot(playerid, InvSlot[playerid][td], 90.000000, 0.000000, 0.000000, 1.000000);
	}
	InvSlot[playerid][20] = CreatePlayerTextDraw(playerid, 31.032264, 103.166667, "123");
	InvSlot[playerid][21] = CreatePlayerTextDraw(playerid, 30.563743, 136.358337, "123");
	InvSlot[playerid][22] = CreatePlayerTextDraw(playerid, 30.720405, 169.733314, "123");
	InvSlot[playerid][23] = CreatePlayerTextDraw(playerid, 30.689659, 203.166671, "123");
	InvSlot[playerid][24] = CreatePlayerTextDraw(playerid, 30.658912, 237.066680, "123");
	InvSlot[playerid][25] = CreatePlayerTextDraw(playerid, 30.534461, 270.325042, "123");
	InvSlot[playerid][26] = CreatePlayerTextDraw(playerid, 30.550567, 303.933349, "123");
	InvSlot[playerid][27] = CreatePlayerTextDraw(playerid, 30.613525, 337.308288, "123");
	InvSlot[playerid][28] = CreatePlayerTextDraw(playerid, 30.629631, 371.208221, "123");
	InvSlot[playerid][29] = CreatePlayerTextDraw(playerid, 30.692588, 405.174591, "123");
	InvSlot[playerid][30] = CreatePlayerTextDraw(playerid, 140.307632, 103.216674, "123");
	InvSlot[playerid][31] = CreatePlayerTextDraw(playerid, 140.307632, 136.358337, "123");
	InvSlot[playerid][32] = CreatePlayerTextDraw(playerid, 140.307632, 169.733314, "123");
	InvSlot[playerid][33] = CreatePlayerTextDraw(playerid, 140.307632, 203.166671, "123");
	InvSlot[playerid][34] = CreatePlayerTextDraw(playerid, 140.307632, 237.066680, "123");
	InvSlot[playerid][35] = CreatePlayerTextDraw(playerid, 140.307632, 270.325042, "123");
	InvSlot[playerid][36] = CreatePlayerTextDraw(playerid, 140.307632, 303.933349, "123");
	InvSlot[playerid][37] = CreatePlayerTextDraw(playerid, 140.307632, 337.308288, "123");
	InvSlot[playerid][38] = CreatePlayerTextDraw(playerid, 140.307632, 371.208221, "123");
	InvSlot[playerid][39] = CreatePlayerTextDraw(playerid, 140.307632, 405.174591, "123");
	for(new td=20;td<40;td++) {
		PlayerTextDrawLetterSize(playerid, InvSlot[playerid][td], 0.449999, 1.600000);
		PlayerTextDrawTextSize(playerid, InvSlot[playerid][td], 95.0, 30.466674);
		PlayerTextDrawAlignment(playerid, InvSlot[playerid][td], 1);
		PlayerTextDrawColor(playerid, InvSlot[playerid][td], -1);
		PlayerTextDrawUseBox(playerid, InvSlot[playerid][td], true);
		PlayerTextDrawBoxColor(playerid, InvSlot[playerid][td], 0);
		PlayerTextDrawSetShadow(playerid, InvSlot[playerid][td], 0);
		PlayerTextDrawSetOutline(playerid, InvSlot[playerid][td], 0);
		PlayerTextDrawBackgroundColor(playerid, InvSlot[playerid][td], -240);
		PlayerTextDrawFont(playerid, InvSlot[playerid][td], 5);
		PlayerTextDrawSetProportional(playerid, InvSlot[playerid][td], 1);
		PlayerTextDrawSetSelectable(playerid, InvSlot[playerid][td], true);
		PlayerTextDrawSetPreviewModel(playerid, InvSlot[playerid][td], 1649);
		PlayerTextDrawSetPreviewRot(playerid, InvSlot[playerid][td], 90.000000, 0.000000, 90.000000, 1.000000);
	}
	InvSlot[playerid][40] = CreatePlayerTextDraw(playerid, 57.253280, 111.791633, "_");
	InvSlot[playerid][41] = CreatePlayerTextDraw(playerid, 57.253280, 144.874893, "_");
	InvSlot[playerid][42] = CreatePlayerTextDraw(playerid, 57.253280, 178.541625, "_");
	InvSlot[playerid][43] = CreatePlayerTextDraw(playerid, 57.253280, 211.799926, "_");
	InvSlot[playerid][44] = CreatePlayerTextDraw(playerid, 57.253280, 246.283370, "_");
	InvSlot[playerid][45] = CreatePlayerTextDraw(playerid, 57.253280, 278.958435, "_");
	InvSlot[playerid][46] = CreatePlayerTextDraw(playerid, 57.253280, 312.041809, "_");
	InvSlot[playerid][47] = CreatePlayerTextDraw(playerid, 57.253280, 345.883605, "_");
	InvSlot[playerid][48] = CreatePlayerTextDraw(playerid, 57.253280, 379.841735, "_");
	InvSlot[playerid][49] = CreatePlayerTextDraw(playerid, 57.253280, 413.683380, "_");
	InvSlot[playerid][50] = CreatePlayerTextDraw(playerid, 167.371780, 111.791633, "_");
	InvSlot[playerid][51] = CreatePlayerTextDraw(playerid, 167.371780, 144.874893, "_");
	InvSlot[playerid][52] = CreatePlayerTextDraw(playerid, 167.371780, 178.541625, "_");
	InvSlot[playerid][53] = CreatePlayerTextDraw(playerid, 167.371780, 211.799926, "_");
	InvSlot[playerid][54] = CreatePlayerTextDraw(playerid, 167.371780, 246.283370, "_");
	InvSlot[playerid][55] = CreatePlayerTextDraw(playerid, 167.371780, 278.958435, "_");
	InvSlot[playerid][56] = CreatePlayerTextDraw(playerid, 167.371780, 312.041809, "_");
	InvSlot[playerid][57] = CreatePlayerTextDraw(playerid, 167.371780, 345.883605, "_");
	InvSlot[playerid][58] = CreatePlayerTextDraw(playerid, 167.371780, 379.841735, "_");
	InvSlot[playerid][59] = CreatePlayerTextDraw(playerid, 167.371780, 413.683380, "_");
	for(new td=40;td<60;td++) {
		PlayerTextDrawLetterSize(playerid, InvSlot[playerid][td], 0.196061, 1.051666);
		PlayerTextDrawAlignment(playerid, InvSlot[playerid][td], 1);
		PlayerTextDrawColor(playerid, InvSlot[playerid][td], -1);
		PlayerTextDrawSetShadow(playerid, InvSlot[playerid][td], 0);
		PlayerTextDrawSetOutline(playerid, InvSlot[playerid][td], 0);
		PlayerTextDrawBackgroundColor(playerid, InvSlot[playerid][td], 51);
		PlayerTextDrawFont(playerid, InvSlot[playerid][td], 1);
		PlayerTextDrawSetProportional(playerid, InvSlot[playerid][td], 1);
	}
	InvSlot[playerid][60] = CreatePlayerTextDraw(playerid, 124.0, 111.891723, "_");
	InvSlot[playerid][61] = CreatePlayerTextDraw(playerid, 124.0, 145.133369, "_");
	InvSlot[playerid][62] = CreatePlayerTextDraw(playerid, 124.0, 177.733383, "_");
	InvSlot[playerid][63] = CreatePlayerTextDraw(playerid, 124.0, 211.558395, "_");
	InvSlot[playerid][64] = CreatePlayerTextDraw(playerid, 124.0, 244.741760, "_");
	InvSlot[playerid][65] = CreatePlayerTextDraw(playerid, 124.0, 279.150085, "_");
	InvSlot[playerid][66] = CreatePlayerTextDraw(playerid, 124.0, 312.508392, "_");
	InvSlot[playerid][67] = CreatePlayerTextDraw(playerid, 124.0, 345.866455, "_");
	InvSlot[playerid][68] = CreatePlayerTextDraw(playerid, 124.0, 379.574737, "_");
	InvSlot[playerid][69] = CreatePlayerTextDraw(playerid, 124.0, 412.875030, "_");
	InvSlot[playerid][70] = CreatePlayerTextDraw(playerid, 232.035034, 111.891723, "_");
	InvSlot[playerid][71] = CreatePlayerTextDraw(playerid, 232.035034, 145.133369, "_");
	InvSlot[playerid][72] = CreatePlayerTextDraw(playerid, 232.035034, 177.733383, "_");
	InvSlot[playerid][73] = CreatePlayerTextDraw(playerid, 232.035034, 211.558395, "_");
	InvSlot[playerid][74] = CreatePlayerTextDraw(playerid, 232.035034, 244.741760, "_");
	InvSlot[playerid][75] = CreatePlayerTextDraw(playerid, 232.035034, 279.150085, "_");
	InvSlot[playerid][76] = CreatePlayerTextDraw(playerid, 232.035034, 312.508392, "_");
	InvSlot[playerid][77] = CreatePlayerTextDraw(playerid, 232.035034, 345.866455, "_");
	InvSlot[playerid][78] = CreatePlayerTextDraw(playerid, 232.035034, 379.574737, "_");
	InvSlot[playerid][79] = CreatePlayerTextDraw(playerid, 232.035034, 412.875030, "_");
	for(new td=60;td<80;td++) {
		PlayerTextDrawLetterSize(playerid, InvSlot[playerid][td], 0.196061, 1.051666);
		PlayerTextDrawAlignment(playerid, InvSlot[playerid][td], 3);
		PlayerTextDrawColor(playerid, InvSlot[playerid][td], -1);
		PlayerTextDrawSetShadow(playerid, InvSlot[playerid][td], 0);
		PlayerTextDrawSetOutline(playerid, InvSlot[playerid][td], 0);
		PlayerTextDrawBackgroundColor(playerid, InvSlot[playerid][td], 51);
		PlayerTextDrawFont(playerid, InvSlot[playerid][td], 2);
		PlayerTextDrawSetProportional(playerid, InvSlot[playerid][td], 1);
	}
	InvSlot[playerid][80] = CreatePlayerTextDraw(playerid, 137.730895, 105.300010, "usebox");
	PlayerTextDrawLetterSize(playerid, InvSlot[playerid][80], 0.000000, 36.293556);
	PlayerTextDrawTextSize(playerid, InvSlot[playerid][80], 131.107040, 0.000000);
	PlayerTextDrawAlignment(playerid, InvSlot[playerid][80], 1);
	PlayerTextDrawColor(playerid, InvSlot[playerid][80], 0);
	PlayerTextDrawUseBox(playerid, InvSlot[playerid][80], true);
	PlayerTextDrawBoxColor(playerid, InvSlot[playerid][80], -251);
	PlayerTextDrawSetShadow(playerid, InvSlot[playerid][80], 0);
	PlayerTextDrawSetOutline(playerid, InvSlot[playerid][80], 0);
	PlayerTextDrawFont(playerid, InvSlot[playerid][80], 0);
	
	InvSlot[playerid][81] = CreatePlayerTextDraw(playerid, 188.019287, 102.891677, "123");
	PlayerTextDrawLetterSize(playerid, InvSlot[playerid][81], 0.449999, 1.600000);
	PlayerTextDrawTextSize(playerid, InvSlot[playerid][81], 50.000000, 55.000000);
	PlayerTextDrawAlignment(playerid, InvSlot[playerid][81], 1);
	PlayerTextDrawColor(playerid, InvSlot[playerid][81], -1);
	PlayerTextDrawUseBox(playerid, InvSlot[playerid][81], true);
	PlayerTextDrawBoxColor(playerid, InvSlot[playerid][81], 0);
	PlayerTextDrawSetShadow(playerid, InvSlot[playerid][81], 0);
	PlayerTextDrawSetOutline(playerid, InvSlot[playerid][81], 1);
	PlayerTextDrawBackgroundColor(playerid, InvSlot[playerid][81], -112);
	PlayerTextDrawFont(playerid, InvSlot[playerid][81], 5);
	PlayerTextDrawSetProportional(playerid, InvSlot[playerid][81], 1);
	PlayerTextDrawSetSelectable(playerid, InvSlot[playerid][81], true);
	PlayerTextDrawSetPreviewModel(playerid, InvSlot[playerid][81], 1);
	PlayerTextDrawSetPreviewRot(playerid, InvSlot[playerid][81], 0.000000, 0.000000, 0.000000, 1.000000);
	InvSlot[playerid][82] = CreatePlayerTextDraw(playerid, 187.923843, 147.2, "LD_SPAC:white");
	InvSlot[playerid][83] = CreatePlayerTextDraw(playerid, 210.897674, 147.2, "LD_SPAC:white");
	for(new td=82;td<84;td++) {
		PlayerTextDrawLetterSize(playerid, InvSlot[playerid][td], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, InvSlot[playerid][td], 27.500000, 10.500000);
		PlayerTextDrawAlignment(playerid, InvSlot[playerid][td], 1);
		PlayerTextDrawColor(playerid, InvSlot[playerid][td], -1);
		PlayerTextDrawSetShadow(playerid, InvSlot[playerid][td], 0);
		PlayerTextDrawSetOutline(playerid, InvSlot[playerid][td], 0);
		PlayerTextDrawFont(playerid, InvSlot[playerid][td], 4);
		PlayerTextDrawSetSelectable(playerid, InvSlot[playerid][td], true);
	}
	InvSlot[playerid][84] = CreatePlayerTextDraw(playerid, 193.873916, 149.999984, "USE______DROP");
	PlayerTextDrawLetterSize(playerid, InvSlot[playerid][84], 0.162795, 0.619998);
	PlayerTextDrawAlignment(playerid, InvSlot[playerid][84], 1);
	PlayerTextDrawColor(playerid, InvSlot[playerid][84], 255);
	PlayerTextDrawSetShadow(playerid, InvSlot[playerid][84], 0);
	PlayerTextDrawSetOutline(playerid, InvSlot[playerid][84], 0);
	PlayerTextDrawBackgroundColor(playerid, InvSlot[playerid][84], 51);
	PlayerTextDrawFont(playerid, InvSlot[playerid][84], 2);
	PlayerTextDrawSetProportional(playerid, InvSlot[playerid][84], 1);
	
	InvSlot[playerid][85] = CreatePlayerTextDraw(playerid, 128.281066, 269.174896, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, InvSlot[playerid][85], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, InvSlot[playerid][85], 2.000000, 165.000000);
	PlayerTextDrawAlignment(playerid, InvSlot[playerid][85], 1);
	PlayerTextDrawColor(playerid, InvSlot[playerid][85], -1);
	PlayerTextDrawSetShadow(playerid, InvSlot[playerid][85], 0);
	PlayerTextDrawSetOutline(playerid, InvSlot[playerid][85], 0);
	PlayerTextDrawFont(playerid, InvSlot[playerid][85], 4);
	PlayerTextDrawSetSelectable(playerid, InvSlot[playerid][85], true);

	InvSlot[playerid][86] = CreatePlayerTextDraw(playerid, 128.390792, 103.691638, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, InvSlot[playerid][86], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, InvSlot[playerid][86], 2.000000, 165.000000);
	PlayerTextDrawAlignment(playerid, InvSlot[playerid][86], 1);
	PlayerTextDrawColor(playerid, InvSlot[playerid][86], 353703423);
	PlayerTextDrawSetShadow(playerid, InvSlot[playerid][86], 0);
	PlayerTextDrawSetOutline(playerid, InvSlot[playerid][86], 0);
	PlayerTextDrawFont(playerid, InvSlot[playerid][86], 4);
	PlayerTextDrawSetSelectable(playerid, InvSlot[playerid][86], true);

	InvSlot[playerid][87] = CreatePlayerTextDraw(playerid, 240.648696, 104.099899, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, InvSlot[playerid][87], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, InvSlot[playerid][87], 2.000000, 165.000000);
	PlayerTextDrawAlignment(playerid, InvSlot[playerid][87], 1);
	PlayerTextDrawColor(playerid, InvSlot[playerid][87], -1);
	PlayerTextDrawSetShadow(playerid, InvSlot[playerid][87], 0);
	PlayerTextDrawSetOutline(playerid, InvSlot[playerid][87], 0);
	PlayerTextDrawFont(playerid, InvSlot[playerid][87], 4);
	PlayerTextDrawSetSelectable(playerid, InvSlot[playerid][87], true);

	InvSlot[playerid][88] = CreatePlayerTextDraw(playerid, 240.571105, 269.074859, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, InvSlot[playerid][88], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, InvSlot[playerid][88], 2.000000, 165.000000);
	PlayerTextDrawAlignment(playerid, InvSlot[playerid][88], 1);
	PlayerTextDrawColor(playerid, InvSlot[playerid][88], 353703935);
	PlayerTextDrawSetShadow(playerid, InvSlot[playerid][88], 0);
	PlayerTextDrawSetOutline(playerid, InvSlot[playerid][88], 0);
	PlayerTextDrawFont(playerid, InvSlot[playerid][88], 4);
	PlayerTextDrawSetSelectable(playerid, InvSlot[playerid][88], true);
	
	InvGun[playerid][0] = CreatePlayerTextDraw(playerid, 470.395812, 37.808320, "New Textdraw");
	InvGun[playerid][1] = CreatePlayerTextDraw(playerid, 469.990203, 118.275016, "New Textdraw");
	InvGun[playerid][2] = CreatePlayerTextDraw(playerid, 440.536193, 147.691741, "New Textdraw");
	InvGun[playerid][3] = CreatePlayerTextDraw(playerid, 428.011718, 338.858398, "New Textdraw");
	InvGun[playerid][4] = CreatePlayerTextDraw(playerid, 455.123199, 237.525054, "New Textdraw");
	for(new td=0;td<5;td++) {
		PlayerTextDrawLetterSize(playerid, InvGun[playerid][td], 0.449999, 1.600000);
		PlayerTextDrawTextSize(playerid, InvGun[playerid][td], 184.128814, 222.249969);
		PlayerTextDrawAlignment(playerid, InvGun[playerid][td], 1);
		PlayerTextDrawColor(playerid, InvGun[playerid][td], -1);
		PlayerTextDrawUseBox(playerid, InvGun[playerid][td], true);
		PlayerTextDrawBoxColor(playerid, InvGun[playerid][td], 0);
		PlayerTextDrawBackgroundColor(playerid, InvGun[playerid][td], 0x00000000);
		PlayerTextDrawSetShadow(playerid, InvGun[playerid][td], 0);
		PlayerTextDrawSetOutline(playerid, InvGun[playerid][td], 0);
		PlayerTextDrawFont(playerid, InvGun[playerid][td], 5);
		PlayerTextDrawSetProportional(playerid, InvGun[playerid][td], 1);
	}
	PlayerTextDrawTextSize(playerid, InvGun[playerid][2], 239.414306, 329.083190);
	PlayerTextDrawTextSize(playerid, InvGun[playerid][4], 239.414306, 329.083190);
	PlayerTextDrawTextSize(playerid, InvGun[playerid][3], 172.884246, 160.499885);
	PlayerTextDrawSetPreviewModel(playerid, InvGun[playerid][0], 356);
	PlayerTextDrawSetPreviewRot(playerid, InvGun[playerid][0], 30.000000, 0.000000, 0.000000, 3.000000);
	PlayerTextDrawSetPreviewModel(playerid, InvGun[playerid][1], 349);
	PlayerTextDrawSetPreviewRot(playerid, InvGun[playerid][1], 30.000000, 0.000000, 0.000000, 3.000000);
	PlayerTextDrawSetPreviewModel(playerid, InvGun[playerid][2], 348);
	PlayerTextDrawSetPreviewRot(playerid, InvGun[playerid][2], 0.000000, 0.000000, 0.000000, 3.000000);
	PlayerTextDrawSetPreviewModel(playerid, InvGun[playerid][3], 336);
	PlayerTextDrawSetPreviewRot(playerid, InvGun[playerid][3], 0.000000, 0.000000, 45.000000, 3.000000);
	PlayerTextDrawSetPreviewModel(playerid, InvGun[playerid][4], 342);
	PlayerTextDrawSetPreviewRot(playerid, InvGun[playerid][4], 0.000000, 0.000000, 45.000000, 3.000000);

	InvGun[playerid][5] = CreatePlayerTextDraw(playerid, 495.367675, 103.974998, "M4");
	InvGun[playerid][6] = CreatePlayerTextDraw(playerid, 495.290161, 183.141632, "SHOTGUN");
	InvGun[playerid][7] = CreatePlayerTextDraw(playerid, 495.353088, 263.474945, "DESERT EAGLE");
	InvGun[playerid][8] = CreatePlayerTextDraw(playerid, 495.415954, 344.974975, "BAT");
	InvGun[playerid][9] = CreatePlayerTextDraw(playerid, 560.134704, 344.808258, "GRENADE");
	for(new td=5;td<10;td++) {
		PlayerTextDrawLetterSize(playerid, InvGun[playerid][td], 0.217608, 1.751664);
		PlayerTextDrawAlignment(playerid, InvGun[playerid][td], 1);
		PlayerTextDrawColor(playerid, InvGun[playerid][td], -1);
		PlayerTextDrawSetShadow(playerid, InvGun[playerid][td], 0);
		PlayerTextDrawSetOutline(playerid, InvGun[playerid][td], 0);
		PlayerTextDrawBackgroundColor(playerid, InvGun[playerid][td], 51);
		PlayerTextDrawFont(playerid, InvGun[playerid][td], 2);
		PlayerTextDrawSetProportional(playerid, InvGun[playerid][td], 1);
	}

	InvGun[playerid][10] = CreatePlayerTextDraw(playerid, 605.533630, 103.808334, "5.56mm__0_I_48");
	InvGun[playerid][11] = CreatePlayerTextDraw(playerid, 605.596557, 183.558334, "12Gauge__0_I_58");
	InvGun[playerid][12] = CreatePlayerTextDraw(playerid, 605.659729, 263.891662, "9mm__0_I_15");
	for(new td=10;td<13;td++) {
		PlayerTextDrawLetterSize(playerid, InvGun[playerid][td], 0.160449, 1.325831);
		PlayerTextDrawAlignment(playerid, InvGun[playerid][td], 3);
		PlayerTextDrawColor(playerid, InvGun[playerid][td], -1);
		PlayerTextDrawSetShadow(playerid, InvGun[playerid][td], 0);
		PlayerTextDrawSetOutline(playerid, InvGun[playerid][td], 0);
		PlayerTextDrawBackgroundColor(playerid, InvGun[playerid][td], 51);
		PlayerTextDrawFont(playerid, InvGun[playerid][td], 1);
		PlayerTextDrawSetProportional(playerid, InvGun[playerid][td], 1);
	}
	InvGun[playerid][13] = CreatePlayerTextDraw(playerid, 604.861145, 430.008422, "x2");
	PlayerTextDrawLetterSize(playerid, InvGun[playerid][13], 0.286954, 1.314165);
	PlayerTextDrawAlignment(playerid, InvGun[playerid][13], 3);
	PlayerTextDrawColor(playerid, InvGun[playerid][13], -1);
	PlayerTextDrawUseBox(playerid, InvGun[playerid][13], true);
	PlayerTextDrawBoxColor(playerid, InvGun[playerid][13], 0);
	PlayerTextDrawSetShadow(playerid, InvGun[playerid][13], 0);
	PlayerTextDrawSetOutline(playerid, InvGun[playerid][13], 0);
	PlayerTextDrawBackgroundColor(playerid, InvGun[playerid][13], 51);
	PlayerTextDrawFont(playerid, InvGun[playerid][13], 2);
	PlayerTextDrawSetProportional(playerid, InvGun[playerid][13], 1);
	
	StatMenu[playerid][0] = CreatePlayerTextDraw(playerid, 335.587219, 67.416648, "usebox");
	PlayerTextDrawLetterSize(playerid, StatMenu[playerid][0], 0.000000, -0.363518);
	PlayerTextDrawTextSize(playerid, StatMenu[playerid][0], 630.035156, 0.000000);
	PlayerTextDrawAlignment(playerid, StatMenu[playerid][0], 1);
	PlayerTextDrawColor(playerid, StatMenu[playerid][0], 0);
	PlayerTextDrawUseBox(playerid, StatMenu[playerid][0], true);
	PlayerTextDrawBoxColor(playerid, StatMenu[playerid][0], -5963521);
	PlayerTextDrawSetShadow(playerid, StatMenu[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, StatMenu[playerid][0], 0);
	PlayerTextDrawFont(playerid, StatMenu[playerid][0], 0);

	StatMenu[playerid][1] = CreatePlayerTextDraw(playerid, 335.650085, 183.916610, "usebox");
	PlayerTextDrawLetterSize(playerid, StatMenu[playerid][1], 0.000000, -0.363518);
	PlayerTextDrawTextSize(playerid, StatMenu[playerid][1], 630.035278, 0.000000);
	PlayerTextDrawAlignment(playerid, StatMenu[playerid][1], 1);
	PlayerTextDrawColor(playerid, StatMenu[playerid][1], 0);
	PlayerTextDrawUseBox(playerid, StatMenu[playerid][1], true);
	PlayerTextDrawBoxColor(playerid, StatMenu[playerid][1], -5963521);
	PlayerTextDrawSetShadow(playerid, StatMenu[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, StatMenu[playerid][1], 0);
	PlayerTextDrawFont(playerid, StatMenu[playerid][1], 0);

	StatMenu[playerid][2] = CreatePlayerTextDraw(playerid, 336.181427, 180.833389, "usebox");
	PlayerTextDrawLetterSize(playerid, StatMenu[playerid][2], 0.000000, -12.685626);
	PlayerTextDrawTextSize(playerid, StatMenu[playerid][2], 629.566772, 0.000000);
	PlayerTextDrawAlignment(playerid, StatMenu[playerid][2], 1);
	PlayerTextDrawColor(playerid, StatMenu[playerid][2], 0);
	PlayerTextDrawUseBox(playerid, StatMenu[playerid][2], true);
	PlayerTextDrawBoxColor(playerid, StatMenu[playerid][2], 353703248);
	PlayerTextDrawSetShadow(playerid, StatMenu[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, StatMenu[playerid][2], 0);
	PlayerTextDrawFont(playerid, StatMenu[playerid][2], 0);

	StatMenu[playerid][3] = CreatePlayerTextDraw(playerid, 341.552032, 71.750030, "MURDER:_0");
	PlayerTextDrawLetterSize(playerid, StatMenu[playerid][3], 0.339428, 1.349166);
	PlayerTextDrawAlignment(playerid, StatMenu[playerid][3], 1);
	PlayerTextDrawColor(playerid, StatMenu[playerid][3], -5963521);
	PlayerTextDrawSetShadow(playerid, StatMenu[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, StatMenu[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, StatMenu[playerid][3], 51);
	PlayerTextDrawFont(playerid, StatMenu[playerid][3], 2);
	PlayerTextDrawSetProportional(playerid, StatMenu[playerid][3], 1);

	StatMenu[playerid][4] = CreatePlayerTextDraw(playerid, 360.0, 83.5, "HANDS: KNIFE: DESERT_EAGLE: 9mm: SILENCED_9mm: SHOTGUN: M4: AK-47: COUNTRY_RIFLE: GRENADE:");
	PlayerTextDrawLetterSize(playerid, StatMenu[playerid][4], 0.205569, 0.717998);
	PlayerTextDrawTextSize(playerid, StatMenu[playerid][4], 279.707183, 0.000000);
	PlayerTextDrawAlignment(playerid, StatMenu[playerid][4], 1);
	PlayerTextDrawColor(playerid, StatMenu[playerid][4], -1061109505);
	PlayerTextDrawUseBox(playerid, StatMenu[playerid][4], true);
	PlayerTextDrawBoxColor(playerid, StatMenu[playerid][4], 0);
	PlayerTextDrawSetShadow(playerid, StatMenu[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, StatMenu[playerid][4], 0);
	PlayerTextDrawBackgroundColor(playerid, StatMenu[playerid][4], 51);
	PlayerTextDrawFont(playerid, StatMenu[playerid][4], 2);
	PlayerTextDrawSetProportional(playerid, StatMenu[playerid][4], 1);
	
	StatMenu[playerid][5] = CreatePlayerTextDraw(playerid, 486.435272, 71.758346, "DEATHS:_0");
	PlayerTextDrawLetterSize(playerid, StatMenu[playerid][5], 0.339428, 1.349166);
	PlayerTextDrawAlignment(playerid, StatMenu[playerid][5], 1);
	PlayerTextDrawColor(playerid, StatMenu[playerid][5], -5963521);
	PlayerTextDrawSetShadow(playerid, StatMenu[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, StatMenu[playerid][5], 0);
	PlayerTextDrawBackgroundColor(playerid, StatMenu[playerid][5], 51);
	PlayerTextDrawFont(playerid, StatMenu[playerid][5], 2);
	PlayerTextDrawSetProportional(playerid, StatMenu[playerid][5], 1);

	StatMenu[playerid][6] = CreatePlayerTextDraw(playerid, 503.161315, 83.5, "HANDS: KNIFE: DESERT_EAGLE: 9mm: SILENCED_9mm: SHOTGUN: M4: AK-47: COUNTRY_RIFLE: GRENADE: OTHER:");
	PlayerTextDrawLetterSize(playerid, StatMenu[playerid][6], 0.205569, 0.717998);
	PlayerTextDrawTextSize(playerid, StatMenu[playerid][6], 279.707183, 0.000000);
	PlayerTextDrawAlignment(playerid, StatMenu[playerid][6], 1);
	PlayerTextDrawColor(playerid, StatMenu[playerid][6], -1061109505);
	PlayerTextDrawUseBox(playerid, StatMenu[playerid][6], true);
	PlayerTextDrawBoxColor(playerid, StatMenu[playerid][6], 0);
	PlayerTextDrawSetShadow(playerid, StatMenu[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, StatMenu[playerid][6], 0);
	PlayerTextDrawBackgroundColor(playerid, StatMenu[playerid][6], 51);
	PlayerTextDrawFont(playerid, StatMenu[playerid][6], 2);
	PlayerTextDrawSetProportional(playerid, StatMenu[playerid][6], 1);

	StatMenu[playerid][7] = CreatePlayerTextDraw(playerid, 434.161315, 83.5, "0 0 0 0 0 0 0 0 0 0");
	PlayerTextDrawLetterSize(playerid, StatMenu[playerid][7], 0.205569, 0.717998);
	PlayerTextDrawTextSize(playerid, StatMenu[playerid][7], 279.707183, 0.000000);
	PlayerTextDrawAlignment(playerid, StatMenu[playerid][7], 1);
	PlayerTextDrawColor(playerid, StatMenu[playerid][7], -1061109505);
	PlayerTextDrawUseBox(playerid, StatMenu[playerid][7], true);
	PlayerTextDrawBoxColor(playerid, StatMenu[playerid][7], 0);
	PlayerTextDrawSetShadow(playerid, StatMenu[playerid][7], 0);
	PlayerTextDrawSetOutline(playerid, StatMenu[playerid][7], 0);
	PlayerTextDrawBackgroundColor(playerid, StatMenu[playerid][7], 51);
	PlayerTextDrawFont(playerid, StatMenu[playerid][7], 2);
	PlayerTextDrawSetProportional(playerid, StatMenu[playerid][7], 1);

	StatMenu[playerid][8] = CreatePlayerTextDraw(playerid, 573.161315, 83.5, "0 0 0 0 0 0 0 0 0 0 0");
	PlayerTextDrawLetterSize(playerid, StatMenu[playerid][8], 0.205569, 0.717998);
	PlayerTextDrawTextSize(playerid, StatMenu[playerid][8], 279.707183, 0.000000);
	PlayerTextDrawAlignment(playerid, StatMenu[playerid][8], 1);
	PlayerTextDrawColor(playerid, StatMenu[playerid][8], -1061109505);
	PlayerTextDrawUseBox(playerid, StatMenu[playerid][8], true);
	PlayerTextDrawBoxColor(playerid, StatMenu[playerid][8], 0);
	PlayerTextDrawSetShadow(playerid, StatMenu[playerid][8], 0);
	PlayerTextDrawSetOutline(playerid, StatMenu[playerid][8], 0);
	PlayerTextDrawBackgroundColor(playerid, StatMenu[playerid][8], 51);
	PlayerTextDrawFont(playerid, StatMenu[playerid][8], 2);
	PlayerTextDrawSetProportional(playerid, StatMenu[playerid][8], 1);

	StatMenu[playerid][9] = CreatePlayerTextDraw(playerid, 341.661895, 161.416702, "PLAYED:_0");
	PlayerTextDrawLetterSize(playerid, StatMenu[playerid][9], 0.339428, 1.349166);
	PlayerTextDrawAlignment(playerid, StatMenu[playerid][9], 1);
	PlayerTextDrawColor(playerid, StatMenu[playerid][9], -5963521);
	PlayerTextDrawSetShadow(playerid, StatMenu[playerid][9], 0);
	PlayerTextDrawSetOutline(playerid, StatMenu[playerid][9], 0);
	PlayerTextDrawBackgroundColor(playerid, StatMenu[playerid][9], 51);
	PlayerTextDrawFont(playerid, StatMenu[playerid][9], 2);
	PlayerTextDrawSetProportional(playerid, StatMenu[playerid][9], 1);

	StatMenu[playerid][10] = CreatePlayerTextDraw(playerid, 486.451385, 161.250167, "WINS:_0");
	PlayerTextDrawLetterSize(playerid, StatMenu[playerid][10], 0.339428, 1.349166);
	PlayerTextDrawAlignment(playerid, StatMenu[playerid][10], 1);
	PlayerTextDrawColor(playerid, StatMenu[playerid][10], -5963521);
	PlayerTextDrawSetShadow(playerid, StatMenu[playerid][10], 0);
	PlayerTextDrawSetOutline(playerid, StatMenu[playerid][10], 0);
	PlayerTextDrawBackgroundColor(playerid, StatMenu[playerid][10], 51);
	PlayerTextDrawFont(playerid, StatMenu[playerid][10], 2);
	PlayerTextDrawSetProportional(playerid, StatMenu[playerid][10], 1);

	SetMenu[playerid][0] = CreatePlayerTextDraw(playerid, 338.272338, 68.833351, "TEXT_DRAW_LANGUAGE:");
	PlayerTextDrawLetterSize(playerid, SetMenu[playerid][0], 0.194187, 1.110000);
	PlayerTextDrawAlignment(playerid, SetMenu[playerid][0], 1);
	PlayerTextDrawColor(playerid, SetMenu[playerid][0], -1061109505);
	PlayerTextDrawSetShadow(playerid, SetMenu[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, SetMenu[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, SetMenu[playerid][0], 51);
	PlayerTextDrawFont(playerid, SetMenu[playerid][0], 2);
	PlayerTextDrawSetProportional(playerid, SetMenu[playerid][0], 1);

	SetMenu[playerid][1] = CreatePlayerTextDraw(playerid, 338.382049, 78.175025, "LANGUAGE:");
	PlayerTextDrawLetterSize(playerid, SetMenu[playerid][1], 0.194187, 1.110000);
	PlayerTextDrawAlignment(playerid, SetMenu[playerid][1], 1);
	PlayerTextDrawColor(playerid, SetMenu[playerid][1], -1061109505);
	PlayerTextDrawSetShadow(playerid, SetMenu[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, SetMenu[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, SetMenu[playerid][1], 51);
	PlayerTextDrawFont(playerid, SetMenu[playerid][1], 2);
	PlayerTextDrawSetProportional(playerid, SetMenu[playerid][1], 1);

	SetMenu[playerid][2] = CreatePlayerTextDraw(playerid, 467.647277, 68.958335, "ENGLISH");
	PlayerTextDrawLetterSize(playerid, SetMenu[playerid][2], 0.194187, 1.110000);
	PlayerTextDrawAlignment(playerid, SetMenu[playerid][2], 2);
	PlayerTextDrawColor(playerid, SetMenu[playerid][2], -1061109505);
	PlayerTextDrawSetShadow(playerid, SetMenu[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, SetMenu[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, SetMenu[playerid][2], 51);
	PlayerTextDrawFont(playerid, SetMenu[playerid][2], 2);
	PlayerTextDrawSetProportional(playerid, SetMenu[playerid][2], 1);

	SetMenu[playerid][3] = CreatePlayerTextDraw(playerid, 416.969299, 78.066688, "RUSSIAN");
	PlayerTextDrawLetterSize(playerid, SetMenu[playerid][3], 0.194187, 1.110000);
	PlayerTextDrawAlignment(playerid, SetMenu[playerid][3], 2);
	PlayerTextDrawColor(playerid, SetMenu[playerid][3], -1061109505);
	PlayerTextDrawSetShadow(playerid, SetMenu[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, SetMenu[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, SetMenu[playerid][3], 51);
	PlayerTextDrawFont(playerid, SetMenu[playerid][3], 2);
	PlayerTextDrawSetProportional(playerid, SetMenu[playerid][3], 1);

	SetMenu[playerid][4] = CreatePlayerTextDraw(playerid, 348.222717, 88.816696, "_");//personal_message
	SetMenu[playerid][5] = CreatePlayerTextDraw(playerid, 348.332641, 99.266693, "_");//The_blacked_out_inventory
	SetMenu[playerid][6] = CreatePlayerTextDraw(playerid, 348.582946, 110.941703, "_");//Radar_at_the_top_of_the_screen
	for(new td=4;td<7;td++) {
		PlayerTextDrawLetterSize(playerid, SetMenu[playerid][td], 0.194187, 1.110000);
		PlayerTextDrawAlignment(playerid, SetMenu[playerid][td], 1);
		PlayerTextDrawColor(playerid, SetMenu[playerid][td], -1061109505);
		PlayerTextDrawSetShadow(playerid, SetMenu[playerid][td], 0);
		PlayerTextDrawSetOutline(playerid, SetMenu[playerid][td], 0);
		PlayerTextDrawBackgroundColor(playerid, SetMenu[playerid][td], 51);
		PlayerTextDrawFont(playerid, SetMenu[playerid][td], 2);
		PlayerTextDrawSetProportional(playerid, SetMenu[playerid][td], 1);
	}
	Indicators[playerid][0] = CreatePlayerTextDraw(playerid, 546.015319, 0.299997, "LD_SPAC:white");
	Indicators[playerid][1] = CreatePlayerTextDraw(playerid, 465.492492, 0.299997, "LD_SPAC:white");
	for(new td=0;td<2;td++) {
		PlayerTextDrawLetterSize(playerid, Indicators[playerid][td], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, Indicators[playerid][td], 22.816978, 24.0);
		PlayerTextDrawAlignment(playerid, Indicators[playerid][td], 1);
		PlayerTextDrawColor(playerid, Indicators[playerid][td], 0x151515FF);
		PlayerTextDrawSetShadow(playerid, Indicators[playerid][td], 0);
		PlayerTextDrawSetOutline(playerid, Indicators[playerid][td], 0);
		PlayerTextDrawFont(playerid, Indicators[playerid][td], 4);
	}
	Indicators[playerid][2] = CreatePlayerTextDraw(playerid, 487.842895, 0.299997, "LD_SPAC:white");
	Indicators[playerid][3] = CreatePlayerTextDraw(playerid, 568.365722, 0.299997, "LD_SPAC:white");
	for(new td=2;td<4;td++) {
		PlayerTextDrawLetterSize(playerid, Indicators[playerid][td], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, Indicators[playerid][td], 52.802330, 24.0);
		PlayerTextDrawAlignment(playerid, Indicators[playerid][td], 1);
		PlayerTextDrawColor(playerid, Indicators[playerid][td], -1061109505);
		PlayerTextDrawSetShadow(playerid, Indicators[playerid][td], 0);
		PlayerTextDrawSetOutline(playerid, Indicators[playerid][td], 0);
		PlayerTextDrawFont(playerid, Indicators[playerid][td], 4);
	}
	Indicators[playerid][4] = CreatePlayerTextDraw(playerid, 476.954895, 0.349981, "_");//100
	Indicators[playerid][5] = CreatePlayerTextDraw(playerid, 557.603698, 0.358314, "_");//100
	for(new td=4;td<6;td++) {
		PlayerTextDrawLetterSize(playerid, Indicators[playerid][td], 0.341771, 2.346666);
		PlayerTextDrawAlignment(playerid, Indicators[playerid][td], 2);
		PlayerTextDrawColor(playerid, Indicators[playerid][td], -1061109505);
		PlayerTextDrawSetShadow(playerid, Indicators[playerid][td], 0);
		PlayerTextDrawSetOutline(playerid, Indicators[playerid][td], 0);
		PlayerTextDrawBackgroundColor(playerid, Indicators[playerid][td], 51);
		PlayerTextDrawFont(playerid, Indicators[playerid][td], 2);
		PlayerTextDrawSetProportional(playerid, Indicators[playerid][td], 1);
	}
	Indicators[playerid][6] = CreatePlayerTextDraw(playerid, 513.688659, 0.358314, "_");//УБИЙСТВ 507.940399
	Indicators[playerid][7] = CreatePlayerTextDraw(playerid, 594.211486, 0.483314, "_");//В ЖИВЫХ
	for(new td=6;td<8;td++) {
		PlayerTextDrawLetterSize(playerid, Indicators[playerid][td], 0.277114, 2.346666);
		PlayerTextDrawAlignment(playerid, Indicators[playerid][td], 2);
		PlayerTextDrawColor(playerid, Indicators[playerid][td], 0x151515FF);
		PlayerTextDrawSetShadow(playerid, Indicators[playerid][td], 0);
		PlayerTextDrawSetOutline(playerid, Indicators[playerid][td], 0);
		PlayerTextDrawBackgroundColor(playerid, Indicators[playerid][td], 51);
		PlayerTextDrawFont(playerid, Indicators[playerid][td], 2);
		PlayerTextDrawSetProportional(playerid, Indicators[playerid][td], 1);
	}
	Indicators[playerid][8] = CreatePlayerTextDraw(playerid, 317.657379, 297.466613, "MATCH_STARTS");
	PlayerTextDrawLetterSize(playerid, Indicators[playerid][8], 0.312114, 2.350162);
	PlayerTextDrawAlignment(playerid, Indicators[playerid][8], 2);
	PlayerTextDrawColor(playerid, Indicators[playerid][8], -1829653249);
	PlayerTextDrawSetShadow(playerid, Indicators[playerid][8], 1);
	PlayerTextDrawSetOutline(playerid, Indicators[playerid][8], 0);
	PlayerTextDrawBackgroundColor(playerid, Indicators[playerid][8], 255);
	PlayerTextDrawFont(playerid, Indicators[playerid][8], 2);
	PlayerTextDrawSetProportional(playerid, Indicators[playerid][8], 1);

	Indicators[playerid][9] = CreatePlayerTextDraw(playerid, 318.142028, 315.850006, "90");
	PlayerTextDrawLetterSize(playerid, Indicators[playerid][9], 0.312114, 2.350163);
	PlayerTextDrawAlignment(playerid, Indicators[playerid][9], 2);
	PlayerTextDrawColor(playerid, Indicators[playerid][9], -1829653249);
	PlayerTextDrawSetShadow(playerid, Indicators[playerid][9], 1);
	PlayerTextDrawSetOutline(playerid, Indicators[playerid][9], 0);
	PlayerTextDrawBackgroundColor(playerid, Indicators[playerid][9], 255);
	PlayerTextDrawFont(playerid, Indicators[playerid][9], 2);
	PlayerTextDrawSetProportional(playerid, Indicators[playerid][9], 1);
	
	Indicators[playerid][10] = CreatePlayerTextDraw(playerid, 318.001434, 297.216644, "_");
	PlayerTextDrawLetterSize(playerid, Indicators[playerid][10], 0.213724, 1.597661);
	PlayerTextDrawAlignment(playerid, Indicators[playerid][10], 2);
	PlayerTextDrawColor(playerid, Indicators[playerid][10], -1);
	PlayerTextDrawSetShadow(playerid, Indicators[playerid][10], 0);
	PlayerTextDrawSetOutline(playerid, Indicators[playerid][10], 0);
	PlayerTextDrawBackgroundColor(playerid, Indicators[playerid][10], 255);
	PlayerTextDrawFont(playerid, Indicators[playerid][10], 2);
	PlayerTextDrawSetProportional(playerid, Indicators[playerid][10], 1);
	
	TDProcess[playerid][0] = CreatePlayerTextDraw(playerid, 300.228454, 207.199996, "particle:target256");
	PlayerTextDrawLetterSize(playerid, TDProcess[playerid][0], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, TDProcess[playerid][0], 43.385070, 32.666679);
	PlayerTextDrawAlignment(playerid, TDProcess[playerid][0], 1);
	PlayerTextDrawColor(playerid, TDProcess[playerid][0], -1);
	PlayerTextDrawSetShadow(playerid, TDProcess[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, TDProcess[playerid][0], 0);
	PlayerTextDrawFont(playerid, TDProcess[playerid][0], 4);

	TDProcess[playerid][1] = CreatePlayerTextDraw(playerid, 321.686706, 214.900009, "_");
	PlayerTextDrawLetterSize(playerid, TDProcess[playerid][1], 0.449999, 1.600000);
	PlayerTextDrawAlignment(playerid, TDProcess[playerid][1], 2);
	PlayerTextDrawColor(playerid, TDProcess[playerid][1], -1);
	PlayerTextDrawUseBox(playerid, TDProcess[playerid][1], true);
	PlayerTextDrawBoxColor(playerid, TDProcess[playerid][1], 0);
	PlayerTextDrawSetShadow(playerid, TDProcess[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, TDProcess[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, TDProcess[playerid][1], 51);
	PlayerTextDrawFont(playerid, TDProcess[playerid][1], 1);
	PlayerTextDrawSetProportional(playerid, TDProcess[playerid][1], 1);
	
	LobbyMenu[playerid][0] = CreatePlayerTextDraw(playerid, 9.510991, 3.091645, "PLAY");
	PlayerTextDrawLetterSize(playerid, LobbyMenu[playerid][0], 0.575092, 3.869163);
	PlayerTextDrawTextSize(playerid, LobbyMenu[playerid][0], 91.361618, 24.166687);
	PlayerTextDrawAlignment(playerid, LobbyMenu[playerid][0], 1);
	PlayerTextDrawColor(playerid, LobbyMenu[playerid][0], -608460033);
	PlayerTextDrawUseBox(playerid, LobbyMenu[playerid][0], true);
	PlayerTextDrawBoxColor(playerid, LobbyMenu[playerid][0], 0);
	PlayerTextDrawSetShadow(playerid, LobbyMenu[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, LobbyMenu[playerid][0], -1);
	PlayerTextDrawBackgroundColor(playerid, LobbyMenu[playerid][0], 353703184);
	PlayerTextDrawFont(playerid, LobbyMenu[playerid][0], 2);
	PlayerTextDrawSetProportional(playerid, LobbyMenu[playerid][0], 1);
	PlayerTextDrawSetSelectable(playerid, LobbyMenu[playerid][0], true);
	LobbyMenu[playerid][1] = CreatePlayerTextDraw(playerid, 456.0, 14.000000, "REWARDS");
	LobbyMenu[playerid][2] = CreatePlayerTextDraw(playerid, 373.0, 14.000000, "CHARACTER");
	LobbyMenu[playerid][3] = CreatePlayerTextDraw(playerid, 539.0, 14.000000, "STATISTICS");
	for(new td=1;td<4;td++) {
		PlayerTextDrawLetterSize(playerid, LobbyMenu[playerid][td], 0.276645, 1.780832);
		PlayerTextDrawTextSize(playerid, LobbyMenu[playerid][td], 12.000000, 72.333335);
		PlayerTextDrawAlignment(playerid, LobbyMenu[playerid][td], 2);
		PlayerTextDrawColor(playerid, LobbyMenu[playerid][td], -1061109505);
		PlayerTextDrawUseBox(playerid, LobbyMenu[playerid][td], true);
		PlayerTextDrawBoxColor(playerid, LobbyMenu[playerid][td], -256);
		PlayerTextDrawSetShadow(playerid, LobbyMenu[playerid][td], 0);
		PlayerTextDrawSetOutline(playerid, LobbyMenu[playerid][td], 0);
		PlayerTextDrawBackgroundColor(playerid, LobbyMenu[playerid][td], 51);
		PlayerTextDrawFont(playerid, LobbyMenu[playerid][td], 2);
		PlayerTextDrawSetProportional(playerid, LobbyMenu[playerid][td], 1);
		PlayerTextDrawSetSelectable(playerid, LobbyMenu[playerid][td], true);
	}
	LobbyMenu[playerid][4] = CreatePlayerTextDraw(playerid, 574.594421, 40.483345, "_");//Nick_Name
	PlayerTextDrawLetterSize(playerid, LobbyMenu[playerid][4], 0.332400, 1.325833);
	PlayerTextDrawAlignment(playerid, LobbyMenu[playerid][4], 3);
	PlayerTextDrawColor(playerid, LobbyMenu[playerid][4], -1);
	LobbyMenu[playerid][5] = CreatePlayerTextDraw(playerid, 592.789367, 38.625019, "_");//BP
	PlayerTextDrawLetterSize(playerid, LobbyMenu[playerid][5], 0.247128, 1.734166);
	PlayerTextDrawAlignment(playerid, LobbyMenu[playerid][5], 1);
	PlayerTextDrawColor(playerid, LobbyMenu[playerid][5], -5963521);
	for(new td=4;td<6;td++) {
		PlayerTextDrawSetShadow(playerid, LobbyMenu[playerid][td], 0);
		PlayerTextDrawSetOutline(playerid, LobbyMenu[playerid][td], 0);
		PlayerTextDrawBackgroundColor(playerid, LobbyMenu[playerid][td], 255);
		PlayerTextDrawFont(playerid, LobbyMenu[playerid][td], 2);
		PlayerTextDrawSetProportional(playerid, LobbyMenu[playerid][td], 1);
	}
	LobbyMenu[playerid][6] = CreatePlayerTextDraw(playerid, 92.286964, 417.783447, "none");
	PlayerTextDrawLetterSize(playerid, LobbyMenu[playerid][6], 0.215269, 1.039999);
	PlayerTextDrawAlignment(playerid, LobbyMenu[playerid][6], 2);
	PlayerTextDrawColor(playerid, LobbyMenu[playerid][6], -1);
	PlayerTextDrawSetShadow(playerid, LobbyMenu[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, LobbyMenu[playerid][6], 0);
	PlayerTextDrawBackgroundColor(playerid, LobbyMenu[playerid][6], 51);
	PlayerTextDrawFont(playerid, LobbyMenu[playerid][6], 1);
	PlayerTextDrawSetProportional(playerid, LobbyMenu[playerid][6], 1);

	LobbyMenu[playerid][7] = CreatePlayerTextDraw(playerid, 186.428939, 417.791564, "none");
	PlayerTextDrawLetterSize(playerid, LobbyMenu[playerid][7], 0.215269, 1.039999);
	PlayerTextDrawAlignment(playerid, LobbyMenu[playerid][7], 2);
	PlayerTextDrawColor(playerid, LobbyMenu[playerid][7], -1061109505);
	PlayerTextDrawSetShadow(playerid, LobbyMenu[playerid][7], 0);
	PlayerTextDrawSetOutline(playerid, LobbyMenu[playerid][7], 0);
	PlayerTextDrawBackgroundColor(playerid, LobbyMenu[playerid][7], 51);
	PlayerTextDrawFont(playerid, LobbyMenu[playerid][7], 1);
	PlayerTextDrawSetProportional(playerid, LobbyMenu[playerid][7], 1);

	LobbyMenu[playerid][8] = CreatePlayerTextDraw(playerid, 280.336761, 417.683258, "none");
	PlayerTextDrawLetterSize(playerid, LobbyMenu[playerid][8], 0.215269, 1.039999);
	PlayerTextDrawAlignment(playerid, LobbyMenu[playerid][8], 2);
	PlayerTextDrawColor(playerid, LobbyMenu[playerid][8], -1);
	PlayerTextDrawSetShadow(playerid, LobbyMenu[playerid][8], 0);
	PlayerTextDrawSetOutline(playerid, LobbyMenu[playerid][8], 0);
	PlayerTextDrawBackgroundColor(playerid, LobbyMenu[playerid][8], 51);
	PlayerTextDrawFont(playerid, LobbyMenu[playerid][8], 1);
	PlayerTextDrawSetProportional(playerid, LobbyMenu[playerid][8], 1);

	LobbyMenu[playerid][9] = CreatePlayerTextDraw(playerid, 374.244415, 417.574890, "none");
	PlayerTextDrawLetterSize(playerid, LobbyMenu[playerid][9], 0.215269, 1.039999);
	PlayerTextDrawAlignment(playerid, LobbyMenu[playerid][9], 2);
	PlayerTextDrawColor(playerid, LobbyMenu[playerid][9], -1061109505);
	PlayerTextDrawSetShadow(playerid, LobbyMenu[playerid][9], 0);
	PlayerTextDrawSetOutline(playerid, LobbyMenu[playerid][9], 0);
	PlayerTextDrawBackgroundColor(playerid, LobbyMenu[playerid][9], 51);
	PlayerTextDrawFont(playerid, LobbyMenu[playerid][9], 1);
	PlayerTextDrawSetProportional(playerid, LobbyMenu[playerid][9], 1);
	
	Registration[playerid][0] = CreatePlayerTextDraw(playerid, 322.061218, 171.616668, "_");//REGISTRATION
	PlayerTextDrawLetterSize(playerid, Registration[playerid][0], 0.539862, 2.477916);
	PlayerTextDrawAlignment(playerid, Registration[playerid][0], 2);
	PlayerTextDrawColor(playerid, Registration[playerid][0], -1061109505);
	PlayerTextDrawSetShadow(playerid, Registration[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, Registration[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, Registration[playerid][0], 51);
	PlayerTextDrawFont(playerid, Registration[playerid][0], 2);
	PlayerTextDrawSetProportional(playerid, Registration[playerid][0], 1);
	Registration[playerid][1] = CreatePlayerTextDraw(playerid, 323.763946, 171.566650, "_");//REGISTRATION
	PlayerTextDrawLetterSize(playerid, Registration[playerid][1], 0.539862, 2.477916);
	PlayerTextDrawAlignment(playerid, Registration[playerid][1], 2);
	PlayerTextDrawColor(playerid, Registration[playerid][1], -1061109505);
	PlayerTextDrawSetShadow(playerid, Registration[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, Registration[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, Registration[playerid][1], 51);
	PlayerTextDrawFont(playerid, Registration[playerid][1], 2);
	PlayerTextDrawSetProportional(playerid, Registration[playerid][1], 1);
	Registration[playerid][2] = CreatePlayerTextDraw(playerid, 289.686614, 228.491760, "_");//YOU_Password
	PlayerTextDrawLetterSize(playerid, Registration[playerid][2], 0.255469, 1.186416);
	PlayerTextDrawAlignment(playerid, Registration[playerid][2], 2);
	PlayerTextDrawColor(playerid, Registration[playerid][2], 353703423);
	PlayerTextDrawSetShadow(playerid, Registration[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, Registration[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, Registration[playerid][2], 51);
	PlayerTextDrawFont(playerid, Registration[playerid][2], 1);
	PlayerTextDrawSetProportional(playerid, Registration[playerid][2], 1);
	Registration[playerid][3] = CreatePlayerTextDraw(playerid, 387.951690, 225.291610, "_");//CREATE
	PlayerTextDrawLetterSize(playerid, Registration[playerid][3], 0.311223, 1.553916);
	PlayerTextDrawAlignment(playerid, Registration[playerid][3], 2);
	PlayerTextDrawColor(playerid, Registration[playerid][3], 353703423);
	PlayerTextDrawSetShadow(playerid, Registration[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, Registration[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, Registration[playerid][3], 51);
	PlayerTextDrawFont(playerid, Registration[playerid][3], 2);
	PlayerTextDrawSetProportional(playerid, Registration[playerid][3], 1);

	Registration[playerid][4] = CreatePlayerTextDraw(playerid, 319.109771, 191.974990, "_");//TExt error
	PlayerTextDrawLetterSize(playerid, Registration[playerid][4], 0.373396, 1.062749);
	PlayerTextDrawAlignment(playerid, Registration[playerid][4], 2);
	PlayerTextDrawColor(playerid, Registration[playerid][4], 0x000000FF);// 353703423);
	PlayerTextDrawSetShadow(playerid, Registration[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, Registration[playerid][4], 0);
	PlayerTextDrawBackgroundColor(playerid, Registration[playerid][4], 51);
	PlayerTextDrawFont(playerid, Registration[playerid][4], 1);
	PlayerTextDrawSetProportional(playerid, Registration[playerid][4], 1);
	CharMenu[playerid][0] = CreatePlayerTextDraw(playerid, 317.189056, 54.250022, "WARDROBE");
	PlayerTextDrawLetterSize(playerid, CharMenu[playerid][0], 0.299133, 1.366665);
	PlayerTextDrawAlignment(playerid, CharMenu[playerid][0], 1);
	PlayerTextDrawColor(playerid, CharMenu[playerid][0], -1);
	PlayerTextDrawSetShadow(playerid, CharMenu[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, CharMenu[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, CharMenu[playerid][0], 51);
	PlayerTextDrawFont(playerid, CharMenu[playerid][0], 2);
	PlayerTextDrawSetProportional(playerid, CharMenu[playerid][0], 1);

	CharMenu[playerid][1] = CreatePlayerTextDraw(playerid, 312.035095, 75.074989, "New Textdraw");
	PlayerTextDrawLetterSize(playerid, CharMenu[playerid][1], 0.449999, 1.600000);
	PlayerTextDrawTextSize(playerid, CharMenu[playerid][1], 61.781852, 88.525009);
	PlayerTextDrawAlignment(playerid, CharMenu[playerid][1], 1);
	PlayerTextDrawColor(playerid, CharMenu[playerid][1], -1);
	PlayerTextDrawUseBox(playerid, CharMenu[playerid][1], true);
	PlayerTextDrawBoxColor(playerid, CharMenu[playerid][1], 0);
	PlayerTextDrawSetShadow(playerid, CharMenu[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, CharMenu[playerid][1], 1);
	PlayerTextDrawSetSelectable(playerid, CharMenu[playerid][1], true);
	PlayerTextDrawBackgroundColor(playerid, CharMenu[playerid][1], 0xFFFFFF30);
	PlayerTextDrawFont(playerid, CharMenu[playerid][1], 5);
	PlayerTextDrawSetProportional(playerid, CharMenu[playerid][1], 1);
	PlayerTextDrawSetPreviewModel(playerid, CharMenu[playerid][1], 1);
	PlayerTextDrawSetPreviewRot(playerid, CharMenu[playerid][1], 0.000000, 0.000000, 0.000000, 1.000000);

	CharMenu[playerid][2] = CreatePlayerTextDraw(playerid, 376.238647, 74.908302, "New Textdraw");
	PlayerTextDrawLetterSize(playerid, CharMenu[playerid][2], 0.449999, 1.600000);
	PlayerTextDrawTextSize(playerid, CharMenu[playerid][2], 61.781852, 88.525009);
	PlayerTextDrawAlignment(playerid, CharMenu[playerid][2], 1);
	PlayerTextDrawColor(playerid, CharMenu[playerid][2], -1);
	PlayerTextDrawUseBox(playerid, CharMenu[playerid][2], true);
	PlayerTextDrawBoxColor(playerid, CharMenu[playerid][2], 0);
	PlayerTextDrawSetShadow(playerid, CharMenu[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, CharMenu[playerid][2], 1);
	PlayerTextDrawBackgroundColor(playerid, CharMenu[playerid][2], 0xFFFFFF30);
	PlayerTextDrawSetSelectable(playerid, CharMenu[playerid][2], true);
	PlayerTextDrawFont(playerid, CharMenu[playerid][2], 5);
	PlayerTextDrawSetProportional(playerid, CharMenu[playerid][2], 1);
	PlayerTextDrawSetPreviewModel(playerid, CharMenu[playerid][2], 2);
	PlayerTextDrawSetPreviewRot(playerid, CharMenu[playerid][2], 0.000000, 0.000000, 0.000000, 1.000000);

	CharMenu[playerid][3] = CreatePlayerTextDraw(playerid, 440.348510, 75.149963, "New Textdraw");
	PlayerTextDrawLetterSize(playerid, CharMenu[playerid][3], 0.449999, 1.600000);
	PlayerTextDrawTextSize(playerid, CharMenu[playerid][3], 61.781852, 88.525009);
	PlayerTextDrawAlignment(playerid, CharMenu[playerid][3], 1);
	PlayerTextDrawColor(playerid, CharMenu[playerid][3], -1);
	PlayerTextDrawUseBox(playerid, CharMenu[playerid][3], true);
	PlayerTextDrawBoxColor(playerid, CharMenu[playerid][3], 0);
	PlayerTextDrawSetShadow(playerid, CharMenu[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, CharMenu[playerid][3], 1);
	PlayerTextDrawSetSelectable(playerid, CharMenu[playerid][3], true);
	PlayerTextDrawBackgroundColor(playerid, CharMenu[playerid][3], 0xFFFFFF30);
	PlayerTextDrawFont(playerid, CharMenu[playerid][3], 5);
	PlayerTextDrawSetProportional(playerid, CharMenu[playerid][3], 1);
	PlayerTextDrawSetPreviewModel(playerid, CharMenu[playerid][3], 3);
	PlayerTextDrawSetPreviewRot(playerid, CharMenu[playerid][3], 0.000000, 0.000000, 0.000000, 1.000000);

	CharMenu[playerid][4] = CreatePlayerTextDraw(playerid, 504.177337, 75.099937, "New Textdraw");
	PlayerTextDrawLetterSize(playerid, CharMenu[playerid][4], 0.449999, 1.600000);
	PlayerTextDrawTextSize(playerid, CharMenu[playerid][4], 61.781852, 88.525009);
	PlayerTextDrawAlignment(playerid, CharMenu[playerid][4], 1);
	PlayerTextDrawColor(playerid, CharMenu[playerid][4], -1);
	PlayerTextDrawUseBox(playerid, CharMenu[playerid][4], true);
	PlayerTextDrawBoxColor(playerid, CharMenu[playerid][4], 0);
	PlayerTextDrawSetShadow(playerid, CharMenu[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, CharMenu[playerid][4], 1);
	PlayerTextDrawSetSelectable(playerid, CharMenu[playerid][4], true);
	PlayerTextDrawBackgroundColor(playerid, CharMenu[playerid][4], 0xFFFFFF30);
	PlayerTextDrawFont(playerid, CharMenu[playerid][4], 5);
	PlayerTextDrawSetProportional(playerid, CharMenu[playerid][4], 1);
	PlayerTextDrawSetPreviewModel(playerid, CharMenu[playerid][4], 7);
	PlayerTextDrawSetPreviewRot(playerid, CharMenu[playerid][4], 0.000000, 0.000000, 0.000000, 1.000000);

	CharMenu[playerid][5] = CreatePlayerTextDraw(playerid, 568.381164, 75.166587, "New Textdraw");
	PlayerTextDrawLetterSize(playerid, CharMenu[playerid][5], 0.449999, 1.600000);
	PlayerTextDrawTextSize(playerid, CharMenu[playerid][5], 61.781852, 88.525009);
	PlayerTextDrawAlignment(playerid, CharMenu[playerid][5], 1);
	PlayerTextDrawColor(playerid, CharMenu[playerid][5], -1);
	PlayerTextDrawUseBox(playerid, CharMenu[playerid][5], true);
	PlayerTextDrawBoxColor(playerid, CharMenu[playerid][5], 0);
	PlayerTextDrawSetShadow(playerid, CharMenu[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, CharMenu[playerid][5], 1);
	PlayerTextDrawSetSelectable(playerid, CharMenu[playerid][5], true);
	PlayerTextDrawBackgroundColor(playerid, CharMenu[playerid][5], 0xFFFFFF30);
	PlayerTextDrawFont(playerid, CharMenu[playerid][5], 5);
	PlayerTextDrawSetProportional(playerid, CharMenu[playerid][5], 1);
	PlayerTextDrawSetPreviewModel(playerid, CharMenu[playerid][5], 14);
	PlayerTextDrawSetPreviewRot(playerid, CharMenu[playerid][5], 0.000000, 0.000000, 0.000000, 1.000000);

	CharMenu[playerid][6] = CreatePlayerTextDraw(playerid, 312.332336, 166.783294, "New Textdraw");
	PlayerTextDrawLetterSize(playerid, CharMenu[playerid][6], 0.449999, 1.600000);
	PlayerTextDrawTextSize(playerid, CharMenu[playerid][6], 61.781852, 88.525009);
	PlayerTextDrawAlignment(playerid, CharMenu[playerid][6], 1);
	PlayerTextDrawColor(playerid, CharMenu[playerid][6], -1);
	PlayerTextDrawUseBox(playerid, CharMenu[playerid][6], true);
	PlayerTextDrawBoxColor(playerid, CharMenu[playerid][6], 0);
	PlayerTextDrawSetShadow(playerid, CharMenu[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, CharMenu[playerid][6], 1);
	PlayerTextDrawSetSelectable(playerid, CharMenu[playerid][6], true);
	PlayerTextDrawBackgroundColor(playerid, CharMenu[playerid][6], 0xFFFFFF30);
	PlayerTextDrawFont(playerid, CharMenu[playerid][6], 5);
	PlayerTextDrawSetProportional(playerid, CharMenu[playerid][6], 1);
	PlayerTextDrawSetPreviewModel(playerid, CharMenu[playerid][6], 15);
	PlayerTextDrawSetPreviewRot(playerid, CharMenu[playerid][6], 0.000000, 0.000000, 0.000000, 1.000000);

	CharMenu[playerid][7] = CreatePlayerTextDraw(playerid, 376.348602, 166.558288, "New Textdraw");
	PlayerTextDrawLetterSize(playerid, CharMenu[playerid][7], 0.449999, 1.600000);
	PlayerTextDrawTextSize(playerid, CharMenu[playerid][7], 61.781852, 88.525009);
	PlayerTextDrawAlignment(playerid, CharMenu[playerid][7], 1);
	PlayerTextDrawColor(playerid, CharMenu[playerid][7], -1);
	PlayerTextDrawUseBox(playerid, CharMenu[playerid][7], true);
	PlayerTextDrawBoxColor(playerid, CharMenu[playerid][7], 0);
	PlayerTextDrawSetShadow(playerid, CharMenu[playerid][7], 0);
	PlayerTextDrawSetOutline(playerid, CharMenu[playerid][7], 1);
	PlayerTextDrawSetSelectable(playerid, CharMenu[playerid][7], true);
	PlayerTextDrawBackgroundColor(playerid, CharMenu[playerid][7], 0xFFFFFF30);
	PlayerTextDrawFont(playerid, CharMenu[playerid][7], 5);
	PlayerTextDrawSetProportional(playerid, CharMenu[playerid][7], 1);
	PlayerTextDrawSetPreviewModel(playerid, CharMenu[playerid][7], 18);
	PlayerTextDrawSetPreviewRot(playerid, CharMenu[playerid][7], 0.000000, 0.000000, 0.000000, 1.000000);

	CharMenu[playerid][8] = CreatePlayerTextDraw(playerid, 440.599151, 166.683273, "New Textdraw");
	PlayerTextDrawLetterSize(playerid, CharMenu[playerid][8], 0.449999, 1.600000);
	PlayerTextDrawTextSize(playerid, CharMenu[playerid][8], 61.781852, 88.525009);
	PlayerTextDrawAlignment(playerid, CharMenu[playerid][8], 1);
	PlayerTextDrawColor(playerid, CharMenu[playerid][8], -1);
	PlayerTextDrawUseBox(playerid, CharMenu[playerid][8], true);
	PlayerTextDrawBoxColor(playerid, CharMenu[playerid][8], 0);
	PlayerTextDrawSetShadow(playerid, CharMenu[playerid][8], 0);
	PlayerTextDrawSetOutline(playerid, CharMenu[playerid][8], 1);
	PlayerTextDrawSetSelectable(playerid, CharMenu[playerid][8], true);
	PlayerTextDrawBackgroundColor(playerid, CharMenu[playerid][8], 0xFFFFFF30);
	PlayerTextDrawFont(playerid, CharMenu[playerid][8], 5);
	PlayerTextDrawSetProportional(playerid, CharMenu[playerid][8], 1);
	PlayerTextDrawSetPreviewModel(playerid, CharMenu[playerid][8], 19);
	PlayerTextDrawSetPreviewRot(playerid, CharMenu[playerid][8], 0.000000, 0.000000, 0.000000, 1.000000);

	CharMenu[playerid][9] = CreatePlayerTextDraw(playerid, 504.334197, 166.691589, "New Textdraw");
	PlayerTextDrawLetterSize(playerid, CharMenu[playerid][9], 0.449999, 1.600000);
	PlayerTextDrawTextSize(playerid, CharMenu[playerid][9], 61.781852, 88.525009);
	PlayerTextDrawAlignment(playerid, CharMenu[playerid][9], 1);
	PlayerTextDrawColor(playerid, CharMenu[playerid][9], -1);
	PlayerTextDrawUseBox(playerid, CharMenu[playerid][9], true);
	PlayerTextDrawBoxColor(playerid, CharMenu[playerid][9], 0);
	PlayerTextDrawSetShadow(playerid, CharMenu[playerid][9], 0);
	PlayerTextDrawSetOutline(playerid, CharMenu[playerid][9], 1);
	PlayerTextDrawSetSelectable(playerid, CharMenu[playerid][9], true);
	PlayerTextDrawBackgroundColor(playerid, CharMenu[playerid][9], 0xFFFFFF30);
	PlayerTextDrawFont(playerid, CharMenu[playerid][9], 5);
	PlayerTextDrawSetProportional(playerid, CharMenu[playerid][9], 1);
	PlayerTextDrawSetPreviewModel(playerid, CharMenu[playerid][9], 20);
	PlayerTextDrawSetPreviewRot(playerid, CharMenu[playerid][9], 0.000000, 0.000000, 0.000000, 1.000000);

	CharMenu[playerid][10] = CreatePlayerTextDraw(playerid, 568.538085, 166.466629, "New Textdraw");
	PlayerTextDrawLetterSize(playerid, CharMenu[playerid][10], 0.449999, 1.600000);
	PlayerTextDrawTextSize(playerid, CharMenu[playerid][10], 61.781852, 88.525009);
	PlayerTextDrawAlignment(playerid, CharMenu[playerid][10], 1);
	PlayerTextDrawColor(playerid, CharMenu[playerid][10], -1);
	PlayerTextDrawUseBox(playerid, CharMenu[playerid][10], true);
	PlayerTextDrawBoxColor(playerid, CharMenu[playerid][10], 0);
	PlayerTextDrawSetShadow(playerid, CharMenu[playerid][10], 0);
	PlayerTextDrawSetOutline(playerid, CharMenu[playerid][10], 1);
	PlayerTextDrawSetSelectable(playerid, CharMenu[playerid][10], true);
	PlayerTextDrawBackgroundColor(playerid, CharMenu[playerid][10], 0xFFFFFF30);
	PlayerTextDrawFont(playerid, CharMenu[playerid][10], 5);
	PlayerTextDrawSetProportional(playerid, CharMenu[playerid][10], 1);
	PlayerTextDrawSetPreviewModel(playerid, CharMenu[playerid][10], 22);
	PlayerTextDrawSetPreviewRot(playerid, CharMenu[playerid][10], 0.000000, 0.000000, 0.000000, 1.000000);

	CharMenu[playerid][11] = CreatePlayerTextDraw(playerid, 317.298828, 269.333496, "REWARDS");
	PlayerTextDrawLetterSize(playerid, CharMenu[playerid][11], 0.299133, 1.366665);
	PlayerTextDrawAlignment(playerid, CharMenu[playerid][11], 1);
	PlayerTextDrawColor(playerid, CharMenu[playerid][11], -1);
	PlayerTextDrawSetShadow(playerid, CharMenu[playerid][11], 0);
	PlayerTextDrawSetOutline(playerid, CharMenu[playerid][11], 0);
	PlayerTextDrawBackgroundColor(playerid, CharMenu[playerid][11], 51);
	PlayerTextDrawFont(playerid, CharMenu[playerid][11], 2);
	PlayerTextDrawSetProportional(playerid, CharMenu[playerid][11], 1);

	CharMenu[playerid][12] = CreatePlayerTextDraw(playerid, 312.114074, 286.491577, "New Textdraw");
	PlayerTextDrawLetterSize(playerid, CharMenu[playerid][12], 0.449999, 1.600000);
	PlayerTextDrawTextSize(playerid, CharMenu[playerid][12], 61.781852, 74.816658);
	PlayerTextDrawAlignment(playerid, CharMenu[playerid][12], 1);
	PlayerTextDrawColor(playerid, CharMenu[playerid][12], -1);
	PlayerTextDrawUseBox(playerid, CharMenu[playerid][12], true);
	PlayerTextDrawBoxColor(playerid, CharMenu[playerid][12], 0);
	PlayerTextDrawSetShadow(playerid, CharMenu[playerid][12], 0);
	PlayerTextDrawSetOutline(playerid, CharMenu[playerid][12], 1);
	PlayerTextDrawSetSelectable(playerid, CharMenu[playerid][12], true);
	PlayerTextDrawBackgroundColor(playerid, CharMenu[playerid][12], 0xFFFFFF30);
	PlayerTextDrawFont(playerid, CharMenu[playerid][12], 5);
	PlayerTextDrawSetProportional(playerid, CharMenu[playerid][12], 1);
	PlayerTextDrawSetPreviewModel(playerid, CharMenu[playerid][12], 2969);
	PlayerTextDrawSetPreviewRot(playerid, CharMenu[playerid][12], -30.000000, 0.000000, 30.000000, 1.000000);
	
	CharMenu[playerid][13] = CreatePlayerTextDraw(playerid, 370.787658, 287.700012, "x1");
	PlayerTextDrawLetterSize(playerid, CharMenu[playerid][13], 0.217144, 1.320000);
	PlayerTextDrawAlignment(playerid, CharMenu[playerid][13], 3);
	PlayerTextDrawColor(playerid, CharMenu[playerid][13], -1);
	PlayerTextDrawUseBox(playerid, CharMenu[playerid][13], true);
	PlayerTextDrawBoxColor(playerid, CharMenu[playerid][13], 0);
	PlayerTextDrawSetShadow(playerid, CharMenu[playerid][13], 0);
	PlayerTextDrawSetOutline(playerid, CharMenu[playerid][13], 0);
	PlayerTextDrawBackgroundColor(playerid, CharMenu[playerid][13], 51);
	PlayerTextDrawFont(playerid, CharMenu[playerid][13], 1);
	PlayerTextDrawSetProportional(playerid, CharMenu[playerid][13], 1);
	
	CharMenu[playerid][14] = CreatePlayerTextDraw(playerid, 61.188869, 363.941802, "DAYS________________7");
	PlayerTextDrawLetterSize(playerid, CharMenu[playerid][14], 0.341302, 2.504167);
	PlayerTextDrawAlignment(playerid, CharMenu[playerid][14], 1);
	PlayerTextDrawColor(playerid, CharMenu[playerid][14], 0xD68513FF);
	PlayerTextDrawSetShadow(playerid, CharMenu[playerid][14], 0);
	PlayerTextDrawSetOutline(playerid, CharMenu[playerid][14], 0);
	PlayerTextDrawBackgroundColor(playerid, CharMenu[playerid][14], 51);
	PlayerTextDrawFont(playerid, CharMenu[playerid][14], 2);
	PlayerTextDrawSetProportional(playerid, CharMenu[playerid][14], 1);
	
	CharMenu[playerid][15] = CreatePlayerTextDraw(playerid, 315.051635, 150.708328, "DAYS_________________1");
	PlayerTextDrawLetterSize(playerid, CharMenu[playerid][15], 0.178726, 1.331665);
	PlayerTextDrawTextSize(playerid, CharMenu[playerid][15], 369.195007, 16.341666);
	PlayerTextDrawAlignment(playerid, CharMenu[playerid][15], 1);
	PlayerTextDrawColor(playerid, CharMenu[playerid][15], -5963521);
	PlayerTextDrawUseBox(playerid, CharMenu[playerid][15], true);
	PlayerTextDrawBoxColor(playerid, CharMenu[playerid][15], -256);
	PlayerTextDrawSetShadow(playerid, CharMenu[playerid][15], 0);
	PlayerTextDrawSetOutline(playerid, CharMenu[playerid][15], 0);
	PlayerTextDrawBackgroundColor(playerid, CharMenu[playerid][15], 51);
	PlayerTextDrawFont(playerid, CharMenu[playerid][15], 2);
	PlayerTextDrawSetProportional(playerid, CharMenu[playerid][15], 1);
	PlayerTextDrawSetSelectable(playerid, CharMenu[playerid][15], true);

	CharMenu[playerid][16] = CreatePlayerTextDraw(playerid, 379.958038, 150.599975, "DAYS_________________1");
	PlayerTextDrawLetterSize(playerid, CharMenu[playerid][16], 0.178726, 1.331665);
	PlayerTextDrawTextSize(playerid, CharMenu[playerid][16], 433.944519, 16.400000);
	PlayerTextDrawAlignment(playerid, CharMenu[playerid][16], 1);
	PlayerTextDrawColor(playerid, CharMenu[playerid][16], -5963521);
	PlayerTextDrawUseBox(playerid, CharMenu[playerid][16], true);
	PlayerTextDrawBoxColor(playerid, CharMenu[playerid][16], -256);
	PlayerTextDrawSetShadow(playerid, CharMenu[playerid][16], 0);
	PlayerTextDrawSetOutline(playerid, CharMenu[playerid][16], 0);
	PlayerTextDrawBackgroundColor(playerid, CharMenu[playerid][16], 51);
	PlayerTextDrawFont(playerid, CharMenu[playerid][16], 2);
	PlayerTextDrawSetProportional(playerid, CharMenu[playerid][16], 1);
	PlayerTextDrawSetSelectable(playerid, CharMenu[playerid][16], true);

	CharMenu[playerid][17] = CreatePlayerTextDraw(playerid, 443.880584, 150.666625, "DAYS_________________1");
	PlayerTextDrawLetterSize(playerid, CharMenu[playerid][17], 0.178726, 1.331665);
	PlayerTextDrawTextSize(playerid, CharMenu[playerid][17], 496.210937, 16.258334);
	PlayerTextDrawAlignment(playerid, CharMenu[playerid][17], 1);
	PlayerTextDrawColor(playerid, CharMenu[playerid][17], -5963521);
	PlayerTextDrawUseBox(playerid, CharMenu[playerid][17], true);
	PlayerTextDrawBoxColor(playerid, CharMenu[playerid][17], -256);
	PlayerTextDrawSetShadow(playerid, CharMenu[playerid][17], 0);
	PlayerTextDrawSetOutline(playerid, CharMenu[playerid][17], 0);
	PlayerTextDrawBackgroundColor(playerid, CharMenu[playerid][17], 51);
	PlayerTextDrawFont(playerid, CharMenu[playerid][17], 2);
	PlayerTextDrawSetProportional(playerid, CharMenu[playerid][17], 1);
	PlayerTextDrawSetSelectable(playerid, CharMenu[playerid][17], true);

	CharMenu[playerid][18] = CreatePlayerTextDraw(playerid, 507.100402, 150.674942, "DAYS_________________1");
	PlayerTextDrawLetterSize(playerid, CharMenu[playerid][18], 0.178726, 1.331665);
	PlayerTextDrawTextSize(playerid, CharMenu[playerid][18], 560.773437, 16.625000);
	PlayerTextDrawAlignment(playerid, CharMenu[playerid][18], 1);
	PlayerTextDrawColor(playerid, CharMenu[playerid][18], -5963521);
	PlayerTextDrawUseBox(playerid, CharMenu[playerid][18], true);
	PlayerTextDrawBoxColor(playerid, CharMenu[playerid][18], -256);
	PlayerTextDrawSetShadow(playerid, CharMenu[playerid][18], 0);
	PlayerTextDrawSetOutline(playerid, CharMenu[playerid][18], 0);
	PlayerTextDrawBackgroundColor(playerid, CharMenu[playerid][18], 51);
	PlayerTextDrawFont(playerid, CharMenu[playerid][18], 2);
	PlayerTextDrawSetProportional(playerid, CharMenu[playerid][18], 1);
	PlayerTextDrawSetSelectable(playerid, CharMenu[playerid][18], true);

	CharMenu[playerid][19] = CreatePlayerTextDraw(playerid, 571.632263, 150.741592, "DAYS_________________1");
	PlayerTextDrawLetterSize(playerid, CharMenu[playerid][19], 0.178726, 1.331665);
	PlayerTextDrawTextSize(playerid, CharMenu[playerid][19], 624.164001, 16.166666);
	PlayerTextDrawAlignment(playerid, CharMenu[playerid][19], 1);
	PlayerTextDrawColor(playerid, CharMenu[playerid][19], -5963521);
	PlayerTextDrawUseBox(playerid, CharMenu[playerid][19], true);
	PlayerTextDrawBoxColor(playerid, CharMenu[playerid][19], -256);
	PlayerTextDrawSetShadow(playerid, CharMenu[playerid][19], 0);
	PlayerTextDrawSetOutline(playerid, CharMenu[playerid][19], 0);
	PlayerTextDrawBackgroundColor(playerid, CharMenu[playerid][19], 51);
	PlayerTextDrawFont(playerid, CharMenu[playerid][19], 2);
	PlayerTextDrawSetProportional(playerid, CharMenu[playerid][19], 1);
	PlayerTextDrawSetSelectable(playerid, CharMenu[playerid][19], true);

	CharMenu[playerid][20] = CreatePlayerTextDraw(playerid, 315.882415, 241.691604, "DAYS_________________1");
	PlayerTextDrawLetterSize(playerid, CharMenu[playerid][20], 0.178726, 1.331665);
	PlayerTextDrawTextSize(playerid, CharMenu[playerid][20], 371.115509, 16.516666);
	PlayerTextDrawAlignment(playerid, CharMenu[playerid][20], 1);
	PlayerTextDrawColor(playerid, CharMenu[playerid][20], -5963521);
	PlayerTextDrawUseBox(playerid, CharMenu[playerid][20], true);
	PlayerTextDrawBoxColor(playerid, CharMenu[playerid][20], -256);
	PlayerTextDrawSetShadow(playerid, CharMenu[playerid][20], 0);
	PlayerTextDrawSetOutline(playerid, CharMenu[playerid][20], 0);
	PlayerTextDrawBackgroundColor(playerid, CharMenu[playerid][20], 51);
	PlayerTextDrawFont(playerid, CharMenu[playerid][20], 2);
	PlayerTextDrawSetProportional(playerid, CharMenu[playerid][20], 1);
	PlayerTextDrawSetSelectable(playerid, CharMenu[playerid][20], true);

	CharMenu[playerid][21] = CreatePlayerTextDraw(playerid, 379.945739, 241.641586, "DAYS_________________1");
	PlayerTextDrawLetterSize(playerid, CharMenu[playerid][21], 0.178726, 1.331665);
	PlayerTextDrawTextSize(playerid, CharMenu[playerid][21], 432.445098, 16.516666);
	PlayerTextDrawAlignment(playerid, CharMenu[playerid][21], 1);
	PlayerTextDrawColor(playerid, CharMenu[playerid][21], -5963521);
	PlayerTextDrawUseBox(playerid, CharMenu[playerid][21], true);
	PlayerTextDrawBoxColor(playerid, CharMenu[playerid][21], -256);
	PlayerTextDrawSetShadow(playerid, CharMenu[playerid][21], 0);
	PlayerTextDrawSetOutline(playerid, CharMenu[playerid][21], 0);
	PlayerTextDrawBackgroundColor(playerid, CharMenu[playerid][21], 51);
	PlayerTextDrawFont(playerid, CharMenu[playerid][21], 2);
	PlayerTextDrawSetProportional(playerid, CharMenu[playerid][21], 1);
	PlayerTextDrawSetSelectable(playerid, CharMenu[playerid][21], true);

	CharMenu[playerid][22] = CreatePlayerTextDraw(playerid, 444.149444, 241.766632, "DAYS_________________1");
	PlayerTextDrawLetterSize(playerid, CharMenu[playerid][22], 0.178726, 1.331665);
	PlayerTextDrawTextSize(playerid, CharMenu[playerid][22], 496.820251, 16.575000);
	PlayerTextDrawAlignment(playerid, CharMenu[playerid][22], 1);
	PlayerTextDrawColor(playerid, CharMenu[playerid][22], -5963521);
	PlayerTextDrawUseBox(playerid, CharMenu[playerid][22], true);
	PlayerTextDrawBoxColor(playerid, CharMenu[playerid][22], -256);
	PlayerTextDrawSetShadow(playerid, CharMenu[playerid][22], 0);
	PlayerTextDrawSetOutline(playerid, CharMenu[playerid][22], 0);
	PlayerTextDrawBackgroundColor(playerid, CharMenu[playerid][22], 51);
	PlayerTextDrawFont(playerid, CharMenu[playerid][22], 2);
	PlayerTextDrawSetProportional(playerid, CharMenu[playerid][22], 1);
	PlayerTextDrawSetSelectable(playerid, CharMenu[playerid][22], true);

	CharMenu[playerid][23] = CreatePlayerTextDraw(playerid, 508.072143, 241.774948, "DAYS_________________1");
	PlayerTextDrawLetterSize(playerid, CharMenu[playerid][23], 0.178726, 1.331665);
	PlayerTextDrawTextSize(playerid, CharMenu[playerid][23], 561.335083, 16.400000);
	PlayerTextDrawAlignment(playerid, CharMenu[playerid][23], 1);
	PlayerTextDrawColor(playerid, CharMenu[playerid][23], -5963521);
	PlayerTextDrawUseBox(playerid, CharMenu[playerid][23], true);
	PlayerTextDrawBoxColor(playerid, CharMenu[playerid][23], -256);
	PlayerTextDrawSetShadow(playerid, CharMenu[playerid][23], 0);
	PlayerTextDrawSetOutline(playerid, CharMenu[playerid][23], 0);
	PlayerTextDrawBackgroundColor(playerid, CharMenu[playerid][23], 51);
	PlayerTextDrawFont(playerid, CharMenu[playerid][23], 2);
	PlayerTextDrawSetProportional(playerid, CharMenu[playerid][23], 1);
	PlayerTextDrawSetSelectable(playerid, CharMenu[playerid][23], true);

	CharMenu[playerid][24] = CreatePlayerTextDraw(playerid, 571.666748, 241.666595, "DAYS_________________1");
	PlayerTextDrawLetterSize(playerid, CharMenu[playerid][24], 0.178726, 1.331665);
	PlayerTextDrawTextSize(playerid, CharMenu[playerid][24], 625.007873, 16.749999);
	PlayerTextDrawAlignment(playerid, CharMenu[playerid][24], 1);
	PlayerTextDrawColor(playerid, CharMenu[playerid][24], -5963521);
	PlayerTextDrawUseBox(playerid, CharMenu[playerid][24], true);
	PlayerTextDrawBoxColor(playerid, CharMenu[playerid][24], -256);
	PlayerTextDrawSetShadow(playerid, CharMenu[playerid][24], 0);
	PlayerTextDrawSetOutline(playerid, CharMenu[playerid][24], 0);
	PlayerTextDrawBackgroundColor(playerid, CharMenu[playerid][24], 51);
	PlayerTextDrawFont(playerid, CharMenu[playerid][24], 2);
	PlayerTextDrawSetProportional(playerid, CharMenu[playerid][24], 1);
	PlayerTextDrawSetSelectable(playerid, CharMenu[playerid][24], true);
	
	RewMenu[playerid][0] = CreatePlayerTextDraw(playerid, 423.964965, 69.999984, "_");//PIONEER_CRATE
	PlayerTextDrawLetterSize(playerid, RewMenu[playerid][0], 0.325372, 1.640833);
	PlayerTextDrawAlignment(playerid, RewMenu[playerid][0], 1);
	PlayerTextDrawColor(playerid, RewMenu[playerid][0], -1);
	PlayerTextDrawUseBox(playerid, RewMenu[playerid][0], true);
	PlayerTextDrawBoxColor(playerid, RewMenu[playerid][0], 0);
	PlayerTextDrawSetShadow(playerid, RewMenu[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, RewMenu[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, RewMenu[playerid][0], 51);
	PlayerTextDrawFont(playerid, RewMenu[playerid][0], 2);
	PlayerTextDrawSetProportional(playerid, RewMenu[playerid][0], 1);

	RewMenu[playerid][1] = CreatePlayerTextDraw(playerid, 478.641326, 100.099990, "_");//7,000
	PlayerTextDrawLetterSize(playerid, RewMenu[playerid][1], 0.388622, 2.410831);
	PlayerTextDrawAlignment(playerid, RewMenu[playerid][1], 1);
	PlayerTextDrawColor(playerid, RewMenu[playerid][1], -5963521);
	PlayerTextDrawSetShadow(playerid, RewMenu[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, RewMenu[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, RewMenu[playerid][1], 51);
	PlayerTextDrawFont(playerid, RewMenu[playerid][1], 2);
	PlayerTextDrawSetProportional(playerid, RewMenu[playerid][1], 1);

	RewMenu[playerid][2] = CreatePlayerTextDraw(playerid, 496.632904, 150.791702, "RECEIVE");
	PlayerTextDrawLetterSize(playerid, RewMenu[playerid][2], 0.305694, 1.640833);
	PlayerTextDrawAlignment(playerid, RewMenu[playerid][2], 2);
	PlayerTextDrawColor(playerid, RewMenu[playerid][2], 255);
	PlayerTextDrawSetShadow(playerid, RewMenu[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, RewMenu[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, RewMenu[playerid][2], 51);
	PlayerTextDrawFont(playerid, RewMenu[playerid][2], 2);
	PlayerTextDrawSetProportional(playerid, RewMenu[playerid][2], 1);

	RewMenu[playerid][3] = CreatePlayerTextDraw(playerid, 418.077972, 69.949974, "_");//7th
	PlayerTextDrawLetterSize(playerid, RewMenu[playerid][3], 0.325372, 1.640833);
	PlayerTextDrawAlignment(playerid, RewMenu[playerid][3], 3);
	PlayerTextDrawColor(playerid, RewMenu[playerid][3], -5963521);
	PlayerTextDrawUseBox(playerid, RewMenu[playerid][3], true);
	PlayerTextDrawBoxColor(playerid, RewMenu[playerid][3], 0);
	PlayerTextDrawSetShadow(playerid, RewMenu[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, RewMenu[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, RewMenu[playerid][3], 51);
	PlayerTextDrawFont(playerid, RewMenu[playerid][3], 1);
	PlayerTextDrawSetProportional(playerid, RewMenu[playerid][3], 1);
	
	RewMenu[playerid][4] = CreatePlayerTextDraw(playerid, 56.222587, 257.250000, "New Textdraw");
	PlayerTextDrawLetterSize(playerid,RewMenu[playerid][4], 0.449999, 1.600000);
	PlayerTextDrawTextSize(playerid, RewMenu[playerid][4], 116.193267, 132.999984);
	PlayerTextDrawAlignment(playerid, RewMenu[playerid][4], 1);
	PlayerTextDrawColor(playerid, RewMenu[playerid][4], -1);
	PlayerTextDrawUseBox(playerid, RewMenu[playerid][4], true);
	PlayerTextDrawBoxColor(playerid, RewMenu[playerid][4], 0);
	PlayerTextDrawSetShadow(playerid, RewMenu[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, RewMenu[playerid][4], 1);
	PlayerTextDrawBackgroundColor(playerid, RewMenu[playerid][4], -538976384);
	PlayerTextDrawFont(playerid, RewMenu[playerid][4], 5);
	PlayerTextDrawSetProportional(playerid, RewMenu[playerid][4], 1);
	PlayerTextDrawSetPreviewModel(playerid, RewMenu[playerid][4], 6);
	PlayerTextDrawSetPreviewRot(playerid, RewMenu[playerid][4], 0.000000, 0.000000, 0.000000, 1.000000);

	RewMenu[playerid][5] = CreatePlayerTextDraw(playerid, 113.335273, 245.641601, "Your winnings:");
	PlayerTextDrawLetterSize(playerid, RewMenu[playerid][5], 0.173572, 1.133333);
	PlayerTextDrawAlignment(playerid, RewMenu[playerid][5], 2);
	PlayerTextDrawColor(playerid, RewMenu[playerid][5], -538976257);
	PlayerTextDrawSetShadow(playerid, RewMenu[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, RewMenu[playerid][5], 0);
	PlayerTextDrawBackgroundColor(playerid, RewMenu[playerid][5], 51);
	PlayerTextDrawFont(playerid, RewMenu[playerid][5], 2);
	PlayerTextDrawSetProportional(playerid, RewMenu[playerid][5], 1);
	
	KeysF[playerid] = CreatePlayerTextDraw(playerid, 388.170013, 262.208312, "Eject");
	PlayerTextDrawLetterSize(playerid, KeysF[playerid], 0.189736, 1.175333);
	PlayerTextDrawAlignment(playerid, KeysF[playerid], 1);
	PlayerTextDrawColor(playerid, KeysF[playerid], -1);
	PlayerTextDrawSetShadow(playerid, KeysF[playerid], 0);
	PlayerTextDrawSetOutline(playerid, KeysF[playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, KeysF[playerid], 51);
	PlayerTextDrawFont(playerid, KeysF[playerid], 2);
	PlayerTextDrawSetProportional(playerid, KeysF[playerid], 1);
	
	Killed[playerid][0] = CreatePlayerTextDraw(playerid, 44.509552, 154.525009, "_");//Alex_Dyson
	PlayerTextDrawLetterSize(playerid, Killed[playerid][0], 0.519809, 2.235831);
	PlayerTextDrawAlignment(playerid, Killed[playerid][0], 1);
	PlayerTextDrawColor(playerid, Killed[playerid][0], -103);
	PlayerTextDrawSetShadow(playerid, Killed[playerid][0], 1);
	PlayerTextDrawSetOutline(playerid, Killed[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, Killed[playerid][0], 51);
	PlayerTextDrawFont(playerid, Killed[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, Killed[playerid][0], 1);

	Killed[playerid][1] = CreatePlayerTextDraw(playerid, 44.291397, 179.791671, "_");//WINNER_-_WINNER_CHICKEN_DINNER
	PlayerTextDrawLetterSize(playerid, Killed[playerid][1], 0.426573, 3.163331);
	PlayerTextDrawAlignment(playerid, Killed[playerid][1], 1);
	PlayerTextDrawColor(playerid, Killed[playerid][1], -5635841);
	PlayerTextDrawUseBox(playerid, Killed[playerid][1], true);
	PlayerTextDrawBoxColor(playerid, Killed[playerid][1], 0);
	PlayerTextDrawSetShadow(playerid, Killed[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, Killed[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, Killed[playerid][1], 51);
	PlayerTextDrawFont(playerid, Killed[playerid][1], 2);
	PlayerTextDrawSetProportional(playerid, Killed[playerid][1], 1);

	Killed[playerid][2] = CreatePlayerTextDraw(playerid, 117.333824, 228.208297, "#1");
	PlayerTextDrawLetterSize(playerid, Killed[playerid][2], 0.285874, 1.341580);
	PlayerTextDrawAlignment(playerid, Killed[playerid][2], 3);
	PlayerTextDrawColor(playerid, Killed[playerid][2], -1061109505);
	PlayerTextDrawUseBox(playerid, Killed[playerid][2], true);
	PlayerTextDrawBoxColor(playerid, Killed[playerid][2], 0);
	PlayerTextDrawSetShadow(playerid, Killed[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, Killed[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, Killed[playerid][2], 51);
	PlayerTextDrawFont(playerid, Killed[playerid][2], 1);
	PlayerTextDrawSetProportional(playerid, Killed[playerid][2], 1);

	Killed[playerid][3] = CreatePlayerTextDraw(playerid, 172.963439, 228.099945, "0");//12
	PlayerTextDrawLetterSize(playerid, Killed[playerid][3], 0.285874, 1.341580);
	PlayerTextDrawAlignment(playerid, Killed[playerid][3], 2);
	PlayerTextDrawColor(playerid, Killed[playerid][3], -1061109505);
	PlayerTextDrawUseBox(playerid, Killed[playerid][3], true);
	PlayerTextDrawBoxColor(playerid, Killed[playerid][3], 0);
	PlayerTextDrawSetShadow(playerid, Killed[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, Killed[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, Killed[playerid][3], 51);
	PlayerTextDrawFont(playerid, Killed[playerid][3], 1);
	PlayerTextDrawSetProportional(playerid, Killed[playerid][3], 1);

	Killed[playerid][4] = CreatePlayerTextDraw(playerid, 319.203491, 228.141738, "0");
	PlayerTextDrawLetterSize(playerid, Killed[playerid][4], 0.285874, 1.341580);
	PlayerTextDrawAlignment(playerid, Killed[playerid][4], 3);
	PlayerTextDrawColor(playerid, Killed[playerid][4], -1061109505);
	PlayerTextDrawUseBox(playerid, Killed[playerid][4], true);
	PlayerTextDrawBoxColor(playerid, Killed[playerid][4], 0);
	PlayerTextDrawSetShadow(playerid, Killed[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, Killed[playerid][4], 0);
	PlayerTextDrawBackgroundColor(playerid, Killed[playerid][4], 51);
	PlayerTextDrawFont(playerid, Killed[playerid][4], 1);
	PlayerTextDrawSetProportional(playerid, Killed[playerid][4], 1);

	Killed[playerid][5] = CreatePlayerTextDraw(playerid, 591.805541, 26.374973, "/100");
	PlayerTextDrawLetterSize(playerid, Killed[playerid][5], 0.358168, 3.606662);
	PlayerTextDrawAlignment(playerid, Killed[playerid][5], 1);
	PlayerTextDrawColor(playerid, Killed[playerid][5], -2139062017);
	PlayerTextDrawUseBox(playerid, Killed[playerid][5], true);
	PlayerTextDrawBoxColor(playerid, Killed[playerid][5], 0);
	PlayerTextDrawSetShadow(playerid, Killed[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, Killed[playerid][5], 0);
	PlayerTextDrawBackgroundColor(playerid, Killed[playerid][5], 51);
	PlayerTextDrawFont(playerid, Killed[playerid][5], 2);
	PlayerTextDrawSetProportional(playerid, Killed[playerid][5], 1);

	Killed[playerid][6] = CreatePlayerTextDraw(playerid, 588.870300, 26.616645, "#10");
	PlayerTextDrawLetterSize(playerid, Killed[playerid][6], 0.585399, 3.769999);
	PlayerTextDrawAlignment(playerid, Killed[playerid][6], 3);
	PlayerTextDrawColor(playerid, Killed[playerid][6], -5635841);
	PlayerTextDrawUseBox(playerid, Killed[playerid][6], true);
	PlayerTextDrawBoxColor(playerid, Killed[playerid][6], 0);
	PlayerTextDrawSetShadow(playerid, Killed[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, Killed[playerid][6], 0);
	PlayerTextDrawBackgroundColor(playerid, Killed[playerid][6], 51);
	PlayerTextDrawFont(playerid, Killed[playerid][6], 3);
	PlayerTextDrawSetProportional(playerid, Killed[playerid][6], 1);

	Killed[playerid][7] = CreatePlayerTextDraw(playerid, 555.291320, 372.924957, "EXIT_TO_LOBBY");
	PlayerTextDrawLetterSize(playerid, Killed[playerid][7], 0.263058, 1.862498);
	PlayerTextDrawAlignment(playerid, Killed[playerid][7], 2);
	PlayerTextDrawColor(playerid, Killed[playerid][7], -1);
	PlayerTextDrawSetShadow(playerid, Killed[playerid][7], 0);
	PlayerTextDrawSetOutline(playerid, Killed[playerid][7], 0);
	PlayerTextDrawBackgroundColor(playerid, Killed[playerid][7], 51);
	PlayerTextDrawFont(playerid, Killed[playerid][7], 2);
	PlayerTextDrawSetProportional(playerid, Killed[playerid][7], 1);

	Killed[playerid][8] = CreatePlayerTextDraw(playerid, 455.291320, 372.924957, "SPECTATE");
	PlayerTextDrawLetterSize(playerid, Killed[playerid][8], 0.263058, 1.862498);
	PlayerTextDrawAlignment(playerid, Killed[playerid][8], 2);
	PlayerTextDrawColor(playerid, Killed[playerid][8], -1);
	PlayerTextDrawSetShadow(playerid, Killed[playerid][8], 0);
	PlayerTextDrawSetOutline(playerid, Killed[playerid][8], 0);
	PlayerTextDrawBackgroundColor(playerid, Killed[playerid][8], 51);
	PlayerTextDrawFont(playerid, Killed[playerid][8], 2);
	PlayerTextDrawSetProportional(playerid, Killed[playerid][8], 1);
	
	NWSE[playerid][12] = CreatePlayerTextDraw(playerid, 230.419052, 30.0, "_");//NW
	PlayerTextDrawLetterSize(playerid, NWSE[playerid][12], 0.173572, 0.835833);
	PlayerTextDrawAlignment(playerid, NWSE[playerid][12], 2);
	PlayerTextDrawColor(playerid, NWSE[playerid][12], -86);
	PlayerTextDrawSetShadow(playerid, NWSE[playerid][12], 0);
	PlayerTextDrawSetOutline(playerid, NWSE[playerid][12], 0);
	PlayerTextDrawBackgroundColor(playerid, NWSE[playerid][12], 51);
	PlayerTextDrawFont(playerid, NWSE[playerid][12], 2);
	PlayerTextDrawSetProportional(playerid, NWSE[playerid][12], 1);

	NWSE[playerid][9] = CreatePlayerTextDraw(playerid, 273.820098, 30.0, "_");//N
	PlayerTextDrawLetterSize(playerid, NWSE[playerid][9], 0.173572, 0.835833);
	PlayerTextDrawAlignment(playerid, NWSE[playerid][9], 2);
	PlayerTextDrawColor(playerid, NWSE[playerid][9], -86);
	PlayerTextDrawSetShadow(playerid, NWSE[playerid][9], 0);
	PlayerTextDrawSetOutline(playerid, NWSE[playerid][9], 0);
	PlayerTextDrawBackgroundColor(playerid, NWSE[playerid][9], 51);
	PlayerTextDrawFont(playerid, NWSE[playerid][9], 2);
	PlayerTextDrawSetProportional(playerid, NWSE[playerid][9], 1);

	NWSE[playerid][6] = CreatePlayerTextDraw(playerid, 316.050018, 30.0, "_");//ne
	PlayerTextDrawLetterSize(playerid, NWSE[playerid][6], 0.173572, 0.835833);
	PlayerTextDrawAlignment(playerid, NWSE[playerid][6], 2);
	PlayerTextDrawColor(playerid, NWSE[playerid][6], -86);
	PlayerTextDrawSetShadow(playerid, NWSE[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, NWSE[playerid][6], 0);
	PlayerTextDrawBackgroundColor(playerid, NWSE[playerid][6], 51);
	PlayerTextDrawFont(playerid, NWSE[playerid][6], 2);
	PlayerTextDrawSetProportional(playerid, NWSE[playerid][6], 1);

	NWSE[playerid][3] = CreatePlayerTextDraw(playerid, 360.716583, 30.0, "_");//E
	PlayerTextDrawLetterSize(playerid, NWSE[playerid][3], 0.173572, 0.835833);
	PlayerTextDrawAlignment(playerid, NWSE[playerid][3], 2);
	PlayerTextDrawColor(playerid, NWSE[playerid][3], -86);
	PlayerTextDrawSetShadow(playerid, NWSE[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, NWSE[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, NWSE[playerid][3], 51);
	PlayerTextDrawFont(playerid, NWSE[playerid][3], 2);
	PlayerTextDrawSetProportional(playerid, NWSE[playerid][3], 1);

	NWSE[playerid][0] = CreatePlayerTextDraw(playerid, 404.164855, 30.0, "_");//SE
	PlayerTextDrawLetterSize(playerid, NWSE[playerid][0], 0.173572, 0.835833);
	PlayerTextDrawAlignment(playerid, NWSE[playerid][0], 2);
	PlayerTextDrawColor(playerid, NWSE[playerid][0], -86);
	PlayerTextDrawSetShadow(playerid, NWSE[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, NWSE[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, NWSE[playerid][0], 51);
	PlayerTextDrawFont(playerid, NWSE[playerid][0], 2);
	PlayerTextDrawSetProportional(playerid, NWSE[playerid][0], 1);

	NWSE[playerid][11] = CreatePlayerTextDraw(playerid, 246.382720, 30.0, "_");//330
	PlayerTextDrawLetterSize(playerid, NWSE[playerid][11], 0.147709, 0.778666);
	PlayerTextDrawAlignment(playerid, NWSE[playerid][11], 2);
	PlayerTextDrawColor(playerid, NWSE[playerid][11], 1886417066);
	PlayerTextDrawSetShadow(playerid, NWSE[playerid][11], 0);
	PlayerTextDrawSetOutline(playerid, NWSE[playerid][11], 0);
	PlayerTextDrawBackgroundColor(playerid, NWSE[playerid][11], 51);
	PlayerTextDrawFont(playerid, NWSE[playerid][11], 2);
	PlayerTextDrawSetProportional(playerid, NWSE[playerid][11], 1);

	NWSE[playerid][10] = CreatePlayerTextDraw(playerid, 260.361053, 30.0, "_");//345
	PlayerTextDrawLetterSize(playerid, NWSE[playerid][10], 0.147709, 0.778666);
	PlayerTextDrawAlignment(playerid, NWSE[playerid][10], 2);
	PlayerTextDrawColor(playerid, NWSE[playerid][10], 1886417066);
	PlayerTextDrawSetShadow(playerid, NWSE[playerid][10], 0);
	PlayerTextDrawSetOutline(playerid, NWSE[playerid][10], 0);
	PlayerTextDrawBackgroundColor(playerid, NWSE[playerid][10], 51);
	PlayerTextDrawFont(playerid, NWSE[playerid][10], 2);
	PlayerTextDrawSetProportional(playerid, NWSE[playerid][10], 1);

	NWSE[playerid][8] = CreatePlayerTextDraw(playerid, 288.207550, 30.0, "_");//15
	PlayerTextDrawLetterSize(playerid, NWSE[playerid][8], 0.147709, 0.778666);
	PlayerTextDrawAlignment(playerid, NWSE[playerid][8], 2);
	PlayerTextDrawColor(playerid, NWSE[playerid][8], 1886417066);
	PlayerTextDrawSetShadow(playerid, NWSE[playerid][8], 0);
	PlayerTextDrawSetOutline(playerid, NWSE[playerid][8], 0);
	PlayerTextDrawBackgroundColor(playerid, NWSE[playerid][8], 51);
	PlayerTextDrawFont(playerid, NWSE[playerid][8], 2);
	PlayerTextDrawSetProportional(playerid, NWSE[playerid][8], 1);

	NWSE[playerid][7] = CreatePlayerTextDraw(playerid, 301.810852, 30.0, "_");//30
	PlayerTextDrawLetterSize(playerid, NWSE[playerid][7], 0.147709, 0.778666);
	PlayerTextDrawAlignment(playerid, NWSE[playerid][7], 2);
	PlayerTextDrawColor(playerid, NWSE[playerid][7], 1886417066);
	PlayerTextDrawSetShadow(playerid, NWSE[playerid][7], 0);
	PlayerTextDrawSetOutline(playerid, NWSE[playerid][7], 0);
	PlayerTextDrawBackgroundColor(playerid, NWSE[playerid][7], 51);
	PlayerTextDrawFont(playerid, NWSE[playerid][7], 2);
	PlayerTextDrawSetProportional(playerid, NWSE[playerid][7], 1);

	NWSE[playerid][5] = CreatePlayerTextDraw(playerid, 330.641174, 30.0, "_");//60
	PlayerTextDrawLetterSize(playerid, NWSE[playerid][5], 0.147709, 0.778666);
	PlayerTextDrawAlignment(playerid, NWSE[playerid][5], 2);
	PlayerTextDrawColor(playerid, NWSE[playerid][5], 1886417066);
	PlayerTextDrawSetShadow(playerid, NWSE[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, NWSE[playerid][5], 0);
	PlayerTextDrawBackgroundColor(playerid, NWSE[playerid][5], 51);
	PlayerTextDrawFont(playerid, NWSE[playerid][5], 2);
	PlayerTextDrawSetProportional(playerid, NWSE[playerid][5], 1);

	NWSE[playerid][4] = CreatePlayerTextDraw(playerid, 345.603210, 30.0, "_");//75
	PlayerTextDrawLetterSize(playerid, NWSE[playerid][4], 0.147709, 0.778666);
	PlayerTextDrawAlignment(playerid, NWSE[playerid][4], 2);
	PlayerTextDrawColor(playerid, NWSE[playerid][4], 1886417066);
	PlayerTextDrawSetShadow(playerid, NWSE[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, NWSE[playerid][4], 0);
	PlayerTextDrawBackgroundColor(playerid, NWSE[playerid][4], 51);
	PlayerTextDrawFont(playerid, NWSE[playerid][4], 2);
	PlayerTextDrawSetProportional(playerid, NWSE[playerid][4], 1);

	NWSE[playerid][2] = CreatePlayerTextDraw(playerid, 376.167144, 30.0, "_");//105
	PlayerTextDrawLetterSize(playerid, NWSE[playerid][2], 0.147709, 0.778666);
	PlayerTextDrawAlignment(playerid, NWSE[playerid][2], 2);
	PlayerTextDrawColor(playerid, NWSE[playerid][2], 1886417066);
	PlayerTextDrawSetShadow(playerid, NWSE[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, NWSE[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, NWSE[playerid][2], 51);
	PlayerTextDrawFont(playerid, NWSE[playerid][2], 2);
	PlayerTextDrawSetProportional(playerid, NWSE[playerid][2], 1);

	NWSE[playerid][1] = CreatePlayerTextDraw(playerid, 389.583160, 30.0, "_");//120
	PlayerTextDrawLetterSize(playerid, NWSE[playerid][1], 0.147709, 0.778666);
	PlayerTextDrawAlignment(playerid, NWSE[playerid][1], 2);
	PlayerTextDrawColor(playerid, NWSE[playerid][1], 1886417066);
	PlayerTextDrawSetShadow(playerid, NWSE[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, NWSE[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, NWSE[playerid][1], 51);
	PlayerTextDrawFont(playerid, NWSE[playerid][1], 2);
	PlayerTextDrawSetProportional(playerid, NWSE[playerid][1], 1);
	
	NWSE[playerid][13] = CreatePlayerTextDraw(playerid, 226.389343, 18.433328, "hud:radar_waypoint");
	PlayerTextDrawLetterSize(playerid, NWSE[playerid][13], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, NWSE[playerid][13], 7.964838, 7.583345);
	PlayerTextDrawAlignment(playerid, NWSE[playerid][13], 1);
	PlayerTextDrawColor(playerid, NWSE[playerid][13], -1);
	PlayerTextDrawSetShadow(playerid, NWSE[playerid][13], 0);
	PlayerTextDrawSetOutline(playerid, NWSE[playerid][13], 0);
	PlayerTextDrawFont(playerid, NWSE[playerid][13], 4);
	
	Banned[playerid][0] = CreatePlayerTextDraw(playerid, 315.096984, 160.191680, "_");//B30
	PlayerTextDrawLetterSize(playerid, Banned[playerid][0], 0.353016, 2.276666);
	PlayerTextDrawAlignment(playerid, Banned[playerid][0], 1);
	PlayerTextDrawColor(playerid, Banned[playerid][0], -1061109505);
	PlayerTextDrawSetShadow(playerid, Banned[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, Banned[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, Banned[playerid][0], 51);
	PlayerTextDrawFont(playerid, Banned[playerid][0], 2);
	PlayerTextDrawSetProportional(playerid, Banned[playerid][0], 1);

	Banned[playerid][1] = CreatePlayerTextDraw(playerid, 327.606231, 209.308319, "_");//YOU ARE BANNED ON THIS SERVER
	PlayerTextDrawLetterSize(playerid, Banned[playerid][1], 0.401461, 1.600000);
	PlayerTextDrawAlignment(playerid, Banned[playerid][1], 2);
	PlayerTextDrawColor(playerid, Banned[playerid][1], -1);
	PlayerTextDrawSetShadow(playerid, Banned[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, Banned[playerid][1], 1);
	PlayerTextDrawBackgroundColor(playerid, Banned[playerid][1], 353703423);
	PlayerTextDrawFont(playerid, Banned[playerid][1], 2);
	PlayerTextDrawSetProportional(playerid, Banned[playerid][1], 1);

	Banned[playerid][2] = CreatePlayerTextDraw(playerid, 199.981048, 221.675018, "_");//Banned: ACSE
	PlayerTextDrawLetterSize(playerid, Banned[playerid][2], 0.226514, 1.442499);
	PlayerTextDrawAlignment(playerid, Banned[playerid][2], 1);
	PlayerTextDrawColor(playerid, Banned[playerid][2], -1061109505);
	PlayerTextDrawSetShadow(playerid, Banned[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, Banned[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, Banned[playerid][2], 255);
	PlayerTextDrawFont(playerid, Banned[playerid][2], 2);
	PlayerTextDrawSetProportional(playerid, Banned[playerid][2], 1);

	Banned[playerid][3] = CreatePlayerTextDraw(playerid, 200.090805, 232.591720, "_");//Reason: B30
	PlayerTextDrawLetterSize(playerid, Banned[playerid][3], 0.226514, 1.442499);
	PlayerTextDrawAlignment(playerid, Banned[playerid][3], 1);
	PlayerTextDrawColor(playerid, Banned[playerid][3], -1061109505);
	PlayerTextDrawSetShadow(playerid, Banned[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, Banned[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, Banned[playerid][3], 255);
	PlayerTextDrawFont(playerid, Banned[playerid][3], 2);
	PlayerTextDrawSetProportional(playerid, Banned[playerid][3], 1);

	Banned[playerid][4] = CreatePlayerTextDraw(playerid, 455.451416, 221.750076, "_");//Date_of_ban:_17/07/07_12:00
	PlayerTextDrawLetterSize(playerid, Banned[playerid][4], 0.174977, 1.442499);
	PlayerTextDrawAlignment(playerid, Banned[playerid][4], 3);
	PlayerTextDrawColor(playerid, Banned[playerid][4], -1061109505);
	PlayerTextDrawSetShadow(playerid, Banned[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, Banned[playerid][4], 0);
	PlayerTextDrawBackgroundColor(playerid, Banned[playerid][4], 255);
	PlayerTextDrawFont(playerid, Banned[playerid][4], 2);
	PlayerTextDrawSetProportional(playerid, Banned[playerid][4], 1);

	Banned[playerid][5] = CreatePlayerTextDraw(playerid, 455.467529, 232.550125, "_");//Date_unban:_17/07/07_15:00
	PlayerTextDrawLetterSize(playerid, Banned[playerid][5], 0.174977, 1.442499);
	PlayerTextDrawAlignment(playerid, Banned[playerid][5], 3);
	PlayerTextDrawColor(playerid, Banned[playerid][5], -1061109505);
	PlayerTextDrawSetShadow(playerid, Banned[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, Banned[playerid][5], 0);
	PlayerTextDrawBackgroundColor(playerid, Banned[playerid][5], 255);
	PlayerTextDrawFont(playerid, Banned[playerid][5], 2);
	PlayerTextDrawSetProportional(playerid, Banned[playerid][5], 1);
	
	AdmSystem[playerid][0] = CreatePlayerTextDraw(playerid, 582.997375, 174.658309, "_");//MODE:_SOLO PING: SPEED:
	PlayerTextDrawLetterSize(playerid, AdmSystem[playerid][0], 0.191844, 1.174165);
	PlayerTextDrawTextSize(playerid, AdmSystem[playerid][0], 564.100219, 77.583320);
	PlayerTextDrawAlignment(playerid, AdmSystem[playerid][0], 1);
	PlayerTextDrawColor(playerid, AdmSystem[playerid][0], -538976257);
	PlayerTextDrawUseBox(playerid, AdmSystem[playerid][0], true);
	PlayerTextDrawBoxColor(playerid, AdmSystem[playerid][0], -256);
	PlayerTextDrawSetShadow(playerid, AdmSystem[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, AdmSystem[playerid][0], 1);
	PlayerTextDrawBackgroundColor(playerid, AdmSystem[playerid][0], 16);
	PlayerTextDrawFont(playerid, AdmSystem[playerid][0], 2);
	PlayerTextDrawSetProportional(playerid, AdmSystem[playerid][0], 1);

	AdmSystem[playerid][1] = CreatePlayerTextDraw(playerid, 612.577148, 185.574920, "_");//%d %d
	PlayerTextDrawLetterSize(playerid, AdmSystem[playerid][1], 0.191844, 1.174165);
	PlayerTextDrawTextSize(playerid, AdmSystem[playerid][1], 6.560204, 174.416671);
	PlayerTextDrawAlignment(playerid, AdmSystem[playerid][1], 1);
	PlayerTextDrawColor(playerid, AdmSystem[playerid][1], -538976257);
	PlayerTextDrawUseBox(playerid, AdmSystem[playerid][1], true);
	PlayerTextDrawBoxColor(playerid, AdmSystem[playerid][1], -256);
	PlayerTextDrawSetShadow(playerid, AdmSystem[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, AdmSystem[playerid][1], 1);
	PlayerTextDrawBackgroundColor(playerid, AdmSystem[playerid][1], 16);
	PlayerTextDrawFont(playerid, AdmSystem[playerid][1], 2);
	PlayerTextDrawSetProportional(playerid, AdmSystem[playerid][1], 1);
	
	TeamMatesHP[playerid][0] = CreatePlayerTextDraw(playerid, 4.216672, 259.583251, "Alex_Dyson");
	PlayerTextDrawLetterSize(playerid, TeamMatesHP[playerid][0], 0.251112, 0.855082);
	PlayerTextDrawAlignment(playerid, TeamMatesHP[playerid][0], 1);
	PlayerTextDrawColor(playerid, TeamMatesHP[playerid][0], 16777215);
	PlayerTextDrawSetShadow(playerid, TeamMatesHP[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, TeamMatesHP[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, TeamMatesHP[playerid][0], 51);
	PlayerTextDrawFont(playerid, TeamMatesHP[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, TeamMatesHP[playerid][0], 1);

	TeamMatesHP[playerid][1] = CreatePlayerTextDraw(playerid, 4.420186, 279.475006, "DySon");
	PlayerTextDrawLetterSize(playerid, TeamMatesHP[playerid][1], 0.251112, 0.855082);
	PlayerTextDrawAlignment(playerid, TeamMatesHP[playerid][1], 1);
	PlayerTextDrawColor(playerid, TeamMatesHP[playerid][1], 16777215);
	PlayerTextDrawSetShadow(playerid, TeamMatesHP[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, TeamMatesHP[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, TeamMatesHP[playerid][1], 51);
	PlayerTextDrawFont(playerid, TeamMatesHP[playerid][1], 1);
	PlayerTextDrawSetProportional(playerid, TeamMatesHP[playerid][1], 1);

	TeamMatesHP[playerid][2] = CreatePlayerTextDraw(playerid, 4.420186, 299.475006, "Skidd");
	PlayerTextDrawLetterSize(playerid, TeamMatesHP[playerid][2], 0.251112, 0.855082);
	PlayerTextDrawAlignment(playerid, TeamMatesHP[playerid][2], 1);
	PlayerTextDrawColor(playerid, TeamMatesHP[playerid][2], 16777215);
	PlayerTextDrawSetShadow(playerid, TeamMatesHP[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, TeamMatesHP[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, TeamMatesHP[playerid][2], 51);
	PlayerTextDrawFont(playerid, TeamMatesHP[playerid][2], 1);
	PlayerTextDrawSetProportional(playerid, TeamMatesHP[playerid][2], 1);

	TeamMatesHP[playerid][3] = CreatePlayerTextDraw(playerid, 3.000000, 270.000000, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, TeamMatesHP[playerid][3], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, TeamMatesHP[playerid][3], 50.000000, 8.000000);
	PlayerTextDrawAlignment(playerid, TeamMatesHP[playerid][3], 1);
	PlayerTextDrawColor(playerid, TeamMatesHP[playerid][3], -538976416);
	PlayerTextDrawSetShadow(playerid, TeamMatesHP[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, TeamMatesHP[playerid][3], 0);
	PlayerTextDrawFont(playerid, TeamMatesHP[playerid][3], 4);

	TeamMatesHP[playerid][4] = CreatePlayerTextDraw(playerid, 3.000000, 290.000000, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, TeamMatesHP[playerid][4], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, TeamMatesHP[playerid][4], 50.000000, 8.000000);
	PlayerTextDrawAlignment(playerid, TeamMatesHP[playerid][4], 1);
	PlayerTextDrawColor(playerid, TeamMatesHP[playerid][4], -538976416);
	PlayerTextDrawSetShadow(playerid, TeamMatesHP[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, TeamMatesHP[playerid][4], 0);
	PlayerTextDrawFont(playerid, TeamMatesHP[playerid][4], 4);

	TeamMatesHP[playerid][5] = CreatePlayerTextDraw(playerid, 3.000000, 310.000000, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, TeamMatesHP[playerid][5], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, TeamMatesHP[playerid][5], 50.000000, 8.000000);
	PlayerTextDrawAlignment(playerid, TeamMatesHP[playerid][5], 1);
	PlayerTextDrawColor(playerid, TeamMatesHP[playerid][5], -538976416);
	PlayerTextDrawSetShadow(playerid, TeamMatesHP[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, TeamMatesHP[playerid][5], 0);
	PlayerTextDrawFont(playerid, TeamMatesHP[playerid][5], 4);
	
	Speedometr[playerid][0] = CreatePlayerTextDraw(playerid, 601.128906, 358.758514, "0");
	PlayerTextDrawLetterSize(playerid, Speedometr[playerid][0], 0.446251, 3.939165);
	PlayerTextDrawAlignment(playerid, Speedometr[playerid][0], 3);
	PlayerTextDrawColor(playerid, Speedometr[playerid][0], -538976257);
	PlayerTextDrawUseBox(playerid, Speedometr[playerid][0], true);
	PlayerTextDrawBoxColor(playerid, Speedometr[playerid][0], 0);
	PlayerTextDrawSetShadow(playerid, Speedometr[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, Speedometr[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, Speedometr[playerid][0], 51);
	PlayerTextDrawFont(playerid, Speedometr[playerid][0], 2);
	PlayerTextDrawSetProportional(playerid, Speedometr[playerid][0], 1);

	Speedometr[playerid][1] = CreatePlayerTextDraw(playerid, 579.092346, 401.100006, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, Speedometr[playerid][1], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, Speedometr[playerid][1], 26.000000, 5.000000);
	PlayerTextDrawAlignment(playerid, Speedometr[playerid][1], 1);
	PlayerTextDrawColor(playerid, Speedometr[playerid][1], -538976257);
	PlayerTextDrawSetShadow(playerid, Speedometr[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, Speedometr[playerid][1], 0);
	PlayerTextDrawFont(playerid, Speedometr[playerid][1], 4);
	
	TeammateSearch[playerid] = CreatePlayerTextDraw(playerid, 513.030761, 171.500000, "_");//ИГРОКИ,_КОТОРЫЕ_ИЩУТ ИГРОКОВ_В_КОМАHДУ:
	PlayerTextDrawLetterSize(playerid, TeammateSearch[playerid], 0.205899, 1.955832);
	PlayerTextDrawTextSize(playerid, TeammateSearch[playerid], 10.775974, 0.000000);
	PlayerTextDrawAlignment(playerid, TeammateSearch[playerid], 1);
	PlayerTextDrawColor(playerid, TeammateSearch[playerid], -1061109505);
	PlayerTextDrawUseBox(playerid, TeammateSearch[playerid], true);
	PlayerTextDrawBoxColor(playerid, TeammateSearch[playerid], 353703168);
	PlayerTextDrawSetShadow(playerid, TeammateSearch[playerid], 0);
	PlayerTextDrawSetOutline(playerid, TeammateSearch[playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, TeammateSearch[playerid], 353703423);
	PlayerTextDrawFont(playerid, TeammateSearch[playerid], 2);
	PlayerTextDrawSetProportional(playerid, TeammateSearch[playerid], 1);
	
	HUD[playerid][0] = CreatePlayerTextDraw(playerid, 255.0, 417.841766, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, HUD[playerid][0], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, HUD[playerid][0], 125.000000, 14.000000);
	PlayerTextDrawAlignment(playerid, HUD[playerid][0], 1);
	PlayerTextDrawColor(playerid, HUD[playerid][0], -1061109505);
	PlayerTextDrawSetShadow(playerid, HUD[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, HUD[playerid][0], 0);
	PlayerTextDrawFont(playerid, HUD[playerid][0], 4);

	HUD[playerid][1] = CreatePlayerTextDraw(playerid, 255.0, 412.649963, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, HUD[playerid][1], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, HUD[playerid][1], 25.000000, 2.000000);
	PlayerTextDrawAlignment(playerid, HUD[playerid][1], 1);
	PlayerTextDrawColor(playerid, HUD[playerid][1], -862387969);
	PlayerTextDrawSetShadow(playerid, HUD[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, HUD[playerid][1], 0);
	PlayerTextDrawFont(playerid, HUD[playerid][1], 4);

	HUD[playerid][2] = CreatePlayerTextDraw(playerid, 285.0, 412.658477, "LD_SPAC:white");
	PlayerTextDrawLetterSize(playerid, HUD[playerid][2], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, HUD[playerid][2], 50.000000, 2.000000);
	PlayerTextDrawAlignment(playerid, HUD[playerid][2], 1);
	PlayerTextDrawColor(playerid, HUD[playerid][2], -1283063553);
	PlayerTextDrawSetShadow(playerid, HUD[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, HUD[playerid][2], 0);
	PlayerTextDrawFont(playerid, HUD[playerid][2], 4);

	HUD[playerid][3] = CreatePlayerTextDraw(playerid, 369.0, 398.258575, "2");
	PlayerTextDrawLetterSize(playerid, HUD[playerid][3], 0.245256, 1.232498);
	PlayerTextDrawAlignment(playerid, HUD[playerid][3], 1);
	PlayerTextDrawColor(playerid, HUD[playerid][3], -1);
	PlayerTextDrawUseBox(playerid, HUD[playerid][3], true);
	PlayerTextDrawBoxColor(playerid, HUD[playerid][3], 0);
	PlayerTextDrawSetShadow(playerid, HUD[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, HUD[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, HUD[playerid][3], 51);
	PlayerTextDrawFont(playerid, HUD[playerid][3], 2);
	PlayerTextDrawSetProportional(playerid, HUD[playerid][3], 1);

	HUD[playerid][4] = CreatePlayerTextDraw(playerid, 349.0, 398.075317, "3");
	PlayerTextDrawLetterSize(playerid, HUD[playerid][4], 0.245256, 1.232498);
	PlayerTextDrawAlignment(playerid, HUD[playerid][4], 1);
	PlayerTextDrawColor(playerid, HUD[playerid][4], -1);
	PlayerTextDrawUseBox(playerid, HUD[playerid][4], true);
	PlayerTextDrawBoxColor(playerid, HUD[playerid][4], 0);
	PlayerTextDrawSetShadow(playerid, HUD[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, HUD[playerid][4], 0);
	PlayerTextDrawBackgroundColor(playerid, HUD[playerid][4], 51);
	PlayerTextDrawFont(playerid, HUD[playerid][4], 2);
	PlayerTextDrawSetProportional(playerid, HUD[playerid][4], 1);
	return true;
}