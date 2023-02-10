stock OnGuardNormalWeaponShotTime(weaponid)
{
	new 
		TIME_SHOT;
		
	switch(weaponid)
	{
		case 0..8, 10..15: 		TIME_SHOT = 250;
		case 9: 				TIME_SHOT = 30;
		case 16..18:			TIME_SHOT = 0;
		case 19..20:			TIME_SHOT = 20;
		case 21:				TIME_SHOT = 0;
		case 22:				TIME_SHOT = 160;
		case 23..24:			TIME_SHOT = 120;
		case 25:				TIME_SHOT = 700;
		case 26..27:			TIME_SHOT = 120;
		case 28:				TIME_SHOT = 50;
		case 29..31:			TIME_SHOT = 60;
		case 32:				TIME_SHOT = 50;
		case 33..34:			TIME_SHOT = 700;
		case 35..37:			TIME_SHOT = 0;
		case 38:				TIME_SHOT = 20;
		case 39..40:			TIME_SHOT = 0;
		case 41..42:			TIME_SHOT = 10;
		case 43..47:			TIME_SHOT = 0;
		case 48:				TIME_SHOT = 400;
	}
	return TIME_SHOT;
}

stock OnServerMaximalDamageWeapon(weaponid)
{
	new MAXIMAL_DAMAGE_DISTANCE;
	    
	if(weaponid >= 0 || weaponid <= 46)
	{
		switch(weaponid)
		{
		    case 0..15: 		MAXIMAL_DAMAGE_DISTANCE = 1;
		    case 19, 31:  		MAXIMAL_DAMAGE_DISTANCE = 70;
			case 20, 38:        MAXIMAL_DAMAGE_DISTANCE = 60;
			case 22..24:        MAXIMAL_DAMAGE_DISTANCE = 30;
			case 25, 27:        MAXIMAL_DAMAGE_DISTANCE = 40;
			case 26, 28:        MAXIMAL_DAMAGE_DISTANCE = 30;
			case 29, 32:     	MAXIMAL_DAMAGE_DISTANCE = 30;
			case 30:            MAXIMAL_DAMAGE_DISTANCE = 70;
			case 33:            MAXIMAL_DAMAGE_DISTANCE = 90;
			case 34:            MAXIMAL_DAMAGE_DISTANCE = 300;
			default: 			MAXIMAL_DAMAGE_DISTANCE = 0;
		}
		return MAXIMAL_DAMAGE_DISTANCE;
	}
	return 0;
}
stock OnServerSetPlayerPriorityHealth(targetid, weaponid)
{
//16-18 weapon ignore damage
//21 	weapon ignore damage
//35-36 weapon ignore damage
//39-40 weapon ignore damage
//43-45 weapon ignore damage
	new Float: TOTAL_PLAYER_DAMAGE;

	if(PLAYER_SYNC[targetid][PLAYER_ARMOUR] <= 0.00000)
	{
		TOTAL_PLAYER_DAMAGE = PLAYER_SYNC[targetid][PLAYER_HEALTH];
		switch(weaponid)
		{
			case 0..15: 	TOTAL_PLAYER_DAMAGE -= 3.0;
			case 19:    	TOTAL_PLAYER_DAMAGE -= 10.0;
			case 22, 29: 	TOTAL_PLAYER_DAMAGE -= 8.0;
			case 23, 32: 	TOTAL_PLAYER_DAMAGE -= 10.0;
			case 24, 38: 	TOTAL_PLAYER_DAMAGE -= 45.0;
			case 25..26:	TOTAL_PLAYER_DAMAGE -= 10.0;
			case 27: 		TOTAL_PLAYER_DAMAGE -= 5.0;
			case 28: 		TOTAL_PLAYER_DAMAGE -= 7.0;
			case 30..31:	TOTAL_PLAYER_DAMAGE -= 10.0;
			case 33:		TOTAL_PLAYER_DAMAGE -= 25.0;
			case 34:		TOTAL_PLAYER_DAMAGE -= 40.0;
			case 37:		TOTAL_PLAYER_DAMAGE -= 10.0;
			case 41..42:	TOTAL_PLAYER_DAMAGE -= 2.0;
			case 46:		TOTAL_PLAYER_DAMAGE -= 3.0;
			default: return true;
		}
		OnServerSendRpcHealth(targetid, TOTAL_PLAYER_DAMAGE);
	}
	if(PLAYER_SYNC[targetid][PLAYER_ARMOUR] > 0.00000)
	{
		switch(weaponid)
		{
			case 0..15: 	TOTAL_PLAYER_DAMAGE = 3.0;
			case 19:    	TOTAL_PLAYER_DAMAGE = 10.0;
			case 22, 29: 	TOTAL_PLAYER_DAMAGE = 8.0;
			case 23, 32: 	TOTAL_PLAYER_DAMAGE = 10.0;
			case 24, 38: 	TOTAL_PLAYER_DAMAGE = 45.0;
			case 25..26:	TOTAL_PLAYER_DAMAGE = 10.0;
			case 27: 		TOTAL_PLAYER_DAMAGE = 5.0;
			case 28: 		TOTAL_PLAYER_DAMAGE = 7.0;
			case 30..31:	TOTAL_PLAYER_DAMAGE = 10.0;
			case 33:		TOTAL_PLAYER_DAMAGE = 25.0;
			case 34:		TOTAL_PLAYER_DAMAGE = 40.0;
			case 37:		TOTAL_PLAYER_DAMAGE = 10.0;
			case 41..42:	TOTAL_PLAYER_DAMAGE = 2.0;
			case 46:		TOTAL_PLAYER_DAMAGE = 3.0;
			default: return true;
		}
		if(PLAYER_SYNC[targetid][PLAYER_ARMOUR] - TOTAL_PLAYER_DAMAGE > 0.0000)
		{
			PLAYER_SYNC[targetid][PLAYER_ARMOUR] -= TOTAL_PLAYER_DAMAGE;
			OnServerSendRpcArmour(targetid, PLAYER_SYNC[targetid][PLAYER_ARMOUR]);
		}
		else
		{
			new Float: DAMAGE_ARMOUR;
			PLAYER_SYNC[targetid][PLAYER_ARMOUR] = 0;
			SetPlayerArmour(targetid, 0);
			OnServerSendRpcArmour(targetid, PLAYER_SYNC[targetid][PLAYER_ARMOUR]);
			
			DAMAGE_ARMOUR = TOTAL_PLAYER_DAMAGE - PLAYER_SYNC[targetid][PLAYER_ARMOUR];
			OnServerSendRpcHealth(targetid, DAMAGE_ARMOUR);
		}
	}
	return true;
}