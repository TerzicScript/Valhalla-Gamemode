/*

GetPlayerAimedBodyPart include (v1.01) by Dinnozor

Detects if you shoot the head/arm/leg/torso of a player !

Feel free to share but please don't remove credits.

Credits :
	-wups for GetDistanceFromPointToLine
 	-Double-O-Seven for CrossProduct system
	-Nero3D for GetPlayerCameraWeaponVector

Thanks also to TheArcher, wups, Nanory for their help and contribution.

v2.0 :
-finally got this working as a real include
-greatly improved the accuracy thanks to Nero_3D GetPlayerCameraWeaponVector include that let me take the correct offset with Widescreen ON
-/widescreen command to let the player take the Widescreen ON/OFF mode. Being in Widescreen ON mode is no longer a problem since it doesn't make it easier to do headshots. Indeed, the script now checks if the player aims a point, no more just the coord on Z axis. Please note it is still working better with Widescreen OFF mode.

v1.01:
-made it easier to shoot the arm, which was almost impossible in the 1.0
-kind of found a solution about the widescreen on/off problem (thanks to Nanory on Samp Forums for reporting) : the script checks if the player has an "overcorrection" with the GetPlayerCameraFrontVector Z-coord (which was the case when the player used Widescreen). If so, it will put the player in a "Widescreen" mode.
Also (since all the values were got experimentally), it will make the inverse check with angle correction (still about the GetPlayerCameraFrontVector inaccuracy with other weapons than sniper rifle) to check if the player lacks of correction. So basically, if the player is not in Widescreen but the script detected so (because of any bug or a wrong calculation), the script will automatically put the player back in non-Widescreen mode.
Added some calculation to do that, and a PVar "Widescreen".
Moreover, please note the script will be more accurate without Widescreen.

More info here : http://forum.sa-mp.com/showthread.php?t=403713
Video here : http://www.youtube.com/watch?v=2Y4ngd_wpzY

*/

#include <a_samp>

#if defined GPABP
#endinput
#endif
#define GPABP

#define BP_HEAD 1
#define BP_BODY 0
#define BP_ARM 3
#define BP_LEG 2

#if !defined COLOR_LIGHTRED
#define COLOR_LIGHTRED 0xFF6347AA
#endif

forward Float:DistanceGPABP(Float:xA,Float:yA,Float:zA,Float:xB,Float:yB,Float:zB);

forward OnPlayerHeadshot(playerid,targetid,weaponid);
forward OnPlayerLegshot(playerid,targetid,weaponid);
forward OnPlayerArmshot(playerid,targetid,weaponid);

static
bool:GPA_OPC,
bool:GPA_OPTD,
bool:GPA_OPCT;

public OnPlayerCommandText(playerid,cmdtext[])
{
	if(!strcmp(cmdtext,"/widescreeneeeee",true))
	{
		//Let the player toggle the Widescreen mode ON/OFF, according to his settings.
		new ws=GetPVarInt(playerid,"Widescreen");
		if(ws==0)
		{
			SetPVarInt(playerid,"Widescreen",1);
			SendClientMessage(playerid,COLOR_LIGHTRED,"Widescreen ON");

		}
		else
		{
			SetPVarInt(playerid,"Widescreen",0);
			SendClientMessage(playerid,COLOR_LIGHTRED,"Widescreen OFF");

		}
		return 1;

	}
	if(GPA_OPCT)
	{
		return CallLocalFunction("GPA_OnPlayerCommandText","is",playerid,cmdtext);

	}
	return 0;
}

#if defined _ALS_OnPlayerCommandText
#undef OnPlayerCommandText
#else
#define _ALS_OnPlayerCommandText
#endif
#define OnPlayerCommandText GPA_OnPlayerCommandText

forward GPA_OnPlayerCommandText(playerid,cmdtext[]);

public Float:DistanceGPABP(Float:xA,Float:yA,Float:zA,Float:xB,Float:yB,Float:zB)
{
	new Float:Dist=floatsqroot((xB-xA)*(xB-xA)+(yB-yA)*(yB-yA)+(zB-zA)*(zB-zA));
	return Dist;
}

stock AdjustVector(& Float: vX, & Float: vY, & Float: vZ, Float: oX, Float: oY, const Float: oZ)
{
	// Credits Nero_3D
	static
	Float: Angle;
	Angle = -atan2(vX, vY);
	if(45.0 < Angle)
	{
		oX ^= oY;
		oY ^= oX;
		oX ^= oY;
		if(90.0 < Angle)
		{
			oX *= -1;
			if(135.0 < Angle)
			{
				oX *= -1;
				oX ^= oY;
				oY ^= oX;
				oX ^= oY;
				oX *= -1;

			}

		}

	}
	else if(Angle < 0.0)
	{
		oY *= -1;
		if(Angle < -45.0)
		{
			oX *= -1;
			oX ^= oY;
			oY ^= oX;
			oX ^= oY;
			oX *= -1;
			if(Angle < -90.0)
			{
				oX *= -1;
				if(Angle < -135.0)
				{
					oX ^= oY;
					oY ^= oX;
					oX ^= oY;

				}

			}

		}

	}
	vX += oX,
	vY += oY;
	vZ += oZ;
	return false;
}

stock GetPlayerCameraWeaponVector(playerid, & Float: vX, & Float: vY, & Float: vZ)
{
	// Credits Nero_3D. I just added the offset for Widescreen ON players
	static
	weapon;
	if(21 < (weapon = GetPlayerWeapon(playerid)) < 39)
	{
		GetPlayerCameraFrontVector(playerid, vX, vY, vZ);
		switch(weapon)
		{
			case WEAPON_SNIPER, WEAPON_ROCKETLAUNCHER, WEAPON_HEATSEEKER:
			{
			}
			case WEAPON_RIFLE:
			{
				if(GetPVarInt(playerid,"Widescreen")==0) AdjustVector(vX, vY, vZ, 0.016204, 0.009899, 0.047177);
				else AdjustVector(vX, vY, vZ, 0.015085, 0.010467, 0.035687);


			}

			case WEAPON_AK47, WEAPON_M4:
			{
				if(GetPVarInt(playerid,"Widescreen")==0) AdjustVector(vX, vY, vZ, 0.026461, 0.013070, 0.069079);
				else AdjustVector(vX, vY, vZ, 0.024255, 0.013714, 0.053342);


			}

			default:
			{
				if(GetPVarInt(playerid,"Widescreen")==0) AdjustVector(vX, vY, vZ, 0.043949, 0.015922, 0.103412);
				else AdjustVector(vX, vY, vZ, 0.041103, 0.014111, 0.079249);


			}

		}
		return true;

	}
	else
	GetPlayerCameraFrontVector(playerid, vX, vY, vZ);
	return false;
}

stock crossp(Float:v1x, Float:v1y, Float:v1z, Float:v2x, Float:v2y, Float:v2z, &Float:output)
{
	new
	Float:c1 = (v1y * v2z) - (v1z * v2y),
	Float:c2 = (v1z * v2x) - (v1x * v2z),
	Float:c3 = (v1x * v2y) - (v1y * v2x);
	output = floatsqroot ((c1 * c1) + (c2 * c2) + (c3 * c3));
	return 0;
}
stock GetDistanceFromPointToLine(&Float:distance, Float:line_vector_x, Float:line_vector_y, Float:line_vector_z, Float:line_x, Float:line_y, Float:line_z, Float:point_x, Float:point_y, Float:point_z)
{
	//A line is defined by a point (which is on the line (line_x/y/z)) and a vector which defines the direction (line_vector_x/y/z).
	static Float:output;
	crossp(line_vector_x, line_vector_y, line_vector_z, point_x - line_x, point_y - line_y, point_z - line_z, output);//Cross product of 2 vectors.
	distance = output / floatsqroot ((line_vector_x * line_vector_x) + (line_vector_y * line_vector_y) + (line_vector_z * line_vector_z));
	return 0;
}

stock GetPlayerAimedBodyPart(playerid, targetid, Float:range)
{
	new Float:xv,Float:yv,Float:zv,Float:xc,Float:yc,Float:zc,Float:zt,Float:X2,Float:Y2,Float:Z2;
	new Float:AngleP,Float:xP,Float:yP,Float:zP;
	new Float:DistH,Float:DistL,Float:DistA;
	GetPlayerPos(targetid,X2,Y2,Z2);
	GetPlayerPos(playerid,xP,yP,zP);
	GetPlayerCameraPos(playerid,xc,yc,zc);
	GetPlayerCameraWeaponVector(playerid,xv,yv,zv);
	GetPlayerFacingAngle(targetid,AngleP);

	zt=range*zv+zc;

	if(GetPlayerSpecialAction(targetid)==1)
	{
		GetDistanceFromPointToLine(DistH,xv,yv,zv,xc,yc,zc,X2,Y2,Z2-0.1);
		GetDistanceFromPointToLine(DistA,xv,yv,zv,xc,yc,zc,0.5*floatcos(-AngleP,degrees)+X2,Y2-0.5*floatsin(-AngleP,degrees),Z2-0.55);
		if(DistH<=0.2) return BP_HEAD;
		else if(DistA<=0.3) return BP_ARM;

	}
	else if(GetPlayerState(targetid)!=1)
	{
		if(Z2+0.4<=zt) return BP_HEAD;

	}
	else
	{
		GetDistanceFromPointToLine(DistH,xv,yv,zv,xc,yc,zc,X2,Y2,Z2+0.6);
		GetDistanceFromPointToLine(DistL,xv,yv,zv,xc,yc,zc,X2,Y2,Z2-0.4);
		GetDistanceFromPointToLine(DistA,xv,yv,zv,xc,yc,zc,0.5*floatcos(-AngleP,degrees)+X2,Y2-0.5*floatsin(-AngleP,degrees),Z2);
		if(DistH<=0.2) return BP_HEAD;
		else if(DistL<=0.5) return BP_LEG;
		else if(DistA<=0.4) return BP_ARM;

	}
	return BP_BODY;
}

public OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid)
{
	new Float:Xt,Float:Yt,Float:Zt;
	GetPlayerPos(playerid,Xt,Yt,Zt);
	if(issuerid!=INVALID_PLAYER_ID)

	{
		new Float:xc,Float:yc,Float:zc,Float:DistC;
		GetPlayerCameraPos(issuerid,xc,yc,zc);
		DistC=DistanceGPABP(xc,yc,zc,Xt,Yt,Zt);

		switch(GetPlayerAimedBodyPart(issuerid,playerid,DistC))

		{
			case BP_HEAD:CallLocalFunction("OnPlayerHeadshot", "ddd", issuerid,playerid,weaponid);
			case BP_LEG:CallLocalFunction("OnPlayerLegshot", "ddd", issuerid,playerid,weaponid);
			case BP_ARM:CallLocalFunction("OnPlayerArmshot", "ddd", issuerid,playerid,weaponid);
			//Create a call back for torso shots if you want : use default here


		}



	}
	if(GPA_OPTD)
	{
		return CallLocalFunction("GPA_OnPlayerTakeDamage","ddfd",playerid,issuerid,amount,weaponid);

	}
	return 1;
}

#if defined _ALS_OnPlayerTakeDamage
#undef OnPlayerTakeDamage
#else
#define _ALS_OnPlayerTakeDamage
#endif
#define OnPlayerTakeDamage GPA_OnPlayerTakeDamage

forward GPA_OnPlayerTakeDamage(playerid,issuerid,Float:amount,weaponid);

public OnPlayerConnect(playerid)
{
	//Let's tell the people to check their Display settings. You can also save this var in a file, if you don't want to make them check everytime...
	//SendClientMessage(playerid,COLOR_LIGHTRED,"Use /widescreen command to set your aim (if you use Widescreen ON). See your advanced display settings.");
	SetPVarInt(playerid,"Widescreen",0);//Assuming most of the people don't use Widescreen
	if(GPA_OPC)
	{
		return CallLocalFunction("GPA_OnPlayerConnect","d",playerid);

	}
	return 1;
}

#if defined _ALS_OnPlayerConnect
#undef OnPlayerConnect
#else
#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect GPA_OnPlayerConnect

forward GPA_OnPlayerConnect(playerid);

public OnGameModeInit()

{
	GPA_OPC=funcidx("GPA_OnPlayerConnect")!=-1;
	GPA_OPTD=funcidx("GPA_OnPlayerTakeDamage")!=-1;
	GPA_OPCT=funcidx("GPA_OnPlayerCommandText")!=-1;
	if(funcidx("GPA_OnGameModeInit")!=-1)
	{
		return CallLocalFunction("GPA_OnGameModeInit","");

	}
	return 1;

}
#if defined _ALS_OnGameModeInit
#undef OnGameModeInit
#else
#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit GPA_OnGameModeInit

forward GPA_OnGameModeInit();