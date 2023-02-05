//AutoPilot script by Gamer_Z v0.2
#include <a_samp>//SA:MP Team
#define FILTERSCRIPT
#include <RouteConnector>//GPS Plugin
#include <Pawn.CMD>//By Zeex
////////////////////////////////////////////////////////////////////////////////
//#define USE_TIMERS
#define USE_SMOOTH_TURNS // thanks to richardcor91 for the SetVehicleAngularVelocity help
////////////////////////////////////////////////////////////////////////////////
new id[MAX_PLAYERS] = {-1,...};
new CurrTarget[MAX_PLAYERS] = {0,...};
new Timer[MAX_PLAYERS] = {-1,...};
new Float:spd[MAX_PLAYERS] = {0.30,...};
#if defined USE_TIMERS
new interval[MAX_PLAYERS] = {250,...};
#endif
////////////////////////////////////////////////////////////////////////////////

forward Float:atan2VehicleZ(Float:Xb,Float:Yb,Float:Xe,Float:Ye);// Dunno how to name it...

enum location
{
	name[16],
	Float:X,
	Float:Y,
	Float:Z
}

#define PLACES (6)
new places[PLACES][location] =
{
	{"LV-c",2140.6675,993.1867,10.5248},//Las Venturas
	{"SF-c",-2261.2009,564.2894,34.7200},//San Frierro
	{"LS-c",2495.3755,-1669.4906,13.5163},//Los Santos
	{"LV-a",1686.3107,1609.5485,10.8203},//Las Venturas Airport
	{"SF-a",-1538.8635,-422.9142,5.8516},//San Frierro Airport
	{"LS-a",1953.5204,-2290.1130,13.5469}//Los Santos Airport
};
////////////////////////////////////////////////////////////////////////////////
CMD:autopilot(playerid,params[])
{
	if(!IsPlayerInAnyVehicle(playerid))
	{
		SendClientMessage(playerid,-1,"AUTOPILOT YOU MUST BE IN A VEHICLE");
	    return 1;
	}
	if(!strcmp(params,"stop",true))
	{
		if(Timer[playerid] != (-1))
		{
		    #if defined USE_TIMERS
		    KillTimer(Timer[playerid]);
		    #endif
		    Timer[playerid] = -1;
		    DeleteArray(id[playerid]);
		    id[playerid] = -1;
		    CurrTarget[playerid] = 0;
		    SendClientMessage(playerid,-1,"AUTOPILOT DISABLED");
		    return 1;
		}
		SendClientMessage(playerid,-1,"AUTOPILOT COULDN'T BE DISABLED");
	    return 1;
	}
	if(params[0] == 48 && params[1] == 46)
	{
	    if(id[playerid] == -1)
	    {
			new out[32];
			if(!isNumeric(params[2]))
			{
			    SendClientMessage(playerid,-1,"AUTOPILOT SPEED MUST BE BETWEEN 0.01 and 0.80");
			    return 1;
			}
			if(!isNumeric(params[3]))
				params[3] = 48;
			format(out,32,"%c%c",params[2],params[3]);
			new Float:tmpspd = floatdiv(strval(out),100.00);
			if(0.01 > tmpspd > 0.80)
			{
			    SendClientMessage(playerid,-1,"AUTOPILOT SPEED MUST BE BETWEEN 0.01 and 0.80");
			    return 1;
			}
	        spd[playerid] = tmpspd;
	        format(out,32,"AUTOPILOT SPEED SET TO: %.3f",spd[playerid]);
	        SendClientMessage(playerid,-1,out);
		}
		else
		{
			SendClientMessage(playerid,-1,"AUTOPILOT CANNOT CHANGE SPEED WHILE DRIVING (bug prevention)");
		}
        return 1;
	}
	
    if(id[playerid] == -1)
    {
        if (params[0] == 0 || (params[0] == 1 && params[1] == 0))
        {
            SendClientMessage(playerid,-1,"AUTOPILOT HAS NO TARGET");
            return 1;
        }
        new place = -1;
        for(new i = 0; i < PLACES; ++i)
        {
            if(!strcmp(places[i][name],params,true))
            {
                place = i;
                break;
            }
        }
        if(place == -1)
        {
            SendClientMessage(playerid,-1,"AUTOPILOT DOESN'T KNOW THAT PLACE");
            return 1;
        }
        new start = NearestPlayerNode(playerid,15.0);
        if(start == -1)
        {
            SendClientMessage(playerid,-1,"AUTOPILOT MALFUNCTION, PLEASE TRY AGAIN ON ANOTHER PLACE");
            return 1;
        }
		CalculatePath(start,NearestNodeFromPoint(places[place][X],places[place][Y],places[place][Z]),playerid);
		SendClientMessage(playerid,-1,"AUTOPILOT IS CALCULATING THE ROUTE FOR YOU..");
		return 1;
	}
 	SendClientMessage(playerid,-1,"AUTOPILOT ALREADY TURNED ON");
    return 1;
}

// CMD:ap(playerid,params[])
// {
//     return cmd_autopilot(playerid,params);
// }

stock isNumeric(const string[])
{
  new length=strlen(string);
  if (length==0) return false;
  for (new i = 0; i < length; i++)
	{
	  if (
			(string[i] > '9' || string[i] < '0' && string[i]!='-' && string[i]!='+') // Not a number,'+' or '-'
			 || (string[i]=='-' && i!=0)                                             // A '-' but not at first.
			 || (string[i]=='+' && i!=0)                                             // A '+' but not at first.
		 ) return false;
	}
  if (length==1 && (string[0]=='-' || string[0]=='+')) return false;
  return true;
}

#if defined USE_TIMERS
CMD:interval(playerid,params[])
{
    interval[playerid] = strval(params);
    format(string,128,"Interval: %d",interval);
    SendClientMessage(playerid,-1,string);
    return 1;
}
#endif
////////////////////////////////////////////////////////////////////////////////
public GPS_WhenRouteIsCalculated(routeid,node_id_array[],amount_of_nodes,Float:distance,Float:Polygon[],Polygon_Size,Float:NodePosX[],Float:NodePosY[],Float:NodePosZ[])
{
	id[routeid] = StoreRouteArray(amount_of_nodes,node_id_array);
    #if defined USE_TIMERS
	Timer[routeid] = SetTimerEx("AutoPilot",interval[routeid],1,"i",routeid);
	#else
    Timer[routeid] = 1;
    #endif
    SendClientMessage(routeid,-1,".. AUTOPILOT WILL DRIVE YOU NOW TO YOUR DESTINATION");
	return 1;
}

#if defined USE_TIMERS

#else
public OnPlayerUpdate(playerid)
{
	if(Timer[playerid] == 1)
		AutoPilot(playerid);
	return 1;
}
#endif

public OnPlayerConnect(playerid)
{
    Timer[playerid] = -1;
    id[playerid] = -1;
    CurrTarget[playerid] = 0;
    #if defined USE_TIMERS
    interval[playerid] = 250;
    #endif
	return 1;
}

public OnPlayerDisconnect(playerid,reason)
{
	if(Timer[playerid] != (-1))
	{
	    #if defined USE_TIMERS
	    KillTimer(Timer[playerid]);
	    #endif
	    Timer[playerid] = -1;
	    DeleteArray(id[playerid]);
	    id[playerid] = -1;
	    CurrTarget[playerid] = 0;
	}
	return 1;
}

forward AutoPilot(playerid);
public AutoPilot(playerid)
{
	if(IsPlayerInAnyVehicle(playerid))
	{
	    new Float:pos[2][3];
	    new vehicleid = GetPlayerVehicleID(playerid);
	    if(CurrTarget[playerid] == 0)
	    {
	        CurrTarget[playerid]++;
	        GetNodePos(GetRouteAtPos(id[playerid],CurrTarget[playerid]),pos[0][0],pos[0][1],pos[0][2]);
	        SetVehiclePos(vehicleid,pos[0][0],pos[0][1],pos[0][2]+2.0);
	        return 1;
	    }
	    new amount;
		new nodeid = GetRouteAtPos(id[playerid],CurrTarget[playerid],amount);
		if((CurrTarget[playerid]+1) >= amount)
		{
		    #if defined USE_TIMERS
		    KillTimer(Timer[playerid]);
		    #endif
		    Timer[playerid] = -1;
		    DeleteArray(id[playerid]);
		    id[playerid] = -1;
		    CurrTarget[playerid] = 0;
		    SetVehicleVelocity(vehicleid,0.0,0.0,0.0);
		    SendClientMessage(playerid,-1,"Destination reached, have a nice day.");
		    return 1;
		}
        GetNodePos(nodeid,pos[1][0],pos[1][1],pos[1][2]);
        if(IsPlayerInRangeOfPoint(playerid,10.0,pos[1][0],pos[1][1],pos[1][2]))
        {
            CurrTarget[playerid]++;
            return 1;
        }
       	PullVehicleIntoDirection(vehicleid,pos[1][0],pos[1][1],pos[1][2],spd[playerid]);
	}
	else
	{
	    #if defined USE_TIMERS
	    KillTimer(Timer[playerid]);
	    #endif
	    Timer[playerid] = -1;
	    DeleteArray(id[playerid]);
	    id[playerid] = -1;
	    CurrTarget[playerid] = 0;
	}
	return 1;
}
//--------------------AUTO-PILOT-CORE-FUNCTIONS-------------------------------//
#define DEPRECATE_Z
stock PullVehicleIntoDirection(vehicleid, Float:x, Float:y, Float:z, Float:speed)//Thanks to Miguel for supplying me with this function, I have edited it a bit
{
	new
        Float:distance,
        Float:vehicle_pos[3];

    GetVehiclePos(vehicleid, vehicle_pos[0], vehicle_pos[1], vehicle_pos[2]);
	#if defined USE_SMOOTH_TURNS
	new Float: oz = atan2VehicleZ(vehicle_pos[0], vehicle_pos[1], x, y);
	new Float: vz;
	GetVehicleZAngle(vehicleid, vz);
	if(oz < vz-180) oz = oz+360;
	if(vz < oz-180) vz = vz+360;
	new Float: cz = floatabs(vz - oz);
	#else
	SetVehicleZAngle(vehicleid, atan2VehicleZ(vehicle_pos[0], vehicle_pos[1], x, y));
	#endif
    x -= vehicle_pos[0];
    y -= vehicle_pos[1];
    z -= vehicle_pos[2];
    #if defined DEPRECATE_Z
    distance = floatsqroot((x * x) + (y * y));
    x = (speed * x) / distance;
    y = (speed * y) / distance;
    GetVehicleVelocity(vehicleid, vehicle_pos[0], vehicle_pos[0], z);
    #else
    z+=0.11;
    distance = floatsqroot((x * x) + (y * y) + (z * z));
    x = (speed * x) / distance;
    y = (speed * y) / distance;
    z = (speed * z) / distance;
    #endif
	#if defined USE_SMOOTH_TURNS
	if(cz > 0)
 	{
		new Float: fz = cz*0.0015;
		if(vz < oz) SetVehicleAngularVelocity(vehicleid, 0.0, 0.0, fz);
		if(vz > oz) SetVehicleAngularVelocity(vehicleid, 0.0, 0.0, -fz);
	}
	#endif
    SetVehicleVelocity(vehicleid, x, y, z);
}

stock Float:atan2VehicleZ(Float:Xb,Float:Yb,Float:Xe,Float:Ye)
{
	new Float:a = floatabs(360.0 - atan2( Xe-Xb,Ye-Yb));
	if(360.0 > a > 180.0) return a;
	return a-360.0;
}
//----------------------------------------------------------------------------//
