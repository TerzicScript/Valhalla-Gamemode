/*
======================================================

		     Evo Scripts™
	          I-Sync™ Technology
                     By EvoturK™

======================================================
*/
native Evo_GetVehicleOwner(vehicleid);
native Evo_SetVehicleOwner(vehicleid, owner[]);
native Evo_GetVehiclePrice(vehicleid);
native Evo_SetVehiclePrice(vehicleid, price);
native Evo_GetSystemIDFromVehicleID(vehicleid);
native Evo_IsVehicleInSystem(vehicleid);
native Evo_CreateVehicle(Modelid, Owner[], Float:X, Float:Y, Float:Z, Float:Rot, Col1, Col2, Price);
native Evo_DeleteVehicle(vehicleid);

#define Evo_GetVehicleOwner           _Evo_GetVehicleOwner
#define Evo_SetVehicleOwner           _Evo_SetVehicleOwner
#define Evo_GetVehiclePrice           _Evo_GetVehiclePrice
#define Evo_SetVehiclePrice           _Evo_SetVehiclePrice
#define Evo_GetSystemIDFromVehicleID  _Evo_GetSystemIDFromVehicleID
#define Evo_IsVehicleInSystem         _Evo_IsVehicleInSystem
#define Evo_CreateVehicle             _Evo_CreateVehicle
#define Evo_DeleteVehicle             _Evo_DeleteVehicle

forward _Evo_GetVehicleOwner(vehicleid);
public _Evo_GetVehicleOwner(vehicleid)
{
	return CallRemoteFunction("_GetVehicleOwner", "i", vehicleid);
} 

forward _Evo_SetVehicleOwner(vehicleid, owner[]);
public _Evo_SetVehicleOwner(vehicleid, owner[])
{
	return CallRemoteFunction("_SetVehicleOwner", "is", vehicleid, owner);
} 

forward _Evo_GetVehiclePrice(vehicleid);
public _Evo_GetVehiclePrice(vehicleid)
{
	return CallRemoteFunction("_GetVehiclePrice", "i", vehicleid);
} 

forward _Evo_SetVehiclePrice(vehicleid, price);
public _Evo_SetVehiclePrice(vehicleid, price)
{
	return CallRemoteFunction("_SetVehiclePrice", "ii", vehicleid, price);
} 

forward _Evo_GetSystemIDFromVehicleID(vehicleid);
public _Evo_GetSystemIDFromVehicleID(vehicleid)
{
	return CallRemoteFunction("_GetSystemIDFromVehicleID", "i", vehicleid);
} 

forward _Evo_IsVehicleInSystem(vehicleid);
public _Evo_IsVehicleInSystem(vehicleid)
{
	return CallRemoteFunction("_IsVehicleInSystem", "i", vehicleid);
} 

forward _Evo_CreateVehicle(Modelid, Owner[], Float:X, Float:Y, Float:Z, Float:Rot, Col1, Col2, Price);
public _Evo_CreateVehicle(Modelid, Owner[], Float:X, Float:Y, Float:Z, Float:Rot, Col1, Col2, Price)
{
	return CallRemoteFunction("_CreateEvoVehicle", "isffffiii", Modelid, Owner, X, Y, Z, Rot, Col1, Col2, Price);
} 

forward _Evo_DeleteVehicle(vehicleid);
public _Evo_DeleteVehicle(vehicleid)
{
	return CallRemoteFunction("_DeleteVehicle", "i", vehicleid);
} 