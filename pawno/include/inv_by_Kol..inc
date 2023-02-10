// eSelection.inc - Rewritten version of mSelection.inc
// Created for Interactive Roleplay - 17/03/2013 @ 10:20 PM.

#if !defined MAX_MENU_ITEMS
	#define MAX_MENU_ITEMS (54)
#endif

#if !defined MAX_CUSTOM_ROTATIONS
	#define MAX_CUSTOM_ROTATIONS (54)
#endif

#define MODEL_RESPONSE_CANCEL (0)
#define MODEL_RESPONSE_SELECT (1)

enum g_ePlayerMenuEnum {

	PlayerText:g_eMenuTextdraws[13],
	PlayerText:g_eMenuItems[18],
	PlayerText:g_eMenuAmounts[18],
	Float:g_eMenuRot[ 4 ],
	g_eMenuModels[MAX_MENU_ITEMS],
	g_eMenuAmount[MAX_MENU_ITEMS],
	g_eMenuTotalItems,
	g_eMenuPage,
	g_eMenuPages,
	g_eMenuShown,
	g_eMenuExtra,
	g_eMenuIgnore,
	g_eMenuTime,
	g_eMenuType

};

new g_eMenuItemNames[ MAX_PLAYERS ][ MAX_INVENTORY ][ 32 ];

enum g_eItemRotationEnum {

	g_eItemModel,
	Float:g_eItemRotX,
	Float:g_eItemRotY,
	Float:g_eItemRotZ,
	Float:g_eItemZoom
};

static stock
	g_ePlayerMenuData[MAX_PLAYERS][g_ePlayerMenuEnum],
	g_eMenuCustomRotation[MAX_CUSTOM_ROTATIONS][g_eItemRotationEnum]
;

static const g_arrVehicleColors[256] = {
	0x000000FF, 0xF5F5F5FF, 0x2A77A1FF, 0x840410FF, 0x263739FF, 0x86446EFF, 0xD78E10FF, 0x4C75B7FF, 0xBDBEC6FF, 0x5E7072FF,
	0x46597AFF, 0x656A79FF, 0x5D7E8DFF, 0x58595AFF, 0xD6DAD6FF, 0x9CA1A3FF, 0x335F3FFF, 0x730E1AFF, 0x7B0A2AFF, 0x9F9D94FF,
	0x3B4E78FF, 0x732E3EFF, 0x691E3BFF, 0x96918CFF, 0x515459FF, 0x3F3E45FF, 0xA5A9A7FF, 0x635C5AFF, 0x3D4A68FF, 0x979592FF,
	0x421F21FF, 0x5F272BFF, 0x8494ABFF, 0x767B7CFF, 0x646464FF, 0x5A5752FF, 0x252527FF, 0x2D3A35FF, 0x93A396FF, 0x6D7A88FF,
	0x221918FF, 0x6F675FFF, 0x7C1C2AFF, 0x5F0A15FF, 0x193826FF, 0x5D1B20FF, 0x9D9872FF, 0x7A7560FF, 0x989586FF, 0xADB0B0FF,
	0x848988FF, 0x304F45FF, 0x4D6268FF, 0x162248FF, 0x272F4BFF, 0x7D6256FF, 0x9EA4ABFF, 0x9C8D71FF, 0x6D1822FF, 0x4E6881FF,
	0x9C9C98FF, 0x917347FF, 0x661C26FF, 0x949D9FFF, 0xA4A7A5FF, 0x8E8C46FF, 0x341A1EFF, 0x6A7A8CFF, 0xAAAD8EFF, 0xAB988FFF,
	0x851F2EFF, 0x6F8297FF, 0x585853FF, 0x9AA790FF, 0x601A23FF, 0x20202CFF, 0xA4A096FF, 0xAA9D84FF, 0x78222BFF, 0x0E316DFF,
	0x722A3FFF, 0x7B715EFF, 0x741D28FF, 0x1E2E32FF, 0x4D322FFF, 0x7C1B44FF, 0x2E5B20FF, 0x395A83FF, 0x6D2837FF, 0xA7A28FFF,
	0xAFB1B1FF, 0x364155FF, 0x6D6C6EFF, 0x0F6A89FF, 0x204B6BFF, 0x2B3E57FF, 0x9B9F9DFF, 0x6C8495FF, 0x4D8495FF, 0xAE9B7FFF,
	0x406C8FFF, 0x1F253BFF, 0xAB9276FF, 0x134573FF, 0x96816CFF, 0x64686AFF, 0x105082FF, 0xA19983FF, 0x385694FF, 0x525661FF,
	0x7F6956FF, 0x8C929AFF, 0x596E87FF, 0x473532FF, 0x44624FFF, 0x730A27FF, 0x223457FF, 0x640D1BFF, 0xA3ADC6FF, 0x695853FF,
	0x9B8B80FF, 0x620B1CFF, 0x5B5D5EFF, 0x624428FF, 0x731827FF, 0x1B376DFF, 0xEC6AAEFF, 0x000000FF, 0x177517FF, 0x210606FF,
	0x125478FF, 0x452A0DFF, 0x571E1EFF, 0x010701FF, 0x25225AFF, 0x2C89AAFF, 0x8A4DBDFF, 0x35963AFF, 0xB7B7B7FF, 0x464C8DFF,
	0x84888CFF, 0x817867FF, 0x817A26FF, 0x6A506FFF, 0x583E6FFF, 0x8CB972FF, 0x824F78FF, 0x6D276AFF, 0x1E1D13FF, 0x1E1306FF,
	0x1F2518FF, 0x2C4531FF, 0x1E4C99FF, 0x2E5F43FF, 0x1E9948FF, 0x1E9999FF, 0x999976FF, 0x7C8499FF, 0x992E1EFF, 0x2C1E08FF,
	0x142407FF, 0x993E4DFF, 0x1E4C99FF, 0x198181FF, 0x1A292AFF, 0x16616FFF, 0x1B6687FF, 0x6C3F99FF, 0x481A0EFF, 0x7A7399FF,
	0x746D99FF, 0x53387EFF, 0x222407FF, 0x3E190CFF, 0x46210EFF, 0x991E1EFF, 0x8D4C8DFF, 0x805B80FF, 0x7B3E7EFF, 0x3C1737FF,
	0x733517FF, 0x781818FF, 0x83341AFF, 0x8E2F1CFF, 0x7E3E53FF, 0x7C6D7CFF, 0x020C02FF, 0x072407FF, 0x163012FF, 0x16301BFF,
	0x642B4FFF, 0x368452FF, 0x999590FF, 0x818D96FF, 0x99991EFF, 0x7F994CFF, 0x839292FF, 0x788222FF, 0x2B3C99FF, 0x3A3A0BFF,
	0x8A794EFF, 0x0E1F49FF, 0x15371CFF, 0x15273AFF, 0x375775FF, 0x060820FF, 0x071326FF, 0x20394BFF, 0x2C5089FF, 0x15426CFF,
	0x103250FF, 0x241663FF, 0x692015FF, 0x8C8D94FF, 0x516013FF, 0x090F02FF, 0x8C573AFF, 0x52888EFF, 0x995C52FF, 0x99581EFF,
	0x993A63FF, 0x998F4EFF, 0x99311EFF, 0x0D1842FF, 0x521E1EFF, 0x42420DFF, 0x4C991EFF, 0x082A1DFF, 0x96821DFF, 0x197F19FF,
	0x3B141FFF, 0x745217FF, 0x893F8DFF, 0x7E1A6CFF, 0x0B370BFF, 0x27450DFF, 0x071F24FF, 0x784573FF, 0x8A653AFF, 0x732617FF,
	0x319490FF, 0x56941DFF, 0x59163DFF, 0x1B8A2FFF, 0x38160BFF, 0x041804FF, 0x355D8EFF, 0x2E3F5BFF, 0x561A28FF, 0x4E0E27FF,
	0x706C67FF, 0x3B3E42FF, 0x2E2D33FF, 0x7B7E7DFF, 0x4A4442FF, 0x28344EFF
};

stock SetModelPreviewRotation(modelid, Float:x, Float:y, Float:z, Float:zoom = 1.5)
{
	for (new i = 0; i != MAX_CUSTOM_ROTATIONS; i ++) if (!g_eMenuCustomRotation[ i ][g_eItemModel]) {
		g_eMenuCustomRotation[ i ][g_eItemModel] = modelid;
		g_eMenuCustomRotation[ i ][g_eItemRotX] = x;
		g_eMenuCustomRotation[ i ][g_eItemRotY] = y;
		g_eMenuCustomRotation[ i ][g_eItemRotZ] = z;
		g_eMenuCustomRotation[ i ][g_eItemZoom] = zoom;

		break;
	}
	return 0;
}

stock show_inventory_tds( playerid, bool:show ) {

	if( show ) {

	    g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 0 ] = CreatePlayerTextDraw(playerid, 73.000000, 170.711135, "box");
		PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 0 ], 0.000000, 24.250038);
		PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 0 ], 554.000000, 0.000000);
		PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 0 ], 1);
		PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 0 ], -1);
		PlayerTextDrawUseBox(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 0 ], 1);
		PlayerTextDrawBoxColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 0 ], 370414591);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 0 ], 0);
		PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 0 ], 0);
		PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 0 ], 255);
		PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 0 ], 0);
		PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 0 ], 1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 0 ], 0);

		g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 1 ] = CreatePlayerTextDraw(playerid, 171.000000, 175.066650, "box");
		PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 1 ], 0.000000, 0.999997);
		PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 1 ], 551.000000, 0.000000);
		PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 1 ], 1);
		PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 1 ], -1);
		PlayerTextDrawUseBox(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 1 ], 1);
		PlayerTextDrawBoxColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 1 ], 8388607);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 1 ], 0);
		PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 1 ], 0);
		PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 1 ], 255);
		PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 1 ], 1);
		PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 1 ], 1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 1 ], 0);

		new page[8];

		format(page, 8, "1/%d", g_ePlayerMenuData[ playerid ][g_eMenuPages] );

		g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 2 ] = CreatePlayerTextDraw(playerid, 510.500000, 174.444442, page );
		PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 2 ], 0.240997, 1.077332);
		PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 2 ], 2);
		PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 2 ], -1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 2 ], 0);
		PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 2 ], 1);
		PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 2 ], 255);
		PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 2 ], 2);
		PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 2 ], 1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 2 ], 0);

		g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 3 ] = CreatePlayerTextDraw(playerid, 537.500000, 174.288909, "ld_beat:right");
		PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 3 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 3 ], 12.000000, 11.000000);
		PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 3 ], 1);
		PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 3 ], -1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 3 ], 0);
		PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 3 ], 0);
		PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 3 ], 255);
		PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 3 ], 4);
		PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 3 ], 0);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 3 ], 0);
		PlayerTextDrawSetSelectable(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 3 ], true);

		g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 4 ] = CreatePlayerTextDraw(playerid, 471.500000, 174.288909, "ld_beat:left");
		PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 4 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 4 ], 12.000000, 11.000000);
		PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 4 ], 1);
		PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 4 ], -1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 4 ], 0);
		PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 4 ], 0);
		PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 4 ], 255);
		PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 4 ], 4);
		PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 4 ], 0);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 4 ], 0);
		PlayerTextDrawSetSelectable(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 4 ], true);

     	g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 5 ] = CreatePlayerTextDraw(playerid, 527.000000, 156.399963, "exit");
		PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 5 ], 0.240997, 1.077332);
		PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 5 ], 10.000000, 54.000000);
		PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 5 ], 2);
		PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 5 ], -1);
		PlayerTextDrawUseBox(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 5 ], 1);
		PlayerTextDrawBoxColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 5 ], 8388607);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 5 ], 0);
		PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 5 ], 1);
		PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 5 ], 255);
		PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 5 ], 2);
		PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 5 ], 1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 5 ], 0);
		PlayerTextDrawSetSelectable(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 5 ], true);

		g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 6 ] = CreatePlayerTextDraw(playerid, 109.000000, 156.399963, "inventar");
		PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 6 ], 0.240997, 1.077332);
		PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 6 ], 0.000000, 72.000000);
		PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 6 ], 2);
		PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 6 ], -1);
		PlayerTextDrawUseBox(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 6 ], 1);
		PlayerTextDrawBoxColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 6 ], 8388607);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 6 ], 0);
		PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 6 ], 1);
		PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 6 ], 255);
		PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 6 ], 2);
		PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 6 ], 1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 6 ], 0);

		g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 7 ] = CreatePlayerTextDraw(playerid, 172.500000, 174.444427, "predmeti");
		PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 7 ], 0.240997, 1.077332);
		PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 7 ], 1);
		PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 7 ], -1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 7 ], 0);
		PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 7 ], 1);
		PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 7 ], 255);
		PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 7 ], 2);
		PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 7 ], 1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 7 ], 0);

		g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][8] = CreatePlayerTextDraw(playerid, 73.500000, 189.222198, "");
		PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][8], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][8], 90.000000, 90.000000);
		PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][8], 1);
		PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][8], -1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][8], 0);
		PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][8], 0);
		PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][8], 96);
		PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][8], 5);
		PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][8], 0);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][8], 0);
		PlayerTextDrawSetPreviewModel(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][8], GetPlayerSkin( playerid ) );
		PlayerTextDrawSetPreviewRot(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][8], 0.000000, 0.000000, 0.000000, 1.000000);

		g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][9] = CreatePlayerTextDraw(playerid, 75.500000, 175.066650, "box");
		PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][9], 0.000000, 0.949998);
		PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][9], 162.000000, 0.000000);
		PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][9], 1);
		PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][9], -1);
		PlayerTextDrawUseBox(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][9], 1);
		PlayerTextDrawBoxColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][9], 8388607 );
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][9], 0);
		PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][9], 0);
		PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][9], 255);
		PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][9], 1);
		PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][9], 1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][9], 0);

		g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][10] = CreatePlayerTextDraw(playerid, 118.500000, 176.311096, ImeIgraca( playerid ) );
		PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][10], 0.179000, 0.710219);
		PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][10], 2);
		PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][10], -1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][10], 0);
		PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][10], 1);
		PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][10], 255);
		PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][10], 2);
		PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][10], 1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][10], 0);

		new string_new[ 256 ];

		new pol[ 7 ];
		if( PlayerInfo[ playerid ][ xPol ] == 1 ) pol = "Musko";
		else if( PlayerInfo[ playerid ][ xPol ] == 2 ) pol = "Zensko";

		format( string_new, sizeof( string_new ), "Starost:___%d~n~Pol:___%s~n~~n~Organizacija~n~Ime:_%s~n~Rank:_%s~n~~n~Posao~n~Ime:__%s~n~Ugovor:_%d/3",
		                    PlayerInfo[ playerid ][ xGodine ],
		                    pol,
							getOrgName( PlayerInfo[ playerid ][ xClan ] ),
							getOrgRank( playerid, PlayerInfo[ playerid ][ xClan ] ),
							getJobName( PlayerInfo[ playerid ][ xPosao ] ),
							PlayerInfo[ playerid ][ xUgovor ] );

		g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][11] = CreatePlayerTextDraw(playerid, 75.500000, 290.177825, string_new );
		PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][11], 0.155000, 0.940442);
		PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][11], 162.000000, 0.000000);
		PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][11], 1);
		PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][11], -1);
		PlayerTextDrawUseBox(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][11], 1);
		PlayerTextDrawBoxColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][11], 96);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][11], 0);
		PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][11], 1);
		PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][11], 255);
		PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][11], 2);
		PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][11], 1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][11], 0);

		new skin_str[ 10 ];
		format( skin_str, sizeof( skin_str ), "%d",  GetPlayerSkin( playerid ) );
        g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][12] = CreatePlayerTextDraw(playerid, 162.000000, 271.511199, skin_str );
		PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][12], 0.148497, 0.753776);
		PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][12], 3);
		PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][12], -1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][12], 0);
		PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][12], 1);
		PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][12], 255);
		PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][12], 2);
		PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][12], 1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][12], 0);


		//
		/*
	    g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 0 ] = CreatePlayerTextDraw(playerid, 413.500000, 62.911102, "");
		PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 0 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 0 ], 69.000000, 54.000000);
		PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 0 ], 1);
		PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 0 ], -1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 0 ], 0);
		PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 0 ], 0);
		PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 0 ], 96);
		PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 0 ], 5);
		PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 0 ], 0);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 0 ], 0);
		PlayerTextDrawSetSelectable(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 0 ], 1);
		PlayerTextDrawSetPreviewModel(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 0 ], clothes_info[ playerid ][ x_slot_1_model ] );
		PlayerTextDrawSetPreviewRot(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 0 ], 0.000000, 270.000000, 270.000000, 1.000000);
		g_ePlayerMenuData[ playerid ][g_eMenuClothesModel][ 0 ] = clothes_info[ playerid ][ x_slot_1_model ];


		g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 1 ] = CreatePlayerTextDraw(playerid, 483.500000, 62.911079, "");
		PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 1 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 1 ], 69.000000, 54.000000);
		PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 1 ], 1);
		PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 1 ], -1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 1 ], 0);
		PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 1 ], 0);
		PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 1 ], 96);
		PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 1 ], 5);
		PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 1 ], 0);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 1 ], 0);
		PlayerTextDrawSetSelectable(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 1 ], 1);
		PlayerTextDrawSetPreviewModel(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 1 ], clothes_info[ playerid ][ x_slot_2_model ] );
		PlayerTextDrawSetPreviewRot(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 1 ], 0.000000, 0.000000, 0.000000, 1.000000);
		g_ePlayerMenuData[ playerid ][g_eMenuClothesModel][ 1 ] = clothes_info[ playerid ][ x_slot_2_model ];

		g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 2 ] = CreatePlayerTextDraw(playerid, 413.500000, 117.044464, "");
		PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 2 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 2 ], 69.000000, 54.000000);
		PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 2 ], 1);
		PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 2 ], -1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 2 ], 0);
		PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 2 ], 0);
		PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 2 ], 96);
		PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 2 ], 5);
		PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 2 ], 0);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 2 ], 0);
		PlayerTextDrawSetSelectable(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 2 ], 1);
		PlayerTextDrawSetPreviewModel(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 2 ], clothes_info[ playerid ][ x_slot_3_model ] );
		PlayerTextDrawSetPreviewRot(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 2 ], 0.000000, 0.000000, 70.000000, 1.000000);
		g_ePlayerMenuData[ playerid ][g_eMenuClothesModel][ 2 ] = clothes_info[ playerid ][ x_slot_3_model ];

		g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 3 ] = CreatePlayerTextDraw(playerid, 483.500000, 117.044464, "");
		PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 3 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 3 ], 69.000000, 54.000000);
		PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 3 ], 1);
		PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 3 ], -1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 3 ], 0);
		PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 3 ], 0);
		PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 3 ], 96);
		PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 3 ], 5);
		PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 3 ], 0);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 3 ], 0);
		PlayerTextDrawSetSelectable(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 3 ], 1);
		PlayerTextDrawSetPreviewModel(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 3 ], clothes_info[ playerid ][ x_slot_4_model ] );
		PlayerTextDrawSetPreviewRot(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 3 ], 90.000000, 0.000000, 90.000000, 1.000000);
		g_ePlayerMenuData[ playerid ][g_eMenuClothesModel][ 3 ] = clothes_info[ playerid ][ x_slot_4_model ];*/



		// OVDE SE RAD98

	    for (new i = 0; i < 13; i ++) {
		    PlayerTextDrawShow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ i ]);
		}
		//for (new i = 0; i < 4; i ++) {
		  //  PlayerTextDrawShow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuClothes][ i ]);
		//}

		SelectTextDraw(playerid, SERVER_COLOR);

	}
	else if( !show ) {

	    if (!IsPlayerConnected(playerid) || !g_ePlayerMenuData[ playerid ][g_eMenuShown])
	    	return 0;

		for (new i = 0; i < 13; i ++) {
		    PlayerTextDrawHide(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ i ]);
		    PlayerTextDrawDestroy(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ i ]);
		    g_ePlayerMenuData[ playerid ][ g_eMenuTextdraws ][ i ] = PlayerText:INVALID_TEXT_DRAW;
		}

		for (new i = 0; i != MAX_MENU_ITEMS; i ++)
		{
		    if (i < 18)
		    {
		        if (g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ] != PlayerText:INVALID_TEXT_DRAW)
		        {
		            PlayerTextDrawDestroy(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ]);
	                g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ] = PlayerText:INVALID_TEXT_DRAW;
				}
		    	if (g_ePlayerMenuData[ playerid ][g_eMenuAmounts][ i ] != PlayerText:INVALID_TEXT_DRAW)
		    	{
	                PlayerTextDrawDestroy(playerid, g_ePlayerMenuData[ playerid ][g_eMenuAmounts][ i ]);
	                g_ePlayerMenuData[ playerid ][g_eMenuAmounts][ i ] = PlayerText:INVALID_TEXT_DRAW;
				}
			}
			g_ePlayerMenuData[ playerid ][g_eMenuModels][ i ] = -1;
			g_ePlayerMenuData[ playerid ][g_eMenuAmount][ i ] = 0;
		}
		g_ePlayerMenuData[ playerid ][g_eMenuShown] = false;
		g_ePlayerMenuData[ playerid ][g_eMenuTotalItems] = 0;
		g_ePlayerMenuData[ playerid ][g_eMenuExtra] = 0;
		g_ePlayerMenuData[ playerid ][g_eMenuPage] = 1;
		g_ePlayerMenuData[ playerid ][g_eMenuPages] = 0;
	    g_ePlayerMenuData[ playerid ][g_eMenuIgnore] = true;

		g_ePlayerMenuData[ playerid ][g_eMenuRot][ 0 ] = 0.0;
	    g_ePlayerMenuData[ playerid ][g_eMenuRot][ 1 ] = 0.0;
	    g_ePlayerMenuData[ playerid ][g_eMenuRot][ 2 ] = 0.0;
	    g_ePlayerMenuData[ playerid ][g_eMenuRot][ 3 ] = 0.0;

		CancelSelectTextDraw(playerid);
	}
	return true;
}

stock ShowModelESelectionMenu(playerid, extraid, items[], size = sizeof(items), Float:fRotX = 0.0, Float:fRotY = 0.0, Float:fRotZ = 0.0, Float:fZoom = 1.5, carcol = -1, bool:amount = false, amounts[] = {-1}, name_items[][] )
{
		if (!IsPlayerConnected(playerid))
		    return 0;

		if (size > MAX_MENU_ITEMS)
		    return printf("** Warning: Please increase \"MAX_MENU_ITEMS\" if you want to create more items.");

		if (g_ePlayerMenuData[ playerid ][g_eMenuShown])
		{
		    show_inventory_tds( playerid, false );
		}

		new new_size;
        for( new i = 0; i < MAX_INVENTORY; i++ ) {
			if( inventoryInfo[ playerid ][ i ][ invExists ] ) {
			    new_size++;
				strmid( g_eMenuItemNames[ playerid ][ i ], inventoryInfo[ playerid ][ i ][ invItem ], 0, strlen( inventoryInfo[ playerid ][ i ][ invItem ] ), 32 );
			}
			else {
				strmid( g_eMenuItemNames[ playerid ][ i ], "None", 0, strlen( "None" ), 32 );
			}
		}

	    g_ePlayerMenuData[ playerid ][g_eMenuExtra] = extraid;
		g_ePlayerMenuData[ playerid ][g_eMenuShown] = true;
		g_ePlayerMenuData[ playerid ][g_eMenuPage] = 1;
		g_ePlayerMenuData[ playerid ][g_eMenuPages] = (new_size / 18) + 1;
		g_ePlayerMenuData[ playerid ][g_eMenuTime] = GetTickCount();
		g_ePlayerMenuData[ playerid ][g_eMenuType] = 1;

	    g_ePlayerMenuData[ playerid ][g_eMenuRot][ 0 ] = fRotX;
	    g_ePlayerMenuData[ playerid ][g_eMenuRot][ 1 ] = fRotY;
	    g_ePlayerMenuData[ playerid ][g_eMenuRot][ 2 ] = fRotZ;
		g_ePlayerMenuData[ playerid ][g_eMenuRot][ 3 ] = fZoom;

	    show_inventory_tds( playerid, true );

    	for (new i = 0; i < 18; i ++) {
		    g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ] = PlayerText:INVALID_TEXT_DRAW;
			g_ePlayerMenuData[ playerid ][g_eMenuAmounts][ i ] = PlayerText:INVALID_TEXT_DRAW;
		}

		new
		    Float:x = 104.5,
		    Float:y = 189.222106;

	 	new str[64];

	 	for (new i = 0, idx = 0; i != MAX_MENU_ITEMS; i ++)
		{
	 		if (i >= size)
	 		{
	 	        g_ePlayerMenuData[ playerid ][g_eMenuModels][ i ] = -1;
	 	    }
	 	    else
			{
			    if (items[ i ] == -1)
				{
	                g_ePlayerMenuData[ playerid ][g_eMenuModels][ i ] = -1;
	                g_ePlayerMenuData[ playerid ][g_eMenuAmount][ i ] = 0;
	      		}
		  		else
		  		{
		   			g_ePlayerMenuData[ playerid ][g_eMenuTotalItems]++;
					g_ePlayerMenuData[ playerid ][g_eMenuModels][ i ] = items[ i ];

					if (amount) {
		                g_ePlayerMenuData[ playerid ][g_eMenuAmount][ i ] = amounts[ i ];
					}
				}
				if (i < 18 && items[ i ] != -1)
				{
					if (idx > 0 && (idx % 6) == 0)
					{
		   				x = 169.0;
		  	    		y += 67.50;
		  			}
		    		else
					{
		 	    		x += 64.50; // ex 67.50
		        	}
		        	idx++;

		        	if (i < 18 && items[ i ] != -1)
					{

					    g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ] = CreatePlayerTextDraw(playerid, x, y, "");

	                    PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], 0.000000, 0.000000);
						PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], 62.000000, 63.000000);
						PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], 1);
						PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], -1);
						PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], 0);
						PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], 0);
						PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], 0x00000060 );
						PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], 5);
						PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], 0);
						PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], 0);
						PlayerTextDrawSetSelectable(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], 1);
						PlayerTextDrawSetPreviewModel(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], items[ i ]);
						PlayerTextDrawSetPreviewRot(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], fRotX, fRotY, fRotZ, fZoom);// 1.500000);

						if (amount && amounts[ i ] != -1)
						{
						    format(str, sizeof(str), "%s(%d)", name_items[ i ], amounts[ i ]);

						    g_ePlayerMenuData[ playerid ][g_eMenuAmounts][ i ] = CreatePlayerTextDraw(playerid, x + 32.0, y + 54.0, str);

						    PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuAmounts][ i ], 0.165000, 0.766219);
							PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuAmounts][ i ], 2);
							PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuAmounts][ i ], -1);
							PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuAmounts][ i ], 0);
							PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuAmounts][ i ], 0);
							PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuAmounts][ i ], 255);
							PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuAmounts][ i ], 2);
							PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuAmounts][ i ], 1);
							PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuAmounts][ i ], 0);
						}
						else
						{
						    g_ePlayerMenuData[ playerid ][g_eMenuAmounts][ i ] = PlayerText:INVALID_TEXT_DRAW;
						}

	                    if (carcol != -1)
	                    {
							PlayerTextDrawSetPreviewVehCol(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], carcol, carcol);
						}
						for (new j = 0; j != MAX_CUSTOM_ROTATIONS; j ++)
						{
							if (g_eMenuCustomRotation[j][g_eItemModel] == items[ i ])
							{
								PlayerTextDrawSetPreviewRot(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], g_eMenuCustomRotation[j][g_eItemRotX], g_eMenuCustomRotation[j][g_eItemRotY], g_eMenuCustomRotation[j][g_eItemRotZ], g_eMenuCustomRotation[j][g_eItemZoom]);
								break;
							}
						}
					}
				}
			}
		}

		for (new i = 0; i < 18; i ++) if (g_ePlayerMenuData[ playerid ][g_eMenuModels][ i ] != -1) {
		    PlayerTextDrawShow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ]);

		    if (g_ePlayerMenuData[ playerid ][g_eMenuAmounts][ i ] != PlayerText:INVALID_TEXT_DRAW) {
		        PlayerTextDrawShow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuAmounts][ i ]);
			}
		}


		return 1;
}

stock ShowColorSelectionMenu(playerid, extraid, colors[], size = sizeof(colors))
{
		if (!IsPlayerConnected(playerid))
		    return 0;

		if (size > MAX_MENU_ITEMS)
		    return printf("** Warning: Please increase \"MAX_MENU_ITEMS\" if you want to create more items.");

		if (g_ePlayerMenuData[ playerid ][g_eMenuShown])
		{
		    show_inventory_tds( playerid, false );
		}
		for (new i = 0; i < 18; i ++) {
		    g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ] = PlayerText:INVALID_TEXT_DRAW;
			g_ePlayerMenuData[ playerid ][g_eMenuAmounts][ i ] = PlayerText:INVALID_TEXT_DRAW;
		}
		new
		    Float:x = 104.5,
			Float:y = 189.222106,
			page[8];

		format(page, 8, "1/%d", (size / 18) + 1);

	 	for (new i = 0, idx = 0; i != MAX_MENU_ITEMS; i ++)
		{
	 	    if (i >= size)
			{
	 	        g_ePlayerMenuData[ playerid ][g_eMenuModels][ i ] = -1;
	 	    }
	 	    else
			{
			    if (colors[ i ] == -1)
				{
	                g_ePlayerMenuData[ playerid ][g_eMenuModels][ i ] = -1;
	      		}
		  		else
			 	{
		   			g_ePlayerMenuData[ playerid ][g_eMenuTotalItems]++;
					g_ePlayerMenuData[ playerid ][g_eMenuModels][ i ] = colors[ i ];
				}
				if (idx < 18 && colors[ i ] != -1)
				{
					if (idx > 0 && (idx % 6) == 0)
					{
		   				x = 169.0;
			  	    	y += 67.50;
		  			}
		    		else
					{
		 	    		x += 64.50;
		        	}
		        	idx++;

		        	if (colors[ i ] != -1)
					{
					    g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ] = CreatePlayerTextDraw(playerid, x, y, "_");

						/*PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], g_arrVehicleColors[colors[ i ]]);
						PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], 5);
						PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], 1.430000, 5.700000);
						PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], -1);
						PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], 1);
						PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], 1);
						PlayerTextDrawUseBox(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], 1);
						PlayerTextDrawBoxColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], 0);
						PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], 61.000000, 54.000000);
						PlayerTextDrawSetSelectable(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], 1);
						PlayerTextDrawSetPreviewModel(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], 19300);*/

						PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], 0.000000, 0.000000);
						PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], 62.000000, 63.000000);
						PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], 1);
						PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], -1);
						PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], 0);
						PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], 0);
						PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], g_arrVehicleColors[colors[ i ]] );
						PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], 5);
						PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], 0);
						PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], 0);
						PlayerTextDrawSetSelectable(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], 1);
						PlayerTextDrawSetPreviewModel(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ], 19300 );


						g_ePlayerMenuData[ playerid ][g_eMenuAmounts][ i ] = PlayerText:INVALID_TEXT_DRAW;
					}
				}
			}
		}
		g_ePlayerMenuData[ playerid ][g_eMenuExtra] = extraid;
		g_ePlayerMenuData[ playerid ][g_eMenuShown] = true;
		g_ePlayerMenuData[ playerid ][g_eMenuPage] = 1;
		g_ePlayerMenuData[ playerid ][g_eMenuPages] = (size / 18) + 1;
		g_ePlayerMenuData[ playerid ][g_eMenuTime] = GetTickCount();
		g_ePlayerMenuData[ playerid ][g_eMenuType] = 2;

		g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 0 ] = CreatePlayerTextDraw(playerid, 73.000000, 170.711135, "box");
		PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 0 ], 0.000000, 24.250038);
		PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 0 ], 554.000000, 0.000000);
		PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 0 ], 1);
		PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 0 ], -1);
		PlayerTextDrawUseBox(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 0 ], 1);
		PlayerTextDrawBoxColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 0 ], 370414591);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 0 ], 0);
		PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 0 ], 0);
		PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 0 ], 255);
		PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 0 ], 0);
		PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 0 ], 1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 0 ], 0);

		g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 1 ] = CreatePlayerTextDraw(playerid, 171.000000, 175.066650, "box");
		PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 1 ], 0.000000, 0.999997);
		PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 1 ], 551.000000, 0.000000);
		PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 1 ], 1);
		PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 1 ], -1);
		PlayerTextDrawUseBox(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 1 ], 1);
		PlayerTextDrawBoxColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 1 ], 8388607);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 1 ], 0);
		PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 1 ], 0);
		PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 1 ], 255);
		PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 1 ], 1);
		PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 1 ], 1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 1 ], 0);

		format(page, 8, "1/%d", g_ePlayerMenuData[ playerid ][g_eMenuPages] );

		g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 2 ] = CreatePlayerTextDraw(playerid, 510.500000, 174.444442, page );
		PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 2 ], 0.240997, 1.077332);
		PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 2 ], 2);
		PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 2 ], -1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 2 ], 0);
		PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 2 ], 1);
		PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 2 ], 255);
		PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 2 ], 2);
		PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 2 ], 1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 2 ], 0);

		g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 3 ] = CreatePlayerTextDraw(playerid, 537.500000, 174.288909, "ld_beat:right");
		PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 3 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 3 ], 12.000000, 11.000000);
		PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 3 ], 1);
		PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 3 ], -1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 3 ], 0);
		PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 3 ], 0);
		PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 3 ], 255);
		PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 3 ], 4);
		PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 3 ], 0);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 3 ], 0);
		PlayerTextDrawSetSelectable(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 3 ], true);

		g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 4 ] = CreatePlayerTextDraw(playerid, 471.500000, 174.288909, "ld_beat:left");
		PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 4 ], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 4 ], 12.000000, 11.000000);
		PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 4 ], 1);
		PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 4 ], -1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 4 ], 0);
		PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 4 ], 0);
		PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 4 ], 255);
		PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 4 ], 4);
		PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 4 ], 0);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 4 ], 0);
		PlayerTextDrawSetSelectable(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 4 ], true);

     	g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 5 ] = CreatePlayerTextDraw(playerid, 527.000000, 156.399963, "exit");
		PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 5 ], 0.240997, 1.077332);
		PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 5 ], 10.000000, 54.000000);
		PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 5 ], 2);
		PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 5 ], -1);
		PlayerTextDrawUseBox(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 5 ], 1);
		PlayerTextDrawBoxColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 5 ], 8388607);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 5 ], 0);
		PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 5 ], 1);
		PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 5 ], 255);
		PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 5 ], 2);
		PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 5 ], 1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 5 ], 0);
		PlayerTextDrawSetSelectable(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 5 ], true);

		g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 6 ] = CreatePlayerTextDraw(playerid, 109.000000, 156.399963, "inventar");
		PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 6 ], 0.240997, 1.077332);
		PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 6 ], 0.000000, 72.000000);
		PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 6 ], 2);
		PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 6 ], -1);
		PlayerTextDrawUseBox(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 6 ], 1);
		PlayerTextDrawBoxColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 6 ], 8388607);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 6 ], 0);
		PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 6 ], 1);
		PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 6 ], 255);
		PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 6 ], 2);
		PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 6 ], 1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 6 ], 0);

		g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 7 ] = CreatePlayerTextDraw(playerid, 172.500000, 174.444427, "predmeti");
		PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 7 ], 0.240997, 1.077332);
		PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 7 ], 1);
		PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 7 ], -1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 7 ], 0);
		PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 7 ], 1);
		PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 7 ], 255);
		PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 7 ], 2);
		PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 7 ], 1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 7 ], 0);

        g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][8] = CreatePlayerTextDraw(playerid, 73.500000, 189.222198, "");
		PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][8], 0.000000, 0.000000);
		PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][8], 90.000000, 90.000000);
		PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][8], 1);
		PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][8], -1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][8], 0);
		PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][8], 0);
		PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][8], 96);
		PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][8], 5);
		PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][8], 0);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][8], 0);
		PlayerTextDrawSetPreviewModel(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][8], GetPlayerSkin( playerid ) );
		PlayerTextDrawSetPreviewRot(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][8], 0.000000, 0.000000, 0.000000, 1.000000);

		g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][9] = CreatePlayerTextDraw(playerid, 75.500000, 175.066650, "box");
		PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][9], 0.000000, 0.949998);
		PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][9], 162.000000, 0.000000);
		PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][9], 1);
		PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][9], -1);
		PlayerTextDrawUseBox(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][9], 1);
		PlayerTextDrawBoxColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][9], 8388607 );
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][9], 0);
		PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][9], 0);
		PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][9], 255);
		PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][9], 1);
		PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][9], 1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][9], 0);

		g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][10] = CreatePlayerTextDraw(playerid, 118.500000, 176.311096, ImeIgraca( playerid ) );
		PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][10], 0.179000, 0.710219);
		PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][10], 2);
		PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][10], -1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][10], 0);
		PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][10], 1);
		PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][10], 255);
		PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][10], 2);
		PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][10], 1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][10], 0);

		new string_new[ 256 ];

		new pol[ 7 ];
		if( PlayerInfo[ playerid ][ xPol ] == 1 ) pol = "Musko";
		else if( PlayerInfo[ playerid ][ xPol ] == 2 ) pol = "Zensko";

		format( string_new, sizeof( string_new ), "Starost:___%d~n~Pol:___%s~n~~n~Organizacija~n~Ime:_%s~n~Rank:_%s~n~~n~Posao~n~Ime:__%s~n~Ugovor:_%d/3",
		                    PlayerInfo[ playerid ][ xGodine ],
		                    pol,
							getOrgName( PlayerInfo[ playerid ][ xClan ] ),
							getOrgRank( playerid, PlayerInfo[ playerid ][ xClan ] ),
							getJobName( PlayerInfo[ playerid ][ xPosao ] ),
							PlayerInfo[ playerid ][ xUgovor ] );

		g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][11] = CreatePlayerTextDraw(playerid, 75.500000, 290.177825, string_new );
		PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][11], 0.155000, 0.940442);
		PlayerTextDrawTextSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][11], 162.000000, 0.000000);
		PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][11], 1);
		PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][11], -1);
		PlayerTextDrawUseBox(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][11], 1);
		PlayerTextDrawBoxColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][11], 96);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][11], 0);
		PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][11], 1);
		PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][11], 255);
		PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][11], 2);
		PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][11], 1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][11], 0);

		new skin_str[ 10 ];
		format( skin_str, sizeof( skin_str ), "%d",  GetPlayerSkin( playerid ) );
        g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][12] = CreatePlayerTextDraw(playerid, 162.000000, 271.511199, skin_str );
		PlayerTextDrawLetterSize(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][12], 0.148497, 0.753776);
		PlayerTextDrawAlignment(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][12], 3);
		PlayerTextDrawColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][12], -1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][12], 0);
		PlayerTextDrawSetOutline(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][12], 1);
		PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][12], 255);
		PlayerTextDrawFont(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][12], 2);
		PlayerTextDrawSetProportional(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][12], 1);
		PlayerTextDrawSetShadow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][12], 0);

		for (new i = 0; i < 13; i ++) {
		    PlayerTextDrawShow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ i ]);
		}
		for (new i = 0; i < 18; i ++) if (g_ePlayerMenuData[ playerid ][g_eMenuModels][ i ] != -1) {
		    PlayerTextDrawShow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ]);

		    if (g_ePlayerMenuData[ playerid ][g_eMenuAmounts][ i ] != PlayerText:INVALID_TEXT_DRAW) {
		        PlayerTextDrawShow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuAmounts][ i ]);
			}
		}
		SelectTextDraw(playerid, SERVER_COLOR);
		return 1;
}

public OnPlayerClickTextDraw(playerid, Text:clickedid)
{
	if (g_ePlayerMenuData[ playerid ][g_eMenuIgnore] || (GetTickCount() - g_ePlayerMenuData[ playerid ][g_eMenuTime]) < 200)
	{
	    g_ePlayerMenuData[ playerid ][g_eMenuIgnore] = false;
	    return CallLocalFunction("MS_OnPlayerClickTextDraw", "dd", playerid, _:clickedid);
	}
	else if ((clickedid == Text:INVALID_TEXT_DRAW && g_ePlayerMenuData[ playerid ][g_eMenuShown]))
	{
	    CallLocalFunction("OnModelSelectionResponse", "ddddd", playerid, g_ePlayerMenuData[ playerid ][g_eMenuExtra], 0, 0, MODEL_RESPONSE_CANCEL);
	    show_inventory_tds( playerid, false );
	}
	return CallLocalFunction("MS_OnPlayerClickTextDraw", "dd", playerid, _:clickedid);
}

stock Menu_SetPage(playerid, page)
{
	if (g_ePlayerMenuData[ playerid ][g_eMenuShown])
	{
	    if (page < 1 || page > g_ePlayerMenuData[ playerid ][g_eMenuPages])
		    return 0;

	    new
			start = (18 * (page - 1)),
			str[64];

		for (new i = 0; i < 18; i ++) {
			PlayerTextDrawHide(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ]);
		}
		for (new i = start; i != start + 18 && i < MAX_MENU_ITEMS; i ++)
		{
  			if (g_ePlayerMenuData[ playerid ][g_eMenuModels][ i ] == -1)
  			{
     			PlayerTextDrawHide(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][i - start]);

		        if (g_ePlayerMenuData[ playerid ][g_eMenuAmounts][i - start] != PlayerText:INVALID_TEXT_DRAW)
				{
    			    PlayerTextDrawHide(playerid, g_ePlayerMenuData[ playerid ][g_eMenuAmounts][i - start]);
				}
			}
			else
			{
			    if (g_ePlayerMenuData[ playerid ][g_eMenuType] == 2)
				{
			        PlayerTextDrawSetPreviewModel(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][i - start], 19300);
			        PlayerTextDrawBackgroundColor(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][i - start], g_arrVehicleColors[g_ePlayerMenuData[ playerid ][g_eMenuModels][ i ]]);
			    }
			    else
				{
					PlayerTextDrawSetPreviewRot(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][i - start], g_ePlayerMenuData[ playerid ][g_eMenuRot][ 0 ], g_ePlayerMenuData[ playerid ][g_eMenuRot][ 1 ], g_ePlayerMenuData[ playerid ][g_eMenuRot][ 2 ], g_ePlayerMenuData[ playerid ][g_eMenuRot][ 3 ]);

				    for (new j = 0; j != MAX_CUSTOM_ROTATIONS; j ++)
					{
						if (g_eMenuCustomRotation[j][g_eItemModel] == g_ePlayerMenuData[ playerid ][g_eMenuModels][ i ])
						{
							PlayerTextDrawSetPreviewRot(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][i - start], g_eMenuCustomRotation[j][g_eItemRotX], g_eMenuCustomRotation[j][g_eItemRotY], g_eMenuCustomRotation[j][g_eItemRotZ], g_eMenuCustomRotation[j][g_eItemZoom]);
							break;
						}
					}
				    PlayerTextDrawSetPreviewModel(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][i - start], g_ePlayerMenuData[ playerid ][g_eMenuModels][ i ]);
				}
		        PlayerTextDrawHide(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][i - start]);
		        PlayerTextDrawShow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuItems][i - start]);

		        if (g_ePlayerMenuData[ playerid ][g_eMenuAmounts][i - start] != PlayerText:INVALID_TEXT_DRAW)
				{
				    format(str, sizeof(str), "%s(%d)", g_eMenuItemNames[ playerid ][ i ], g_ePlayerMenuData[ playerid ][g_eMenuAmount][ i ]);

					PlayerTextDrawSetString(playerid, g_ePlayerMenuData[ playerid ][g_eMenuAmounts][i - start], str);

					PlayerTextDrawHide(playerid, g_ePlayerMenuData[ playerid ][g_eMenuAmounts][i - start]);
			        PlayerTextDrawShow(playerid, g_ePlayerMenuData[ playerid ][g_eMenuAmounts][i - start]);
				}
			}
		}
	    g_ePlayerMenuData[ playerid ][g_eMenuPage] = page;

	    format(str, 8, "%d/%d", page, g_ePlayerMenuData[ playerid ][g_eMenuPages]);
	    PlayerTextDrawSetString(playerid, g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 2 ], str);
	}
	return 1;
}

public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
	/*if (!g_ePlayerMenuData[ playerid ][g_eMenuShown] || (GetTickCount() - g_ePlayerMenuData[ playerid ][g_eMenuTime]) < 600)
	{
		return CallLocalFunction("MS_OnPlayerClickPlayerTextDraw", "ii", playerid, _:playertextid);
	}*/
    if (playertextid == g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 5 ])
	{
	    if( g_ePlayerMenuData[ playerid ][g_eMenuShown]  ) {
        	//CallLocalFunction("OnModelSelectionResponse", "ddddd", playerid, g_ePlayerMenuData[ playerid ][g_eMenuExtra], 0, 0, MODEL_RESPONSE_CANCEL);
        	show_inventory_tds( playerid, false );
		}
	}
	else
	{
		if (playertextid == g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 3 ])
		{
			if (g_ePlayerMenuData[ playerid ][g_eMenuPage] == g_ePlayerMenuData[ playerid ][g_eMenuPages])
			    return 0;

			else
				Menu_SetPage(playerid, g_ePlayerMenuData[ playerid ][g_eMenuPage] + 1);
		}
		else if (playertextid == g_ePlayerMenuData[ playerid ][g_eMenuTextdraws][ 4 ])
		{
			if (g_ePlayerMenuData[ playerid ][g_eMenuPage] < 2)
			    return 0;

	        else
				Menu_SetPage(playerid, g_ePlayerMenuData[ playerid ][g_eMenuPage] - 1);
		}
		/*else if( playertextid == g_ePlayerMenuData[ playerid ][ g_eMenuTextdraws ][ 6 ] ) {

            static
			    items[ MAX_INVENTORY ],
				name_items[ MAX_INVENTORY ][ 32 ],
				amounts[ MAX_INVENTORY ];

		    for( new i = 0; i < MAX_INVENTORY; i++ ) {
		 		if( inventoryInfo[ playerid ][ i ][ invExists ] ) {
		   			items[ i ] = inventoryInfo[ playerid ][ i ][ invModel ];
					strmid( name_items[ i ], inventoryInfo[ playerid ][ i ][ invItem ], 0, strlen( inventoryInfo[ playerid ][ i ][ invItem ] ), 32 );
		   			amounts[ i ] = inventoryInfo[ playerid ][ i ][ invQuantity ];
				}
				else {
				    items[ i ] = -1;
				    strmid( name_items[ i ], "None", 0, strlen( "None" ), 32 );
				    amounts[ i ] = -1;
				}
			}

			ShowModelESelectionMenu(playerid, 1, items, sizeof(items), 0.0, 0.0, 0.0, 1.0, -1, true, amounts, name_items );

		}
		else if( playertextid == g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 0 ] ) {

			if( g_ePlayerMenuData[ playerid ][g_eMenuClothesModel][ 0 ] == -1 ) return SendErrorMessage( playerid, "Nemate nista od garderobe u slotu broj 1." );
	   		show_inventory_tds( playerid, false );
	   		chosen_clothes_slot[ playerid ] = 1;
		   	SPD( playerid, dialog_CLOTHESMENU, DSL, "Slot: 1", "Postavi na sebe\nSkini sa sebe\nIzmeni poziciju\nDaj predmet\nBaci predmet", "Odaberi", "Odustani");
        }
		else if( playertextid == g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 1 ] ) {

			if( g_ePlayerMenuData[ playerid ][g_eMenuClothesModel][ 1 ] == -1 ) return SendErrorMessage( playerid, "Nemate nista od garderobe u slotu broj 2." );
	   		show_inventory_tds( playerid, false );
	   		chosen_clothes_slot[ playerid ] = 2;
		   	SPD( playerid, dialog_CLOTHESMENU, DSL, "Slot: 2", "Postavi na sebe\nSkini sa sebe\nIzmeni poziciju\nDaj predmet\nBaci predmet", "Odaberi", "Odustani");
        }
        else if( playertextid == g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 2 ] ) {

			if( g_ePlayerMenuData[ playerid ][g_eMenuClothesModel][ 2 ] == -1 ) return SendErrorMessage( playerid, "Nemate nista od garderobe u slotu broj 3." );
	   		show_inventory_tds( playerid, false );
	   		chosen_clothes_slot[ playerid ] = 3;
		   	SPD( playerid, dialog_CLOTHESMENU, DSL, "Slot: 3", "Postavi na sebe\nSkini sa sebe\nIzmeni poziciju\nDaj predmet\nBaci predmet", "Odaberi", "Odustani");
		}
        else if( playertextid == g_ePlayerMenuData[ playerid ][g_eMenuClothes][ 3 ] ) {

			if( g_ePlayerMenuData[ playerid ][g_eMenuClothesModel][ 3 ] == -1 ) return SendErrorMessage( playerid, "Nemate nista od garderobe u slotu broj 4." );
	   		show_inventory_tds( playerid, false );
	   		chosen_clothes_slot[ playerid ] = 4;
		   	SPD( playerid, dialog_CLOTHESMENU, DSL, "Slot: 4", "Postavi na sebe\nSkini sa sebe\nIzmeni poziciju\nDaj predmet\nBaci predmet", "Odaberi", "Odustani");
		}*/
		else for (new i = 0; i < 18; i ++) {

		    if (g_ePlayerMenuData[ playerid ][g_eMenuItems][ i ] == playertextid ) {

		        new
					index = (i + (g_ePlayerMenuData[ playerid ][g_eMenuPage] - 1) * 18),
					extraid = g_ePlayerMenuData[ playerid ][g_eMenuExtra],
					modelid = g_ePlayerMenuData[ playerid ][g_eMenuModels][index];

	            show_inventory_tds( playerid, false );
		        CallLocalFunction("OnModelSelectionResponse", "ddddd", playerid, extraid, index, modelid, MODEL_RESPONSE_SELECT);
		        break;
		    }
		}
	}
	return CallLocalFunction("MS_OnPlayerClickPlayerTextDraw", "dd", playerid, _:playertextid);
}

#if defined _ALS_OnPlayerClickTextDraw
	#undef OnPlayerClickTextDraw
#else
	#define _ALS_OnPlayerClickTextDraw
#endif

#if defined _ALS_OnPlayerClickPlayerTD
	#undef OnPlayerClickPlayerTextDraw
#else
	#define _ALS_OnPlayerClickPlayerTD
#endif

#define OnPlayerClickTextDraw MS_OnPlayerClickTextDraw
#define OnPlayerClickPlayerTextDraw MS_OnPlayerClickPlayerTextDraw

forward MS_OnPlayerClickTextDraw(playerid, Text:clickedid);
forward MS_OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid);

forward OnModelSelectionResponse(playerid, extraid, index, modelid, response);