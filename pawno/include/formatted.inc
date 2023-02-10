/*
	Formated Functions Include (formatted.inc)
	* Now make and use most used funcions with arguments! Fast and well optimized!
	* Create your own formated function in one line :)

 	Author: (creator)
	* Gammix

	Contributors:
	* Y_Less & Zeex - f_return initial code

	(c) Copyright 2015
  	* This file is provided as is (no warranties).
*/

/*
FUNCTIONS:
native f_input
native f_return(const fmat[], start);
native _
native SendClientMessagef(playerid, color, const message[], f_input);
native SendClientMessageToAllf(color, const message[], f_input);
native GameTextForPlayerf(playerid, const text[], expiretime, style, f_input);
native GameTextForAllf(const text[], expiretime, style, f_input);
native stock GameTextForPlayerf(playerid, const text[], expiretime, style, f_input);
native strcatf(dest[], const source[], maxlength = sizeof(dest), f_input);
native TextDrawSetStringf(Text:text, const string[], f_input);
native PlayerTextDrawSetStringf(playerid, PlayerText:text, const string[], f_input);
native ShowPlayerDialogf(playerid, dialogid, style, caption[], const info[], button1[], button2[], f_input);
*/

//start - it is the param count where the arguments are started
/* 	For example:

		stock SendClientMessagef(playerid, color, const fmat[], f_input)
				return SendClientMessage(playerid, color, f_return(fmat, 3));

	- Here f_input was placed at position number 3 (counting starting from 0 - whole numbers).
	- So we write 3 as the start param in f_return so as to detect the place!
*/
stock f_return(const fmat[], start)//credits to Y_Less and Zeex for this! & Edited by me
{
 	static
		f_out[200 * 5],
		f_size = 200,
		f_numargs,
		f_startarg,
		f_argend;

	#emit LOAD.S.pri   0
	#emit ADD.C        8
	#emit MOVE.alt

	#emit LOAD.I
	#emit STOR.S.pri   f_numargs

	#emit ADD
	#emit STOR.S.pri   f_argend

	#emit LOAD.S.pri   start
	#emit SMUL.C       4
	#emit ADD
	#emit STOR.S.pri   f_startarg

	while(f_argend != f_startarg)
	{
		#emit MOVE.pri
		#emit LOAD.I
		#emit PUSH.pri
		#emit CONST.pri    4
		#emit SUB.alt
		#emit STOR.S.pri   f_argend
	}

	#emit PUSH.S       fmat
	#emit PUSH         f_size
	#emit PUSH.C       f_out

	#emit LOAD.S.pri   f_numargs
	#emit ADD.C        12
	#emit LOAD.S.alt   start
	#emit XCHG
	#emit SMUL.C       4
	#emit SUB.alt
	#emit PUSH.pri
	#emit MOVE.alt

	#emit SYSREQ.C     format

	#emit CONST.pri    4
	#emit ADD
	#emit MOVE.alt

	#emit LCTRL        4
	#emit ADD
	#emit SCTRL        4

	return f_out;
}

#define f_input 	{ _, Float, Text3D, Menu, Text, DB, DBResult, bool, File, hex, bit, bit_byte, Bit }:...

stock SendClientMessagef(playerid, color, const message[], f_input)
		return SendClientMessage(playerid, color, f_return(message, 3));

stock SendClientMessageToAllf(color, const message[], f_input)
		return SendClientMessageToAllf(color, f_return(message, 2));

stock GameTextForPlayerf(playerid, const text[], expiretime, style, f_input)
		return GameTextForPlayer(playerid, f_return(text, 4), expiretime, style);

stock GameTextForAllf(const text[], expiretime, style, f_input)
		return GameTextForAll(f_return(text, 3), expiretime, style);
	
stock strcatf(dest[], const source[], maxlength = sizeof(dest), f_input)
		return strcat(dest, f_return(source, 3), maxlength);

stock TextDrawSetStringf(Text:text, const string[], f_input)
		return TextDrawSetString(text, f_return(string, 2));

stock PlayerTextDrawSetStringf(playerid, PlayerText:text, const string[], f_input)
		return PlayerTextDrawSetString(playerid, text, f_return(string, 3));
		
stock ShowPlayerDialogf(playerid, dialogid, style, caption[], const info[], button1[], button2[], f_input)
		return ShowPlayerDialog(playerid, dialogid, style, caption, f_return(info, 7), button1, button2);