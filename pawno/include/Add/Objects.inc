#if defined _objectload
#endinput
#endif
#define _objectload
new Text: RewMenuT[8];
new Text: RegistrationT[5];
new Text: LobbyMenuT[31];
new Text: CharMenuT[9];
new Text: SetMenuT[19];
new Text: KeysFT[5];
new Text: KilledT[10];
new Text: NWSET[14];
new Text: BannedT[5];
new Text: TeamMatesT[6];
new Text: TOP10[3];
new Text: Offset[101];
new Text: SpeedometrT[7];
new Text: InvGunT[20];
new Text: TeammateSearchT[13];
new Text: HUDT[5];
new Text: MAPT[2];
ObjectLoad(){
	RegistrationT[0] = TextDrawCreate(841.121704, -45.166656, "usebox");
	TextDrawLetterSize(RegistrationT[0], 0.000000, 67.996589);
	TextDrawTextSize(RegistrationT[0], -68.530014, 0.000000);
	TextDrawAlignment(RegistrationT[0], 1);
	TextDrawColor(RegistrationT[0], 0);
	TextDrawUseBox(RegistrationT[0], true);
	TextDrawBoxColor(RegistrationT[0], 353703280);
	TextDrawSetShadow(RegistrationT[0], 0);
	TextDrawSetOutline(RegistrationT[0], 0);
	TextDrawFont(RegistrationT[0] , 0);
	
	MAPT[0] = TextDrawCreate(476.017517, 263.841766, "LD_SPAC:white");
	TextDrawLetterSize(MAPT[0], 0.000000, 0.000000);
	TextDrawTextSize(MAPT[0], 158.969146, 177.741714);
	TextDrawAlignment(MAPT[0], 1);
	TextDrawColor(MAPT[0], 353703423);
	TextDrawSetShadow(MAPT[0], 0);
	TextDrawSetOutline(MAPT[0], 0);
	TextDrawFont(MAPT[0], 4);
	
	MAPT[1] = TextDrawCreate(478.969635, 267.050018, "samaps:map");
	TextDrawLetterSize(MAPT[1], 0.000000, 0.000000);
	TextDrawTextSize(MAPT[1], 152.269424, 170.333404);
	TextDrawAlignment(MAPT[1], 1);
	TextDrawColor(MAPT[1], -256);
	TextDrawSetShadow(MAPT[1], 0);
	TextDrawSetOutline(MAPT[1], 0);
	TextDrawFont(MAPT[1], 4);
	
	InvGunT[0] = TextDrawCreate(478.032257, 101.291637, "New Textdraw");
	InvGunT[1] = TextDrawCreate(478.188873, 181.858276, "New Textdraw");
	InvGunT[2] = TextDrawCreate(478.251831, 262.249862, "New Textdraw");
	InvGunT[3] = TextDrawCreate(478.267944, 342.874664, "New Textdraw");
	InvGunT[4] = TextDrawCreate(542.424377, 342.999664, "New Textdraw");
	for(new td=0;td<5;td++) {
		TextDrawLetterSize(InvGunT[td], 0.449999, 1.600000);
		TextDrawTextSize(InvGunT[td], 126.969238, 79.333335);
		TextDrawAlignment(InvGunT[td], 1);
		TextDrawColor(InvGunT[td], -1);
		TextDrawUseBox(InvGunT[td], true);
		TextDrawBoxColor(InvGunT[td], 0);
		TextDrawSetShadow(InvGunT[td], 0);
		TextDrawSetOutline(InvGunT[td], 1);
		TextDrawBackgroundColor(InvGunT[td], 0x00000000);
		TextDrawFont(InvGunT[td], 5);
		TextDrawSetProportional(InvGunT[td], 1);
		TextDrawSetSelectable(InvGunT[td], true);
		TextDrawSetPreviewModel(InvGunT[td], 1649);
		TextDrawSetPreviewRot(InvGunT[td], 90.000000, 0.000000, 0.000000, 1.000000);
	}
	TextDrawTextSize(InvGunT[3], 63.000000, 79.000000);
	TextDrawTextSize(InvGunT[4], 63.000000, 79.000000);
	
	InvGunT[5] = TextDrawCreate(495.305908, 103.491664, "usebox");
	InvGunT[6] = TextDrawCreate(495.462677, 184.233337, "usebox");
	InvGunT[7] = TextDrawCreate(495.525604, 264.741699, "usebox");
	InvGunT[8] = TextDrawCreate(495.588562, 345.074951, "usebox");
	InvGunT[9] = TextDrawCreate(559.933410, 345.258300, "usebox");
	for(new td=5;td<10;td++) {
		TextDrawLetterSize(InvGunT[td], 0.000000, 1.506741);
		TextDrawTextSize(InvGunT[td], 476.313415, 0.000000);
		TextDrawAlignment(InvGunT[td], 1);
		TextDrawColor(InvGunT[td], 0);
		TextDrawUseBox(InvGunT[td], true);
		TextDrawBoxColor(InvGunT[td], 255);
		TextDrawSetShadow(InvGunT[td], 0);
		TextDrawSetOutline(InvGunT[td], 0);
		TextDrawFont(InvGunT[td], 0);
	}
	TextDrawTextSize(InvGunT[9], 540.595336, 0.000000);

	InvGunT[10] = TextDrawCreate(486.325286, 101.583320, "1");
	InvGunT[11] = TextDrawCreate(486.856689, 181.916656, "2");
	InvGunT[12] = TextDrawCreate(486.388244, 262.416702, "3");
	InvGunT[13] = TextDrawCreate(486.451141, 343.333282, "4");
	InvGunT[14] = TextDrawCreate(551.732299, 343.400207, "5");
	for(new td=10;td<15;td++) {
		TextDrawLetterSize(InvGunT[td], 0.449999, 1.600000);
		TextDrawAlignment(InvGunT[td], 2);
		TextDrawColor(InvGunT[td], -1);
		TextDrawSetShadow(InvGunT[td], 0);
		TextDrawSetOutline(InvGunT[td], 0);
		TextDrawBackgroundColor(InvGunT[td], 51);
		TextDrawFont(InvGunT[td], 2);
		TextDrawSetProportional(InvGunT[td], 1);
	}

	InvGunT[15] = TextDrawCreate(480.0, 183.0, "usebox");
	InvGunT[16] = TextDrawCreate(480.0, 263.0, "usebox");
	InvGunT[17] = TextDrawCreate(480.0, 343.0, "usebox");
	InvGunT[18] = TextDrawCreate(545.0, 443.0, "usebox");
	InvGunT[19] = TextDrawCreate(480.0, 443.0, "usebox");
	for(new td=15;td<20;td++) {
		TextDrawLetterSize(InvGunT[td], 0.000000, -0.3);
		TextDrawTextSize(InvGunT[td], 603.0, 0.000000);
		TextDrawAlignment(InvGunT[td], 1);
		TextDrawColor(InvGunT[td], 0);
		TextDrawUseBox(InvGunT[td], true);
		TextDrawBoxColor(InvGunT[td], -1);
		TextDrawSetShadow(InvGunT[td], 0);
		TextDrawSetOutline(InvGunT[td], 0);
		TextDrawFont(InvGunT[td], 0);
	}
	TextDrawTextSize(InvGunT[19], 539.282531, 0.000000);
	
	SpeedometrT[0] = TextDrawCreate(605.048339, 373.333343, "km/h");
	TextDrawLetterSize(SpeedometrT[0], 0.362385, 2.171664);
	TextDrawAlignment(SpeedometrT[0], 1);
	TextDrawColor(SpeedometrT[0], -538976257);
	TextDrawUseBox(SpeedometrT[0], true);
	TextDrawBoxColor(SpeedometrT[0], 0);
	TextDrawSetShadow(SpeedometrT[0], 0);
	TextDrawSetOutline(SpeedometrT[0], 0);
	TextDrawBackgroundColor(SpeedometrT[0], 51);
	TextDrawFont(SpeedometrT[0], 1);
	TextDrawSetProportional(SpeedometrT[0], 1);

	SpeedometrT[1] = TextDrawCreate(577.639587, 406.291870, "LD_SPAC:white");
	TextDrawLetterSize(SpeedometrT[1], 0.000000, 0.000000);
	TextDrawTextSize(SpeedometrT[1], 55.000000, 1.500000);
	TextDrawAlignment(SpeedometrT[1], 1);
	TextDrawColor(SpeedometrT[1], 353703423);
	TextDrawSetShadow(SpeedometrT[1], 0);
	TextDrawSetOutline(SpeedometrT[1], 0);
	TextDrawFont(SpeedometrT[1], 4);

	SpeedometrT[2] = TextDrawCreate(577.468505, 398.716979, "LD_SPAC:white");
	TextDrawLetterSize(SpeedometrT[2], 0.000000, 0.000000);
	TextDrawTextSize(SpeedometrT[2], 1.500000, 8.000000);
	TextDrawAlignment(SpeedometrT[2], 1);
	TextDrawColor(SpeedometrT[2], 353703423);
	TextDrawSetShadow(SpeedometrT[2], 0);
	TextDrawSetOutline(SpeedometrT[2], 0);
	TextDrawFont(SpeedometrT[2], 4);

	SpeedometrT[3] = TextDrawCreate(631.271179, 398.900390, "LD_SPAC:white");
	TextDrawLetterSize(SpeedometrT[3], 0.000000, 0.000000);
	TextDrawTextSize(SpeedometrT[3], 1.500000, 8.000000);
	TextDrawAlignment(SpeedometrT[3], 1);
	TextDrawColor(SpeedometrT[3], 353703423);
	TextDrawSetShadow(SpeedometrT[3], 0);
	TextDrawSetOutline(SpeedometrT[3], 0);
	TextDrawFont(SpeedometrT[3], 4);

	SpeedometrT[4] = TextDrawCreate(604.206542, 399.725402, "LD_SPAC:white");
	TextDrawLetterSize(SpeedometrT[4], 0.000000, 0.000000);
	TextDrawTextSize(SpeedometrT[4], 1.500000, 8.000000);
	TextDrawAlignment(SpeedometrT[4], 1);
	TextDrawColor(SpeedometrT[4], 353703423);
	TextDrawSetShadow(SpeedometrT[4], 0);
	TextDrawSetOutline(SpeedometrT[4], 0);
	TextDrawFont(SpeedometrT[4], 4);

	SpeedometrT[5] = TextDrawCreate(576.000183, 388.441528, "E");
	TextDrawLetterSize(SpeedometrT[5], 0.228857, 1.051666);
	TextDrawAlignment(SpeedometrT[5], 1);
	TextDrawColor(SpeedometrT[5], -1523963137);
	TextDrawSetShadow(SpeedometrT[5], 0);
	TextDrawSetOutline(SpeedometrT[5], 0);
	TextDrawBackgroundColor(SpeedometrT[5], 51);
	TextDrawFont(SpeedometrT[5], 2);
	TextDrawSetProportional(SpeedometrT[5], 1);

	SpeedometrT[6] = TextDrawCreate(629.615051, 389.324829, "F");
	TextDrawLetterSize(SpeedometrT[6], 0.314597, 1.051666);
	TextDrawAlignment(SpeedometrT[6], 1);
	TextDrawColor(SpeedometrT[6], -538976257);
	TextDrawUseBox(SpeedometrT[6], true);
	TextDrawBoxColor(SpeedometrT[6], 0);
	TextDrawSetShadow(SpeedometrT[6], 0);
	TextDrawSetOutline(SpeedometrT[6], 0);
	TextDrawBackgroundColor(SpeedometrT[6], 51);
	TextDrawFont(SpeedometrT[6], 1);
	TextDrawSetProportional(SpeedometrT[6], 1);
	
	for(new td=0;td<101;td++) {
		Offset[td] = TextDrawCreate(637.892395, 426.825195, "3:00");
		TextDrawLetterSize(Offset[td], 0.328652, 2.241666);
		TextDrawAlignment(Offset[td], 3);
		TextDrawColor(Offset[td], -538976257);
		TextDrawSetShadow(Offset[td], 0);
		TextDrawSetOutline(Offset[td], 1);
		TextDrawBackgroundColor(Offset[td], 353703280);
		TextDrawFont(Offset[td], 2);
		TextDrawSetProportional(Offset[td], 1);
	}
	
	CharMenuT[0] = TextDrawCreate(311.224304, 73.424987, "usebox");
	CharMenuT[1] = TextDrawCreate(311.240142, 266.749908, "usebox");
	for(new td=0;td<2;td++) {
		TextDrawLetterSize(CharMenuT[td], 0.000000, -0.358830);
		TextDrawTextSize(CharMenuT[td], 630.035278, 0.000000);
		TextDrawAlignment(CharMenuT[td], 1);
		TextDrawColor(CharMenuT[td], 0);
		TextDrawUseBox(CharMenuT[td], true);
		TextDrawBoxColor(CharMenuT[td], -5963521);
		TextDrawSetShadow(CharMenuT[td], 0);
		TextDrawSetOutline(CharMenuT[td], 0);
		TextDrawFont(CharMenuT[td], 0);
	}
	CharMenuT[2] = TextDrawCreate(312.224304, 284.425018, "usebox");
	CharMenuT[3] = TextDrawCreate(312.240142, 366.916564, "usebox");
	for(new td=2;td<4;td++) {
		TextDrawLetterSize(CharMenuT[td], 0.000000, -0.358830);
		TextDrawTextSize(CharMenuT[td], 630.035278, 0.000000);
		TextDrawAlignment(CharMenuT[td], 1);
		TextDrawColor(CharMenuT[td], 0);
		TextDrawUseBox(CharMenuT[td], true);
		TextDrawBoxColor(CharMenuT[td], -192);
		TextDrawSetShadow(CharMenuT[td], 0);
		TextDrawSetOutline(CharMenuT[td], 0);
		TextDrawFont(CharMenuT[td], 0);
	}
	CharMenuT[4] = TextDrawCreate(301.727630, 137.783325, "LD_BEAT:up");
	TextDrawLetterSize(CharMenuT[4], 0.000000, 0.000000);
	TextDrawTextSize(CharMenuT[4], 9.885780, 27.008321);
	TextDrawAlignment(CharMenuT[4], 1);
	TextDrawColor(CharMenuT[4], -5963521);//-2139062017
	TextDrawSetShadow(CharMenuT[4], 0);
	TextDrawSetOutline(CharMenuT[4], 0);
	TextDrawFont(CharMenuT[4], 4);
	TextDrawSetSelectable(CharMenuT[4], true);

	CharMenuT[5] = TextDrawCreate(301.790649, 166.958343, "LD_BEAT:down");
	TextDrawLetterSize(CharMenuT[5], 0.000000, 0.000000);
	TextDrawTextSize(CharMenuT[5], 9.885780, 27.008321);
	TextDrawAlignment(CharMenuT[5], 1);
	TextDrawColor(CharMenuT[5], -5963521);
	TextDrawSetShadow(CharMenuT[5], 0);
	TextDrawSetOutline(CharMenuT[5], 0);
	TextDrawFont(CharMenuT[5], 4);
	TextDrawSetSelectable(CharMenuT[5], true);

	CharMenuT[6] = TextDrawCreate(278.864074, 76.474998, "knop");
	TextDrawLetterSize(CharMenuT[6], 0.449999, 1.600000);
	TextDrawTextSize(CharMenuT[6], 22.489017, 30.916664);
	TextDrawAlignment(CharMenuT[6], 1);
	TextDrawColor(CharMenuT[6], -1);
	TextDrawUseBox(CharMenuT[6], true);
	TextDrawBoxColor(CharMenuT[6], -256);
	TextDrawSetShadow(CharMenuT[6], 0);
	TextDrawSetOutline(CharMenuT[6], 1);
	TextDrawBackgroundColor(CharMenuT[6], -160);
	TextDrawFont(CharMenuT[6], 5);
	TextDrawSetProportional(CharMenuT[6], 1);
	TextDrawSetSelectable(CharMenuT[6], true);
	TextDrawSetPreviewModel(CharMenuT[6], 33);
	TextDrawSetPreviewRot(CharMenuT[6], 0.000000, 0.000000, 0.000000, 1.000000);

	CharMenuT[7] = TextDrawCreate(278.973846, 110.550010, "knop");
	TextDrawLetterSize(CharMenuT[7], 0.449999, 1.600000);
	TextDrawTextSize(CharMenuT[7], 22.489017, 30.916664);
	TextDrawAlignment(CharMenuT[7], 1);
	TextDrawColor(CharMenuT[7], -1);
	TextDrawUseBox(CharMenuT[7], true);
	TextDrawBoxColor(CharMenuT[7], -256);
	TextDrawSetShadow(CharMenuT[7], 0);
	TextDrawSetOutline(CharMenuT[7], 1);
	TextDrawBackgroundColor(CharMenuT[7], -160);
	TextDrawFont(CharMenuT[7], 5);
	TextDrawSetProportional(CharMenuT[7], 1);
	TextDrawSetSelectable(CharMenuT[7], true);
	TextDrawSetPreviewModel(CharMenuT[7], 19012);
	TextDrawSetPreviewRot(CharMenuT[7], 160.000000, 180.000000, -80.000000, 1.000000);

	CharMenuT[8] = TextDrawCreate(279.083587, 145.266708, "knop");
	TextDrawLetterSize(CharMenuT[8], 0.449999, 1.600000);
	TextDrawTextSize(CharMenuT[8], 22.489017, 30.916664);
	TextDrawAlignment(CharMenuT[8], 1);
	TextDrawColor(CharMenuT[8], -1);
	TextDrawUseBox(CharMenuT[8], true);
	TextDrawBoxColor(CharMenuT[8], -256);
	TextDrawSetShadow(CharMenuT[8], 0);
	TextDrawSetOutline(CharMenuT[8], 1);
	TextDrawBackgroundColor(CharMenuT[8], -160);
	TextDrawFont(CharMenuT[8], 5);
	TextDrawSetProportional(CharMenuT[8], 1);
	TextDrawSetSelectable(CharMenuT[8], true);
	TextDrawSetPreviewModel(CharMenuT[8], 18947);
	TextDrawSetPreviewRot(CharMenuT[8], 100.000000, 100.000000, 80.000000, 1.000000);

	SetMenuT[0] = TextDrawCreate(335.587219, 67.416648, "usebox");
	TextDrawLetterSize(SetMenuT[0], 0.000000, -0.363516);
	TextDrawTextSize(SetMenuT[0], 630.035156, 0.000000);
	TextDrawAlignment(SetMenuT[0], 1);
	TextDrawColor(SetMenuT[0], 0);
	TextDrawUseBox(SetMenuT[0], true);
	TextDrawBoxColor(SetMenuT[0], -5963521);
	TextDrawSetShadow(SetMenuT[0], 0);
	TextDrawSetOutline(SetMenuT[0], 0);
	TextDrawFont(SetMenuT[0], 0);

	SetMenuT[1] = TextDrawCreate(335.650085, 147.049972, "usebox");
	TextDrawLetterSize(SetMenuT[1], 0.000000, -0.363516);
	TextDrawTextSize(SetMenuT[1], 630.035278, 0.000000);
	TextDrawAlignment(SetMenuT[1], 1);
	TextDrawColor(SetMenuT[1], 0);
	TextDrawUseBox(SetMenuT[1], true);
	TextDrawBoxColor(SetMenuT[1], -5963521);
	TextDrawSetShadow(SetMenuT[1], 0);
	TextDrawSetOutline(SetMenuT[1], 0);
	TextDrawFont(SetMenuT[1], 0);

	SetMenuT[2] = TextDrawCreate(336.228271, 144.316741, "usebox");
	TextDrawLetterSize(SetMenuT[2], 0.000000, -8.656341);
	TextDrawTextSize(SetMenuT[2], 629.566772, 0.000000);
	TextDrawAlignment(SetMenuT[2], 1);
	TextDrawColor(SetMenuT[2], 0);
	TextDrawUseBox(SetMenuT[2], true);
	TextDrawBoxColor(SetMenuT[2], 353703248);
	TextDrawSetShadow(SetMenuT[2], 0);
	TextDrawSetOutline(SetMenuT[2], 0);
	TextDrawFont(SetMenuT[2], 0);
	
	SetMenuT[3] = TextDrawCreate(276.895965, 572.833129, "New Textdraw");
	TextDrawLetterSize(SetMenuT[3], 0.449999, 1.600000);
	TextDrawAlignment(SetMenuT[3], 1);
	TextDrawColor(SetMenuT[3], -1);
	TextDrawSetShadow(SetMenuT[3], 0);
	TextDrawSetOutline(SetMenuT[3], 1);
	TextDrawBackgroundColor(SetMenuT[3], 51);
	TextDrawFont(SetMenuT[3], 1);
	TextDrawSetProportional(SetMenuT[3], 1);

	SetMenuT[4] = TextDrawCreate(338.585815, 112.775016, "LD_SPAC:white");
	TextDrawLetterSize(SetMenuT[4], 0.000000, 0.000000);
	TextDrawTextSize(SetMenuT[4], 7.496335, 8.225008);
	TextDrawAlignment(SetMenuT[4], 1);
	TextDrawColor(SetMenuT[4], -1061109505);
	TextDrawSetShadow(SetMenuT[4], 0);
	TextDrawSetOutline(SetMenuT[4], 0);
	TextDrawFont(SetMenuT[4], 4);
	TextDrawSetSelectable(SetMenuT[4], true);

	SetMenuT[5] = TextDrawCreate(344.755554, 124.750007, "LD_SPAC:white");
	TextDrawLetterSize(SetMenuT[5], 0.000000, 0.000000);
	TextDrawTextSize(SetMenuT[5], 12.696924, 14.291663);
	TextDrawAlignment(SetMenuT[5], 1);
	TextDrawColor(SetMenuT[5], -1061109505);
	TextDrawSetShadow(SetMenuT[5], 0);
	TextDrawSetOutline(SetMenuT[5], 0);
	TextDrawFont(SetMenuT[5], 4);
	TextDrawSetSelectable(SetMenuT[5], true);

	SetMenuT[6] = TextDrawCreate(347.268066, 122.733299, "0");
	TextDrawLetterSize(SetMenuT[6], 0.464898, 1.600000);
	TextDrawAlignment(SetMenuT[6], 1);
	TextDrawColor(SetMenuT[6], 255);
	TextDrawUseBox(SetMenuT[6], true);
	TextDrawBoxColor(SetMenuT[6], 0);
	TextDrawSetShadow(SetMenuT[6], 0);
	TextDrawSetOutline(SetMenuT[6], 0);
	TextDrawBackgroundColor(SetMenuT[6], 51);
	TextDrawFont(SetMenuT[6], 1);
	TextDrawSetProportional(SetMenuT[6], 1);

	SetMenuT[7] = TextDrawCreate(346.224090, 130.416625, "LD_SPAC:white");
	TextDrawLetterSize(SetMenuT[7], 0.000000, 0.000000);
	TextDrawTextSize(SetMenuT[7], 9.885797, 7.291665);
	TextDrawAlignment(SetMenuT[7], 1);
	TextDrawColor(SetMenuT[7], 255);
	TextDrawSetShadow(SetMenuT[7], 0);
	TextDrawSetOutline(SetMenuT[7], 0);
	TextDrawFont(SetMenuT[7], 4);
	TextDrawSetSelectable(SetMenuT[7], false);

	SetMenuT[8] = TextDrawCreate(366.417327, 124.758338, "LD_SPAC:white");
	TextDrawLetterSize(SetMenuT[8], 0.000000, 0.000000);
	TextDrawTextSize(SetMenuT[8], 12.696924, 14.291663);
	TextDrawAlignment(SetMenuT[8], 1);
	TextDrawColor(SetMenuT[8], -1061109505);
	TextDrawSetShadow(SetMenuT[8], 0);
	TextDrawSetOutline(SetMenuT[8], 0);
	TextDrawFont(SetMenuT[8], 4);
	TextDrawSetSelectable(SetMenuT[8], true);

	SetMenuT[9] = TextDrawCreate(368.960449, 125.300041, "$");
	TextDrawLetterSize(SetMenuT[9], 0.411112, 1.424999);
	TextDrawAlignment(SetMenuT[9], 1);
	TextDrawColor(SetMenuT[9], 255);
	TextDrawUseBox(SetMenuT[9], true);
	TextDrawBoxColor(SetMenuT[9], 0);
	TextDrawSetShadow(SetMenuT[9], 0);
	TextDrawSetOutline(SetMenuT[9], 0);
	TextDrawBackgroundColor(SetMenuT[9], 51);
	TextDrawFont(SetMenuT[9], 3);
	TextDrawSetProportional(SetMenuT[9], 1);

	SetMenuT[10] = TextDrawCreate(430.336761, 71.283340, "LD_BEAT:left");
	TextDrawLetterSize(SetMenuT[10], 0.000000, 0.000000);
	TextDrawTextSize(SetMenuT[10], 7.496337, 8.225010);
	TextDrawAlignment(SetMenuT[10], 1);
	TextDrawColor(SetMenuT[10], -1061109505);
	TextDrawSetShadow(SetMenuT[10], 0);
	TextDrawSetOutline(SetMenuT[10], 0);
	TextDrawFont(SetMenuT[10], 4);
	TextDrawSetSelectable(SetMenuT[10], true);

	SetMenuT[11] = TextDrawCreate(495.524444, 71.291656, "LD_BEAT:right");
	TextDrawLetterSize(SetMenuT[11], 0.000000, 0.000000);
	TextDrawTextSize(SetMenuT[11], 7.496337, 8.225010);
	TextDrawAlignment(SetMenuT[11], 1);
	TextDrawColor(SetMenuT[11], -1061109505);
	TextDrawSetShadow(SetMenuT[11], 0);
	TextDrawSetOutline(SetMenuT[11], 0);
	TextDrawFont(SetMenuT[11], 4);
	TextDrawSetSelectable(SetMenuT[11], true);

	SetMenuT[12] = TextDrawCreate(382.844665, 80.333351, "LD_BEAT:left");
	SetMenuT[13] = TextDrawCreate(441.660736, 80.633338, "LD_BEAT:right");
	SetMenuT[14] = TextDrawCreate(338.459808, 90.241699, "LD_SPAC:white");
	SetMenuT[15] = TextDrawCreate(338.569641, 101.333343, "LD_SPAC:white");
	for(new td=12;td<16;td++) {
		TextDrawLetterSize(SetMenuT[td], 0.000000, 0.000000);
		TextDrawTextSize(SetMenuT[td], 7.496337, 8.225010);
		TextDrawAlignment(SetMenuT[td], 1);
		TextDrawColor(SetMenuT[td], -1061109505);
		TextDrawSetShadow(SetMenuT[td], 0);
		TextDrawSetOutline(SetMenuT[td], 0);
		TextDrawFont(SetMenuT[td], 4);
		TextDrawSetSelectable(SetMenuT[td], true);
	}
	SetMenuT[16] = TextDrawCreate(339.820007, 88.800025, "V");
	SetMenuT[17] = TextDrawCreate(339.820007, 99.716712, "V");
	SetMenuT[18] = TextDrawCreate(339.820007, 111.275047, "V");
	for(new td=16;td<19;td++) {
		TextDrawLetterSize(SetMenuT[td], 0.194187, 1.110000);
		TextDrawAlignment(SetMenuT[td], 1);
		TextDrawColor(SetMenuT[td], 255);
		TextDrawSetShadow(SetMenuT[td], 0);
		TextDrawSetOutline(SetMenuT[td], 0);
		TextDrawBackgroundColor(SetMenuT[td], 51);
		TextDrawFont(SetMenuT[td], 2);
		TextDrawSetProportional(SetMenuT[td], 1);
	}
	
	TOP10[0] = TextDrawCreate(579.373535, 414.691772, "TOP_10");
	TextDrawLetterSize(TOP10[0], 0.328652, 1.588333);
	TextDrawAlignment(TOP10[0], 1);
	TextDrawColor(TOP10[0], -5963521);
	TextDrawSetShadow(TOP10[0], 0);
	TextDrawSetOutline(TOP10[0], 0);
	TextDrawBackgroundColor(TOP10[0], 51);
	TextDrawFont(TOP10[0], 2);
	TextDrawSetProportional(TOP10[0], 1);

	TOP10[1] = TextDrawCreate(575.391113, 413.116668, "LD_SPAC:white");
	TextDrawLetterSize(TOP10[1], 0.000000, 0.000000);
	TextDrawTextSize(TOP10[1], 50.000000, 20.000000);
	TextDrawAlignment(TOP10[1], 1);
	TextDrawColor(TOP10[1], -1);
	TextDrawSetShadow(TOP10[1], 0);
	TextDrawSetOutline(TOP10[1], 0);
	TextDrawFont(TOP10[1], 4);
	TextDrawSetSelectable(TOP10[1], true);
	TextDrawSetPreviewModel(TOP10[1], 96);
	TextDrawSetPreviewRot(TOP10[1], 0.000000, 0.000000, 0.000000, 1.000000);

	TOP10[2] = TextDrawCreate(577.562500, 414.933258, "LD_SPAC:white");
	TextDrawLetterSize(TOP10[2], 0.000000, 0.000000);
	TextDrawTextSize(TOP10[2], 46.000000, 16.000000);
	TextDrawAlignment(TOP10[2], 1);
	TextDrawColor(TOP10[2], 353703423);
	TextDrawSetShadow(TOP10[2], 0);
	TextDrawSetOutline(TOP10[2], 0);
	TextDrawFont(TOP10[2], 4);
	TextDrawSetPreviewModel(TOP10[2], 96);
	TextDrawSetPreviewRot(TOP10[2], 0.000000, 0.000000, 0.000000, 1.000000);
	
	LobbyMenuT[0] = TextDrawCreate(-16.272287, 12.000000, "usebox");
	TextDrawLetterSize(LobbyMenuT[0], 0.000000, 2.479805);
	TextDrawTextSize(LobbyMenuT[0], 640.342407, 0.000000);
	TextDrawAlignment(LobbyMenuT[0], 1);
	TextDrawColor(LobbyMenuT[0], 0);
	TextDrawUseBox(LobbyMenuT[0], true);
	TextDrawBoxColor(LobbyMenuT[0], 353703248);
	TextDrawSetShadow(LobbyMenuT[0], 0);
	TextDrawSetOutline(LobbyMenuT[0], 0);
	TextDrawFont(LobbyMenuT[0], 0);

	LobbyMenuT[2] = TextDrawCreate(613.903686, 14.875000, "LD_SPAC:white");
	TextDrawLetterSize(LobbyMenuT[2], 0.000000, 0.000000);
	TextDrawTextSize(LobbyMenuT[2], 15.508064, 17.208330);
	TextDrawAlignment(LobbyMenuT[2], 1);
	TextDrawColor(LobbyMenuT[2], -1061109505);
	TextDrawSetShadow(LobbyMenuT[2], 0);
	TextDrawSetOutline(LobbyMenuT[2], 0);
	TextDrawFont(LobbyMenuT[2], 4);
	TextDrawSetSelectable(LobbyMenuT[2], true);

	LobbyMenuT[3] = TextDrawCreate(621.776550, 14.666666, "O");
	TextDrawLetterSize(LobbyMenuT[3], 0.558598, 1.910912);
	TextDrawAlignment(LobbyMenuT[3], 2);
	TextDrawColor(LobbyMenuT[3], 255);
	TextDrawSetShadow(LobbyMenuT[3], 0);
	TextDrawSetOutline(LobbyMenuT[3], 0);
	TextDrawBackgroundColor(LobbyMenuT[3], 51);
	TextDrawFont(LobbyMenuT[3], 1);
	TextDrawSetProportional(LobbyMenuT[3], 1);

	LobbyMenuT[4] = TextDrawCreate(620.135009, 14.700008, "I");
	TextDrawLetterSize(LobbyMenuT[4], 0.363323, 1.086665);
	TextDrawAlignment(LobbyMenuT[4], 1);
	TextDrawColor(LobbyMenuT[4], 255);
	TextDrawSetShadow(LobbyMenuT[4], 0);
	TextDrawSetOutline(LobbyMenuT[4], 0);
	TextDrawBackgroundColor(LobbyMenuT[4], 51);
	TextDrawFont(LobbyMenuT[4], 1);
	TextDrawSetProportional(LobbyMenuT[4], 1);

	LobbyMenuT[5] = TextDrawCreate(594.663452, 14.824995, "LD_SPAC:white");
	TextDrawLetterSize(LobbyMenuT[5], 0.000000, 0.000000);
	TextDrawTextSize(LobbyMenuT[5], 15.508064, 17.208330);
	TextDrawAlignment(LobbyMenuT[5], 1);
	TextDrawColor(LobbyMenuT[5], -1061109505);
	TextDrawSetShadow(LobbyMenuT[5], 0);
	TextDrawSetOutline(LobbyMenuT[5], 0);
	TextDrawFont(LobbyMenuT[5], 4);
	TextDrawSetSelectable(LobbyMenuT[5], true);
	LobbyMenuT[6] = TextDrawCreate(602.691772, 15.241662, "O");
	TextDrawLetterSize(LobbyMenuT[6], 0.461241, 1.716663);
	TextDrawAlignment(LobbyMenuT[6], 2);
	TextDrawColor(LobbyMenuT[6], 255);
	TextDrawUseBox(LobbyMenuT[6], true);
	TextDrawBoxColor(LobbyMenuT[6], 0);
	TextDrawSetShadow(LobbyMenuT[6], 0);
	TextDrawSetOutline(LobbyMenuT[6], 0);
	TextDrawBackgroundColor(LobbyMenuT[6], 51);
	TextDrawFont(LobbyMenuT[6], 1);
	TextDrawSetProportional(LobbyMenuT[6], 1);

	LobbyMenuT[7] = TextDrawCreate(577.312561, 2.099967, ".");
	TextDrawLetterSize(LobbyMenuT[7], 1.571588, 6.767742);
	TextDrawAlignment(LobbyMenuT[7], 1);
	TextDrawColor(LobbyMenuT[7], -5963521);
	TextDrawUseBox(LobbyMenuT[7], true);
	TextDrawBoxColor(LobbyMenuT[7], 0);
	TextDrawSetShadow(LobbyMenuT[7], 0);
	TextDrawSetOutline(LobbyMenuT[7], -1);
	TextDrawBackgroundColor(LobbyMenuT[7], -5963521);
	TextDrawFont(LobbyMenuT[7], 1);
	TextDrawSetProportional(LobbyMenuT[7], 1);

	LobbyMenuT[8] = TextDrawCreate(579.827209, 38.866676, "p");
	TextDrawLetterSize(LobbyMenuT[8], 0.311503, 1.115249);
	TextDrawAlignment(LobbyMenuT[8], 1);
	TextDrawColor(LobbyMenuT[8], -1);
	TextDrawUseBox(LobbyMenuT[8], true);
	TextDrawBoxColor(LobbyMenuT[8], 0);
	TextDrawSetShadow(LobbyMenuT[8], 0);
	TextDrawSetOutline(LobbyMenuT[8], 0);
	TextDrawBackgroundColor(LobbyMenuT[8], 51);
	TextDrawFont(LobbyMenuT[8], 0);
	TextDrawSetProportional(LobbyMenuT[8], 1);
	LobbyMenuT[9] = TextDrawCreate(600.503479, 3.791651, ".");
	LobbyMenuT[10] = TextDrawCreate(600.566406, 13.308320, ".");
	LobbyMenuT[11] = TextDrawCreate(604.986572, 8.241653, ".");
	LobbyMenuT[12] = TextDrawCreate(596.288208, 8.308319, ".");
	for(new td=9;td<13;td++) {
		TextDrawLetterSize(LobbyMenuT[td], 0.493759, 2.192666);
		TextDrawAlignment(LobbyMenuT[td], 1);
		TextDrawColor(LobbyMenuT[td], 255);
		TextDrawUseBox(LobbyMenuT[td], true);
		TextDrawBoxColor(LobbyMenuT[td], 0);
		TextDrawSetShadow(LobbyMenuT[td], 0);
		TextDrawSetOutline(LobbyMenuT[td], 0);
		TextDrawBackgroundColor(LobbyMenuT[td], 255);
		TextDrawFont(LobbyMenuT[td], 1);
		TextDrawSetProportional(LobbyMenuT[td], 1);
	}
	LobbyMenuT[13] = TextDrawCreate(597.850585, 17.299989, ".");
	LobbyMenuT[14] = TextDrawCreate(597.850585, 10.083312, ".");
	LobbyMenuT[15] = TextDrawCreate(603.786315, 10.083312, ".");
	LobbyMenuT[16] = TextDrawCreate(603.786315, 17.299989, ".");
	for(new td=13;td<17;td++) {
		TextDrawLetterSize(LobbyMenuT[td], 0.384734, 1.412749);
		TextDrawAlignment(LobbyMenuT[td], 1);
		TextDrawColor(LobbyMenuT[td], 255);
		TextDrawUseBox(LobbyMenuT[td], true);
		TextDrawBoxColor(LobbyMenuT[td], 0);
		TextDrawSetShadow(LobbyMenuT[td], 0);
		TextDrawSetOutline(LobbyMenuT[td], 0);
		TextDrawBackgroundColor(LobbyMenuT[td], 255);
		TextDrawFont(LobbyMenuT[td], 1);
		TextDrawSetProportional(LobbyMenuT[td], 1);
	}
	LobbyMenuT[17] = TextDrawCreate(581.998535, 41.733345, "p");
	TextDrawLetterSize(LobbyMenuT[17], 0.311503, 1.115249);
	TextDrawAlignment(LobbyMenuT[17], 1);
	TextDrawColor(LobbyMenuT[17], -1);
	TextDrawUseBox(LobbyMenuT[17], true);
	TextDrawBoxColor(LobbyMenuT[17], 0);
	TextDrawSetShadow(LobbyMenuT[17], 0);
	TextDrawSetOutline(LobbyMenuT[17], 0);
	TextDrawBackgroundColor(LobbyMenuT[17], 51);
	TextDrawFont(LobbyMenuT[17], 0);
	TextDrawSetProportional(LobbyMenuT[17], 1);

	LobbyMenuT[18] = TextDrawCreate(584.123046, 43.141689, "p");
	TextDrawLetterSize(LobbyMenuT[18], -0.282112, 1.115249);
	TextDrawAlignment(LobbyMenuT[18], 1);
	TextDrawColor(LobbyMenuT[18], -1);
	TextDrawUseBox(LobbyMenuT[18], true);
	TextDrawBoxColor(LobbyMenuT[18], 0);
	TextDrawSetShadow(LobbyMenuT[18], 0);
	TextDrawSetOutline(LobbyMenuT[18], 0);
	TextDrawBackgroundColor(LobbyMenuT[18], 51);
	TextDrawFont(LobbyMenuT[18], 0);
	TextDrawSetProportional(LobbyMenuT[18], 1);

	
	LobbyMenuT[19] = TextDrawCreate(9.510991, 42.591621, "battlegrounds");
	TextDrawLetterSize(LobbyMenuT[19], 0.286951, 2.299995);
	TextDrawTextSize(LobbyMenuT[19], 116.193237, 22.750015);
	TextDrawAlignment(LobbyMenuT[19], 1);
	TextDrawColor(LobbyMenuT[19], -5963521);
	TextDrawUseBox(LobbyMenuT[19], true);
	TextDrawBoxColor(LobbyMenuT[19], 0);
	TextDrawSetShadow(LobbyMenuT[19], 1);
	TextDrawSetOutline(LobbyMenuT[19], 0);
	TextDrawBackgroundColor(LobbyMenuT[19], 353703232);
	TextDrawFont(LobbyMenuT[19], 2);
	TextDrawSetProportional(LobbyMenuT[19], 1);
	TextDrawSetSelectable(LobbyMenuT[19], true);
	
	LobbyMenuT[20] = TextDrawCreate(109.385070, 23.083311, "usebox");
	TextDrawLetterSize(LobbyMenuT[20], 0.000000, 11.989786);
	TextDrawTextSize(LobbyMenuT[20], 7.464128, 0.000000);
	TextDrawAlignment(LobbyMenuT[20], 1);
	TextDrawColor(LobbyMenuT[20], 0);
	TextDrawUseBox(LobbyMenuT[20], true);
	TextDrawBoxColor(LobbyMenuT[20], 0x00000040);
	TextDrawSetShadow(LobbyMenuT[20], 0);
	TextDrawSetOutline(LobbyMenuT[20], 0);
	TextDrawFont(LobbyMenuT[20], 0);
	LobbyMenuT[1] = TextDrawCreate(-249.206375, -218.166839, "LD_NONE:explm03");
	TextDrawLetterSize(LobbyMenuT[1], 0.000000, 0.000000);
	TextDrawTextSize(LobbyMenuT[1], 487.262664, 352.916442);
	TextDrawAlignment(LobbyMenuT[1], 1);
	TextDrawColor(LobbyMenuT[1], -5963521);
	TextDrawSetShadow(LobbyMenuT[1], 0);
	TextDrawSetOutline(LobbyMenuT[1], 0);
	TextDrawFont(LobbyMenuT[1], 4);
	LobbyMenuT[21] = TextDrawCreate(14.884345, 82.966613, "TEAM");
	TextDrawLetterSize(LobbyMenuT[21], 0.236350, 1.839161);
	TextDrawAlignment(LobbyMenuT[21], 1);
	TextDrawColor(LobbyMenuT[21], -5963521);
	TextDrawSetShadow(LobbyMenuT[21], 1);
	TextDrawSetOutline(LobbyMenuT[21], 0);
	TextDrawBackgroundColor(LobbyMenuT[21], 353703232);
	TextDrawFont(LobbyMenuT[21], 2);
	TextDrawSetProportional(LobbyMenuT[21], 1);

	LobbyMenuT[24] = TextDrawCreate(15.000000, 113.000000, "LD_SPAC:white");
	TextDrawLetterSize(LobbyMenuT[24], 0.000000, 0.000000);
	TextDrawTextSize(LobbyMenuT[24], 85.161056, 1.500000);
	TextDrawAlignment(LobbyMenuT[24], 1);
	TextDrawColor(LobbyMenuT[24], -112);
	TextDrawSetShadow(LobbyMenuT[24], 0);
	TextDrawSetOutline(LobbyMenuT[24], 0);
	TextDrawFont(LobbyMenuT[24], 4);

	LobbyMenuT[25] = TextDrawCreate(13.199134, 101.016624, "v");
	TextDrawLetterSize(LobbyMenuT[25], 0.282265, 0.882493);
	TextDrawTextSize(LobbyMenuT[25], 116.193237, 22.750015);
	TextDrawAlignment(LobbyMenuT[25], 1);
	TextDrawColor(LobbyMenuT[25], -1);
	TextDrawUseBox(LobbyMenuT[25], true);
	TextDrawBoxColor(LobbyMenuT[25], 0);
	TextDrawSetShadow(LobbyMenuT[25], 1);
	TextDrawSetOutline(LobbyMenuT[25], 0);
	TextDrawBackgroundColor(LobbyMenuT[25], 353703232);
	TextDrawFont(LobbyMenuT[25], 2);
	TextDrawSetProportional(LobbyMenuT[25], 1);

	LobbyMenuT[26] = TextDrawCreate(13.262092, 117.183319, "v");
	TextDrawLetterSize(LobbyMenuT[26], 0.282265, 0.882493);
	TextDrawTextSize(LobbyMenuT[26], 116.193237, 22.750015);
	TextDrawAlignment(LobbyMenuT[26], 1);
	TextDrawColor(LobbyMenuT[26], -1);
	TextDrawUseBox(LobbyMenuT[26], true);
	TextDrawBoxColor(LobbyMenuT[26], 0);
	TextDrawSetShadow(LobbyMenuT[26], 1);
	TextDrawSetOutline(LobbyMenuT[26], 0);
	TextDrawBackgroundColor(LobbyMenuT[26], 353703232);
	TextDrawFont(LobbyMenuT[26], 2);
	TextDrawSetProportional(LobbyMenuT[26], 1);

	LobbyMenuT[22] = TextDrawCreate(26.612060, 99.516654, "SOLO");
	TextDrawLetterSize(LobbyMenuT[22], 0.371288, 1.284999);
	TextDrawTextSize(LobbyMenuT[22], 66.998527, 11.083333);
	TextDrawAlignment(LobbyMenuT[22], 1);
	TextDrawColor(LobbyMenuT[22], -1061109505);
	TextDrawUseBox(LobbyMenuT[22], true);
	TextDrawBoxColor(LobbyMenuT[22], 0);
	TextDrawSetShadow(LobbyMenuT[22], 0);
	TextDrawSetOutline(LobbyMenuT[22], 0);
	TextDrawBackgroundColor(LobbyMenuT[22], 51);
	TextDrawFont(LobbyMenuT[22], 2);
	TextDrawSetProportional(LobbyMenuT[22], 1);
	TextDrawSetSelectable(LobbyMenuT[22], true);

	LobbyMenuT[23] = TextDrawCreate(26.658905, 114.858352, "SQUAD");
	TextDrawLetterSize(LobbyMenuT[23], 0.339897, 1.378332);
	TextDrawTextSize(LobbyMenuT[23], 73.557823, 14.583332);
	TextDrawAlignment(LobbyMenuT[23], 1);
	TextDrawColor(LobbyMenuT[23], -1061109505);
	TextDrawUseBox(LobbyMenuT[23], true);
	TextDrawBoxColor(LobbyMenuT[23], 0);
	TextDrawSetShadow(LobbyMenuT[23], 0);
	TextDrawSetOutline(LobbyMenuT[23], 0);
	TextDrawBackgroundColor(LobbyMenuT[23], 51);
	TextDrawFont(LobbyMenuT[23], 2);
	TextDrawSetProportional(LobbyMenuT[23], 1);
	TextDrawSetSelectable(LobbyMenuT[23], true);
	
	LobbyMenuT[27] = TextDrawCreate(86.899078, 429.858184, "hud:radar_gangP");
	TextDrawLetterSize(LobbyMenuT[27], 0.000000, 0.000000);
	TextDrawTextSize(LobbyMenuT[27], 15.000000, 15.000000);
	TextDrawAlignment(LobbyMenuT[27], 1);
	TextDrawColor(LobbyMenuT[27], -16776961);
	TextDrawSetShadow(LobbyMenuT[27], 0);
	TextDrawSetOutline(LobbyMenuT[27], 0);
	TextDrawFont(LobbyMenuT[27], 4);
	TextDrawSetSelectable(LobbyMenuT[27], true);

	LobbyMenuT[28] = TextDrawCreate(178.229888, 429.924865, "hud:radar_gangY");
	TextDrawLetterSize(LobbyMenuT[28], 0.000000, 0.000000);
	TextDrawTextSize(LobbyMenuT[28], 15.000000, 15.000000);
	TextDrawAlignment(LobbyMenuT[28], 1);
	TextDrawColor(LobbyMenuT[28], -1);
	TextDrawSetShadow(LobbyMenuT[28], 0);
	TextDrawSetOutline(LobbyMenuT[28], 0);
	TextDrawFont(LobbyMenuT[28], 4);
	TextDrawSetSelectable(LobbyMenuT[28], true);

	LobbyMenuT[29] = TextDrawCreate(274.276824, 430.099822, "hud:radar_gangG");
	TextDrawLetterSize(LobbyMenuT[29], 0.000000, 0.000000);
	TextDrawTextSize(LobbyMenuT[29], 15.000000, 15.000000);
	TextDrawAlignment(LobbyMenuT[29], 1);
	TextDrawColor(LobbyMenuT[29], -1);
	TextDrawSetShadow(LobbyMenuT[29], 0);
	TextDrawSetOutline(LobbyMenuT[29], 0);
	TextDrawFont(LobbyMenuT[29], 4);
	TextDrawSetSelectable(LobbyMenuT[29], true);

	LobbyMenuT[30] = TextDrawCreate(365.748413, 430.166503, "hud:radar_gangN");
	TextDrawLetterSize(LobbyMenuT[30], 0.000000, 0.000000);
	TextDrawTextSize(LobbyMenuT[30], 15.000000, 15.000000);
	TextDrawAlignment(LobbyMenuT[30], 1);
	TextDrawColor(LobbyMenuT[30], -1);
	TextDrawSetShadow(LobbyMenuT[30], 0);
	TextDrawSetOutline(LobbyMenuT[30], 0);
	TextDrawFont(LobbyMenuT[30], 4);
	TextDrawSetSelectable(LobbyMenuT[30], true);
	RegistrationT[1] = TextDrawCreate(224.702728, 222.308303, "LD_SPAC:white");
	TextDrawLetterSize(RegistrationT[1], 0.000000, 0.000000);
	TextDrawTextSize(RegistrationT[1], 132.170043, 23.625000);
	TextDrawAlignment(RegistrationT[1], 1);
	TextDrawColor(RegistrationT[1], -1061109505);
	TextDrawSetShadow(RegistrationT[1], 0);
	TextDrawSetOutline(RegistrationT[1], 0);
	TextDrawFont(RegistrationT[1], 4);
	TextDrawSetSelectable(RegistrationT[1], true);
	RegistrationT[2] = TextDrawCreate(356.467407, 222.308303, "LD_SPAC:white");
	TextDrawLetterSize(RegistrationT[2], 0.000000, 0.000000);
	TextDrawTextSize(RegistrationT[2], 62.969253, 23.625017);
	TextDrawAlignment(RegistrationT[2], 1);
	TextDrawColor(RegistrationT[2], -5635841);
	TextDrawSetShadow(RegistrationT[2], 0);
	TextDrawSetOutline(RegistrationT[2], 0);
	TextDrawFont(RegistrationT[2], 4);
	TextDrawSetSelectable(RegistrationT[2], true);
	RegistrationT[3] = TextDrawCreate(312.427612, 286.625091, "LD_SPAC:white");
	TextDrawLetterSize(RegistrationT[3], 0.000000, 0.000000);
	TextDrawTextSize(RegistrationT[3], 32.046859, 18.316667);
	TextDrawAlignment(RegistrationT[3], 1);
	TextDrawColor(RegistrationT[3], -1061109505);
	TextDrawSetShadow(RegistrationT[3], 0);
	TextDrawSetOutline(RegistrationT[3], 0);
	TextDrawFont(RegistrationT[3], 4);
	TextDrawSetSelectable(RegistrationT[3], true);
	RegistrationT[4] = TextDrawCreate(329.198974, 286.483306, "OK");
	TextDrawLetterSize(RegistrationT[4], 0.276645, 1.780832);
	TextDrawAlignment(RegistrationT[4], 2);
	TextDrawColor(RegistrationT[4], 255);
	TextDrawSetShadow(RegistrationT[4], 0);
	TextDrawSetOutline(RegistrationT[4], 0);
	TextDrawBackgroundColor(RegistrationT[4], 51);
	TextDrawFont(RegistrationT[4], 2);
	TextDrawSetProportional(RegistrationT[4], 1);
	
	RewMenuT[0] = TextDrawCreate(560.008789, 68.525009, "usebox");
	TextDrawLetterSize(RewMenuT[0], 0.000000, 2.211111);
	TextDrawTextSize(RewMenuT[0], 352.201965, 0.000000);
	TextDrawAlignment(RewMenuT[0], 1);
	TextDrawColor(RewMenuT[0], 0);
	TextDrawUseBox(RewMenuT[0], true);
	TextDrawBoxColor(RewMenuT[0], 128);
	TextDrawSetShadow(RewMenuT[0], 0);
	TextDrawSetOutline(RewMenuT[0], 0);
	TextDrawFont(RewMenuT[0], 0);

	RewMenuT[1] = TextDrawCreate(345.159362, 60.783306, "New Textdraw");
	TextDrawLetterSize(RewMenuT[1], 0.449999, 1.600000);
	TextDrawTextSize(RewMenuT[1], 112.913604, 149.333343);
	TextDrawAlignment(RewMenuT[1], 1);
	TextDrawUseBox(RewMenuT[1], true);
	TextDrawBoxColor(RewMenuT[1], 0);
	TextDrawSetShadow(RewMenuT[1], 0);
	TextDrawSetOutline(RewMenuT[1], 1);
	TextDrawFont(RewMenuT[1], 5);
	TextDrawSetProportional(RewMenuT[1], 1);
	TextDrawBackgroundColor(RewMenuT[1], 0x00000000);
	TextDrawSetPreviewModel(RewMenuT[1], 2969);
	TextDrawSetPreviewRot(RewMenuT[1], -30.000000, 0.000000, 20.000000, 1.000000);

	RewMenuT[2] = TextDrawCreate(460.040954, 72.624992, ".");
	TextDrawLetterSize(RewMenuT[2], 1.292309, 5.709579);
	TextDrawAlignment(RewMenuT[2], 1);
	TextDrawColor(RewMenuT[2], -5963521);
	TextDrawUseBox(RewMenuT[2], true);
	TextDrawBoxColor(RewMenuT[2], 0);
	TextDrawSetShadow(RewMenuT[2], 0);
	TextDrawSetOutline(RewMenuT[2], -1);
	TextDrawBackgroundColor(RewMenuT[2], -5963521);
	TextDrawFont(RewMenuT[2], 1);
	TextDrawSetProportional(RewMenuT[2], 1);

	RewMenuT[3] = TextDrawCreate(461.540496, 103.716690, "p");
	TextDrawLetterSize(RewMenuT[3], 0.338022, 0.888333);
	TextDrawAlignment(RewMenuT[3], 1);
	TextDrawColor(RewMenuT[3], -1);
	TextDrawUseBox(RewMenuT[3], true);
	TextDrawBoxColor(RewMenuT[3], 0);
	TextDrawSetShadow(RewMenuT[3], 0);
	TextDrawSetOutline(RewMenuT[3], 0);
	TextDrawBackgroundColor(RewMenuT[3], 51);
	TextDrawFont(RewMenuT[3], 0);
	TextDrawSetProportional(RewMenuT[3], 1);

	RewMenuT[4] = TextDrawCreate(463.711853, 105.708351, "p");
	TextDrawLetterSize(RewMenuT[4], 0.367538, 1.092499);
	TextDrawAlignment(RewMenuT[4], 1);
	TextDrawColor(RewMenuT[4], -1);
	TextDrawUseBox(RewMenuT[4], true);
	TextDrawBoxColor(RewMenuT[4], 0);
	TextDrawSetShadow(RewMenuT[4], 0);
	TextDrawSetOutline(RewMenuT[4], 0);
	TextDrawBackgroundColor(RewMenuT[4], 51);
	TextDrawFont(RewMenuT[4], 0);
	TextDrawSetProportional(RewMenuT[4], 1);

	RewMenuT[5] = TextDrawCreate(467.101409, 107.233360, "p");
	TextDrawLetterSize(RewMenuT[5], -0.390525, 0.800832);
	TextDrawAlignment(RewMenuT[5], 1);
	TextDrawColor(RewMenuT[5], -1);
	TextDrawUseBox(RewMenuT[5], true);
	TextDrawBoxColor(RewMenuT[5], 0);
	TextDrawSetShadow(RewMenuT[5], 0);
	TextDrawSetOutline(RewMenuT[5], 0);
	TextDrawBackgroundColor(RewMenuT[5], 51);
	TextDrawFont(RewMenuT[5], 0);
	TextDrawSetProportional(RewMenuT[5], 1);

	RewMenuT[6] = TextDrawCreate(457.885772, 149.799987, "LD_SPAC:white");
	TextDrawLetterSize(RewMenuT[6], 0.000000, 0.000000);
	TextDrawTextSize(RewMenuT[6], 72.620803, 19.541673);
	TextDrawAlignment(RewMenuT[6], 1);
	TextDrawColor(RewMenuT[6], -5635841);
	TextDrawSetShadow(RewMenuT[6], 0);
	TextDrawSetOutline(RewMenuT[6], 0);
	TextDrawFont(RewMenuT[6], 4);
	TextDrawSetSelectable(RewMenuT[6], true);

	RewMenuT[7] = TextDrawCreate(174.415802, 247.199905, "usebox");
	TextDrawLetterSize(RewMenuT[7], 0.000000, 0.914812);
	TextDrawTextSize(RewMenuT[7], 54.222549, 0.000000);
	TextDrawAlignment(RewMenuT[7], 1);
	TextDrawColor(RewMenuT[7], 0);
	TextDrawUseBox(RewMenuT[7], true);
	TextDrawBoxColor(RewMenuT[7], 353703423);
	TextDrawSetShadow(RewMenuT[7], 0);
	TextDrawSetOutline(RewMenuT[7], 0);
	TextDrawFont(RewMenuT[7], 0);
	
	KeysFT[0] = TextDrawCreate(371.724822, 257.308258, "O");
	TextDrawLetterSize(KeysFT[0], 0.349361, 2.178082);
	TextDrawAlignment(KeysFT[0], 1);
	TextDrawColor(KeysFT[0], -235);
	TextDrawSetShadow(KeysFT[0], 0);
	TextDrawSetOutline(KeysFT[0], 1);
	TextDrawBackgroundColor(KeysFT[0], -1);
	TextDrawFont(KeysFT[0], 2);
	TextDrawSetProportional(KeysFT[0], 1);

	KeysFT[1] = TextDrawCreate(372.755523, 261.567108, "o");
	TextDrawLetterSize(KeysFT[1], 0.343504, 1.468750);
	TextDrawAlignment(KeysFT[1], 1);
	TextDrawColor(KeysFT[1], 353703423);
	TextDrawSetShadow(KeysFT[1], 0);
	TextDrawSetOutline(KeysFT[1], 1);
	TextDrawBackgroundColor(KeysFT[1], 353703423);
	TextDrawFont(KeysFT[1], 3);
	TextDrawSetProportional(KeysFT[1], 1);

	KeysFT[2] = TextDrawCreate(374.208068, 261.450012, "F");
	TextDrawLetterSize(KeysFT[2], 0.181068, 1.290833);
	TextDrawAlignment(KeysFT[2], 1);
	TextDrawColor(KeysFT[2], -1);
	TextDrawSetShadow(KeysFT[2], 0);
	TextDrawSetOutline(KeysFT[2], 0);
	TextDrawBackgroundColor(KeysFT[2], 51);
	TextDrawFont(KeysFT[2], 2);
	TextDrawSetProportional(KeysFT[2], 1);

	KeysFT[3] = TextDrawCreate(483.264984, 264.933380, "usebox");
	TextDrawLetterSize(KeysFT[3], 0.000000, 0.785179);
	TextDrawTextSize(KeysFT[3], 382.281066, 0.000000);
	TextDrawAlignment(KeysFT[3], 1);
	TextDrawColor(KeysFT[3], 0);
	TextDrawUseBox(KeysFT[3], true);
	TextDrawBoxColor(KeysFT[3], 80);
	TextDrawSetShadow(KeysFT[3], 0);
	TextDrawSetOutline(KeysFT[3], 0);
	TextDrawFont(KeysFT[3], 0);

	KeysFT[4] = TextDrawCreate(417.781372, 265.233428, "usebox");
	TextDrawLetterSize(KeysFT[4], 0.000000, 0.747698);
	TextDrawTextSize(KeysFT[4], 382.702514, 0.000000);
	TextDrawAlignment(KeysFT[4], 1);
	TextDrawColor(KeysFT[4], 0);
	TextDrawUseBox(KeysFT[4], true);
	TextDrawBoxColor(KeysFT[4], 80);
	TextDrawSetShadow(KeysFT[4], 0);
	TextDrawSetOutline(KeysFT[4], 0);
	TextDrawFont(KeysFT[4], 0);
	
	KilledT[0] = TextDrawCreate(746.948852, -81.333335, "usebox");
	TextDrawLetterSize(KilledT[0], 0.000000, 65.981948);
	TextDrawTextSize(KilledT[0], -150.521224, 0.000000);
	TextDrawAlignment(KilledT[0], 1);
	TextDrawColor(KilledT[0], 0);
	TextDrawUseBox(KilledT[0], true);
	TextDrawBoxColor(KilledT[0], 102);
	TextDrawSetShadow(KilledT[0], 0);
	TextDrawSetOutline(KilledT[0], 0);
	TextDrawFont(KilledT[0], 0);

	KilledT[1] = TextDrawCreate(44.181571, 227.324966, "RANK");
	TextDrawLetterSize(KilledT[1], 0.295854, 1.471665);
	TextDrawAlignment(KilledT[1], 1);
	TextDrawColor(KilledT[1], -2139062017);
	TextDrawSetShadow(KilledT[1], 0);
	TextDrawSetOutline(KilledT[1], 0);
	TextDrawBackgroundColor(KilledT[1], 51);
	TextDrawFont(KilledT[1], 2);
	TextDrawSetProportional(KilledT[1], 1);

	KilledT[2] = TextDrawCreate(139.541793, 227.274963, "KILL");
	TextDrawLetterSize(KilledT[2], 0.295854, 1.471665);
	TextDrawAlignment(KilledT[2], 1);
	TextDrawColor(KilledT[2], -2139062017);
	TextDrawSetShadow(KilledT[2], 0);
	TextDrawSetOutline(KilledT[2], 0);
	TextDrawBackgroundColor(KilledT[2], 51);
	TextDrawFont(KilledT[2], 2);
	TextDrawSetProportional(KilledT[2], 1);

	KilledT[3] = TextDrawCreate(239.774795, 227.283401, "REWARD");
	TextDrawLetterSize(KilledT[3], 0.295854, 1.471665);
	TextDrawAlignment(KilledT[3], 1);
	TextDrawColor(KilledT[3], -2139062017);
	TextDrawSetShadow(KilledT[3], 0);
	TextDrawSetOutline(KilledT[3], 0);
	TextDrawBackgroundColor(KilledT[3], 51);
	TextDrawFont(KilledT[3], 2);
	TextDrawSetProportional(KilledT[3], 1);

	KilledT[4] = TextDrawCreate(182.521514, 232.416732, "PLAYERS");
	TextDrawLetterSize(KilledT[4], 0.181536, 0.800831);
	TextDrawAlignment(KilledT[4], 1);
	TextDrawColor(KilledT[4], -2139062017);
	TextDrawSetShadow(KilledT[4], 0);
	TextDrawSetOutline(KilledT[4], 0);
	TextDrawBackgroundColor(KilledT[4], 51);
	TextDrawFont(KilledT[4], 2);
	TextDrawSetProportional(KilledT[4], 1);

	KilledT[5] = TextDrawCreate(118.989753, 243.758422, "usebox");
	TextDrawLetterSize(KilledT[5], 0.000000, -0.297143);
	TextDrawTextSize(KilledT[5], 42.322105, 0.000000);
	TextDrawAlignment(KilledT[5], 1);
	TextDrawColor(KilledT[5], -224);
	TextDrawUseBox(KilledT[5], true);
	TextDrawBoxColor(KilledT[5], -224);
	TextDrawSetShadow(KilledT[5], 0);
	TextDrawSetOutline(KilledT[5], 0);
	TextDrawFont(KilledT[5], 0);

	KilledT[6] = TextDrawCreate(216.270996, 243.416732, "usebox");
	TextDrawLetterSize(KilledT[6], 0.000000, -0.297143);
	TextDrawTextSize(KilledT[6], 138.603317, 0.000000);
	TextDrawAlignment(KilledT[6], 1);
	TextDrawColor(KilledT[6], -224);
	TextDrawUseBox(KilledT[6], true);
	TextDrawBoxColor(KilledT[6], -224);
	TextDrawSetShadow(KilledT[6], 0);
	TextDrawSetOutline(KilledT[6], 0);
	TextDrawFont(KilledT[6], 0);

	KilledT[7] = TextDrawCreate(321.376647, 243.366714, "usebox");
	TextDrawLetterSize(KilledT[7], 0.000000, -0.297143);
	TextDrawTextSize(KilledT[7], 237.836242, 0.000000);
	TextDrawAlignment(KilledT[7], 1);
	TextDrawColor(KilledT[7], -224);
	TextDrawUseBox(KilledT[7], true);
	TextDrawBoxColor(KilledT[7], -224);
	TextDrawSetShadow(KilledT[7], 0);
	TextDrawSetOutline(KilledT[7], 0);
	TextDrawFont(KilledT[7], 0);

	KilledT[8] = TextDrawCreate(509.985626, 371.116790, "LD_SPAC:white");
	TextDrawLetterSize(KilledT[8], 0.000000, 0.000000);
	TextDrawTextSize(KilledT[8], 89.487548, 23.333311);
	TextDrawAlignment(KilledT[8], 1);
	TextDrawColor(KilledT[8], -2139062017);
	TextDrawSetShadow(KilledT[8], 0);
	TextDrawSetOutline(KilledT[8], 0);
	TextDrawFont(KilledT[8], 4);
	TextDrawSetSelectable(KilledT[8], true);
	KilledT[9] = TextDrawCreate(409.985626, 371.116790, "LD_SPAC:white");
	TextDrawLetterSize(KilledT[9], 0.000000, 0.000000);
	TextDrawTextSize(KilledT[9], 89.487548, 23.333311);
	TextDrawAlignment(KilledT[9], 1);
	TextDrawColor(KilledT[9], -2139062017);
	TextDrawSetShadow(KilledT[9], 0);
	TextDrawSetOutline(KilledT[9], 0);
	TextDrawFont(KilledT[9], 4);
	TextDrawSetSelectable(KilledT[9], true);
	
	NWSET[0] = TextDrawCreate(229.387527, 15.0, "l");
	TextDrawLetterSize(NWSET[0], 0.246287, 1.600000);
	TextDrawAlignment(NWSET[0], 1);
	TextDrawColor(NWSET[0], -86);
	TextDrawUseBox(NWSET[0], true);
	TextDrawBoxColor(NWSET[0], 0);
	TextDrawSetShadow(NWSET[0], 0);
	TextDrawSetOutline(NWSET[0], 0);
	TextDrawBackgroundColor(NWSET[0], 51);
	TextDrawFont(NWSET[0], 1);
	TextDrawSetProportional(NWSET[0], 1);

	NWSET[1] = TextDrawCreate(272.601470, 15.0, "l");
	TextDrawLetterSize(NWSET[1], 0.246287, 1.600000);
	TextDrawAlignment(NWSET[1], 1);
	TextDrawColor(NWSET[1], -86);
	TextDrawUseBox(NWSET[1], true);
	TextDrawBoxColor(NWSET[1], 0);
	TextDrawSetShadow(NWSET[1], 0);
	TextDrawSetOutline(NWSET[1], 0);
	TextDrawBackgroundColor(NWSET[1], 51);
	TextDrawFont(NWSET[1], 1);
	TextDrawSetProportional(NWSET[1], 1);

	NWSET[2] = TextDrawCreate(315.065643, 15.0, "l");
	TextDrawLetterSize(NWSET[2], 0.246287, 1.600000);
	TextDrawAlignment(NWSET[2], 1);
	TextDrawColor(NWSET[2], -86);
	TextDrawUseBox(NWSET[2], true);
	TextDrawBoxColor(NWSET[2], 0);
	TextDrawSetShadow(NWSET[2], 0);
	TextDrawSetOutline(NWSET[2], 0);
	TextDrawBackgroundColor(NWSET[2], 51);
	TextDrawFont(NWSET[2], 1);
	TextDrawSetProportional(NWSET[2], 1);

	NWSET[3] = TextDrawCreate(359.638305, 15.0, "l");
	TextDrawLetterSize(NWSET[3], 0.246287, 1.600000);
	TextDrawAlignment(NWSET[3], 1);
	TextDrawColor(NWSET[3], -86);
	TextDrawUseBox(NWSET[3], true);
	TextDrawBoxColor(NWSET[3], 0);
	TextDrawSetShadow(NWSET[3], 0);
	TextDrawSetOutline(NWSET[3], 0);
	TextDrawBackgroundColor(NWSET[3], 51);
	TextDrawFont(NWSET[3], 1);
	TextDrawSetProportional(NWSET[3], 1);

	NWSET[4] = TextDrawCreate(402.337158, 15.0, "l");
	TextDrawLetterSize(NWSET[4], 0.246287, 1.600000);
	TextDrawAlignment(NWSET[4], 1);
	TextDrawColor(NWSET[4], -86);
	TextDrawUseBox(NWSET[4], true);
	TextDrawBoxColor(NWSET[4], 0);
	TextDrawSetShadow(NWSET[4], 0);
	TextDrawSetOutline(NWSET[4], 0);
	TextDrawBackgroundColor(NWSET[4], 51);
	TextDrawFont(NWSET[4], 1);
	TextDrawSetProportional(NWSET[4], 1);

	NWSET[5] = TextDrawCreate(244.461608, 16.0, "l");
	TextDrawLetterSize(NWSET[5], 0.246287, 1.354999);
	TextDrawAlignment(NWSET[5], 1);
	TextDrawColor(NWSET[5], 1886417066);
	TextDrawUseBox(NWSET[5], true);
	TextDrawBoxColor(NWSET[5], 0);
	TextDrawSetShadow(NWSET[5], 0);
	TextDrawSetOutline(NWSET[5], 0);
	TextDrawBackgroundColor(NWSET[5], 51);
	TextDrawFont(NWSET[5], 1);
	TextDrawSetProportional(NWSET[5], 1);

	NWSET[6] = TextDrawCreate(258.111724, 16.0, "l");
	TextDrawLetterSize(NWSET[6], 0.246287, 1.354999);
	TextDrawAlignment(NWSET[6], 1);
	TextDrawColor(NWSET[6], 1886417066);
	TextDrawUseBox(NWSET[6], true);
	TextDrawBoxColor(NWSET[6], 0);
	TextDrawSetShadow(NWSET[6], 0);
	TextDrawSetOutline(NWSET[6], 0);
	TextDrawBackgroundColor(NWSET[6], 51);
	TextDrawFont(NWSET[6], 1);
	TextDrawSetProportional(NWSET[6], 1);

	NWSET[7] = TextDrawCreate(287.223449, 16.0, "l");
	TextDrawLetterSize(NWSET[7], 0.246287, 1.354999);
	TextDrawAlignment(NWSET[7], 1);
	TextDrawColor(NWSET[7], 1886417066);
	TextDrawUseBox(NWSET[7], true);
	TextDrawBoxColor(NWSET[7], 0);
	TextDrawSetShadow(NWSET[7], 0);
	TextDrawSetOutline(NWSET[7], 0);
	TextDrawBackgroundColor(NWSET[7], 51);
	TextDrawFont(NWSET[7], 1);
	TextDrawSetProportional(NWSET[7], 1);

	NWSET[8] = TextDrawCreate(312.316375, -0.933286, "v");
	TextDrawLetterSize(NWSET[8], 0.391153, 1.497333);
	TextDrawAlignment(NWSET[8], 1);
	TextDrawColor(NWSET[8], -1);
	TextDrawSetShadow(NWSET[8], 0);
	TextDrawSetOutline(NWSET[8], 1);
	TextDrawBackgroundColor(NWSET[8], -1);
	TextDrawFont(NWSET[8], 1);
	TextDrawSetProportional(NWSET[8], 1);

	NWSET[9] = TextDrawCreate(300.405151, 16.0, "l");
	TextDrawLetterSize(NWSET[9], 0.246287, 1.354999);
	TextDrawAlignment(NWSET[9], 1);
	TextDrawColor(NWSET[9], 1886417066);
	TextDrawUseBox(NWSET[9], true);
	TextDrawBoxColor(NWSET[9], 0);
	TextDrawSetShadow(NWSET[9], 0);
	TextDrawSetOutline(NWSET[9], 0);
	TextDrawBackgroundColor(NWSET[9], 51);
	TextDrawFont(NWSET[9], 1);
	TextDrawSetProportional(NWSET[9], 1);

	NWSET[10] = TextDrawCreate(329.704071, 16.0, "l");
	TextDrawLetterSize(NWSET[10], 0.246287, 1.354998);
	TextDrawAlignment(NWSET[10], 1);
	TextDrawColor(NWSET[10], 1886417066);
	TextDrawUseBox(NWSET[10], true);
	TextDrawBoxColor(NWSET[10], 0);
	TextDrawSetShadow(NWSET[10], 0);
	TextDrawSetOutline(NWSET[10], 0);
	TextDrawBackgroundColor(NWSET[10], 51);
	TextDrawFont(NWSET[10], 1);
	TextDrawSetProportional(NWSET[10], 1);

	NWSET[11] = TextDrawCreate(344.385070, 16.0, "l");
	TextDrawLetterSize(NWSET[11], 0.246287, 1.354998);
	TextDrawAlignment(NWSET[11], 1);
	TextDrawColor(NWSET[11], 1886417066);
	TextDrawUseBox(NWSET[11], true);
	TextDrawBoxColor(NWSET[11], 0);
	TextDrawSetShadow(NWSET[11], 0);
	TextDrawSetOutline(NWSET[11], 0);
	TextDrawBackgroundColor(NWSET[11], 51);
	TextDrawFont(NWSET[11], 1);
	TextDrawSetProportional(NWSET[11], 1);

	NWSET[12] = TextDrawCreate(374.433624, 16.0, "l");
	TextDrawLetterSize(NWSET[12], 0.246287, 1.354998);
	TextDrawAlignment(NWSET[12], 1);
	TextDrawColor(NWSET[12], 1886417066);
	TextDrawUseBox(NWSET[12], true);
	TextDrawBoxColor(NWSET[12], 0);
	TextDrawSetShadow(NWSET[12], 0);
	TextDrawSetOutline(NWSET[12], 0);
	TextDrawBackgroundColor(NWSET[12], 51);
	TextDrawFont(NWSET[12], 1);
	TextDrawSetProportional(NWSET[12], 1);

	NWSET[13] = TextDrawCreate(388.599121, 16.0, "l");
	TextDrawLetterSize(NWSET[13], 0.246287, 1.354998);
	TextDrawAlignment(NWSET[13], 1);
	TextDrawColor(NWSET[13], 1886417066);
	TextDrawUseBox(NWSET[13], true);
	TextDrawBoxColor(NWSET[13], 0);
	TextDrawSetShadow(NWSET[13], 0);
	TextDrawSetOutline(NWSET[13], 0);
	TextDrawBackgroundColor(NWSET[13], 51);
	TextDrawFont(NWSET[13], 1);
	TextDrawSetProportional(NWSET[13], 1);

	BannedT[0] = TextDrawCreate(194.389465, 131.016647, "I");
	TextDrawLetterSize(BannedT[0], 37.393829, 3.734997);
	TextDrawAlignment(BannedT[0], 1);
	TextDrawColor(BannedT[0], -1061109505);
	TextDrawSetShadow(BannedT[0], 0);
	TextDrawSetOutline(BannedT[0], 1);
	TextDrawBackgroundColor(BannedT[0], 51);
	TextDrawFont(BannedT[0], 1);
	TextDrawSetProportional(BannedT[0], 1);

	BannedT[1] = TextDrawCreate(316.439300, 136.499969, "ANTI CHEAT SAMP EDITION");
	TextDrawLetterSize(BannedT[1], 0.350486, 2.381664);
	TextDrawAlignment(BannedT[1], 2);
	TextDrawColor(BannedT[1], 353703423);
	TextDrawSetShadow(BannedT[1], 0);
	TextDrawSetOutline(BannedT[1], 0);
	TextDrawBackgroundColor(BannedT[1], 51);
	TextDrawFont(BannedT[1], 2);
	TextDrawSetProportional(BannedT[1], 1);

	BannedT[2] = TextDrawCreate(296.105285, 149.916671, "I");
	TextDrawLetterSize(BannedT[2], 7.517172, 4.645000);
	TextDrawAlignment(BannedT[2], 1);
	TextDrawColor(BannedT[2], 353703423);
	TextDrawSetShadow(BannedT[2], 0);
	TextDrawSetOutline(BannedT[2], 1);
	TextDrawBackgroundColor(BannedT[2], 51);
	TextDrawFont(BannedT[2], 1);
	TextDrawSetProportional(BannedT[2], 1);

	BannedT[3] = TextDrawCreate(304.304840, 159.775054, "#");
	TextDrawLetterSize(BannedT[3], 0.519809, 2.533333);
	TextDrawAlignment(BannedT[3], 1);
	TextDrawColor(BannedT[3], -1061109505);
	TextDrawUseBox(BannedT[3], true);
	TextDrawBoxColor(BannedT[3], 0);
	TextDrawSetShadow(BannedT[3], 0);
	TextDrawSetOutline(BannedT[3], 0);
	TextDrawBackgroundColor(BannedT[3], 51);
	TextDrawFont(BannedT[3], 1);
	TextDrawSetProportional(BannedT[3], 1);

	BannedT[4] = TextDrawCreate(629.224487, 426.416687, "/q to exit the game");
	TextDrawLetterSize(BannedT[4], 0.318813, 1.063333);
	TextDrawAlignment(BannedT[4], 3);
	TextDrawColor(BannedT[4], -1061109505);
	TextDrawUseBox(BannedT[4], true);
	TextDrawBoxColor(BannedT[4], 0);
	TextDrawSetShadow(BannedT[4], 0);
	TextDrawSetOutline(BannedT[4], 1);
	TextDrawBackgroundColor(BannedT[4], 353703423);
	TextDrawFont(BannedT[4], 2);
	TextDrawSetProportional(BannedT[4], 1);

	TeamMatesT[0] = TextDrawCreate(3.000000, 270.000000, "LD_SPAC:white");
	TextDrawLetterSize(TeamMatesT[0], 0.000000, 0.000000);
	TextDrawTextSize(TeamMatesT[0], 50.000000, 8.000000);
	TextDrawAlignment(TeamMatesT[0], 1);
	TextDrawColor(TeamMatesT[0], 0x51515140);
	TextDrawSetShadow(TeamMatesT[0], 0);
	TextDrawSetOutline(TeamMatesT[0], 0);
	TextDrawFont(TeamMatesT[0], 4);

	TeamMatesT[1] = TextDrawCreate(3.000000, 290.000000, "LD_SPAC:white");
	TextDrawLetterSize(TeamMatesT[1], 0.000000, 0.000000);
	TextDrawTextSize(TeamMatesT[1], 50.000000, 8.000000);
	TextDrawAlignment(TeamMatesT[1], 1);
	TextDrawColor(TeamMatesT[1], 0x51515140);
	TextDrawSetShadow(TeamMatesT[1], 0);
	TextDrawSetOutline(TeamMatesT[1], 0);
	TextDrawFont(TeamMatesT[1], 4);

	TeamMatesT[2] = TextDrawCreate(3.000000, 310.000000, "LD_SPAC:white");
	TextDrawLetterSize(TeamMatesT[2], 0.000000, 0.000000);
	TextDrawTextSize(TeamMatesT[2], 50.000000, 8.000000);
	TextDrawAlignment(TeamMatesT[2], 1);
	TextDrawColor(TeamMatesT[2], 0x51515140);
	TextDrawSetShadow(TeamMatesT[2], 0);
	TextDrawSetOutline(TeamMatesT[2], 0);
	TextDrawFont(TeamMatesT[2], 4);

	TeamMatesT[3] = TextDrawCreate(3.000000, 270.000000, "hud:radar_LocoSyndicate");
	TextDrawLetterSize(TeamMatesT[3], 0.000000, 0.000000);
	TextDrawTextSize(TeamMatesT[3], 10.000000, 10.000000);
	TextDrawAlignment(TeamMatesT[3], 1);
	TextDrawColor(TeamMatesT[3], -2139062017);
	TextDrawSetShadow(TeamMatesT[3], 0);
	TextDrawSetOutline(TeamMatesT[3], 0);
	TextDrawFont(TeamMatesT[3], 4);

	TeamMatesT[4] = TextDrawCreate(3.000000, 290.000000, "hud:radar_LocoSyndicate");
	TextDrawLetterSize(TeamMatesT[4], 0.000000, 0.000000);
	TextDrawTextSize(TeamMatesT[4], 10.000000, 10.000000);
	TextDrawAlignment(TeamMatesT[4], 1);
	TextDrawColor(TeamMatesT[4], -2139062017);
	TextDrawSetShadow(TeamMatesT[4], 0);
	TextDrawSetOutline(TeamMatesT[4], 0);
	TextDrawFont(TeamMatesT[4], 4);

	TeamMatesT[5] = TextDrawCreate(3.000000, 310.000000, "hud:radar_LocoSyndicate");
	TextDrawLetterSize(TeamMatesT[5], 0.000000, 0.000000);
	TextDrawTextSize(TeamMatesT[5], 10.000000, 10.000000);
	TextDrawAlignment(TeamMatesT[5], 1);
	TextDrawColor(TeamMatesT[5], -2139062017);
	TextDrawSetShadow(TeamMatesT[5], 0);
	TextDrawSetOutline(TeamMatesT[5], 0);
	TextDrawFont(TeamMatesT[5], 4);
	
	TeammateSearchT[0] = TextDrawCreate(539.268371, 208.0, "_");
	TeammateSearchT[1] = TextDrawCreate(539.268371, 223.0, "_");
	TeammateSearchT[2] = TextDrawCreate(539.268371, 238.0, "_");
	TeammateSearchT[3] = TextDrawCreate(539.268371, 253.0, "_");
	TeammateSearchT[4] = TextDrawCreate(539.268371, 268.0, "_");
	TeammateSearchT[5] = TextDrawCreate(539.268371, 283.0, "_");
	TeammateSearchT[6] = TextDrawCreate(539.268371, 298.0, "_");
	TeammateSearchT[7] = TextDrawCreate(539.268371, 313.0, "_");
	TeammateSearchT[8] = TextDrawCreate(539.268371, 328.0, "_");
	TeammateSearchT[9] = TextDrawCreate(539.268371, 343.0, "_");
	for(new td=0;td<10;td++) {
		//TextDrawSetString(TeammateSearchT[td],"Player_Nick(id)");
		TextDrawLetterSize(TeammateSearchT[td], 0.369881, 1.290832);
		TextDrawTextSize(TeammateSearchT[td], 618.448425, 13.416666);
		TextDrawAlignment(TeammateSearchT[td], 1);
		TextDrawColor(TeammateSearchT[td], -1061109505);
		TextDrawUseBox(TeammateSearchT[td], true);
		TextDrawBoxColor(TeammateSearchT[td], 0);
		TextDrawSetShadow(TeammateSearchT[td], 1);
		TextDrawSetOutline(TeammateSearchT[td], 0);
		TextDrawBackgroundColor(TeammateSearchT[td], 353703423);
		TextDrawFont(TeammateSearchT[td], 1);
		TextDrawSetProportional(TeammateSearchT[td], 1);
		TextDrawSetSelectable(TeammateSearchT[td], true);
	}

	TeammateSearchT[10] = TextDrawCreate(18.00879, 394.416656, "LD_OTB2:Ric5");
	TextDrawLetterSize(TeammateSearchT[10], 0.000000, 0.000000);
	TextDrawTextSize(TeammateSearchT[10], 59.267967, 60.199985);
	TextDrawAlignment(TeammateSearchT[10], 1);
	TextDrawColor(TeammateSearchT[10], 255);
	TextDrawSetShadow(TeammateSearchT[10], 0);
	TextDrawSetOutline(TeammateSearchT[10], 0);
	TextDrawFont(TeammateSearchT[10], 4);
	TextDrawSetSelectable(TeammateSearchT[10], true);

	TeammateSearchT[11] = TextDrawCreate(40.02954, 419.850189, "o");
	TextDrawLetterSize(TeammateSearchT[11], 0.413923, 1.570833);
	TextDrawAlignment(TeammateSearchT[11], 1);
	TextDrawColor(TeammateSearchT[11], -1061109505);
	TextDrawUseBox(TeammateSearchT[11], true);
	TextDrawBoxColor(TeammateSearchT[11], 0);
	TextDrawSetShadow(TeammateSearchT[11], 0);
	TextDrawSetOutline(TeammateSearchT[11], 0);
	TextDrawBackgroundColor(TeammateSearchT[11], 51);
	TextDrawFont(TeammateSearchT[11], 2);
	TextDrawSetProportional(TeammateSearchT[11], 1);

	TeammateSearchT[12] = TextDrawCreate(45.41718, 428.250061, "\\");
	TextDrawLetterSize(TeammateSearchT[12], 0.762503, 1.069167);
	TextDrawAlignment(TeammateSearchT[12], 1);
	TextDrawColor(TeammateSearchT[12], -1061109505);
	TextDrawSetShadow(TeammateSearchT[12], 0);
	TextDrawSetOutline(TeammateSearchT[12], 0);
	TextDrawBackgroundColor(TeammateSearchT[12], 51);
	TextDrawFont(TeammateSearchT[12], 1);
	TextDrawSetProportional(TeammateSearchT[12], 1);
	
	HUDT[0] = TextDrawCreate(382.002349, 420.058166, "usebox");
	TextDrawLetterSize(HUDT[0], 0.000000, 1.050705);
	TextDrawTextSize(HUDT[0], 252.708938, 0.000000);
	TextDrawAlignment(HUDT[0], 1);
	TextDrawColor(HUDT[0], 0);
	TextDrawUseBox(HUDT[0], true);
	TextDrawBoxColor(HUDT[0], 102);
	TextDrawSetShadow(HUDT[0], 0);
	TextDrawSetOutline(HUDT[0], 0);
	TextDrawFont(HUDT[0], 0);

	HUDT[1] = TextDrawCreate(275.0, 412.125061, "v");
	TextDrawLetterSize(HUDT[1], 0.300000, 0.300000);
	TextDrawAlignment(HUDT[1], 1);
	TextDrawColor(HUDT[1], -862387969);
	TextDrawUseBox(HUDT[1], true);
	TextDrawBoxColor(HUDT[1], 0);
	TextDrawSetShadow(HUDT[1], 0);
	TextDrawSetOutline(HUDT[1], 0);
	TextDrawBackgroundColor(HUDT[1], -5963521);
	TextDrawFont(HUDT[1], 3);
	TextDrawSetProportional(HUDT[1], 1);

	HUDT[2] = TextDrawCreate(282.0, 415.166595, "v");
	TextDrawLetterSize(HUDT[2], 0.300000, -0.300000);
	TextDrawAlignment(HUDT[2], 1);
	TextDrawColor(HUDT[2], -1283063553);
	TextDrawUseBox(HUDT[2], true);
	TextDrawBoxColor(HUDT[2], 0);
	TextDrawSetShadow(HUDT[2], 0);
	TextDrawSetOutline(HUDT[2], 0);
	TextDrawBackgroundColor(HUDT[2], -5963521);
	TextDrawFont(HUDT[2], 3);
	TextDrawSetProportional(HUDT[2], 1);

	HUDT[3] = TextDrawCreate(356.0, 388.750244, "New Textdraw");
	TextDrawLetterSize(HUDT[3], 0.449999, 1.600000);
	TextDrawTextSize(HUDT[3], 30.000000, 30.000000);
	TextDrawAlignment(HUDT[3], 1);
	TextDrawColor(HUDT[3], 353703423);
	TextDrawUseBox(HUDT[3], true);
	TextDrawBoxColor(HUDT[3], 0x00000000);
	TextDrawSetShadow(HUDT[3], 0);
	TextDrawSetOutline(HUDT[3], 0);
	TextDrawBackgroundColor(HUDT[3], -256);
	TextDrawFont(HUDT[3], 5);
	TextDrawSetProportional(HUDT[3], 1);
	TextDrawSetPreviewModel(HUDT[3], 19515);
	TextDrawSetPreviewRot(HUDT[3], 0.000000, -90.000000, 0.000000, 1.000000);

	HUDT[4] = TextDrawCreate(329.0, 383.683990, "New Textdraw");
	TextDrawLetterSize(HUDT[4], 0.449999, 1.600000);
	TextDrawTextSize(HUDT[4], 45.000000, 50.000000);
	TextDrawAlignment(HUDT[4], 1);
	TextDrawColor(HUDT[4], 353703423);
	TextDrawUseBox(HUDT[4], true);
	TextDrawBoxColor(HUDT[4], 0x00000000);
	TextDrawSetShadow(HUDT[4], 0);
	TextDrawSetOutline(HUDT[4], 0);
	TextDrawBackgroundColor(HUDT[4], -256);
	TextDrawFont(HUDT[4], 5);
	TextDrawSetProportional(HUDT[4], 1);
	TextDrawSetPreviewModel(HUDT[4], 19109);
	TextDrawSetPreviewRot(HUDT[4], 0.000000, -90.000000, 0.000000, 1.000000);
	
	new tmpobjid;
	tmpobjid = CreateObject(9931,2039.987,1244.722,731.751,0.000,0.000,0.000,233.000);
	SetObjectMaterial(tmpobjid, 0, 5710, "cemetery_law", "mauswall03_law", 0x00000000);
	SetObjectMaterial(tmpobjid, 1, 6867, "vgnpwrmainbld", "sw_wallbrick_02", 0x00000000);
	SetObjectMaterial(tmpobjid, 2, 6867, "vgnpwrmainbld", "sw_wallbrick_02", 0x00000000);
	SetObjectMaterial(tmpobjid, 3, 18773, "tunnelsections", "stonewall4", 0x00000000);
	SetObjectMaterial(tmpobjid, 4, 6867, "vgnpwrmainbld", "sw_wallbrick_02", 0x00000000);
	SetObjectMaterial(tmpobjid, 5, 6867, "vgnpwrmainbld", "sw_wallbrick_02", 0x00000000);
	SetObjectMaterial(tmpobjid, 6, 6867, "vgnpwrmainbld", "sw_wallbrick_02", 0x00000000);
	SetObjectMaterial(tmpobjid, 7, 18773, "tunnelsections", "stonewall4", 0x00000000);
	tmpobjid = CreateObject(19458,2068.222,1253.387,715.098,0.000,90.000,0.000,233.000);
	SetObjectMaterial(tmpobjid, 0, 14815, "whore_main", "WH_tiles2", 0x00000000);
	tmpobjid = CreateObject(3980,2078.212,1211.899,716.933,0.000,0.000,358.000,233.000);
	SetObjectMaterial(tmpobjid, 0, 6867, "vgnpwrmainbld", "sw_wallbrick_02", 0x00000000);
	SetObjectMaterial(tmpobjid, 1, 9575, "archbrij", "conc_wall_stripd2128h", 0x00000000);
	SetObjectMaterial(tmpobjid, 2, 14407, "carter_block", "ab_stripped_floor2", 0x00000000);
	SetObjectMaterial(tmpobjid, 3, 6867, "vgnpwrmainbld", "sw_wallbrick_02", 0x00000000);
	SetObjectMaterial(tmpobjid, 4, 6867, "vgnpwrmainbld", "sw_wallbrick_02", 0x00000000);
	SetObjectMaterial(tmpobjid, 5, 9514, "711_sfw", "brick", 0x00000000);
	SetObjectMaterial(tmpobjid, 6, 9514, "711_sfw", "brick", 0x00000000);
	tmpobjid = CreateObject(14409,2065.669,1249.221,713.404,0.000,0.000,270.000,233.000);
	SetObjectMaterial(tmpobjid, 0, 4004, "civic07_lan", "sl_rotnbrik", 0x00000000);
	SetObjectMaterial(tmpobjid, 1, 4004, "civic07_lan", "sl_rotnbrik", 0x00000000);
	tmpobjid = CreateObject(19458,2068.222,1243.757,715.098,0.000,90.000,0.000,233.000);
	SetObjectMaterial(tmpobjid, 0, 14815, "whore_main", "WH_tiles2", 0x00000000);
	tmpobjid = CreateObject(19458,2071.723,1243.757,715.098,0.000,90.000,0.000,233.000);
	SetObjectMaterial(tmpobjid, 0, 14815, "whore_main", "WH_tiles2", 0x00000000);
	tmpobjid = CreateObject(19458,2071.723,1253.387,715.098,0.000,90.000,0.000,233.000);
	SetObjectMaterial(tmpobjid, 0, 14815, "whore_main", "WH_tiles2", 0x00000000);
	tmpobjid = CreateObject(19458,2075.203,1253.387,715.098,0.000,90.000,0.000,233.000);
	SetObjectMaterial(tmpobjid, 0, 14815, "whore_main", "WH_tiles2", 0x00000000);
	tmpobjid = CreateObject(19458,2075.213,1243.757,715.098,0.000,90.000,0.000,233.000);
	SetObjectMaterial(tmpobjid, 0, 14815, "whore_main", "WH_tiles2", 0x00000000);
	tmpobjid = CreateObject(19458,2078.703,1253.387,715.098,0.000,90.000,0.000,233.000);
	SetObjectMaterial(tmpobjid, 0, 14815, "whore_main", "WH_tiles2", 0x00000000);
	tmpobjid = CreateObject(19458,2078.703,1243.757,715.098,0.000,90.000,0.000,233.000);
	SetObjectMaterial(tmpobjid, 0, 14815, "whore_main", "WH_tiles2", 0x00000000);
	tmpobjid = CreateObject(19458,2082.202,1243.757,715.098,0.000,90.000,0.000,233.000);
	SetObjectMaterial(tmpobjid, 0, 14407, "carter_block", "ab_stripped_floor2", 0x00000000);
	tmpobjid = CreateObject(19458,2082.202,1253.387,715.098,0.000,90.000,0.000,233.000);
	SetObjectMaterial(tmpobjid, 0, 14407, "carter_block", "ab_stripped_floor2", 0x00000000);
	tmpobjid = CreateObject(19458,2071.723,1243.757,720.417,0.000,180.000,90.000,233.000);
	SetObjectMaterial(tmpobjid, 0, 6867, "vgnpwrmainbld", "sw_wallbrick_02", 0x00000000);
	tmpobjid = CreateObject(19458,2071.723,1243.757,723.907,0.000,180.000,90.000,233.000);
	SetObjectMaterial(tmpobjid, 0, 6867, "vgnpwrmainbld", "sw_wallbrick_02", 0x00000000);
	tmpobjid = CreateObject(19458,2078.832,1243.767,716.908,0.000,180.000,90.000,233.000);
	SetObjectMaterial(tmpobjid, 0, 6867, "vgnpwrmainbld", "sw_wallbrick_02", 0x00000000);
	tmpobjid = CreateObject(19458,2081.354,1243.757,720.417,0.000,180.000,90.000,233.000);
	SetObjectMaterial(tmpobjid, 0, 6867, "vgnpwrmainbld", "sw_wallbrick_02", 0x00000000);
	tmpobjid = CreateObject(19458,2081.344,1243.757,723.907,0.000,180.000,90.000,233.000);
	SetObjectMaterial(tmpobjid, 0, 6867, "vgnpwrmainbld", "sw_wallbrick_02", 0x00000000);
	tmpobjid = CreateObject(2969,2076.254,1249.354,715.411,-90.900,46.100,0.000,233.000);
	SetObjectMaterial(tmpobjid, 0, 16640, "a51", "sw_olddrum1", 0x00000000);
	tmpobjid = CreateObject(854,2077.030,1249.782,715.314,0.000,0.000,0.000,233.000);
	SetObjectMaterial(tmpobjid, 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
	tmpobjid = CreateObject(854,2075.830,1250.232,715.314,0.000,0.000,0.000,233.000);
	SetObjectMaterial(tmpobjid, 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
	tmpobjid = CreateObject(1650,2075.969,1249.928,715.670,9.199,8.699,-59.000,233.000);
	SetObjectMaterial(tmpobjid, 0, 5408, "tempstuff_lae", "sl_metalbndrust1", 0x00000000);
	tmpobjid = CreateObject(854,2077.578,1245.929,715.374,0.000,0.000,-48.299,233.000);
	SetObjectMaterial(tmpobjid, 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
	tmpobjid = CreateObject(3013,2076.677,1246.604,715.283,0.000,0.000,-21.399,233.000);
	SetObjectMaterial(tmpobjid, 0, 13659, "8bars", "barrier", 0x00000000);
	tmpobjid = CreateObject(854,2072.483,1244.418,715.214,0.000,0.000,-48.299,233.000);
	SetObjectMaterial(tmpobjid, 0, 9514, "711_sfw", "ws_carpark2", 0x00000000);
	tmpobjid = CreateObject(19458,2064.731,1253.387,715.098,0.000,90.000,0.000,233.000);
	SetObjectMaterial(tmpobjid, 0, 14815, "whore_main", "WH_tiles2", 0x00000000);
	tmpobjid = CreateObject(19458,2064.731,1243.758,715.098,0.000,90.000,0.000,233.000);
	SetObjectMaterial(tmpobjid, 0, 14815, "whore_main", "WH_tiles2", 0x00000000);
	tmpobjid = CreateObject(14409,2065.669,1253.311,713.404,0.000,0.000,270.000,233.000);
	SetObjectMaterial(tmpobjid, 0, 4004, "civic07_lan", "sl_rotnbrik", 0x00000000);
	SetObjectMaterial(tmpobjid, 1, 4004, "civic07_lan", "sl_rotnbrik", 0x00000000);
	tmpobjid = CreateObject(19401,2073.026,1243.755,716.944,0.000,0.000,90.000,233.000);
	SetObjectMaterial(tmpobjid, 0, 6867, "vgnpwrmainbld", "sw_wallbrick_02", 0x00000000);
	tmpobjid = CreateObject(19401,2069.816,1243.755,716.944,0.000,0.000,90.000,233.000);
	SetObjectMaterial(tmpobjid, 0, 6867, "vgnpwrmainbld", "sw_wallbrick_02", 0x00000000);
	tmpobjid = CreateObject(854,2073.746,1244.040,719.875,-90.099,-47.400,-48.299,300.000);
	SetObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	tmpobjid = CreateObject(854,2070.359,1244.080,719.638,-87.299,-67.200,-67.599,300.000);
	SetObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	tmpobjid = CreateObject(854,2074.859,1243.480,715.365,0.000,0.500,-48.299,233.000);
	SetObjectMaterial(tmpobjid, 0, 18757, "vcinteriors", "dts_elevator_carpet3", 0x00000000);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	tmpobjid = CreateObject(11103,2073.011,1243.710,717.503,0.000,0.000,90.000,233.000);
	tmpobjid = CreateObject(342,2076.033,1249.505,715.638,0.000,-16.500,0.000,233.000);
	tmpobjid = CreateObject(355,2077.320,1246.163,715.771,-19.699,-90.600,121.400,233.000);
	tmpobjid = CreateObject(1672,2076.414,1249.202,715.673,0.000,0.000,0.000,233.000);
	tmpobjid = CreateObject(1672,2076.264,1249.366,715.635,89.500,67.599,4.900,233.000);
	tmpobjid = CreateObject(342,2076.514,1246.495,715.457,0.000,-16.500,0.000,233.000);
	tmpobjid = CreateObject(342,2076.758,1246.533,715.391,0.000,-121.799,-7.299,233.000);
	tmpobjid = CreateObject(1448,2072.129,1249.694,715.313,0.000,0.000,53.299,233.000);
	tmpobjid = CreateObject(1462,2074.259,1244.338,715.183,0.000,0.000,180.000,233.000);
	tmpobjid = CreateObject(2358,2075.238,1249.488,715.294,0.000,0.000,-124.000,233.000);
	tmpobjid = CreateObject(2358,2074.231,1249.832,715.294,0.000,0.000,-102.900,233.000);
	tmpobjid = CreateObject(342,2075.402,1249.495,715.441,0.000,-16.500,0.000,233.000);
	tmpobjid = CreateObject(342,2075.430,1249.650,715.477,0.000,81.799,83.000,233.000);
	tmpobjid = CreateObject(852,2069.144,1246.385,715.103,0.000,0.000,136.800,233.000);
	tmpobjid = CreateObject(852,2072.070,1243.251,715.103,0.000,0.000,42.600,233.000);
	tmpobjid = CreateObject(1219,2072.812,1243.572,717.201,179.700,-90.800,270.500,233.000);
	tmpobjid = CreateObject(995,2061.232,1251.166,716.580,-0.200,-90.399,-90.000,233.000);
	tmpobjid = CreateObject(995,2061.232,1248.855,716.596,-0.200,-90.399,-90.000,233.000);
	tmpobjid = CreateObject(995,2061.232,1250.496,716.584,-0.200,-90.399,-90.000,233.000);
	tmpobjid = CreateObject(995,2061.232,1249.566,716.591,-0.200,-90.399,-90.000,233.000);
	tmpobjid = CreateObject(852,2066.048,1251.368,715.103,0.000,0.000,-170.999,233.000);
	tmpobjid = CreateObject(1448,2066.725,1251.090,715.482,27.100,0.000,53.299,233.000);
	tmpobjid = CreateObject(11103,2069.851,1243.690,717.503,0.000,0.000,90.000,233.000);
	tmpobjid = CreateObject(849,2070.087,1250.227,715.443,0.000,0.000,0.000,233.000);
	tmpobjid = CreateObject(924,2071.204,1246.789,715.373,0.000,0.000,0.000,233.000);
	tmpobjid = CreateObject(849,2070.587,1244.407,715.443,0.000,0.000,0.000,233.000);
	tmpobjid = CreateObject(849,2070.662,1248.561,715.443,0.000,0.000,-141.099,233.000);
	tmpobjid = CreateObject(1219,2070.062,1243.548,717.186,179.700,90.699,90.800,233.000);

	
	CreateObject(12957, 2481.81323, -1693.82898, 13.20430,   0.00000, 0.00000, 15.90000);
	CreateObject(1440, 2463.48120, -1708.10327, 13.00550,   0.00000, 0.00000, -2.58000);
	CreateObject(1415, 2478.97412, -1703.45300, 12.54760,   0.00000, 0.00000, 86.15999);
	CreateObject(2670, 2465.79150, -1712.20728, 12.59820,   0.00000, 0.00000, 59.22000);
	CreateObject(2673, 2479.77466, -1701.45398, 12.66781,   0.00000, 0.00000, 0.00000);
	CreateObject(2674, 2479.42139, -1700.29126, 12.64576,   0.00000, 0.00000, 0.00000);
	CreateObject(1391, 1929.57715, -1318.75037, 47.17650,   0.00000, -11.00000, 0.00000);
	CreateObject(1388, 1927.38086, -1318.58398, 58.77840,   -23.00000, 9.00000, 93.00000);
	CreateObject(3502, 1900.83398, -1303.53723, 14.50670,   0.00000, 0.00000, 153.65997);
	CreateObject(3502, 1910.17139, -1318.64734, 15.17470,   0.00000, 0.00000, 59.16000);
	CreateObject(3502, 1876.44971, -1296.83643, 14.17270,   0.00000, 0.00000, -89.81999);
	CreateObject(1358, 1891.28345, -1294.92297, 13.90400,   0.00000, 0.00000, 0.00000);
	CreateObject(3593, 2488.90894, -1658.27673, 12.69730,   360.00000, 0.00000, -88.00000);
	CreateObject(762, 2460.63281, -1679.01563, 12.38281,   356.85840, 0.00000, 3.14159);
	CreateObject(3593, 2424.45361, -1644.22388, 12.75040,   1.00000, 0.00000, 1.00000);
	CreateObject(849, 2472.20068, -1655.14880, 12.69130,   0.00000, 0.00000, 0.00000);
	CreateObject(12957, 2473.26685, -1657.19690, 12.97130,   0.00000, 0.00000, -55.19999);
	CreateObject(19869, 2467.77173, -1651.41931, 12.29400,   0.00000, 0.00000, 102.72002);
	CreateObject(19869, 2468.28613, -1656.66296, 12.29400,   0.00000, 0.00000, 88.80000);
	CreateObject(19869, 2467.91528, -1668.06201, 12.29400,   0.00000, 0.00000, 88.80000);
	CreateObject(19869, 2468.54614, -1673.22925, 12.29400,   0.00000, 0.00000, 106.68001);
	CreateObject(19869, 2470.64063, -1678.02661, 12.29400,   0.00000, 0.00000, 120.48000);
	CreateObject(1415, 2478.18530, -1715.93872, 12.54760,   0.00000, 0.00000, 86.88000);
	CreateObject(935, 2466.19775, -1650.49390, 13.04710,   0.00000, 0.00000, 0.00000);
	CreateObject(1428, 2446.14648, -1638.56348, 13.81480,   0.00000, 0.00000, -89.34000);
	CreateObject(3866, 2366.09937, -1711.03906, 19.99550,   0.00000, 0.00000, 0.00000);
	CreateObject(1438, 1897.74854, -1328.72668, 12.60830,   -0.88800, 0.00000, 0.00000);
	CreateObject(12839, 1884.55078, -1314.29749, 15.76640,   0.00000, 0.00000, 0.00000);
	CreateObject(1369, 1886.82861, -1313.43591, 44.08690,   0.00000, 0.00000, -33.36000);
	CreateObject(3796, 1901.45349, -1318.78125, 13.17419,   0.00000, 0.00000, 0.00000);
	CreateObject(2674, 2482.01245, -1689.87659, 12.64576,   0.00000, 0.00000, 0.00000);
	CreateObject(2674, 2476.55786, -1673.49988, 12.37760,   0.00000, 0.00000, 0.00000);
	CreateObject(2674, 2473.57446, -1661.67542, 12.37760,   0.00000, 0.00000, 0.00000);
	CreateObject(2674, 2490.37769, -1661.40808, 12.37760,   0.00000, 0.00000, 0.00000);
	CreateObject(2674, 2502.19653, -1679.42920, 12.37760,   0.00000, 0.00000, 0.00000);
	CreateObject(3593, 2506.60864, -1668.32935, 12.69730,   360.00000, 0.00000, -148.71996);
	CreateObject(3593, 2485.47510, -1681.22925, 12.69730,   360.00000, 0.00000, -99.69996);
	CreateObject(19869, 2534.37671, -1706.89673, 12.34590,   0.00000, 0.00000, 1.98000);
	CreateObject(19869, 2473.30078, -1682.52209, 12.29400,   0.00000, 0.00000, 120.48000);
	CreateObject(19869, 2476.69824, -1686.44177, 12.29400,   0.00000, 0.00000, 140.52014);
	CreateObject(673, 2384.63550, -1741.94360, 11.88920,   0.00000, 0.00000, 0.00000);
	CreateObject(673, 2344.65234, -1742.43896, 11.88920,   0.00000, 0.00000, 0.00000);
	CreateObject(673, 2235.06934, -1742.48950, 11.88920,   0.00000, 0.00000, 0.00000);
	CreateObject(673, 2279.60327, -1742.65784, 11.88920,   0.00000, 0.00000, 0.00000);
	CreateObject(2669, 2355.76343, -1719.73376, 13.80200,   0.00000, 0.00000, 90.48000);
	CreateObject(1362, 2360.58838, -1720.96155, 13.15210,   0.00000, 0.00000, 0.00000);
	CreateObject(1505, 2401.74902, -1714.50720, 13.12331,   0.00000, 0.00000, 0.00000);
	CreateObject(1765, 2357.12549, -1712.98291, 12.56752,   0.00000, 0.00000, 118.44002);
	CreateObject(1765, 2356.64233, -1710.45374, 12.56752,   0.00000, 0.00000, 73.80005);
	CreateObject(1280, 2382.12476, -1741.99719, 12.90380,   0.00000, 0.00000, 90.36000);
	CreateObject(1280, 2347.51001, -1742.24304, 12.97480,   0.00000, 0.00000, 90.54000);
	CreateObject(1280, 2281.93335, -1742.75781, 12.90530,   0.00000, 0.00000, 90.12000);
	CreateObject(1280, 2237.24170, -1742.31836, 12.90380,   0.00000, 0.00000, 90.84000);
	CreateObject(1814, 2358.86133, -1711.86682, 12.56755,   0.00000, 0.00000, 88.19997);
	CreateObject(2673, 2358.57690, -1713.19946, 12.67490,   0.00000, 0.00000, 0.00000);
	CreateObject(1440, 2353.60693, -1710.79358, 13.06830,   0.00000, 0.00000, 87.30000);
	CreateObject(1481, 2465.06958, -1710.70264, 13.04540,   0.00000, 0.00000, 24.42000);
	CreateObject(1728, 2465.31177, -1717.17871, 12.43120,   0.00000, 0.00000, 138.42000);
	CreateObject(2670, 2479.82227, -1704.28613, 12.60820,   0.00000, 0.00000, 59.22000);
	CreateObject(2370, 2466.05786, -1714.17603, 12.24440,   0.00000, 0.00000, 0.00000);
	CreateObject(1728, 2463.08594, -1714.02441, 12.43120,   0.00000, 0.00000, 89.33998);
	CreateObject(2670, 2465.87964, -1715.57300, 12.59820,   0.00000, 0.00000, 19.31999);
	CreateObject(1440, 2480.60522, -1690.17432, 13.09050,   0.00000, 0.00000, 83.87997);
	CreateObject(1582, 2466.65601, -1713.43738, 13.08030,   0.00000, 0.00000, 0.00000);
	CreateObject(1216, 2388.95923, -1738.89624, 13.13960,   0.00000, 0.00000, 273.00012);
	CreateObject(1257, 2392.86792, -1739.03650, 13.63719,   0.00000, 0.00000, -90.12000);
	CreateObject(689, -33.78376, -1471.70752, 0.98320,   0.00000, 0.00000, 0.00000);
	CreateObject(1486, 2465.88452, -1714.33203, 13.22220,   0.00000, 0.00000, 0.00000);
	CreateObject(1486, 2466.08862, -1713.47876, 13.22220,   0.00000, 0.00000, 0.00000);
	CreateObject(1486, 2466.64844, -1714.40356, 13.22220,   0.00000, 0.00000, 0.00000);
	CreateObject(3852, 2236.23682, -1835.41785, 14.04090,   0.00000, 0.00000, -83.28000);
	CreateObject(3566, 2441.02441, -1644.19250, 28.25210,   -12.00000, 2.00000, -124.00000);
	CreateObject(3593, 2434.28149, -1633.67322, 27.03520,   0.00000, 0.00000, 0.00000);
	CreateObject(3593, 2434.31787, -1625.18396, 26.72520,   -4.00000, 0.00000, 0.00000);
	CreateObject(2567, 2436.71655, -1675.40515, 14.64640,   0.00000, 0.00000, -51.48000);
	CreateObject(1232, 2373.73218, -1742.47034, 13.62380,   0.00000, 0.00000, 0.00000);
	CreateObject(1232, 2323.93774, -1742.32263, 13.62380,   0.00000, 0.00000, 0.00000);
	CreateObject(1232, 2353.74121, -1742.18591, 13.62380,   0.00000, 0.00000, 0.00000);
	CreateObject(1232, 2226.43774, -1742.31384, 13.62380,   0.00000, 0.00000, 0.00000);
	CreateObject(1232, 2287.12964, -1742.28638, 13.62380,   0.00000, 0.00000, 0.00000);
	CreateObject(1232, 2253.66968, -1742.37976, 13.62380,   0.00000, 0.00000, 0.00000);
	CreateObject(19869, 2371.90479, -1723.30273, 12.54321,   0.00000, 0.00000, 0.00000);
	CreateObject(19869, 2364.48828, -1722.55920, 12.54321,   0.00000, 0.00000, -15.42001);
	CreateObject(5464, 1902.53296, -1309.50134, 29.81670,   0.00000, 0.00000, 0.00000);
	CreateObject(1428, 1885.42859, -1331.30652, 14.01260,   0.00000, 0.00000, 0.00000);
	//Skidd
	CreateObject(10832,62.4000000,-1533.3000000,6.0000000,0.0000000,0.0000000,262.0000000); //object(gatehouse2_sfse) (2)
	CreateObject(10832,42.4000000,-1529.9000000,6.2000000,0.0000000,0.0000000,83.9960000); //object(gatehouse2_sfse) (3)
	CreateObject(966,36.9000000,-1525.1000000,4.2000000,0.0000000,0.0000000,266.0000000); //object(bar_gatebar01) (1)
	CreateObject(966,36.7002000,-1533.5000000,4.2000000,0.0000000,0.0000000,85.9900000); //object(bar_gatebar01) (2)
	CreateObject(966,65.8000000,-1529.4000000,3.9000000,0.0000000,0.0000000,266.0000000); //object(bar_gatebar01) (3)
	CreateObject(966,64.6000000,-1538.0000000,4.0000000,0.0000000,0.0000000,85.9950000); //object(bar_gatebar01) (4)
	CreateObject(968,36.7000000,-1525.0999800,5.2000000,81.0000000,181.0000000,261.0000000); //object(barrierturn) (1)
	CreateObject(973,33.0000000,-1526.1000000,5.2000000,0.0000000,0.0000000,354.0000000); //object(sub_roadbarrier) (1)
	CreateObject(973,32.5000000,-1531.0000000,5.1000000,0.0000000,0.0000000,167.9960000); //object(sub_roadbarrier) (2)
	CreateObject(973,72.2998100,-1533.0000000,5.0000000,0.0000000,0.0000000,349.9910000); //object(sub_roadbarrier) (3)
	CreateObject(973,71.7000000,-1536.6000000,5.1000000,0.0000000,0.0000000,175.9910000); //object(sub_roadbarrier) (4)
	CreateObject(968,66.0000000,-1529.4004000,4.9000000,80.9970000,181.0000000,86.9950000); //object(barrierturn) (2)
	CreateObject(968,36.5996100,-1533.5000000,5.2000000,80.9970000,181.0000000,69.0000000); //object(barrierturn) (3)
	CreateObject(968,36.7002000,-1525.0996000,5.2000000,80.9970000,181.0000000,260.9970000); //object(barrierturn) (4)
	CreateObject(968,64.8000000,-1538.0000000,5.0000000,81.0000000,181.0000000,275.0000000); //object(barrierturn) (7)
	CreateObject(968,66.0000000,-1529.4004000,4.9000000,80.9970000,181.0000000,86.9950000); //object(barrierturn) (8)
	CreateObject(968,66.0000000,-1529.4004000,4.9000000,80.9970000,181.0000000,86.9950000); //object(barrierturn) (9)
	CreateObject(12957,27.3000000,-1528.5000000,4.8000000,0.0000000,0.0000000,140.0000000); //object(sw_pickupwreck01) (1)
	CreateObject(849,31.4000000,-1526.5000000,4.5000000,0.0000000,0.0000000,0.0000000); //object(cj_urb_rub_3) (1)
	CreateObject(1358,35.9000000,-1528.7000000,5.6000000,0.0000000,0.0000000,84.0000000); //object(cj_skip_rubbish) (1)
	CreateObject(3594,20.9003900,-1515.7998000,3.9000000,0.0000000,0.0000000,277.9980000); //object(la_fuckcar1) (1)
	CreateObject(851,28.9000000,-1538.7000000,4.2000000,0.0000000,0.0000000,0.0000000); //object(cj_urb_rub_2) (1)
	CreateObject(2674,52.8000000,-1533.3000000,4.3000000,0.0000000,0.0000000,0.0000000); //object(proc_rubbish_2) (1)
	CreateObject(1369,53.9000000,-1531.0000000,4.9000000,0.0000000,0.0000000,316.0000000); //object(cj_wheelchair1) (1)
	CreateObject(1440,56.9000000,-1533.0000000,4.8000000,0.0000000,0.0000000,260.0000000); //object(dyn_box_pile_3) (1)
	CreateObject(2672,56.4000000,-1530.9000000,4.5000000,0.0000000,0.0000000,0.0000000); //object(proc_rubbish_4) (1)
	CreateObject(854,48.3000000,-1532.3000000,4.5000000,0.0000000,0.0000000,0.0000000); //object(cj_urb_rub_3b) (1)
	CreateObject(873,26.0000000,-1534.5000000,5.5000000,0.0000000,0.0000000,0.0000000); //object(veg_procfpatch) (1)
	CreateObject(865,21.1000000,-1520.7000000,3.3000000,0.0000000,0.0000000,0.0000000); //object(sand_combush02) (1)
	CreateObject(865,26.6000000,-1518.8000000,3.3000000,0.0000000,0.0000000,0.0000000); //object(sand_combush02) (2)
	CreateObject(865,30.5000000,-1522.0000000,3.9000000,0.0000000,0.0000000,0.0000000); //object(sand_combush02) (3)
	CreateObject(760,25.9000000,-1522.4000000,3.6000000,0.0000000,0.0000000,0.0000000); //object(sm_bush_small_1) (1)
	CreateObject(1442,51.9000000,-1531.7000000,4.9000000,0.0000000,0.0000000,0.0000000); //object(dyn_firebin0) (1)
	CreateObject(2673,50.6000000,-1532.9000000,4.4000000,0.0000000,0.0000000,0.0000000); //object(proc_rubbish_5) (1)
	CreateObject(1450,48.0000000,-1528.6000000,4.9000000,0.0000000,0.0000000,84.0000000); //object(dyn_crate_3) (1)
	CreateObject(2671,50.1000000,-1530.1000000,4.3000000,0.0000000,0.0000000,0.0000000); //object(proc_rubbish_3) (1)
	CreateObject(707,15.6000000,-1506.6000000,2.6000000,0.0000000,0.0000000,77.9970000); //object(sm_bushvbig) (1)
	CreateObject(707,-2.2000000,-1507.9000000,2.2000000,0.0000000,0.0000000,0.0000000); //object(sm_bushvbig) (2)
	CreateObject(707,-0.5000000,-1542.6000000,1.6000000,0.0000000,0.0000000,0.0000000); //object(sm_bushvbig) (3)
	CreateObject(873,-25.3000000,-1539.6000000,2.9000000,0.0000000,0.0000000,0.0000000); //object(veg_procfpatch) (2)
	CreateObject(874,-27.8000000,-1557.4000000,2.8000000,0.0000000,0.0000000,0.0000000); //object(veg_procgrasspatch) (1)
	CreateObject(849,-23.6000000,-1549.9000000,1.4000000,0.0000000,0.0000000,0.0000000); //object(cj_urb_rub_3) (2)
	CreateObject(852,-34.7000000,-1557.6000000,1.1000000,0.0000000,0.0000000,0.0000000); //object(cj_urb_rub_4) (1)
	CreateObject(1365,-38.6000000,-1549.8000000,2.9000000,0.0000000,0.0000000,86.0000000); //object(cj_big_skip1) (1)
	CreateObject(13591,-35.5000000,-1536.7000000,2.0000000,0.0000000,0.0000000,258.0000000); //object(kickcar28) (1)
	CreateObject(901,-12.3000000,-1556.4000000,2.0000000,0.0000000,0.0000000,4.0000000); //object(searock05) (2)
	CreateObject(2671,-27.1000000,-1527.0000000,0.9000000,0.0000000,0.0000000,0.0000000); //object(proc_rubbish_3) (2)
	CreateObject(874,7.5000000,-1522.4000000,4.4000000,0.0000000,0.0000000,0.0000000); //object(veg_procgrasspatch) (2)
	CreateObject(707,33.0996100,-1485.0996000,8.2000000,0.0000000,0.0000000,77.9970000); //object(sm_bushvbig) (4)
	CreateObject(3363,-10.0000000,-1534.5000000,1.5000000,0.0000000,0.0000000,14.0000000); //object(des_ruin1_) (1)
	CreateObject(14402,-16.0000000,-1530.3000000,2.3000000,0.0000000,0.0000000,0.0000000); //object(flower-bush09) (1)
	CreateObject(18451,79.2000000,-1536.0000000,4.9000000,0.0000000,0.0000000,72.0000000); //object(cs_oldcarjmp) (1)
	CreateObject(850,71.8000000,-1529.2000000,4.2000000,0.0000000,0.0000000,218.0000000); //object(cj_urb_rub_1) (1)
	CreateObject(3594,49.7000000,-1539.7000000,4.8000000,0.0000000,0.0000000,32.0000000); //object(la_fuckcar1) (2)
	CreateObject(2675,44.8000000,-1541.3000000,4.3000000,0.0000000,0.0000000,0.0000000); //object(proc_rubbish_6) (1)
	CreateObject(1221,53.4000000,-1543.1000000,4.6000000,0.0000000,0.0000000,0.0000000); //object(cardboardbox4) (1)
	CreateObject(960,43.9000000,-1534.4000000,4.6000000,0.0000000,0.0000000,26.0000000); //object(cj_arm_crate) (1)
	CreateObject(2059,55.3000000,-1533.7000000,4.3000000,0.0000000,0.0000000,0.0000000); //object(cj_gunstuff1) (1)
	CreateObject(1236,69.3000000,-1534.0000000,4.8000000,0.0000000,0.0000000,58.0000000); //object(rcyclbank01) (1)
	CreateObject(851,74.2000000,-1535.2000000,4.6000000,0.0000000,0.0000000,0.0000000); //object(cj_urb_rub_2) (3)
	CreateObject(2672,71.9000000,-1534.2000000,4.5000000,0.0000000,0.0000000,0.0000000); //object(proc_rubbish_4) (2)
	CreateObject(2036,71.4000000,-1535.9000000,4.2000000,0.0000000,0.0000000,328.0000000); //object(cj_psg1) (1)
	CreateObject(2058,69.7000000,-1535.8000000,4.2000000,0.0000000,0.0000000,346.0000000); //object(cj_gun_docs) (1)
	CreateObject(873,85.6000000,-1546.8000000,6.5000000,0.0000000,0.0000000,34.0000000); //object(veg_procfpatch) (3)
	CreateObject(874,60.8000000,-1539.9000000,5.9000000,0.0000000,0.0000000,80.0000000); //object(veg_procgrasspatch) (3)
	CreateObject(759,70.6000000,-1517.1000000,3.9000000,0.0000000,0.0000000,0.0000000); //object(sm_bush_large_1) (1)
	CreateObject(3566,84.3000000,-1551.3000000,7.6000000,0.0000000,0.0000000,258.0000000); //object(lasntrk1) (1)
	CreateObject(873,-23.5000000,-1517.8000000,2.6000000,0.0000000,0.0000000,0.0000000); //object(veg_procfpatch) (4)
	CreateObject(874,83.8000000,-1528.3000000,6.1000000,0.0000000,0.0000000,48.0000000); //object(veg_procgrasspatch) (4)
	CreateObject(874,47.1000000,-1524.6000000,6.1000000,0.0000000,0.0000000,255.9990000); //object(veg_procgrasspatch) (5)
	CreateObject(849,63.6000000,-1522.9000000,4.3000000,0.0000000,0.0000000,0.0000000); //object(cj_urb_rub_3) (4)
	CreateObject(1299,69.4000000,-1523.9000000,4.4000000,0.0000000,0.0000000,348.0000000); //object(smashboxpile) (1)
	CreateObject(2676,67.1000000,-1527.2000000,4.0000000,0.0000000,0.0000000,0.0000000); //object(proc_rubbish_8) (1)
	CreateObject(933,59.3000000,-1528.4000000,4.0000000,0.0000000,0.0000000,0.0000000); //object(cj_cableroll) (1)
	CreateObject(707,86.8000000,-1562.0000000,6.2000000,0.0000000,0.0000000,77.9970000); //object(sm_bushvbig) (5)
	CreateObject(707,114.0000000,-1570.8000000,8.6000000,0.0000000,0.0000000,77.9970000); //object(sm_bushvbig) (6)
	CreateObject(707,104.2000000,-1589.5000000,10.1000000,0.0000000,0.0000000,77.9970000); //object(sm_bushvbig) (7)
	CreateObject(707,142.3999900,-1530.7000000,9.1000000,0.0000000,0.0000000,77.9970000); //object(sm_bushvbig) (8)
/*	//IslandSnow
	tmpobjid = CreateObject(11695, -2541.90796, 3917.50195, -22.43430,   0.00000, 0.00000, 0.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0x00000000);
	SetObjectMaterial(tmpobjid, 2, 3914, "snow", "mp_snow", 0x00000000);
	SetObjectMaterial(tmpobjid, 3, 3914, "snow", "mp_snow", 0x00000000);
	CreateObject(19545, -2561.76831, 3962.40820, 10.19630,   0.00000, 0.00000, 0.00000);
	tmpobjid = CreateObject(766, -2478.57739, 3903.02490, 9.84110,   0.00000, 0.00000, -4.56000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0x00000000);
	CreateObject(8075, -2535.55957, 3852.20996, 14.06040,   0.00000, 0.00000, -0.24001);
	CreateObject(8886, -2563.29810, 3847.65625, 13.61120,   0.00000, 0.00000, 90.65999);
	tmpobjid = CreateObject(18259, -2518.29053, 3928.04053, 11.42990,   0.00000, 0.00000, 0.00000);
	SetObjectMaterial(tmpobjid, 1, 3914, "snow", "mp_snow", 0x00000000);
	CreateObject(18258, -2523.41992, 3927.41016, 11.82700,   0.00000, 0.00000, 0.00000);
	CreateObject(19545, -2561.76758, 3899.94287, 10.19630,   0.00000, 0.00000, 0.00000);
	CreateObject(19545, -2576.80005, 3899.91846, 10.19630,   0.00000, 0.00000, 0.00000);
	CreateObject(19545, -2576.75269, 3962.39941, 10.19630,   0.00000, 0.00000, 0.00000);
	tmpobjid = CreateObject(698, -2505.41626, 3960.71631, 14.98300,   0.00000, 0.00000, 15.84000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0xFFFFFFFF);
	tmpobjid = CreateObject(698, -2504.96777, 3983.86279, 14.98300,   0.00000, 0.00000, 15.84000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0xFFFFFFFF);
	tmpobjid = CreateObject(698, -2532.85181, 3978.06152, 14.98300,   0.00000, 0.00000, 15.84000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0xFFFFFFFF);
	tmpobjid = CreateObject(698, -2482.07886, 3949.38086, 14.98300,   0.00000, 0.00000, 15.84000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0xFFFFFFFF);
	tmpobjid = CreateObject(698, -2479.06348, 3972.48242, 14.98300,   0.00000, 0.00000, 15.84000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0xFFFFFFFF);
	tmpobjid = CreateObject(791, -2608.02881, 3846.77490, 1.94750,   0.00000, 0.00000, 0.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0xFFFFFFFF);
	tmpobjid = CreateObject(698, -2476.85083, 3873.69434, 12.74910,   0.00000, 0.00000, 0.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0xFFFFFFFF);
	tmpobjid = CreateObject(698, -2502.43994, 3849.58154, 12.74910,   0.00000, 0.00000, 0.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0xFFFFFFFF);
	tmpobjid = CreateObject(766, -2494.95093, 3917.20850, 9.84110,   0.00000, 0.00000, 0.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0x00000000);
	CreateObject(2935, -2574.27197, 3847.78857, 11.42800,   0.00000, 0.00000, 53.40000);
	CreateObject(2935, -2569.65088, 3858.69971, 11.42800,   0.00000, 0.00000, 135.71994);
	CreateObject(2935, -2554.92676, 3850.78369, 11.42800,   0.00000, 0.00000, 208.67995);
	CreateObject(2934, -2552.41772, 3862.83105, 11.28710,   0.00000, 0.00000, 35.46000);
	CreateObject(2934, -2534.74780, 3869.68115, 11.28710,   0.00000, 0.00000, 121.02000);
	CreateObject(17026, -2552.14331, 4015.42041, -1.73370,   0.00000, 0.00000, -116.63999);
	CreateObject(17026, -2546.23267, 3824.90723, -5.68590,   0.00000, 0.00000, -119.81999);
	CreateObject(923, -2515.80322, 3913.92041, 10.82850,   0.00000, 0.00000, 4.43999);
	CreateObject(1765, -2516.96582, 3931.17773, 11.50941,   0.00000, 0.00000, -31.01998);
	CreateObject(1765, -2520.27271, 3930.68896, 11.50941,   0.00000, 0.00000, 24.06001);
	CreateObject(941, -2586.11182, 3906.37402, 10.48070,   0.00000, 0.00000, -38.88000);
	CreateObject(14556, -2514.27710, 3920.53174, 12.97820,   0.00000, 0.00000, 91.73999);
	CreateObject(1543, -2520.20337, 3930.13672, 11.51033,   0.00000, 0.00000, 0.00000);
	CreateObject(1543, -2516.06812, 3930.08740, 11.51033,   0.00000, 0.00000, 0.00000);
	CreateObject(937, -2514.17627, 3926.89600, 11.90130,   0.00000, 0.00000, 92.70000);
	tmpobjid = CreateObject(3364, -2609.48193, 3966.14893, 10.08256,   0.00000, 0.00000, -125.22000);
	SetObjectMaterial(tmpobjid, 1, 3914, "snow", "mp_snow", 0x00000000);
	SetObjectMaterial(tmpobjid, 4, 3914, "snow", "mp_snow", 0x00000000);
	SetObjectMaterial(tmpobjid, 5, 3914, "snow", "mp_snow", 0x00000000);
	CreateObject(3168, -2600.59985, 3919.05615, 10.07061,   0.00000, 0.00000, 203.28004);
	CreateObject(3172, -2601.72290, 3935.07617, 10.09149,   0.00000, 0.00000, -196.20006);
	CreateObject(941, -2586.14746, 3900.75977, 10.48070,   0.00000, 0.00000, -0.12000);
	CreateObject(941, -2586.57788, 3910.74023, 10.48070,   0.00000, 0.00000, 11.70000);
	CreateObject(941, -2587.17383, 3915.54297, 10.48070,   0.00000, 0.00000, -7.92000);
	CreateObject(941, -2586.59717, 3919.65723, 10.48070,   0.00000, 0.00000, -2.28000);
	CreateObject(941, -2586.53906, 3923.98779, 10.48070,   0.00000, 0.00000, -86.99998);
	CreateObject(348, -2586.22363, 3906.21240, 10.95260,   91.00000, 4.00000, -46.00000);
	CreateObject(348, -2586.05322, 3906.56348, 10.95260,   91.00000, 4.00000, -46.00000);
	CreateObject(355, -2586.18433, 3900.46045, 10.93370,   84.00000, -76.00000, 80.16000);
	CreateObject(355, -2586.16406, 3900.98682, 10.93370,   84.00000, -76.00000, 80.16000);
	CreateObject(356, -2586.47339, 3910.47021, 10.98620,   94.00000, 91.00000, -77.00000);
	CreateObject(356, -2586.64136, 3910.92773, 10.98620,   94.00000, 91.00000, -77.00000);
	CreateObject(358, -2522.97656, 3929.39209, 11.76230,   -11.00000, -84.00000, 101.00000);
	CreateObject(3271, -2566.52002, 3952.96729, 10.15381,   0.00000, 0.00000, 3.12000);
	CreateObject(16599, -2620.14697, 3950.93555, 14.39680,   0.00000, 0.00000, 15.66000);
	CreateObject(17026, -2631.98608, 3989.66357, -1.73370,   0.00000, 0.00000, -52.32000);
	CreateObject(17026, -2635.52393, 3942.60986, -1.73370,   0.00000, 0.00000, -4.86000);
	CreateObject(17026, -2466.50464, 3932.09912, -1.73370,   0.00000, 0.00000, -24.24000);
	CreateObject(769, -2504.89600, 3943.99121, 10.07472,   0.00000, 0.00000, 0.00000);
	CreateObject(342, -2586.06006, 3915.33936, 11.02630,   -4.00000, 76.00000, 0.00000);
	CreateObject(342, -2586.58887, 3915.63818, 11.02630,   -4.00000, 76.00000, 0.00000);
	CreateObject(342, -2586.60815, 3915.35742, 11.02630,   -4.00000, 76.00000, 0.00000);
	CreateObject(342, -2587.04663, 3915.69775, 11.02630,   -4.00000, 76.00000, 0.00000);
	CreateObject(342, -2587.28833, 3915.42383, 11.02630,   -4.00000, 76.00000, 0.00000);
	CreateObject(342, -2587.55469, 3915.70654, 11.02630,   -4.00000, 76.00000, 0.00000);
	CreateObject(349, -2586.83398, 3919.48486, 10.95060,   84.00000, -91.00000, 97.12000);
	CreateObject(349, -2586.84058, 3919.93506, 10.95060,   84.00000, -91.00000, 97.12000);
	CreateObject(353, -2586.82373, 3924.06543, 10.95400,   84.00000, -76.00000, 0.00000);
	CreateObject(353, -2586.22559, 3924.11572, 10.95400,   84.00000, -76.00000, 0.00000);
	tmpobjid = CreateObject(766, -2509.74219, 3891.19727, 9.84110,   0.00000, 0.00000, 0.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0x00000000);
	CreateObject(933, -2518.21069, 3929.50488, 10.97890,   0.00000, 0.00000, 0.00000);	
	tmpobjid = CreateObject(664, -2595.90210, 3896.15552, 8.94290,   0.00000, 0.00000, 0.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0x00000000);
	tmpobjid = CreateObject(664, -2537.4458, 3897.4248, 8.9429,   0.00000, 0.00000, 0.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0x00000000);
	CreateObject(19076, -2524.25513, 3942.72485, 10.05956,   0.00000, 0.00000, 0.00000);
	CreateObject(19054, -2525.40210, 3941.98608, 10.73930,   0.00000, 0.00000, 0.00000);
	CreateObject(19056, -2526.06055, 3943.44507, 10.73930,   0.00000, 0.00000, 18.00000);
	CreateObject(19055, -2523.28418, 3943.50781, 10.73930,   0.00000, 0.00000, 11.00000);
	CreateObject(19058, -2524.68091, 3944.23462, 10.73930,   0.00000, 0.00000, -40.00000);
	CreateObject(19057, -2523.69971, 3941.63135, 10.73930,   0.00000, 0.00000, 20.00000);
	tmpobjid = CreateObject(19059, -2524.48853, 3938.72681, 10.49020,   0.00000, 0.00000, 0.00000);
	SetObjectMaterial(tmpobjid, 1, 3914, "snow", "mp_snow", 0xFFFFFFFF);
	tmpobjid = CreateObject(1946, -2524.48853, 3938.72681, 11.68250,   0.00000, 0.00000, 0.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0xFFFFFFFF);
	CreateObject(19468, -2524.48853, 3938.72681, 12.06380,   0.00000, 180.00000, 0.00000);
	tmpobjid = CreateObject(19578, -2524.66870, 3938.70068, 11.70390,   -90.00000, 0.00000, -170.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0xFFED9121);
	tmpobjid = CreateObject(1974, -2524.6245, 3938.6484, 11.7623,   0.00000, 0.00000, 0.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0xFF000000);
	tmpobjid = CreateObject(1974, -2524.6445, 3938.7686, 11.7623,   0.00000, 0.00000, 0.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0xFF000000);
	tmpobjid = CreateObject(19059, -2524.48853, 3938.72681, 11.15020,   0.00000, 0.00000, 0.00000);
	SetObjectMaterial(tmpobjid, 1, 3914, "snow", "mp_snow", 0xFFFFFFFF);
	tmpobjid = CreateObject(1974, -2524.79492, 3938.46680, 10.14790,   0.00000, 0.00000, 0.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0xFFFFFFFF);
	tmpobjid = CreateObject(1974, -2524.87671, 3938.84692, 10.14790,   0.00000, 0.00000, 0.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0xFFFFFFFF);
	tmpobjid = CreateObject(902, -2537.35962, 3897.16504, 57.00000,   42.00000, 90.00000, 0.00000);
	SetObjectMaterial(tmpobjid, 0, 8839, "vgsecarshow", "lightyellow2_32", 0xFFFFFFFF);
	tmpobjid = CreateObject(902, -2537.21948, 3897.16504, 57.00000,   30.00000, 90.00000, 180.00000);
	SetObjectMaterial(tmpobjid, 0, 8839, "vgsecarshow", "lightyellow2_32", 0xFFFFFFFF);
	CreateObject(19054, -2522.20898, 3933.78442, 12.14970,   0.00000, 0.00000, -25.00000);
	CreateObject(19055, -2520.62549, 3933.66724, 12.14970,   0.00000, 0.00000, 4.00000);
	CreateObject(19056, -2521.62402, 3932.11865, 12.14970,   0.00000, 0.00000, 18.00000);
	CreateObject(19057, -2521.46094, 3933.06348, 13.28970,   0.00000, 0.00000, 0.00000);
	tmpobjid = CreateObject(19689, -2602.64917, 3877.59839, 9.50000,   0.00000, 160.00000, 62.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0x00000000);
	tmpobjid = CreateObject(19689, -2604.38379, 3985.48877, 9.50000,   0.00000, 160.00000, 0.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0x00000000);
	tmpobjid = CreateObject(19689, -2522.31494, 3995.77271, 9.50000,   0.00000, 160.00000, 0.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0x00000000);
	tmpobjid = CreateObject(19689, -2566.53296, 3994.12866, 9.50000,   0.00000, 160.00000, 0.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0x00000000);
	tmpobjid = CreateObject(19689, -2550.04956, 3900.77783, 9.50000,   0.00000, 160.00000, 98.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0x00000000);
	tmpobjid = CreateObject(19689, -2487.48022, 3863.12573, 9.50000,   0.00000, 160.00000, -25.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0x00000000);
	tmpobjid = CreateObject(19689, -2487.43140, 3891.73047, 9.50000,   0.00000, 160.00000, 47.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0x00000000);
	tmpobjid = CreateObject(19689, -2490.26514, 3933.02954, 9.50000,   0.00000, 160.00000, 105.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0x00000000);
	tmpobjid = CreateObject(19689, -2503.07031, 3975.86743, 9.50000,   0.00000, 160.00000, 33.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0x00000000);
	tmpobjid = CreateObject(19689, -2538.10986, 3926.77710, 9.50000,   0.00000, 160.00000, 98.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0x00000000);
	tmpobjid = CreateObject(19689, -2535.54883, 3967.92065, 9.50000,   0.00000, 160.00000, -40.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0x00000000);
	tmpobjid = CreateObject(19689, -2519.34497, 3863.03906, 9.50000,   0.00000, 160.00000, -55.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0x00000000);
	tmpobjid = CreateObject(19689, -2600.97021, 3851.54590, 9.50000,   0.00000, 160.00000, -40.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0x00000000);
	tmpobjid = CreateObject(19689, -2575.63306, 3968.42236, 9.50000,   0.00000, 160.00000, 55.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0x00000000);
	tmpobjid = CreateObject(19689, -2561.65576, 3942.38062, 9.50000,   0.00000, 160.00000, 69.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0x00000000);
	tmpobjid = CreateObject(19689, -2607.54370, 3966.34424, 9.50000,   0.00000, 160.00000, -33.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0x00000000);
	tmpobjid = CreateObject(19689, -2607.79004, 3925.71924, 9.50000,   0.00000, 160.00000, 84.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0x00000000);
	tmpobjid = CreateObject(19689, -2565.19482, 3869.03247, 9.50000,   0.00000, 160.00000, 0.00000);
	SetObjectMaterial(tmpobjid, 0, 3914, "snow", "mp_snow", 0x00000000);
	CreateObject(2712, -2525.02783, 3937.85889, 10.68080,   0.00000, 0.00000, 0.00000);
	tmpobjid = CreateObject(334, -2524.62451, 3938.31348, 11.27130,   0.00000, 90.00000, -113.00000);
	tmpobjid = CreateObject(334, -2524.65723, 3939.01636, 11.42640,   0.00000, 62.00000, 120.00000);*/

	//Island
	tmpobjid = CreateObject(11695,-2541.907,3917.501,-22.434,0.000,0.000,0.000,123.000);
	SetObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "Bow_church_grass_alt", 0x00000000);
	//SetObjectMaterial(tmpobjid, 0, 17944, "lngblok_lae2", "white64bumpy", 0x00000000);
	tmpobjid = CreateObject(17026,-2552.143,4015.420,-1.733,0.000,0.000,-116.639,123.000);
	SetObjectMaterial(tmpobjid, 1, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0x00000000);
	tmpobjid = CreateObject(17026,-2546.232,3824.907,-5.685,0.000,0.000,-119.819,123.000);
	SetObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0x00000000);
	SetObjectMaterial(tmpobjid, 1, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0x00000000);
	tmpobjid = CreateObject(17026,-2631.986,3989.663,-1.733,0.000,0.000,-52.319,123.000);
	SetObjectMaterial(tmpobjid, 1, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0x00000000);
	tmpobjid = CreateObject(17026,-2635.523,3942.609,-1.733,0.000,0.000,-4.860,123.000);
	SetObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0x00000000);
	SetObjectMaterial(tmpobjid, 1, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0x00000000);
	tmpobjid = CreateObject(17026,-2466.504,3932.099,-1.733,0.000,0.000,-24.239,123.000);
	SetObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0x00000000);
	SetObjectMaterial(tmpobjid, 1, 10101, "2notherbuildsfe", "ws_rooftarmac1", 0x00000000);
	CreateObject(19545,-2561.768,3962.408,10.126,0.000,0.000,0.000,123.000);
	CreateObject(766,-2478.577,3903.024,9.841,0.000,0.000,-4.559,123.000);
	CreateObject(8075,-2535.559,3852.209,14.060,0.000,0.000,-0.240,123.000);
	CreateObject(8886,-2563.298,3847.656,13.611,0.000,0.000,90.659,123.000);
	CreateObject(18259,-2518.290,3928.040,11.429,0.000,0.000,0.000,123.000);
	CreateObject(18258,-2523.419,3927.410,11.826,0.000,0.000,0.000,123.000);
	CreateObject(19545,-2561.826,3899.942,10.106,0.000,0.000,0.000,123.000);
	CreateObject(19545,-2576.770,3899.918,10.126,0.000,0.000,0.000,123.000);
	CreateObject(19545,-2576.752,3962.399,10.116,0.000,0.000,0.000,123.000);
	CreateObject(698,-2505.416,3960.716,14.982,0.000,0.000,15.840,123.000);
	CreateObject(698,-2504.967,3983.862,14.982,0.000,0.000,15.840,123.000);
	CreateObject(698,-2532.851,3978.061,14.982,0.000,0.000,15.840,123.000);
	CreateObject(698,-2482.078,3949.380,14.982,0.000,0.000,15.840,123.000);
	CreateObject(698,-2479.063,3972.482,14.982,0.000,0.000,15.840,123.000);
	CreateObject(791,-2608.028,3846.774,1.947,0.000,0.000,0.000,123.000);
	CreateObject(698,-2476.850,3873.694,12.749,0.000,0.000,0.000,123.000);
	CreateObject(698,-2503.603,3849.712,12.749,0.000,0.000,0.000,123.000);
	CreateObject(766,-2494.950,3917.208,9.841,0.000,0.000,0.000,123.000);
	CreateObject(2935,-2574.271,3847.788,11.428,0.000,0.000,53.400,123.000);
	CreateObject(2935,-2569.650,3858.699,11.428,0.000,0.000,135.719,123.000);
	CreateObject(2935,-2554.926,3850.783,11.428,0.000,0.000,208.679,123.000);
	CreateObject(2934,-2552.417,3862.831,11.287,0.000,0.000,35.459,123.000);
	CreateObject(2934,-2534.747,3869.681,11.287,0.000,0.000,121.019,123.000);
	CreateObject(901,-2517.530,3976.402,8.724,0.000,0.000,0.000,123.000);
	CreateObject(745,-2595.274,3851.725,10.090,0.000,0.000,-33.419,123.000);
	CreateObject(1369,-2531.758,3933.086,10.767,0.000,0.000,-33.840,123.000);
	CreateObject(744,-2479.732,3953.815,10.087,0.000,0.000,0.000,123.000);
	CreateObject(933,-2525.138,3912.370,10.096,0.000,0.000,0.000,123.000);
	CreateObject(923,-2515.803,3913.920,10.828,0.000,0.000,4.439,123.000);
	CreateObject(762,-2489.094,3865.699,11.922,0.000,0.000,0.000,123.000);
	CreateObject(870,-2531.198,3912.465,10.361,0.000,0.000,0.000,123.000);
	CreateObject(870,-2516.576,3884.112,10.361,0.000,0.000,0.000,123.000);
	CreateObject(1765,-2516.965,3931.177,11.509,0.000,0.000,-31.019,123.000);
	CreateObject(1765,-2520.272,3930.688,11.509,0.000,0.000,24.060,123.000);
	CreateObject(941,-2586.111,3906.374,10.480,0.000,0.000,-38.880,123.000);
	CreateObject(14556,-2514.277,3920.531,12.978,0.000,0.000,91.739,123.000);
	CreateObject(1543,-2520.203,3930.136,11.510,0.000,0.000,0.000,123.000);
	CreateObject(1543,-2516.068,3930.087,11.510,0.000,0.000,0.000,123.000);
	CreateObject(937,-2514.176,3926.895,11.901,0.000,0.000,92.699,123.000);
	CreateObject(870,-2594.575,3907.588,10.361,0.000,0.000,0.000,123.000);
	CreateObject(3364,-2609.481,3966.148,10.082,0.000,0.000,-125.220,123.000);
	CreateObject(708,-2602.187,3976.931,10.062,0.000,0.000,0.000,123.000);
	CreateObject(759,-2590.912,3990.067,10.088,0.000,0.000,0.000,123.000);
	CreateObject(705,-2597.590,3891.094,10.070,0.000,0.000,0.000,123.000);
	CreateObject(3168,-2600.599,3919.056,10.070,0.000,0.000,203.280,123.000);
	CreateObject(3172,-2601.722,3935.076,10.091,0.000,0.000,-196.200,123.000);
	CreateObject(1765,-2599.713,3927.604,10.092,0.000,0.000,79.620,123.000);
	CreateObject(1765,-2599.022,3924.597,10.092,0.000,0.000,123.060,123.000);
	CreateObject(941,-2586.147,3900.759,10.480,0.000,0.000,-0.119,123.000);
	CreateObject(941,-2586.577,3910.740,10.480,0.000,0.000,11.699,123.000);
	CreateObject(941,-2587.173,3915.542,10.480,0.000,0.000,-7.920,123.000);
	CreateObject(941,-2586.597,3919.657,10.480,0.000,0.000,-2.279,123.000);
	CreateObject(941,-2586.539,3923.987,10.480,0.000,0.000,-86.999,123.000);
	CreateObject(348,-2586.223,3906.212,10.952,91.000,4.000,-46.000,123.000);
	CreateObject(348,-2586.053,3906.563,10.952,91.000,4.000,-46.000,123.000);
	CreateObject(355,-2586.184,3900.460,10.933,84.000,-76.000,80.160,123.000);
	CreateObject(355,-2586.164,3900.986,10.933,84.000,-76.000,80.160,123.000);
	CreateObject(356,-2586.473,3910.470,10.986,94.000,91.000,-77.000,123.000);
	CreateObject(356,-2586.641,3910.927,10.986,94.000,91.000,-77.000,123.000);
	CreateObject(358,-2522.976,3929.392,11.762,-11.000,-84.000,101.000,123.000);
	CreateObject(19315,-2514.204,3926.926,12.459,84.000,-11.000,98.000,123.000);
	CreateObject(3271,-2566.520,3952.967,10.153,0.000,0.000,3.119,123.000);
	CreateObject(16599,-2620.146,3950.935,14.396,0.000,0.000,15.659,123.000);
	CreateObject(775,-2546.041,3886.617,10.067,0.000,0.000,0.000,123.000);
	CreateObject(769,-2504.895,3943.991,10.074,0.000,0.000,0.000,123.000);
	CreateObject(342,-2586.060,3915.339,11.026,-4.000,76.000,0.000,123.000);
	CreateObject(342,-2586.588,3915.638,11.026,-4.000,76.000,0.000,123.000);
	CreateObject(342,-2586.608,3915.357,11.026,-4.000,76.000,0.000,123.000);
	CreateObject(342,-2587.046,3915.697,11.026,-4.000,76.000,0.000,123.000);
	CreateObject(342,-2587.288,3915.423,11.026,-4.000,76.000,0.000,123.000);
	CreateObject(342,-2587.554,3915.706,11.026,-4.000,76.000,0.000,123.000);
	CreateObject(349,-2586.833,3919.484,10.950,84.000,-91.000,97.120,123.000);
	CreateObject(349,-2586.840,3919.935,10.950,84.000,-91.000,97.120,123.000);
	CreateObject(353,-2586.823,3924.065,10.954,84.000,-76.000,0.000,123.000);
	CreateObject(353,-2586.225,3924.115,10.954,84.000,-76.000,0.000,123.000);
	CreateObject(870,-2592.056,3937.025,10.361,0.000,0.000,0.000,123.000);
	CreateObject(766,-2509.742,3891.197,9.841,0.000,0.000,0.000,123.000);
	CreateObject(933,-2518.210,3929.504,10.978,0.000,0.000,0.000,123.000);
	//Стройка и по мелочи
	tmpobjid = CreateObject(17121,-65.054,-1572.949,-3.898,0.000,0.000,0.000,213.000);
	SetObjectMaterial(tmpobjid, 3, 8034, "vgsswarhse04", "GB_truckdepot14", 0x00000000);
	CreateObject(5463, -81.89080, -1568.44641, 25.35810,   0.00000, 0.00000, 44.70000);
	CreateObject(5644, -82.32097, -1568.31360, 18.06930,   0.00000, 0.00000, 44.52000);
	CreateObject(19589, -95.11776, -1601.69360, 1.74550,   0.00000, 0.00000, 120.42003);
	CreateObject(4641, -44.79400, -1571.42273, 3.06330,   0.00000, 0.00000, -29.76000);
	CreateObject(1684, -43.18874, -1565.04224, 3.00410,   0.00000, 0.00000, -118.98006);
	CreateObject(1684, -47.28564, -1554.89551, 3.00410,   0.00000, 0.00000, -43.32004);
	CreateObject(1415, -58.03089, -1541.95276, 1.63390,   0.00000, 0.00000, -44.82001);
	CreateObject(3567, -82.77670, -1614.06140, 3.17070,   0.00000, 0.00000, -62.40000);
	CreateObject(8886, -107.64848, -1578.67053, 4.88790,   0.00000, 0.00000, -56.57999);
	CreateObject(3593, 2401.55322, -1735.32214, 12.84020,   0.00000, 0.00000, 90.06000);
	CreateObject(3593, 2394.05835, -1735.26526, 12.84020,   0.00000, 0.00000, 90.06000);
	CreateObject(3593, 2385.61816, -1735.13025, 12.84020,   0.00000, 0.00000, 90.06000);
	CreateObject(3593, 2409.68896, -1738.94177, 12.84020,   0.00000, 0.00000, 49.26000);
	CreateObject(3866, 2517.57544, -1526.15710, 30.03870,   0.00000, 0.00000, 0.72000);
	CreateObject(3865, 2520.99341, -1547.62280, 31.67470,   0.00000, 0.00000, -86.82000);
	CreateObject(3865, 2512.45752, -1543.31396, 24.07470,   0.00000, 0.00000, -4.19998);
	CreateObject(3172, 2537.24805, -1523.80664, 22.76444,   0.00000, 0.00000, 0.00000);
	CreateObject(3504, 2536.93774, -1531.60461, 23.90700,   0.00000, 0.00000, 89.88000);
	CreateObject(3504, 2536.94385, -1533.08557, 23.90700,   0.00000, 0.00000, 89.88000);
	CreateObject(19869, 2536.46558, -1536.34363, 22.63132,   0.00000, 0.00000, 88.67999);
	CreateObject(19869, 2534.32422, -1540.47949, 22.63132,   0.00000, 0.00000, 36.05999);
	CreateObject(19869, 2507.82153, -1544.52051, 22.63132,   0.00000, 0.00000, 1.14000);
	CreateObject(19869, 2523.81079, -1542.48157, 22.63130,   84.00000, 0.00000, 19.00000);
	CreateObject(19869, 2536.28857, -1516.38538, 22.94130,   0.15500, 0.00000, -26.88000);
	CreateObject(19869, 2504.23169, -1542.23181, 22.63132,   0.00000, 0.00000, -69.47997);
	CreateObject(19869, 2503.51978, -1537.21582, 22.63132,   0.00000, 0.00000, -94.85997);
	CreateObject(19869, 2529.56763, -1542.08704, 22.63132,   0.00000, 0.00000, 1.14000);
	CreateObject(18248, 2523.94434, -1549.06042, 30.39830,   0.00000, 0.00000, -197.57997);
	CreateObject(3594, 2252.06177, -1660.71875, 14.60670,   0.00000, 0.00000, 97.26000);
	CreateObject(3594, 2260.02173, -1661.36890, 14.60670,   0.00000, 0.00000, 75.66002);
	CreateObject(3594, 2083.61938, -1772.47864, 12.91750,   0.00000, 0.00000, -10.86000);
	CreateObject(3594, 2081.76123, -1779.62268, 12.91750,   0.00000, 0.00000, -10.86000);
	CreateObject(3594, 2080.04053, -1786.96619, 12.91750,   0.00000, 0.00000, -10.86000);
	CreateObject(3594, 2082.78076, -1793.15417, 12.91750,   0.00000, 0.00000, 218.03998);
	CreateObject(3594, 1939.48059, -1777.09888, 12.70730,   0.00000, 0.00000, 3.72000);
	CreateObject(3594, 1911.15002, -1776.30347, 13.04360,   0.00000, 0.00000, 3.30000);
	CreateObject(3594, 1810.34070, -1735.45129, 12.81020,   0.00000, 0.00000, 94.56000);
	CreateObject(3594, 1803.21252, -1735.63977, 12.81020,   0.00000, 0.00000, 94.56000);
	CreateObject(3594, 1817.38379, -1737.68787, 12.81020,   0.00000, 0.00000, 58.02001);
	CreateObject(3594, 1819.62366, -1744.97327, 12.81020,   0.00000, 0.00000, 3.72002);
	CreateObject(3594, 1824.75647, -1764.01599, 12.81020,   0.00000, 0.00000, -175.91994);
	CreateObject(3594, 1824.32825, -1755.97717, 12.81020,   0.00000, 0.00000, -173.09993);
	CreateObject(3594, 1818.53796, -1719.50867, 12.81020,   0.00000, 0.00000, 3.53998);
	CreateObject(1457, 2518.62891, -1518.93518, 24.50730,   0.00000, 0.00000, 44.10000);
	CreateObject(2960, -83.02850, -1580.95984, 1.99780,   0.00000, 0.00000, 0.00000);
	CreateObject(2960, -83.73494, -1582.70056, 1.99780,   0.00000, 0.00000, 30.42000);
	CreateObject(2960, -82.88313, -1579.14136, 1.99780,   0.00000, 0.00000, 23.82001);
	CreateObject(2960, -79.55781, -1577.97119, 1.99780,   0.00000, 0.00000, 96.47999);
	CreateObject(3287, -64.81883, -1540.08691, 6.15680,   0.00000, 0.00000, 63.06000);
	CreateObject(3865, -73.79620, -1541.11487, 3.21850,   0.00000, 0.00000, 10.56000);
	CreateObject(3865, -70.64041, -1549.30554, 3.21850,   0.00000, 0.00000, 83.34000);
	CreateObject(8879, -61.55694, -1553.80591, 7.53430,   0.00000, 0.00000, 188.81990);
	CreateObject(1383, -84.21690, -1604.41296, 33.88760,   0.00000, 0.00000, 0.00000);
	CreateObject(1384, -84.40128, -1604.37305, 65.77560,   0.00000, 0.00000, 0.00000);
	CreateObject(3865, -82.94020, -1614.33435, 5.68830,   0.00000, 0.00000, -62.46000);
	CreateObject(1238, -78.05722, -1615.74683, 2.70180,   0.00000, 0.00000, 0.00000);
	CreateObject(1238, -82.57475, -1618.28125, 2.70180,   0.00000, 0.00000, 0.00000);
	CreateObject(1238, -87.38892, -1620.54858, 2.70180,   0.00000, 0.00000, 0.00000);
	CreateObject(1238, -92.25194, -1619.38135, 2.70180,   0.00000, 0.00000, 0.00000);
	CreateObject(1238, -73.88208, -1611.15100, 2.70180,   0.00000, 0.00000, 0.00000);
	CreateObject(19313, -72.31623, -1605.36572, 4.71740,   0.00000, 0.00000, 34.31999);
	CreateObject(19313, -61.43906, -1596.49854, 4.71740,   0.00000, 0.00000, 44.34000);
	CreateObject(19313, -52.24089, -1585.91589, 4.71740,   0.00000, 0.00000, 54.00000);
	CreateObject(986, -51.48637, -1574.09363, 1.74390,   -91.00000, -11.00000, 61.39999);
	CreateObject(3504, -53.39280, -1546.45837, 2.83570,   0.00000, 0.00000, -42.48000);
	CreateObject(3504, -52.35969, -1547.39807, 2.83570,   0.00000, -0.40000, -42.48000);
	CreateObject(3504, -54.43158, -1545.51074, 2.83570,   0.00000, 0.00000, -42.48000);
	//АЗС
	CreateObject(1211, 1951.68750, -1777.22900, 12.96130,   0.00000, 0.00000, 0.00000);
	CreateObject(1257, 1923.13611, -1758.63672, 13.60180,   0.00000, 0.00000, -89.46000);
	CreateObject(3569, 1923.20959, -1791.31165, 14.66330,   0.00000, 0.00000, 90.36000);
	CreateObject(970, 1929.41089, -1762.30249, 13.06590,   0.00000, 0.00000, 0.00000);
	CreateObject(970, 1925.25146, -1762.30957, 13.06590,   0.00000, 0.00000, 0.00000);
	CreateObject(970, 1921.11096, -1762.30750, 13.06590,   0.00000, 0.00000, 0.00000);
	CreateObject(970, 1916.95776, -1762.30212, 13.06590,   0.00000, 0.00000, 0.00000);
	CreateObject(970, 1931.50024, -1764.36340, 13.06590,   0.00000, 0.00000, 90.29997);
	CreateObject(910, 1913.83582, -1767.96423, 13.45046,   0.00000, 0.00000, -89.82000);
	CreateObject(1346, 1928.90161, -1767.06860, 13.78980,   0.00000, 0.00000, 89.58002);
	//Трейлер парк
	CreateObject(1412, 1864.07153, -1836.50769, 13.81190,   0.00000, 0.00000, -16.92000);
	CreateObject(1412, 1874.15881, -1839.57080, 13.81190,   0.00000, 0.00000, -16.92000);
	CreateObject(1412, 1879.20032, -1841.10376, 13.81190,   0.00000, 0.00000, -16.92000);
	CreateObject(1412, 1889.17444, -1844.12622, 13.81190,   0.00000, 0.00000, -16.92000);
	CreateObject(1412, 1894.19617, -1845.64099, 13.81190,   0.00000, 0.00000, -16.92000);
	CreateObject(1412, 1899.33411, -1846.80298, 13.81190,   0.00000, 0.00000, -8.33999);
	CreateObject(1413, 1884.15613, -1842.53601, 13.82260,   0.00000, 0.00000, 163.02000);
	CreateObject(1413, 1869.15186, -1837.98035, 13.82260,   0.00000, 0.00000, 163.02000);
	CreateObject(3172, 1886.98071, -1846.88208, 12.55630,   0.00000, 0.00000, 74.45998);
	CreateObject(3171, 1872.36084, -1875.68652, 12.55303,   0.00000, 0.00000, -145.13991);
	CreateObject(3174, 1872.92712, -1864.76196, 12.41030,   0.31200, 0.00000, 149.94000);
	CreateObject(759, 1870.52380, -1870.03320, 12.51200,   0.00000, 0.00000, 0.00000);
	CreateObject(3171, 1892.21667, -1855.71863, 12.55303,   0.00000, 0.00000, -289.01990);
	CreateObject(1308, 1897.26978, -1848.32495, 11.69240,   0.00000, 0.00000, 0.00000);
	CreateObject(3173, 1870.90588, -1855.73706, 12.48730,   0.00000, 0.00000, -90.05999);
	CreateObject(3170, 1870.65222, -1844.69324, 12.44620,   0.00000, 0.00000, -90.42001);
	CreateObject(3169, 1894.27478, -1864.96619, 12.29610,   0.00000, 0.00000, -109.19999);
	CreateObject(1334, 1900.51611, -1873.39612, 13.55610,   0.10400, 0.00000, 89.82001);
	CreateObject(1334, 1900.54846, -1876.72058, 13.55610,   0.10400, 0.00000, 89.82001);
	CreateObject(759, 1898.11267, -1851.16541, 12.51200,   0.00000, 0.00000, 0.00000);
	CreateObject(3171, 1892.21667, -1855.71863, 12.55303,   0.00000, 0.00000, -289.01990);
	CreateObject(1440, 1877.67346, -1878.61414, 13.01950,   0.00000, 0.00000, 176.09993);
	CreateObject(1297, 1879.54614, -1837.76685, 15.74940,   0.00000, 0.00000, 76.62002);
	CreateObject(1297, 1900.32568, -1879.11829, 15.74940,   0.00000, 0.00000, -20.09999);
	CreateObject(18664, 1929.73572, -1789.58032, 15.31430,   0.00000, 0.00000, -89.93989);
	CreateObject(1281, 1884.89990, -1876.70117, 13.25810,   0.00000, 0.00000, 2.22000);
	CreateObject(1281, 2111.17407, -1911.71069, 13.31450,   0.00000, 0.00000, 16.68000);
	CreateObject(1281, 2125.27075, -1912.23901, 13.31450,   0.00000, 0.00000, -19.32000);
	CreateObject(1281, 2118.95508, -1924.03723, 13.31450,   0.00000, 0.00000, -19.32000);
	CreateObject(1237, 1843.34045, -1857.61719, 12.24310,   0.00000, 0.00000, 0.00000);
	CreateObject(1237, 1843.36426, -1854.95618, 12.24310,   0.00000, 0.00000, 0.00000);
	CreateObject(3593, 1847.77930, -1856.32080, 12.72390,   0.00000, 0.00000, 89.82000);
	CreateObject(1237, 489.35718, -1735.60645, 10.14117,   0.00000, 0.00000, 0.00000);
	CreateObject(1237, 486.60550, -1735.07520, 10.14117,   0.00000, 0.00000, 0.00000);
	CreateObject(3593, 487.20731, -1740.36670, 10.48350,   0.00000, 0.00000, -8.40000);
	CreateObject(1237, 1023.55768, -1029.38257, 31.18270,   0.00000, 0.00000, 0.00000);
	CreateObject(1237, 1026.38062, -1029.41797, 31.18270,   0.00000, 0.00000, 0.00000);
	CreateObject(3593, 1025.01001, -1024.18774, 31.39740,   0.00000, 0.00000, 0.00000);
	CreateObject(3593, 1041.61707, -1021.25665, 31.39740,   0.00000, 0.00000, 0.00000);
	CreateObject(1237, 1040.13977, -1026.21204, 31.18270,   0.00000, 0.00000, 0.00000);
	CreateObject(1237, 1042.82141, -1026.21301, 31.18270,   0.00000, 0.00000, 0.00000);
	CreateObject(1237, 2071.51147, -1832.66772, 12.35140,   0.00000, 0.00000, 0.00000);
	CreateObject(1237, 2071.50781, -1830.16394, 12.35140,   0.00000, 0.00000, 0.00000);
	//Паломино крик
	CreateObject(7347, 2001.13928, -57.03912, -40.63500,   0.00000, 0.00000, -179.39993);
	CreateObject(935, 2017.35645, -37.28010, -0.00620,   0.00000, 113.00000, 0.00000);
	CreateObject(935, 2014.63379, -39.73873, -0.00620,   0.00000, 113.00000, 175.26006);
	CreateObject(2669, 2165.49316, -119.33640, 2.13960,   2.00000, 11.00000, 257.00000);
	CreateObject(935, 2167.50220, -120.44348, 1.11590,   84.00000, 0.00000, 0.00000);
	CreateObject(935, 2167.11719, -119.05445, 1.11590,   84.00000, 0.00000, 118.74000);
	CreateObject(727, 1864.62939, -1839.18018, 12.28000,   0.00000, 0.00000, 0.00000);
	CreateObject(3567, 2097.72192, 45.12920, 25.97880,   0.00000, 0.00000, 90.42000);
	CreateObject(1238, 2114.69263, 45.19133, 25.63050,   0.00000, 0.00000, 0.00000);
	CreateObject(1238, 2086.92041, 45.11901, 25.63050,   0.00000, 0.00000, 0.00000);
	CreateObject(1238, 2097.21802, 42.10262, 25.63050,   0.00000, 0.00000, 0.00000);
	CreateObject(1238, 2104.28735, 42.38609, 25.63050,   0.00000, 0.00000, 0.00000);
	CreateObject(1238, 2090.97144, 42.29096, 25.63050,   0.00000, 0.00000, 0.00000);
	CreateObject(3502, 2094.42871, 45.11134, 28.65580,   0.00000, 0.00000, 90.24000);
	CreateObject(3502, 2108.47998, 44.79285, 27.92780,   11.00000, 0.00000, 90.00000);
	CreateObject(1238, 2110.96606, 42.17000, 25.63050,   0.00000, 0.00000, 0.00000);
	CreateObject(3502, 1971.13672, -21.80804, 1.61911,   0.00000, 0.00000, 40.67999);
	// Забор ЛС:
	CreateObject(5076, 1367.39063, -2489.52515, 10.10330,   -0.43800, -87.15300, 0.00000);
	CreateObject(5005, 1646.50488, -2391.00415, 13.25460,   68.88100, -0.08500, 0.00000);
	
	CreateObject(11458,1260.799,-1250.986,12.245,-1.999,-1.000,29.965);
    CreateObject(5709,1301.189,-1257.060,21.507,0.000,0.000,0.000);
    CreateObject(11443,1234.364,-1296.329,12.354,-0.500,-6.500,101.199);
    CreateObject(3567,1200.372,-1321.375,13.288,0.000,0.000,-65.199);
    CreateObject(12957,1267.191,-1279.526,13.027,4.400,5.000,-45.799);
    CreateObject(13591,1270.810,-1337.877,12.431,-0.200,0.899,-96.800);
    CreateObject(3594,1281.660,-1357.565,12.960,0.299,0.000,-26.099);
    CreateObject(3593,1285.816,-1309.018,13.579,1.000,-45.400,3.599);
    CreateObject(1369,1182.857,-1319.487,13.170,-0.299,-1.699,53.899);
    CreateObject(1369,1177.989,-1325.370,13.493,-1.700,89.300,115.600);
    CreateObject(817,1243.199,-1305.356,12.477,0.000,0.000,0.000);
    CreateObject(817,1237.804,-1304.104,12.363,0.000,0.000,0.000);
    CreateObject(817,1229.988,-1306.734,12.436,0.000,0.000,0.000);
    CreateObject(817,1225.125,-1305.016,12.476,0.000,0.000,0.000);
    CreateObject(817,1219.168,-1335.037,12.483,0.000,0.000,0.000);
    CreateObject(817,1219.732,-1340.858,12.488,0.000,0.000,0.000);
    CreateObject(817,1220.546,-1349.270,12.494,0.000,0.000,0.000);
    CreateObject(817,1217.230,-1338.833,12.781,0.000,0.000,0.000);
    CreateObject(817,1220.926,-1338.122,12.487,0.000,0.000,0.000);
    CreateObject(817,1220.159,-1336.672,12.484,0.000,0.000,0.000);
    CreateObject(817,1219.584,-1340.239,12.487,0.000,0.000,0.000);
    CreateObject(817,1217.913,-1338.574,12.487,0.000,0.000,0.000);
    CreateObject(817,1241.276,-1296.117,12.331,0.000,0.000,0.000);
    CreateObject(817,1243.676,-1313.781,12.326,0.000,0.000,0.000);
    CreateObject(817,1241.421,-1326.557,12.354,0.000,0.000,0.000);
    CreateObject(817,1243.085,-1336.188,12.336,0.000,0.000,0.000);
    CreateObject(817,1240.755,-1342.348,12.357,0.000,0.000,0.000);
    CreateObject(817,1242.357,-1355.927,12.356,0.000,0.000,0.000);
    CreateObject(817,1224.015,-1297.643,12.476,0.000,0.000,0.000);
    CreateObject(817,1223.978,-1276.256,12.382,0.000,0.000,0.000);
    CreateObject(817,1177.640,-1268.003,14.186,0.000,0.000,0.000);
    CreateObject(817,1179.565,-1296.630,13.225,0.000,0.000,0.000);
    CreateObject(817,1182.796,-1303.782,13.236,0.000,0.000,0.000);
    CreateObject(817,1180.086,-1316.849,12.575,0.000,0.000,0.000);
    CreateObject(817,1177.412,-1329.429,13.093,0.000,0.000,0.000);
    CreateObject(762,1230.494,-1306.151,12.432,0.000,0.000,0.000);
    CreateObject(762,1201.191,-1245.971,14.320,0.000,0.000,0.000);
    CreateObject(762,1239.149,-1326.151,12.369,0.000,0.000,0.000);
    CreateObject(762,1229.889,-1344.506,13.144,0.000,0.000,0.000);
    CreateObject(762,1221.049,-1369.910,12.415,0.000,0.000,0.000);
    CreateObject(762,1228.261,-1378.949,12.343,0.000,0.000,0.000);
    CreateObject(762,1241.072,-1369.930,12.360,0.000,0.000,0.000);
    CreateObject(762,1241.938,-1348.206,12.350,0.000,0.000,0.000);
    CreateObject(1358,1157.849,-1203.903,19.589,-4.499,-0.800,-10.299);
    CreateObject(832,1231.385,-1321.402,14.514,0.000,0.000,0.000);
    CreateObject(1431,1144.510,-1201.905,18.828,0.000,0.000,0.000);
    CreateObject(3504,1189.074,-1205.187,19.736,2.000,1.300,11.799);
    CreateObject(3091,1213.826,-1208.279,18.298,-2.699,0.000,27.199);
    CreateObject(3091,1218.780,-1202.797,18.889,-88.799,0.599,-21.900);
    CreateObject(3091,1109.808,-1283.164,13.007,0.000,-0.599,82.699);
    CreateObject(1238,1052.048,-1311.282,12.722,0.000,0.000,0.000);
    CreateObject(1238,1054.350,-1319.677,12.535,89.999,-62.599,-4.400);
    CreateObject(1238,1063.168,-1311.635,12.699,0.000,0.000,0.000);
    CreateObject(1232,982.551,-1314.413,12.801,94.199,-24.899,-0.399);
    CreateObject(3594,1007.237,-1351.469,12.800,0.000,0.000,-29.000);
    CreateObject(1237,1064.628,-1216.893,15.898,0.000,0.000,0.000);
    CreateObject(1237,1064.628,-1219.237,15.920,0.000,0.000,0.000);
    CreateObject(1237,1064.614,-1218.164,15.871,0.000,0.000,0.000);
    CreateObject(1413,1077.801,-1204.556,18.410,0.000,0.000,-95.800);
    CreateObject(1413,1077.086,-1209.791,18.356,0.000,0.000,-95.599);
    CreateObject(3006,1076.795,-1209.193,16.077,11.700,0.000,7.299);
    CreateObject(981,1350.528,-1272.053,13.292,0.000,0.000,0.000);
    CreateObject(1427,995.594,-1144.838,23.396,0.000,0.000,-92.700);
    CreateObject(1427,1002.532,-1137.452,23.136,0.000,0.000,-112.199);
    CreateObject(1427,997.605,-1151.031,23.297,0.000,0.000,100.200);
    CreateObject(3593,1103.316,-1137.744,22.986,0.000,0.000,-89.400);
    CreateObject(3593,1171.988,-1152.014,22.999,-0.100,177.700,80.199);
    CreateObject(1427,1165.569,-1148.935,23.116,0.000,0.000,-121.099);
    CreateObject(1427,1177.434,-1150.441,23.146,0.000,0.000,-66.600);
    CreateObject(926,1103.307,-1136.937,22.906,0.000,0.000,0.000);
    CreateObject(924,1101.798,-1137.950,23.556,0.000,0.000,0.000);
    CreateObject(3567,937.538,-1211.990,16.631,0.200,0.200,26.500);
    CreateObject(1427,939.773,-1193.678,18.009,0.000,0.000,-12.200);
    CreateObject(1427,948.038,-1221.024,16.195,0.000,0.000,83.400);
    CreateObject(1427,941.082,-1228.647,16.240,0.000,0.000,12.499);
	return true;
}