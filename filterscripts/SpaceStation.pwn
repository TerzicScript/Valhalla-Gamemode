#define FILTERSCRIPT

#include <a_samp>
#include <streamer>
#include <sscanf2>
#include <Pawn.CMD>
#include <pawnbots>

new doorcockpit;
new doorstorage[2];

new bool:door[3];

new sprayer[8];
new bool:sprayers;

new bool:generator;
new bool:ringstate;
new genring[3];
new rotdelay;

new button[4];

public OnFilterScriptInit()
{

	new tmpobjid;
    tmpobjid = CreateDynamicObject(19379, 1883.754760, 1469.286987, 1093.345458, 0.000000, 90.000000, 360.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gun_ceiling2_128", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(19715, 1884.333374, 1469.283325, 1093.509155, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_floorpanel1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(19715, 1884.333374, 1469.283325, 1097.739501, 180.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gun_ceiling2_128", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(18819, 1916.315429, 1469.253417, 1093.251586, 90.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 1, 2917, "a51_crane", "girder2_grey_64HV", 0x00000000);
    tmpobjid = CreateDynamicObject(18819, 1916.315429, 1469.253417, 1097.172607, 90.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 2917, "a51_crane", "girder2_grey_64HV", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 16640, "a51", "a51_floorpanel1", 0x00000000);
    tmpobjid = CreateDynamicObject(18810, 1958.051391, 1469.241088, 1093.118286, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 2917, "a51_crane", "girder2_grey_64HV", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 2917, "a51_crane", "girder2_grey_64HV", 0x00000000);
    tmpobjid = CreateDynamicObject(18810, 1958.051391, 1469.291137, 1097.099975, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_floorpanel1", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 16640, "a51", "a51_floorpanel1", 0x00000000);
    tmpobjid = CreateDynamicObject(19379, 1894.235107, 1469.286987, 1093.345458, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gun_ceiling2_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19379, 1904.735595, 1469.286987, 1093.345458, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gun_ceiling2_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19392, 1891.474731, 1469.259277, 1095.130737, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_floorpanel1", 0x00000000);
    tmpobjid = CreateDynamicObject(19368, 1891.477783, 1466.059204, 1095.130981, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_floorpanel1", 0x00000000);
    tmpobjid = CreateDynamicObject(19368, 1891.477783, 1472.468627, 1095.130981, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_floorpanel1", 0x00000000);
    tmpobjid = CreateDynamicObject(19456, 1892.703491, 1469.074096, 1098.038085, 0.000000, 45.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 2917, "a51_crane", "girder2_grey_64HV", 0x00000000);
    tmpobjid = CreateDynamicObject(19456, 1887.123413, 1473.506103, 1095.161987, 0.000000, 0.000000, 65.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_floorpanel1", 0x00000000);
    tmpobjid = CreateDynamicObject(19456, 1887.149780, 1465.123046, 1095.161987, 0.000000, 0.000000, -65.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_floorpanel1", 0x00000000);
    tmpobjid = CreateDynamicObject(19456, 1883.857788, 1464.642822, 1095.161987, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_floorpanel1", 0x00000000);
    tmpobjid = CreateDynamicObject(19456, 1883.857788, 1473.992797, 1095.161987, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_floorpanel1", 0x00000000);
    tmpobjid = CreateDynamicObject(19456, 1886.770385, 1472.346313, 1098.127197, 0.000006, -44.999996, 65.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 2917, "a51_crane", "girder2_grey_64HV", 0x00000000);
    tmpobjid = CreateDynamicObject(19456, 1886.633544, 1466.230590, 1098.128051, -0.000012, -44.999992, -65.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 2917, "a51_crane", "girder2_grey_64HV", 0x00000000);
    tmpobjid = CreateDynamicObject(19456, 1890.261840, 1467.673339, 1098.130126, 0.000000, -45.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 2917, "a51_crane", "girder2_grey_64HV", 0x00000000);
    tmpobjid = CreateDynamicObject(19456, 1883.857788, 1472.824584, 1098.105712, 0.000007, -45.000000, 89.999977, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 2917, "a51_crane", "girder2_grey_64HV", 0x00000000);
    tmpobjid = CreateDynamicObject(19456, 1883.857788, 1465.866577, 1098.126708, 0.000000, 45.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 2917, "a51_crane", "girder2_grey_64HV", 0x00000000);
    tmpobjid = CreateDynamicObject(19379, 1915.236328, 1469.286987, 1093.345458, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gun_ceiling2_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19379, 1925.728637, 1469.286987, 1093.345458, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gun_ceiling2_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19379, 1936.179443, 1469.286987, 1093.345458, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gun_ceiling2_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19379, 1915.236328, 1478.916503, 1093.345458, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gun_ceiling2_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19379, 1915.236328, 1488.534179, 1093.345458, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gun_ceiling2_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19379, 1904.735595, 1478.896484, 1093.345458, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gun_ceiling2_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19379, 1904.735595, 1459.656738, 1093.345458, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gun_ceiling2_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19379, 1915.236328, 1459.686279, 1093.345458, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gun_ceiling2_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19379, 1915.236328, 1450.085205, 1093.345458, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gun_ceiling2_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19379, 1925.728637, 1459.667480, 1093.345458, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gun_ceiling2_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19379, 1925.728637, 1478.906127, 1093.345458, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gun_ceiling2_128", 0x00000000);
    tmpobjid = CreateDynamicObject(13646, 1916.297973, 1469.147705, 1093.202514, 0.000000, 360.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 18065, "ab_sfammumain", "plate1", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 915, "airconext", "cj_plating3", 0x00000000);
    tmpobjid = CreateDynamicObject(13646, 1916.297973, 1469.147705, 1102.343872, 0.000000, 180.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor2", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 915, "airconext", "cj_plating3", 0x00000000);
    tmpobjid = CreateDynamicObject(18876, 1916.362670, 1469.076171, 1102.519775, 0.000000, 180.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 5150, "wiresetc_las2", "ganggraf01_LA_m", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 16640, "a51", "a51_pipeend", 0x00000000);
    tmpobjid = CreateDynamicObject(11729, 1913.234741, 1469.345214, 1092.810791, 0.000000, 0.000000, 91.199989, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_metal1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(19197, 1916.301025, 1469.140625, 1094.459106, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19527, "cauldron1", "alienliquid1", 0x00000000);
    tmpobjid = CreateDynamicObject(3885, 1916.289184, 1469.234497, 1093.211425, 0.000000, 0.000000, 16.300001, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "metpat64chev_128", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 3, 16640, "a51", "a51_metal1", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 4, 5150, "wiresetc_las2", "ganggraf01_LA_m", 0x00000000);
    tmpobjid = CreateDynamicObject(19478, 1912.978515, 1469.468505, 1094.722534, 0.000000, 0.000000, 2.000015, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_cardreader", 0x00000000);
    tmpobjid = CreateDynamicObject(1420, 1917.801391, 1474.427124, 1096.131958, 0.000000, 0.000000, 74.799987, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 13628, "8stad", "stadroof", 0x00000000);

    tmpobjid = CreateDynamicObject(1420, 1914.813354, 1474.466064, 1096.131958, 0.000000, 0.000000, 106.300018, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 13628, "8stad", "stadroof", 0x00000000);
    tmpobjid = CreateDynamicObject(1420, 1917.801391, 1474.427124, 1098.123779, 0.000007, 0.000001, 74.799980, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 13628, "8stad", "stadroof", 0x00000000);
    tmpobjid = CreateDynamicObject(19475, 1912.984008, 1469.342529, 1093.831542, -0.099999, 0.000000, 1.299999, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 10140, "frieghter2sfe", "sf_ship_pipes", 0x00000000);
    tmpobjid = CreateDynamicObject(19475, 1912.983520, 1469.337890, 1094.622192, 0.000000, 0.000000, 1.899992, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 11150, "ab_acc_control", "ab_dialsSwitches", 0x00000000);
    tmpobjid = CreateDynamicObject(19475, 1912.984008, 1469.342895, 1094.221801, -0.099999, 0.000000, 1.299999, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 10140, "frieghter2sfe", "sf_ship_pipes", 0x00000000);
    tmpobjid = CreateDynamicObject(1317, 1916.274780, 1469.136108, 1093.331298, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 13659, "8bars", "AH_gbarrier", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(7893, 1916.250854, 1465.229980, 1093.500000, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "ws_castironwalk", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(7893, 1916.250854, 1465.229980, 1094.170654, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 18996, "mattextures", "policeshieldgls", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(7893, 1916.250854, 1465.229980, 1094.849853, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "ws_castironwalk", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(3675, 1907.925537, 1469.271972, 1098.911987, 90.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "banding9_64HV", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(3675, 1924.713989, 1469.271972, 1098.911987, 90.000000, 0.000000, 450.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "banding9_64HV", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(3675, 1916.312500, 1477.632446, 1098.911987, 90.000000, 0.000000, 540.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "banding9_64HV", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(3675, 1916.312500, 1460.752685, 1098.911987, 90.000000, 0.000000, 720.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "banding9_64HV", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2960, 1914.774780, 1474.636352, 1098.402221, 0.000000, 90.000000, 107.000038, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor2", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2960, 1917.867675, 1474.607299, 1098.402221, 0.000000, 90.000000, 75.899978, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor2", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2960, 1917.867797, 1463.612792, 1098.402221, 0.000000, 90.000000, -72.999954, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor2", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2960, 1914.760253, 1463.583862, 1098.402221, 0.000000, 90.000000, -104.099990, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor2", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2960, 1921.789550, 1470.714477, 1098.462280, -0.000004, 90.000007, 17.000036, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor2", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2960, 1921.818481, 1467.606933, 1098.472290, -0.000009, 90.000007, -14.099998, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor2", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2960, 1910.806274, 1467.606811, 1098.452270, -0.000004, 90.000007, -162.999893, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor2", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2960, 1910.777343, 1470.714355, 1098.462280, -0.000009, 90.000007, 165.899902, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor2", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(1420, 1914.813354, 1474.466064, 1098.123779, 0.000007, -0.000001, 106.299995, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 13628, "8stad", "stadroof", 0x00000000);
    tmpobjid = CreateDynamicObject(1420, 1917.801391, 1474.427124, 1099.885375, 0.000014, 0.000003, 74.799980, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 13628, "8stad", "stadroof", 0x00000000);
    tmpobjid = CreateDynamicObject(1420, 1914.813354, 1474.466064, 1099.885375, 0.000014, -0.000003, 106.299972, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 13628, "8stad", "stadroof", 0x00000000);
    tmpobjid = CreateDynamicObject(1420, 1914.813354, 1463.804077, 1096.131958, 0.000000, 0.000000, -105.199981, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 13628, "8stad", "stadroof", 0x00000000);
    tmpobjid = CreateDynamicObject(1420, 1917.801391, 1463.765136, 1096.131958, 0.000000, 0.000000, -73.699981, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 13628, "8stad", "stadroof", 0x00000000);
    tmpobjid = CreateDynamicObject(1420, 1914.813354, 1463.804077, 1098.123779, 0.000007, 0.000001, -105.199989, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 13628, "8stad", "stadroof", 0x00000000);
    tmpobjid = CreateDynamicObject(1420, 1917.801391, 1463.765136, 1098.123779, 0.000007, -0.000001, -73.700012, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 13628, "8stad", "stadroof", 0x00000000);
    tmpobjid = CreateDynamicObject(1420, 1914.813354, 1463.804077, 1099.885375, 0.000014, 0.000003, -105.199989, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 13628, "8stad", "stadroof", 0x00000000);
    tmpobjid = CreateDynamicObject(1420, 1917.801391, 1463.765136, 1099.885375, 0.000014, -0.000003, -73.700035, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 13628, "8stad", "stadroof", 0x00000000);
    tmpobjid = CreateDynamicObject(1420, 1921.649658, 1467.612915, 1096.131958, -0.000009, 0.000004, -15.199987, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 13628, "8stad", "stadroof", 0x00000000);
    tmpobjid = CreateDynamicObject(1420, 1921.688598, 1470.600952, 1096.131958, -0.000004, 0.000009, 16.300008, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 13628, "8stad", "stadroof", 0x00000000);
    tmpobjid = CreateDynamicObject(1420, 1921.649658, 1467.612915, 1098.123779, -0.000001, 0.000007, -15.199995, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 13628, "8stad", "stadroof", 0x00000000);
    tmpobjid = CreateDynamicObject(1420, 1921.688598, 1470.600952, 1098.123779, 0.000001, 0.000007, 16.299978, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 13628, "8stad", "stadroof", 0x00000000);
    tmpobjid = CreateDynamicObject(1420, 1921.649658, 1467.612915, 1099.885375, 0.000004, 0.000009, -15.199995, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 13628, "8stad", "stadroof", 0x00000000);
    tmpobjid = CreateDynamicObject(1420, 1921.688598, 1470.600952, 1099.885375, 0.000009, 0.000004, 16.299955, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 13628, "8stad", "stadroof", 0x00000000);
    tmpobjid = CreateDynamicObject(1420, 1910.886962, 1470.600952, 1096.131958, -0.000004, -0.000009, 164.799819, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 13628, "8stad", "stadroof", 0x00000000);
    tmpobjid = CreateDynamicObject(1420, 1910.848022, 1467.612915, 1096.131958, -0.000009, -0.000004, -163.699829, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 13628, "8stad", "stadroof", 0x00000000);
    tmpobjid = CreateDynamicObject(1420, 1910.886962, 1470.600952, 1098.123779, 0.000001, -0.000007, 164.799804, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 13628, "8stad", "stadroof", 0x00000000);
    tmpobjid = CreateDynamicObject(1420, 1910.848022, 1467.612915, 1098.123779, -0.000001, -0.000007, -163.699859, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 13628, "8stad", "stadroof", 0x00000000);
    tmpobjid = CreateDynamicObject(1420, 1910.886962, 1470.600952, 1099.885375, 0.000009, -0.000004, 164.799804, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 13628, "8stad", "stadroof", 0x00000000);
    tmpobjid = CreateDynamicObject(1420, 1910.848022, 1467.612915, 1099.885375, 0.000004, -0.000009, -163.699890, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 13628, "8stad", "stadroof", 0x00000000);
    tmpobjid = CreateDynamicObject(7893, 1916.250854, 1465.229980, 1095.529907, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 18996, "mattextures", "policeshieldgls", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(7893, 1916.250854, 1472.991943, 1093.500000, 0.000000, 0.000000, 179.999893, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "ws_castironwalk", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(7893, 1916.250854, 1472.991943, 1094.170654, 0.000000, 0.000000, 179.999893, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 18996, "mattextures", "policeshieldgls", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(7893, 1916.250854, 1472.991943, 1094.849853, 0.000000, 0.000000, 179.999893, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "ws_castironwalk", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(7893, 1916.250854, 1472.991943, 1095.529907, 0.000000, 0.000000, 179.999893, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 18996, "mattextures", "policeshieldgls", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(2960, 1914.765136, 1463.603149, 1093.812011, 0.000000, 90.000000, -104.099990, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor2", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2960, 1917.853149, 1463.660522, 1093.812133, 0.000000, 90.000000, -72.999954, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor2", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2960, 1917.865234, 1474.597656, 1093.781860, 0.000000, 90.000000, 75.899978, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor2", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2960, 1914.792358, 1474.579223, 1093.812011, 0.000000, 90.000000, 107.000038, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor2", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(1317, 1916.274780, 1469.136108, 1094.602416, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 13659, "8bars", "AH_gbarrier", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(19197, 1916.301025, 1469.140625, 1094.369018, 0.000000, 180.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19527, "cauldron1", "alienliquid1", 0x00000000);
    tmpobjid = CreateDynamicObject(19197, 1916.301025, 1469.140625, 1095.738403, 0.000000, 180.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19527, "cauldron1", "alienliquid1", 0x00000000);
    tmpobjid = CreateDynamicObject(19197, 1916.301025, 1469.140625, 1097.449462, 0.000000, 360.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19527, "cauldron1", "alienliquid1", 0x00000000);
    tmpobjid = CreateDynamicObject(19197, 1916.301025, 1469.140625, 1098.020019, 0.000000, 540.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19527, "cauldron1", "alienliquid1", 0x00000000);
    tmpobjid = CreateDynamicObject(19197, 1916.301025, 1469.130615, 1099.911132, 0.000000, 720.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19527, "cauldron1", "alienliquid1", 0x00000000);
    tmpobjid = CreateDynamicObject(19197, 1916.301025, 1469.140625, 1100.481689, 0.000000, 900.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19527, "cauldron1", "alienliquid1", 0x00000000);
    tmpobjid = CreateDynamicObject(19197, 1916.301025, 1469.140625, 1099.320556, 0.000014, 900.000000, -0.000014, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19527, "cauldron1", "alienliquid1", 0x00000000);
    tmpobjid = CreateDynamicObject(19197, 1916.281005, 1469.110595, 1098.750000, 0.000014, 1080.000000, -0.000014, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19527, "cauldron1", "alienliquid1", 0x00000000);
    tmpobjid = CreateDynamicObject(19197, 1916.301025, 1469.140625, 1096.738769, 0.000014, 900.000000, -0.000014, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19527, "cauldron1", "alienliquid1", 0x00000000);
    tmpobjid = CreateDynamicObject(19197, 1916.291015, 1469.120605, 1096.178222, 0.000014, 1080.000000, -0.000014, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19527, "cauldron1", "alienliquid1", 0x00000000);
    tmpobjid = CreateDynamicObject(7586, 1916.304565, 1469.207031, 1087.071411, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 10101, "2notherbuildsfe", "gz_vicdoor1", 0x00000000);
    tmpobjid = CreateDynamicObject(7586, 1916.304565, 1469.207031, 1108.212280, 0.000000, 180.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 10101, "2notherbuildsfe", "gz_vicdoor1", 0x00000000);
    tmpobjid = CreateDynamicObject(3807, 1912.515747, 1468.089965, 1096.682861, 0.000000, 0.000000, 15.699995, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_panel2", 0x00000000);
    tmpobjid = CreateDynamicObject(3807, 1912.570068, 1470.175537, 1096.682861, 0.000000, 0.000000, -12.900007, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_panel2", 0x00000000);
    tmpobjid = CreateDynamicObject(3807, 1920.040405, 1470.175659, 1096.682861, 0.000000, 0.000000, -164.299926, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_panel2", 0x00000000);
    tmpobjid = CreateDynamicObject(3807, 1919.986083, 1468.090087, 1096.682861, 0.000000, 0.000000, 167.099899, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_panel2", 0x00000000);
    tmpobjid = CreateDynamicObject(3807, 1915.287963, 1472.792358, 1096.682861, -0.000015, -0.000003, -74.299903, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_panel2", 0x00000000);
    tmpobjid = CreateDynamicObject(3807, 1917.373535, 1472.738037, 1096.682861, -0.000012, -0.000009, -102.900039, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_panel2", 0x00000000);
    tmpobjid = CreateDynamicObject(3807, 1917.373657, 1465.418945, 1096.682861, -0.000015, -0.000003, 105.700035, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_panel2", 0x00000000);
    tmpobjid = CreateDynamicObject(3807, 1915.288085, 1465.473266, 1096.682861, -0.000012, -0.000009, 77.099945, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_panel2", 0x00000000);
    tmpobjid = CreateDynamicObject(1316, 1916.296630, 1469.161865, 1096.112426, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_glass", 0xFF202020);
    tmpobjid = CreateDynamicObject(1316, 1916.296630, 1469.161865, 1097.112426, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_glass", 0xFF202020);
    tmpobjid = CreateDynamicObject(1316, 1916.296630, 1469.161865, 1098.112426, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_glass", 0xFF202020);
    tmpobjid = CreateDynamicObject(1316, 1916.296630, 1469.161865, 1099.112426, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_glass", 0xFF202020);
    tmpobjid = CreateDynamicObject(1316, 1916.296630, 1469.161865, 1100.112426, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_glass", 0xFF202020);
    tmpobjid = CreateDynamicObject(1317, 1916.274780, 1469.136108, 1100.932861, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 13659, "8bars", "AH_gbarrier", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(16332, 1914.826416, 1467.479003, 1101.110961, 0.000000, 0.000000, 45.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 5150, "wiresetc_las2", "ganggraf01_LA_m", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 2, 16093, "a51_ext", "ws_controltowerwin1", 0x00000000);
    tmpobjid = CreateDynamicObject(16332, 1917.910888, 1470.563476, 1101.110961, 0.000000, 0.000000, 45.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 5150, "wiresetc_las2", "ganggraf01_LA_m", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 2, 16093, "a51_ext", "ws_controltowerwin1", 0x00000000);
    tmpobjid = CreateDynamicObject(16332, 1917.811523, 1467.548583, 1101.110961, 0.000000, 0.000000, 135.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 5150, "wiresetc_las2", "ganggraf01_LA_m", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 2, 16093, "a51_ext", "ws_controltowerwin1", 0x00000000);
    tmpobjid = CreateDynamicObject(16332, 1914.705688, 1470.654418, 1101.110961, 0.000000, 0.000000, 135.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 5150, "wiresetc_las2", "ganggraf01_LA_m", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 2, 16093, "a51_ext", "ws_controltowerwin1", 0x00000000);
    tmpobjid = CreateDynamicObject(19437, 1878.231079, 1469.239013, 1094.641357, 0.000000, 90.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 10226, "sfeship1", "sf_shipcomp", 0x00000000);
    tmpobjid = CreateDynamicObject(13646, 1879.842529, 1469.272705, 1093.131103, 0.000000, 0.000007, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 10763, "airport1_sfse", "airportwind03", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 3979, "civic01_lan", "sl_laglasswall2", 0x00000000);
    tmpobjid = CreateDynamicObject(19437, 1878.951782, 1469.238037, 1093.920654, 90.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 1809, "cj_hi_fi", "CJ_speaker_6", 0x00000000);
    tmpobjid = CreateDynamicObject(19846, 1879.490844, 1469.244262, 1094.345092, -12.500001, 0.000000, -89.999977, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 1560, "7_11_door", "cj_sheetmetal2", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(13646, 1881.162719, 1469.272705, 1092.910888, 0.000000, 0.000007, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 10763, "airport1_sfse", "airportwind03", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 16640, "a51", "metpat64", 0x00000000);
    tmpobjid = CreateDynamicObject(13646, 1880.502075, 1469.272705, 1092.980957, 0.000000, 0.000007, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 10763, "airport1_sfse", "airportwind03", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 16640, "a51", "metpat64", 0x00000000);
    tmpobjid = CreateDynamicObject(19846, 1879.509887, 1469.626708, 1094.001831, -0.000007, 90.000000, -104.099922, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 2028, "cj_games", "CJ_speaker4", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(19846, 1879.509887, 1468.921020, 1094.001708, 0.599991, 90.000000, -75.499992, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 2028, "cj_games", "CJ_speaker4", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(1628, 1879.704589, 1469.350463, 1093.600341, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 2028, "cj_games", "CJ_speaker4", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(1628, 1879.705566, 1469.170288, 1093.600341, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 2028, "cj_games", "CJ_speaker4", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(19437, 1878.903930, 1466.404541, 1094.491088, 0.000000, 90.000000, 126.499977, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 2028, "cj_games", "CJ_speaker4", 0x00000000);
    tmpobjid = CreateDynamicObject(19437, 1878.883544, 1472.119750, 1094.491088, 180.000000, 90.000000, 55.099945, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 2028, "cj_games", "CJ_speaker4", 0x00000000);
    tmpobjid = CreateDynamicObject(19437, 1880.885742, 1474.990478, 1094.641235, 0.000000, 90.000000, 55.099945, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 2028, "cj_games", "CJ_speaker4", 0x00000000);
    tmpobjid = CreateDynamicObject(19437, 1880.979370, 1463.598266, 1094.621215, 0.000000, 90.000000, 306.499969, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 2028, "cj_games", "CJ_speaker4", 0x00000000);
    tmpobjid = CreateDynamicObject(19437, 1879.483764, 1466.832885, 1093.760375, 90.000000, 90.000000, 126.499977, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 1809, "cj_hi_fi", "CJ_speaker_6", 0x00000000);
    tmpobjid = CreateDynamicObject(19437, 1881.565429, 1464.020019, 1093.760375, 90.000000, 90.000000, 126.499977, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 1809, "cj_hi_fi", "CJ_speaker_6", 0x00000000);
    tmpobjid = CreateDynamicObject(19437, 1879.472900, 1471.706787, 1093.760375, 90.000000, 90.000000, 55.099945, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 1809, "cj_hi_fi", "CJ_speaker_6", 0x00000000);
    tmpobjid = CreateDynamicObject(19437, 1881.457153, 1474.553100, 1093.760375, 90.000000, 90.000000, 55.099945, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 1809, "cj_hi_fi", "CJ_speaker_6", 0x00000000);
    tmpobjid = CreateDynamicObject(19456, 1886.589477, 1465.913696, 1093.510498, 0.000000, 90.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gun_ceiling2_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19456, 1883.386474, 1465.913696, 1093.509521, 0.000000, 90.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gun_ceiling2_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19456, 1883.386474, 1472.684204, 1093.509521, 0.000000, 90.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gun_ceiling2_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19456, 1886.588256, 1472.684204, 1093.510498, 0.000000, 90.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gun_ceiling2_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19456, 1886.578247, 1471.022583, 1091.840209, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19456, 1886.578247, 1467.580932, 1091.840209, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19475, 1879.319213, 1469.247314, 1094.442382, 0.000000, 102.799942, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_boffstuff1", 0x00000000);
    tmpobjid = CreateDynamicObject(19475, 1879.709838, 1469.247314, 1094.354248, 0.000000, 102.799942, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_boffstuff3", 0x00000000);
    tmpobjid = CreateDynamicObject(2114, 1878.675292, 1468.295288, 1094.701293, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19941, "goldbar1", "chrome", 0x00000000);
    tmpobjid = CreateDynamicObject(2114, 1878.675292, 1470.227050, 1094.701293, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19941, "goldbar1", "chrome", 0x00000000);
    tmpobjid = CreateDynamicObject(19475, 1878.686523, 1468.310913, 1094.731201, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "ferry_build14", 0xFF000000);
    tmpobjid = CreateDynamicObject(19475, 1878.686523, 1470.232299, 1094.731201, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "ferry_build14", 0xFF000000);
    tmpobjid = CreateDynamicObject(19135, 1878.676147, 1468.307128, 1094.901000, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19029, "matglasses", "glassestype16map", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 5150, "wiresetc_las2", "ganggraf01_LA_m", 0x00000000);
    tmpobjid = CreateDynamicObject(19135, 1878.676147, 1470.238647, 1094.901000, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19029, "matglasses", "glassestype16map", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 5150, "wiresetc_las2", "ganggraf01_LA_m", 0x00000000);
    tmpobjid = CreateDynamicObject(1581, 1878.682983, 1468.330444, 1095.371337, 0.000000, 0.000000, 450.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 9818, "ship_brijsfw", "ship_greenscreen1", 0x90FFFFFF);
    tmpobjid = CreateDynamicObject(1581, 1878.682983, 1470.221679, 1095.371337, 0.000000, 0.000000, 1710.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 10226, "sfeship1", "sf_shipcomp", 0x9000FF00);
    tmpobjid = CreateDynamicObject(19483, 1879.244384, 1466.135253, 1094.590454, 0.000000, 270.000000, 396.700012, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_boffstuff3", 0x00000000);
    tmpobjid = CreateDynamicObject(19483, 1879.192993, 1472.405517, 1094.590454, 0.000000, 270.000000, 324.600036, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_boffstuff1", 0x00000000);
    tmpobjid = CreateDynamicObject(1613, 1878.838378, 1468.236572, 1094.090820, 0.000000, 90.000000, 630.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 2028, "cj_games", "CJ_speaker4", 0x00000000);
    tmpobjid = CreateDynamicObject(1613, 1878.838378, 1470.267456, 1094.090820, 0.000000, 90.000000, 630.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 2028, "cj_games", "CJ_speaker4", 0x00000000);
    tmpobjid = CreateDynamicObject(18633, 1879.479614, 1468.225708, 1094.371093, 180.000000, 0.000000, 450.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_metal1", 0x00000000);
    tmpobjid = CreateDynamicObject(18633, 1879.479614, 1470.256835, 1094.371093, 180.000000, 0.000000, 450.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_metal1", 0x00000000);
    tmpobjid = CreateDynamicObject(2352, 1879.857421, 1468.220825, 1094.560668, 90.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "banding3c_64HV", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 16640, "a51", "banding3c_64HV", 0x00000000);
    tmpobjid = CreateDynamicObject(2352, 1879.857421, 1468.220825, 1094.560668, 90.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "banding3c_64HV", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 16640, "a51", "banding3c_64HV", 0x00000000);
    tmpobjid = CreateDynamicObject(2352, 1879.857421, 1470.261962, 1094.560668, 90.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "banding3c_64HV", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 16640, "a51", "banding3c_64HV", 0x00000000);
    tmpobjid = CreateDynamicObject(2352, 1879.857421, 1470.261962, 1094.560668, 90.000000, 0.000000, 360.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "banding3c_64HV", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 16640, "a51", "banding3c_64HV", 0x00000000);
    tmpobjid = CreateDynamicObject(1562, 1880.310424, 1468.256835, 1094.360717, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 1809, "cj_hi_fi", "CJ_speaker_6", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(1562, 1880.310424, 1470.238525, 1094.360717, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 1809, "cj_hi_fi", "CJ_speaker_6", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(1563, 1880.650756, 1468.257812, 1094.881469, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(1563, 1880.650756, 1470.239501, 1094.881469, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2114, 1880.560424, 1465.004882, 1094.701293, 0.000007, 0.000007, 89.999946, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19941, "goldbar1", "chrome", 0x00000000);
    tmpobjid = CreateDynamicObject(19475, 1880.544799, 1465.016113, 1094.731201, 0.000007, 90.000007, 89.999946, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "ferry_build14", 0xFF000000);
    tmpobjid = CreateDynamicObject(19135, 1880.548583, 1465.005737, 1094.901000, 0.000007, 0.000007, 89.999946, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19029, "matglasses", "glassestype16map", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 5150, "wiresetc_las2", "ganggraf01_LA_m", 0x00000000);
    tmpobjid = CreateDynamicObject(1581, 1880.525268, 1465.012573, 1095.371337, 0.000007, -0.000007, 539.999877, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 9818, "ship_brijsfw", "ship_screen1sfw", 0x9000FF00);
    tmpobjid = CreateDynamicObject(2114, 1880.435180, 1473.588623, 1094.701293, 0.000000, 0.000007, -90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19941, "goldbar1", "chrome", 0x00000000);
    tmpobjid = CreateDynamicObject(19475, 1880.450805, 1473.577392, 1094.731201, 0.000000, 90.000007, -90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "ferry_build14", 0xFF000000);
    tmpobjid = CreateDynamicObject(19135, 1880.447021, 1473.587768, 1094.901000, 0.000000, 0.000007, -90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19029, "matglasses", "glassestype16map", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 5150, "wiresetc_las2", "ganggraf01_LA_m", 0x00000000);
    tmpobjid = CreateDynamicObject(1581, 1880.470336, 1473.580932, 1095.371337, 0.000007, 0.000000, -0.000105, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19894, "laptopsamp1", "laptopscreen2", 0x9000FF00);
    tmpobjid = CreateDynamicObject(19379, 1884.954956, 1469.286987, 1098.185791, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 1809, "cj_hi_fi", "CJ_speaker_6", 0x00000000);
    tmpobjid = CreateDynamicObject(1562, 1881.314941, 1466.178710, 1094.190551, -0.000007, 0.000000, -67.099983, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 1809, "cj_hi_fi", "CJ_speaker_6", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(1563, 1881.627929, 1466.312011, 1094.711303, -0.000007, 0.000000, -67.099983, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(1562, 1881.243286, 1472.498901, 1094.190551, -0.000014, 0.000001, -116.499954, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 1809, "cj_hi_fi", "CJ_speaker_6", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(1563, 1881.548217, 1472.348022, 1094.711303, -0.000014, 0.000001, -116.499954, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(3387, 1885.286132, 1465.205322, 1093.596435, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 2028, "cj_games", "CJ_speaker4", 0x00000000);
    tmpobjid = CreateDynamicObject(3387, 1883.245727, 1465.205322, 1093.596435, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 2028, "cj_games", "CJ_speaker4", 0x00000000);
    tmpobjid = CreateDynamicObject(3387, 1883.245605, 1473.401245, 1093.596435, 0.000007, 0.000000, 89.999916, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 2028, "cj_games", "CJ_speaker4", 0x00000000);
    tmpobjid = CreateDynamicObject(3387, 1885.286010, 1473.401245, 1093.596435, 0.000007, 0.000000, 89.999916, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 2028, "cj_games", "CJ_speaker4", 0x00000000);
    tmpobjid = CreateDynamicObject(3385, 1883.225219, 1472.927856, 1095.217895, 90.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(3385, 1885.286987, 1472.927856, 1095.217895, 90.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(3385, 1885.286987, 1465.696166, 1095.217895, 90.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(3385, 1883.245971, 1465.696166, 1095.217895, 90.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(19483, 1877.336547, 1467.951416, 1095.610717, 89.999992, 89.999992, -89.999992, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_glass", 0x80FFFFFF);
    tmpobjid = CreateDynamicObject(19482, 1878.964721, 1464.792358, 1095.213012, 0.000000, 0.000000, 35.999988, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_glass", 0x80FFFFFF);
    tmpobjid = CreateDynamicObject(19482, 1878.999267, 1473.792724, 1095.213012, 0.000000, 0.000000, -36.100013, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_glass", 0x80FFFFFF);
    tmpobjid = CreateDynamicObject(19483, 1877.336547, 1469.301513, 1095.610717, 89.999992, 89.999992, -89.999992, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_glass", 0x80FFFFFF);
    tmpobjid = CreateDynamicObject(19483, 1877.336547, 1470.651611, 1095.610717, 89.999992, 89.999992, -89.999992, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_glass", 0x80FFFFFF);
    tmpobjid = CreateDynamicObject(8877, 1877.323364, 1467.163330, 1092.797363, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_strips1", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 16640, "a51", "a51_strips1", 0x00000000);
    tmpobjid = CreateDynamicObject(8877, 1877.323364, 1471.433959, 1092.797363, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_strips1", 0xFFFFFFFF);
    SetDynamicObjectMaterial(tmpobjid, 1, 16640, "a51", "a51_strips1", 0x00000000);
    tmpobjid = CreateDynamicObject(2114, 1877.794433, 1469.296142, 1094.701293, 0.000000, 0.000022, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19941, "goldbar1", "chrome", 0x00000000);
    tmpobjid = CreateDynamicObject(19475, 1877.805664, 1469.301391, 1094.731201, 0.000000, 90.000022, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "ferry_build14", 0xFF000000);
    tmpobjid = CreateDynamicObject(19135, 1877.795288, 1469.307739, 1094.901000, 0.000000, 0.000022, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19029, "matglasses", "glassestype16map", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 5150, "wiresetc_las2", "ganggraf01_LA_m", 0x00000000);
    tmpobjid = CreateDynamicObject(19475, 1877.873901, 1469.311889, 1095.342407, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 18064, "ab_sfammuunits", "gun_targetc", 0x9000FF00);
    tmpobjid = CreateDynamicObject(18844, 1774.873901, 1545.311401, 1073.667968, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 3096, "bbpcpx", "blugrad32", 0x00000000);
    tmpobjid = CreateDynamicObject(900, 1799.154296, 1507.824951, 1087.425537, 71.199981, 26.999969, -0.199999, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 12871, "ce_ground01", "sw_rockgrass1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(900, 1812.613037, 1518.713623, 1083.532348, -103.700012, -19.600023, 45.100017, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 12871, "ce_ground01", "sw_rockgrass1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(900, 1800.724121, 1507.093627, 1074.701293, 0.000000, -96.999992, 112.800018, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 12871, "ce_ground01", "sw_stonesgrass", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(900, 1803.916137, 1522.718505, 1102.066894, 21.799995, -46.299983, 112.800018, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 12871, "ce_ground01", "sw_stonesgrass", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(900, 1811.598144, 1523.747680, 1094.621582, 34.000011, -54.599975, 112.800018, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(900, 1816.552612, 1557.431518, 1089.523559, -6.299984, -79.199958, -173.699935, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 12871, "ce_ground01", "sw_stonesgrass", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(900, 1775.592651, 1501.072509, 1060.765869, -27.699979, -97.899971, 105.400115, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(900, 1768.428833, 1515.080444, 1108.764282, -16.699979, -44.799953, 105.400115, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(900, 1775.779052, 1517.105468, 1111.052001, 6.300024, -44.799953, 105.400115, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(900, 1814.242553, 1531.186645, 1053.889282, 6.300024, -124.699928, -178.399917, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 12871, "ce_ground01", "sw_stonesgrass", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(18844, 1777.263549, 1546.472290, 1073.667968, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 2567, "ab", "ab_plasicwrapa", 0x00000000);
    tmpobjid = CreateDynamicObject(18844, 1776.333251, 1542.501708, 1073.667968, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 2567, "ab", "ab_plasicwrapa", 0x00000000);
    tmpobjid = CreateDynamicObject(19326, 1838.741821, 1470.091552, 1095.991577, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19063, "xmasorbs", "sphere", 0x00000000);
    tmpobjid = CreateDynamicObject(19326, 1838.741821, 1447.421264, 1095.991577, 0.000000, 0.000000, 113.900016, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19063, "xmasorbs", "sphere", 0x00000000);
    tmpobjid = CreateDynamicObject(19326, 1835.971069, 1464.350952, 1093.700073, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19063, "xmasorbs", "sphere", 0x00000000);
    tmpobjid = CreateDynamicObject(19326, 1835.971069, 1464.350952, 1105.879638, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19063, "xmasorbs", "sphere", 0x00000000);
    tmpobjid = CreateDynamicObject(19326, 1835.971069, 1482.671875, 1106.840209, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19063, "xmasorbs", "sphere", 0x00000000);
    tmpobjid = CreateDynamicObject(19326, 1835.971069, 1441.781982, 1106.840209, 0.000000, 0.000000, 124.599998, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19063, "xmasorbs", "sphere", 0x00000000);
    tmpobjid = CreateDynamicObject(19326, 1857.975952, 1512.323608, 1098.979858, 0.000000, 0.000000, 214.600006, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19063, "xmasorbs", "sphere", 0x00000000);
    tmpobjid = CreateDynamicObject(19326, 1861.194213, 1514.543945, 1106.679565, 0.000000, 0.000000, 214.600006, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19063, "xmasorbs", "sphere", 0x00000000);
    tmpobjid = CreateDynamicObject(19326, 1860.346923, 1439.378662, 1098.579833, 0.000000, 0.000000, 304.600006, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19063, "xmasorbs", "sphere", 0x00000000);
    tmpobjid = CreateDynamicObject(19326, 1853.936279, 1448.671386, 1092.490112, 0.000000, 0.000000, 304.600006, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19063, "xmasorbs", "sphere", 0x00000000);
    tmpobjid = CreateDynamicObject(19326, 1847.968872, 1463.044433, 1084.329711, 23.299997, 0.000000, -81.299972, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19063, "xmasorbs", "sphere", 0x00000000);
    tmpobjid = CreateDynamicObject(19326, 1850.149414, 1453.808227, 1082.566284, 23.299997, 0.000000, -81.299972, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19063, "xmasorbs", "sphere", 0x00000000);
    tmpobjid = CreateDynamicObject(2352, 1879.530395, 1468.950439, 1094.380859, 0.000000, -42.299964, -179.099960, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "banding3c_64HV", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 16640, "a51", "banding3c_64HV", 0x00000000);
    tmpobjid = CreateDynamicObject(2352, 1879.566040, 1468.951049, 1094.375610, 0.000000, -42.299964, -179.099960, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "banding3c_64HV", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 16640, "a51", "banding3c_64HV", 0x00000000);
    tmpobjid = CreateDynamicObject(19478, 1879.528198, 1469.007202, 1094.392822, 12.099988, 90.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_pipes", 0x00000000);
    tmpobjid = CreateDynamicObject(2969, 1880.672485, 1470.227661, 1094.901123, 90.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 5150, "wiresetc_las2", "ganggraf01_LA_m", 0x00000000);
    tmpobjid = CreateDynamicObject(2969, 1880.672485, 1468.256591, 1094.901123, 90.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 5150, "wiresetc_las2", "ganggraf01_LA_m", 0x00000000);
    tmpobjid = CreateDynamicObject(2969, 1881.648193, 1466.308593, 1094.690917, 90.000000, 0.000000, 111.599967, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 5150, "wiresetc_las2", "ganggraf01_LA_m", 0x00000000);
    tmpobjid = CreateDynamicObject(2969, 1881.535644, 1472.333984, 1094.690917, 90.000000, 0.000000, 63.499950, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 5150, "wiresetc_las2", "ganggraf01_LA_m", 0x00000000);
    tmpobjid = CreateDynamicObject(19379, 1946.661132, 1469.286987, 1093.345458, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16644, "a51_detailstuff", "steel256128", 0x00000000);
    tmpobjid = CreateDynamicObject(19379, 1957.151855, 1469.286987, 1093.345458, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16644, "a51_detailstuff", "steel256128", 0x00000000);
    tmpobjid = CreateDynamicObject(19379, 1967.643798, 1469.286987, 1093.345458, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16644, "a51_detailstuff", "steel256128", 0x00000000);
    tmpobjid = CreateDynamicObject(19379, 1978.124145, 1469.286987, 1093.345458, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16644, "a51_detailstuff", "steel256128", 0x00000000);
    tmpobjid = CreateDynamicObject(19379, 1967.643798, 1459.655883, 1093.345458, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16644, "a51_detailstuff", "steel256128", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(19379, 1967.643798, 1478.916137, 1093.345458, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16644, "a51_detailstuff", "steel256128", 0x00000000);
    tmpobjid = CreateDynamicObject(19379, 1957.151855, 1478.896606, 1093.345458, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16644, "a51_detailstuff", "steel256128", 0x00000000);
    tmpobjid = CreateDynamicObject(19379, 1957.151855, 1459.657104, 1093.345458, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16644, "a51_detailstuff", "steel256128", 0x00000000);
    tmpobjid = CreateDynamicObject(19379, 1946.661132, 1459.656982, 1093.345458, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16644, "a51_detailstuff", "steel256128", 0x00000000);
    tmpobjid = CreateDynamicObject(19379, 1946.661132, 1478.907592, 1093.345458, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16644, "a51_detailstuff", "steel256128", 0x00000000);
    tmpobjid = CreateDynamicObject(19387, 1932.975341, 1469.309204, 1095.171875, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_floorpanel1", 0x00000000);
    tmpobjid = CreateDynamicObject(19387, 1941.287719, 1469.309204, 1095.171875, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_floorpanel1", 0x00000000);
    tmpobjid = CreateDynamicObject(19447, 1932.975341, 1462.909667, 1095.171875, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_floorpanel1", 0x00000000);
    tmpobjid = CreateDynamicObject(19447, 1932.975341, 1475.729980, 1095.171875, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_floorpanel1", 0x00000000);
    tmpobjid = CreateDynamicObject(19447, 1941.277221, 1475.729980, 1095.171875, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_floorpanel1", 0x00000000);
    tmpobjid = CreateDynamicObject(19447, 1941.277221, 1462.901611, 1095.171875, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_floorpanel1", 0x00000000);
    tmpobjid = CreateDynamicObject(19447, 1941.277221, 1469.431762, 1098.672973, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 2917, "a51_crane", "girder2_grey_64HV", 0x00000000);
    tmpobjid = CreateDynamicObject(19447, 1932.986083, 1469.431762, 1098.672973, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 2917, "a51_crane", "girder2_grey_64HV", 0x00000000);
    tmpobjid = CreateDynamicObject(19387, 1979.914428, 1469.309204, 1095.171875, 0.000000, 0.000007, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_floorpanel1", 0x00000000);
    tmpobjid = CreateDynamicObject(19447, 1979.903930, 1475.729980, 1095.171875, 0.000000, 0.000007, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_floorpanel1", 0x00000000);
    tmpobjid = CreateDynamicObject(19447, 1979.903930, 1462.901611, 1095.171875, 0.000000, 0.000007, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_floorpanel1", 0x00000000);
    tmpobjid = CreateDynamicObject(19447, 1979.903930, 1469.431762, 1098.672973, 0.000000, 0.000007, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 2917, "a51_crane", "girder2_grey_64HV", 0x00000000);
    tmpobjid = CreateDynamicObject(2972, 1954.114013, 1475.590332, 1093.431396, 0.000000, 0.000000, 810.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2972, 1963.323730, 1475.059936, 1093.431396, 0.000000, 0.000000, 900.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2972, 1963.323730, 1473.479614, 1093.431396, 0.000000, 0.000000, 252.100067, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2972, 1959.868774, 1462.782104, 1093.431396, 0.000000, 0.000000, 1.300063, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2972, 1958.330932, 1463.107299, 1093.431396, 0.000000, 0.000000, 13.700062, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2972, 1959.106323, 1463.007568, 1094.621826, 0.000000, 0.000000, 83.200065, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2972, 1951.433959, 1465.050048, 1093.410766, 0.000000, 0.000000, 83.200065, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2972, 1964.714843, 1465.289184, 1093.410766, 0.000000, 0.000000, 173.200073, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2972, 1968.506347, 1472.258911, 1093.410766, 0.000000, 0.000000, -142.699920, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2975, 1957.551879, 1476.438842, 1093.431396, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2975, 1961.612548, 1475.207885, 1093.431396, 0.000000, 0.000000, 84.700019, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2975, 1965.292846, 1474.394409, 1093.431396, 0.000000, 0.000000, 70.900039, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2975, 1951.651000, 1475.096557, 1093.431396, 0.000000, 0.000000, -166.199966, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2975, 1959.010131, 1472.096069, 1093.431396, 0.000000, 0.000000, -166.199966, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2975, 1962.098632, 1463.802001, 1093.431396, 0.000000, 0.000000, 171.800033, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2975, 1956.147827, 1463.174560, 1093.431396, 0.000000, 0.000000, -66.999946, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2975, 1946.460327, 1466.113037, 1093.431396, 0.000000, 0.000000, -33.999942, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2974, 1956.032714, 1473.050537, 1093.431396, 0.000000, 0.000000, 82.700012, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2974, 1953.506103, 1462.766479, 1093.431396, 0.000000, 0.000000, 82.700012, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2974, 1966.954345, 1473.339477, 1093.431396, 0.000000, 0.000000, 134.500015, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2974, 1966.928344, 1465.086181, 1093.431396, 0.000000, 0.000000, -168.200012, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2974, 1959.279541, 1466.777709, 1093.431396, 0.000000, 0.000000, -78.200012, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2973, 1949.443969, 1465.590209, 1093.421386, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2973, 1949.123779, 1473.612792, 1093.421386, 0.000000, 0.000000, 108.700004, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2973, 1955.237792, 1465.906127, 1093.421386, 0.000000, 0.000000, 108.700004, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2973, 1962.384277, 1466.800292, 1093.421386, 0.000000, 0.000000, 103.399971, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2977, 1958.991210, 1474.429809, 1093.301269, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2977, 1959.791748, 1476.220947, 1093.301269, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2977, 1957.461425, 1464.439453, 1093.301269, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2977, 1953.002075, 1465.769897, 1093.301269, 0.000000, 0.000000, -163.399993, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2977, 1952.126098, 1473.545776, 1093.301269, 0.000000, 0.000000, -163.399993, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2977, 1946.436645, 1473.341674, 1093.301269, 0.000000, 0.000000, 88.699996, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(2977, 1970.390625, 1472.798217, 1093.301269, 0.000000, 0.000000, 88.699996, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, -1, "none", "none", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(19447, 1958.109008, 1467.552124, 1101.746459, 0.000000, -101.099975, 90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_intdoor", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(19447, 1958.109008, 1470.845092, 1101.750976, 0.000000, -101.099975, 270.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_intdoor", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1954.461425, 1472.926635, 1101.293090, 20.200000, 90.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1956.712036, 1472.926635, 1101.293090, 20.200000, 90.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1958.972167, 1472.926635, 1101.293090, 20.200000, 90.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1961.242919, 1472.926635, 1101.293090, 20.200000, 90.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1961.783447, 1472.926635, 1101.294067, 20.200000, 90.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1961.783447, 1465.461914, 1101.293090, 20.199996, 90.000000, -0.000014, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1959.532836, 1465.461914, 1101.293090, 20.199996, 90.000000, -0.000014, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1957.272705, 1465.461914, 1101.293090, 20.199996, 90.000000, -0.000014, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1955.001953, 1465.461914, 1101.293090, 20.199996, 90.000000, -0.000014, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1954.461425, 1465.461914, 1101.294067, 20.199996, 90.000000, -0.000014, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1963.254638, 1472.016601, 1101.223999, 0.000000, 90.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1963.254638, 1469.746704, 1101.223999, 0.000000, 90.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1963.254638, 1467.486083, 1101.223999, 0.000000, 90.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1963.254638, 1466.386474, 1101.224975, 0.000000, 90.000000, 270.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1963.254638, 1468.387207, 1101.955322, 0.000000, 90.000000, 270.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1963.254638, 1470.646850, 1101.955322, 0.000000, 90.000000, 270.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1952.941040, 1472.016601, 1101.223999, 0.000014, 90.000000, 89.999954, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1952.941040, 1469.746704, 1101.223999, 0.000014, 90.000000, 89.999954, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1952.941040, 1467.486083, 1101.223999, 0.000014, 90.000000, 89.999954, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1952.941040, 1466.386474, 1101.224975, -0.000014, 90.000000, -89.999954, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1952.941040, 1468.387207, 1101.955322, -0.000014, 90.000000, -89.999954, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1952.941040, 1470.646850, 1101.955322, -0.000014, 90.000000, -89.999954, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1952.941040, 1474.224731, 1100.490478, 0.000014, 125.199958, 89.999954, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1952.941040, 1475.917358, 1099.035766, 0.000014, 138.199966, 89.999954, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1952.941040, 1477.225341, 1097.235107, 0.000014, 149.500000, 89.999954, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1952.941040, 1477.980468, 1095.042114, 0.000014, 172.100219, 89.999954, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1952.931030, 1477.711059, 1094.181640, -9.999999, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1963.250488, 1474.224731, 1100.490478, 0.000029, 125.199958, 89.999908, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1963.250488, 1475.917358, 1099.035766, 0.000029, 138.199966, 89.999908, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1963.250488, 1477.225341, 1097.235107, 0.000029, 149.500000, 89.999908, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1963.250488, 1477.980468, 1095.042114, 0.000029, 172.100219, 89.999908, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1963.240478, 1477.711059, 1094.181640, -9.999999, 0.000014, 0.000001, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1963.240600, 1464.358154, 1100.490478, 0.000007, 125.199958, -89.999992, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1963.240600, 1462.665527, 1099.035766, 0.000007, 138.199966, -89.999992, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1963.240600, 1461.357543, 1097.235107, 0.000007, 149.500000, -89.999992, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1963.240600, 1460.602416, 1095.042114, 0.000007, 172.100219, -89.999992, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1963.250610, 1460.871826, 1094.181640, -9.999999, -0.000007, 179.999847, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1952.931152, 1464.358154, 1100.490478, 0.000022, 125.199958, -90.000038, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1952.931152, 1462.665527, 1099.035766, 0.000022, 138.199966, -90.000038, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1952.931152, 1461.357543, 1097.235107, 0.000022, 149.500000, -90.000038, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1952.931152, 1460.602416, 1095.042114, 0.000022, 172.100219, -90.000038, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(9131, 1952.941162, 1460.871826, 1094.181640, -9.999999, 0.000007, 179.999862, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 14548, "ab_cargo_int", "cargo_floor1", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(19387, 1916.349365, 1485.074707, 1095.171875, 0.000015, 0.000007, 89.999923, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_floorpanel1", 0x00000000);
    tmpobjid = CreateDynamicObject(19447, 1922.748901, 1485.074707, 1095.171875, 0.000015, 0.000007, 89.999923, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_floorpanel1", 0x00000000);
    tmpobjid = CreateDynamicObject(19447, 1909.928588, 1485.074707, 1095.171875, 0.000015, 0.000007, 89.999923, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_floorpanel1", 0x00000000);
    tmpobjid = CreateDynamicObject(19447, 1916.226806, 1485.085449, 1098.672973, 0.000015, 0.000007, 89.999923, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 2917, "a51_crane", "girder2_grey_64HV", 0x00000000);
    tmpobjid = CreateDynamicObject(19387, 1916.349365, 1453.321899, 1095.171875, 0.000022, 0.000007, 89.999900, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_floorpanel1", 0x00000000);
    tmpobjid = CreateDynamicObject(19447, 1922.748901, 1453.321899, 1095.171875, 0.000022, 0.000007, 89.999900, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_floorpanel1", 0x00000000);
    tmpobjid = CreateDynamicObject(19447, 1909.928588, 1453.321899, 1095.171875, 0.000022, 0.000007, 89.999900, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_floorpanel1", 0x00000000);
    tmpobjid = CreateDynamicObject(19447, 1916.226806, 1453.332641, 1098.672973, 0.000022, 0.000007, 89.999900, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 2917, "a51_crane", "girder2_grey_64HV", 0x00000000);
    tmpobjid = CreateDynamicObject(19602, 1891.322143, 1469.249511, 1096.042602, 0.000000, 90.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19623, "camera1", "cscamera02", 0x00000000);
    tmpobjid = CreateDynamicObject(19602, 1891.622436, 1469.249511, 1096.042602, 0.000000, 90.000000, 360.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19623, "camera1", "cscamera02", 0x00000000);
    tmpobjid = CreateDynamicObject(19602, 1933.123779, 1469.249511, 1096.092651, 0.000000, 90.000000, 360.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19623, "camera1", "cscamera02", 0x00000000);
    tmpobjid = CreateDynamicObject(19602, 1941.434570, 1469.249511, 1096.092651, 0.000000, 90.000000, 360.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19623, "camera1", "cscamera02", 0x00000000);
    tmpobjid = CreateDynamicObject(19602, 1941.144287, 1469.249511, 1096.092651, 0.000000, 90.000000, 540.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19623, "camera1", "cscamera02", 0x00000000);
    tmpobjid = CreateDynamicObject(19602, 1932.831054, 1469.249511, 1096.092651, 0.000000, 90.000000, 540.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19623, "camera1", "cscamera02", 0x00000000);
    tmpobjid = CreateDynamicObject(19602, 1979.762695, 1469.249511, 1096.092651, 0.000000, 90.000000, 540.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19623, "camera1", "cscamera02", 0x00000000);
    tmpobjid = CreateDynamicObject(19602, 1916.318969, 1453.467407, 1096.092651, 0.000000, 90.000000, 810.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19623, "camera1", "cscamera02", 0x00000000);
    tmpobjid = CreateDynamicObject(19602, 1916.318969, 1484.918090, 1096.092651, 0.000000, 90.000000, 990.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 19623, "camera1", "cscamera02", 0x00000000);
    tmpobjid = CreateDynamicObject(19566, 1922.748901, 1453.321899, 1093.403076, 0.000007, 45.000000, -90.000022, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19387, 1916.349365, 1453.321899, 1095.171875, 0.000022, 0.000007, 89.999870, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_floorpanel1", 0x00000000);
    tmpobjid = CreateDynamicObject(19566, 1891.473754, 1470.122314, 1093.403076, -0.000007, 45.000000, -89.999977, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19447, 1909.928588, 1453.321899, 1095.171875, 0.000022, 0.000007, 89.999870, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "a51_floorpanel1", 0x00000000);
    tmpobjid = CreateDynamicObject(19447, 1916.226806, 1453.332641, 1098.672973, 0.000022, 0.000007, 89.999870, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 2917, "a51_crane", "girder2_grey_64HV", 0x00000000);
    tmpobjid = CreateDynamicObject(19566, 1891.473754, 1468.440795, 1093.403076, 0.000000, 45.000000, 89.999969, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19566, 1891.473754, 1468.440673, 1095.905517, 0.000000, 224.999969, -89.999954, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19566, 1891.473754, 1470.122192, 1095.905517, 0.000030, -134.999969, 89.999984, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19566, 1932.987915, 1470.150634, 1093.364013, -0.000022, 45.000000, -89.999931, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19566, 1932.987915, 1468.469116, 1093.392333, 0.000015, 45.000000, 89.999923, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19566, 1932.987915, 1468.440673, 1095.965576, -0.000015, 224.999969, -89.999908, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19566, 1932.987915, 1470.122192, 1095.965576, 0.000045, -134.999969, 89.999938, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19566, 1941.282714, 1470.150634, 1093.364013, -0.000030, 45.000000, -89.999908, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19566, 1941.282714, 1468.469116, 1093.392333, 0.000022, 45.000000, 89.999900, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19566, 1941.282714, 1468.440673, 1095.965576, -0.000022, 224.999969, -89.999885, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19566, 1941.282714, 1470.122192, 1095.965576, 0.000053, -134.999969, 89.999916, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19566, 1979.904418, 1470.150634, 1093.364013, -0.000038, 45.000000, -89.999885, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19566, 1979.904418, 1468.469116, 1093.392333, 0.000030, 45.000000, 89.999877, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19566, 1979.904418, 1468.440673, 1095.965576, -0.000030, 224.999969, -89.999862, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19566, 1979.904418, 1470.122192, 1095.965576, 0.000061, -134.999969, 89.999893, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19566, 1915.479370, 1453.314697, 1093.364013, -0.000053, 45.000015, 0.000129, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19566, 1917.160888, 1453.314697, 1093.392333, 0.000045, 44.999984, 179.999710, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19566, 1917.189331, 1453.314697, 1095.965576, -0.000045, 224.999969, 0.000152, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19566, 1915.507812, 1453.314697, 1095.965576, 0.000076, -134.999969, 179.999725, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19566, 1915.479370, 1485.074829, 1093.364013, -0.000053, 45.000038, 0.000129, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19566, 1917.160888, 1485.074829, 1093.392333, 0.000045, 44.999961, 179.999572, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19566, 1917.189331, 1485.074829, 1095.965576, -0.000045, 224.999969, 0.000152, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19566, 1915.507812, 1485.074829, 1095.965576, 0.000076, -134.999969, 179.999588, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "metpat64chev_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19858, 1979.896362, 1468.580810, 1094.662475, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 2669, "cj_chris", "CJ_Grate", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(19858, 1915.586181, 1453.308959, 1094.662475, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 2669, "cj_chris", "CJ_Grate", 0xFFFFFFFF);
    tmpobjid = CreateDynamicObject(19858, 1915.586181, 1485.070922, 1094.662475, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(tmpobjid, 0, 2669, "cj_chris", "CJ_Grate", 0xFFFFFFFF);

    sprayer[0] = CreateDynamicObject(18729, 1915.548339, 1469.840698, 1093.946655, 0.000000, 0.000000, 45.000000, -1, -1, -1, 300.00, 300.00);
    sprayer[1] = CreateDynamicObject(18729, 1915.612060, 1468.474243, 1093.946655, 0.000000, 0.000000, 135.000000, -1, -1, -1, 300.00, 300.00);
    sprayer[2] = CreateDynamicObject(18729, 1916.978515, 1468.453002, 1093.946655, 0.000000, 0.000000, 225.000000, -1, -1, -1, 300.00, 300.00);
    sprayer[3] = CreateDynamicObject(18729, 1917.006835, 1469.826538, 1093.946655, 0.000000, 0.000000, 315.000000, -1, -1, -1, 300.00, 300.00);
    sprayer[4] = CreateDynamicObject(18729, 1915.548339, 1469.840698, 1098.796386, 0.000004, 0.000004, 44.999988, -1, -1, -1, 300.00, 300.00);
    sprayer[5] = CreateDynamicObject(18729, 1915.612060, 1468.474243, 1098.796386, 0.000004, -0.000004, 135.000000, -1, -1, -1, 300.00, 300.00);
    sprayer[6] = CreateDynamicObject(18729, 1916.978515, 1468.453002, 1098.796386, -0.000004, -0.000004, -135.000000, -1, -1, -1, 300.00, 300.00);
    sprayer[7] = CreateDynamicObject(18729, 1917.006835, 1469.826538, 1098.796386, -0.000004, 0.000004, -44.999988, -1, -1, -1, 300.00, 300.00);


    doorcockpit = CreateDynamicObject(19858, 1891.475708, 1468.520263, 1094.662475, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(doorcockpit, 0, 2669, "cj_chris", "CJ_Grate", 0xFFFFFFFF);
    doorstorage[0] = CreateDynamicObject(19858, 1932.977539, 1468.580810, 1094.662475, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(doorstorage[0], 0, 2669, "cj_chris", "CJ_Grate", 0xFFFFFFFF);
    doorstorage[1] = CreateDynamicObject(19858, 1941.288085, 1468.580810, 1094.662475, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(doorstorage[1], 0, 2669, "cj_chris", "CJ_Grate", 0xFFFFFFFF);

    genring[0] = CreateDynamicObject(3438, 1916.293823, 1469.111206, 1096.619140, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(genring[0], 0, 16640, "a51", "des_tunnellight", 0xFFFFFFFF);
    genring[1] = CreateDynamicObject(3438, 1916.293823, 1469.111206, 1098.619140, 0.000000, 90.000000, 0.00000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(genring[1], 0, 16640, "a51", "des_tunnellight", 0xFFFFFFFF);
    genring[2] = CreateDynamicObject(3438, 1916.293823, 1469.111206, 1100.368896, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(genring[2], 0, 16640, "a51", "des_tunnellight", 0xFFFFFFFF);

    button[0] = CreateDynamicObject(2709, 1885.305419, 1472.980590, 1095.216552, 90.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(button[0] , 0, 10101, "2notherbuildsfe", "ferry_build14", 0xFF00FF00);
    button[1]  = CreateDynamicObject(2709, 1883.245117, 1472.980590, 1095.216552, 90.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(button[1] , 0, 10101, "2notherbuildsfe", "ferry_build14", 0xFF00FF00);
    button[2]  = CreateDynamicObject(2709, 1883.245117, 1465.648925, 1095.216552, 90.000000, 0.000000, 360.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(button[2] , 0, 10101, "2notherbuildsfe", "ferry_build14", 0xFF00FF00);
    button[3]  = CreateDynamicObject(2709, 1885.265625, 1465.648925, 1095.216552, 90.000000, 0.000000, 360.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(button[3] , 0, 10101, "2notherbuildsfe", "ferry_build14", 0xFF00FF00);

    SetTimer("ShipTimer", 1000, true);

	print("\n--------------------------------------");
	print(" Spaceship script Loaded!");
	print("--------------------------------------\n");
	return 1;
}

stock ShipTimer();
public ShipTimer()
{
	for(new i=0; i < MAX_PLAYERS; i++)
	{
	    if(IsPlayerConnected(i))
	    {
	        if(IsPlayerInRangeOfPoint(i,3.0,1891.5776,1469.2914,1094.4314) && door[0] == false && !IsDynamicObjectMoving(doorcockpit))
	        {
				door[0] = true;
				MoveDynamicObject(doorcockpit,1891.475708, 1467.149780, 1094.662475, 2.0);
				SetTimer("CloseDoor1", 4000, false);
	        }
			if(IsPlayerInRangeOfPoint(i,3.0,1932.8406,1469.3179,1094.4314) && door[1] == false && !IsDynamicObjectMoving(doorstorage[0]))
			{
			    door[1] = true;
			    MoveDynamicObject(doorstorage[0],1932.977539, 1467.200317, 1094.662475, 2.0);
			    SetTimer("CloseDoor2", 4000, false);
			}
			if(IsPlayerInRangeOfPoint(i,3.0,1941.1128,1469.3054,1094.4314) && door[2] == false && !IsDynamicObjectMoving(doorstorage[1]))
			{
			    door[2] = true;
			    MoveDynamicObject(doorstorage[1],1941.288085, 1467.190185, 1094.662475, 2.0);
			    SetTimer("CloseDoor3", 4000, false);
			}

	    }
	}
	if(rotdelay > 0)rotdelay --;
	if(generator == false)
	{
	    if(ringstate == false)
	    {
	        ringstate = true;
	        if(rotdelay == 0)
	        {
				rotdelay = 3;
				MoveDynamicObject(genring[0], 1916.293823, 1469.111206, 1096.619140+0.0001,  0.0001,  0.0, 90.0, 180.0);
				MoveDynamicObject(genring[1], 1916.293823, 1469.111206, 1098.619140+0.0001,  0.0001,  0.0, 90.0, 180.0);
				MoveDynamicObject(genring[2], 1916.293823, 1469.111206, 1100.368896+0.0001,  0.0001,  0.0, 90.0, 180.0);
	        }
	    }
	    else
	    {
	        ringstate = false;
	        if(rotdelay == 0)
	        {
				rotdelay = 3;
				MoveDynamicObject(genring[0], 1916.293823, 1469.111206, 1096.619140-0.0001,  0.0001,  0.0, 90.0, 0.0);
				MoveDynamicObject(genring[1], 1916.293823, 1469.111206, 1098.619140-0.0001,  0.0001,  0.0, 90.0, 0.0);
				MoveDynamicObject(genring[2], 1916.293823, 1469.111206, 1100.368896-0.0001,  0.0001,  0.0, 90.0, 0.0);
  	        }
	    }
	}
	return 1;
}

stock CloseDoor1();
public CloseDoor1()
{
	MoveDynamicObject(doorcockpit,1891.475708, 1468.520263, 1094.662475, 2.0);
	door[0] = false;
	return 1;
}

stock CloseDoor2();
public CloseDoor2()
{
	MoveDynamicObject(doorstorage[0],1932.977539, 1468.580810, 1094.662475, 2.0);
	door[1] = false;
	return 1;
}

stock CloseDoor3();
public CloseDoor3()
{
	MoveDynamicObject(doorstorage[1],1941.288085, 1468.580810, 1094.662475, 2.0);
	door[2] = false;
	return 1;
}

public OnFilterScriptExit()
{
	return 1;
}


public OnPlayerConnect(playerid)
{
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
	return 1;
}

// public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
// {
// 	if(newkeys == KEY_YES && IsPlayerInRangeOfPoint(playerid,3.0, 1912.6364,1469.3225,1094.5245))
// 	{
// 	    if(sprayers == false)
// 	    {
// 		    sprayers = true;
// 		    SendClientMessage(playerid,0x2BB5E3FF,"ShipAI: Cooling systems have been turned down!");
// 		    for(new s = 0; s < 8; s++)
// 		    {
// 		        if(!IsValidDynamicObject(sprayer[s]))
//         		continue;
//         		new Float:zpos;
//         		Streamer_GetFloatData(0,sprayer[s], E_STREAMER_Z, zpos);
// 				Streamer_SetFloatData(0,sprayer[s], E_STREAMER_Z,zpos+500);
// 		    }
// 	    }
// 	    else
// 	    {
// 	        sprayers = false;
// 	        SendClientMessage(playerid,0x2BB5E3FF,"ShipAI: Cooling systems have been turned up!");
// 		    for(new s = 0; s < 8; s++)
// 		    {
// 		        if(!IsValidDynamicObject(sprayer[s]))
//         		continue;
// 				new Float:zpos;
//         		Streamer_GetFloatData(0,sprayer[s], E_STREAMER_Z, zpos);
// 				Streamer_SetFloatData(0,sprayer[s], E_STREAMER_Z,zpos-500);
// 		    }
// 	    }
// 	}
// 	if(newkeys == KEY_FIRE && IsPlayerInRangeOfPoint(playerid,2.0, 1885.3696,1472.4377,1094.5964))
// 	{
// 	    if(!generator)
// 	    {
// 	        generator = true;
// 	        SetDynamicObjectMaterial(button[0] , 0, 10101, "2notherbuildsfe", "ferry_build14", 0xFFFF0000);
// 	        SendClientMessage(playerid,0x2BB5E3FF,"ShipAI: Gravity generator has been shut down!");
// 	    }
// 	    else
// 	    {
// 	        generator = false;
// 	        SetDynamicObjectMaterial(button[0] , 0, 10101, "2notherbuildsfe", "ferry_build14", 0xFF00FF00);
// 	        SendClientMessage(playerid,0x2BB5E3FF,"ShipAI: Gravity generator has been powered up!");
// 	    }
// 	}
// 	return 1;
// }

// CMD:gotoship(playerid) {

//     SetPlayerPos(playerid,1929.2999,1469.4764,1094.4314);
//     SetPlayerFacingAngle(playerid,94.2796);
//     SetPlayerWeather(playerid,67);
//     SetPlayerTime(playerid,5,0);
//     SetPlayerInterior(playerid,2);
//     SetCameraBehindPlayer(playerid);

//     return 1;
// }
