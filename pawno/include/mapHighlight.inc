#if defined __INC_MAPHIGHLIGHT__
#endinput
#endif
#define __INC_MAPHIGHLIGHT__

/*

Map Highlighting Include by NaS

  With this include you can highlight areas on the ingame map.
  4 GangZones will quickly expand from the specified location, creating a ping effect.
  This ping effect can be customized, you can change the speed, distance, width, color, direction and delay.
  Since GangZones cannot actually be moved, the script repeatedly creates and destroys them to create a similar effect.
  In the current version only global GangZones are supported.

Functions:

  CreateMapHighlight(Float:x, Float:y, color, Float:distance, Float:width, interval, direction, max_steps, pause_time, playerid)

  x, y: 		the 2D position of the center
  color: 		RGBA color
  distance:		distance in m which the ping will travel
  width: 		the width of the zones in m
  interval: 	interval in ms in which the zones will be updated
  direction: 	positive values will move the zones away from the center, negative values will move them towards the center
  max_steps:	the total number of steps the zones will take (they travel 1 step per interval)
  pause_time: 	delay in ms for which the animation will pause after completing one iteration, 0 for none
  playerid: 	the PlayerID for which the zones will show, -1 for all players
  returns: 		ID of the MapHighlight, -1 if no free slot was found

  DestroyMapHighlight(mhlid)

  mhlid: 		the ID of the MapHighlight to destroy
  returns: 		1 if it was valid, 0 if not

  IsValidMapHighlight(mhlid)

  mhlid: 		the ID of the MapHighlight
  returns: 		1 if it is valid, 0 if not

  SetMapHighlightPlayerID(mhlid, playerid)

  mhlid:		the ID to set the PlayerID of
  playerid:		the PlayerID to show the zones to, -1 for all players

*/
//

#define MAX_MAP_HIGHLIGHTS				100

//

static enum E_MAP_HIGHLIGHT
{
	mhl_Used,

	Float:mhl_X,
	Float:mhl_Y,
	mhl_Color,
	Float:mhl_Distance,
	Float:mhl_Width,
	mhl_Interval,
	mhl_Direction,
	mhl_MaxStep,
	mhl_PauseTime,
	mhl_PlayerID,
	
	mhl_Step,
	mhl_Tick,

	mhl_GZIDs[4],
	mhl_TimerID,
};

static g_MapHighlights[MAX_MAP_HIGHLIGHTS][E_MAP_HIGHLIGHT];

//

forward mhl_UpdateMapHighlight(mhlid);

//

public mhl_UpdateMapHighlight(mhlid)
{
	new tick = GetTickCount(),
		pause_time = g_MapHighlights[mhlid][mhl_PauseTime],
		max_steps = g_MapHighlights[mhlid][mhl_MaxStep],
		pause_step = g_MapHighlights[mhlid][mhl_Direction] > 0 ? 0 : max_steps - 1,
		playerid = g_MapHighlights[mhlid][mhl_PlayerID];

	if(playerid != -1 && !IsPlayerConnected(playerid)) return 1;

	if(g_MapHighlights[mhlid][mhl_Step] == pause_step && pause_time > 0)
	{
		new dif = tick - g_MapHighlights[mhlid][mhl_Tick];

		if(dif < pause_time)
		{
			for(new i = 0; i < 4; i ++)
			{
				if(g_MapHighlights[mhlid][mhl_GZIDs][i] != -1)
				{
					GangZoneDestroy(g_MapHighlights[mhlid][mhl_GZIDs][i]);
					g_MapHighlights[mhlid][mhl_GZIDs][i] = -1;
				}
			}

			return 1;
		}
	}

	for(new i = 0; i < 4; i ++)
	{
		new Float:maxx, Float:maxy, Float:minx, Float:miny;
		//(side, step, max_steps, Float:distance, Float:width, Float:x, Float:y, &Float:minx, &Float:miny, &Float:maxx, &Float:maxy)
		GetMapHighlightPosForStep(i, g_MapHighlights[mhlid][mhl_Step], g_MapHighlights[mhlid][mhl_MaxStep], g_MapHighlights[mhlid][mhl_Distance], g_MapHighlights[mhlid][mhl_Width], g_MapHighlights[mhlid][mhl_X], g_MapHighlights[mhlid][mhl_Y], minx, miny, maxx, maxy);

		if(g_MapHighlights[mhlid][mhl_GZIDs][i] != -1)
		{
			GangZoneDestroy(g_MapHighlights[mhlid][mhl_GZIDs][i]);
			g_MapHighlights[mhlid][mhl_GZIDs][i] = -1;
		}

		if(playerid != -1)
		{
			g_MapHighlights[mhlid][mhl_GZIDs][i] = GangZoneCreate(minx, miny, maxx, maxy);
			GangZoneShowForPlayer(g_MapHighlights[mhlid][mhl_PlayerID], g_MapHighlights[mhlid][mhl_GZIDs][i], g_MapHighlights[mhlid][mhl_Color]);
		}
		else
		{
			g_MapHighlights[mhlid][mhl_GZIDs][i] = GangZoneCreate(minx, miny, maxx, maxy);
			GangZoneShowForAll(g_MapHighlights[mhlid][mhl_GZIDs][i], g_MapHighlights[mhlid][mhl_Color]);
		}
	}

	g_MapHighlights[mhlid][mhl_Step] += g_MapHighlights[mhlid][mhl_Direction];

	if(g_MapHighlights[mhlid][mhl_Step] >= max_steps)
	{
		g_MapHighlights[mhlid][mhl_Step] = 0;

		g_MapHighlights[mhlid][mhl_Tick] = tick;
	}
	else if(g_MapHighlights[mhlid][mhl_Step] < 0)
	{
		g_MapHighlights[mhlid][mhl_Step] = max_steps - 1;

		g_MapHighlights[mhlid][mhl_Tick] = tick;
	}

	return 1;
}

//

stock IsValidMapHighlight(mhlid)
{
	if(mhlid < 0 || mhlid >= MAX_MAP_HIGHLIGHTS || !g_MapHighlights[mhlid][mhl_Used])
	{
		return 0;
	}

	return 1;
}

stock CreateMapHighlight(Float:x, Float:y, color, Float:distance = 300.0, Float:width = 20.0, interval = 150, direction = 1, max_steps = 10, pause_time = 0, playerid = -1)
{
	new mhlid = -1;
	for(new i = 0; i < MAX_MAP_HIGHLIGHTS; i ++) if(!g_MapHighlights[i][mhl_Used])
	{
		mhlid = i;
		break;
	}

	if(mhlid == -1) return -1;

	g_MapHighlights[mhlid][mhl_Used] = 1;

	g_MapHighlights[mhlid][mhl_X] = x;
	g_MapHighlights[mhlid][mhl_Y] = y;
	g_MapHighlights[mhlid][mhl_Color] = color;
	g_MapHighlights[mhlid][mhl_Distance] = distance;
	g_MapHighlights[mhlid][mhl_Width] = width;
	g_MapHighlights[mhlid][mhl_Interval] = interval;
	g_MapHighlights[mhlid][mhl_Direction] = (direction == 0 ? 1 : direction);
	g_MapHighlights[mhlid][mhl_MaxStep] = (max_steps < 1 ? 1 : max_steps);
	g_MapHighlights[mhlid][mhl_PauseTime] = (pause_time > 0 ? pause_time + interval : 0);
	g_MapHighlights[mhlid][mhl_PlayerID] = playerid;

	g_MapHighlights[mhlid][mhl_Step] = (direction < 0 ? max_steps - 1 : 0);

	g_MapHighlights[mhlid][mhl_Tick] = GetTickCount();

	g_MapHighlights[mhlid][mhl_TimerID] = SetTimerEx("mhl_UpdateMapHighlight", interval, 1, "i", mhlid);
	g_MapHighlights[mhlid][mhl_GZIDs] = {-1, -1, -1, -1};

	return mhlid;
}

stock DestroyMapHighlight(mhlid)
{
	if(!IsValidMapHighlight(mhlid)) return 0;

	g_MapHighlights[mhlid][mhl_Used] = 0;

	KillTimer(g_MapHighlights[mhlid][mhl_TimerID]);

	for(new i = 0; i < 4; i ++)
	{
		if(g_MapHighlights[mhlid][mhl_GZIDs][i] != -1)
		{
			GangZoneDestroy(g_MapHighlights[mhlid][mhl_GZIDs][i]);
		}
	}

	return 1;
}

stock SetMapHighlightPlayerID(mhlid, playerid)
{
	if(!IsValidMapHighlight(mhlid) || playerid < -1 || playerid >= MAX_PLAYERS) return 0;

	g_MapHighlights[mhlid][mhl_PlayerID] = playerid;

	return 1;
}

//

// Calculates the coordinates for all 4 zones by an arbitrary id, it also avoids overlapping the zones in the squares's corners

static stock GetMapHighlightPosForStep(side, step, max_steps, Float:distance, Float:width, Float:x, Float:y, &Float:minx, &Float:miny, &Float:maxx, &Float:maxy)
{
	new const 	Float:step_dist = distance / float(max_steps);
	new const 	Float:hwidth = width / 2.0;

	new 		Float:dist = (step + 1) * step_dist;

	switch(side)
	{
		case 0: // N
		{
			minx = x - dist - hwidth;
			maxx = x + dist + hwidth;

			miny = y + dist - hwidth;
			maxy = y + dist + hwidth;
		}

		case 1: // E
		{
			minx = x + dist - hwidth;
			maxx = x + dist + hwidth;

			miny = y - dist + hwidth;
			maxy = y + dist - hwidth;
		}

		case 2: // S
		{
			minx = x - dist - hwidth;
			maxx = x + dist + hwidth;

			miny = y - dist - hwidth;
			maxy = y - dist + hwidth;
		}

		case 3: // W
		{
			minx = x - dist - hwidth;
			maxx = x - dist + hwidth;

			miny = y - dist + hwidth;
			maxy = y + dist - hwidth;
		}
	}

	return 1;
}

// 

// EOF