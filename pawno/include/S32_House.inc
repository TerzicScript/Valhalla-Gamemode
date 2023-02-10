/*
 * S32_House - Create house with just one line (MySQL)!
 * Copyright(c)System32
 * This file is provided as is (no warranties)
 
 
 * I started developing this include a 2-3 months ago but I had a big problems, now it's fixed and everything works!
 * Functions: 52
 * Commands: 18
 * Callbacks: 4
 * Credits:
     * System32 - Almost everything!
     * The Guy - Helped me a lot, thank you!
     * Y_Less - y_hooks, y_commands, sscanf & foreach!
     * G-Stylezz (BlueG) - MySQL plugin!
     * Some guy on forums like wups, Y_Less - helped me with some things!
 * That is basically it, have fun with this include and easy scripting!
 */
 
#if !defined _inc_a_samp
	#include <a_samp>
#endif
#if !defined _inc_a_mysql
	#include <a_mysql>
#endif
#if !defined _inc_foreach
	#include <foreach>
#endif
#include <YSI\y_hooks>
#include <YSI\y_commands>

#define MAX_HOUSES 150
#define MAX_CURRENT_HOUSES 50
#define house_version "v2.0.0"
#if !defined MAX_HOUSES
	#error Please define the max houses (#define MAX_HOUSES)
#endif


#define COLOR_LIME                                              0x10F441AA
#define COLOR_KRED                                              0xFF0000FF
#define COLOR_YELLOW                                            0xFFFF00AA

enum hInfo
{
	hOwner[24],
	Float: hEnterX,
	Float: hEnterY,
	Float: hEnterZ,
	Float: hExitX,
	Float: hExitY,
	Float: hExitZ,
	hInterior,
	hPrice,
	hVirtualWorld,
	hOwned,
	hLocked,
	Text3D: hLabel,
	hPickup,
	hWeaponID1,
	hWeaponID2,
	hWeaponID3,
	hWeaponID1Ammo,
	hWeaponID2Ammo,
	hWeaponID3Ammo,
	hMoney,
	hRentUser[24],
	hRentPrice,
	hRented,
	hRentDisabled,
	hAlarm,
	hCar,
	hVehicleID,
	Float: hCarX,
	Float: hCarY,
	Float: hCarZ,
	Float: hCarA,
	hCarColor1,
	hCarColor2,
	hCarLocked,
	hCarOwner[24],
	hCarWeaponID1,
	hCarWeaponID2,
	hCarWeaponID1Ammo,
	hCarWeaponID2Ammo,
	hCarMoney
};
new HouseInfo[MAX_HOUSES][hInfo];

enum hcInfo
{
	Float: hcEnterX,
	Float: hcEnterY,
	Float: hcEnterZ,
	Float: hcExitX,
	Float: hcExitY,
	Float: hcExitZ,
	hcInterior,
	hcVirtualWorld,
	hcPrice,
	hcRentPrice,
	Text3D: hcLabel,
	hcPickup
}
new CurrentHouseInfo[MAX_CURRENT_HOUSES][hcInfo];

new Iterator:Houses<MAX_HOUSES>, hstring[128], HQuery[1000], HouseID, hsavingstring[3000], House_Weapon[MAX_PLAYERS][13], House_Ammo[MAX_PLAYERS][13], RentFeeTimer, Float: PPos[4], CurrentHouseID;
new bool: PlayerEnteredHisHouse[MAX_PLAYERS] = false, bool: PlayerEnteredHisHouseCar[MAX_PLAYERS] = false, bool: PlayerCanRobHouse[MAX_PLAYERS] = true, HouseLockBreaking[MAX_PLAYERS], HouseRobbing[MAX_PLAYERS], CanRobHouseTimer[MAX_PLAYERS];

forward OnPlayerEnterHouse(playerid, houseid);
forward OnPlayerExitHouse(playerid, houseid);
forward OnPlayerEnterHouseVehicle(playerid);
forward OnPlayerExitHouseVehicle(playerid);
forward RentFeeUp();
forward BreakingLock(playerid);
forward RobbingHouse(playerid);
forward CanRobHouse(playerid);

//*****************************           *****************************
//***************************** FUNCTIONS *****************************
//*****************************           *****************************




/*

 • Function: CreateHouse(Float: EnterX, Float: EnterY, Float: EnterZ, Interior, Float: InteriorX, Float: InteriorY, Float: InteriorZ, Price, VirtualWorld, RentPrice) 
 • Data storage: MySQL (G-Stylezzz's plugin)
 • Usage: Creating house, use this in OnGameModeInit or OnFilterScriptInit!
 • Parameters:
        EnterX, EnterY, EnterZ: Coordinates where you can enter house, also on that coordiantes will create pickup and 3D text!
        ExitX, ExitY, ExitZ: Coordinates where you can exit house, this coordinates are coordiantes of interior, you can find interiors on http://weedarr.wikidot.com/interior or http://wiki.sa-mp.com/wiki/InteriorIDs
		Interior: ID od interior you want, see the web page on the parameter above
		Price: Price for buying house
		VirtulWorld: Always increase this because if you have 2 same interior and player are in the (Example one is in his house, second is in his too) they will see themself, It will look that they have same house! (Bad explained :/)
		RentPrice: Price for renting house, when player buy house maximum rent price is 10000 so, if you put it 20000 than he change it, he won't be able to set it again on 20000
 • Example: CreateHouse(-2521.3315,-623.4722,132.7717, 3, 1527.229980,-11.574499,1002.097106, 1000, 0, 5000);

*/

stock CreateHouse(Float: EnterX, Float: EnterY, Float: EnterZ, Interior, Float: ExitX, Float: ExitY, Float: ExitZ, Price, VirtualWorld, RentPrice, VehicleID = 0, Float: CarX = 0.0, Float: CarY = 0.0, Float: CarZ = 0.0, Float: CarA = 0.0, CarColor1 = 0, CarColor2 = 0)
{
    format(HQuery, sizeof(HQuery), "SELECT * FROM `house` WHERE `HouseID` = %d", HouseID);
    mysql_query(HQuery);
    mysql_store_result();
 	if(mysql_num_rows() == 0) 
    {
        format(HouseInfo[HouseID][hOwner], 24, "None");
        format(HouseInfo[HouseID][hRentUser], 24, "None");
        format(HouseInfo[HouseID][hCarOwner], 24, "None");
		HouseInfo[HouseID][hEnterX] = EnterX;
		HouseInfo[HouseID][hEnterY] = EnterY;
		HouseInfo[HouseID][hEnterZ] = EnterZ;
		HouseInfo[HouseID][hExitX] = ExitX;
		HouseInfo[HouseID][hExitY] = ExitY;
		HouseInfo[HouseID][hExitZ] = ExitZ;
		HouseInfo[HouseID][hInterior] = Interior;
		HouseInfo[HouseID][hVirtualWorld] = VirtualWorld;
		HouseInfo[HouseID][hPrice] = Price;
		HouseInfo[HouseID][hRentPrice] = RentPrice;
		HouseInfo[HouseID][hVehicleID] = VehicleID;
		HouseInfo[HouseID][hCarX] = CarX;
		HouseInfo[HouseID][hCarY] = CarY;
		HouseInfo[HouseID][hCarZ] = CarZ;
		HouseInfo[HouseID][hCarA] = CarA;
		HouseInfo[HouseID][hCarColor1] = CarColor1;
		HouseInfo[HouseID][hCarColor2] = CarColor2;
        format(hstring, sizeof(hstring), "For sale!\nPrice: %d\nHouse ID: %d\nType /buyhouse to buy house!", Price, HouseID);
        format(HQuery, sizeof(HQuery), "INSERT INTO `house` (`User`, `EnterX`, `EnterY`, `EnterZ`, `ExitX`, `ExitY`, `ExitZ`, `Interior`, `Price`, `VirtualWorld`, `Owned`, `Locked`, `Alarm`, `Weapon ID 1`, `Weapon ID 2`, `Weapon ID 3`, `Weapon ID 1 Ammo`, `Weapon ID 2 Ammo`, `Weapon ID 3 Ammo`, `Money`,");
		format(HQuery, sizeof(HQuery), "%s `Rent User`, `Rent Price`, `Rented`, `Rent Disabled`, `VehicleID`, `CarX`, `CarY`, `CarZ`, `CarA`, `Color1`, `Color2`, `Car Locked`, `Car Owner`, `Car Weapon ID 1`, `Car Weapon ID 2`, `Car Weapon ID 1 Ammo`, `Car Weapon ID 2 Ammo`, `Car Money`, `HouseID`) VALUES", HQuery);
		format(HQuery, sizeof(HQuery), "%s  ('None', %f, %f, %f, %f, %f, %f, %d, %d, %d, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', %d, 0, 0, %d, %f, %f, %f, %f, %d, %d, 0, 'None', 0, 0, 0, 0, 0, %d)", HQuery, HouseInfo[HouseID][hEnterX], HouseInfo[HouseID][hEnterY], HouseInfo[HouseID][hEnterZ], HouseInfo[HouseID][hExitX], HouseInfo[HouseID][hExitY],
		HouseInfo[HouseID][hExitZ], HouseInfo[HouseID][hInterior], HouseInfo[HouseID][hPrice], HouseInfo[HouseID][hVirtualWorld], HouseInfo[HouseID][hRentPrice], HouseInfo[HouseID][hVehicleID], HouseInfo[HouseID][hCarX], HouseInfo[HouseID][hCarY], HouseInfo[HouseID][hCarZ], HouseInfo[HouseID][hCarA], HouseInfo[HouseID][hCarColor1], HouseInfo[HouseID][hCarColor2], HouseID);
	    mysql_query(HQuery);
        HouseInfo[HouseID][hLabel] = Create3DTextLabel(hstring, 0x21DD00FF, EnterX, EnterY, EnterZ, 40.0, 0);
        HouseInfo[HouseID][hPickup] = CreatePickup(1273, 23, EnterX, EnterY, EnterZ, 0);
        if(HouseInfo[HouseID][hVehicleID] != 0 && HouseInfo[HouseID][hCarX] != 0.0 && HouseInfo[HouseID][hCarY] != 0.0 && HouseInfo[HouseID][hCarZ] != 0.0 && HouseInfo[HouseID][hCarA] > 0.0)
        {
			HouseInfo[HouseID][hCar] = AddStaticVehicle(VehicleID, CarX, CarY, CarZ, CarA, CarColor1, CarColor2);
        }
	}
	else
	{
        if(mysql_fetch_row_format(HQuery, "|"))
        {
			mysql_fetch_field_row(hsavingstring, "User"); format(HouseInfo[HouseID][hOwner], 24, "%s", hsavingstring);
            mysql_fetch_field_row(hsavingstring, "EnterX"); HouseInfo[HouseID][hEnterX] = floatstr(hsavingstring);
            mysql_fetch_field_row(hsavingstring, "EnterY"); HouseInfo[HouseID][hEnterY] = floatstr(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "EnterZ"); HouseInfo[HouseID][hEnterZ] = floatstr(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "ExitX"); HouseInfo[HouseID][hExitX] = floatstr(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "ExitY"); HouseInfo[HouseID][hExitY] = floatstr(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "ExitZ"); HouseInfo[HouseID][hExitZ] = floatstr(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "Interior"); HouseInfo[HouseID][hInterior] = strval(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "Price"); HouseInfo[HouseID][hPrice] = strval(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "VirtualWorld"); HouseInfo[HouseID][hVirtualWorld] = strval(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "Owned"); HouseInfo[HouseID][hOwned] = strval(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "Locked"); HouseInfo[HouseID][hLocked] = strval(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "Weapon ID 1"); HouseInfo[HouseID][hWeaponID1] = strval(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "Weapon ID 2"); HouseInfo[HouseID][hWeaponID2] = strval(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "Weapon ID 3"); HouseInfo[HouseID][hWeaponID3] = strval(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "Weapon ID 1 Ammo"); HouseInfo[HouseID][hWeaponID1Ammo] = strval(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "Weapon ID 2 Ammo"); HouseInfo[HouseID][hWeaponID2Ammo] = strval(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "Weapon ID 3 Ammo"); HouseInfo[HouseID][hWeaponID3Ammo] = strval(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "Money"); HouseInfo[HouseID][hMoney] = strval(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "Rent User"); format(HouseInfo[HouseID][hRentUser], 24, "%s", hsavingstring);
			mysql_fetch_field_row(hsavingstring, "Rent Price"); HouseInfo[HouseID][hRentPrice] = strval(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "Rented"); HouseInfo[HouseID][hRented] = strval(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "Rent Disabled"); HouseInfo[HouseID][hRentDisabled] = strval(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "Alarm"); HouseInfo[HouseID][hAlarm] = strval(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "VehicleID"); HouseInfo[HouseID][hVehicleID] = strval(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "CarX"); HouseInfo[HouseID][hCarX] = floatstr(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "CarY"); HouseInfo[HouseID][hCarY] = floatstr(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "CarZ"); HouseInfo[HouseID][hCarZ] = floatstr(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "CarA"); HouseInfo[HouseID][hCarA] = floatstr(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "Color1"); HouseInfo[HouseID][hCarColor1] = strval(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "Color2"); HouseInfo[HouseID][hCarColor2] = strval(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "Car Locked"); HouseInfo[HouseID][hCarLocked] = strval(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "Car Owner"); format(HouseInfo[HouseID][hCarOwner], 24, "%s", hsavingstring);
			mysql_fetch_field_row(hsavingstring, "Car Weapon ID 1"); HouseInfo[HouseID][hCarWeaponID1] = strval(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "Car Weapon ID 2"); HouseInfo[HouseID][hCarWeaponID2] = strval(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "Car Weapon ID 1 Ammo"); HouseInfo[HouseID][hCarWeaponID1Ammo] = strval(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "Car Weapon ID 2 Ammo"); HouseInfo[HouseID][hCarWeaponID2Ammo] = strval(hsavingstring);
			mysql_fetch_field_row(hsavingstring, "Car Money"); HouseInfo[HouseID][hCarMoney] = strval(hsavingstring);
			if(HouseInfo[HouseID][hOwned] == 1)
			{
			    if(HouseInfo[HouseID][hRentDisabled] == 0)
			    {
					format(hstring, sizeof(hstring), "Owner: %s\nHouse ID: %d\nRent User: %s\nRent Price: %d", HouseInfo[HouseID][hOwner], HouseID, HouseInfo[HouseID][hRentUser], HouseInfo[HouseID][hRentPrice]);
					HouseInfo[HouseID][hLabel] = Create3DTextLabel(hstring, 0x21DD00FF, HouseInfo[HouseID][hEnterX], HouseInfo[HouseID][hEnterY], HouseInfo[HouseID][hEnterZ], 40.0, 0);
	                HouseInfo[HouseID][hPickup] = CreatePickup(1239, 23, HouseInfo[HouseID][hEnterX], HouseInfo[HouseID][hEnterY], HouseInfo[HouseID][hEnterZ], 0);
				}
				else
				{
   					format(hstring, sizeof(hstring), "Owner: %s\nHouse ID: %d\nRent Disabled", HouseInfo[HouseID][hOwner], HouseID);
					HouseInfo[HouseID][hLabel] = Create3DTextLabel(hstring, 0x21DD00FF, HouseInfo[HouseID][hEnterX], HouseInfo[HouseID][hEnterY], HouseInfo[HouseID][hEnterZ], 40.0, 0);
                	HouseInfo[HouseID][hPickup] = CreatePickup(1239, 23, HouseInfo[HouseID][hEnterX], HouseInfo[HouseID][hEnterY], HouseInfo[HouseID][hEnterZ], 0);
				}
			}
			else 
			{
			    format(hstring, sizeof(hstring), "For sale!\nPrice: %d\nHouse ID: %d\nType /buyhouse to buy house!", Price, HouseID);
			    HouseInfo[HouseID][hLabel] = Create3DTextLabel(hstring, 0x21DD00FF, HouseInfo[HouseID][hEnterX], HouseInfo[HouseID][hEnterY], HouseInfo[HouseID][hEnterZ], 40.0, 0);
                HouseInfo[HouseID][hPickup] = CreatePickup(1273, 23, HouseInfo[HouseID][hEnterX], HouseInfo[HouseID][hEnterY], HouseInfo[HouseID][hEnterZ], 0);
			}
  		}
    	if(HouseInfo[HouseID][hVehicleID] != 0 && HouseInfo[HouseID][hCarX] != 0.0 && HouseInfo[HouseID][hCarY] != 0.0 && HouseInfo[HouseID][hCarZ] != 0.0 && HouseInfo[HouseID][hCarA] > 0.0)
        {
			HouseInfo[HouseID][hCar] = AddStaticVehicle(HouseInfo[HouseID][hVehicleID], HouseInfo[HouseID][hCarX], HouseInfo[HouseID][hCarY], HouseInfo[HouseID][hCarZ], HouseInfo[HouseID][hCarA], HouseInfo[HouseID][hCarColor1], HouseInfo[HouseID][hCarColor2]);
        }
	}
    mysql_free_result();
    HouseID++;
    if(HouseID > MAX_HOUSES)
	{
		print("You reached maximum number of houses! Please enlarge the #define MAX_HOUSES\nin S32_House.inc! If you don't enlarge it, some houses won't work properly!");
	}
	Iter_Add(Houses, HouseID);
	return 1;
}



/*

 • Function: GetHouseUser(houseid)
 • Usage: Getting name of user of specific house!
 • Parameters:
        houseid: ID of house that you want to get user (owner)
 • Example: format(string, sizeof(string), "House user of house id %d is %s", houseid, GetHouseUser(houseid));

*/

stock GetHouseUser(houseid)
{
	new howner[24];
	format(howner, sizeof(howner), "%s", HouseInfo[houseid][hOwner]);
	return howner;
}



/*

 • Function: GetHouseRentUser(houseid)
 • Usage: Getting name of rent user of specific house!
 • Parameters:
        houseid: ID of house that you want to get rent user
 • Example: format(string, sizeof(string), "House rent user of house id %d is %s", houseid, GetHouseRentUser(houseid));

*/

stock GetHouseRentUser(houseid)
{
	new howner[24];
	format(howner, sizeof(howner), "%s", HouseInfo[houseid][hRentUser]);
	return howner;
}



/*

 • Function: GetHouseEnterPos(houseid)
 • Usage: Getting the enter position (XYZ) of specific house!
 • Parameters:
        houseid: ID of house that you want to get enter position
 • Example: format(string, sizeof(string), "House enter XYZ of house id %d is %s", houseid, GetHouseEnterPos(houseid));

*/

stock GetHouseEnterPos(houseid)
{
    new getxyz[128];
    format(getxyz, sizeof(getxyz), "%f, %f, %f", HouseInfo[houseid][hEnterX], HouseInfo[houseid][hEnterY], HouseInfo[houseid][hEnterZ]);
    return getxyz;
}



/*

 • Function: GetHouseExitPos(houseid)
 • Usage: Getting the exit position (XYZ) of specific house!
 • Parameters:
        houseid: ID of house that you want to get exit position
 • Example: format(string, sizeof(string), "House exit XYZ of house id %d is %s", houseid, GetHouseExitPos(houseid));

*/

stock GetHouseExitPos(houseid)
{
    new getxyz[128];
    format(getxyz, sizeof(getxyz), "%f, %f, %f", HouseInfo[houseid][hExitX], HouseInfo[houseid][hExitY], HouseInfo[houseid][hExitZ]);
    return getxyz;
}



/*

 • Function: GetHouseEnterX(houseid)
 • Usage: Getting the enter X position of specific house!
 • Parameters:
        houseid: ID of house that you want to get enter X position
 • Example: format(string, sizeof(string), "House enter X of house id %d is %s", houseid, GetHouseEnterX(houseid));

*/

stock GetHouseEnterX(houseid)
{
    new getx[128];
    format(getx, sizeof(getx), "%f", HouseInfo[houseid][hEnterX]);
    return getx;
}



/*

 • Function: GetHouseEnterY(houseid)
 • Usage: Getting the enter Y position of specific house!
 • Parameters:
        houseid: ID of house that you want to get enter Y position
 • Example: format(string, sizeof(string), "House enter Y of house id %d is %s", houseid, GetHouseEnterY(houseid));

*/

stock GetHouseEnterY(houseid)
{
    new gety[128];
    format(gety, sizeof(gety), "%f", HouseInfo[houseid][hEnterY]);
    return gety;
}



/*

 • Function: GetHouseEnterZ(houseid)
 • Usage: Getting the enter Z position of specific house!
 • Parameters:
        houseid: ID of house that you want to get enter Z position
 • Example: format(string, sizeof(string), "House enter Z of house id %d is %s", houseid, GetHouseEnterZ(houseid));

*/

stock GetHouseEnterZ(houseid)
{
    new getz[128];
    format(getz, sizeof(getz), "%f", HouseInfo[houseid][hEnterZ]);
    return getz;
}



/*

 • Function: GetHouseExitX(houseid)
 • Usage: Getting the enter X position of specific house!
 • Parameters:
        houseid: ID of house that you want to get enter X position
 • Example: format(string, sizeof(string), "House exit X of house id %d is %s", houseid, GetHouseExitX(houseid));

*/

stock GetHouseExitX(houseid)
{
    new getx[128];
    format(getx, sizeof(getx), "%f", HouseInfo[houseid][hExitX]);
    return getx;
}



/*

 • Function: GetHouseExitY(houseid)
 • Usage: Getting the enter Y position of specific house!
 • Parameters:
        houseid: ID of house that you want to get enter Y position
 • Example: format(string, sizeof(string), "House exit Y of house id %d is %s", houseid, GetHouseExitY(houseid));

*/

stock GetHouseExitY(houseid)
{
    new gety[128];
    format(gety, sizeof(gety), "%f", HouseInfo[houseid][hExitY]);
    return gety;
}



/*

 • Function: GetHouseExitZ(houseid)
 • Usage: Getting the enter Z position of specific house!
 • Parameters:
        houseid: ID of house that you want to get enter Z position
 • Example: format(string, sizeof(string), "House exit Z of house id %d is %s", houseid, GetHouseExitZ(houseid));

*/

stock GetHouseExitZ(houseid)
{
    new getz[128];
    format(getz, sizeof(getz), "%f", HouseInfo[houseid][hExitZ]);
    return getz;
}



/*

 • Function: GetHousePrice(houseid)
 • Usage: Getting the price of specific house!
 • Parameters:
        houseid: ID of house that you want to get price
 • Example: format(string, sizeof(string), "House price of house id %d is %d", houseid, GetHousePrice(houseid));

*/

stock GetHousePrice(houseid) return HouseInfo[houseid][hPrice];



/*

 • Function: GetHouseInterior(houseid)
 • Usage: Getting the interior of specific house!
 • Parameters:
        houseid: ID of house that you want to get interior
 • Example: format(string, sizeof(string), "House interior of house id %d is %d", houseid, GetHouseInterior(houseid));

*/

stock GetHouseInterior(houseid) return HouseInfo[houseid][hInterior];



/*

 • Function: GetHouseVirtualWorld(houseid)
 • Usage: Getting the virtualworld of specific house!
 • Parameters:
        houseid: ID of house that you want to get virtualworld
 • Example: format(string, sizeof(string), "House virtualworld of house id %d is %d", houseid, GetHouseVirtualWorld(houseid));

*/

stock GetHouseVirtualWorld(houseid) return HouseInfo[houseid][hVirtualWorld];



/*

 • Function: GetHouseRentPrice(houseid)
 • Usage: Getting the rent price of specific house!
 • Parameters:
        houseid: ID of house that you want to get rent price
 • Example: format(string, sizeof(string), "House rent priceof house id %d is %d", houseid, GetHouseRentPrice(houseid));

*/

stock GetHouseRentPrice(houseid) return HouseInfo[houseid][hRentPrice];



/*

 • Function: GetHouseMoney(houseid)
 • Usage: Getting the money (stored money) of specific house!
 • Parameters:
        houseid: ID of house that you want to get money
 • Example: format(string, sizeof(string), "House money of house id %d is %d", houseid, GetHouseMoney(houseid));

*/

stock GetHouseMoney(houseid) return HouseInfo[houseid][hMoney];



/*

 • Function: GetHouseWeaponID1(houseid)
 • Usage: Getting the weapon id 1 of specific house!
 • Parameters:
        houseid: ID of house that you want to get the weapon id 1
 • Example: format(string, sizeof(string), "House weapon id 1 of house id %d is %d", houseid, GetHouseWeaponID1(houseid));

*/

stock GetHouseWeaponID1(houseid) return HouseInfo[houseid][hWeaponID1];



/*

 • Function: GetHouseWeaponID2(houseid)
 • Usage: Getting the weapon id 2 of specific house!
 • Parameters:
        houseid: ID of house that you want to get the weapon id 2
 • Example: format(string, sizeof(string), "House weapon id 2 of house id %d is %d", houseid, GetHouseWeaponID2(houseid));

*/
stock GetHouseWeaponID2(houseid) return HouseInfo[houseid][hWeaponID2];



/*

 • Function: GetHouseWeaponID3(houseid)
 • Usage: Getting the weapon id 3 of specific house!
 • Parameters:
        houseid: ID of house that you want to get the weapon id 3
 • Example: format(string, sizeof(string), "House weapon id 3 of house id %d is %d", houseid, GetHouseWeaponID3(houseid));

*/

stock GetHouseWeaponID3(houseid) return HouseInfo[houseid][hWeaponID3];



/*

 • Function: GetHouseWeaponID1Ammo(houseid)
 • Usage: Getting the weapon id 1 of specific house!
 • Parameters:
        houseid: ID of house that you want to get the weapon id 1 ammo
 • Example: format(string, sizeof(string), "House weapon id 1 ammo of house id %d is %d", houseid, GetHouseWeaponID1Ammo(houseid));

*/

stock GetHouseWeaponID1Ammo(houseid) return HouseInfo[houseid][hWeaponID1Ammo];



/*

 • Function: GetHouseWeaponID2Ammo(houseid)
 • Usage: Getting the weapon id 2 of specific house!
 • Parameters:
        houseid: ID of house that you want to get the weapon id 2 ammo
 • Example: format(string, sizeof(string), "House weapon id 2 ammo of house id %d is %d", houseid, GetHouseWeaponID2Ammo(houseid));

*/

stock GetHouseWeaponID2Ammo(houseid) return HouseInfo[houseid][hWeaponID2Ammo];



/*

 • Function: GetHouseWeaponID3Ammo(houseid)
 • Usage: Getting the weapon id 3 of specific house!
 • Parameters:
        houseid: ID of house that you want to get the weapon id 3 ammo
 • Example: format(string, sizeof(string), "House weapon id 3 ammo of house id %d is %d", houseid, GetHouseWeaponID3Ammo(houseid));

*/

stock GetHouseWeaponID3Ammo(houseid) return HouseInfo[houseid][hWeaponID3Ammo];



/*

 • Function: GetHouseWeaponID1Name(houseid)
 • Usage: Getting the name of weapon id 1 of specific house!
 • Parameters:
        houseid: ID of house that you want to get the name of weapon id 1
 • Example: format(string, sizeof(string), "House name of weapon id 1 of house id %d is %d", houseid, GetHouseWeaponID1Name(houseid));

*/

stock GetHouseWeaponID1Name(houseid)
{
	new weaponid[128], weaponid2[128];
	format(weaponid, sizeof(weaponid), "%s", GetWeapon(HouseInfo[houseid][hWeaponID1]));
	format(weaponid2, sizeof(weaponid2), "Nothing");
	if(HouseInfo[houseid][hWeaponID1] > 0) return weaponid;
	else return weaponid2;
}



/*

 • Function: GetHouseWeaponID2Name(houseid)
 • Usage: Getting the name of weapon id 2 of specific house!
 • Parameters:
        houseid: ID of house that you want to get the name of weapon id 2
 • Example: format(string, sizeof(string), "House name of weapon id 2 of house id %d is %d", houseid, GetHouseWeaponID2Name(houseid));

*/

stock GetHouseWeaponID2Name(houseid)
{
	new weaponid[128], weaponid2[128];
	format(weaponid, sizeof(weaponid), "%s", GetWeapon(HouseInfo[houseid][hWeaponID2]));
	format(weaponid2, sizeof(weaponid2), "Nothing");
	if(HouseInfo[houseid][hWeaponID2] > 0) return weaponid;
	else return weaponid2;
}



/*

 • Function: GetHouseWeaponID13Name(houseid)
 • Usage: Getting the name of weapon id 3 of specific house!
 • Parameters:
        houseid: ID of house that you want to get the name of weapon id 3
 • Example: format(string, sizeof(string), "House name of weapon id 3 of house id %d is %d", houseid, GetHouseWeaponID3Name(houseid));

*/

stock GetHouseWeaponID3Name(houseid)
{
	new weaponid[128], weaponid2[128];
	format(weaponid, sizeof(weaponid), "%s", GetWeapon(HouseInfo[houseid][hWeaponID3]));
	format(weaponid2, sizeof(weaponid2), "Nothing");
	if(HouseInfo[houseid][hWeaponID3] > 0) return weaponid;
	else return weaponid2;
}



/*

 • Function: IsHouseOwned(houseid)
 • Usage: Checking if is house owned of specific house!
 • Parameters:
        houseid: ID of house that you want to check if is owned
 • Example: if(IsHouseOwned(houseid)) return SendClientMessage(playerid, -1, "House is owned!");
	        else SendClientMessage(playerid, -1, "House is not owned!");

*/

stock IsHouseOwned(houseid)
{
	if(HouseInfo[houseid][hOwned] == 1) return 1;
	else return 0;
}



/*

 • Function: IsHouseLocked(houseid)
 • Usage: Checking if is house locked of specific house!
 • Parameters:
        houseid: ID of house that you want to check if is locked
 • Example: if(IsHouseLocked(houseid)) return SendClientMessage(playerid, -1, "House is locked!");
	        else SendClientMessage(playerid, -1, "House is not locked!");

*/

stock IsHouseLocked(houseid)
{
	if(HouseInfo[houseid][hLocked] == 1) return 1;
	else return 0;
}



/*

 • Function: IsHouseRented(houseid)
 • Usage: Checking if is house owned of specific house!
 • Parameters:
        houseid: ID of house that you want to check if is rented
 • Example: if(IsHouseRented(houseid)) return SendClientMessage(playerid, -1, "House is rented!");
	        else SendClientMessage(playerid, -1, "House is not rented!");

*/

stock IsHouseRented(houseid)
{
	if(HouseInfo[houseid][hRented] == 1) return 1;
	else return 0;
}



/*

 • Function: IsHouseRentDisabled(houseid)
 • Usage: Checking if is house owned of specific house!
 • Parameters:
        houseid: ID of house that you want to check if is rent disabled
 • Example: if(IsHouseRentDisabled(houseid)) return SendClientMessage(playerid, -1, "House rent is disabled!");
	        else SendClientMessage(playerid, -1, "House rent is not disabled!");

*/

stock IsHouseRentDisabled(houseid)
{
	if(HouseInfo[houseid][hRentDisabled] == 1) return 1;
	else return 0;
}



/*

 • Function: IsHouseHaveAlarm(houseid)
 • Usage: Checking if is house have an alarm!
 • Parameters:
        houseid: ID of house that you want to check if it have an alarm
 • Example: if(IsHouseHaveAlarm(houseid)) return SendClientMessage(playerid, -1, "House have an alarm!");
	        else SendClientMessage(playerid, -1, "House doesn't have an alarm!");

*/

stock IsHouseHaveAlarm(houseid)
{
	if(HouseInfo[houseid][hAlarm] == 1) return 1;
	else return 0;
}



/*

 • Function: IsPlayerHouseOwner(playerid, houseid)
 • Usage: Checking if is player owner of specific house!
 • Parameters:
        playerid: ID of player that you want preform check
        houseid: ID of house that you want to check if is player owner
 • Example: if(IsPlayerHouseOwner(playerid, houseid)) return SendClientMessage(playerid, -1, "You are owner of the house!");
	        else SendClientMessage(playerid, -1, "You are not owner of the house!");

*/

stock IsPlayerHouseOwner(playerid, houseid)
{
	if(!strcmp(HouseInfo[houseid][hOwner], GetName(playerid), false)) return 1;
	else return 0;
}



/*

 • Function: IsPlayerBuyAnyHouse(playerid)
 • Usage: Checking if is player buyed house and he is owner of any house (used when you try to rent room but you already have house)!
 • Parameters:
        playerid: ID of player that you want preform check
 • Example: if(IsPlayerBuyAnyHouse(playerid)) return SendClientMessage(playerid, -1, "You have house already!");
	        else SendClientMessage(playerid, -1, "You don't have house!");

*/

stock IsPlayerBuyAnyHouse(playerid)
{
	new HQuery2[200];
	format(HQuery2, sizeof(HQuery2), "SELECT User FROM `house` WHERE `User` = '%s'", GetName(playerid));
	mysql_query(HQuery2);
	mysql_store_result();
	if(mysql_num_rows() == 1)
	{
		mysql_free_result();
		return 1;
	}
	else
	{
		mysql_free_result();
		return 0;
	}
}



/*

 • Function: IsPlayerRentAnyHouse(playerid)
 • Usage: Checking if is player rented house and he is rent user of any house (used when you try to rent room but you already rented some house)!
 • Parameters:
        playerid: ID of player that you want preform check
 • Example: if(IsPlayerRentAnyHouse(playerid)) return SendClientMessage(playerid, -1, "You rent house already!");
	        else SendClientMessage(playerid, -1, "You don't rent house!");

*/

stock IsPlayerRentAnyHouse(playerid)
{
	new HQuery2[200];
	format(HQuery2, sizeof(HQuery2), "SELECT `Rent User` FROM `house` WHERE `Rent User` = '%s'", GetName(playerid));
	mysql_query(HQuery2);
	mysql_store_result();
	if(mysql_num_rows() == 1)
	{
		mysql_free_result();
		return 1;
	}
	else
	{
		mysql_free_result();
		return 0;
	}
}



/*

 • Function: IsPlayerBuyHouse(playerid, houseid)
 • Usage: Checking if is player rented house and he is rent user of any house (used when you try to rent room but you already rented some house)!
 • Parameters:
        playerid: ID of player that you want preform check
        houseid: ID of house that you want to check if is player buy house
 • Example: if(IsPlayerBuyHouse(playerid, houseid)) return SendClientMessage(playerid, -1, "You buy this house already!");
	        else SendClientMessage(playerid, -1, "You didn't buy rent this house!");

*/

stock IsPlayerBuyHouse(playerid, houseid)
{
	new HQuery2[200];
	format(HQuery2, sizeof(HQuery2), "SELECT User FROM `house` WHERE `User` = '%s' AND `HouseID` = %d", GetName(playerid), houseid);
	mysql_query(HQuery2);
	mysql_store_result();
	if(mysql_num_rows() == 1)
	{
		mysql_free_result();
		return 1;
	}
	else
	{
		mysql_free_result();
		return 0;
	}
}



/*

 • Function: IsPlayerRentHouse(playerid, houseid)
 • Usage: Checking if is player rented house and he is rent user of any house (used when you try to rent room but you already rented some house)!
 • Parameters:
        playerid: ID of player that you want preform check
        houseid: ID of house that you want to check if is player rented user
 • Example: if(IsPlayerRentAnyHouse(playerid, houseid)) return SendClientMessage(playerid, -1, "You rent this house already!");
	        else SendClientMessage(playerid, -1, "You don't rent this house!");

*/

stock IsPlayerRentHouse(playerid, houseid)
{
	new HQuery2[200];
	format(HQuery2, sizeof(HQuery2), "SELECT `Rent User` FROM `house` WHERE `Rent User` = '%s' AND `HouseID` = %d", GetName(playerid), houseid);
	mysql_query(HQuery2);
	mysql_store_result();
	if(mysql_num_rows() == 1)
	{
		mysql_free_result();
		return 1;
	}
	else
	{
		mysql_free_result();
		return 0;
	}
}



/*

 • Function: IsHouseExist(houseid)
 • Usage: Checking if is player rented house and he is rent user of any house (used when you try to rent room but you already rented some house)!
 • Parameters:
        houseid: ID of house that you want to check if is exist
 • Example: if(IsHouseExist(houseid)) return SendClientMessage(playerid, -1, "House exist!");
	        else SendClientMessage(playerid, -1, "House doesn't exist!");

*/

stock IsHouseExist(houseid)
{
	new HQuery2[200];
	format(HQuery2, sizeof(HQuery2), "SELECT HouseID FROM `house` WHERE `HouseID` = '%d'", houseid);
	mysql_query(HQuery2);
	mysql_store_result();
	if(mysql_num_rows() == 1)
	{
		mysql_free_result();
		return 1;
	}
	else
	{
		mysql_free_result();
		return 0;
	}
}



/*

 • Function: IsPlayerHouseRentUser(playerid, houseid)
 • Usage: Checking if is player rent user of specific house!
 • Parameters:
        playerid: ID of player that you want preform check
        houseid: ID of house that you want to check if is player rent user
 • Example: if(IsPlayerHouseRentUser(playerid, houseid)) return SendClientMessage(playerid, -1, "You are rent user of the house!");
	        else SendClientMessage(playerid, -1, "You are not rent user of the house!");

*/

stock IsPlayerHouseRentUser(playerid, houseid)
{
	if(!strcmp(HouseInfo[houseid][hRentUser], GetName(playerid), false)) return 1;
	else return 0;
}



/*

 • Function: GetTotalHouses(playerid, houseid)
 • Usage: Getting all houses, easiser than counting line etc.! Use this in OnGameModeInit after all houses!
 • Example: printf("Total houses: %d", GetTotalHouses());

*/

stock GetTotalHouses() return Iter_Count(Houses);



/*

 • Function: IsHouseWeaponSlotFree(houseid, slot)
 • Usage: Checking if is slot free in stored weapons of specific house!
 • Parameters:
        houseid: ID of house that you want to check if is slot free
        slot: Slot of stored weapons from 1-3!
 • Example: if(IsHouseWeaponSlotFree(houseid, 1)) return SendClientMessage(playerid, -1, "Slot 1 is free!");
	        else SendClientMessage(playerid, -1, "Slot 1 is not free!");

*/

stock IsHouseWeaponSlotFree(houseid, slot)
{
	switch(slot)
	{
	    case 1:
	    {
	        if(HouseInfo[houseid][hWeaponID1] < 1) return 1;
	        else return 0;
	    }
	    case 2:
	    {
 	        if(HouseInfo[houseid][hWeaponID2] < 1) return 1;
	        else return 0;
	    }
	    case 3:
	    {
 	        if(HouseInfo[houseid][hWeaponID3] < 1) return 1;
	        else return 0;
	    }
	}
	return slot;
}



/*

 • Function: SpawnPlayerAtHouse(playerid)
 • Usage: Spawning player at his house, use this in OnPlayerSpawn!
 • Parameters:
        playerid: ID of player that you want to spawn!
 • Example: SpawnPlayerAtHouse(playerid);

*/

stock SpawnPlayerAtHouse(playerid)
{
    foreach(Houses, i)
    {
	 	if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false) || !strcmp(HouseInfo[i][hRentUser], GetName(playerid), false) && HouseInfo[i][hOwned] == 1)
	    {
		 	new HQuery2[200];
			format(HQuery2, sizeof(HQuery2), "SELECT HouseID FROM `house` WHERE `HouseID` = '%d'", i);
			mysql_query(HQuery2);
			mysql_store_result();
			if(mysql_num_rows() == 1)
			{
		        SetPlayerPos(playerid, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]);
		        SetPlayerInterior(playerid, HouseInfo[i][hInterior]);
		        SetPlayerVirtualWorld(playerid, HouseInfo[i][hVirtualWorld]);
		        PlayerEnteredHisHouse[playerid] = true;
          		mysql_free_result();
		        return 1;
			}
	    }
	}
	return 0;
}



/*

 • Function: GetHouseCarID(houseid)
 • Usage: Getting vehicle ID of house car
 • Parameters:
        houseid: ID of house that you want to get vehicle ID
 • Example: format(string, sizeof(string), "Vehicle ID of House ID %d: %d", houseid, GetHouseCar(houseid));

*/

stock GetHouseCarID(houseid) return HouseInfo[houseid][hVehicleID];



/*

 • Function: GetHouseCarPos(houseid)
 • Usage: Getting vehicle pos of house car
 • Parameters:
        houseid: ID of house that you want to get vehicle pos
 • Example: format(string, sizeof(string), "Vehicle pos of House ID %d: %s", houseid, GetHouseCarPos(houseid));

*/

stock GetHouseCarPos(houseid)
{
	new getxyz[128];
	format(getxyz, sizeof(getxyz), "%f, %f, %f", HouseInfo[houseid][hCarX], HouseInfo[houseid][hCarY], HouseInfo[houseid][hCarZ]);
	return getxyz;
}


/*

 • Function: GetHouseCarAngle(houseid)
 • Usage: Getting vehicle angle of house car
 • Parameters:
        houseid: ID of house that you want to get vehicle angle
 • Example: format(string, sizeof(string), "Vehicle angle of House ID %d: %s", houseid, GetHouseCarAngle(houseid));

*/

stock GetHouseCarAngle(houseid)
{
	new geta[128];
	format(geta, sizeof(geta), "%f", HouseInfo[houseid][hCarA]);
	return geta;
}



/*

 • Function: GetHouseCarColor1(houseid)
 • Usage: Getting vehicle color 1 of house car
 • Parameters:
        houseid: ID of house that you want to get vehicle color 1
 • Example: format(string, sizeof(string), "Vehicle color 1 of House ID %d: %d", houseid, GetHouseCarColor1(houseid));

*/

stock GetHouseCarColor1(houseid) return HouseInfo[houseid][hCarColor1];


/*

 • Function: GetHouseCarColor2(houseid)
 • Usage: Getting vehicle color 2 of house car
 • Parameters:
        houseid: ID of house that you want to get vehicle color 2
 • Example: format(string, sizeof(string), "Vehicle color 2 of House ID %d: %d", houseid, GetHouseCarColor2(houseid));

*/

stock GetHouseCarColor2(houseid) return HouseInfo[houseid][hCarColor2];



/*

 • Function: GetHouseCarWeaponID1(houseid)
 • Usage: Getting weapon id 1 of house car
 • Parameters:
        houseid: ID of house that you want to get vehicle weapon id 1
 • Example: format(string, sizeof(string), "Vehicle weapon id 1 of House ID %d: %d", houseid, GetHouseCarWeaponID1(houseid));

*/

stock GetHouseCarWeaponID1(houseid) return HouseInfo[houseid][hCarWeaponID1];



/*

 • Function: GetHouseCarWeaponID2(houseid)
 • Usage: Getting weapon id 2 of house car
 • Parameters:
        houseid: ID of house that you want to get vehicle weapon id 2
 • Example: format(string, sizeof(string), "Vehicle weapon id 2 of House ID %d: %d", houseid, GetHouseCarWeaponID2(houseid));

*/

stock GetHouseCarWeaponID2(houseid) return HouseInfo[houseid][hCarWeaponID2];



/*

 • Function: GetHouseCarWeaponID1Ammo(houseid)
 • Usage: Getting weapon id 1 ammo of house car
 • Parameters:
        houseid: ID of house that you want to get vehicle weapon id 1 ammo
 • Example: format(string, sizeof(string), "Vehicle weapon id 1 ammo of House ID %d: %d", houseid, GetHouseCarWeaponID1Ammo(houseid));

*/

stock GetHouseCarWeaponID1Ammo(houseid) return HouseInfo[houseid][hCarWeaponID1Ammo];



/*

 • Function: GetHouseCarWeaponID2Ammo(houseid)
 • Usage: Getting weapon id 2 ammo of house car
 • Parameters:
        houseid: ID of house that you want to get vehicle weapon id 2 ammo
 • Example: format(string, sizeof(string), "Vehicle weapon id 2 ammo of House ID %d: %d", houseid, GetHouseCarWeaponID2Ammo(houseid));

*/

stock GetHouseCarWeaponID2Ammo(houseid) return HouseInfo[houseid][hCarWeaponID2Ammo];


/*

 • Function: GetHouseCarWeaponID1Name(houseid)
 • Usage: Getting name of weapon id 1 of house car
 • Parameters:
        houseid: ID of house that you want to get vehicle name of weapon id 1
 • Example: format(string, sizeof(string), "Vehicle weapon id 1 name of House ID %d: %s", houseid, GetHouseCarWeaponID1Name(houseid));

*/

stock GetHouseCarWeaponID1Name(houseid)
{
	new weaponid[128], weaponid2[128];
	format(weaponid, sizeof(weaponid), "%s", GetWeapon(HouseInfo[houseid][hCarWeaponID1]));
	format(weaponid2, sizeof(weaponid2), "Nothing");
	if(HouseInfo[houseid][hCarWeaponID1] > 0) return weaponid;
	else return weaponid2;
}



/*

 • Function: GetHouseCarWeaponID2Name(houseid)
 • Usage: Getting name of weapon id 2 of house car
 • Parameters:
        houseid: ID of house that you want to get vehicle name of weapon id 2
 • Example: format(string, sizeof(string), "Vehicle weapon id 2 name of House ID %d: %s", houseid, GetHouseCarWeaponID2Name(houseid));

*/

stock GetHouseCarWeaponID2Name(houseid)
{
	new weaponid[128], weaponid2[128];
	format(weaponid, sizeof(weaponid), "%s", GetWeapon(HouseInfo[houseid][hCarWeaponID2]));
	format(weaponid2, sizeof(weaponid2), "Nothing");
	if(HouseInfo[houseid][hCarWeaponID2] > 0) return weaponid;
	else return weaponid2;
}



/*

 • Function: GetHouseCarMoney(houseid)
 • Usage: Getting money of house car
 • Parameters:
        houseid: ID of house that you want to get vehicle money
 • Example: format(string, sizeof(string), "Vehicle money of House ID %d: %d", houseid, GetHouseCarMoney(houseid));

*/

stock GetHouseCarMoney(houseid) return HouseInfo[houseid][hCarMoney];



/*

 • Function: IsHouseCarLocked(houseid)
 • Usage: Checking if is hosue car locked
 • Parameters:
        houseid: ID of house that you want to check if is house car locked
 • Example: if(IsHouseCarLocked(houseid)) SendClientMessae(playerid, -1, "House car is locked!");
            else SendClientMessage(playerid, -1, "House car is not locked!");

*/

stock IsHouseCarLocked(houseid)
{
	if(HouseInfo[houseid][hCarLocked] == 1) return 1;
	else return 0;
}

//----Stocks for easier scripting!----
/*stock GetName(playerid)
{
	new pName[MAX_PLAYER_NAME];
	GetPlayerName(playerid, pName, MAX_PLAYER_NAME);
	return pName;
}

stock GetWeapon(weaponid)
{
    new gunname[32];
    GetWeaponName(weaponid, gunname, sizeof(gunname));
    return gunname;
}*/

stock Custom_GetPlayerWeapon(playerid)
{
	for(new w = 0; w < 13; w++)
	{
		GetPlayerWeaponData(playerid, w, House_Weapon[playerid][w], House_Ammo[playerid][w]);
	}
	return 1;
}

stock Custom_GetSlot(weaponid)
{
	new slot;
	if(weaponid == 0 || weaponid == 1){slot = 0;}
	else if(weaponid > 8 && weaponid < 10){slot = 1;}
	else if(weaponid > 9 && weaponid < 16){slot = 10;}
	else if(weaponid > 15 && weaponid < 20){slot = 8;}
	else if(weaponid > 21 && weaponid < 25){slot = 2;}
	else if(weaponid > 24 && weaponid < 28){slot = 3;}
	else if(weaponid == 28 || weaponid == 29 || weaponid == 32){slot = 4;}
	else if(weaponid == 30 || weaponid == 31){slot = 5;}
	else if(weaponid == 33 || weaponid == 34){slot = 6;}
	else if(weaponid > 34 || weaponid < 39){slot = 7;}
	return slot;
}

stock IsPlayerNearPlayer(playerid, playerid2, Float: radius)
{
    new Float: pPos[4];
    GetPlayerPos(playerid2, pPos[0], pPos[1], pPos[2]);
    if(IsPlayerInRangeOfPoint(playerid, radius, pPos[0], pPos[1], pPos[2])) return 1;
    return 0;
}
//----End of stocks!----


//*****************************          *****************************
//***************************** COMMANDS *****************************
//*****************************          *****************************




/*

 • Command: /buyhouse
 • Processor: y_commands (YCMD)
 • Usage: Buying house (Player must be in range of house he want to buy!)

*/

YCMD:buyhouse(playerid, params[], help) 
{
	#pragma unused help
	#pragma unused params
    foreach(Houses, i)
    {
        if(IsPlayerInRangeOfPoint(playerid, 3.0, HouseInfo[i][hEnterX], HouseInfo[i][hEnterY], HouseInfo[i][hEnterZ]))
        {
            if(HouseInfo[i][hOwned] == 1) return SendClientMessage(playerid, COLOR_KRED, "House is already owned!");
            if(GetPlayerMoney(playerid) < HouseInfo[i][hPrice]) return SendClientMessage(playerid, COLOR_KRED, "You don't have enough money!");
			
			new HQuery2[200];
			format(HQuery2, sizeof(HQuery2), "SELECT User FROM `house` WHERE `User` = '%s'", GetName(playerid));
			mysql_query(HQuery2);
			mysql_store_result();
			if(mysql_num_rows() == 1) return SendClientMessage(playerid, COLOR_KRED, "You have house already!");
			mysql_free_result();

			format(HouseInfo[i][hOwner], 24, "%s", GetName(playerid));
			format(HouseInfo[i][hCarOwner], 24, "%s", GetName(playerid));
			HouseInfo[i][hOwned] = 1;
			DestroyPickup(HouseInfo[i][hPickup]);
			HouseInfo[i][hPickup] = CreatePickup(1239, 23, HouseInfo[i][hEnterX], HouseInfo[i][hEnterY], HouseInfo[i][hEnterZ], 0);
			format(hstring, sizeof(hstring), "Owner: %s\nHouse ID: %d\nRent User: %s\nRent Price: %d", HouseInfo[i][hOwner], i, HouseInfo[i][hRentUser], HouseInfo[i][hRentPrice]);
			Update3DTextLabelText(HouseInfo[i][hLabel], 0x21DD00FF, hstring);
			GivePlayerMoney(playerid, -HouseInfo[i][hPrice]);
			SendClientMessage(playerid, COLOR_LIME, "House bought!");
			
 			format(HQuery, sizeof(HQuery), "UPDATE `house` SET `User` = '%s', `Car Owner` = '%s', `Owned` = 1 WHERE `HouseID` = %d", GetName(playerid), GetName(playerid), i);
			mysql_query(HQuery);
		}
	}
	return 1;
}

/*

 • Command: /sellhouse
 • Processor: y_commands (YCMD)
 • Usage: Selling house (Player must be in range of house he want to sell!)

*/

YCMD:sellhouse(playerid, params[], help)
{
	#pragma unused help
	#pragma unused params
	foreach(Houses, i)
	{
	    if(IsPlayerInRangeOfPoint(playerid, 3.0, HouseInfo[i][hEnterX], HouseInfo[i][hEnterY], HouseInfo[i][hEnterZ]))
        {
         	if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false)) 
	        {
                format(HouseInfo[i][hOwner], 24, "None");
                format(HouseInfo[i][hRentUser], 24, "None");
                format(HouseInfo[i][hCarOwner], 24, "None");
				HouseInfo[i][hOwned] = 0;
				HouseInfo[i][hLocked] = 0;
				HouseInfo[i][hRented] = 0;
		 		DestroyPickup(HouseInfo[i][hPickup]);
				HouseInfo[i][hPickup] = CreatePickup(1273, 23, HouseInfo[i][hEnterX], HouseInfo[i][hEnterY], HouseInfo[i][hEnterZ], 0);
				format(hstring, sizeof(hstring), "For sale!\nPrice: %d\nHouse ID: %d\nType /buyhouse to buy house!", HouseInfo[i][hPrice], i);
				Update3DTextLabelText(HouseInfo[i][hLabel], 0x21DD00FF, hstring);
				GivePlayerMoney(playerid, HouseInfo[i][hPrice]);
				SendClientMessage(playerid, COLOR_LIME, "House sold!");

				format(HQuery, sizeof(HQuery), "UPDATE `house` SET `User` = 'None', `Owned` = 0, `Locked` = 0, `Rent User` = 'None', `Rented` = 0 WHERE `HouseID` = %d", i);
				mysql_query(HQuery);
			}
		}
	}
	return 1;
}

/*

 • Command: /sellhouseto
 • Processor: y_commands (YCMD)
 • Usage: Selling house to other player (must be near you!)
 • Parameters:
        id: The id of player you want to sell house

*/

YCMD:sellhouseto(playerid, params[], help)
{
	#pragma unused help
	#pragma unused params
	new id, selltostring[128];
	foreach(Houses, i)
	{
	    if(IsPlayerInRangeOfPoint(playerid, 3.0, HouseInfo[i][hEnterX], HouseInfo[i][hEnterY], HouseInfo[i][hEnterZ]))
        {
         	if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false))
	        {
	            if(sscanf(params, "i", id)) return SendClientMessage(playerid, -1, "Usage: /sellhouseto [ID]");
	            else if(id == INVALID_PLAYER_ID) return SendClientMessage(playerid, -1, "Invalid ID");
	            else if(id == playerid) return SendClientMessage(playerid, -1, "You can't sell house to yourself!");
				if(!IsPlayerNearPlayer(playerid, id, 7.0)) return SendClientMessage(playerid, -1, "Player is not near you!");
				format(selltostring, sizeof(selltostring), "Do you want to buy house from player %s for %d$?", GetName(playerid), HouseInfo[i][hPrice]);
				ShowPlayerDialog(id, 5688, DIALOG_STYLE_MSGBOX, "  Buy house", selltostring, "Yes", "No");
				SetPVarInt(id, "Seller", playerid);
			}
		}
	}
	return 1;
}

/*

 • Command: /lockhouse
 • Processor: y_commands (YCMD)
 • Usage: Locking house (Player must be in range of his house to lock it!)

*/

YCMD:lockhouse(playerid, params[], help)
{
	#pragma unused help
	#pragma unused params
	foreach(Houses, i)
	{
	    if(IsPlayerInRangeOfPoint(playerid, 3.0, HouseInfo[i][hEnterX], HouseInfo[i][hEnterY], HouseInfo[i][hEnterZ]) || IsPlayerInRangeOfPoint(playerid, 3.0, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]))
        {
		    if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false) || !strcmp(HouseInfo[i][hRentUser], GetName(playerid), false)) 
		    {
				HouseInfo[i][hLocked] = 1;
			 	GameTextForPlayer(playerid, "House ~r~locked!", 2000, 5);

				format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Locked` = 1 WHERE `HouseID` = %d", i);
				mysql_query(HQuery);
			}
		}
	}
	return 1;
}

/*

 • Command: /unlockhouse
 • Processor: y_commands (YCMD)
 • Usage: Unlocking house (Player must be in range of his house to unlock it!)

*/

YCMD:unlockhouse(playerid, params[], help) 
{
	#pragma unused help
	#pragma unused params
	foreach(Houses, i)
	{
	    if(IsPlayerInRangeOfPoint(playerid, 3.0, HouseInfo[i][hEnterX], HouseInfo[i][hEnterY], HouseInfo[i][hEnterZ]) || IsPlayerInRangeOfPoint(playerid, 3.0, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]))
        {
		    if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false) || !strcmp(HouseInfo[i][hRentUser], GetName(playerid), false)) 
		    {
				HouseInfo[i][hLocked] = 0;
			 	GameTextForPlayer(playerid, "House ~g~unlocked!", 2000, 5);

				format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Locked` = 0 WHERE `HouseID` = %d", i);
				mysql_query(HQuery);
			}
		}
	}
	return 1;
}

/*

 • Command: /rentroom
 • Processor: y_commands (YCMD)
 • Usage: Renting room (house) (Player must be in range of house that he want to rent it!)

*/

YCMD:rentroom(playerid, params[], help) 
{
	#pragma unused help
	#pragma unused params
    foreach(Houses, i)
    {
        if(IsPlayerInRangeOfPoint(playerid, 3.0, HouseInfo[i][hEnterX], HouseInfo[i][hEnterY], HouseInfo[i][hEnterZ]))
        {
            if(HouseInfo[i][hOwned] == 1)
            {

				new HQuery2[200], HQuery3[200];
				format(HQuery2, sizeof(HQuery2), "SELECT `Rent User` FROM `house` WHERE `Rent User` = '%s'", GetName(playerid));
				mysql_query(HQuery2);
				mysql_store_result();
				if(mysql_num_rows() == 1) return SendClientMessage(playerid, COLOR_KRED, "You have rented house already!");
				mysql_free_result();
				
				format(HQuery3, sizeof(HQuery3), "SELECT User FROM `house` WHERE `User` = '%s'", GetName(playerid));
				mysql_query(HQuery3);
				mysql_store_result();
				if(mysql_num_rows() == 1) return SendClientMessage(playerid, COLOR_KRED, "You have house!");
				mysql_free_result();
			
				if(GetPlayerMoney(playerid) < HouseInfo[i][hRentPrice]) return SendClientMessage(playerid, COLOR_KRED, "You don't have enough money!");
				if(HouseInfo[i][hRented] == 1) return SendClientMessage(playerid, COLOR_KRED, "House is already rented!");
                if(HouseInfo[i][hRentDisabled] == 1) return SendClientMessage(playerid, COLOR_KRED, "Renting this house is disabled!");
				format(HouseInfo[i][hRentUser], 24, "%s", GetName(playerid));
				HouseInfo[i][hRented] = 1;
				GivePlayerMoney(playerid, -HouseInfo[i][hRentPrice]);
				format(hstring, sizeof(hstring), "Owner: %s\nHouse ID: %d\nRent User: %s\nRent Price: %d", HouseInfo[i][hOwner], i, HouseInfo[i][hRentUser], HouseInfo[i][hRentPrice]);
				Update3DTextLabelText(HouseInfo[i][hLabel], 0x21DD00FF, hstring);
 			 	SendClientMessage(playerid, COLOR_YELLOW, "Now you rent this house!");

				format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Rent User` = '%s', `Rented` = 1 WHERE `HouseID` = %d", HouseInfo[i][hRentUser], i);
				mysql_query(HQuery);
            }
            else SendClientMessage(playerid, COLOR_KRED, "That house is not owned! You can buy it but not rent it!");
        }
	}
	return 1;
}

/*

 • Command: /stoprent
 • Processor: y_commands (YCMD)
 • Usage: Stop renting room (house) (Player must be in range of his rented house to stop renting it!)

*/

YCMD:stoprent(playerid, params[], help) 
{
	#pragma unused help
	#pragma unused params
    foreach(Houses, i)
    {
        if(IsPlayerInRangeOfPoint(playerid, 3.0, HouseInfo[i][hEnterX], HouseInfo[i][hEnterY], HouseInfo[i][hEnterZ]))
        {
            if(HouseInfo[i][hOwned] == 1)
            {
				if(strcmp(HouseInfo[i][hRentUser], GetName(playerid), false)) return SendClientMessage(playerid, COLOR_KRED, "You don't rent this room!");
				format(HouseInfo[i][hRentUser], 24, "None");
				HouseInfo[i][hRented] = 0;
				format(hstring, sizeof(hstring), "Owner: %s\nHouse ID: %d\nRent User: %s\nRent Price: %d", HouseInfo[i][hOwner], i, HouseInfo[i][hRentUser], HouseInfo[i][hRentPrice]);
				Update3DTextLabelText(HouseInfo[i][hLabel], 0x21DD00FF, hstring);
 			 	SendClientMessage(playerid, COLOR_YELLOW, "You stop renting this house!");

				format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Rent User` = 'None', `Rented` = 0 WHERE `HouseID` = %d", i);
				mysql_query(HQuery);
            }
            else SendClientMessage(playerid, COLOR_KRED, "That house is not owned!");
        }
	}
	return 1;
}

/*

 • Command: /housecontrol
 • Processor: y_commands (YCMD)
 • Usage: Controling your house: lock house, unlock house, set rent price, storing weapons in house, taking weapons from house, storing money in house, taking money from house & kicking rented user from house (Player must be in his house to control it!)

*/

YCMD:housecontrol(playerid, params[], help) 
{
	#pragma unused help
	#pragma unused params
    foreach(Houses, i)
	{
        if(IsPlayerInRangeOfPoint(playerid, 20.0, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]))
        {
			if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false) && PlayerEnteredHisHouse[playerid] == true)
			{
				ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");
			}
			else SendClientMessage(playerid, COLOR_KRED, "You must enter your house!");
		}
	}
	return 1;
}

/*

 • Command: /houseinfo
 • Processor: y_commands (YCMD)
 • Usage: Getting stats of your house, is locked, unlocked blabalba

*/

YCMD:housestats(playerid, params[], help)
{
	#pragma unused help
	#pragma unused params
    foreach(Houses, i)
	{
		format(HQuery, sizeof(HQuery), "SELECT HouseID FROM `house` WHERE `HouseID` = '%d'", i);
		mysql_query(HQuery);
		mysql_store_result();
		if(mysql_num_rows() == 1)
		{
		    if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false))
			{
    		    new gunstring1[128], gunstring2[128], gunstring3[128];
				if(HouseInfo[i][hWeaponID1] == 0) format(gunstring1, sizeof(gunstring1), "{FFFFFF}Weapon: {F81414}Nothing");
				else format(gunstring1, sizeof(gunstring1), "{FFFFFF}Weapon: {F81414}%s {FFFFFF}| Ammo: {F81414}%d", GetWeapon(HouseInfo[i][hWeaponID1]), HouseInfo[i][hWeaponID1Ammo]);

				if(HouseInfo[i][hWeaponID2] == 0) format(gunstring2, sizeof(gunstring1), "{FFFFFF}Weapon: {F81414}Nothing");
				else format(gunstring2, sizeof(gunstring2), "{FFFFFF}Weapon: {F81414}%s {FFFFFF}| Ammo: {F81414}%d", GetWeapon(HouseInfo[i][hWeaponID2]), HouseInfo[i][hWeaponID2Ammo]);

				if(HouseInfo[i][hWeaponID3] == 0) format(gunstring3, sizeof(gunstring1), "{FFFFFF}Weapon: {F81414}Nothing");
				else format(gunstring3, sizeof(gunstring3), "{FFFFFF}Weapon: {F81414}%s {FFFFFF}| Ammo: {F81414}%d", GetWeapon(HouseInfo[i][hWeaponID3]), HouseInfo[i][hWeaponID3Ammo]);
				
	    		format(hstring, 256, "{FFFFFF}Money: {F81414}%d\n{FFFFFF}Rent User: {F81414}%s\n{FFFFFF}Price: {F81414}%d\n{FFFFFF}Rent Price: {F81414}%d\n%s\n%s\n%s", HouseInfo[i][hMoney], HouseInfo[i][hRentUser], HouseInfo[i][hPrice], HouseInfo[i][hRentPrice], gunstring1, gunstring2, gunstring3);
				ShowPlayerDialog(playerid, 500, DIALOG_STYLE_MSGBOX, "   House information!", hstring, "Ok", "");
			}
		}
		mysql_free_result();
	}
	return 1;
}

/*

 • Command: /breaklock
 • Processor: y_commands (YCMD)
 • Usage: Breaking lock of house

*/

YCMD:breaklock(playerid, params[], help)
{
	#pragma unused help
	#pragma unused params
    foreach(Houses, i)
	{
        if(IsPlayerInRangeOfPoint(playerid, 3.0, HouseInfo[i][hEnterX], HouseInfo[i][hEnterY], HouseInfo[i][hEnterZ]))
        {
            if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false) || !strcmp(HouseInfo[i][hRentUser], GetName(playerid), false)) return SendClientMessage(playerid, COLOR_KRED, "You can't break lock of your house!");
            if(HouseInfo[i][hOwned] == 0) return SendClientMessage(playerid, COLOR_KRED, "That house is not owned!");
            if(HouseInfo[i][hLocked] == 0) return SendClientMessage(playerid, COLOR_KRED, "That house is not locked!");
			SendClientMessage(playerid, COLOR_LIME, "Breaking house lock...");
			TogglePlayerControllable(playerid, 0);
			HouseLockBreaking[playerid] = SetTimerEx("BreakingLock", 5000, 0, "d", playerid);
		}
	}
	return 1;
}

/*

 • Command: /robhouse
 • Processor: y_commands (YCMD)
 • Usage: Controling your house: lock house, unlock house, set rent price, storing weapons in house, taking weapons from house, storing money in house, taking money from house & kicking rented user from house (Player must be in his house to control it!)

*/

YCMD:robhouse(playerid, params[], help)
{
	#pragma unused help
	#pragma unused params
    foreach(Houses, i)
	{
        if(IsPlayerInRangeOfPoint(playerid, 20.0, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]))
        {
			if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false) && PlayerEnteredHisHouse[playerid] == true) return SendClientMessage(playerid, COLOR_KRED, "You can't rob your house!");
			if(HouseInfo[i][hOwned] == 0) return SendClientMessage(playerid, COLOR_KRED, "That house is not owned!");
			if(PlayerCanRobHouse[playerid] == false) return SendClientMessage(playerid, COLOR_KRED, "You can rob next house for 1 hour!");
			SendClientMessage(playerid, COLOR_LIME, "Searching for money in the house...");
			TogglePlayerControllable(playerid, 0);
			HouseRobbing[playerid] = SetTimerEx("RobbingHouse", 15000, 0, "d", playerid);
		}
	}
	return 1;
}

/*

 • Command: /createhouse (RCON Admins only)
 • Processor: y_commands (YCMD)
 • Usage: Creating house at your position

*/

YCMD:createhouse(playerid, params[], help)
{
	#pragma unused help
	#pragma unused params
	if(IsPlayerAdmin(playerid))
	{
	    GetPlayerPos(playerid, PPos[0], PPos[1], PPos[2]);
	    CurrentHouseInfo[CurrentHouseID][hcLabel] = Create3DTextLabel("This is house has been just created!", 0x21DD00FF, PPos[0], PPos[1], PPos[2], 40.0, 0);
        CurrentHouseInfo[CurrentHouseID][hcPickup] = CreatePickup(1273, 23, PPos[0], PPos[1], PPos[2], 0);
        SendClientMessage(playerid, COLOR_LIME, "House has been created successfully!");
        ShowPlayerDialog(playerid, 5696, DIALOG_STYLE_LIST, "   Creating the house!", "Change interior\nChange interior position\nChange virtual world\nChange house price\nChange house rent price\nExport to file", "Ok", "Exit");
		CurrentHouseInfo[CurrentHouseID][hcEnterX] = PPos[0];
		CurrentHouseInfo[CurrentHouseID][hcEnterY] = PPos[1];
		CurrentHouseInfo[CurrentHouseID][hcEnterZ] = PPos[2];
		CurrentHouseID++;
	}
	else SendClientMessage(playerid, COLOR_KRED, "Only RCON admin can use this!");
	return 1;
}

/*

 • Command: /createhouse (RCON Admins only)
 • Processor: y_commands (YCMD)
 • Usage: Creating house at your position

*/

YCMD:edithouse(playerid, params[], help)
{
	#pragma unused help
	#pragma unused params
	for(new h = 0; h < MAX_CURRENT_HOUSES; h++)
	{
		if(IsPlayerAdmin(playerid))
		{
			if(IsPlayerInRangeOfPoint(playerid, 3.0, CurrentHouseInfo[h][hcEnterX], CurrentHouseInfo[h][hcEnterY], CurrentHouseInfo[h][hcEnterZ]))
			{
			    ShowPlayerDialog(playerid, 5696, DIALOG_STYLE_LIST, "   Creating the house!", "Change interior\nChange interior position\nChange virtual world\nChange house price\nChange house rent price\nExport to file", "Ok", "Exit");
			}
		}
		else SendClientMessage(playerid, COLOR_KRED, "Only RCON admin can use this!");
	}
	return 1;
}

/*

 • Command: /asellhouse (RCON Admins only)
 • Processor: y_commands (YCMD)
 • Usage: Selling specific house
 • Parameters:
        houseid: you don't need to be in range of house, just type ID of house that you want to sell!

*/

YCMD:asellhouse(playerid, params[], help) 
{
	#pragma unused help
	new houseid;
	if(IsPlayerAdmin(playerid))
	{
	    if(sscanf(params, "i", houseid)) return SendClientMessage(playerid, -1, "Usage: /asellhouse [House ID]");
		else if(houseid <= -1) return SendClientMessage(playerid, -1, "Invalid ID");
		else if(HouseInfo[houseid][hOwned] == 0) return SendClientMessage(playerid, -1, "That house is not owned!");
		else
        format(HouseInfo[houseid][hOwner], 24, "None");
        format(HouseInfo[houseid][hRentUser], 24, "None");
		HouseInfo[houseid][hOwned] = 0;
		HouseInfo[houseid][hLocked] = 0;
		HouseInfo[houseid][hRented] = 0;
 		DestroyPickup(HouseInfo[houseid][hPickup]);
		HouseInfo[houseid][hPickup] = CreatePickup(1273, 23, HouseInfo[houseid][hEnterX], HouseInfo[houseid][hEnterY], HouseInfo[houseid][hEnterZ], 0);
		format(hstring, sizeof(hstring), "For sale!\nPrice: %d\nHouse ID: %d\nType /buyhouse to buy house!", HouseInfo[houseid][hPrice], houseid);
		Update3DTextLabelText(HouseInfo[houseid][hLabel], 0x21DD00FF, hstring);
		SendClientMessage(playerid, COLOR_LIME, "House sold!");

		format(HQuery, sizeof(HQuery), "UPDATE `house` SET `User` = 'None', `Owned` = 0, `Locked` = 0, `Rent User` = 'None', `Rented` = 0 WHERE `HouseID` = %d", houseid);
		mysql_query(HQuery);
		
	}
	else SendClientMessage(playerid, COLOR_KRED, "Only RCON admin can use this!");
	return 1;
}

/*

 • Command: /asetprice (RCON Admins only)
 • Processor: y_commands (YCMD)
 • Usage: Setting price of specific house
 • Parameters:
        houseid: you don't need to be in range of house, just type ID of house that you want to sell!
        price: price that you want to set

*/

YCMD:asetprice(playerid, params[], help)
{
	#pragma unused help
	new houseid, price, pricestring[128];
	if(IsPlayerAdmin(playerid))
	{
	    if(sscanf(params, "ii", houseid, price)) return SendClientMessage(playerid, -1, "Usage: /asetprice [House ID][Price]");
		else if(houseid <= -1) return SendClientMessage(playerid, -1, "Invalid ID");
		else if(HouseInfo[houseid][hOwned] == 1) return SendClientMessage(playerid, -1, "That house is owned!");
		else
		HouseInfo[houseid][hPrice] = price;
		format(hstring, sizeof(hstring), "For sale!\nPrice: %d\nHouse ID: %d\nType /buyhouse to buy house!", HouseInfo[houseid][hPrice], houseid);
		Update3DTextLabelText(HouseInfo[houseid][hLabel], 0x21DD00FF, hstring);
		format(pricestring, sizeof(pricestring), "House price set on %d!", price);
		SendClientMessage(playerid, COLOR_LIME, pricestring);

		format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Price` = %d WHERE `HouseID` = %d", price, houseid);
		mysql_query(HQuery);

	}
	else SendClientMessage(playerid, COLOR_KRED, "Only RCON admin can use this!");
	return 1;
}

/*

 • Command: /agotohouse (RCON Admins only)
 • Processor: y_commands (YCMD)
 • Usage: Teleporting to a specific house
 • Parameters:
        houseid: you don't need to be in range of house, just type ID of house that you want to go!

*/

YCMD:agotohouse(playerid, params[], help)
{
	#pragma unused help
	new houseid;
	if(IsPlayerAdmin(playerid))
	{
	    if(sscanf(params, "i", houseid)) return SendClientMessage(playerid, -1, "Usage: /agotohouse [House ID]");
		else if(houseid <= -1) return SendClientMessage(playerid, -1, "Invalid ID");
		new HQuery2[200];
		format(HQuery2, sizeof(HQuery2), "SELECT HouseID FROM `house` WHERE `HouseID` = '%d'", houseid);
		mysql_query(HQuery2);
		mysql_store_result();
		if(mysql_num_rows() == 0) return SendClientMessage(playerid, COLOR_KRED, "House doesn't exist!");
		mysql_free_result();
			
		SetPlayerPos(playerid, HouseInfo[houseid][hEnterX], HouseInfo[houseid][hEnterY], HouseInfo[houseid][hEnterZ]);
		SendClientMessage(playerid, COLOR_LIME, "You have been teleported to the house!");
	}
	else SendClientMessage(playerid, COLOR_KRED, "Only RCON admin can use this!");
	return 1;
}

/*

 • Command: /lockhousecar
 • Processor: y_commands (YCMD)
 • Usage: Locking your house car

*/

YCMD:lockhousecar(playerid, params[], help)
{
	#pragma unused help
	#pragma unused params
    foreach(Houses, i)
	{
		new HQuery2[200];
		format(HQuery2, sizeof(HQuery2), "SELECT HouseID FROM `house` WHERE `HouseID` = '%d'", i);
		mysql_query(HQuery2);
		mysql_store_result();
		if(!strcmp(HouseInfo[i][hCarOwner], GetName(playerid), false))
		{
			HouseInfo[i][hCarLocked] = 1;
		 	GameTextForPlayer(playerid, "House car ~r~locked!", 2000, 5);

			format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Car Locked` = 1 WHERE `HouseID` = %d", i);
			mysql_query(HQuery);
		}
		mysql_free_result();
	}
	return 1;
}

/*

 • Command: /unlockhousecar
 • Processor: y_commands (YCMD)
 • Usage: Unlocking your house car

*/

YCMD:unlockhousecar(playerid, params[], help)
{
	#pragma unused help
	#pragma unused params
    foreach(Houses, i)
	{
		new HQuery2[200];
		format(HQuery2, sizeof(HQuery2), "SELECT HouseID FROM `house` WHERE `HouseID` = '%d'", i);
		mysql_query(HQuery2);
		mysql_store_result();
		if(!strcmp(HouseInfo[i][hCarOwner], GetName(playerid), false))
		{
			HouseInfo[i][hCarLocked] = 0;
		 	GameTextForPlayer(playerid, "House car ~g~unlocked!", 2000, 5);

			format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Car Locked` = 0 WHERE `HouseID` = %d", i);
			mysql_query(HQuery);
		}
		mysql_free_result();
	}
	return 1;
}

/*

 • Command: /housecarcontrol
 • Processor: y_commands (YCMD)
 • Usage: Controling your house car: lock house car, unlock house car, storing weapons in house car, taking weapons from house car, storing money in house car, taking money from house car (Player must be in his house car to control it!)

*/

YCMD:housecarcontrol(playerid, params[], help)
{
	#pragma unused help
	#pragma unused params
    foreach(Houses, i)
	{
 		new HQuery2[200];
		format(HQuery2, sizeof(HQuery2), "SELECT HouseID FROM `house` WHERE `HouseID` = '%d'", i);
		mysql_query(HQuery2);
		mysql_store_result();
		if(mysql_num_rows() == 1)
		{
			if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false))
			{
				if(PlayerEnteredHisHouseCar[playerid] == true)
				{
					ShowPlayerDialog(playerid, 5689, DIALOG_STYLE_LIST, "   Control your house car!", "Lock house car\nUnlock house car\nStore weapon\nTake weapon\nStore money\nTake money", "Ok", "Exit");
				}
				else SendClientMessage(playerid, COLOR_KRED, "You must enter your house car!");
			}
		}
		mysql_free_result();
	}
	return 1;
}

public RentFeeUp()
{
    foreach(Player, p)
	{
	    if(!IsPlayerConnected(p)) continue;
	    foreach(Houses, i)
		{
		 	new HQuery2[200];
			format(HQuery2, sizeof(HQuery2), "SELECT HouseID FROM `house` WHERE `HouseID` = '%d'", i);
			mysql_query(HQuery2);
			mysql_store_result();
			if(mysql_num_rows() == 1)
			{
			    if(!strcmp(HouseInfo[i][hRentUser], GetName(p), false))
				{
				    GivePlayerMoney(p, -HouseInfo[i][hRentPrice]);
				    HouseInfo[i][hMoney] += HouseInfo[i][hRentPrice];
				    format(hstring, sizeof(hstring), "Rent fee: %d", HouseInfo[i][hRentPrice]);
				    printf("Rent fee: %d", HouseInfo[i][hRentPrice]);
				    SendClientMessage(p, COLOR_LIME, hstring);
				    mysql_free_result();

		           	format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Money` = %d WHERE `HouseID` = %d", HouseInfo[i][hMoney], i);
					mysql_query(HQuery);
	   			}
			}
		}
	}
	return 1;
}

public BreakingLock(playerid)
{
    foreach(Houses, i)
	{
        if(IsPlayerInRangeOfPoint(playerid, 3.0, HouseInfo[i][hEnterX], HouseInfo[i][hEnterY], HouseInfo[i][hEnterZ]))
        {
            if(HouseInfo[i][hAlarm] == 0)
            {
			    new breaking = random(4);
			    switch(breaking)
			    {
					case 0,1,2:
					{
						TogglePlayerControllable(playerid, 1);
						KillTimer(HouseLockBreaking[playerid]);
						SendClientMessage(playerid, COLOR_YELLOW, "Breaking unsuccessfully!");
					}
					case 3:
					{
						HouseInfo[i][hLocked] = 0;
						TogglePlayerControllable(playerid, 1);
						KillTimer(HouseLockBreaking[playerid]);
						SendClientMessage(playerid, COLOR_YELLOW, "Breaking successfully!");

						format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Locked` = 0 WHERE `HouseID` = %d", i);
						mysql_query(HQuery);
					}
			    }
			}
			else
			{
			    new breaking = random(5);
			    switch(breaking)
			    {
					case 0,1,2,3:
					{
						TogglePlayerControllable(playerid, 1);
						KillTimer(HouseLockBreaking[playerid]);
						SendClientMessage(playerid, COLOR_YELLOW, "Breaking unsuccessfully!");
					}
					case 4:
					{
						HouseInfo[i][hLocked] = 0;
						TogglePlayerControllable(playerid, 1);
						KillTimer(HouseLockBreaking[playerid]);
						SendClientMessage(playerid, COLOR_YELLOW, "Breaking successfully!");

						format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Locked` = 0 WHERE `HouseID` = %d", i);
						mysql_query(HQuery);
					}
			    }
			}
		}
	}
	return 1;
}

public RobbingHouse(playerid)
{
	foreach(Houses, i)
	{
        if(IsPlayerInRangeOfPoint(playerid, 20.0, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]))
        {
            if(HouseInfo[i][hMoney] == 0) return SendClientMessage(playerid, COLOR_YELLOW, "There is no money in the house");
			new robmoney = random(HouseInfo[i][hMoney]);
			GivePlayerMoney(playerid, robmoney);
			HouseInfo[i][hMoney] -= robmoney;
			format(hstring, sizeof(hstring), "House robbed successfully! Robbed money: %d", robmoney);
			SendClientMessage(playerid, COLOR_YELLOW, hstring);
			PlayerCanRobHouse[playerid] = false;
			CanRobHouseTimer[playerid] = SetTimerEx("CanRobHouse", 3600000, 0, "d", playerid);
			TogglePlayerControllable(playerid, 1);
			
			format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Money` = %d WHERE `HouseID` = %d", HouseInfo[i][hMoney], i);
			mysql_query(HQuery);
		}
	}
	return 1;
}

public CanRobHouse(playerid)
{
    PlayerCanRobHouse[playerid] = true;
	return 1;
}

//*****************************           *****************************
//***************************** CALLBACKS *****************************
//*****************************           *****************************




/*

 • Callback: OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])  (Hooked using y_hook)
 • Action: Dialogs for house controling, later will be more for dynamic creating house!

*/

Hook:H1_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
	    case 5678: //Dialog for house controling
	    {
	        if(!response) return 0;
	        switch(listitem)
	        {
	            case 0: //locking house
	            {
	                foreach(Houses, i)
        			{
			            if(IsPlayerInRangeOfPoint(playerid, 20.0, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]))
			            {
		         		    if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false))
				    		{
								HouseInfo[i][hLocked] = 1;
							 	GameTextForPlayer(playerid, "House ~r~locked!", 2000, 5);
							 	ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");

								format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Locked` = 1 WHERE `HouseID` = %d", i);
								mysql_query(HQuery);
							}
						}
					}
	            }
     	        case 1: //unlocking house
	            {
	                foreach(Houses, i)
        			{
			            if(IsPlayerInRangeOfPoint(playerid, 20.0, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]))
			            {
		         		    if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false))
				    		{
								HouseInfo[i][hLocked] = 0;
							 	GameTextForPlayer(playerid, "House ~g~unlocked!", 2000, 5);
							 	ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");

								format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Locked` = 0 WHERE `HouseID` = %d", i);
								mysql_query(HQuery);
							}
						}
					}
	            }
	            case 2: //setting rent fee
	            {
     	            if(!response) return ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");
	            	foreach(Houses, i)
        			{
			            if(IsPlayerInRangeOfPoint(playerid, 20.0, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]))
			            {
			            	if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false))
							{
							    format(hstring, sizeof(hstring), "Current rent price: %d\nType ammount of price that you want to set for renting\n0 for disabling rent!", HouseInfo[i][hRentPrice]);
							    ShowPlayerDialog(playerid, 5686, DIALOG_STYLE_INPUT, "   Rent price", hstring, "Ok", "Back");
							}
						}
					}
	            }
	            case 3: //storing a gun
	            {
	                if(!response) return ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");
	            	foreach(Houses, i)
        			{
			            if(IsPlayerInRangeOfPoint(playerid, 20.0, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]))
			            {
			            	if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false))
							{
				    		    new gunstring[128], gunstring1[128], gunstring2[128], gunstring3[128];
								if(HouseInfo[i][hWeaponID1] == 0) format(gunstring1, sizeof(gunstring1), "Nothing");
								else format(gunstring1, sizeof(gunstring1), "Weapon: %s | Ammo: %d", GetWeapon(HouseInfo[i][hWeaponID1]), HouseInfo[i][hWeaponID1Ammo]);
								
								if(HouseInfo[i][hWeaponID2] == 0) format(gunstring2, sizeof(gunstring1), "Nothing");
								else format(gunstring2, sizeof(gunstring2), "Weapon: %s | Ammo: %d", GetWeapon(HouseInfo[i][hWeaponID2]), HouseInfo[i][hWeaponID2Ammo]);
								
								if(HouseInfo[i][hWeaponID3] == 0) format(gunstring3, sizeof(gunstring1), "Nothing");
								else format(gunstring3, sizeof(gunstring3), "Weapon: %s | Ammo: %d", GetWeapon(HouseInfo[i][hWeaponID3]), HouseInfo[i][hWeaponID3Ammo]);
								
								format(gunstring, sizeof(gunstring), "%s\n%s\n%s", gunstring1, gunstring2, gunstring3);
								ShowPlayerDialog(playerid, 5679, DIALOG_STYLE_LIST, "  Stored guns", gunstring, "Ok", "Back");
							}
						}
					}
	            }
	            case 4: //taking a gun
	            {
	                if(!response) return ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");
            		foreach(Houses, i)
        			{
			            if(IsPlayerInRangeOfPoint(playerid, 20.0, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]))
			            {
			            	if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false))
							{
				    		    new gunstring[128], gunstring1[128], gunstring2[128], gunstring3[128];
								if(HouseInfo[i][hWeaponID1] == 0) format(gunstring1, sizeof(gunstring1), "Nothing");
								else format(gunstring1, sizeof(gunstring1), "Weapon: %s | Ammo: %d", GetWeapon(HouseInfo[i][hWeaponID1]), HouseInfo[i][hWeaponID1Ammo]);

								if(HouseInfo[i][hWeaponID2] == 0) format(gunstring2, sizeof(gunstring1), "Nothing");
								else format(gunstring2, sizeof(gunstring2), "Weapon: %s | Ammo: %d", GetWeapon(HouseInfo[i][hWeaponID2]), HouseInfo[i][hWeaponID2Ammo]);

								if(HouseInfo[i][hWeaponID3] == 0) format(gunstring3, sizeof(gunstring1), "Nothing");
								else format(gunstring3, sizeof(gunstring3), "Weapon: %s | Ammo: %d", GetWeapon(HouseInfo[i][hWeaponID3]), HouseInfo[i][hWeaponID3Ammo]);

								format(gunstring, sizeof(gunstring), "%s\n%s\n%s", gunstring1, gunstring2, gunstring3);
								ShowPlayerDialog(playerid, 5683, DIALOG_STYLE_LIST, "  Stored guns", gunstring, "Ok", "Back");
							}
						}
					}
				}
				case 5: //storing money
				{
	                if(!response) return ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");
            		foreach(Houses, i)
        			{
			            if(IsPlayerInRangeOfPoint(playerid, 20.0, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]))
			            {
			            	if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false))
							{
							    new moneystring[128];
							    format(moneystring, sizeof(moneystring), "Current stored money: %d\n\nType ammount of money that you want to store", HouseInfo[i][hMoney]);
							    ShowPlayerDialog(playerid, 5684, DIALOG_STYLE_INPUT, "   Stored money", moneystring, "Ok", "Back");
							}
						}
					}
				}
				case 6: //taking money
				{
	                if(!response) return ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");
            		foreach(Houses, i)
        			{
			            if(IsPlayerInRangeOfPoint(playerid, 20.0, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]))
			            {
			            	if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false))
							{
							    new moneystring[128];
							    format(moneystring, sizeof(moneystring), "Current stored money: %d\n\nType ammount of money that you want to take", HouseInfo[i][hMoney]);
							    ShowPlayerDialog(playerid, 5685, DIALOG_STYLE_INPUT, "   Stored money", moneystring, "Ok", "Back");
							}
						}
					}
				}
				case 7: //kicking rent user
				{
	                if(!response) return ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");
            		foreach(Houses, i)
        			{
			            if(IsPlayerInRangeOfPoint(playerid, 20.0, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]))
			            {
			            	if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false))
							{
							    if(HouseInfo[i][hRented] == 0)
								{
									SendClientMessage(playerid, COLOR_KRED, "No one doesn't rent this house!");
									ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");
									return 1;
								}
							    new moneystring[128];
							    format(moneystring, sizeof(moneystring), "Current rent user: %s\n\nDo you want to kick him?", HouseInfo[i][hRentUser]);
							    ShowPlayerDialog(playerid, 5687, DIALOG_STYLE_MSGBOX, "   Kick rent user", moneystring, "Yes", "No");
							}
						}
					}
				}
				case 8: //buying an alarm
				{
			        if(!response) return ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");
            		foreach(Houses, i)
        			{
			            if(IsPlayerInRangeOfPoint(playerid, 20.0, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]))
			            {
			            	if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false))
							{
							    if(HouseInfo[i][hAlarm] == 1)
								{
									SendClientMessage(playerid, COLOR_KRED, "House already have an alarm!");
									ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");
									return 1;
								}
								if(GetPlayerMoney(playerid) < 2000)
								{
       								SendClientMessage(playerid, COLOR_KRED, "You don't have enough money!");
									ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");
									return 1;
								}
								HouseInfo[i][hAlarm] = 1;
								GivePlayerMoney(playerid, -2000);
								SendClientMessage(playerid, COLOR_YELLOW, "You buyed an alarm for your house!");
								ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");
								
								format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Alarm` = 1 WHERE `HouseID` = %d", i);
								mysql_query(HQuery);
							}
						}
					}
				}
				case 9: //selling an alarm
				{
					if(!response) return ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");
            		foreach(Houses, i)
        			{
			            if(IsPlayerInRangeOfPoint(playerid, 20.0, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]))
			            {
			            	if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false))
							{
							    if(HouseInfo[i][hAlarm] == 0)
								{
									SendClientMessage(playerid, COLOR_KRED, "House doesn't have an alarm!");
									ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");
									return 1;
								}
								HouseInfo[i][hAlarm] = 0;
								GivePlayerMoney(playerid, 2000);
								SendClientMessage(playerid, COLOR_YELLOW, "You sell an alarm of your house!");
								ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");

								format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Alarm` = 0 WHERE `HouseID` = %d", i);
								mysql_query(HQuery);
							}
						}
					}
				}
	        }
	    }
	    case 5679: //dialog with all stored guns
	    {
	        if(!response) return ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");
	        switch(listitem)
	        {
	            case 0: //slot 1
	            {
		            foreach(Houses, i)
					{
			            if(IsPlayerInRangeOfPoint(playerid, 20.0, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]))
			            {
	            	 		if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false))
				    		{
		        				ShowPlayerDialog(playerid, 5680, DIALOG_STYLE_INPUT, "  Gun", "Type a gun ID that you want to store!", "Ok", "Exit");
							}
						}
					}
				}
	            case 1: //slot 2
	            {
		            foreach(Houses, i)
					{
			            if(IsPlayerInRangeOfPoint(playerid, 20.0, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]))
			            {
	            	 		if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false))
				    		{
		        				ShowPlayerDialog(playerid, 5681, DIALOG_STYLE_INPUT, "  Gun", "Type a gun ID that you want to store!", "Ok", "Exit");
							}
						}
					}
				}
	            case 2: //slot 3
	            {
		            foreach(Houses, i)
					{
			            if(IsPlayerInRangeOfPoint(playerid, 20.0, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]))
			            {
	            	 		if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false))
				    		{
		        				ShowPlayerDialog(playerid, 5682, DIALOG_STYLE_INPUT, "  Gun", "Type a gun ID that you want to store!", "Ok", "Exit");
							}
						}
					}
				}
			}
	    }
	    case 5680: //dialog for storing gun in slot 1
	    {
	        if(!response) return ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");
		    foreach(Houses, i)
			{
	            if(IsPlayerInRangeOfPoint(playerid, 20.0, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]))
	            {
        	 		if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false))
		    		{
					    Custom_GetPlayerWeapon(playerid);
	    		        if(House_Weapon[playerid][Custom_GetSlot(strval(inputtext))] == strval(inputtext))
	    		        {
	    		        	if(strval(inputtext) > 0 || strval(inputtext) < 46)
    		    			{
		    		            HouseInfo[i][hWeaponID1] = strval(inputtext);
		    		            HouseInfo[i][hWeaponID1Ammo] = House_Ammo[playerid][Custom_GetSlot(HouseInfo[i][hWeaponID1])];
								format(hstring, sizeof(hstring), "Gun ID %d stored in the slot 1", strval(inputtext));
								SendClientMessage(playerid, COLOR_LIME, hstring);
								ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nKick rent user", "Ok", "Exit\nBuy alarm | $2000\nSell alarm");

                				format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Weapon ID 1` = %d, `Weapon ID 1 Ammo` = %d WHERE `HouseID` = %d", strval(inputtext), HouseInfo[i][hWeaponID1Ammo], i);
								mysql_query(HQuery);
							}
			    		    else
							{
								SendClientMessage(playerid, COLOR_KRED, "Invalid gun ID!");
								ShowPlayerDialog(playerid, 5680, DIALOG_STYLE_INPUT, "  Gun", "Type a gun ID that you want to store!", "Ok", "Exit");
							}
		    			}
	    		        else
						{
							SendClientMessage(playerid, COLOR_KRED, "You don't have that gun!");
							ShowPlayerDialog(playerid, 5680, DIALOG_STYLE_INPUT, "  Gun", "Type a gun ID that you want to store!", "Ok", "Exit");
						}
		    		}
		        }
			}
	    }
	    case 5681: //dialog for storing gun in slot 2
	    {
	        if(!response) return ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");
		    foreach(Houses, i)
			{
	            if(IsPlayerInRangeOfPoint(playerid, 20.0, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]))
	            {
        	 		if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false))
		    		{
					    Custom_GetPlayerWeapon(playerid);
	    		        if(House_Weapon[playerid][Custom_GetSlot(strval(inputtext))] == strval(inputtext))
	    		        {
	    		        	if(strval(inputtext) > 0 || strval(inputtext) < 46)
    		    			{
		    		            HouseInfo[i][hWeaponID2] = strval(inputtext);
		    		            HouseInfo[i][hWeaponID2Ammo] = House_Ammo[playerid][Custom_GetSlot(HouseInfo[i][hWeaponID2])];
		    		            format(hstring, sizeof(hstring), "Gun ID %d stored in the slot 2", strval(inputtext));
		    		            SendClientMessage(playerid, COLOR_LIME, hstring);
								ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");

                				format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Weapon ID 2` = %d, `Weapon ID 2 Ammo` = %d WHERE `HouseID` = %d", strval(inputtext), HouseInfo[i][hWeaponID2Ammo], i);
								mysql_query(HQuery);
							}
			    		    else
							{
								SendClientMessage(playerid, COLOR_KRED, "Invalid gun ID!");
								ShowPlayerDialog(playerid, 5680, DIALOG_STYLE_INPUT, "  Gun", "Type a gun ID that you want to store!", "Ok", "Exit");
							}
		    			}
	    		        else
						{
							SendClientMessage(playerid, COLOR_KRED, "You don't have that gun!");
							ShowPlayerDialog(playerid, 5680, DIALOG_STYLE_INPUT, "  Gun", "Type a gun ID that you want to store!", "Ok", "Exit");
						}
		    		}
		        }
			}
	    }
	    case 5682: //dialog for storing gun in slot 3
	    {
	        if(!response) return ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");
		    foreach(Houses, i)
			{
	            if(IsPlayerInRangeOfPoint(playerid, 20.0, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]))
	            {
        	 		if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false))
		    		{
					    Custom_GetPlayerWeapon(playerid);
	    		        if(House_Weapon[playerid][Custom_GetSlot(strval(inputtext))] == strval(inputtext))
	    		        {
	    		        	if(strval(inputtext) > 0 || strval(inputtext) < 46)
    		    			{
		    		            HouseInfo[i][hWeaponID3] = strval(inputtext);
		    		            HouseInfo[i][hWeaponID3Ammo] = House_Ammo[playerid][Custom_GetSlot(HouseInfo[i][hWeaponID3])];
		    		            format(hstring, sizeof(hstring), "Gun ID %d stored in the slot 3", strval(inputtext));
		    		            SendClientMessage(playerid, COLOR_LIME, hstring);
								ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");

                				format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Weapon ID 3` = %d, `Weapon ID 3 Ammo` = %d WHERE `HouseID` = %d", strval(inputtext), HouseInfo[i][hWeaponID3Ammo], i);
								mysql_query(HQuery);
							}
			    		    else
							{
								SendClientMessage(playerid, COLOR_KRED, "Invalid gun ID!");
								ShowPlayerDialog(playerid, 5680, DIALOG_STYLE_INPUT, "  Gun", "Type a gun ID that you want to store!", "Ok", "Exit");
							}
		    			}
	    		        else
						{
							SendClientMessage(playerid, COLOR_KRED, "You don't have that gun!");
							ShowPlayerDialog(playerid, 5680, DIALOG_STYLE_INPUT, "  Gun", "Type a gun ID that you want to store!", "Ok", "Exit");
						}
		    		}
		        }
			}
	    }
	    case 5683: //dialog for taking gun
	    {
	        if(!response) return ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");
	        switch(listitem)
	        {
	            case 0: //slot 1
	            {
		       		foreach(Houses, i)
					{
			            if(IsPlayerInRangeOfPoint(playerid, 20.0, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]))
			            {
			            	if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false))
							{
							    if(HouseInfo[i][hWeaponID1] > 1) //if slot isn't empty (Emty slot is weapon ID 0 (Hand))
							    {
							        GivePlayerWeapon(playerid, HouseInfo[i][hWeaponID1], HouseInfo[i][hWeaponID1Ammo]);
							        HouseInfo[i][hWeaponID1] = 0;
							        HouseInfo[i][hWeaponID1Ammo] = 0;
							        ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");
							        
           	                		format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Weapon ID 1` = 0, `Weapon ID 1 Ammo` = 0 WHERE `HouseID` = %d", i);
									mysql_query(HQuery);
							    }
							    else
							    {
							        SendClientMessage(playerid, COLOR_KRED, "That slot is empty!");
							    	ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");
							    }
							}
						}
					}
				}
	            case 1: //slot 2
	            {
		       		foreach(Houses, i)
					{
			            if(IsPlayerInRangeOfPoint(playerid, 20.0, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]))
			            {
			            	if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false))
							{
							    if(HouseInfo[i][hWeaponID2] > 1) //if slot isn't empty (Emty slot is weapon ID 0 (Hand))
							    {
							        GivePlayerWeapon(playerid, HouseInfo[i][hWeaponID2], HouseInfo[i][hWeaponID2Ammo]);
							        HouseInfo[i][hWeaponID2] = 0;
							        HouseInfo[i][hWeaponID2Ammo] = 0;
							        ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");

           	                		format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Weapon ID 2` = 0, `Weapon ID 2 Ammo` = 0 WHERE `HouseID` = %d", i);
									mysql_query(HQuery);
							    }
							    else
							    {
							        SendClientMessage(playerid, COLOR_KRED, "That slot is empty!");
							    	ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");
							    }
							}
						}
					}
				}
				case 2: //slot 3
	            {
		       		foreach(Houses, i)
					{
			            if(IsPlayerInRangeOfPoint(playerid, 20.0, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]))
			            {
			            	if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false))
							{
				            	if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false))
								{
								    if(HouseInfo[i][hWeaponID3] > 1) //if slot isn't empty (Emty slot is weapon ID 0 (Hand))
								    {
								        GivePlayerWeapon(playerid, HouseInfo[i][hWeaponID3], HouseInfo[i][hWeaponID3Ammo]);
								        HouseInfo[i][hWeaponID3] = 0;
								        HouseInfo[i][hWeaponID3Ammo] = 0;
								        ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");

	           	                		format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Weapon ID 3` = 0, `Weapon ID 3 Ammo` = 0 WHERE `HouseID` = %d", i);
										mysql_query(HQuery);
								    }
								    else
								    {
								        SendClientMessage(playerid, COLOR_KRED, "That slot is empty!");
								    	ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");
								    }
								}
							}
						}
					}
				}
			}
		}
	    case 5684: //dialog for storing money
		{
		    if(!response) return ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");
       		foreach(Houses, i)
			{
	            if(IsPlayerInRangeOfPoint(playerid, 20.0, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]))
	            {
	            	if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false))
					{
   						new moneystring[128];
						format(moneystring, sizeof(moneystring), "Current stored money: %d\n\nType ammount of money that you want to store", HouseInfo[i][hMoney]);
		    			if(!strlen(inputtext)) return ShowPlayerDialog(playerid, 5684, DIALOG_STYLE_INPUT, "   Stored money", moneystring, "Ok", "Back");
						if(GetPlayerMoney(playerid) < strval(inputtext))
						{
							SendClientMessage(playerid, COLOR_KRED, "You don't have enoguh money to store!");
							ShowPlayerDialog(playerid, 5684, DIALOG_STYLE_INPUT, "   Stored money", moneystring, "Ok", "Back");
							return 1;
						}
						if(strval(inputtext) > 10000000)
						{
							SendClientMessage(playerid, COLOR_KRED, "You can store maximum 10000000!");
							ShowPlayerDialog(playerid, 5684, DIALOG_STYLE_INPUT, "   Stored money", moneystring, "Ok", "Back");
							return 1;
						}
						HouseInfo[i][hMoney] += strval(inputtext);
						GivePlayerMoney(playerid, -strval(inputtext));
						format(hstring, sizeof(hstring), "You store %d$! Current stored money: %d", strval(inputtext), HouseInfo[i][hMoney]);
						SendClientMessage(playerid, COLOR_YELLOW, hstring);
						ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");
						
			           	format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Money` = %d WHERE `HouseID` = %d", HouseInfo[i][hMoney], i);
						mysql_query(HQuery);
					}
				}
			}
		}
		case 5685: //dialog for taking money
		{
			if(!response) return ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");
       		foreach(Houses, i)
			{
	            if(IsPlayerInRangeOfPoint(playerid, 20.0, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]))
	            {
	            	if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false))
					{
						new moneystring[128];
		    			format(moneystring, sizeof(moneystring), "Current stored money: %d\n\nType ammount of money that you want to take", HouseInfo[i][hMoney]);
						if(!strlen(inputtext)) return ShowPlayerDialog(playerid, 5685, DIALOG_STYLE_INPUT, "   Stored money", moneystring, "Ok", "Back");
						if(strval(inputtext) > HouseInfo[i][hMoney])
						{
							SendClientMessage(playerid, COLOR_KRED, "House does not have that much money!");
							ShowPlayerDialog(playerid, 5685, DIALOG_STYLE_INPUT, "   Stored money", moneystring, "Ok", "Back");
							return 1;
						}
						HouseInfo[i][hMoney] -= strval(inputtext);
						GivePlayerMoney(playerid, strval(inputtext));
						format(hstring, sizeof(hstring), "You take %d$! Current stored money: %d", strval(inputtext), HouseInfo[i][hMoney]);
						SendClientMessage(playerid, COLOR_YELLOW, hstring);
						ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");

			           	format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Money` = %d WHERE `HouseID` = %d", HouseInfo[i][hMoney], i);
						mysql_query(HQuery);
					}
				}
			}
		}
		case 5686: //dialog for setting rent price
		{
			if(!response) return ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");
       		foreach(Houses, i)
			{
	            if(IsPlayerInRangeOfPoint(playerid, 20.0, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]))
	            {
	            	if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false))
					{
					    new rentstring[128], labelstring[128];
						format(rentstring, sizeof(rentstring), "Current rent price: %d\nType ammount of price that you want to set for renting\n0 for disabling rent!", HouseInfo[i][hRentPrice]);
						if(!strlen(inputtext)) return ShowPlayerDialog(playerid, 5686, DIALOG_STYLE_INPUT, "   Rent price", rentstring, "Ok", "Back");
						if(strval(inputtext) < 0 || strval(inputtext) > 10000) return ShowPlayerDialog(playerid, 5686, DIALOG_STYLE_INPUT, "   Rent price", rentstring, "Ok", "Back");
						if(strval(inputtext) == 0)
						{
							HouseInfo[i][hRentDisabled] = 1;
							HouseInfo[i][hRented] = 0;
							format(HouseInfo[i][hRentUser], 24, "None");
						    SendClientMessage(playerid, COLOR_YELLOW, "Rent disabled!");
                          	format(labelstring, sizeof(labelstring), "Owner: %s\nHouse ID: %d\nRent Disabled", HouseInfo[i][hOwner], i);
							Update3DTextLabelText(HouseInfo[i][hLabel], 0x21DD00FF, labelstring);

							format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Rent User` = 'None', `Rented` = 0, `Rent Disabled` = 1 WHERE `HouseID` = %d", i);
							mysql_query(HQuery);
							return ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");
						}
						HouseInfo[i][hRentDisabled] = 0;
						HouseInfo[i][hRentPrice] = strval(inputtext);
  						format(labelstring, sizeof(labelstring), "Owner: %s\nHouse ID: %d\nRent User: %s\nRent Price: %d", HouseInfo[i][hOwner], i, HouseInfo[i][hRentUser], HouseInfo[i][hRentPrice]);
						Update3DTextLabelText(HouseInfo[i][hLabel], 0x21DD00FF, labelstring);
					    format(hstring, sizeof(hstring), "Rent price set on %d", HouseInfo[i][hRentPrice]);
					    SendClientMessage(playerid, COLOR_YELLOW, hstring);
					    ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");
					    
					    format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Rent Price` = %d, `Rent Disabled` = 0 WHERE `HouseID` = %d", HouseInfo[i][hRentPrice], i);
						mysql_query(HQuery);
					}
				}
			}
		}
		case 5687: //dialog for kicking rent user
		{
			if(!response) return ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");
       		foreach(Houses, i)
			{
	            if(IsPlayerInRangeOfPoint(playerid, 20.0, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]))
	            {
	            	if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false))
					{
					    new labelstring[128];
					    HouseInfo[i][hRented] = 0;
		    			format(hstring, sizeof(hstring), "You kicked %s", HouseInfo[i][hRentUser]);
					    SendClientMessage(playerid, COLOR_YELLOW, hstring);
					    format(HouseInfo[i][hRentUser], 24, "None");
   						format(labelstring, sizeof(labelstring), "Owner: %s\nHouse ID: %d\nRent User: %s\nRent Price: %d", HouseInfo[i][hOwner], i, HouseInfo[i][hRentUser], HouseInfo[i][hRentPrice]);
						Update3DTextLabelText(HouseInfo[i][hLabel], 0x21DD00FF, labelstring);
					    ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user\nBuy alarm | $2000\nSell alarm", "Ok", "Exit");

					    format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Rent User` = 'None', `Rented` = 0 WHERE `HouseID` = %d", i);
						mysql_query(HQuery);
					}
				}
			}
		}
		case 5688: //sell to player house
		{
		    new selledstring[128], selledstring2[128];
		    if(!response)
		    {
		        SendClientMessage(playerid, COLOR_YELLOW, "You canceled buying house!");
		        SendClientMessage(GetPVarInt(playerid, "Seller"), COLOR_YELLOW, "Player canceled buying house!");
		        return 1;
		    }
			print("Calls under response");
		    foreach(Houses, i)
		    {
		        if(IsPlayerInRangeOfPoint(GetPVarInt(playerid, "Seller"), 3.0, HouseInfo[i][hEnterX], HouseInfo[i][hEnterY], HouseInfo[i][hEnterZ]))
		        {
				 	if(!strcmp(HouseInfo[i][hOwner], GetName(GetPVarInt(playerid, "Seller")), false) && HouseInfo[i][hOwned] == 1)
				    {
					 	new HQuery2[200];
						format(HQuery2, sizeof(HQuery2), "SELECT HouseID FROM `house` WHERE `HouseID` = '%d'", i);
						mysql_query(HQuery2);
						mysql_store_result();
						if(mysql_num_rows() == 1)
						{
						    print("House sold!");
			                format(HouseInfo[i][hOwner], 24, "%s", GetName(playerid));
			                format(HouseInfo[i][hRentUser], 24, "None");
							HouseInfo[i][hOwned] = 1;
							HouseInfo[i][hLocked] = 0;
							HouseInfo[i][hRented] = 0;
							GivePlayerMoney(playerid, -HouseInfo[i][hPrice]);
							GivePlayerMoney(GetPVarInt(playerid, "Seller"), HouseInfo[i][hPrice]);
							if(HouseInfo[i][hRentDisabled] == 0)
							{
								DestroyPickup(HouseInfo[i][hPickup]);
								HouseInfo[i][hPickup] = CreatePickup(1239, 23, HouseInfo[i][hEnterX], HouseInfo[i][hEnterY], HouseInfo[i][hEnterZ], 0);
								format(hstring, sizeof(hstring), "Owner: %s\nHouse ID: %d\nRent User: %s\nRent Price: %d", HouseInfo[i][hOwner], i, HouseInfo[i][hRentUser], HouseInfo[i][hRentPrice]);
								Update3DTextLabelText(HouseInfo[i][hLabel], 0x21DD00FF, hstring);
							}
							else
							{
								DestroyPickup(HouseInfo[i][hPickup]);
								HouseInfo[i][hPickup] = CreatePickup(1239, 23, HouseInfo[i][hEnterX], HouseInfo[i][hEnterY], HouseInfo[i][hEnterZ], 0);
								format(hstring, sizeof(hstring), "Owner: %s\nHouse ID: %d\nRent Disabled", HouseInfo[i][hOwner], i);
								Update3DTextLabelText(HouseInfo[i][hLabel], 0x21DD00FF, hstring);
							}
							format(selledstring, sizeof(selledstring), "You bought house from player %s for %d$", GetName(GetPVarInt(playerid, "Seller")), HouseInfo[i][hPrice]);
							SendClientMessage(playerid, COLOR_YELLOW, selledstring);
							format(selledstring2, sizeof(selledstring2), "House sold to player %s for %d$", GetName(playerid), HouseInfo[i][hPrice]);
							SendClientMessage(GetPVarInt(playerid, "Seller"), COLOR_YELLOW, selledstring2);
							mysql_free_result();

							format(HQuery, sizeof(HQuery), "UPDATE `house` SET `User` = '%s', `Owned` = 1, `Locked` = 0, `Rent User` = 'None', `Rented` = 0 WHERE `HouseID` = %d", GetName(playerid), i);
							mysql_query(HQuery);
						}
					}
				}
			}
		}
		case 5689: //dialog for house car controling
		{
		    if(!response) return 0;
		    switch(listitem)
		    {
		        case 0:
		        {
		            if(!response) return 0;
		          	foreach(Houses, i)
					{
						new HQuery2[200];
						format(HQuery2, sizeof(HQuery2), "SELECT HouseID FROM `house` WHERE `HouseID` = '%d'", i);
						mysql_query(HQuery2);
						mysql_store_result();
						if(!strcmp(HouseInfo[i][hCarOwner], GetName(playerid), false))
						{
							HouseInfo[i][hCarLocked] = 1;
						 	GameTextForPlayer(playerid, "House car ~r~locked!", 2000, 5);

							format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Car Locked` = 1 WHERE `HouseID` = %d", i);
							mysql_query(HQuery);
						}
						mysql_free_result();
					}
		        }
			    case 1:
			    {
			        if(!response) return 0;
	      			foreach(Houses, i)
					{
						new HQuery2[200];
						format(HQuery2, sizeof(HQuery2), "SELECT HouseID FROM `house` WHERE `HouseID` = '%d'", i);
						mysql_query(HQuery2);
						mysql_store_result();
						if(!strcmp(HouseInfo[i][hCarOwner], GetName(playerid), false))
						{
							HouseInfo[i][hCarLocked] = 0;
						 	GameTextForPlayer(playerid, "House car ~g~unlocked!", 2000, 5);

							format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Car Locked` = 0 WHERE `HouseID` = %d", i);
							mysql_query(HQuery);
						}
						mysql_free_result();
					}
			    }
				case 2:
				{
				    if(!response) return ShowPlayerDialog(playerid, 5689, DIALOG_STYLE_LIST, "   Control your house car!", "Lock house car\nUnlock house car\nStore weapon\nTake weapon\nStore money\nTake money", "Ok", "Exit");
	      			foreach(Houses, i)
					{
						new HQuery2[200];
						format(HQuery2, sizeof(HQuery2), "SELECT HouseID FROM `house` WHERE `HouseID` = '%d'", i);
						mysql_query(HQuery2);
						mysql_store_result();
						if(mysql_num_rows() == 1)
						{
							if(!strcmp(HouseInfo[i][hCarOwner], GetName(playerid), false))
							{
				    		    new gunstring[128], gunstring1[128], gunstring2[128];
								if(HouseInfo[i][hCarWeaponID1] == 0) format(gunstring1, sizeof(gunstring1), "Nothing");
								else format(gunstring1, sizeof(gunstring1), "Weapon: %s | Ammo: %d", GetWeapon(HouseInfo[i][hCarWeaponID1]), HouseInfo[i][hCarWeaponID1Ammo]);

								if(HouseInfo[i][hCarWeaponID2] == 0) format(gunstring2, sizeof(gunstring1), "Nothing");
								else format(gunstring2, sizeof(gunstring2), "Weapon: %s | Ammo: %d", GetWeapon(HouseInfo[i][hCarWeaponID2]), HouseInfo[i][hCarWeaponID2Ammo]);

								format(gunstring, sizeof(gunstring), "%s\n%s", gunstring1, gunstring2);

								ShowPlayerDialog(playerid, 5690, DIALOG_STYLE_LIST, "   Stored guns", gunstring, "Ok", "Exit");
							}
						}
						mysql_free_result();
					}
				}
				case 3:
				{
					if(!response) return ShowPlayerDialog(playerid, 5689, DIALOG_STYLE_LIST, "   Control your house car!", "Lock house car\nUnlock house car\nStore weapon\nTake weapon\nStore money\nTake money", "Ok", "Exit");
	      			foreach(Houses, i)
					{
						new HQuery2[200];
						format(HQuery2, sizeof(HQuery2), "SELECT HouseID FROM `house` WHERE `HouseID` = '%d'", i);
						mysql_query(HQuery2);
						mysql_store_result();
						if(mysql_num_rows() == 1)
						{
							if(!strcmp(HouseInfo[i][hCarOwner], GetName(playerid), false))
							{
				    		    new gunstring[128], gunstring1[128], gunstring2[128];
								if(HouseInfo[i][hCarWeaponID1] == 0) format(gunstring1, sizeof(gunstring1), "Nothing");
								else format(gunstring1, sizeof(gunstring1), "Weapon: %s | Ammo: %d", GetWeapon(HouseInfo[i][hCarWeaponID1]), HouseInfo[i][hCarWeaponID1Ammo]);

								if(HouseInfo[i][hCarWeaponID2] == 0) format(gunstring2, sizeof(gunstring1), "Nothing");
								else format(gunstring2, sizeof(gunstring2), "Weapon: %s | Ammo: %d", GetWeapon(HouseInfo[i][hCarWeaponID2]), HouseInfo[i][hCarWeaponID2Ammo]);

								format(gunstring, sizeof(gunstring), "%s\n%s", gunstring1, gunstring2);

								ShowPlayerDialog(playerid, 5693, DIALOG_STYLE_LIST, "   Stored guns", gunstring, "Ok", "Exit");
							}
							mysql_free_result();
						}
					}
				}
				case 4:
				{
					if(!response) return ShowPlayerDialog(playerid, 5689, DIALOG_STYLE_LIST, "   Control your house car!", "Lock house car\nUnlock house car\nStore weapon\nTake weapon\nStore money\nTake money", "Ok", "Exit");
	      			foreach(Houses, i)
					{
						new HQuery2[200];
						format(HQuery2, sizeof(HQuery2), "SELECT HouseID FROM `house` WHERE `HouseID` = '%d'", i);
						mysql_query(HQuery2);
						mysql_store_result();
						if(mysql_num_rows() == 1)
						{
							if(!strcmp(HouseInfo[i][hCarOwner], GetName(playerid), false))
							{
				    		    new moneystring[128];
								format(moneystring, sizeof(moneystring), "Current stored money: %d\n\nType ammount of money that you want to store", HouseInfo[i][hCarMoney]);
								ShowPlayerDialog(playerid, 5694, DIALOG_STYLE_INPUT, "   Stored money", moneystring, "Ok", "Back");
							}
						}
						mysql_free_result();
					}
				}
				case 5:
				{
					if(!response) return ShowPlayerDialog(playerid, 5689, DIALOG_STYLE_LIST, "   Control your house car!", "Lock house car\nUnlock house car\nStore weapon\nTake weapon\nStore money\nTake money", "Ok", "Exit");
	      			foreach(Houses, i)
					{
						new HQuery2[200];
						format(HQuery2, sizeof(HQuery2), "SELECT HouseID FROM `house` WHERE `HouseID` = '%d'", i);
						mysql_query(HQuery2);
						mysql_store_result();
						if(mysql_num_rows() == 1)
						{
							if(!strcmp(HouseInfo[i][hCarOwner], GetName(playerid), false))
							{
							    new moneystring[128];
							    format(moneystring, sizeof(moneystring), "Current stored money: %d\n\nType ammount of money that you want to take", HouseInfo[i][hCarMoney]);
							    ShowPlayerDialog(playerid, 5695, DIALOG_STYLE_INPUT, "   Stored money", moneystring, "Ok", "Back");
							}
						}
						mysql_free_result();
					}
				}
			}
		}
		case 5690: //dialog with all stored guns
		{
		    if(!response) return ShowPlayerDialog(playerid, 5689, DIALOG_STYLE_LIST, "   Control your house car!", "Lock house car\nUnlock house car\nStore weapon\nTake weapon\nStore money\nTake money", "Ok", "Exit");
		    switch(listitem)
		    {
		        case 0:
		        {
		            ShowPlayerDialog(playerid, 5691, DIALOG_STYLE_INPUT, "  Gun", "Type a gun ID that you want to store!", "Ok", "Exit");
		        }
	        	case 1:
		        {
		            ShowPlayerDialog(playerid, 5692, DIALOG_STYLE_INPUT, "  Gun", "Type a gun ID that you want to store!", "Ok", "Exit");
		        }
		    }
		}
		case 5691: //dialog for storing gun in slot 1
		{
		    if(!response) return ShowPlayerDialog(playerid, 5689, DIALOG_STYLE_LIST, "   Control your house car!", "Lock house car\nUnlock house car\nStore weapon\nTake weapon\nStore money\nTake money", "Ok", "Exit");
			foreach(Houses, i)
			{
				new HQuery2[200];
				format(HQuery2, sizeof(HQuery2), "SELECT HouseID FROM `house` WHERE `HouseID` = '%d'", i);
				mysql_query(HQuery2);
				mysql_store_result();
				if(mysql_num_rows() == 1)
				{
					if(!strcmp(HouseInfo[i][hCarOwner], GetName(playerid), false))
					{
					    Custom_GetPlayerWeapon(playerid);
	    		        if(House_Weapon[playerid][Custom_GetSlot(strval(inputtext))] == strval(inputtext))
	    		        {
	    		        	if(strval(inputtext) > 0 || strval(inputtext) < 46)
    		    			{
		    		            HouseInfo[i][hCarWeaponID1] = strval(inputtext);
		    		            HouseInfo[i][hCarWeaponID1Ammo] = House_Ammo[playerid][Custom_GetSlot(HouseInfo[i][hCarWeaponID1])];
								format(hstring, sizeof(hstring), "Gun ID %d stored in the slot 1", strval(inputtext));
								SendClientMessage(playerid, COLOR_LIME, hstring);
								ShowPlayerDialog(playerid, 5689, DIALOG_STYLE_LIST, "   Control your house car!", "Lock house car\nUnlock house car\nStore weapon\nTake weapon\nStore money\nTake money", "Ok", "Exit");

                				format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Car Weapon ID 1` = %d, `Car Weapon ID 1 Ammo` = %d WHERE `HouseID` = %d", strval(inputtext), HouseInfo[i][hCarWeaponID1Ammo], i);
								mysql_query(HQuery);
							}
			    		    else
							{
								SendClientMessage(playerid, COLOR_KRED, "Invalid gun ID!");
								ShowPlayerDialog(playerid, 5691, DIALOG_STYLE_INPUT, "  Gun", "Type a gun ID that you want to store!", "Ok", "Exit");
							}
		    			}
	    		        else
						{
							SendClientMessage(playerid, COLOR_KRED, "You don't have that gun!");
							ShowPlayerDialog(playerid, 5691, DIALOG_STYLE_INPUT, "  Gun", "Type a gun ID that you want to store!", "Ok", "Exit");
						}
					}
				}
				mysql_free_result();
			}
		}
		case 5692: //dialog for storing gun in slot 2
		{
		    if(!response) return ShowPlayerDialog(playerid, 5689, DIALOG_STYLE_LIST, "   Control your house car!", "Lock house car\nUnlock house car\nStore weapon\nTake weapon\nStore money\nTake money", "Ok", "Exit");
			foreach(Houses, i)
			{
				new HQuery2[200];
				format(HQuery2, sizeof(HQuery2), "SELECT HouseID FROM `house` WHERE `HouseID` = '%d'", i);
				mysql_query(HQuery2);
				mysql_store_result();
				if(mysql_num_rows() == 1)
				{
					if(!strcmp(HouseInfo[i][hCarOwner], GetName(playerid), false))
					{
					    Custom_GetPlayerWeapon(playerid);
	    		        if(House_Weapon[playerid][Custom_GetSlot(strval(inputtext))] == strval(inputtext))
	    		        {
	    		        	if(strval(inputtext) > 0 || strval(inputtext) < 46)
    		    			{
		    		            HouseInfo[i][hCarWeaponID2] = strval(inputtext);
		    		            HouseInfo[i][hCarWeaponID2Ammo] = House_Ammo[playerid][Custom_GetSlot(HouseInfo[i][hCarWeaponID2])];
								format(hstring, sizeof(hstring), "Gun ID %d stored in the slot 2", strval(inputtext));
								SendClientMessage(playerid, COLOR_LIME, hstring);
								ShowPlayerDialog(playerid, 5689, DIALOG_STYLE_LIST, "   Control your house car!", "Lock house car\nUnlock house car\nStore weapon\nTake weapon\nStore money\nTake money", "Ok", "Exit");

                				format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Car Weapon ID 2` = %d, `Car Weapon ID 2 Ammo` = %d WHERE `HouseID` = %d", strval(inputtext), HouseInfo[i][hCarWeaponID2Ammo], i);
								mysql_query(HQuery);
							}
			    		    else
							{
								SendClientMessage(playerid, COLOR_KRED, "Invalid gun ID!");
								ShowPlayerDialog(playerid, 5691, DIALOG_STYLE_INPUT, "  Gun", "Type a gun ID that you want to store!", "Ok", "Exit");
							}
		    			}
	    		        else
						{
							SendClientMessage(playerid, COLOR_KRED, "You don't have that gun!");
							ShowPlayerDialog(playerid, 5691, DIALOG_STYLE_INPUT, "  Gun", "Type a gun ID that you want to store!", "Ok", "Exit");
						}
					}
				}
				mysql_free_result();
			}
		}
	    case 5693: //dialog for taking gun
	    {
	        if(!response) return ShowPlayerDialog(playerid, 5678, DIALOG_STYLE_LIST, "   Control your house!", "Lock house\nUnlock house\nSet rent price\nStore weapon\nTake weapon\nStore money\nTake money\nKick rent user", "Ok", "Exit");
	        switch(listitem)
	        {
	            case 0: //slot 1
	            {
				    if(!response) return ShowPlayerDialog(playerid, 5689, DIALOG_STYLE_LIST, "   Control your house car!", "Lock house car\nUnlock house car\nStore weapon\nTake weapon\nStore money\nTake money", "Ok", "Exit");
					foreach(Houses, i)
					{
						new HQuery2[200];
						format(HQuery2, sizeof(HQuery2), "SELECT HouseID FROM `house` WHERE `HouseID` = '%d'", i);
						mysql_query(HQuery2);
						mysql_store_result();
						if(mysql_num_rows() == 1)
						{
							if(!strcmp(HouseInfo[i][hCarOwner], GetName(playerid), false))
							{
							    if(HouseInfo[i][hCarWeaponID1] > 1) //if slot isn't empty (Emty slot is weapon ID 0 (Hand))
							    {
							        GivePlayerWeapon(playerid, HouseInfo[i][hCarWeaponID1], HouseInfo[i][hCarWeaponID1Ammo]);
							        HouseInfo[i][hCarWeaponID1] = 0;
							        HouseInfo[i][hCarWeaponID1Ammo] = 0;
							        ShowPlayerDialog(playerid, 5689, DIALOG_STYLE_LIST, "   Control your house car!", "Lock house car\nUnlock house car\nStore weapon\nTake weapon\nStore money\nTake money", "Ok", "Exit");

           	                		format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Car Weapon ID 1` = 0, `Car Weapon ID 1 Ammo` = 0 WHERE `HouseID` = %d", i);
									mysql_query(HQuery);
							    }
							    else
							    {
							        SendClientMessage(playerid, COLOR_KRED, "That slot is empty!");
							    	ShowPlayerDialog(playerid, 5689, DIALOG_STYLE_LIST, "   Control your house car!", "Lock house car\nUnlock house car\nStore weapon\nTake weapon\nStore money\nTake money", "Ok", "Exit");
							    }
							}
							mysql_free_result();
						}
					}
				}
	            case 1: //slot 2
	            {
				    if(!response) return ShowPlayerDialog(playerid, 5689, DIALOG_STYLE_LIST, "   Control your house car!", "Lock house car\nUnlock house car\nStore weapon\nTake weapon\nStore money\nTake money", "Ok", "Exit");
					foreach(Houses, i)
					{
						new HQuery2[200];
						format(HQuery2, sizeof(HQuery2), "SELECT HouseID FROM `house` WHERE `HouseID` = '%d'", i);
						mysql_query(HQuery2);
						mysql_store_result();
						if(mysql_num_rows() == 1)
						{
							if(!strcmp(HouseInfo[i][hCarOwner], GetName(playerid), false))
							{
							    if(HouseInfo[i][hCarWeaponID2] > 1) //if slot isn't empty (Emty slot is weapon ID 0 (Hand))
							    {
							        GivePlayerWeapon(playerid, HouseInfo[i][hCarWeaponID2], HouseInfo[i][hCarWeaponID2Ammo]);
							        HouseInfo[i][hCarWeaponID2] = 0;
							        HouseInfo[i][hCarWeaponID2Ammo] = 0;
							        ShowPlayerDialog(playerid, 5689, DIALOG_STYLE_LIST, "   Control your house car!", "Lock house car\nUnlock house car\nStore weapon\nTake weapon\nStore money\nTake money", "Ok", "Exit");

           	                		format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Car Weapon ID 2` = 0, `Car Weapon ID 2 Ammo` = 0 WHERE `HouseID` = %d", i);
									mysql_query(HQuery);
							    }
							    else
							    {
							        SendClientMessage(playerid, COLOR_KRED, "That slot is empty!");
							    	ShowPlayerDialog(playerid, 5689, DIALOG_STYLE_LIST, "   Control your house car!", "Lock house car\nUnlock house car\nStore weapon\nTake weapon\nStore money\nTake money", "Ok", "Exit");
							    }
							}
						}
						mysql_free_result();
					}
				}
			}
		}
	    case 5694: //dialog for storing money
		{
		    if(!response) return ShowPlayerDialog(playerid, 5689, DIALOG_STYLE_LIST, "   Control your house car!", "Lock house car\nUnlock house car\nStore weapon\nTake weapon\nStore money\nTake money", "Ok", "Exit");
			foreach(Houses, i)
			{
				new HQuery2[200];
				format(HQuery2, sizeof(HQuery2), "SELECT HouseID FROM `house` WHERE `HouseID` = '%d'", i);
				mysql_query(HQuery2);
				mysql_store_result();
				if(mysql_num_rows() == 1)
				{
					if(!strcmp(HouseInfo[i][hCarOwner], GetName(playerid), false))
					{
   						new moneystring[128];
						format(moneystring, sizeof(moneystring), "Current stored money: %d\n\nType ammount of money that you want to store", HouseInfo[i][hCarMoney]);
		    			if(!strlen(inputtext)) return ShowPlayerDialog(playerid, 5684, DIALOG_STYLE_INPUT, "   Stored money", moneystring, "Ok", "Back");
						if(GetPlayerMoney(playerid) < strval(inputtext))
						{
							SendClientMessage(playerid, COLOR_KRED, "You don't have enoguh money to store!");
							ShowPlayerDialog(playerid, 5694, DIALOG_STYLE_INPUT, "   Stored money", moneystring, "Ok", "Back");
							return 1;
						}
						if(strval(inputtext) > 10000000)
						{
							SendClientMessage(playerid, COLOR_KRED, "You can store maximum 10000000!");
							ShowPlayerDialog(playerid, 5694, DIALOG_STYLE_INPUT, "   Stored money", moneystring, "Ok", "Back");
							return 1;
						}
						HouseInfo[i][hCarMoney] += strval(inputtext);
						GivePlayerMoney(playerid, -strval(inputtext));
						format(hstring, sizeof(hstring), "You store %d$! Current stored money: %d", strval(inputtext), HouseInfo[i][hCarMoney]);
						SendClientMessage(playerid, COLOR_YELLOW, hstring);
						ShowPlayerDialog(playerid, 5689, DIALOG_STYLE_LIST, "   Control your house car!", "Lock house car\nUnlock house car\nStore weapon\nTake weapon\nStore money\nTake money", "Ok", "Exit");

			           	format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Car Money` = %d WHERE `HouseID` = %d", HouseInfo[i][hCarMoney], i);
						mysql_query(HQuery);
					}
				}
				mysql_free_result();
			}
		}
		case 5695: //dialog for taking money
		{
			if(!response) return ShowPlayerDialog(playerid, 5689, DIALOG_STYLE_LIST, "   Control your house car!", "Lock house car\nUnlock house car\nStore weapon\nTake weapon\nStore money\nTake money", "Ok", "Exit");
			foreach(Houses, i)
			{
				new HQuery2[200];
				format(HQuery2, sizeof(HQuery2), "SELECT HouseID FROM `house` WHERE `HouseID` = '%d'", i);
				mysql_query(HQuery2);
				mysql_store_result();
				if(mysql_num_rows() == 1)
				{
					if(!strcmp(HouseInfo[i][hCarOwner], GetName(playerid), false))
					{
						new moneystring[128];
		    			format(moneystring, sizeof(moneystring), "Current stored money: %d\n\nType ammount of money that you want to take", HouseInfo[i][hCarMoney]);
						if(!strlen(inputtext)) return ShowPlayerDialog(playerid, 5685, DIALOG_STYLE_INPUT, "   Stored money", moneystring, "Ok", "Back");
						if(strval(inputtext) > HouseInfo[i][hCarMoney])
						{
							SendClientMessage(playerid, COLOR_KRED, "House car does not have that much money!");
							ShowPlayerDialog(playerid, 5695, DIALOG_STYLE_INPUT, "   Stored money", moneystring, "Ok", "Back");
							return 1;
						}
						HouseInfo[i][hCarMoney] -= strval(inputtext);
						GivePlayerMoney(playerid, strval(inputtext));
						format(hstring, sizeof(hstring), "You take %d$! Current stored money: %d", strval(inputtext), HouseInfo[i][hCarMoney]);
						SendClientMessage(playerid, COLOR_YELLOW, hstring);
						ShowPlayerDialog(playerid, 5689, DIALOG_STYLE_LIST, "   Control your house car!", "Lock house car\nUnlock house car\nStore weapon\nTake weapon\nStore money\nTake money", "Ok", "Exit");

			           	format(HQuery, sizeof(HQuery), "UPDATE `house` SET `Car Money` = %d WHERE `HouseID` = %d", HouseInfo[i][hCarMoney], i);
						mysql_query(HQuery);
					}
				}
				mysql_free_result();
			}
		}
		case 5696:
		{
			if(!response) return 0; //ShowPlayerDialog(playerid, 5696, DIALOG_STYLE_LIST, "   Creating the house!", "Change interior\nChange interior position\nChange virtual world\nChange house price\nChange house rent price\nExport to file", "Ok", "Exit");
			switch(listitem)
			{
			    case 0:
			    {
			        ShowPlayerDialog(playerid, 5697, DIALOG_STYLE_INPUT, "   Change house interior", "Enter the new interior ID", "Ok", "Exit");
			    }
			    case 1:
			    {
			        ShowPlayerDialog(playerid, 5698, DIALOG_STYLE_INPUT, "   Change house interior position", "Enter the new interior X coordinate", "Ok", "Exit");
			    }
			    case 2:
			    {
			        ShowPlayerDialog(playerid, 5699, DIALOG_STYLE_INPUT, "   Change house virtualworld", "Enter the new virtualworld", "Ok", "Exit");
			    }
			    case 3:
			    {
			        ShowPlayerDialog(playerid, 5700, DIALOG_STYLE_INPUT, "   Change house price", "Enter the new price", "Ok", "Exit");
			    }
			    case 4:
			    {
			        ShowPlayerDialog(playerid, 5701, DIALOG_STYLE_INPUT, "   Change house rent price", "Enter the new rent price", "Ok", "Exit");
			    }
			    case 5:
			    {
			        for(new h = 0; h < MAX_CURRENT_HOUSES; h++)
			        {
			            if(IsPlayerAdmin(playerid))
			            {
			                if(IsPlayerInRangeOfPoint(playerid, 3.0, CurrentHouseInfo[h][hcEnterX], CurrentHouseInfo[h][hcEnterY], CurrentHouseInfo[h][hcEnterZ]))
							{
							    new File: lFile = fopen("Houses.txt", io_append), logData[178];
								format(logData, sizeof(logData), "CreateHouse(%f, %f, %f, %d, %f, %f, %f, %d, %d, %d); \r\n", CurrentHouseInfo[h][hcEnterX], CurrentHouseInfo[h][hcEnterY], CurrentHouseInfo[h][hcEnterZ], CurrentHouseInfo[h][hcInterior], CurrentHouseInfo[h][hcExitX], CurrentHouseInfo[h][hcExitY], CurrentHouseInfo[h][hcExitZ], CurrentHouseInfo[h][hcPrice], CurrentHouseInfo[h][hcVirtualWorld], CurrentHouseInfo[h][hcRentPrice]);
								fwrite(lFile, logData);
								fclose(lFile);
								
								SendClientMessage(playerid, COLOR_LIME, "House has been successfully {FFFFFF}exported!");
								ShowPlayerDialog(playerid, 5696, DIALOG_STYLE_LIST, "   Creating the house!", "Change interior\nChange interior position\nChange virtual world\nChange house price\nChange house rent price\nExport to file", "Ok", "Exit");
							}
						}
					}
			    }
			}
		}
		case 5697:
		{
		    if(!response) return ShowPlayerDialog(playerid, 5696, DIALOG_STYLE_LIST, "   Creating the house!", "Change interior\nChange interior position\nChange virtual world\nChange house price\nChange house rent price\nExport to file", "Ok", "Exit");
	        for(new h = 0; h < MAX_CURRENT_HOUSES; h++)
	        {
	            if(IsPlayerAdmin(playerid))
	            {
	                if(IsPlayerInRangeOfPoint(playerid, 3.0, CurrentHouseInfo[h][hcEnterX], CurrentHouseInfo[h][hcEnterY], CurrentHouseInfo[h][hcEnterZ]))
					{
					    if(!strlen(inputtext)) return ShowPlayerDialog(playerid, 5697, DIALOG_STYLE_INPUT, "   Change house interior", "Enter the new interior ID", "Ok", "Exit");
						CurrentHouseInfo[h][hcInterior] = strval(inputtext);

					    format(hstring, sizeof(hstring), "House interior has been changed to {FFFFFF}%d", strval(inputtext));
					    SendClientMessage(playerid, COLOR_LIME, hstring);
			            ShowPlayerDialog(playerid, 5696, DIALOG_STYLE_LIST, "   Creating the house!", "Change interior\nChange interior position\nChange virtual world\nChange house price\nChange house rent price\nExport to file", "Ok", "Exit");
					}
				}
			}
		}
		case 5698:
		{
		    if(!response) return ShowPlayerDialog(playerid, 5696, DIALOG_STYLE_LIST, "   Creating the house!", "Change interior\nChange interior position\nChange virtual world\nChange house price\nChange house rent price\nExport to file", "Ok", "Exit");
	        for(new h = 0; h < MAX_CURRENT_HOUSES; h++)
	        {
	            if(IsPlayerAdmin(playerid))
	            {
	                if(IsPlayerInRangeOfPoint(playerid, 3.0, CurrentHouseInfo[h][hcEnterX], CurrentHouseInfo[h][hcEnterY], CurrentHouseInfo[h][hcEnterZ]))
					{
					    if(!strlen(inputtext)) return ShowPlayerDialog(playerid, 5698, DIALOG_STYLE_INPUT, "   Change house interior position", "Enter the new interior X coordinate", "Ok", "Exit");
						CurrentHouseInfo[h][hcExitX] = strval(inputtext);

					    format(hstring, sizeof(hstring), "House interior X coordinate has been changed to {FFFFFF}%d", strval(inputtext));
					    SendClientMessage(playerid, COLOR_LIME, hstring);
               			ShowPlayerDialog(playerid, 5702, DIALOG_STYLE_INPUT, "   Change house interior position", "Enter the new interior Y coordinate", "Ok", "Exit");
					}
				}
			}
		}
		case 5699:
		{
		    if(!response) return ShowPlayerDialog(playerid, 5696, DIALOG_STYLE_LIST, "   Creating the house!", "Change interior\nChange interior position\nChange virtual world\nChange house price\nChange house rent price\nExport to file", "Ok", "Exit");
	        for(new h = 0; h < MAX_CURRENT_HOUSES; h++)
	        {
	            if(IsPlayerAdmin(playerid))
	            {
	                if(IsPlayerInRangeOfPoint(playerid, 3.0, CurrentHouseInfo[h][hcEnterX], CurrentHouseInfo[h][hcEnterY], CurrentHouseInfo[h][hcEnterZ]))
					{
					    if(!strlen(inputtext)) return ShowPlayerDialog(playerid, 5699, DIALOG_STYLE_INPUT, "   Change house virtualworld", "Enter the new virtualworld", "Ok", "Exit");
						CurrentHouseInfo[h][hcVirtualWorld] = strval(inputtext);

					    format(hstring, sizeof(hstring), "House virtualworld has been changed to {FFFFFF}%d", strval(inputtext));
					    SendClientMessage(playerid, COLOR_LIME, hstring);
			            ShowPlayerDialog(playerid, 5696, DIALOG_STYLE_LIST, "   Creating the house!", "Change interior\nChange interior position\nChange virtual world\nChange house price\nChange house rent price\nExport to file", "Ok", "Exit");
					}
				}
			}
		}
		case 5700:
		{
		    if(!response) return ShowPlayerDialog(playerid, 5696, DIALOG_STYLE_LIST, "   Creating the house!", "Change interior\nChange interior position\nChange virtual world\nChange house price\nChange house rent price\nExport to file", "Ok", "Exit");
	        for(new h = 0; h < MAX_CURRENT_HOUSES; h++)
	        {
	            if(IsPlayerAdmin(playerid))
	            {
	                if(IsPlayerInRangeOfPoint(playerid, 3.0, CurrentHouseInfo[h][hcEnterX], CurrentHouseInfo[h][hcEnterY], CurrentHouseInfo[h][hcEnterZ]))
					{
					    if(!strlen(inputtext)) return ShowPlayerDialog(playerid, 5700, DIALOG_STYLE_INPUT, "   Change house price", "Enter the new price", "Ok", "Exit");
						CurrentHouseInfo[h][hcPrice] = strval(inputtext);

					    format(hstring, sizeof(hstring), "House price has been changed to {FFFFFF}%d", strval(inputtext));
					    SendClientMessage(playerid, COLOR_LIME, hstring);
			            ShowPlayerDialog(playerid, 5696, DIALOG_STYLE_LIST, "   Creating the house!", "Change interior\nChange interior position\nChange virtual world\nChange house price\nChange house rent price\nExport to file", "Ok", "Exit");
					}
				}
			}
		}
		case 5701:
		{
		    if(!response) return ShowPlayerDialog(playerid, 5696, DIALOG_STYLE_LIST, "   Creating the house!", "Change interior\nChange interior position\nChange virtual world\nChange house price\nChange house rent price\nExport to file", "Ok", "Exit");
	        for(new h = 0; h < MAX_CURRENT_HOUSES; h++)
	        {
	            if(IsPlayerAdmin(playerid))
	            {
	                if(IsPlayerInRangeOfPoint(playerid, 3.0, CurrentHouseInfo[h][hcEnterX], CurrentHouseInfo[h][hcEnterY], CurrentHouseInfo[h][hcEnterZ]))
					{
					    if(!strlen(inputtext)) return ShowPlayerDialog(playerid, 5701, DIALOG_STYLE_INPUT, "   Change house rent price", "Enter the new rent price", "Ok", "Exit");
						CurrentHouseInfo[h][hcRentPrice] = strval(inputtext);

					    format(hstring, sizeof(hstring), "House rent price has been changed to {FFFFFF}%d", strval(inputtext));
					    SendClientMessage(playerid, COLOR_LIME, hstring);
			            ShowPlayerDialog(playerid, 5696, DIALOG_STYLE_LIST, "   Creating the house!", "Change interior\nChange interior position\nChange virtual world\nChange house price\nChange house rent price\nExport to file", "Ok", "Exit");
					}
				}
			}
		}
		case 5702:
		{
		    if(!response) return ShowPlayerDialog(playerid, 5696, DIALOG_STYLE_LIST, "   Creating the house!", "Change interior\nChange interior position\nChange virtual world\nChange house price\nChange house rent price\nExport to file", "Ok", "Exit");
	        for(new h = 0; h < MAX_CURRENT_HOUSES; h++)
	        {
	            if(IsPlayerAdmin(playerid))
	            {
	                if(IsPlayerInRangeOfPoint(playerid, 3.0, CurrentHouseInfo[h][hcEnterX], CurrentHouseInfo[h][hcEnterY], CurrentHouseInfo[h][hcEnterZ]))
					{
					    if(!strlen(inputtext)) return ShowPlayerDialog(playerid, 5702, DIALOG_STYLE_INPUT, "   Change house interior position", "Enter the new interior Y coordinate", "Ok", "Exit");
						CurrentHouseInfo[h][hcExitY] = strval(inputtext);

					    format(hstring, sizeof(hstring), "House interior Y coordinate has been changed to {FFFFFF}%d", strval(inputtext));
					    SendClientMessage(playerid, COLOR_LIME, hstring);
               			ShowPlayerDialog(playerid, 5703, DIALOG_STYLE_INPUT, "   Change house interior position", "Enter the new interior Z coordinate", "Ok", "Exit");
					}
				}
			}
		}
		case 5703:
		{
		    if(!response) return ShowPlayerDialog(playerid, 5696, DIALOG_STYLE_LIST, "   Creating the house!", "Change interior\nChange interior position\nChange virtual world\nChange house price\nChange house rent price\nExport to file", "Ok", "Exit");
	        for(new h = 0; h < MAX_CURRENT_HOUSES; h++)
	        {
	            if(IsPlayerAdmin(playerid))
	            {
	                if(IsPlayerInRangeOfPoint(playerid, 3.0, CurrentHouseInfo[h][hcEnterX], CurrentHouseInfo[h][hcEnterY], CurrentHouseInfo[h][hcEnterZ]))
					{
					    if(!strlen(inputtext)) return ShowPlayerDialog(playerid, 5703, DIALOG_STYLE_INPUT, "   Change house interior position", "Enter the new interior Z coordinate", "Ok", "Exit");
						CurrentHouseInfo[h][hcExitZ] = strval(inputtext);

					    format(hstring, sizeof(hstring), "House interior Z coordinate has been changed to {FFFFFF}%d", strval(inputtext));
					    SendClientMessage(playerid, COLOR_LIME, hstring);
               			ShowPlayerDialog(playerid, 5696, DIALOG_STYLE_LIST, "   Creating the house!", "Change interior\nChange interior position\nChange virtual world\nChange house price\nChange house rent price\nExport to file", "Ok", "Exit");
					}
				}
			}
		}
	}
	return 1;
}

/*

 • Callback: OnPlayerKeyStateChange(playerid, newkeys, oldkeys)  (Hooked using y_hook)
 • Action: Player can enter house (If is not locked!) using F or Enter (by default in GTA:SA)

*/

Hook:H2_OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(newkeys & KEY_SECONDARY_ATTACK && !IsPlayerInAnyVehicle(playerid))
    {
        foreach(Houses, i)
        {
            if(IsPlayerInRangeOfPoint(playerid, 3.0, HouseInfo[i][hEnterX], HouseInfo[i][hEnterY], HouseInfo[i][hEnterZ]) && GetPlayerInterior(playerid) == 0 && GetPlayerVirtualWorld(playerid) == 0)
            {
                if(HouseInfo[i][hLocked] == 0)
                {
                    if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false)) 
		    		{
		    		    PlayerEnteredHisHouse[playerid] = true;
		    		}
	            	SetPlayerInterior(playerid, HouseInfo[i][hInterior]);
	                SetPlayerVirtualWorld(playerid, HouseInfo[i][hVirtualWorld]);
	                SetPlayerPos(playerid, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]);
	                return CallLocalFunction("OnPlayerEnterHouse", "dd", playerid, i);
				}
				else SendClientMessage(playerid, COLOR_KRED, "House is locked!"); 
            }
            else if(IsPlayerInRangeOfPoint(playerid, 3.0, HouseInfo[i][hExitX], HouseInfo[i][hExitY], HouseInfo[i][hExitZ]) && GetPlayerInterior(playerid) == HouseInfo[i][hInterior] && GetPlayerVirtualWorld(playerid) == HouseInfo[i][hVirtualWorld])
            {
                if(HouseInfo[i][hLocked] == 0) 
                {
                    if(!strcmp(HouseInfo[i][hOwner], GetName(playerid), false))
		    		{
		    		    PlayerEnteredHisHouse[playerid] = false;
		    		}
	            	SetPlayerInterior(playerid, 0);
	                SetPlayerVirtualWorld(playerid, 0);
	                SetPlayerPos(playerid, HouseInfo[i][hEnterX], HouseInfo[i][hEnterY], HouseInfo[i][hEnterZ]);
	                return CallLocalFunction("OnPlayerExitHouse", "dd", playerid, i);
    			}
				else SendClientMessage(playerid, COLOR_KRED, "House is locked!"); 
            }
        }
    }
    return 1;
}

Hook:H3_OnGameModeInit()
{
	RentFeeTimer = SetTimer("RentFeeUp", 3600000, 0);
	return 1;
}

Hook:H4_OnGameModeExit()
{
	KillTimer(RentFeeTimer);
	return 1;
}

/*

 • Callback: OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)  (Hooked using y_hook)
 • Action: Player can enter house car (If is not locked!) using F or Enter (by default in GTA:SA)

*/

Hook:H5_OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	foreach(Houses, i)
	{
	 	new HQuery2[200];
		format(HQuery2, sizeof(HQuery2), "SELECT HouseID FROM `house` WHERE `HouseID` = '%d'", i);
		mysql_query(HQuery2);
		mysql_store_result();
		if(mysql_num_rows() == 1)
		{
			if(vehicleid == HouseInfo[i][hCar]) CallLocalFunction("OnPlayerEnterHouseVehicle", "d", playerid);
			if(HouseInfo[i][hCarLocked] == 1 && !IsPlayerInAnyVehicle(playerid))
			{
				SendClientMessage(playerid, COLOR_KRED, "House car is locked!");
				GetPlayerPos(playerid, PPos[0], PPos[1], PPos[2]);
				SetPlayerPos(playerid, PPos[0], PPos[1], PPos[2]);
				return 1;
			}
            if(!strcmp(HouseInfo[i][hCarOwner], GetName(playerid), false))
    		{
				PlayerEnteredHisHouseCar[playerid] = true;
   			}
		}
		mysql_free_result();
	}
	return 1;
}

/*

 • Callback: OnPlayerExitVehicle(playerid, vehicleid)  (Hooked using y_hook)
 • Action: Player can exit house car using F or Enter (by default in GTA:SA)

*/

Hook:H6_OnPlayerExitVehicle(playerid, vehicleid)
{
	foreach(Houses, i)
	{
	 	new HQuery2[200];
		format(HQuery2, sizeof(HQuery2), "SELECT HouseID FROM `house` WHERE `HouseID` = '%d'", i);
		mysql_query(HQuery2);
		mysql_store_result();
		if(mysql_num_rows() == 1)
		{
			if(vehicleid == HouseInfo[i][hCar]) CallLocalFunction("OnPlayerExitHouseVehicle", "d", playerid);
			if(HouseInfo[i][hCarLocked] == 1 && !IsPlayerInAnyVehicle(playerid))
			{
				SendClientMessage(playerid, COLOR_KRED, "House car is locked!");
				GetPlayerPos(playerid, PPos[0], PPos[1], PPos[2]);
				SetPlayerPos(playerid, PPos[0], PPos[1], PPos[2]);
				return 1;
			}
            if(!strcmp(HouseInfo[i][hCarOwner], GetName(playerid), false))
    		{
				PlayerEnteredHisHouseCar[playerid] = false;
			}
		}
		mysql_free_result();
	}
	return 1;
}

Hook:H7_OnPlayerConnect(playerid)
{
	new credits[128];
	format(credits, sizeof(credits), "This server use S32_House %s by System32!", house_version);
	SendClientMessage(playerid, COLOR_LIME, credits);
	
	PlayerEnteredHisHouse[playerid] = false;
	PlayerEnteredHisHouseCar[playerid] = false;
	PlayerCanRobHouse[playerid] = true;
	HouseLockBreaking[playerid] = 0;
	HouseRobbing[playerid] = 0;
	CanRobHouseTimer[playerid] = 0;
	return 1;
}

Hook:H8_OnPlayerDisconnect(playerid, reason)
{
	PlayerEnteredHisHouse[playerid] = false;
	PlayerEnteredHisHouseCar[playerid] = false;
	PlayerCanRobHouse[playerid] = true;
	HouseLockBreaking[playerid] = 0;
	HouseRobbing[playerid] = 0;
	CanRobHouseTimer[playerid] = 0;
	return 1;
}
