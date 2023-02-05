/*
	Advanced WAR System v1.0.0
		by Dimi

    Credits:
        dock;
		Y_Less;
*/
//-------------------------------[Includes]-------------------------------------

#include <a_samp>
#include <sscanf2>
#include <YSI\y_iterate>
#include <Pawn.CMD>

//-----------------------------[Definitions]------------------------------------

#define MAX_WARS                    										  20 // change
#define SPD                                                     ShowPlayerDialog
#define SCM                                                    SendClientMessage
#define DSL 												   DIALOG_STYLE_LIST
#define IPI 												   INVALID_PLAYER_ID
#define DSI                                                   DIALOG_STYLE_INPUT
#define DSMSG 												 DIALOG_STYLE_MSGBOX

#define SendErrorMessage(%0,%1) \
	SCM(%0, COLOR_RED, "ERROR | {FFFFFF} "%1)
	
#define COLOR_RED                                                     0xfa5555AA

#define COL_ORANGE           										  "{FFAF00}"
#define COL_WHITE          											  "{FFFFFF}"
#define COL_TEAM1           										  "{F81414}"
#define COL_TEAM2        											  "{0049FF}"

#define dialog_WAR															2106
#define dialog_WAR_CREATE_1												 	2107
#define dialog_WAR_CREATE_2											 	 	2108
#define dialog_WAR_CREATE_3											 	 	2109
#define dialog_WAR_CREATE_4												 	2110
#define dialog_WAR_CREATE_5											 	 	2111
#define dialog_WAR_CREATE_6													2112
#define dialog_WAR_CREATE_7											 	 	2113
#define dialog_WAR_CREATE_8											 	 	2114
#define dialog_WARINVITE													2115
#define dialog_WARUNINVITE													2116

//-----------------------------[News & Enums]-----------------------------------

new PlayerText:WARTextDraw[ MAX_PLAYERS ][ 9 ];

enum WAR {
	bool:warCreating,
    bool:warActive,
	warTeamScore[ 2 ],
	warGuns[ 4 ],
	warMap,
	warMapMembers,
	warTeamMembers[ 2 ],
	warTeamLeader[ 2 ],
	warTimer,
	warTimerSec,
	warTimerMin,
	warTimerTime
}
new WARInfo[ MAX_WARS ][ WAR ];

enum WARI {
	bool:warTeam[ 2 ],
	warKills,
	warDeaths,
	warID,
	Float:LastPosition[ 3 ],
	LastInterior,
	LastVirtualWorld
}
new WARPInfo[ MAX_PLAYERS ][ WARI ];

new CreatingWAR[ MAX_PLAYERS ];

new globalstring[ 128 ];

new Float:warMap1Team1[ 9 ][ 3 ] = {
	{ 1147.9226,2813.0664,10.8125 },
	{ 1148.4319,2809.7048,10.8203 },
	{ 1148.7649,2805.6304,10.8203 },
	{ 1151.0385,2800.8855,10.8203 },
	{ 1155.1233,2800.9697,10.8203 },
	{ 1155.0419,2805.0557,10.8203 },
	{ 1144.4396,2799.8264,10.8125 },
	{ 1139.9843,2806.2156,10.9688 },
	{ 1140.9631,2812.3542,10.9190 }
};

new Float:warMap1Team2[ 9 ][ 3 ] = {
	{ 1403.0447,2733.0447,10.8126 },
	{ 1410.5400,2737.9583,10.8203 },
	{ 1414.4192,2747.7236,10.8203 },
	{ 1411.3033,2757.2588,11.2597 },
	{ 1399.9032,2750.0581,10.8203 },
	{ 1391.1559,2744.3250,10.8203 },
	{ 1384.0992,2743.9656,10.8203 },
	{ 1388.7274,2728.1936,10.8203 },
	{ 1379.5826,2729.1980,10.8203 }
};

new Float:warMap2Team1[ 7 ][ 3 ] = {
	{ -972.6812,1096.0303,1344.9882 },
	{ -972.5949,1084.3115,1344.9950 },
	{ -973.4254,1076.6229,1344.9950 },
	{ -973.5809,1070.1228,1345.0007 },
	{ -973.7216,1064.7092,1345.0061 },
	{ -973.6556,1056.8405,1345.0156 },
	{ -973.0229,1024.2570,1345.0525 }
};

new Float:warMap2Team2[ 7 ][ 3 ] = {
	{ -1132.7081,1022.7668,1345.7273 },
	{ -1132.6602,1035.5205,1345.7427 },
	{ -1132.2740,1041.1238,1345.7412 },
	{ -1131.0614,1048.8101,1345.7435 },
	{ -1132.0385,1055.2090,1345.7603 },
	{ -1132.0372,1063.7393,1345.7628 },
	{ -1131.6272,1094.3673,1345.7885 }
};

new Float:warMap3Team1[ 4 ][ 3 ] = {
	{ 1295.8276,1070.7544,10.7652 },
	{ 1293.9846,1078.9841,10.6999 },
	{ 1300.7595,1085.3835,10.8203 },
	{ 1312.7617,1084.8655,10.8203}
};

new Float:warMap3Team2[ 4 ][ 3 ] = {
	{ 1492.2148,916.9006,10.9297 },
	{ 1478.9260,916.6356,10.8203 },
	{ 1467.7583,915.6778,10.8203 },
	{ 1471.7261,930.1809,10.8203 }
};

new Float:warMap4Team1[ 5 ][ 3 ] = {
	{ 2922.0735,4057.7339,41.9413 },
	{ 2924.9233,4058.4211,41.9413 },
	{ 2925.6855,4053.5361,41.9413 },
	{ 2926.5029,4045.3936,41.9413 },
	{ 2921.1628,4044.2600,41.9413 }
};

new Float:warMap4Team2[ 5 ][ 3 ] = {
	{ 2925.1416,4300.6401,41.9413 },
	{ 2923.4927,4307.6055,41.9413 },
	{ 2927.1511,4311.6382,41.9413 },
	{ 2930.3958,4310.5850,41.9413 },
	{ 2931.5002,4302.3281,41.9413 }
};

new Float:warMap5Team1[ 4 ][ 3 ] = {
	{ -136.6962,-114.7337,3.1172 },
	{ -126.6221,-115.4705,3.1172 },
	{ -104.1388,-119.4517,3.1172 },
	{ -84.2369,-121.1719,3.1172 }
};

new Float:warMap5Team2[ 4 ][ 3 ] = {
	{ 0.4129,91.1095,3.1172 },
	{ -22.3045,108.2041,3.1172 },
	{ -45.0152,113.6356,3.1172 },
	{ -77.4174,134.2272,3.1172 }
};

//-------------------------------[Stocks]---------------------------------------

stock GetPlayerLeader( playerid ) {
	return PlayerInfo[playerid][xLider];
}

stock GetPlayerMember( playerid ) {
	return PlayerInfo[playerid][xClan];
}

stock CreateMaps( ) {

    // WAR MAP FREE 1
    CreateDynamicObject(987, 1402.24536, 2725.05518, 9.80886,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(987, 1390.26404, 2725.06543, 9.80886,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(987, 1378.31885, 2725.07349, 9.80886,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(987, 1366.35645, 2725.08228, 9.80886,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(987, 1354.41626, 2725.06909, 9.80886,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(987, 1342.46826, 2725.05127, 9.80886,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(987, 1330.49927, 2725.06299, 9.80886,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(987, 1318.52832, 2725.06982, 9.80886,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(987, 1306.56763, 2725.06885, 9.80886,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(987, 1294.60339, 2725.07227, 9.80886,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(987, 1282.63672, 2725.05591, 9.80886,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(987, 1270.67261, 2725.07129, 9.80886,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(987, 1258.72913, 2725.08618, 9.80886,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(987, 1246.76160, 2725.08960, 9.80886,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(987, 1234.81372, 2725.08594, 9.80886,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(987, 1222.89075, 2725.08862, 9.80886,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(987, 1210.91333, 2725.09033, 9.80886,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(987, 1198.95313, 2725.09375, 9.80886,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(987, 1186.97864, 2725.10913, 9.80886,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(987, 1175.02136, 2725.11401, 9.80886,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(987, 1163.05969, 2725.12476, 9.80886,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(987, 1151.07605, 2725.11548, 9.80886,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(987, 1139.09717, 2725.15405, 9.80886,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(987, 1127.13562, 2725.16724, 9.80886,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(987, 1115.20520, 2725.17578, 9.80886,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(987, 1115.34839, 2737.05737, 9.80890,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(987, 1115.33215, 2749.04248, 9.80890,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(987, 1115.29431, 2761.00757, 9.80890,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(987, 1115.27698, 2772.97949, 9.80890,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(987, 1115.26611, 2784.92017, 9.80890,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(987, 1115.26294, 2796.90186, 9.80890,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(987, 1115.25940, 2808.88159, 9.80890,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(987, 1115.25647, 2820.85303, 9.80890,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(987, 1115.24048, 2832.83887, 9.80890,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(987, 1115.23950, 2844.83472, 9.80890,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(987, 1115.24780, 2856.75928, 9.80890,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(987, 1115.22070, 2862.74048, 9.80890,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(987, 1127.12402, 2862.97852, 9.80890,   0.00000, 0.00000, -180.00000);
    CreateDynamicObject(987, 1139.06519, 2862.98975, 9.80890,   0.00000, 0.00000, -180.00000);
    CreateDynamicObject(987, 1151.01318, 2863.00220, 9.80890,   0.00000, 0.00000, -180.00000);
    CreateDynamicObject(987, 1162.96143, 2863.03613, 9.80890,   0.00000, 0.00000, -180.00000);
    CreateDynamicObject(987, 1174.92896, 2863.04810, 9.80890,   0.00000, 0.00000, -180.00000);
    CreateDynamicObject(987, 1186.89026, 2863.03076, 9.80890,   0.00000, 0.00000, -180.00000);
    CreateDynamicObject(987, 1198.87122, 2863.04126, 9.80890,   0.00000, 0.00000, -180.00000);
    CreateDynamicObject(987, 1210.81763, 2863.03394, 9.80890,   0.00000, 0.00000, -180.00000);
    CreateDynamicObject(987, 1222.73877, 2863.03052, 9.80890,   0.00000, 0.00000, -180.00000);
    CreateDynamicObject(987, 1234.70117, 2863.04736, 9.80890,   0.00000, 0.00000, -180.00000);
    CreateDynamicObject(987, 1246.66406, 2863.06421, 9.80890,   0.00000, 0.00000, -180.00000);
    CreateDynamicObject(987, 1258.64526, 2863.07935, 9.80890,   0.00000, 0.00000, -180.00000);
    CreateDynamicObject(987, 1270.60657, 2863.11597, 9.80890,   0.00000, 0.00000, -180.00000);
    CreateDynamicObject(987, 1282.54724, 2863.12769, 9.80890,   0.00000, 0.00000, -180.00000);
    CreateDynamicObject(987, 1294.50769, 2863.14014, 9.80890,   0.00000, 0.00000, -180.00000);
    CreateDynamicObject(987, 1306.46375, 2863.13843, 9.80890,   0.00000, 0.00000, -180.00000);
    CreateDynamicObject(987, 1318.41870, 2863.14063, 9.80890,   0.00000, 0.00000, -180.00000);
    CreateDynamicObject(987, 1330.35999, 2863.15503, 9.80890,   0.00000, 0.00000, -180.00000);
    CreateDynamicObject(987, 1342.32080, 2863.16919, 9.80890,   0.00000, 0.00000, -180.00000);
    CreateDynamicObject(987, 1354.26807, 2863.15820, 9.80890,   0.00000, 0.00000, -180.00000);
    CreateDynamicObject(987, 1366.20166, 2863.14795, 9.80890,   0.00000, 0.00000, -180.00000);
    CreateDynamicObject(987, 1378.16162, 2863.16138, 9.80890,   0.00000, 0.00000, -180.00000);
    CreateDynamicObject(987, 1390.08862, 2863.17212, 9.80890,   0.00000, 0.00000, -180.00000);
    CreateDynamicObject(987, 1402.01514, 2863.17798, 9.80890,   0.00000, 0.00000, -180.00000);
    CreateDynamicObject(987, 1413.96252, 2863.20532, 9.80890,   0.00000, 0.00000, -180.00000);
    CreateDynamicObject(987, 1416.96423, 2863.21606, 9.80890,   0.00000, 0.00000, -180.00000);
    CreateDynamicObject(987, 1416.89087, 2851.31323, 9.80890,   0.00000, 0.00000, -270.00000);
    CreateDynamicObject(987, 1416.87317, 2839.38721, 9.80890,   0.00000, 0.00000, -270.00000);
    CreateDynamicObject(987, 1416.87952, 2827.44702, 9.80890,   0.00000, 0.00000, -270.00000);
    CreateDynamicObject(987, 1416.89124, 2815.50659, 9.80890,   0.00000, 0.00000, -270.00000);
    CreateDynamicObject(987, 1427.16016, 2809.34521, 9.80890,   0.00000, 0.00000, -211.00000);
    CreateDynamicObject(987, 1437.34827, 2803.20337, 9.80890,   0.00000, 0.00000, -211.00000);
    CreateDynamicObject(987, 1414.16968, 2725.04785, 9.80890,   0.00000, 0.00000, 47.00000);
    CreateDynamicObject(987, 1422.31311, 2733.78906, 9.80890,   0.00000, 0.00000, 39.00000);
    CreateDynamicObject(3887, 1230.42151, 2796.69702, 7.29060,   0.00000, 0.00000, -156.00000);
    CreateDynamicObject(11441, 1350.94287, 2833.11011, 9.80600,   0.00000, 0.00000, 76.00000);
    CreateDynamicObject(3374, 1378.27673, 2802.86523, 11.30570,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3374, 1343.54895, 2761.32080, 9.86570,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3374, 1215.42517, 2760.70410, 11.30570,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3374, 1197.53918, 2813.81812, 11.30570,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3374, 1261.20776, 2837.02905, 11.28570,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(1225, 1345.34375, 2821.74805, 10.21200,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3887, 1392.30969, 2749.75195, 11.99060,   0.00000, 0.00000, -62.00000);
    CreateDynamicObject(1225, 1389.02783, 2822.76733, 10.21200,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(1225, 1388.89087, 2824.23730, 10.21200,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(1225, 1388.08826, 2823.26025, 10.21200,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(1225, 1390.50586, 2811.41016, 10.23200,   0.00000, 91.00000, 76.00000);
    CreateDynamicObject(1225, 1405.41479, 2797.38818, 10.21200,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(11441, 1351.93457, 2824.92578, 9.80600,   0.00000, 0.00000, -164.00000);
    CreateDynamicObject(1225, 1345.27417, 2822.78687, 10.21200,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(1225, 1336.10559, 2797.72266, 10.15200,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(1225, 1335.11780, 2798.80396, 10.21200,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(1225, 1340.89380, 2784.21606, 9.63200,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(1225, 1340.35193, 2783.20654, 9.55200,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(1225, 1341.02002, 2762.57544, 9.01200,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(1225, 1340.58154, 2761.26416, 9.01200,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(1225, 1374.03882, 2748.16919, 10.63200,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(1225, 1387.54565, 2755.45483, 11.21200,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(1225, 1386.31445, 2755.26904, 11.21200,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(1225, 1309.16650, 2758.02100, 10.17200,   -0.04000, 0.00000, 0.00000);
    CreateDynamicObject(1225, 1308.42639, 2758.92725, 10.17200,   -0.04000, 0.00000, 0.00000);
    CreateDynamicObject(1225, 1286.70679, 2759.12500, 9.55200,   -0.04000, 0.00000, 0.00000);
    CreateDynamicObject(1225, 1287.17090, 2760.54395, 9.55200,   -0.04000, 0.00000, 0.00000);
    CreateDynamicObject(12957, 1284.31543, 2757.97754, 10.56130,   0.00000, 0.00000, -18.00000);
    CreateDynamicObject(1225, 1278.00623, 2768.32422, 10.17200,   90.00000, -2.00000, 0.00000);
    CreateDynamicObject(1225, 1268.38147, 2774.02905, 10.19200,   0.00000, -2.00000, 0.00000);
    CreateDynamicObject(1225, 1248.82690, 2774.68872, 10.19200,   0.00000, -2.00000, 0.00000);
    CreateDynamicObject(1225, 1242.80884, 2757.51929, 10.19200,   0.00000, -2.00000, 0.00000);
    CreateDynamicObject(1225, 1251.97766, 2741.87622, 9.59200,   0.00000, -2.00000, 0.00000);
    CreateDynamicObject(1225, 1234.04407, 2741.60352, 10.25200,   0.00000, -2.00000, 0.00000);
    CreateDynamicObject(11440, 1161.18787, 2802.94019, 9.20590,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(1225, 1162.79236, 2806.82666, 12.66940,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(13591, 1201.63550, 2851.41064, 10.37750,   0.00000, 0.00000, 47.00000);
    CreateDynamicObject(1225, 1196.92114, 2847.86133, 10.27920,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(1225, 1261.68506, 2839.84619, 10.29400,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(11440, 1318.50671, 2833.33472, 9.14880,   0.00000, 0.00000, 69.00000);
    CreateDynamicObject(1225, 1309.56897, 2828.14404, 10.17700,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(1225, 1303.88879, 2809.01147, 10.21700,   0.00000, 91.00000, 0.00000);
    CreateDynamicObject(11443, 1393.70508, 2848.73633, 9.59060,   0.00000, 0.00000, -52.00000);
    CreateDynamicObject(1225, 1393.84058, 2846.14209, 10.12890,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(1225, 1390.42456, 2848.55322, 10.12890,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(11443, 1183.32727, 2767.95508, 9.80886,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(1225, 1186.34802, 2767.93628, 10.23610,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(1225, 1185.02710, 2771.86255, 10.23610,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3363, 1277.47925, 2799.51782, 9.80920,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(1225, 1342.50500, 2841.29810, 10.21200,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(1225, 1385.46948, 2781.96582, 10.33200,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(1225, 1385.95361, 2780.62671, 10.33200,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(12957, 1390.28198, 2782.74414, 10.61180,   0.00000, 0.00000, 0.00000);
	// WAR MAP FREE 2
	CreateDynamicObject(8171, 2946.0625, 4109.7930, 40.9413, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(8171, 2906.4460, 4109.7998, 40.9413, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(8171, 2887.0964, 4109.9063, 60.4812, 0.2350, 91.3100, 359.7500);
    CreateDynamicObject(8171, 2966.1877, 4109.6035, 60.5463, 0.2335, 89.3224, 180.0543);
    CreateDynamicObject(8171, 2906.4038, 4248.0059, 40.9413, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(8171, 2946.0469, 4248.0132, 40.9413, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(8171, 2887.6990, 4248.1597, 61.0062, 359.9807, 91.3074, 359.7473);
    CreateDynamicObject(8171, 2965.8220, 4247.4531, 60.0713, 0.2307, 89.3188, 180.2994);
    CreateDynamicObject(8171, 2926.5183, 4316.0449, 60.0213, 0.2307, 89.3134, 270.0416);
    CreateDynamicObject(8171, 2929.2061, 4041.4587, 60.0213, 0.2307, 89.3079, 90.1884);
    CreateDynamicObject(8171, 2946.4397, 4248.4385, 79.3963, 0.0000, 179.1900, 0.0000);
    CreateDynamicObject(8171, 2906.7041, 4248.4395, 78.8463, 0.0000, 179.1870, 0.0000);
    CreateDynamicObject(8171, 2906.6987, 4110.1406, 78.8463, 0.0000, 179.1870, 0.0000);
    CreateDynamicObject(3110, 2945.3767, 4153.6963, 38.6663, 0.0000, 0.0000, 5.9550);
    CreateDynamicObject(6052, 2898.2649, 4199.9722, 43.4139, 0.0000, 0.0000, 29.9100);
    CreateDynamicObject(6052, 2899.5896, 4199.0464, 43.0989, 359.5750, 177.1150, 284.2800);
    CreateDynamicObject(16084, 2901.1116, 4133.3525, 38.4913, 1.7500, 356.0300, 15.9700);
    CreateDynamicObject(3663, 2927.2021, 4166.1641, 43.0220, 0.0000, 0.0000, 272.2102);
    CreateDynamicObject(3663, 2927.0901, 4170.1211, 43.0220, 0.0000, 0.0000, 92.4481);
    CreateDynamicObject(16084, 2949.8240, 4213.4536, 37.3412, 1.7468, 356.0284, 191.4136);
    CreateDynamicObject(3269, 2905.7034, 4160.4521, 40.9413, 0.0000, 0.0000, 57.8350);
    CreateDynamicObject(12934, 2973.6648, 4161.0703, 44.3245, 0.0000, 0.0000, 48.1301);
    CreateDynamicObject(18260, 2940.8855, 4118.3267, 42.5145, 0.0000, 0.0000, 190.5106);
    CreateDynamicObject(2932, 2916.1472, 4044.9136, 42.3932, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(2932, 2930.3440, 4044.7532, 42.3932, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(2932, 2930.2915, 4054.1082, 42.3932, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(2932, 2915.9849, 4053.4519, 42.3932, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(2932, 2925.5251, 4061.8821, 42.3932, 0.0000, 0.0000, 90.5078);
    CreateDynamicObject(2932, 2918.3765, 4061.8315, 42.3932, 0.0000, 0.0000, 90.5054);
    CreateDynamicObject(2973, 2929.5278, 4071.7622, 40.9413, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(2973, 2933.3254, 4074.2947, 40.9413, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(2973, 2931.3643, 4073.2207, 43.3662, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(2973, 2934.2549, 4076.8298, 40.9413, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(2973, 2924.2859, 4078.3643, 40.9413, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(2973, 2920.9131, 4079.6577, 40.9413, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(2973, 2922.5464, 4079.2798, 43.3913, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(2973, 2914.6040, 4077.2412, 40.8763, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(2975, 2912.0498, 4076.4343, 40.9413, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(2975, 2912.0498, 4076.4336, 42.1663, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(2975, 2909.8635, 4076.1775, 42.1663, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(2975, 2909.8833, 4076.2266, 41.1663, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(2991, 2921.7510, 4103.8647, 41.5690, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(2991, 2921.7744, 4103.8726, 42.7690, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(2991, 2921.7744, 4103.8721, 43.9191, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(2934, 2935.0413, 4312.3618, 42.3932, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(2934, 2935.0022, 4303.6436, 42.3932, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(2934, 2920.7473, 4312.1729, 42.3932, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(2934, 2920.5190, 4302.8579, 42.3932, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(2934, 2922.3162, 4295.3857, 42.3932, 0.0000, 0.0000, 89.5101);
    CreateDynamicObject(2934, 2933.4146, 4295.3623, 42.3932, 0.0000, 0.0000, 90.0057);
    CreateDynamicObject(2934, 2926.8384, 4295.3472, 42.3932, 0.0000, 0.0000, 89.5056);
    CreateDynamicObject(2974, 2913.1233, 4281.4204, 40.9413, 0.0000, 0.0000, 119.6400);
    CreateDynamicObject(2974, 2915.3826, 4280.4678, 40.9413, 0.0000, 0.0000, 181.6455);
    CreateDynamicObject(2974, 2918.6296, 4280.6685, 40.9413, 0.0000, 0.0000, 269.3875);
    CreateDynamicObject(2974, 2927.0398, 4279.2568, 40.9413, 0.0000, 0.0000, 253.3698);
    CreateDynamicObject(2974, 2929.8049, 4279.1147, 40.9413, 0.0000, 0.0000, 279.3544);
    CreateDynamicObject(2974, 2928.8606, 4277.5688, 40.9413, 0.0000, 0.0000, 278.0994);
    CreateDynamicObject(2974, 2926.5779, 4277.2715, 40.9413, 0.0000, 0.0000, 278.0969);
    CreateDynamicObject(2974, 2928.1638, 4277.4058, 43.7663, 0.0000, 0.0000, 278.0969);
    CreateDynamicObject(2974, 2924.7744, 4278.5913, 40.9413, 0.0000, 0.0000, 340.5964);
    CreateDynamicObject(3378, 2946.0964, 4280.7583, 42.1112, 0.0000, 0.0000, 304.1952);
    CreateDynamicObject(3378, 2946.0957, 4280.7578, 44.3512, 0.0000, 0.0000, 304.1949);
    CreateDynamicObject(3585, 2908.1560, 4065.1472, 42.5711, 0.0000, 0.0000, 47.8650);
    CreateDynamicObject(3585, 2906.3303, 4066.7869, 42.5711, 0.0000, 0.0000, 47.8619);
    CreateDynamicObject(3585, 2904.6826, 4068.4734, 42.5711, 0.0000, 0.0000, 39.9219);
    CreateDynamicObject(3585, 2903.3472, 4070.2861, 42.5711, 0.0000, 0.0000, 33.9639);
    CreateDynamicObject(3585, 2902.2825, 4072.2351, 42.5711, 0.0000, 0.0000, 20.8438);
    CreateDynamicObject(3585, 2901.7178, 4074.3394, 42.5461, 0.0000, 0.0000, 6.9461);
    CreateDynamicObject(3585, 2901.5010, 4076.6543, 42.5211, 0.0000, 0.0000, 2.9734);
    CreateDynamicObject(2991, 2950.1531, 4094.4287, 41.5690, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(2991, 2950.1523, 4094.4287, 42.8190, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(2991, 2950.1523, 4094.4287, 44.0690, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(2991, 2954.3076, 4093.2632, 41.5690, 0.0000, 0.0000, 328.1051);
    CreateDynamicObject(2991, 2954.3213, 4093.2837, 42.8190, 0.0000, 0.0000, 328.1012);
    CreateDynamicObject(2991, 2954.3213, 4093.2832, 44.0689, 0.0000, 0.0000, 328.1012);
    CreateDynamicObject(2991, 2942.9612, 4095.0745, 41.5439, 0.0000, 0.0000, 328.1012);
    CreateDynamicObject(2991, 2942.9609, 4095.0742, 42.7689, 0.0000, 0.0000, 328.1012);
    CreateDynamicObject(2991, 2942.9609, 4095.0742, 43.8939, 0.0000, 0.0000, 328.1012);
    CreateDynamicObject(2991, 2946.3823, 4094.3325, 45.2190, 359.2500, 358.0150, 4.0111);
    CreateDynamicObject(16301, 2914.8337, 4120.4917, 45.1091, 0.0000, 0.0000, 71.7750);
    CreateDynamicObject(16311, 2930.9119, 4148.0361, 52.3643, 0.0000, 0.0000, 45.8950);
    CreateDynamicObject(16311, 2953.0288, 4188.8677, 52.2393, 0.0000, 0.0000, 256.5099);
    CreateDynamicObject(16301, 2952.8406, 4220.3813, 44.2092, 358.7500, 358.0150, 282.2239);
    CreateDynamicObject(3865, 2907.0601, 4280.1265, 42.8752, 0.0000, 0.0000, 131.5950);
    CreateDynamicObject(3865, 2900.9775, 4273.8223, 42.8752, 0.0000, 0.0000, 141.5642);
    CreateDynamicObject(3865, 2897.5974, 4266.8145, 42.8752, 0.0000, 0.0000, 171.4688);
    CreateDynamicObject(3865, 2896.8999, 4258.4038, 42.8752, 0.0000, 0.0000, 181.4336);
    CreateDynamicObject(3865, 2897.0337, 4250.6128, 42.8752, 0.0000, 0.0000, 181.4282);
    CreateDynamicObject(3865, 2897.1570, 4241.4370, 42.8752, 0.0000, 0.0000, 181.4282);
    CreateDynamicObject(3865, 2897.2605, 4232.4385, 42.8752, 0.0000, 0.0000, 181.4282);
    CreateDynamicObject(3865, 2897.3896, 4223.4839, 42.8752, 0.0000, 0.0000, 181.4282);
    CreateDynamicObject(3865, 2897.3127, 4210.8110, 43.5502, 14.6750, 0.0000, 181.4282);
    CreateDynamicObject(3865, 2897.3782, 4202.7544, 46.6752, 27.8322, 0.0000, 181.4227);
    CreateDynamicObject(3865, 2897.4624, 4195.0615, 50.7502, 27.8284, 0.0000, 181.4227);
    CreateDynamicObject(3865, 2897.5408, 4187.7300, 55.5501, 37.7684, 0.0000, 181.4227);
    CreateDynamicObject(3865, 2897.4651, 4180.3711, 60.9252, 34.5455, 0.0000, 179.4227);
    CreateDynamicObject(3865, 2897.1863, 4171.4805, 64.1002, 4.7660, 0.0000, 178.4177);
    CreateDynamicObject(3675, 2964.6809, 4127.9097, 47.7725, 0.0000, 0.0000, 270.2703);
    CreateDynamicObject(3214, 2897.4216, 4162.3687, 56.3810, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(3214, 2897.3164, 4154.2368, 56.3810, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(3269, 2896.8799, 4150.0088, 42.3413, 0.0000, 0.0000, 348.0420);
    CreateDynamicObject(3865, 2898.0813, 4146.1489, 64.1002, 4.7626, 0.0000, 359.8123);
    CreateDynamicObject(3865, 2897.9731, 4137.1470, 62.7251, 12.7026, 0.0000, 359.8077);
    CreateDynamicObject(3865, 2897.8188, 4128.4048, 60.5751, 14.6852, 0.0000, 359.8022);
    CreateDynamicObject(3865, 2897.9934, 4119.8823, 57.8000, 20.9332, 0.0000, 3.7722);
    CreateDynamicObject(3865, 2898.4143, 4111.4478, 54.5500, 20.9290, 0.0000, 3.7683);
    CreateDynamicObject(3865, 2898.8235, 4103.2388, 51.1500, 23.1790, 0.0000, 3.7683);
    CreateDynamicObject(3865, 2899.2803, 4094.7463, 47.5000, 23.1757, 0.0000, 3.7628);
    CreateDynamicObject(3865, 2899.8013, 4087.6245, 45.1249, 14.9706, 0.0000, 5.7478);
    CreateDynamicObject(3865, 2900.8042, 4081.6189, 43.9000, 9.9839, 0.0000, 11.4958);
    CreateDynamicObject(3406, 2962.1606, 4124.8135, 47.0120, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(3406, 2951.8049, 4123.2603, 47.0120, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(12934, 2937.2039, 4098.4331, 44.3245, 0.0000, 0.0000, 199.4000);
    CreateDynamicObject(925, 2961.7756, 4241.9683, 42.0032, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(925, 2959.4500, 4241.9927, 42.0032, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(925, 2957.1260, 4242.0928, 42.0032, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(925, 2953.7290, 4242.2393, 42.0032, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(925, 2951.3335, 4243.0142, 42.0032, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(925, 2951.2844, 4242.9897, 44.0532, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(925, 2953.7285, 4242.2393, 44.1032, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(1348, 2946.2793, 4246.0381, 41.6438, 0.0000, 0.0000, 139.5800);
    CreateDynamicObject(964, 2953.7417, 4242.2329, 45.1740, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(3566, 2949.3616, 4258.5718, 43.5549, 0.0000, 0.0000, 49.8500);
    CreateDynamicObject(3566, 2936.5239, 4250.1211, 43.5549, 0.0000, 0.0000, 119.6350);
    CreateDynamicObject(3566, 2912.6487, 4244.3428, 43.5549, 0.0000, 0.0000, 229.3001);
    CreateDynamicObject(3761, 2932.2522, 4188.7314, 42.9402, 0.0000, 0.0000, 55.8950);
    CreateDynamicObject(3761, 2926.2815, 4193.4009, 42.9402, 0.0000, 0.0000, 135.6530);
    CreateDynamicObject(3761, 2935.1130, 4197.8228, 42.9402, 0.0000, 0.0000, 185.4984);
    CreateDynamicObject(3761, 2921.3103, 4200.0815, 42.9402, 0.0000, 0.0000, 125.6732);
    CreateDynamicObject(3761, 2917.0486, 4192.9609, 42.9402, 0.0000, 0.0000, 215.4027);
    CreateDynamicObject(2395, 2925.3589, 4167.7871, 71.9962, 270.6749, 0.0000, 359.0000);
    CreateDynamicObject(8171, 2946.4680, 4110.1543, 79.4213, 0.0000, 179.1870, 0.0000);
    CreateDynamicObject(2395, 2925.3147, 4165.0737, 71.9712, 270.6702, 0.0000, 358.9948);
    CreateDynamicObject(2395, 2925.2715, 4162.3584, 71.9462, 270.6702, 0.0000, 358.9948);
    CreateDynamicObject(2395, 2928.9763, 4162.2866, 71.9462, 270.6702, 0.0000, 358.9948);
    CreateDynamicObject(2395, 2929.0112, 4165.0371, 71.9712, 270.6702, 0.0000, 358.9948);
    CreateDynamicObject(2395, 2929.0752, 4167.7290, 71.9962, 270.6702, 0.0000, 358.9948);
    CreateDynamicObject(2395, 2925.4006, 4170.5552, 71.8462, 90.2851, 0.0000, 358.4797);
    CreateDynamicObject(2395, 2929.1240, 4170.4775, 71.8462, 90.2802, 0.0000, 358.9784);
    CreateDynamicObject(2395, 2929.1077, 4167.8022, 71.8462, 90.2802, 0.0000, 358.9783);
    CreateDynamicObject(2395, 2929.0605, 4165.1211, 71.8212, 90.2802, 0.0000, 358.9783);
    CreateDynamicObject(2395, 2925.3518, 4167.8628, 71.8212, 90.2802, 0.0000, 358.9783);
    CreateDynamicObject(2395, 2925.3230, 4165.1523, 71.8212, 90.2802, 0.0000, 358.9783);
    CreateDynamicObject(987, 2924.9365, 4162.5845, 71.7927, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(987, 2925.0972, 4174.1118, 71.8677, 0.0000, 0.0000, 270.2703);
    CreateDynamicObject(987, 2936.6013, 4174.0420, 71.8677, 0.0000, 0.0000, 180.5392);
    CreateDynamicObject(987, 2936.7102, 4162.2393, 71.8677, 0.0000, 0.0000, 90.8084);
    CreateDynamicObject(2395, 2925.3977, 4170.5176, 71.9962, 270.6702, 0.0000, 358.9948);
    CreateDynamicObject(2395, 2925.4326, 4171.6479, 71.9962, 270.6702, 0.0000, 358.9948);
    CreateDynamicObject(2395, 2929.1550, 4171.5186, 71.9962, 270.6702, 0.0000, 358.9948);
    CreateDynamicObject(2395, 2929.1260, 4169.9878, 71.9962, 270.6702, 0.0000, 358.9948);
    CreateDynamicObject(2395, 2932.8457, 4171.4375, 71.9962, 270.6702, 0.0000, 358.9948);
    CreateDynamicObject(2395, 2932.8379, 4168.7305, 71.9962, 270.6702, 0.0000, 358.9948);
    CreateDynamicObject(2395, 2932.7468, 4166.0405, 71.9962, 270.6702, 0.0000, 358.9948);
    CreateDynamicObject(2395, 2932.6855, 4163.2832, 71.9962, 270.6702, 0.0000, 358.9948);
    CreateDynamicObject(2395, 2932.6709, 4162.2046, 71.9962, 270.6702, 0.0000, 358.9948);
    CreateDynamicObject(2395, 2937.3682, 4162.5752, 71.9712, 270.6702, 0.0000, 88.7397);
    CreateDynamicObject(2395, 2937.3582, 4166.2656, 71.9712, 270.6647, 0.0000, 88.7366);
    CreateDynamicObject(2395, 2937.3662, 4169.9263, 71.9712, 270.6647, 0.0000, 88.7366);
    CreateDynamicObject(2395, 2937.5039, 4170.8687, 71.9712, 270.6647, 0.0000, 88.7366);
    CreateDynamicObject(2395, 2925.4963, 4173.2295, 71.8462, 90.2802, 0.0000, 358.4784);
    CreateDynamicObject(2395, 2925.4705, 4174.1040, 71.8462, 90.2802, 0.0000, 358.4784);
    CreateDynamicObject(2395, 2929.1973, 4174.0586, 71.8462, 90.2802, 0.0000, 358.4784);
    CreateDynamicObject(2395, 2929.2031, 4173.0093, 71.8462, 90.2802, 0.0000, 358.4784);
    CreateDynamicObject(2395, 2932.9282, 4173.9673, 71.8462, 90.2802, 0.0000, 358.4784);
    CreateDynamicObject(2395, 2932.8831, 4171.2441, 71.8462, 90.2802, 0.0000, 358.4784);
    CreateDynamicObject(2395, 2932.8367, 4168.5713, 71.8462, 90.2802, 0.0000, 358.4784);
    CreateDynamicObject(2395, 2932.8132, 4165.9478, 71.8462, 90.2802, 0.0000, 358.4784);
    CreateDynamicObject(2395, 2932.8315, 4165.2998, 71.8462, 90.2802, 0.0000, 358.4784);
    CreateDynamicObject(2395, 2934.0190, 4163.1309, 71.8462, 90.2802, 354.0450, 93.8027);
    CreateDynamicObject(2395, 2933.9878, 4166.7329, 71.8462, 90.2802, 356.0249, 93.8013);
    CreateDynamicObject(2395, 2933.8804, 4170.3828, 71.8462, 90.2802, 356.0229, 93.8013);
    CreateDynamicObject(987, 2936.6035, 4174.4302, 76.5927, 0.0000, 0.0000, 180.5383);
    CreateDynamicObject(987, 2937.1362, 4162.2231, 76.6927, 0.0000, 0.0000, 90.8075);
    CreateDynamicObject(987, 2924.9365, 4162.1846, 76.6927, 0.0000, 0.0000, 0.0000);
    CreateDynamicObject(987, 2924.6235, 4174.1113, 76.7927, 0.0000, 0.0000, 270.2692);
    CreateDynamicObject(1472, 2908.9597, 4064.4204, 41.3564, 0.0000, 0.0000, 48.6000);
}

stock CreatePlayerTextDraws( playerid ) {
    WARTextDraw[ playerid ][ 0 ] = CreatePlayerTextDraw(playerid,640.000000, 220.000000, "          ");
	PlayerTextDrawBackgroundColor(playerid,WARTextDraw[ playerid ][ 0 ], 255);
	PlayerTextDrawFont(playerid,WARTextDraw[ playerid ][ 0 ], 1);
	PlayerTextDrawLetterSize(playerid,WARTextDraw[ playerid ][ 0 ], 0.500000, 1.000000);
	PlayerTextDrawColor(playerid,WARTextDraw[ playerid ][ 0 ], -1);
	PlayerTextDrawSetOutline(playerid,WARTextDraw[ playerid ][ 0 ], 0);
	PlayerTextDrawSetProportional(playerid,WARTextDraw[ playerid ][ 0 ], 1);
	PlayerTextDrawSetShadow(playerid,WARTextDraw[ playerid ][ 0 ], 1);
	PlayerTextDrawUseBox(playerid,WARTextDraw[ playerid ][ 0 ], 1);
	PlayerTextDrawBoxColor(playerid,WARTextDraw[ playerid ][ 0 ], 150);
	PlayerTextDrawTextSize(playerid,WARTextDraw[ playerid ][ 0 ], 500.000000, 40.000000);
	PlayerTextDrawSetSelectable(playerid,WARTextDraw[ playerid ][ 0 ], 0);

	WARTextDraw[ playerid ][ 1 ] = CreatePlayerTextDraw(playerid,567.000000, 220.000000, "WAR");
	PlayerTextDrawAlignment(playerid,WARTextDraw[ playerid ][ 1 ], 2);
	PlayerTextDrawBackgroundColor(playerid,WARTextDraw[ playerid ][ 1 ], 255);
	PlayerTextDrawFont(playerid,WARTextDraw[ playerid ][ 1 ], 2);
	PlayerTextDrawLetterSize(playerid,WARTextDraw[ playerid ][ 1 ], 0.419999, 0.899999);
	PlayerTextDrawColor(playerid,WARTextDraw[ playerid ][ 1 ], CROHERZE );
	PlayerTextDrawSetOutline(playerid,WARTextDraw[ playerid ][ 1 ], 0);
	PlayerTextDrawSetProportional(playerid,WARTextDraw[ playerid ][ 1 ], 1);
	PlayerTextDrawSetShadow(playerid,WARTextDraw[ playerid ][ 1 ], 1);
	PlayerTextDrawSetSelectable(playerid,WARTextDraw[ playerid ][ 1 ], 0);

	WARTextDraw[ playerid ][ 2 ] = CreatePlayerTextDraw(playerid,568.000000, 227.000000, "-");
	PlayerTextDrawAlignment(playerid,WARTextDraw[ playerid ][ 2 ], 2);
	PlayerTextDrawBackgroundColor(playerid,WARTextDraw[ playerid ][ 2 ], 255);
	PlayerTextDrawFont(playerid,WARTextDraw[ playerid ][ 2 ], 2);
	PlayerTextDrawLetterSize(playerid,WARTextDraw[ playerid ][ 2 ], 12.080010, 0.899999);
	PlayerTextDrawColor(playerid,WARTextDraw[ playerid ][ 2 ], -1);
	PlayerTextDrawSetOutline(playerid,WARTextDraw[ playerid ][ 2 ], 0);
	PlayerTextDrawSetProportional(playerid,WARTextDraw[ playerid ][ 2 ], 1);
	PlayerTextDrawSetShadow(playerid,WARTextDraw[ playerid ][ 2 ], 1);
	PlayerTextDrawSetSelectable(playerid,WARTextDraw[ playerid ][ 2 ], 0);

	WARTextDraw[ playerid ][ 3 ] = CreatePlayerTextDraw(playerid,527.000000, 234.000000, "Team 1");
	PlayerTextDrawAlignment(playerid,WARTextDraw[ playerid ][ 3 ], 2);
	PlayerTextDrawBackgroundColor(playerid,WARTextDraw[ playerid ][ 3 ], 255);
	PlayerTextDrawFont(playerid,WARTextDraw[ playerid ][ 3 ], 2);
	PlayerTextDrawLetterSize(playerid,WARTextDraw[ playerid ][ 3 ], 0.360000, 0.899999);
	PlayerTextDrawColor(playerid,WARTextDraw[ playerid ][ 3 ], -1);
	PlayerTextDrawSetOutline(playerid,WARTextDraw[ playerid ][ 3 ], 0);
	PlayerTextDrawSetProportional(playerid,WARTextDraw[ playerid ][ 3 ], 1);
	PlayerTextDrawSetShadow(playerid,WARTextDraw[ playerid ][ 3 ], 1);
	PlayerTextDrawSetSelectable(playerid,WARTextDraw[ playerid ][ 3 ], 0);

	WARTextDraw[ playerid ][ 4 ] = CreatePlayerTextDraw(playerid,608.000000, 234.000000, "Team 2");
	PlayerTextDrawAlignment(playerid,WARTextDraw[ playerid ][ 4 ], 2);
	PlayerTextDrawBackgroundColor(playerid,WARTextDraw[ playerid ][ 4 ], 255);
	PlayerTextDrawFont(playerid,WARTextDraw[ playerid ][ 4 ], 2);
	PlayerTextDrawLetterSize(playerid,WARTextDraw[ playerid ][ 4 ], 0.360000, 0.899999);
	PlayerTextDrawColor(playerid,WARTextDraw[ playerid ][ 4 ], -1);
	PlayerTextDrawSetOutline(playerid,WARTextDraw[ playerid ][ 4 ], 0);
	PlayerTextDrawSetProportional(playerid,WARTextDraw[ playerid ][ 4 ], 1);
	PlayerTextDrawSetShadow(playerid,WARTextDraw[ playerid ][ 4 ], 1);
	PlayerTextDrawSetSelectable(playerid,WARTextDraw[ playerid ][ 4 ], 0);

	WARTextDraw[ playerid ][ 5 ] = CreatePlayerTextDraw(playerid,506.000000, 248.000000, "Kills: 100~n~Deaths: 100~n~Players: 10");
	PlayerTextDrawBackgroundColor(playerid,WARTextDraw[ playerid ][ 5 ], 255);
	PlayerTextDrawFont(playerid,WARTextDraw[ playerid ][ 5 ], 2);
	PlayerTextDrawLetterSize(playerid,WARTextDraw[ playerid ][ 5 ], 0.230000, 0.899999);
	PlayerTextDrawColor(playerid,WARTextDraw[ playerid ][ 5 ], -1);
	PlayerTextDrawSetOutline(playerid,WARTextDraw[ playerid ][ 5 ], 0);
	PlayerTextDrawSetProportional(playerid,WARTextDraw[ playerid ][ 5 ], 1);
	PlayerTextDrawSetShadow(playerid,WARTextDraw[ playerid ][ 5 ], 1);
	PlayerTextDrawSetSelectable(playerid,WARTextDraw[ playerid ][ 5 ], 0);

	WARTextDraw[ playerid ][ 6 ] = CreatePlayerTextDraw(playerid,573.000000, 248.000000, "Kills: 100~n~Deaths: 100~n~Players: 10");
	PlayerTextDrawBackgroundColor(playerid,WARTextDraw[ playerid ][ 6 ], 255);
	PlayerTextDrawFont(playerid,WARTextDraw[ playerid ][ 6 ], 2);
	PlayerTextDrawLetterSize(playerid,WARTextDraw[ playerid ][ 6 ], 0.230000, 0.899999);
	PlayerTextDrawColor(playerid,WARTextDraw[ playerid ][ 6 ], -1);
	PlayerTextDrawSetOutline(playerid,WARTextDraw[ playerid ][ 6 ], 0);
	PlayerTextDrawSetProportional(playerid,WARTextDraw[ playerid ][ 6 ], 1);
	PlayerTextDrawSetShadow(playerid,WARTextDraw[ playerid ][ 6 ], 1);
	PlayerTextDrawSetSelectable(playerid,WARTextDraw[ playerid ][ 6 ], 0);

	WARTextDraw[ playerid ][ 7 ] = CreatePlayerTextDraw(playerid,568.000000, 275.000000, "-");
	PlayerTextDrawAlignment(playerid,WARTextDraw[ playerid ][ 7 ], 2);
	PlayerTextDrawBackgroundColor(playerid,WARTextDraw[ playerid ][ 7 ], 255);
	PlayerTextDrawFont(playerid,WARTextDraw[ playerid ][ 7 ], 2);
	PlayerTextDrawLetterSize(playerid,WARTextDraw[ playerid ][ 7 ], 12.080010, 0.899999);
	PlayerTextDrawColor(playerid,WARTextDraw[ playerid ][ 7 ], -1);
	PlayerTextDrawSetOutline(playerid,WARTextDraw[ playerid ][ 7 ], 0);
	PlayerTextDrawSetProportional(playerid,WARTextDraw[ playerid ][ 7 ], 1);
	PlayerTextDrawSetShadow(playerid,WARTextDraw[ playerid ][ 7 ], 1);
	PlayerTextDrawSetSelectable(playerid,WARTextDraw[ playerid ][ 7 ], 0);

	WARTextDraw[ playerid ][ 8 ] = CreatePlayerTextDraw(playerid,567.000000, 284.000000, "10:00");
	PlayerTextDrawAlignment(playerid,WARTextDraw[ playerid ][ 8 ], 2);
	PlayerTextDrawBackgroundColor(playerid,WARTextDraw[ playerid ][ 8 ], 255);
	PlayerTextDrawFont(playerid,WARTextDraw[ playerid ][ 8 ], 2);
	PlayerTextDrawLetterSize(playerid,WARTextDraw[ playerid ][ 8 ], 0.459999, 1.300000);
	PlayerTextDrawColor(playerid,WARTextDraw[ playerid ][ 8 ], -1);
	PlayerTextDrawSetOutline(playerid,WARTextDraw[ playerid ][ 8 ], 0);
	PlayerTextDrawSetProportional(playerid,WARTextDraw[ playerid ][ 8 ], 1);
	PlayerTextDrawSetShadow(playerid,WARTextDraw[ playerid ][ 8 ], 1);
	PlayerTextDrawSetSelectable(playerid,WARTextDraw[ playerid ][ 8 ], 0);
	
}

stock WarTDControl( playerid, bool:show ) {
	if( show == true ) {
        for( new i = 0; i < 9; i ++ ) {
			PlayerTextDrawShow( playerid, WARTextDraw[ playerid ][ i ] );
		}
	}
	else if( show == false ) {
		for( new i = 0; i < 9; i ++ ) {
			PlayerTextDrawHide( playerid, WARTextDraw[ playerid ][ i ]);
		}
	}
}

stock WARMessage( w, color, string[] ) {
	foreach( Player, i ) {
		if( WARPInfo[ i ][ warID ] == w ) {
			SCM( i, color, string );
		}
	}
}

stock SetWarStatsTD( w ) {
	new string[ 128 ];
	foreach( Player, id ) {
 		if( WARPInfo[ id ][ warID ] == w ) {
			format( string ,sizeof( string ),"~w~Kills: ~g~%d~n~~w~Deaths: ~r~%d~n~~w~Players: ~y~%d", WARInfo[ w ][ warTeamScore ][ 0 ], WARInfo[ w ][ warTeamScore ][ 1 ], WARInfo[ w ][ warTeamMembers ][ 0 ] );
			PlayerTextDrawSetString( id, WARTextDraw[ id ][ 5 ],  string );
			format( string ,sizeof( string ),"~w~Kills: ~g~%d~n~~w~Deaths: ~r~%d~n~~w~Players: ~y~%d", WARInfo[ w ][ warTeamScore ][ 1 ], WARInfo[ w ][ warTeamScore ][ 0 ], WARInfo[ w ][ warTeamMembers ][ 1 ] );
			PlayerTextDrawSetString( id, WARTextDraw[ id ][ 6 ],  string );
		}
	}
}
//-----------------------------[Forwards]---------------------------------------

forward StopWAR( w );
forward StopWARTimer( w );

//------------------------------[Publics]---------------------------------------
public OnFilterScriptInit( ) {

    CreateMaps( );

	print("\n--------------------------------------");
	print(" Advanced WAR system by Dimi");
	print("--------------------------------------\n");
	
	return true;
}

ResetWarStatistics( playerid ) {
    WARPInfo[ playerid ][ warTeam ][ 0 ] = false;
    WARPInfo[ playerid ][ warTeam ][ 1 ] = false;
    WARPInfo[ playerid ][ warKills ] = 0;
    WARPInfo[ playerid ][ warDeaths ] = 0;
    WARPInfo[ playerid ][ warID ] = -1;
}

public StopWAR( w ) {
    WARInfo[ w ][ warActive ] = false;
    WARInfo[ w ][ warCreating ] = false;
	KillTimer( WARInfo[ w ][ warTimer ] );
	foreach( Player, i ) {
	    if( WARPInfo[ i ][ warID ] == w ) {

  		    if (WARInfo[ w ][ warTeamScore ][ 0 ] > WARInfo[ w ][ warTeamScore ][ 1 ] ) {
  		        if( WARPInfo[ i ][ warTeam ][ 0 ] ) {
  		        	SCM( i, -1, ""COL_ORANGE"WAR "COL_WHITE"| "COL_ORANGE"You won and get"COL_WHITE"100%!");
  		        }
  		    }
  		    if(WARInfo[ w ][ warTeamScore ][ 1 ] > WARInfo[ w ][ warTeamScore ][ 0 ] ) {
  		        if( WARPInfo[ i ][ warTeam ][ 1 ] ) {
  		        	SCM( i, -1, ""COL_ORANGE"WAR "COL_WHITE"| "COL_ORANGE"You won and get"COL_WHITE"100%!");
  		        }
  		    }
  		    SCM( i, -1, globalstring );
  		    format( globalstring, sizeof( globalstring ), ""COL_ORANGE"WAR "COL_WHITE"| "COL_ORANGE"Your score "COL_WHITE"|  "COL_ORANGE"Kills: "COL_WHITE"%d "COL_WHITE"| "COL_ORANGE"Deaths: "COL_WHITE"%d", WARPInfo[ i ][ warKills ], WARPInfo[ i ][ warDeaths ] );
  		    SCM( i, -1, globalstring);
  		    format( globalstring, sizeof( globalstring ), ""COL_ORANGE"WAR "COL_WHITE"| "COL_TEAM1"Team 1: "COL_WHITE"%d | "COL_TEAM2"Team 2: "COL_WHITE"%d", WARInfo[ w ][ warTeamScore ][ 0 ], WARInfo[ w ][ warTeamScore ][ 1 ]  );
  		    SCM( i, -1, globalstring );

  		    WARPInfo[ i ][ warID ] = -1;
	        SetPlayerHealth( i, 100 );
	        
	        SetPlayerPos( i, WARPInfo[ i ][ LastPosition ][ 0 ], WARPInfo[ i ][ LastPosition ][ 1 ],  WARPInfo[ i ][ LastPosition ][ 2 ] );
	        SetPlayerVirtualWorld( i, WARPInfo[ i ][ LastVirtualWorld ] );
	        SetPlayerInterior( i, WARPInfo[ i ][ LastInterior ] );
	        
	        
			ResetPlayerWeapons( i );

	        ResetWarStatistics( i );

	        WarTDControl( i, false );
		}
	}
	WARInfo[ w ][ warTeamMembers ][ 0 ] = 0;
    WARInfo[ w ][ warTeamMembers ][ 1 ] = 0;
    WARInfo[ w ][ warTeamScore ][ 0 ] = 0;
    WARInfo[ w ][ warTeamScore ][ 1 ] = 0;
	return true;
}

public StopWARTimer( w ) {
    if( WARInfo[ w ][ warActive ] == false ) { WARInfo[ w ][ warTimerMin ] = 1; WARInfo[ w ][ warTimerSec ] = 0; KillTimer( WARInfo[ w ][ warTimerTime ] ); }
    WARInfo[ w ][ warTimerSec ]++;
    if( WARInfo[ w ][ warTimerSec ] == 60 ) { WARInfo[ w ][ warTimerMin ]++; WARInfo[ w ][ warTimerSec ] = 0; }
    foreach( Player, i ) {
        if( WARPInfo[ i ][ warID ] == w ) {
            new vreme_string[ 10 ];
		    if( WARInfo[ w ][ warTimerSec ] >= 51 ) {
           		format( vreme_string, sizeof( vreme_string ), "%d:0%d",10*60000/60000 - WARInfo[ w ][ warTimerMin ], 10*60000/10000 - WARInfo[ w ][ warTimerSec ] );
		    }
		    else if( WARInfo[ w ][ warTimerMin ] >= 6 ) {
           		format( vreme_string, sizeof( vreme_string ), "0%d:%d",10*60000/60000 - WARInfo[ w ][ warTimerMin ], 10*60000/10000 - WARInfo[ w ][ warTimerSec ] );
		    }
			else if( WARInfo[ w ][ warTimerSec ] >= 51 && WARInfo[ w ][ warTimerMin ] >= 6) {
           		format( vreme_string, sizeof( vreme_string ), "0%d:0%d",10*60000/60000 - WARInfo[ w ][ warTimerMin ], 10*60000/10000 - WARInfo[ w ][ warTimerSec ] );
			}
			else {
           		format( vreme_string, sizeof( vreme_string ), "%d:%d",10*60000/60000 - WARInfo[ w ][ warTimerMin ], 10*60000/10000 - WARInfo[ w ][ warTimerSec ] );
			}
			PlayerTextDrawSetString( i, WARTextDraw[ i ][ 8 ],  vreme_string );
    	}
    }
    return true;
}

public OnPlayerConnect( playerid ) {

    ResetWarStatistics( playerid );
    CreatingWAR[ playerid ] = -1;
    
	return true;
}

public OnPlayerDisconnect( playerid, reason ) {

	if( WARPInfo[ playerid ][ warTeam ][ 0 ] == true ) {
        format( globalstring, sizeof( globalstring ), ""COL_ORANGE"WAR | "COL_TEAM1"%s: "COL_WHITE"leave server.", GetName( playerid ) );
        WARMessage( WARPInfo[ playerid ][ warID ], -1, globalstring );
		WARInfo[ WARPInfo[ playerid ][ warID ] ][ warTeamMembers ][ 0 ]--;
	}

	if( WARPInfo[ playerid ][ warTeam ][ 1 ] == true ) {
        format( globalstring, sizeof( globalstring ), ""COL_ORANGE"WAR | "COL_TEAM2"%s: "COL_WHITE"leave server.", GetName( playerid ) );
        WARMessage( WARPInfo[ playerid ][ warID ], -1, globalstring );
		WARInfo[ WARPInfo[ playerid ][ warID ] ][ warTeamMembers ][ 1 ]--;
	}
	
	return true;
}

public OnPlayerSpawn( playerid ) {
	if( WARPInfo[ playerid ][ warID ] != -1 ) {
	    new w = WARPInfo[ playerid ][ warID ];

		SetPlayerVirtualWorld( playerid, w );
		SetPlayerHealth( playerid, 100 );
		if( WARInfo[ w ][ warMap ] == 1 ) {
		    new rand1 = random( sizeof( warMap1Team1 ) );
		    new rand2 = random( sizeof( warMap1Team2 ) );
		    if( WARPInfo[ playerid ][ warTeam ][ 0 ] == true ) { SetPlayerPos( playerid, warMap1Team1[ rand1 ][ 0 ], warMap1Team1[ rand1 ][ 1 ],warMap1Team1[ rand1 ][ 2 ] ); }
		    else if( WARPInfo[ playerid ][ warTeam ][ 1 ] == true ) { SetPlayerPos( playerid, warMap1Team2[ rand2 ][ 0 ], warMap1Team2[ rand2 ][ 1 ],warMap1Team2[ rand2 ][ 2 ] ); }
			SetPlayerInterior( playerid, 0 );
		}
		else if( WARInfo[ w ][ warMap ] == 2 ) {
		    new rand1 = random( sizeof( warMap2Team1 ) );
		    new rand2 = random( sizeof( warMap2Team2 ) );
		    if( WARPInfo[ playerid ][ warTeam ][ 0 ] == true ) { SetPlayerPos( playerid, warMap2Team1[ rand1 ][ 0 ], warMap2Team1[ rand1 ][ 1 ],warMap2Team1[ rand1 ][ 2 ] ); }
		    else if( WARPInfo[ playerid ][ warTeam ][ 1 ] == true ) { SetPlayerPos( playerid, warMap2Team2[ rand2 ][ 0 ], warMap2Team2[ rand2 ][ 1 ],warMap2Team2[ rand2 ][ 2 ] ); }
			SetPlayerInterior( playerid, 10 );
		}
		else if( WARInfo[ w ][ warMap ] == 3 ) {
		    new rand1 = random( sizeof( warMap3Team1 ) );
		    new rand2 = random( sizeof( warMap3Team2 ) );
		    if( WARPInfo[ playerid ][ warTeam ][ 0 ] == true ) { SetPlayerPos( playerid, warMap3Team1[ rand1 ][ 0 ], warMap3Team1[ rand1 ][ 1 ],warMap3Team1[ rand1 ][ 2 ] ); }
		    else if( WARPInfo[ playerid ][ warTeam ][ 1 ] == true ) { SetPlayerPos( playerid, warMap3Team2[ rand2 ][ 0 ], warMap3Team2[ rand2 ][ 1 ],warMap3Team2[ rand2 ][ 2 ] ); }
            SetPlayerInterior( playerid, 0 );
		}
		else if( WARInfo[ w ][ warMap ] == 4 ) {
		    new rand1 = random( sizeof( warMap4Team1 ) );
		    new rand2 = random( sizeof( warMap4Team2 ) );
		    if( WARPInfo[ playerid ][ warTeam ][ 0 ] == true ) { SetPlayerPos( playerid, warMap4Team1[ rand1 ][ 0 ], warMap4Team1[ rand1 ][ 1 ], warMap4Team1[ rand1 ][ 2 ] ); }
		    else if( WARPInfo[ playerid ][ warTeam ][ 1 ] == true ) { SetPlayerPos( playerid, warMap4Team2[ rand2 ][ 0 ], warMap4Team2[ rand2 ][ 1 ], warMap4Team2[ rand2 ][ 2 ] ); }
            SetPlayerInterior( playerid, 0 );
		}
		else if( WARInfo[ w ][ warMap ] == 5 ) {
		    new rand1 = random( sizeof( warMap5Team1 ) );
		    new rand2 = random( sizeof( warMap5Team2 ) );
		    if( WARPInfo[ playerid ][ warTeam ][ 0 ] == true ) { SetPlayerPos( playerid, warMap5Team1[ rand1 ][ 0 ], warMap5Team1[ rand1 ][ 1 ],warMap5Team1[ rand1 ][ 2 ] ); }
		    else if( WARPInfo[ playerid ][ warTeam ][ 1 ] == true ) { SetPlayerPos( playerid, warMap5Team2[ rand2 ][ 0 ], warMap5Team2[ rand2 ][ 1 ],warMap5Team2[ rand2 ][ 2 ] ); }
		    SetPlayerInterior( playerid, 0 );
		}
		GivePlayerWeapon( playerid, WARInfo[ w ][ warGuns ][ 0 ], 300 );
		GivePlayerWeapon( playerid, WARInfo[ w ][ warGuns ][ 1 ], 300 );
		GivePlayerWeapon( playerid, WARInfo[ w ][ warGuns ][ 2 ], 300 );
		GivePlayerWeapon( playerid, WARInfo[ w ][ warGuns ][ 3 ], 300 );
		return true;
    }
	return true;
}

public OnPlayerDeath( playerid, killerid, reason ) {
    for(new w = 1; w < MAX_WARS; w ++) {
	    if( killerid != INVALID_PLAYER_ID ) {
			if( WARInfo[ w ][ warActive ] == true && WARPInfo[ playerid ][ warID ] == w && WARPInfo[ killerid ][ warID ] == w ) {
				WARPInfo[ killerid ][ warKills ]++;
			   	WARPInfo[ playerid ][ warDeaths ]++;
				if( WARPInfo[ playerid ][ warTeam ][ 0 ] == true && WARPInfo[ killerid ][ warTeam ][ 0 ] == true ) {
					WARInfo[ w ][ warTeamScore ][ 0 ] -= 3;
                    format( globalstring, sizeof( globalstring ), ""COL_ORANGE"WAR "COL_WHITE"| "COL_TEAM1"%s "COL_WHITE"kill his teammate "COL_TEAM1"%s, "COL_WHITE"and his team lost 3 points.", GetName( killerid ), GetName( playerid ) );
					WARMessage( w, -1, globalstring );
			        SetWarStatsTD( w );
				}
				if( WARPInfo[ playerid ][ warTeam ][ 1 ] == true && WARPInfo[ killerid ][ warTeam ][ 1 ] == true ) {
					WARInfo[ w ][ warTeamScore ][ 1 ] -= 3;
			        format( globalstring, sizeof( globalstring ), ""COL_ORANGE"WAR "COL_WHITE"| "COL_TEAM2"%s "COL_WHITE"kill his teammate "COL_TEAM2"%s, "COL_WHITE"and his team lost 3 points.", GetName( killerid ), GetName( playerid ) );
			        WARMessage( w, -1, globalstring);
			        SetWarStatsTD( w );
				}
				if( WARPInfo[ killerid ][ warTeam ][ 0 ] == true && WARPInfo[ playerid ][ warTeam ][ 1 ] == true ) {
			        WARInfo[ w ][ warTeamScore ][ 0 ]++;
		           	format( globalstring, sizeof( globalstring ), ""COL_ORANGE"WAR "COL_WHITE"| "COL_TEAM1"%s "COL_WHITE"kill a opponent "COL_TEAM2"%s.", GetName( killerid ), GetName( playerid ) );
		           	WARMessage( w, -1, globalstring );
			        SetWarStatsTD( w );
				}
				if( WARPInfo[ killerid ][ warTeam ][ 1 ] == true && WARPInfo[ playerid ][ warTeam ][ 0 ] == true ) {
			        WARInfo[ w ][ warTeamScore ][ 1 ]++;
                    format( globalstring, sizeof( globalstring ), ""COL_ORANGE"WAR "COL_WHITE"| "COL_TEAM2"%s "COL_WHITE"kill a opponent "COL_TEAM1"%s.", GetName( killerid ), GetName( playerid ) );
					WARMessage( w, -1, globalstring );
			        SetWarStatsTD( w );
				}
				return true;
			}
		}
	}
	return true;
}

public OnDialogResponse( playerid, dialogid, response, listitem, inputtext[] ) {

	if( dialogid == dialog_WAR && response ) {
        if( listitem == 0 ) { SPD( playerid, dialog_WAR_CREATE_1, DSL, "Chose map", "Map 1 - Abandoned\nMap 2 - RC Battlefield\nMap 3 - Skladiste\nMap 4 - United\nMap 5 - Farm", "Ok", "Cancel"); }
        if( listitem == 1 ) { SPD( playerid, dialog_WARINVITE, DSI, "Invite player", "Input id of player", "Ok", "Cancel" ); }
        if( listitem == 2 ) { SPD( playerid, dialog_WARUNINVITE, DSI, "Uninvite player", "Input id of player", "Ok", "Cancel" ); }
    }
    else if( dialogid == dialog_WARUNINVITE && response ) {
        if( WARPInfo[ playerid ][ warID ] == -1 ) return SendErrorMessage( playerid, "You are not in war." );
        new player, w = WARPInfo[ playerid ][ warID ];
		if( sscanf( inputtext, "u", player ) ) return SPD( playerid, dialog_WARUNINVITE, DSI, "Uninvite player", "Input id of player", "Ok", "Cancel" );
        if( WARInfo[ w ][ warActive ] == false ) return SendErrorMessage( playerid, "War is not started yet.");
        if( player == IPI ) return SPD( playerid, dialog_WARUNINVITE, DSI, "Uninvite player", "Input id of player", "Ok", "Cancel" );
        if( WARPInfo[ player ][ warID ] == -1 ) return SPD( playerid, dialog_WARUNINVITE, DSI, "Uninvite player", "Input id of player", "Ok", "Cancel" );
		WARPInfo[ player ][ warID ] = -1;
        SetPlayerHealth( player, 100 );

        SetPlayerPos( player, WARPInfo[ player ][ LastPosition ][ 0 ], WARPInfo[ player ][ LastPosition ][ 1 ],  WARPInfo[ player ][ LastPosition ][ 2 ] );
        SetPlayerVirtualWorld( player, WARPInfo[ player ][ LastVirtualWorld ] );
	    SetPlayerInterior( player, WARPInfo[ player ][ LastInterior ] );
		ResetPlayerWeapons( player );

        ResetWarStatistics( player );
        if( WARPInfo[ playerid ][ warTeam ][ 0 ] == true ) { WARInfo[ w ][ warTeamMembers ][ 0 ]--; }
        if( WARPInfo[ playerid ][ warTeam ][ 1 ] == true ) { WARInfo[ w ][ warTeamMembers ][ 1 ]--; }

        SCM( playerid, -1, "Izbacio si clana." );

        WarTDControl( player, false );
	}
    else if( dialogid == dialog_WARINVITE && response ) {
		if( WARPInfo[ playerid ][ warID ] == -1 ) return SendErrorMessage( playerid, "You are not in war." );
        new player, w = WARPInfo[ playerid ][ warID ];
		if( sscanf( inputtext, "u", player ) ) return SPD( playerid, dialog_WARINVITE, DSI, "Invite player", "Input id of player", "Ok", "Cancel" );
        if( WARInfo[ w ][ warActive ] == false ) return SendErrorMessage( playerid, "War is not started yet.");
		if( player == playerid ) return SPD( playerid, dialog_WARINVITE, DSI, "Invite player", "Input id of player", "Ok", "Cancel" );
        if( player == IPI ) return SPD( playerid, dialog_WARINVITE, DSI, "Invite player", "Input id of player", "Ok", "Cancel" );
		if( WARPInfo[ player ][ warID ] != -1 ) return SPD( playerid, dialog_WARINVITE, DSI, "Invite player", "Input id of player", "Ok", "Cancel" );
		if( WARPInfo[ playerid ][ warTeam ][ 0 ] == true ) {
			if( WARInfo[ w ][ warTeamMembers ][ 0 ] >= WARInfo[ w ][ warMapMembers ] ) return SendErrorMessage(playerid, "You already have a maximum number of players in war.");

			GetPlayerPos( player, WARPInfo[ player ][ LastPosition ][ 0 ], WARPInfo[ player ][ LastPosition ][ 1 ],  WARPInfo[ player ][ LastPosition ][ 2 ] );
			WARPInfo[ player ][ LastVirtualWorld ] = GetPlayerVirtualWorld( player );
			WARPInfo[ player ][ LastInterior ] = GetPlayerInterior( player );
			
            new rand1 = random( sizeof( warMap1Team1 ) );
            new rand21 = random( sizeof( warMap2Team1 ) );
            new rand31 = random( sizeof( warMap3Team1 ) );
            new rand41 = random( sizeof( warMap4Team1 ) );
            new rand51 = random( sizeof( warMap5Team1 ) );
            if( WARInfo[ w ][ warMap ] == 1 ) {
				SetPlayerPos( player, warMap1Team1[ rand1 ][ 0 ], warMap1Team1[ rand1 ][ 1 ],warMap1Team1[ rand1 ][ 2 ] );
                SetPlayerInterior( player, 0 );
			}
            else if( WARInfo[ w ][ warMap ] == 2 ) {
				SetPlayerPos( player, warMap2Team1[ rand21 ][ 0 ], warMap2Team1[ rand21 ][ 1 ],warMap2Team1[ rand21 ][ 2 ] );
				SetPlayerInterior( player, 10 );
			}
            else if( WARInfo[ w ][ warMap ] == 3 ) {
				SetPlayerPos( player, warMap3Team1[ rand31 ][ 0 ], warMap3Team1[ rand31 ][ 1 ],warMap3Team1[ rand31 ][ 2 ] );
				SetPlayerInterior( player, 0 );
			}
            else if( WARInfo[ w ][ warMap ] == 4 ) {
				SetPlayerPos( player, warMap4Team1[ rand41 ][ 0 ], warMap4Team1[ rand41 ][ 1 ],warMap4Team1[ rand41 ][ 2 ] );
				SetPlayerInterior( player, 0 );
			}
            else if( WARInfo[ w ][ warMap ] == 5 ) {
				SetPlayerPos( player, warMap5Team1[ rand51 ][ 0 ], warMap5Team1[ rand51 ][ 1 ],warMap5Team1[ rand51 ][ 2 ] );
				SetPlayerInterior( player, 0 );
			}


			GivePlayerWeapon( player, WARInfo[ w ][ warGuns ][ 0 ], 300 );
			GivePlayerWeapon( player, WARInfo[ w ][ warGuns ][ 1 ], 300 );
			GivePlayerWeapon( player, WARInfo[ w ][ warGuns ][ 2 ], 300 );
			GivePlayerWeapon( player, WARInfo[ w ][ warGuns ][ 3 ], 300 );
			SetPlayerVirtualWorld( player, w );
			SetPlayerHealth( player, 100 );

			WARInfo[ w ][ warTeamMembers ][ 0 ]++;

			ResetWarStatistics( player );
    		WARPInfo[ player ][ warTeam ][ 0 ] = true;
    		WARPInfo[ player ][ warID ] = w;
    		format( globalstring, sizeof( globalstring ), ""COL_ORANGE"WAR "COL_WHITE"| "COL_ORANGE"Team 1: "COL_WHITE"%s "COL_WHITE"| "COL_ORANGE"Team 2: "COL_WHITE"%s", getOrgName( GetPlayerMember( WARInfo[ w ][ warTeamLeader ][ 0 ] ) ), getOrgName( GetPlayerMember( WARInfo[ w ][ warTeamLeader ][ 1 ] ) ) );
  		    SCM( player, -1, globalstring );
    		SCM( player, -1, "War chat /wp." );
    		SCM( playerid, -1,"You invite a member." );

    		WarTDControl( player, true );
    		SetWarStatsTD( w );
		}
		else if( WARPInfo[ playerid ][ warTeam ][ 1 ] == true ) {
			if( WARInfo[ w ][ warTeamMembers ][ 1 ] >= WARInfo[ w ][ warMapMembers ] ) return SendErrorMessage(playerid, "Imate maksimalan broj clanova u waru!");

			GetPlayerPos( player, WARPInfo[ player ][ LastPosition ][ 0 ], WARPInfo[ player ][ LastPosition ][ 1 ],  WARPInfo[ player ][ LastPosition ][ 2 ] );
			WARPInfo[ player ][ LastVirtualWorld ] = GetPlayerVirtualWorld( player );
			WARPInfo[ player ][ LastInterior ] = GetPlayerInterior( player );

		    new rand2 = random( sizeof( warMap1Team2 ) );
		    new rand22 = random( sizeof( warMap2Team2 ) );
		    new rand32 = random( sizeof( warMap3Team2 ) );
		    new rand42 = random( sizeof( warMap4Team2 ) );
		    new rand52 = random( sizeof( warMap5Team2 ) );
            if( WARInfo[ w ][ warMap ] == 1 ) {
				SetPlayerPos( player, warMap1Team2[ rand2 ][ 0 ], warMap1Team2[ rand2 ][ 1 ],warMap1Team2[ rand2 ][ 2 ] );
				SetPlayerInterior( player, 0 );
			}
            else if( WARInfo[ w ][ warMap ] == 2 ) {
				SetPlayerPos( player, warMap2Team2[ rand22 ][ 0 ], warMap2Team2[ rand22 ][ 1 ],warMap2Team2[ rand22 ][ 2 ] );
				SetPlayerInterior( player, 10 );
			}
            else if( WARInfo[ w ][ warMap ] == 3 ) {
				SetPlayerPos( player, warMap3Team2[ rand32 ][ 0 ], warMap3Team2[ rand32 ][ 1 ],warMap3Team2[ rand32 ][ 2 ] );
                SetPlayerInterior( player, 0 );
			}
            else if( WARInfo[ w ][ warMap ] == 4 ) {
				SetPlayerPos( player, warMap4Team2[ rand42 ][ 0 ], warMap4Team2[ rand42 ][ 1 ],warMap4Team2[ rand42 ][ 2 ] );
				SetPlayerInterior( player, 0 );
			}
            else if( WARInfo[ w ][ warMap ] == 5 ) {
				SetPlayerPos( player, warMap5Team2[ rand52 ][ 0 ], warMap5Team2[ rand52 ][ 1 ],warMap5Team2[ rand52 ][ 2 ] );
				SetPlayerInterior( player, 0 );
			}

			GivePlayerWeapon( player, WARInfo[ w ][ warGuns ][ 0 ], 300 );
			GivePlayerWeapon( player, WARInfo[ w ][ warGuns ][ 1 ], 300 );
			GivePlayerWeapon( player, WARInfo[ w ][ warGuns ][ 2 ], 300 );
			GivePlayerWeapon( player, WARInfo[ w ][ warGuns ][ 3 ], 300 );
			SetPlayerVirtualWorld( player, w );
			SetPlayerHealth( player, 100 );

			WARInfo[ w ][ warTeamMembers ][ 1 ]++;

			ResetWarStatistics( player );
    		WARPInfo[ player ][ warTeam ][ 1 ] = true;
    		WARPInfo[ player ][ warID ] = w;

    		format( globalstring, sizeof( globalstring ), ""COL_ORANGE"WAR "COL_WHITE"| "COL_ORANGE"Team 1: "COL_WHITE"%s "COL_WHITE"| "COL_ORANGE"Team 2: "COL_WHITE"%s", getOrgName( GetPlayerMember( WARInfo[ w ][ warTeamLeader ][ 0 ] ) ), getOrgName( GetPlayerMember( WARInfo[ w ][ warTeamLeader ][ 1 ] ) ) );
  		    SCM( player, -1, globalstring );
    		SCM( player, -1, "War chat /wp." );
    		SCM( playerid, -1, "You invite a member." );

    		WarTDControl( player, true );
    		SetWarStatsTD( w );
		}
	}
    else if( dialogid == dialog_WAR_CREATE_1 && response) {
        new warid = -1;
		for(new w = 1; w < MAX_WARS; w ++) {
			if( WARInfo[ w ][ warActive ] == false && WARInfo[ w ][ warCreating ] == false ) {
			    warid = w;
			    break;
			}
		}
		if( warid == -1 ) { 
            format( globalstring, sizeof( globalstring ), "ERROR | "COL_WHITE"Already have %d started wars, wait for someone to finish.", MAX_WARS );
			SCM( playerid, COLOR_RED, globalstring );
            return true;
		}
		CreatingWAR[ playerid ] = warid;
		WARInfo[ warid ][ warCreating ] = true;
        WARInfo[ warid ][ warActive ] = false;
        if( listitem == 0 ) { WARInfo[ warid ][ warMap ] = 1; }
		if( listitem == 1 ) { WARInfo[ warid ][ warMap ] = 2; }
		if( listitem == 2 ) { WARInfo[ warid ][ warMap ] = 3; }
		if( listitem == 3 ) { WARInfo[ warid ][ warMap ] = 4; }
		if( listitem == 4 ) { WARInfo[ warid ][ warMap ] = 5; }
        SPD( playerid, dialog_WAR_CREATE_2, DSL, "Chose weapon for slot 1", "Deagle\nColt 45\nSilenced Pistol", "Ok", "Cancel" );
	}
	else if( dialogid == dialog_WAR_CREATE_2 ) {
		if( response ) {
		    new w = CreatingWAR[ playerid ];
		    if( listitem == 0 ) { WARInfo[ w ][ warGuns ][ 0 ] = 24; }
		    if( listitem == 1 ) { WARInfo[ w ][ warGuns ][ 0 ] = 22; }
		    if( listitem == 2 ) { WARInfo[ w ][ warGuns ][ 0 ] = 23; }
		    SPD( playerid, dialog_WAR_CREATE_3, DSL, "Chose weapon for slot 2", "Uzi\nMP5", "Ok", "Cancel");
		}
		else if( !response ) {
		    new w = CreatingWAR[ playerid ];
			WARInfo[ w ][ warCreating ] = false;
	        WARInfo[ w ][ warActive ] = false;
	        CreatingWAR[ playerid ] = -1;
		}
	}
	else if( dialogid == dialog_WAR_CREATE_3 ) {
		if( response ) {
		    new w = CreatingWAR[ playerid ];
		    if( listitem == 0 ) { WARInfo[ w ][ warGuns ][ 1 ] = 28; }
		    if( listitem == 1 ) { WARInfo[ w ][ warGuns ][ 1 ] = 29; }
		    SPD( playerid, dialog_WAR_CREATE_4, DSL, "Chose weapon for slot 3", "AK-47\nM4", "Ok", "Cancel");
		}
		else if( !response ) {
		    new w = CreatingWAR[ playerid ];
			WARInfo[ w ][ warCreating ] = false;
	        WARInfo[ w ][ warActive ] = false;
	        CreatingWAR[ playerid ] = -1;
		}
	}
	else if( dialogid == dialog_WAR_CREATE_4 ) {
		if( response ) {
		    new w = CreatingWAR[ playerid ];
		    if( listitem == 0 ) { WARInfo[ w ][ warGuns ][ 2 ] = 30; }
		    if( listitem == 1 ) { WARInfo[ w ][ warGuns ][ 2 ] = 31; }
		    SPD( playerid, dialog_WAR_CREATE_5, DSL, "Chose weapon for slot 4", "Country Rifle\nShotgun", "Ok", "Cancel");
		}
		else if( !response ) {
		    new w = CreatingWAR[ playerid ];
			WARInfo[ w ][ warCreating ] = false;
	        WARInfo[ w ][ warActive ] = false;
	        CreatingWAR[ playerid ] = -1;
		}
	}
	else if( dialogid == dialog_WAR_CREATE_5 ) {
		if( response ) {
		    new w = CreatingWAR[ playerid ];
		    if( listitem == 0 ) { WARInfo[ w ][ warGuns ][ 3 ] = 33; }
		    if( listitem == 1 ) { WARInfo[ w ][ warGuns ][ 3 ] = 25; }
		    SPD( playerid, dialog_WAR_CREATE_6, DSI, "Maximum members", "Input a number of maximum allowed members to play a war(3-10).", "Ok", "Cancel");
		}
		else if( !response ) {
		    new w = CreatingWAR[ playerid ];
			WARInfo[ w ][ warCreating ] = false;
	        WARInfo[ w ][ warActive ] = false;
	        CreatingWAR[ playerid ] = -1;
		}
	}
	else if( dialogid == dialog_WAR_CREATE_6 ) {
	    if( response ) {
		    new maxigraca, w = CreatingWAR[ playerid ];
			if( sscanf( inputtext, "i", maxigraca ) ) return SPD( playerid, dialog_WAR_CREATE_6, DSI, "Maximum members", "Input a number of maximum allowed members to play a war(3-10).", "Ok", "Cancel");
			if( maxigraca < 3 || maxigraca > 10 ) return SPD( playerid, dialog_WAR_CREATE_6, DSI, "Maximum members", "Input a number of maximum allowed members to play a war(3-10).", "Ok", "Cancel");
	        WARInfo[ w ][ warMapMembers ] = maxigraca;
	        SPD( playerid, dialog_WAR_CREATE_7, DSI, "Leader of opponents", "Input id of opponents leader.", "Ok", "Cancel" );
		}
		else if( !response ) {
		    new w = CreatingWAR[ playerid ];
			WARInfo[ w ][ warCreating ] = false;
	        WARInfo[ w ][ warActive ] = false;
	        CreatingWAR[ playerid ] = -1;
		}
	}
	else if( dialogid == dialog_WAR_CREATE_7 ) {
	    if( response ) {
		    new id, w = CreatingWAR[ playerid ], string[ 128 ];
			if( sscanf( inputtext, "u", id ) ) return SPD( playerid, dialog_WAR_CREATE_7, DSI, "Leader of opponents", "Input id of opponents leader.", "Ok", "Cancel" );
			if( id == IPI ) return SPD( playerid, dialog_WAR_CREATE_7, DSI, "Leader of opponents", "Input id of opponents leader.", "Ok", "Cancel" );
			if( GetPlayerLeader( playerid ) == GetPlayerLeader( id ) ) return SPD( playerid, dialog_WAR_CREATE_7, DSI, "Leader of opponents", "Input id of opponents leader.", "Ok", "Cancel" );
			if( GetPlayerLeader( id ) < 1 ) return SPD( playerid, dialog_WAR_CREATE_7, DSI, "Leader of opponents", "Input id of opponents leader.", "Ok", "Cancel" );
			if( id == playerid ) return SPD( playerid, dialog_WAR_CREATE_7, DSI, "Leader of opponents", "Input id of opponents leader.", "Ok", "Cancel" );
			WARInfo[ w ][ warTeamLeader ][ 0 ] = playerid;
			WARInfo[ w ][ warTeamLeader ][ 1 ] = id;
            CreatingWAR[ id ] = w;
			format( string, sizeof( string ), ""COL_ORANGE"Leader of"COL_WHITE"%s "COL_ORANGE"sent u a request for war. Chose:", getOrgName( GetPlayerMember( playerid ) ) );
			SPD( id, dialog_WAR_CREATE_8, DSMSG, "Request for war", string, "Accept", "Cancel" );
        }
		else if( !response ) {
		    new w = CreatingWAR[ playerid ];
			WARInfo[ w ][ warCreating ] = false;
	        WARInfo[ w ][ warActive ] = false;
	        CreatingWAR[ playerid ] = -1;
		}
	}
	else if( dialogid == dialog_WAR_CREATE_8 ) {
	    if( response ) {
	        new w = CreatingWAR[ playerid ];
	        SCM( WARInfo[ w ][ warTeamLeader ][ 1 ], -1, ""COL_ORANGE"WAR | "COL_WHITE"You accept war request, now invite your players.");
	        SCM( WARInfo[ w ][ warTeamLeader ][ 0 ], -1, ""COL_ORANGE"WAR | "COL_WHITE"Player accept war request, now invite your players.");

            GetPlayerPos( WARInfo[ w ][ warTeamLeader ][ 0 ], WARPInfo[ WARInfo[ w ][ warTeamLeader ][ 0 ] ][ LastPosition ][ 0 ], WARPInfo[ WARInfo[ w ][ warTeamLeader ][ 0 ] ][ LastPosition ][ 1 ],  WARPInfo[ WARInfo[ w ][ warTeamLeader ][ 0 ] ][ LastPosition ][ 2 ] );
			WARPInfo[ WARInfo[ w ][ warTeamLeader ][ 0 ] ][ LastVirtualWorld ] = GetPlayerVirtualWorld( WARInfo[ w ][ warTeamLeader ][ 0 ] );
            WARPInfo[ WARInfo[ w ][ warTeamLeader ][ 0 ] ][ LastInterior ] = GetPlayerInterior( WARInfo[ w ][ warTeamLeader ][ 0 ] );

            GetPlayerPos( WARInfo[ w ][ warTeamLeader ][ 1 ], WARPInfo[ WARInfo[ w ][ warTeamLeader ][ 1 ] ][ LastPosition ][ 0 ], WARPInfo[ WARInfo[ w ][ warTeamLeader ][ 1 ] ][ LastPosition ][ 1 ],  WARPInfo[ WARInfo[ w ][ warTeamLeader ][ 1 ] ][ LastPosition ][ 2 ] );
            WARPInfo[ WARInfo[ w ][ warTeamLeader ][ 1 ] ][ LastVirtualWorld ] = GetPlayerVirtualWorld( WARInfo[ w ][ warTeamLeader ][ 0 ] );
            WARPInfo[ WARInfo[ w ][ warTeamLeader ][ 1 ] ][ LastInterior ] = GetPlayerInterior( WARInfo[ w ][ warTeamLeader ][ 1 ] );

            if( WARInfo[ w ][ warMap ] == 1 ) {
                new rand1 = random( sizeof( warMap1Team1 ) );
		    	new rand2 = random( sizeof( warMap1Team2 ) );
                SetPlayerPos( WARInfo[ w ][ warTeamLeader ][ 0 ], warMap1Team1[ rand1 ][ 0 ], warMap1Team1[ rand1 ][ 1 ],warMap1Team1[ rand1 ][ 2 ] );
            	SetPlayerPos( WARInfo[ w ][ warTeamLeader ][ 1 ], warMap1Team2[ rand2 ][ 0 ], warMap1Team2[ rand2 ][ 1 ],warMap1Team2[ rand2 ][ 2 ] );
                SetPlayerInterior( WARInfo[ w ][ warTeamLeader ][ 0 ], 0 );
                SetPlayerInterior( WARInfo[ w ][ warTeamLeader ][ 1 ], 0 );
			}
            else if( WARInfo[ w ][ warMap ] == 2 ) {
                new rand1 = random( sizeof( warMap2Team1 ) );
		    	new rand2 = random( sizeof( warMap2Team2 ) );
		    	SetPlayerPos( WARInfo[ w ][ warTeamLeader ][ 0 ], warMap2Team1[ rand1 ][ 0 ], warMap2Team1[ rand1 ][ 1 ],warMap2Team1[ rand1 ][ 2 ] );
		    	SetPlayerPos( WARInfo[ w ][ warTeamLeader ][ 1 ], warMap2Team2[ rand2 ][ 0 ], warMap2Team2[ rand2 ][ 1 ],warMap2Team2[ rand2 ][ 2 ] );
                SetPlayerInterior( WARInfo[ w ][ warTeamLeader ][ 0 ], 10 );
                SetPlayerInterior( WARInfo[ w ][ warTeamLeader ][ 1 ], 10 );
			}
			else if( WARInfo[ w ][ warMap ] == 3 ) {
			    new rand1 = random( sizeof( warMap3Team1 ) );
		    	new rand2 = random( sizeof( warMap3Team2 ) );
                SetPlayerPos( WARInfo[ w ][ warTeamLeader ][ 0 ], warMap3Team1[ rand1 ][ 0 ], warMap3Team1[ rand1 ][ 1 ],warMap3Team1[ rand1 ][ 2 ] );
            	SetPlayerPos( WARInfo[ w ][ warTeamLeader ][ 1 ], warMap3Team2[ rand2 ][ 0 ], warMap3Team2[ rand2 ][ 1 ],warMap3Team2[ rand2 ][ 2 ] );
             	SetPlayerInterior( WARInfo[ w ][ warTeamLeader ][ 0 ], 0 );
                SetPlayerInterior( WARInfo[ w ][ warTeamLeader ][ 1 ], 0 );
			}
			else if( WARInfo[ w ][ warMap ] == 4 ) {
			    new rand1 = random( sizeof( warMap4Team1 ) );
		    	new rand2 = random( sizeof( warMap4Team2 ) );
                SetPlayerPos( WARInfo[ w ][ warTeamLeader ][ 0 ], warMap4Team1[ rand1 ][ 0 ], warMap4Team1[ rand1 ][ 1 ],warMap4Team1[ rand1 ][ 2 ] );
            	SetPlayerPos( WARInfo[ w ][ warTeamLeader ][ 1 ], warMap4Team2[ rand2 ][ 0 ], warMap4Team2[ rand2 ][ 1 ],warMap4Team2[ rand2 ][ 2 ] );
            	SetPlayerInterior( WARInfo[ w ][ warTeamLeader ][ 0 ], 0 );
                SetPlayerInterior( WARInfo[ w ][ warTeamLeader ][ 1 ], 0 );
			}
			else if( WARInfo[ w ][ warMap ] == 5 ) {
			    new rand1 = random( sizeof( warMap5Team1 ) );
		    	new rand2 = random( sizeof( warMap5Team2 ) );
                SetPlayerPos( WARInfo[ w ][ warTeamLeader ][ 0 ], warMap5Team1[ rand1 ][ 0 ], warMap5Team1[ rand1 ][ 1 ],warMap5Team1[ rand1 ][ 2 ] );
            	SetPlayerPos( WARInfo[ w ][ warTeamLeader ][ 1 ], warMap5Team2[ rand2 ][ 0 ], warMap5Team2[ rand2 ][ 1 ],warMap5Team2[ rand2 ][ 2 ] );
                SetPlayerInterior( WARInfo[ w ][ warTeamLeader ][ 0 ], 0 );
                SetPlayerInterior( WARInfo[ w ][ warTeamLeader ][ 1 ], 0 );
			}

			WARInfo[ w ][ warActive ] = true;

			GivePlayerWeapon( WARInfo[ w ][ warTeamLeader ][ 0 ], WARInfo[ w ][ warGuns ][ 0 ], 300 );
			GivePlayerWeapon( WARInfo[ w ][ warTeamLeader ][ 0 ], WARInfo[ w ][ warGuns ][ 1 ], 300 );
			GivePlayerWeapon( WARInfo[ w ][ warTeamLeader ][ 0 ], WARInfo[ w ][ warGuns ][ 2 ], 300 );
			GivePlayerWeapon( WARInfo[ w ][ warTeamLeader ][ 0 ], WARInfo[ w ][ warGuns ][ 3 ], 300 );
			SetPlayerVirtualWorld( WARInfo[ w ][ warTeamLeader ][ 0 ], w );
			SetPlayerHealth( WARInfo[ w ][ warTeamLeader ][ 0 ], 100 );

			GivePlayerWeapon( WARInfo[ w ][ warTeamLeader ][ 1 ], WARInfo[ w ][ warGuns ][ 0 ], 300 );
			GivePlayerWeapon( WARInfo[ w ][ warTeamLeader ][ 1 ], WARInfo[ w ][ warGuns ][ 1 ], 300 );
			GivePlayerWeapon( WARInfo[ w ][ warTeamLeader ][ 1 ], WARInfo[ w ][ warGuns ][ 2 ], 300 );
			GivePlayerWeapon( WARInfo[ w ][ warTeamLeader ][ 1 ], WARInfo[ w ][ warGuns ][ 3 ], 300 );
			SetPlayerVirtualWorld( WARInfo[ w ][ warTeamLeader ][ 1 ], w );
			SetPlayerHealth( WARInfo[ w ][ warTeamLeader ][ 1 ], 100 );

			WARInfo[ w ][ warTeamMembers ][ 0 ]++;
			WARInfo[ w ][ warTeamMembers ][ 1 ]++;

			WARInfo[ w ][ warTimer ] = SetTimerEx( "StopWAR", 10*60000, false, "d", w );
			WARInfo[ w ][ warTimerMin ] = 1; WARInfo[ w ][ warTimerSec ] =0;
			WARInfo[ w ][ warTimerTime ] = SetTimerEx( "StopWARTimer", 1000, true, "d", w );

            ResetWarStatistics( WARInfo[ w ][ warTeamLeader ][ 0 ] );
    		WARPInfo[ WARInfo[ w ][ warTeamLeader ][ 0 ] ][ warTeam ][ 0 ] = true;
    		WARPInfo[ WARInfo[ w ][ warTeamLeader ][ 0 ] ][ warID ] = w;

            ResetWarStatistics( WARInfo[ w ][ warTeamLeader ][ 1 ] );
    		WARPInfo[ WARInfo[ w ][ warTeamLeader ][ 1 ] ][ warTeam ][ 1 ] = true;
			WARPInfo[ WARInfo[ w ][ warTeamLeader ][ 1 ] ][ warID ] = w;

    		format( globalstring, sizeof( globalstring ), ""COL_ORANGE"WAR "COL_WHITE"| "COL_ORANGE"Team 1: "COL_WHITE"%s "COL_WHITE"| "COL_ORANGE"Team 2: "COL_WHITE"%s", getOrgName( GetPlayerMember( WARInfo[ w ][ warTeamLeader ][ 0 ] ) ), getOrgName( GetPlayerMember( WARInfo[ w ][ warTeamLeader ][ 1 ] ) ) );
  		    SCM( WARInfo[ w ][ warTeamLeader ][ 0 ], -1, globalstring );
    		SCM( WARInfo[ w ][ warTeamLeader ][ 0 ], -1, "War chat /wp." );

    		format( globalstring, sizeof( globalstring ), ""COL_ORANGE"WAR "COL_WHITE"| "COL_ORANGE"Team 1: "COL_WHITE"%s "COL_WHITE"| "COL_ORANGE"Team 2: "COL_WHITE"%s", getOrgName( GetPlayerMember( WARInfo[ w ][ warTeamLeader ][ 0 ] ) ), getOrgName( GetPlayerMember( WARInfo[ w ][ warTeamLeader ][ 1 ] ) ) );
  		    SCM( WARInfo[ w ][ warTeamLeader ][ 1 ], -1, globalstring );
    		SCM( WARInfo[ w ][ warTeamLeader ][ 1 ], -1, "War chat /wp." );

    		WarTDControl( WARInfo[ w ][ warTeamLeader ][ 0 ], true );
			WarTDControl( WARInfo[ w ][ warTeamLeader ][ 1 ], true );
    		SetWarStatsTD( w );

		}
		else {
		    new w = CreatingWAR[ playerid ];
		    SCM( WARInfo[ w ][ warTeamLeader ][ 0 ], -1, "Opponent Leader cancel your request." );
			WARInfo[ w ][ warCreating ] = false;
	        WARInfo[ w ][ warActive ] = false;
	        CreatingWAR[ WARInfo[ w ][ warTeamLeader ][ 0 ] ] = -1;
	        CreatingWAR[ playerid ] = -1;
		}
	}
	return true;
}

CMD:wp( playerid, params[]) {
	new text[ 64 ];
	if( WARPInfo[ playerid ][ warID ] == -1 ) return SendErrorMessage( playerid, "You are not in war." );
 	if( sscanf( params, "s[64]", text ) ) return SendClientMessage( playerid, -1, "USAGE: /wp [ text ]" );
	if( WARPInfo[ playerid ][ warTeam ][ 0 ] == true ) {
		format( globalstring, sizeof( globalstring ), ""COL_ORANGE"WAR | "COL_TEAM1"%s: "COL_WHITE"%s", GetName( playerid ), text );
	}
	if( WARPInfo[ playerid ][ warTeam ][ 1 ] == true ) {
		format( globalstring, sizeof( globalstring ), ""COL_ORANGE"WAR | "COL_TEAM2"%s: "COL_WHITE"%s", GetName( playerid ), text );
	}
	WARMessage( WARPInfo[ playerid ][ warID ], -1, globalstring );
	return true;
}

CMD:war( playerid ) {
    if( GetPlayerLeader( playerid ) < 1) return SendErrorMessage( playerid, "You are not authorized." );
	SPD( playerid, dialog_WAR, DSL, "War System", "Create WAR\nInvite player in war\nUninvite player from war", "Ok", "Cancel");
	return true;
}