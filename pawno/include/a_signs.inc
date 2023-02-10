/*
 *                                      'a_signs.inc'
 * Traffic  Signs
 * Include made by adri1
 *
 *
 * Functions:
    CreateTrafficSign(signid, Float:x, Float:y, Float:z, Float:rz, Float:viewdistance = 200.0, string[] = "")
    DestroyTrafficSign(signid)
    IsValidTrafficSign(signid)
 *
 * Callbacks
    None...
 */

#if defined _trafficsigns_included
#endinput
#endif
#define _trafficsigns_included

#if !defined STREAMER_TYPE_OBJECT
#include <streamer>
#endif

#define SIGN_STOP               0
#define SIGN_YIELD              1
#define SIGN_PROHIBITED         2
#define SIGN_PROHIBITED2    3
#define SIGN_CROSSWALK          4
#define SIGN_MAXVELOCITY    5
#define SIGN_MINVELOCITY    6
#define SIGN_MAXTONNE       7
#define SIGN_WALKERONLY     8
#define SIGN_BIKEONLY       9
#define SIGN_BIKEPROHIBITED 10
#define SIGN_PROHIBITEDDIR1 11
#define SIGN_PROHIBITEDDIR2 12
#define SIGN_PROHIBITEDDIR3 13
#define SIGN_PROHIBITEDDIR4 14
#define SIGN_GODIR1             15
#define SIGN_GODIR2             16
#define SIGN_GODIR3             17
#define SIGN_GODIR4             18
#define SIGN_TAXI                       19
#define SIGN_BUS                        20
#define SIGN_PARKING1           21
#define SIGN_PARKING2           22
#define MAX_SIGNS           500

enum TrafficSignEnumerator
{
        M1,
        M2,
        M3,
        M4,
        M5
}
new TrafficSign[MAX_SIGNS][TrafficSignEnumerator];
new SignCounter;

stock CreateTrafficSign(signid, Float:x, Float:y, Float:z, Float:rz, Float:viewdistance = 200.0, string[] = "")
{
        switch(signid)
        {
            case SIGN_STOP:
            {
                        new trafficsign_id = CreateDynamicObjectEx(8548, x, y, z, 0.0, 0.0, rz, viewdistance, viewdistance);
                        SetDynamicObjectMaterial(trafficsign_id, 0, 967, "cj_barr_set_1", "Stop2_64");
                        SetDynamicObjectMaterial(trafficsign_id, 1, 967, "cj_barr_set_1", "Stop2_64", 0xFFCCCCCC);
                        SignCounter++;
                        TrafficSign[SignCounter][M1] = trafficsign_id;
                        return SignCounter;
                }
                case SIGN_YIELD:
                {
                    new trafficsign_id = CreateDynamicObjectEx(8548, x, y, z, 0, 0, rz, viewdistance, viewdistance);
                    new Float:p[9];
                    aTraffic_Position(trafficsign_id, -0.525, -0.05, 0.95, p[0], p[1], p[2]);
                    aTraffic_Position(trafficsign_id, -0.5215, -0.055, 0.98, p[3], p[4], p[5]);
                    aTraffic_Position(trafficsign_id, -0.525, -0.025, 0.95, p[6], p[7], p[8]);

                    CreateDynamicObjectEx(2986, p[0], p[1], p[2], -90.0000, 90.0000, rz-90, viewdistance, viewdistance);
                    CreateDynamicObjectEx(2986, p[3], p[4], p[5], -90.0000, 90.0000, rz-90, viewdistance, viewdistance);
                    CreateDynamicObjectEx(2986, p[6], p[7], p[8], -90.0000, 90.0000, rz-90, viewdistance, viewdistance);
                    SetDynamicObjectMaterial(trafficsign_id, 0, 0, "null", "null");
                    SetDynamicObjectMaterial(trafficsign_id, 1, 0, "null", "null");
                    SetDynamicObjectMaterialText(trafficsign_id+1, 0, "5", 50, "Webdings", 100, 0, -65536, 0, 1);
                    SetDynamicObjectMaterialText(trafficsign_id+2, 0, "5", 50, "Webdings", 70, 0, 0xFFFFFFFF, 0, 1);
                    SetDynamicObjectMaterialText(trafficsign_id+3, 0, "5", 50, "Webdings", 100, 0, 0xFFCCCCCC, 0, 1);
                    SignCounter++;
                    TrafficSign[SignCounter][M1] = trafficsign_id;
                    TrafficSign[SignCounter][M2] = trafficsign_id+1;
                    TrafficSign[SignCounter][M3] = trafficsign_id+2;
                    TrafficSign[SignCounter][M4] = trafficsign_id+3;
                    return SignCounter;
                }
                case SIGN_PROHIBITED:
                {
                    new trafficsign_id = CreateDynamicObjectEx(8548, x, y, z, 0.0, 0.0, rz, viewdistance, viewdistance);
                    new Float:p[6];
                    aTraffic_Position(trafficsign_id, -0.03, -0.03, 0.45, p[0], p[1], p[2]);
                    aTraffic_Position(trafficsign_id, 0.48, -0.055, 0.835, p[3], p[4], p[5]);
                    CreateDynamicObjectEx(2986, p[0], p[1], p[2], 0.0000, 90.0000, rz-90, viewdistance, viewdistance);
                    CreateDynamicObjectEx(2986, p[3], p[4], p[5], -90.0000, -90.0000, rz-90, viewdistance, viewdistance);
                    SetDynamicObjectMaterial(trafficsign_id, 0, 0, "null", "null");
                    SetDynamicObjectMaterialText(trafficsign_id+1, 0, "l", 60, "Wingdings", 120, 0, -65536, 0, 1);
                    SetDynamicObjectMaterialText(trafficsign_id+2, 0, "-", 60, "Arial", 200, 0, -1, 0, 1);
                    SignCounter++;
                    TrafficSign[SignCounter][M1] = trafficsign_id;
                    TrafficSign[SignCounter][M2] = trafficsign_id+1;
                    TrafficSign[SignCounter][M3] = trafficsign_id+2;
                    return SignCounter;
                }
                case SIGN_PROHIBITED2:
                {
                    new trafficsign_id = CreateDynamicObjectEx(8548, x, y, z, 0.0, 0.0, rz, viewdistance, viewdistance);
                    new Float:p[9];
                    aTraffic_Position(trafficsign_id, -0.03, -0.03, 0.45, p[0], p[1], p[2]);
                    aTraffic_Position(trafficsign_id, -0.025, -0.04, 0.455, p[3], p[4], p[5]);
                    aTraffic_Position(trafficsign_id, 0.45, -0.045, 1.15, p[6], p[7], p[8]);
                    CreateDynamicObjectEx(2986, p[0], p[1], p[2], 0.0000, 90.0000, rz-90, viewdistance, viewdistance);
                    CreateDynamicObjectEx(2986, p[3], p[4], p[5], 0.0000, 90.0000, rz-90, viewdistance, viewdistance);
                    CreateDynamicObjectEx(2986, p[6], p[7], p[8], 115.5, 90.0000, rz-90, viewdistance, viewdistance);
                    SetDynamicObjectMaterial(trafficsign_id, 0, 0, "null", "null");
                    SetDynamicObjectMaterialText(trafficsign_id+1, 0, "l", 60, "Wingdings", 120, 0, -65536, 0, 1);
                    SetDynamicObjectMaterialText(trafficsign_id+2, 0, "l", 60, "Wingdings", 90, 0, 0xFFFFFFFF, 0, 1);
                    SetDynamicObjectMaterialText(trafficsign_id+3, 0, "\\", 60, "Arial", 95, 1, -65536, 0, 1);
                    SignCounter++;
                    TrafficSign[SignCounter][M1] = trafficsign_id;
                    TrafficSign[SignCounter][M2] = trafficsign_id+1;
                    TrafficSign[SignCounter][M3] = trafficsign_id+2;
                    TrafficSign[SignCounter][M4] = trafficsign_id+3;
                    return SignCounter;
                }
                case SIGN_CROSSWALK:
                {
                    new trafficsign_id = CreateDynamicObjectEx(8548, x, y, z, 0.0, 0.0, rz, viewdistance, viewdistance);
                    new Float:p[9];
                    aTraffic_Position(trafficsign_id, -0.52, -0.04, 0.9, p[0], p[1], p[2]);
                    aTraffic_Position(trafficsign_id, -0.49, -0.06, 0.835, p[3], p[4], p[5]);
                    aTraffic_Position(trafficsign_id, -0.5, -0.06, 0.95, p[6], p[7], p[8]);
                    CreateDynamicObjectEx(2986, p[0], p[1], p[2], -90.0000, 90.0000, rz-90, viewdistance, viewdistance);
                    CreateDynamicObjectEx(2986, p[3], p[4], p[5], -90.0000, 90.0000, rz-90, viewdistance, viewdistance);
                    CreateDynamicObjectEx(2986, p[6], p[7], p[8], 90.0000, -90.0000, rz-90, viewdistance, viewdistance);
                    SetDynamicObjectMaterial(trafficsign_id, 0, 18646, "matcolours", "lightblue", 0xFF00CCFF);
                    SetDynamicObjectMaterial(trafficsign_id, 1, 18646, "matcolours", "grey");
                    SetDynamicObjectMaterialText(trafficsign_id+1, 0, "6", 50, "Webdings", 90, 0, 0xFFFFFFFF, 0, 1);
                    SetDynamicObjectMaterialText(trafficsign_id+2, 0, "||||||||", 60, "Arial", 20, 1, -16777216, 0, 1);
                    SetDynamicObjectMaterialText(trafficsign_id+3, 0, "m", 60, "Webdings", 45, 0, -16777216, 0, 1);
                    SignCounter++;
                    TrafficSign[SignCounter][M1] = trafficsign_id;
                    TrafficSign[SignCounter][M2] = trafficsign_id+1;
                    TrafficSign[SignCounter][M3] = trafficsign_id+2;
                    TrafficSign[SignCounter][M4] = trafficsign_id+3;
                    return SignCounter;
                }
                case SIGN_MAXVELOCITY:
                {
                    new trafficsign_id = CreateDynamicObjectEx(8548, x, y, z, 0.0, 0.0, rz, viewdistance, viewdistance);
                    new Float:p[9];
                    aTraffic_Position(trafficsign_id, -0.03, -0.05, 0.45, p[0], p[1], p[2]);
                    aTraffic_Position(trafficsign_id, -0.025, -0.055, 0.455, p[3], p[4], p[5]);
                    aTraffic_Position(trafficsign_id, 0.48, -0.065, 0.95, p[6], p[7], p[8]);
                    CreateDynamicObjectEx(2986, p[0], p[1], p[2], 0.0000, 90.0000, rz-90, viewdistance, viewdistance);
                    CreateDynamicObjectEx(2986, p[3], p[4], p[5], 0.0000, 90.0000, rz-90, viewdistance, viewdistance);
                    CreateDynamicObjectEx(2986, p[6], p[7], p[8], 90.0000, 90.0000, rz-90, viewdistance, viewdistance);
                    SetDynamicObjectMaterial(trafficsign_id, 0, 0, "null", "null");
                    SetDynamicObjectMaterialText(trafficsign_id+1, 0, "l", 60, "Wingdings", 120, 0, -65536, 0, 1);
                    SetDynamicObjectMaterialText(trafficsign_id+2, 0, "l", 60, "Wingdings", 90, 0, 0xFFFFFFFF, 0, 1);
                    SetDynamicObjectMaterialText(trafficsign_id+3, 0, string, 60, "Arial", 30, 1, 0xFF000000, 0, 1);
                    SignCounter++;
                    TrafficSign[SignCounter][M1] = trafficsign_id;
                    TrafficSign[SignCounter][M2] = trafficsign_id+1;
                    TrafficSign[SignCounter][M3] = trafficsign_id+2;
                    TrafficSign[SignCounter][M4] = trafficsign_id+3;
                    return SignCounter;
                }
                case SIGN_MINVELOCITY:
                {
                    new trafficsign_id = CreateDynamicObjectEx(8548, x, y, z, 0.0, 0.0, rz, viewdistance, viewdistance);
                    new Float:p[6];
                    aTraffic_Position(trafficsign_id, -0.03, -0.05, 0.45, p[0], p[1], p[2]);
                    aTraffic_Position(trafficsign_id, 0.5, -0.06, 0.95, p[3], p[4], p[5]);
                    CreateDynamicObjectEx(2986, p[0], p[1], p[2], 0, 90, rz-90, viewdistance, viewdistance);
                    CreateDynamicObjectEx(2986, p[3], p[4], p[5], 90, 90, rz-90, viewdistance, viewdistance);
                    SetDynamicObjectMaterial(trafficsign_id, 0, 0, "null", "null");
                    SetDynamicObjectMaterialText(trafficsign_id+1, 0, "l", 60, "Wingdings", 120, 0, 0xFF00CCFF, 0, 1);
                    SetDynamicObjectMaterialText(trafficsign_id+2, 0, string, 60, "Arial", 30, 1, 0xFFFFFFFF, 0, 1);
                    SignCounter++;
                    TrafficSign[SignCounter][M1] = trafficsign_id;
                    TrafficSign[SignCounter][M2] = trafficsign_id+1;
                    TrafficSign[SignCounter][M3] = trafficsign_id+2;
                    return SignCounter;
                }
                case SIGN_MAXTONNE:
                {
                    new trafficsign_id = CreateDynamicObjectEx(8548, x, y, z, 0.0, 0.0, rz, viewdistance, viewdistance);
                    new Float:p[9];
                    aTraffic_Position(trafficsign_id, -0.03, -0.05, 0.45, p[0], p[1], p[2]);
                    aTraffic_Position(trafficsign_id, -0.025, -0.055, 0.455, p[3], p[4], p[5]);
                    aTraffic_Position(trafficsign_id, 0.48, -0.065, 0.95, p[6], p[7], p[8]);
                    CreateDynamicObjectEx(2986, p[0], p[1], p[2], 0.0000, 90.0000, rz-90, viewdistance, viewdistance);
                    CreateDynamicObjectEx(2986, p[3], p[4], p[5], 0.0000, 90.0000, rz-90, viewdistance, viewdistance);
                    CreateDynamicObjectEx(2986, p[6], p[7], p[8], 90.0000, 90.0000, rz-90, viewdistance, viewdistance);
                    SetDynamicObjectMaterial(trafficsign_id, 0, 0, "null", "null");
                    SetDynamicObjectMaterialText(trafficsign_id+1, 0, "l", 60, "Wingdings", 120, 0, -65536, 0, 1);
                    SetDynamicObjectMaterialText(trafficsign_id+2, 0, "l", 60, "Wingdings", 90, 0, 0xFFFFFFFF, 0, 1);
                    SetDynamicObjectMaterialText(trafficsign_id+3, 0, string, 60, "Arial", 30, 1, 0xFF000000, 0, 1);
                    SignCounter++;
                    TrafficSign[SignCounter][M1] = trafficsign_id;
                    TrafficSign[SignCounter][M2] = trafficsign_id+1;
                    TrafficSign[SignCounter][M3] = trafficsign_id+2;
                    TrafficSign[SignCounter][M4] = trafficsign_id+3;
                    return SignCounter;
                }
                case SIGN_WALKERONLY:
                {
                    new trafficsign_id = CreateDynamicObjectEx(8548, x, y, z, 0.0, 0.0, rz, viewdistance, viewdistance);
                    new Float:p[6];
                    aTraffic_Position(trafficsign_id, -0.03, -0.025, 0.45, p[0], p[1], p[2]);
                    aTraffic_Position(trafficsign_id, -0.5, -0.05, 0.95, p[3], p[4], p[5]);
                    CreateDynamicObjectEx(2986, p[0], p[1], p[2], 0, 90, rz-90, viewdistance, viewdistance);
                    CreateDynamicObjectEx(2986, p[3], p[4], p[5], 90.0000, -90.0000, rz-90, viewdistance, viewdistance);
                    SetDynamicObjectMaterial(trafficsign_id, 0, 0, "null", "null");
                    SetDynamicObjectMaterialText(trafficsign_id+1, 0, "l", 60, "Wingdings", 120, 0, 0xFF00CCFF, 0, 1);
            		SetDynamicObjectMaterialText(trafficsign_id+2, 0, "m", 60, "Webdings", 45, 0, -16777216, 0, 1);
            		SignCounter++;
              		TrafficSign[SignCounter][M1] = trafficsign_id;
	                TrafficSign[SignCounter][M2] = trafficsign_id+1;
	                TrafficSign[SignCounter][M3] = trafficsign_id+2;
	                return SignCounter;
                }
                case SIGN_BIKEONLY:
                {
                    new trafficsign_id = CreateDynamicObjectEx(8548, x, y, z, 0.0, 0.0, rz, viewdistance, viewdistance);
                    new Float:p[6];
                    aTraffic_Position(trafficsign_id, -0.03, -0.025, 0.45, p[0], p[1], p[2]);
                    aTraffic_Position(trafficsign_id, -0.5, -0.05, 0.975, p[3], p[4], p[5]);
                    CreateDynamicObjectEx(2986, p[0], p[1], p[2], 0, 90, rz-90, viewdistance, viewdistance);
                    CreateDynamicObjectEx(2986, p[3], p[4], p[5], 90.0000, -90.0000, rz-90, viewdistance, viewdistance);
                    SetDynamicObjectMaterial(trafficsign_id, 0, 0, "null", "null");
                    SetDynamicObjectMaterialText(trafficsign_id+1, 0, "l", 60, "Wingdings", 120, 0, 0xFF00CCFF, 0, 1);
            		SetDynamicObjectMaterialText(trafficsign_id+2, 0, "b", 60, "Webdings", 65, 1, -16777216, 0, 1);
              		SignCounter++;
              		TrafficSign[SignCounter][M1] = trafficsign_id;
              		TrafficSign[SignCounter][M2] = trafficsign_id+1;
              		TrafficSign[SignCounter][M3] = trafficsign_id+2;
              		return SignCounter;
                }
                case SIGN_BIKEPROHIBITED:
                {
	                    new trafficsign_id = CreateDynamicObjectEx(8548, x, y, z, 0.0, 0.0, rz, viewdistance, viewdistance);
	                    new Float:p[9];
	                    aTraffic_Position(trafficsign_id, -0.03, -0.03, 0.45, p[0], p[1], p[2]);
	                    aTraffic_Position(trafficsign_id, -0.025, -0.04, 0.455, p[3], p[4], p[5]);
	            		aTraffic_Position(trafficsign_id, -0.5, -0.06, 0.975, p[6], p[7], p[8]);
                        CreateDynamicObjectEx(2986, p[0], p[1], p[2], 0.0000, 90.0000, rz-90, viewdistance, viewdistance);
                        CreateDynamicObjectEx(2986, p[3], p[4], p[5], 0.0000, 90.0000, rz-90, viewdistance, viewdistance);
                        CreateDynamicObjectEx(2986, p[6], p[7], p[8], 90.0000, -90.0000, rz-90, viewdistance, viewdistance);
                        SetDynamicObjectMaterial(trafficsign_id, 0, 0, "null", "null");
                        SetDynamicObjectMaterialText(trafficsign_id+1, 0, "l", 60, "Wingdings", 120, 0, -65536, 0, 1);
                        SetDynamicObjectMaterialText(trafficsign_id+2, 0, "l", 60, "Wingdings", 90, 0, 0xFFFFFFFF, 0, 1);
                        SetDynamicObjectMaterialText(trafficsign_id+3, 0, "b", 60, "Webdings", 65, 1, -16777216, 0, 1);
                        SignCounter++;
                        TrafficSign[SignCounter][M1] = trafficsign_id;
                        TrafficSign[SignCounter][M2] = trafficsign_id+1;
                        TrafficSign[SignCounter][M3] = trafficsign_id+2;
                        TrafficSign[SignCounter][M4] = trafficsign_id+3;
                        return SignCounter;
                }
                case SIGN_PROHIBITEDDIR1:
                {
	                    new trafficsign_id = CreateDynamicObjectEx(8548, x, y, z, 0.0, 0.0, rz, viewdistance, viewdistance);
	                    new Float:p[9];
	                    aTraffic_Position(trafficsign_id, -0.03, -0.03, 0.45, p[0], p[1], p[2]);
	                    aTraffic_Position(trafficsign_id, -0.025, -0.04, 0.455, p[3], p[4], p[5]);
	            		aTraffic_Position(trafficsign_id, -0.485, -0.06, 0.945, p[6], p[7], p[8]);
                        CreateDynamicObjectEx(2986, p[0], p[1], p[2], 0.0000, 90.0000, rz-90, viewdistance, viewdistance);
                        CreateDynamicObjectEx(2986, p[3], p[4], p[5], 0.0000, 90.0000, rz-90, viewdistance, viewdistance);
                        CreateDynamicObjectEx(2986, p[6], p[7], p[8], 90.0000, -90.0000, rz-90, viewdistance, viewdistance);
                        SetDynamicObjectMaterial(trafficsign_id, 0, 0, "null", "null");
                        SetDynamicObjectMaterialText(trafficsign_id+1, 0, "l", 60, "Wingdings", 120, 0, -65536, 0, 1);
                        SetDynamicObjectMaterialText(trafficsign_id+2, 0, "l", 60, "Wingdings", 90, 0, 0xFFFFFFFF, 0, 1);
                        SetDynamicObjectMaterialText(trafficsign_id+3, 0, "ñ", 60, "Wingdings", 65, 1, -16777216, 0, 1);
                        SignCounter++;
                        TrafficSign[SignCounter][M1] = trafficsign_id;
                        TrafficSign[SignCounter][M2] = trafficsign_id+1;
                        TrafficSign[SignCounter][M3] = trafficsign_id+2;
                        TrafficSign[SignCounter][M4] = trafficsign_id+3;
                        return SignCounter;
                }
                case SIGN_PROHIBITEDDIR2:
                {
	                    new trafficsign_id = CreateDynamicObjectEx(8548, x, y, z, 0.0, 0.0, rz, viewdistance, viewdistance);
	                    new Float:p[9];
	                    aTraffic_Position(trafficsign_id, -0.03, -0.03, 0.45, p[0], p[1], p[2]);
	                    aTraffic_Position(trafficsign_id, -0.025, -0.04, 0.455, p[3], p[4], p[5]);
	            		aTraffic_Position(trafficsign_id, -0.015, -0.06, 1.45, p[6], p[7], p[8]);
                        CreateDynamicObjectEx(2986, p[0], p[1], p[2], 0.0000, 90.0000, rz-90, viewdistance, viewdistance);
                        CreateDynamicObjectEx(2986, p[3], p[4], p[5], 0.0000, 90.0000, rz-90, viewdistance, viewdistance);
                        CreateDynamicObjectEx(2986, p[6], p[7], p[8], 0.0000, -90.0000, rz-90, viewdistance, viewdistance);
                        SetDynamicObjectMaterial(trafficsign_id, 0, 0, "null", "null");
                        SetDynamicObjectMaterialText(trafficsign_id+1, 0, "l", 60, "Wingdings", 120, 0, -65536, 0, 1);
                        SetDynamicObjectMaterialText(trafficsign_id+2, 0, "l", 60, "Wingdings", 90, 0, 0xFFFFFFFF, 0, 1);
                        SetDynamicObjectMaterialText(trafficsign_id+3, 0, "ñ", 60, "Wingdings", 65, 1, -16777216, 0, 1);
                        SignCounter++;
                        TrafficSign[SignCounter][M1] = trafficsign_id;
                        TrafficSign[SignCounter][M2] = trafficsign_id+1;
                        TrafficSign[SignCounter][M3] = trafficsign_id+2;
                        TrafficSign[SignCounter][M4] = trafficsign_id+3;
                        return SignCounter;
                }
                case SIGN_PROHIBITEDDIR3:
                {
	                    new trafficsign_id = CreateDynamicObjectEx(8548, x, y, z, 0.0, 0.0, rz, viewdistance, viewdistance);
	                    new Float:p[9];
	                    aTraffic_Position(trafficsign_id, -0.03, -0.03, 0.45, p[0], p[1], p[2]);
	                    aTraffic_Position(trafficsign_id, -0.025, -0.04, 0.455, p[3], p[4], p[5]);
	            		aTraffic_Position(trafficsign_id, 0.485, -0.06, 0.95, p[6], p[7], p[8]);
                        CreateDynamicObjectEx(2986, p[0], p[1], p[2], 0.0000, 90.0000, rz-90, viewdistance, viewdistance);
                        CreateDynamicObjectEx(2986, p[3], p[4], p[5], 0.0000, 90.0000, rz-90, viewdistance, viewdistance);
                        CreateDynamicObjectEx(2986, p[6], p[7], p[8], -90.0000, -90.0000, rz-90, viewdistance, viewdistance);
                        SetDynamicObjectMaterial(trafficsign_id, 0, 0, "null", "null");
                        SetDynamicObjectMaterialText(trafficsign_id+1, 0, "l", 60, "Wingdings", 120, 0, -65536, 0, 1);
                        SetDynamicObjectMaterialText(trafficsign_id+2, 0, "l", 60, "Wingdings", 90, 0, 0xFFFFFFFF, 0, 1);
                        SetDynamicObjectMaterialText(trafficsign_id+3, 0, "ñ", 60, "Wingdings", 65, 1, -16777216, 0, 1);
                        SignCounter++;
                        TrafficSign[SignCounter][M1] = trafficsign_id;
                        TrafficSign[SignCounter][M2] = trafficsign_id+1;
                        TrafficSign[SignCounter][M3] = trafficsign_id+2;
                        TrafficSign[SignCounter][M4] = trafficsign_id+3;
                        return SignCounter;
                }
                case SIGN_PROHIBITEDDIR4:
                {
	                    new trafficsign_id = CreateDynamicObjectEx(8548, x, y, z, 0.0, 0.0, rz, viewdistance, viewdistance);
	                    new Float:p[9];
	                    aTraffic_Position(trafficsign_id, -0.03, -0.03, 0.45, p[0], p[1], p[2]);
	                    aTraffic_Position(trafficsign_id, -0.025, -0.04, 0.455, p[3], p[4], p[5]);
	            		aTraffic_Position(trafficsign_id, 0.015, -0.06, 0.45, p[6], p[7], p[8]);
                        CreateDynamicObjectEx(2986, p[0], p[1], p[2], 0.0000, 90.0000, rz-90, viewdistance, viewdistance);
                        CreateDynamicObjectEx(2986, p[3], p[4], p[5], 0.0000, 90.0000, rz-90, viewdistance, viewdistance);
                        CreateDynamicObjectEx(2986, p[6], p[7], p[8], 180.0000, -90.0000, rz-90, viewdistance, viewdistance);
                        SetDynamicObjectMaterial(trafficsign_id, 0, 0, "null", "null");
                        SetDynamicObjectMaterialText(trafficsign_id+1, 0, "l", 60, "Wingdings", 120, 0, -65536, 0, 1);
                        SetDynamicObjectMaterialText(trafficsign_id+2, 0, "l", 60, "Wingdings", 90, 0, 0xFFFFFFFF, 0, 1);
                        SetDynamicObjectMaterialText(trafficsign_id+3, 0, "ñ", 60, "Wingdings", 65, 1, -16777216, 0, 1);
                        SignCounter++;
                        TrafficSign[SignCounter][M1] = trafficsign_id;
                        TrafficSign[SignCounter][M2] = trafficsign_id+1;
                        TrafficSign[SignCounter][M3] = trafficsign_id+2;
                        TrafficSign[SignCounter][M4] = trafficsign_id+3;
                        return SignCounter;
                }
                case SIGN_GODIR1:
                {
	                    new trafficsign_id = CreateDynamicObjectEx(8548, x, y, z, 0.0, 0.0, rz, viewdistance, viewdistance);
	                    new Float:p[6];
	                    aTraffic_Position(trafficsign_id, -0.03, -0.025, 0.45, p[0], p[1], p[2]);
	                    aTraffic_Position(trafficsign_id, -0.5, -0.06, 0.945, p[3], p[4], p[5]);
                        CreateDynamicObjectEx(2986, p[0], p[1], p[2], 0, 90, rz-90, viewdistance, viewdistance);
                        CreateDynamicObjectEx(2986, p[3], p[4], p[5], 90.0000, -90.0000, rz-90, viewdistance, viewdistance);
                        SetDynamicObjectMaterial(trafficsign_id, 0, 0, "null", "null");
                        SetDynamicObjectMaterialText(trafficsign_id+1, 0, "l", 60, "Wingdings", 120, 0, 0xFF00CCFF, 0, 1);
            			SetDynamicObjectMaterialText(trafficsign_id+2, 0, "ñ", 60, "Wingdings", 65, 1, -16777216, 0, 1);
                        SignCounter++;
                        TrafficSign[SignCounter][M1] = trafficsign_id;
                        TrafficSign[SignCounter][M2] = trafficsign_id+1;
                        TrafficSign[SignCounter][M3] = trafficsign_id+2;
                        return SignCounter;
                }
                case SIGN_GODIR2:
                {
                    	new trafficsign_id = CreateDynamicObjectEx(8548, x, y, z, 0.0, 0.0, rz, viewdistance, viewdistance);
                        new Float:p[6];
	                    aTraffic_Position(trafficsign_id, -0.03, -0.025, 0.45, p[0], p[1], p[2]);
	                    aTraffic_Position(trafficsign_id, -0.015, -0.06, 1.45, p[3], p[4], p[5]);
                        CreateDynamicObjectEx(2986, p[0], p[1], p[2], 0, 90, rz-90, viewdistance, viewdistance);
                        CreateDynamicObjectEx(2986, p[3], p[4], p[5], 0.0000, -90.0000, rz-90, viewdistance, viewdistance);
                        SetDynamicObjectMaterial(trafficsign_id, 0, 0, "null", "null");
                        SetDynamicObjectMaterialText(trafficsign_id+1, 0, "l", 60, "Wingdings", 120, 0, 0xFF00CCFF, 0, 1);
           	 			SetDynamicObjectMaterialText(trafficsign_id+2, 0, "ñ", 60, "Wingdings", 65, 1, -16777216, 0, 1);
                        SignCounter++;
                        TrafficSign[SignCounter][M1] = trafficsign_id;
                        TrafficSign[SignCounter][M2] = trafficsign_id+1;
                        TrafficSign[SignCounter][M3] = trafficsign_id+2;
                        return SignCounter;
                }
                case SIGN_GODIR3:
                {
                    	new trafficsign_id = CreateDynamicObjectEx(8548, x, y, z, 0.0, 0.0, rz, viewdistance, viewdistance);
                        new Float:p[6];
	                    aTraffic_Position(trafficsign_id, -0.03, -0.025, 0.45, p[0], p[1], p[2]);
	                    aTraffic_Position(trafficsign_id, 0.5, -0.06, 0.95, p[3], p[4], p[5]);
                        CreateDynamicObjectEx(2986, p[0], p[1], p[2], 0, 90, rz-90, viewdistance, viewdistance);
                        CreateDynamicObjectEx(2986, p[3], p[4], p[5], -90.0000, -90.0000, rz-90, viewdistance, viewdistance);
                        SetDynamicObjectMaterial(trafficsign_id, 0, 0, "null", "null");
                        SetDynamicObjectMaterialText(trafficsign_id+1, 0, "l", 60, "Wingdings", 120, 0, 0xFF00CCFF, 0, 1);
            			SetDynamicObjectMaterialText(trafficsign_id+2, 0, "ñ", 60, "Wingdings", 65, 1, -16777216, 0, 1);
                        SignCounter++;
                        TrafficSign[SignCounter][M1] = trafficsign_id;
                        TrafficSign[SignCounter][M2] = trafficsign_id+1;
                        TrafficSign[SignCounter][M3] = trafficsign_id+2;
                        return SignCounter;
                }
                case SIGN_GODIR4:
                {
                    	new trafficsign_id = CreateDynamicObjectEx(8548, x, y, z, 0.0, 0.0, rz, viewdistance, viewdistance);
                        new Float:p[6];
                    	aTraffic_Position(trafficsign_id, -0.03, -0.025, 0.45, p[0], p[1], p[2]);
                    	aTraffic_Position(trafficsign_id, 0.015, -0.06, 0.45, p[3], p[4], p[5]);
                        CreateDynamicObjectEx(2986, p[0], p[1], p[2], 0, 90, rz-90, viewdistance, viewdistance);
                        CreateDynamicObjectEx(2986, p[3], p[4], p[5], 180.0000, -90.0000, rz-90, viewdistance, viewdistance);
                        SetDynamicObjectMaterial(trafficsign_id, 0, 0, "null", "null");
                        SetDynamicObjectMaterialText(trafficsign_id+1, 0, "l", 60, "Wingdings", 120, 0, 0xFF00CCFF, 0, 1);
            			SetDynamicObjectMaterialText(trafficsign_id+2, 0, "ñ", 60, "Wingdings", 65, 1, -16777216, 0, 1);
                        SignCounter++;
                        TrafficSign[SignCounter][M1] = trafficsign_id;
                        TrafficSign[SignCounter][M2] = trafficsign_id+1;
                        TrafficSign[SignCounter][M3] = trafficsign_id+2;
                        return SignCounter;
                }
                case SIGN_TAXI:
                {
	                    new trafficsign_id = CreateDynamicObjectEx(8548, x, y, z, 0.0, 0.0, rz, viewdistance, viewdistance);
	                    new Float:p[3];
	                    aTraffic_Position(trafficsign_id, 0.5, -0.06, 0.95, p[0], p[1], p[2]);
                        CreateDynamicObjectEx(2986, p[0], p[1], p[2], 90.0000, 90.0000, rz-90, viewdistance, viewdistance);
                        SetDynamicObjectMaterial(trafficsign_id, 0, 18646, "matcolours", "lightblue", 0xFF00CCFF);
                        SetDynamicObjectMaterial(trafficsign_id, 1, 18646, "matcolours", "grey");
                        SetDynamicObjectMaterialText(trafficsign_id+1, 0, "SONI", 60, "Arial", 30, 1, -16777216, 0, 1);
                        SignCounter++;
                        TrafficSign[SignCounter][M1] = trafficsign_id;
                        TrafficSign[SignCounter][M2] = trafficsign_id+1;
                        return SignCounter;
                }
                case SIGN_BUS:
                {
	                    new trafficsign_id = CreateDynamicObjectEx(8548, x, y, z, 0.0, 0.0, rz, viewdistance, viewdistance);
	                    new Float:p[3];
	                    aTraffic_Position(trafficsign_id, 0.5, -0.06, 0.95, p[0], p[1], p[2]);
                        CreateDynamicObjectEx(2986, p[0], p[1], p[2], 90.0000, 90.0000, rz-90, viewdistance, viewdistance);
                        SetDynamicObjectMaterial(trafficsign_id, 0, 18646, "matcolours", "lightblue", 0xFF00CCFF);
                        SetDynamicObjectMaterial(trafficsign_id, 1, 18646, "matcolours", "grey");
                        SetDynamicObjectMaterialText(trafficsign_id+1, 0, "BUS", 60, "Arial", 30, 1, -16777216, 0, 1);
                        SignCounter++;
                        TrafficSign[SignCounter][M1] = trafficsign_id;
                        TrafficSign[SignCounter][M2] = trafficsign_id+1;
                        return SignCounter;
                }
                case SIGN_PARKING1:
                {
                    	new trafficsign_id = CreateDynamicObjectEx(8548, x, y, z, 0.0, 0.0, rz, viewdistance, viewdistance);
                        new Float:p[3];
                    	aTraffic_Position(trafficsign_id, 0.5, -0.06, 0.95, p[0], p[1], p[2]);
                        CreateDynamicObjectEx(2986, p[0], p[1], p[2], 90.0000, 90.0000, rz-90, viewdistance, viewdistance);
                        SetDynamicObjectMaterial(trafficsign_id, 0, 18646, "matcolours", "lightblue", 0xFF00CCFF);
                        SetDynamicObjectMaterial(trafficsign_id, 1, 18646, "matcolours", "grey");
                        SetDynamicObjectMaterialText(trafficsign_id+1, 0, "PARKING", 60, "Arial", 15, 1, -16777216, 0, 1);
                        SignCounter++;
                        TrafficSign[SignCounter][M1] = trafficsign_id;
                        TrafficSign[SignCounter][M2] = trafficsign_id+1;
                        return SignCounter;
                }
                case SIGN_PARKING2:
                {
                    	new trafficsign_id = CreateDynamicObjectEx(8548, x, y, z, 0.0, 0.0, rz, viewdistance, viewdistance);
                        new Float:p[3];
                    	aTraffic_Position(trafficsign_id, 0.5, -0.06, 0.95, p[0], p[1], p[2]);
                        CreateDynamicObjectEx(2986, p[0], p[1], p[2], 90.0000, 90.0000, rz-90, viewdistance, viewdistance);
                        SetDynamicObjectMaterial(trafficsign_id, 0, 18646, "matcolours", "lightblue", 0xFF00CCFF);
                        SetDynamicObjectMaterial(trafficsign_id, 1, 18646, "matcolours", "grey");
                        SetDynamicObjectMaterialText(trafficsign_id+1, 0, "P", 60, "Arial", 60, 1, -16777216, 0, 1);
                        SignCounter++;
                        TrafficSign[SignCounter][M1] = trafficsign_id;
                        TrafficSign[SignCounter][M2] = trafficsign_id+1;
                        return SignCounter;
                }
        }
        return -1;
}

stock DestroyTrafficSign(signid)
{
        if(IsValidDynamicObject(TrafficSign[signid][M1]))
        {
                DestroyDynamicObject(TrafficSign[signid][M1]);
                SignCounter--;
                if(IsValidDynamicObject(TrafficSign[signid][M2])) DestroyDynamicObject(TrafficSign[signid][M2]);
                if(IsValidDynamicObject(TrafficSign[signid][M3])) DestroyDynamicObject(TrafficSign[signid][M3]);
                if(IsValidDynamicObject(TrafficSign[signid][M4])) DestroyDynamicObject(TrafficSign[signid][M4]);
                if(IsValidDynamicObject(TrafficSign[signid][M5])) DestroyDynamicObject(TrafficSign[signid][M5]);
        }
}

stock IsValidTrafficSign(signid)
{
    if(IsValidDynamicObject(TrafficSign[signid][M1])) return true;
        return false;
}

stock aTraffic_Position(objectid, Float:offset_x, Float:offset_y, Float:offset_z, &Float:x, &Float:y, &Float:z)
{
    	new Float:object_px,
        Float:object_py,
        Float:object_pz,
        Float:object_rx,
        Float:object_ry,
        Float:object_rz;
	    GetDynamicObjectPos(objectid, object_px, object_py, object_pz);
	    GetDynamicObjectRot(objectid, object_rx, object_ry, object_rz);
	    new Float:cos_x = floatcos(object_rx, degrees),
        Float:cos_y = floatcos(object_ry, degrees),
        Float:cos_z = floatcos(object_rz, degrees),
        Float:sin_x = floatsin(object_rx, degrees),
        Float:sin_y = floatsin(object_ry, degrees),
        Float:sin_z = floatsin(object_rz, degrees);
	    x = object_px + offset_x * cos_y * cos_z - offset_x * sin_x * sin_y * sin_z - offset_y * cos_x * sin_z + offset_z * sin_y * cos_z + offset_z * sin_x * cos_y * sin_z;
	    y = object_py + offset_x * cos_y * sin_z + offset_x * sin_x * sin_y * cos_z + offset_y * cos_x * cos_z + offset_z * sin_y * sin_z - offset_z * sin_x * cos_y * cos_z;
	    z = object_pz - offset_x * cos_x * sin_y + offset_y * sin_x + offset_z * cos_x * cos_y;
}
