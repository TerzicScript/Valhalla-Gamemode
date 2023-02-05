/*
	Poker filterscript by.: Zsolesszka
	2012.01.15 - 2012.01.27
*/

#include <a_samp>
#include <YSI\y_hooks>

#define POKERDIALOG 2222

enum
{
	TWO = 2,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE
};

enum
{
	HIGH_CARD = 0,
	ONE_PAIR,
	TWO_PAIR,
	THREE_OF_A_KIND,
	STRAIGHT,
	FLUSH,
	FULL_HOUSE,
	FOUR_OF_A_KIND,
	STRAIGHT_FLUSH,
	ROYAL_FLUSH
};

new
	rang_sor[][] =
{
	{"High card"},
	{"One Pair"},
	{"Two Pair"},
	{"Three of a Kind"},
	{"Straight"},
	{"Flush"},
	{"Full house"},
	{"Four of Kind"},
	{"Straight Flush"},
	{"Royal Flush"}
};

new
	LD_POKE[][] =
{
	{ "LD_POKE:cd2c" },
	{ "LD_POKE:cd3c" },
	{ "LD_POKE:cd4c" },
	{ "LD_POKE:cd5c" },
	{ "LD_POKE:cd6c" },
	{ "LD_POKE:cd7c" },
	{ "LD_POKE:cd8c" },
	{ "LD_POKE:cd9c" },
	{ "LD_POKE:cd10c" },
	{ "LD_POKE:cd11c" },
	{ "LD_POKE:cd12c" },
	{ "LD_POKE:cd13c" },
	{ "LD_POKE:cd1c" },

	{ "LD_POKE:cd2d" },
	{ "LD_POKE:cd3d" },
	{ "LD_POKE:cd4d" },
	{ "LD_POKE:cd5d" },
	{ "LD_POKE:cd6d" },
	{ "LD_POKE:cd7d" },
	{ "LD_POKE:cd8d" },
	{ "LD_POKE:cd9d" },
	{ "LD_POKE:cd10d" },
	{ "LD_POKE:cd11d" },
	{ "LD_POKE:cd12d" },
	{ "LD_POKE:cd13d" },
	{ "LD_POKE:cd1d" },

	{ "LD_POKE:cd2h" },
	{ "LD_POKE:cd3h" },
	{ "LD_POKE:cd4h" },
	{ "LD_POKE:cd5h" },
	{ "LD_POKE:cd6h" },
	{ "LD_POKE:cd7h" },
	{ "LD_POKE:cd8h" },
	{ "LD_POKE:cd9h" },
	{ "LD_POKE:cd10h" },
	{ "LD_POKE:cd11h" },
	{ "LD_POKE:cd12h" },
	{ "LD_POKE:cd13h" },
	{ "LD_POKE:cd1h" },

	{ "LD_POKE:cd2s" },
	{ "LD_POKE:cd3s" },
	{ "LD_POKE:cd4s" },
	{ "LD_POKE:cd5s" },
	{ "LD_POKE:cd6s" },
	{ "LD_POKE:cd7s" },
	{ "LD_POKE:cd8s" },
	{ "LD_POKE:cd9s" },
	{ "LD_POKE:cd10s" },
	{ "LD_POKE:cd11s" },
	{ "LD_POKE:cd12s" },
	{ "LD_POKE:cd13s" },
	{ "LD_POKE:cd1s" }
};

new
	HoldCardName[][] =
{
	{ "{e00909}holdon" },
	{ "{9c8c8c}holdoff" }
};

new
	HoldCardText[][] =
{
	{ "LD_POKE:holdon" },
	{ "LD_POKE:holdoff" },
	{ "LD_POKE:holdmid" }
};

new
	BackGroundData[][] =
{
	{ "LOADSUK:loadscuk" },
	{ "LOADSUK:loadsc9" },
	{ "LOADSUK:loadsc8" },
	{ "LOADSUK:loadsc7" },
	{ "LOADSUK:loadsc6" },
	{ "LOADSUK:loadsc5" },
	{ "LOADSUK:loadsc4" },
	{ "LOADSUK:loadsc3" },
	{ "LOADSUK:loadsc2" },
	{ "LOADSUK:loadsc14" },
	{ "LOADSUK:loadsc13" },
	{ "LOADSUK:loadsc12" },
	{ "LOADSUK:loadsc11" },
	{ "LOADSUK:loadsc10" },
	{ "LOADSUK:loadsc1" }
};

stock
	Card_Name[][] =
{
	"2c", "3c", "4c", "5c", "6c", "7c", "8c", "9c", "Tc", "Jc", "Qc", "Kc", "Ac",
	"2d", "3d", "4d", "5d", "6d", "7d", "8d", "9d", "Td", "Jd", "Qd", "Kd", "Ad",
	"2h", "3h", "4h", "5h", "6h", "7h", "8h", "9h", "Th", "Jh", "Qh", "Kh", "Ah",
	"2s", "3s", "4s", "5s", "6s", "7s", "8s", "9s", "Ts", "Js", "Qs", "Ks", "As"
};

new
	Card_Value[] =
{
	TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE,
	TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE,
	TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE,
	TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
};

new
	Bynary_Mask[] =
{
	1, 2, 4, 8, 0x10, 0x20, 0x40, 0x80, 0x100, 0x200, 0x400, 0x800, 0x1000,
	1, 2, 4, 8, 0x10, 0x20, 0x40, 0x80, 0x100, 0x200, 0x400, 0x800, 0x1000,
	1, 2, 4, 8, 0x10, 0x20, 0x40, 0x80, 0x100, 0x200, 0x400, 0x800, 0x1000,
	1, 2, 4, 8, 0x10, 0x20, 0x40, 0x80, 0x100, 0x200, 0x400, 0x800, 0x1000
//		2	3	4	5	6	7	8	9	T	J	Q	K	A
};

#define TREFF 		0b1 //1 // "clubs"
#define KARO 		0b10 //2 // “diamonds”
#define KOR 		0b100 //4 // “hearts”
#define PIKK 		0b1000 //8 // “spades” or “shields”

new
	Color_Mask[] =
{
	TREFF, TREFF, TREFF, TREFF, TREFF, TREFF, TREFF, TREFF, TREFF, TREFF, TREFF, TREFF, TREFF,	// 1 = 0b10
	KARO, KARO, KARO, KARO, KARO, KARO, KARO, KARO, KARO, KARO, KARO, KARO, KARO,		// 2 = 0b100
	KOR, KOR, KOR, KOR, KOR, KOR, KOR, KOR, KOR, KOR, KOR, KOR, KOR,						// 4 = 0b1000
	PIKK, PIKK, PIKK, PIKK, PIKK, PIKK, PIKK, PIKK, PIKK, PIKK, PIKK, PIKK, PIKK					// 8 = 0b10000
};

new
	pot[] = { 0, 0, 2, 3, 4, 5, 7, 20, 50, 250 };

new
	Text:BackGroundText[MAX_PLAYERS],
	Text:CardsText[MAX_PLAYERS][5],
	Text:HoldsText[MAX_PLAYERS][5],
	Text:WinText[MAX_PLAYERS],
	Text:BetCreditText[MAX_PLAYERS];

#define MIN_BET	5	// $5
#define MAX_BET	100 // $100

#define FIRST_DIVID 	(false)	// enable hold card
#define SECOND_DIVID	(true)	// disable hold card
#define HOLDON  	(false)
#define HOLDOFF	(true) // Not modified

forward TextDrawDizajn(playerid, index);
forward TextDrawDizajn2(playerid, win, One_pair, Two_pair);

enum
	Poker_PlayerInfoEnum
{
	bool:PokerAktive,
	fivecards_hand[10],
	bool:holdstate[5],
	bool:hold,
	Bet,
	Credit
};

new
	PP_Info[MAX_PLAYERS][Poker_PlayerInfoEnum];

public
	OnFilterScriptInit()
{
	print("\nPoker filterscript loaded.\n\t * * * Created by Zsolesszka * * *\n");
	new a[][15] =   //Antideamx
	{ "?","?" };    // -===-
	#pragma unused a // -===-
	return 1;
}

public
	OnFilterScriptExit()
{
	for(new i; i < MAX_PLAYERS; i++)
	{
		if(BackGroundText[i] != Text:INVALID_TEXT_DRAW)
		{	
			Delete_PokerTextDraw(i);
		}
	}
    return 1;
}

public
	OnPlayerConnect(playerid)
{
	BackGroundText[playerid] = Text:INVALID_TEXT_DRAW;
	WinText[playerid] = Text:INVALID_TEXT_DRAW;
	BetCreditText[playerid] = Text:INVALID_TEXT_DRAW;
	for(new i; i < 5; i++)
	{
		CardsText[playerid][i] = Text:INVALID_TEXT_DRAW;
		HoldsText[playerid][i] = Text:INVALID_TEXT_DRAW;
	}
	return 1;
}

public
	OnPlayerDisconnect(playerid, reason)
{
	if(BackGroundText[playerid] != Text:INVALID_TEXT_DRAW)
	{
		Delete_PokerTextDraw(playerid);
	}
	return 1;
}

public
	OnPlayerCommandText(playerid, cmdtext[])
{
	new
		idx,
		cmd[20];
	cmd = strtok(cmdtext, idx);
	if(strcmp("/poker", cmd, true) == 0)
	{
		Create_PokerTextDraw(playerid);
		cmd = strtok(cmdtext, idx);
		new
			credit = strval(cmd);
		if(strlen(cmd) == 0) SendClientMessage(playerid, -1, "{008888}Usage: {ffffff}/poker [0-100000]");
		else if(GetPlayerMoney(playerid) < credit) return SendClientMessage(playerid, -1, "Not have enough money.");
		else if(credit < 5 || credit > 100000) return SendClientMessage(playerid, -1, "{008888}Usage: {ffffff}/poker [0-100000]");
		else
		{
			PP_Info[playerid][Credit] = credit;
			GivePlayerMoney(playerid, -credit);
			TogglePlayerControllable(playerid, false);
			PP_Info[playerid][Bet] = MIN_BET;
			PP_Info[playerid][hold] = FIRST_DIVID;

			TextDrawShowForPlayer(playerid, BackGroundText[playerid]);
			TextDrawShowForPlayer(playerid, WinText[playerid]);
			TextDrawShowForPlayer(playerid, BetCreditText[playerid]);
			BetCredit(playerid);
			WinnText(playerid, 0);

			for(new i; i < 5; i++)
			{
				PP_Info[playerid][fivecards_hand][i] = 0;
				PP_Info[playerid][fivecards_hand][i + 5] = 0;
				PP_Info[playerid][holdstate][i] = HOLDOFF;
				TextDrawSetString(CardsText[playerid][i], "LD_TATT:8poker"); //"LD_POKE:backred");
				TextDrawSetString(HoldsText[playerid][i], "LD_POKE:holdon");
				TextDrawShowForPlayer(playerid, CardsText[playerid][i]);
				TextDrawShowForPlayer(playerid, HoldsText[playerid][i]);
			}
			CreditBet_Dialog(playerid, "Enjoy ..");
		}
		return 1;
	}
	return 0;
}

stock
	Poker_Dialog(playerid, str[])
{
	new
		p_str[512];
	format(p_str, sizeof p_str, " {0c58c4}Deal\n 1:%s\n 2:%s\n 3:%s\n 4:%s\n 5:%s\n",
													HoldCardName[PP_Info[playerid][holdstate][0]],
													HoldCardName[PP_Info[playerid][holdstate][1]],
													HoldCardName[PP_Info[playerid][holdstate][2]],
													HoldCardName[PP_Info[playerid][holdstate][3]],
													HoldCardName[PP_Info[playerid][holdstate][4]]);
	ShowPlayerDialog(playerid, POKERDIALOG, DIALOG_STYLE_LIST, str, p_str, "Select", "");
	return 1;
}

stock
	CreditBet_Dialog(playerid, str[])
{
	ShowPlayerDialog(playerid, POKERDIALOG, DIALOG_STYLE_LIST, str, "{0c58c4}Deal\n{d0dee0}Bet\t+5\nBet\t-5\nCredit\t+100\nCredit\t+500\n{ffff11}Background", "Select", "Exit");
	return 1;
}

public
	OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	printf("Usao u ODR");
	if(dialogid == POKERDIALOG)
	{
		if(response)
		{
			new
				One_pair,
				Two_pair,
				win;
			if(PP_Info[playerid][hold] == FIRST_DIVID)
			{
//--+
				switch(listitem)
				{
					case 1: // Bet+
					{
						if(PP_Info[playerid][Bet] < 100)
						{
							PP_Info[playerid][Bet] += 5;
							BetCredit(playerid);
							WinnText(playerid, 0);
						}
						CreditBet_Dialog(playerid, " ");
						return 1;
					}
					case 2: // Bet-
					{
						if(PP_Info[playerid][Bet] > 5)
						{
							PP_Info[playerid][Bet] -= 5;
							BetCredit(playerid);
							WinnText(playerid, 0);
						}
						CreditBet_Dialog(playerid, " ");
						return 1;
					}
					case 3,4: // Credit +100 / Credit +500
					{
						new
							credit_[] = { 100, 500 };
						if(GetPlayerMoney(playerid) < credit_[listitem - 3])
						{
							CreditBet_Dialog(playerid, "{cc1212}You have no money.");
						} else {
							GivePlayerMoney(playerid, -credit_[listitem - 3]);
							PP_Info[playerid][Credit] += credit_[listitem - 3];
							BetCredit(playerid);
							CreditBet_Dialog(playerid, " ");
						}
						return 1;
					}
					case 5:
					{
						TextDrawSetString(BackGroundText[playerid], BackGroundData[random(sizeof BackGroundData)]);
						CreditBet_Dialog(playerid, "{ffff11}Changed background.");
						return 1;
					}
				}
//--+
				if(PP_Info[playerid][Credit] < PP_Info[playerid][Bet]) return CreditBet_Dialog(playerid, "No Credit.");
//--+
				PP_Info[playerid][Credit] -= PP_Info[playerid][Bet];
				PP_Info[playerid][hold] = SECOND_DIVID;
				PlaySound(playerid, 43000);
//--+
				do
				{
					RandomNumber(52, PP_Info[playerid][fivecards_hand], 10); // Pawn sizeof() does not work enum array
				}
				while(HasDuplicateValues(PP_Info[playerid][fivecards_hand], 10)); // Pawn sizeof() does not work enum array
//--+
				WinnText(playerid, 0);
				BetCredit(playerid);
				TextDrawDizajn(playerid, 0);
//--+
			} else {
//--+
				if(listitem > 0 && listitem < 6)
				{
					PP_Info[playerid][holdstate][listitem - 1] = HOLDOFF - PP_Info[playerid][holdstate][listitem - 1];
					TextDrawSetString(HoldsText[playerid][listitem - 1], HoldCardText[PP_Info[playerid][holdstate][listitem - 1]]);
					PlaySound(playerid, 21000); //43000);
					Poker_Dialog(playerid, "Card select");
					return 1;
				}
//--+
				PP_Info[playerid][hold] = FIRST_DIVID;
//--+
				for(new i; i < 5; i++)
				{
					if(PP_Info[playerid][holdstate][i] == HOLDON)
					{
						TextDrawSetString(HoldsText[playerid][i], "LD_POKE:holdoff");
						PP_Info[playerid][holdstate][i] = HOLDOFF;
					} else {
						Swap(PP_Info[playerid][fivecards_hand][i], PP_Info[playerid][fivecards_hand][i + 5]);
						TextDrawSetString(CardsText[playerid][i], LD_POKE[PP_Info[playerid][fivecards_hand][i]]);
					}
				}
//--+
				win = getwin(PP_Info[playerid][fivecards_hand], One_pair, Two_pair);
//--+
				if(win > ONE_PAIR)
				{
//--+
					PP_Info[playerid][Credit] += (pot[win] * PP_Info[playerid][Bet]);
//--+
					new
						str[128];
					format(str, sizeof str, "Win:{00a6ff}%s | $%d", rang_sor[win], pot[win] * PP_Info[playerid][Bet]);
					CreditBet_Dialog(playerid, str);
//--+
					switch(win)
					{
						case STRAIGHT, FLUSH, STRAIGHT_FLUSH, FULL_HOUSE, ROYAL_FLUSH:
						{
							for(new i = 0; i < 5; i++)
							{
								TextDrawSetString(HoldsText[playerid][i], "LD_POKE:holdmid");
							}
						}
						case TWO_PAIR:
						{
							for(new i = 0; i < 5; i++)
							{
								if( Card_Value[One_pair] == Card_Value[PP_Info[playerid][fivecards_hand][i]] ||
									Card_Value[Two_pair] == Card_Value[PP_Info[playerid][fivecards_hand][i]])
								{
									TextDrawSetString(HoldsText[playerid][i], "LD_POKE:holdmid");
								}
							}
						}
						case ONE_PAIR, FOUR_OF_A_KIND, THREE_OF_A_KIND:
						{
							for(new i = 0; i < 5; i++)
							{
								if(Card_Value[One_pair] == Card_Value[PP_Info[playerid][fivecards_hand][i]])
								{
									TextDrawSetString(HoldsText[playerid][i], "LD_POKE:holdmid");
								}
							}
						}
					}
					PlaySound(playerid, 43001); //30800); //5448);
					WinnText(playerid, win);
					BetCredit(playerid);
//--+
				} else {
//--+
					for(new i = 0; i < 5; i++)
					{
						TextDrawSetString(HoldsText[playerid][i], "LD_POKE:holdoff");
					}
//--+
					CreditBet_Dialog(playerid, "No win.");
//--+
				}
			}
		} else {
//--+

			Delete_PokerTextDraw(playerid);
//--+
			TogglePlayerControllable(playerid, true);
//--+
			GivePlayerMoney(playerid, PP_Info[playerid][Credit]);
			new
				str[128];
			format(str, sizeof str, "Thank you using the {ffffff}¤ [Fs]Poker script by.: Zsolesszka ¤{22a4b5} Add money : {ffffff}$%d", PP_Info[playerid][Credit]);
			SendClientMessage(playerid, 0x22a4b5AA, str);
//--+
		}
		return 1;
	}
	return 0;
}

stock
	getwin(const cards[], &One_Pair_Type, &Two_Pair_Type)
{
	new
		i = 0,
		getcolor,
		straight;

	getcolor = Color_Mask[cards[0]] | Color_Mask[cards[1]] | Color_Mask[cards[2]] | Color_Mask[cards[3]] | Color_Mask[cards[4]];
	getcolor = getcolor & (getcolor - 1);

	straight = (Bynary_Mask[cards[0]] | Bynary_Mask[cards[1]] | Bynary_Mask[cards[2]] | Bynary_Mask[cards[3]] | Bynary_Mask[cards[4]]);

	if(getcolor == 0)
	{
		if(straight == 31) return ROYAL_FLUSH;
		if(HasStraight(straight)) return STRAIGHT_FLUSH;
		return FLUSH;
	} else {
		new
			two_pair,
			three_of_a_kind,
			match[13];
		for(i = 0; i < 5; i++)
		{
			match[cards[i] % 13]++;
		}
		for(i = 0; i < 13; i++)
		{
			switch(match[i])
			{
				case 2:
				{
					two_pair++;
					if(two_pair == 1)
						One_Pair_Type = i;
					else if(two_pair == 2)
						Two_Pair_Type = i;
				}
				case 3: three_of_a_kind++, One_Pair_Type = i;
				case 4: return One_Pair_Type = i, FOUR_OF_A_KIND;
			}
		}
		if(two_pair == 1 && three_of_a_kind == 1) return FULL_HOUSE;
		if(two_pair == 2) return TWO_PAIR;
		if(two_pair == 1) return ONE_PAIR;
		if(three_of_a_kind == 1) return THREE_OF_A_KIND;
		if(HasStraight(straight)) return STRAIGHT;
	}
	return HIGH_CARD;
}

stock
	HasStraight(straight)
{
	switch(straight)
	{
		case 31, 62, 124, 248, 496, 992, 1984, 3968, 7936, 4111: return true;
	}
	return false;
}

public
	TextDrawDizajn(playerid, index)
{
	if(index == 5)
	{
		new
			win,
			One_pair,
			Two_pair;
		win = getwin(PP_Info[playerid][fivecards_hand], One_pair, Two_pair);
		SetTimerEx("TextDrawDizajn2", 200, false, "iiii", playerid, win, One_pair, Two_pair);
		return 1;
	} else {
		PlaySound(playerid, 20800);
		TextDrawSetString(CardsText[playerid][index], "LD_POKE:cdback");
		TextDrawSetString(HoldsText[playerid][index], "LD_POKE:holdoff");
		SetTimerEx("TextDrawDizajn", 100, false, "ii", playerid, ++index);
	}
	return 1;
}

public
	TextDrawDizajn2(playerid, win, One_pair, Two_pair)
{
//--+
	for(new i; i < 5; i++)
	{
		TextDrawSetString(CardsText[playerid][i], LD_POKE[PP_Info[playerid][fivecards_hand][i]]);
		TextDrawSetString(HoldsText[playerid][i], "LD_POKE:holdoff");
	}
//--+
	switch(win)
	{
		case STRAIGHT, FLUSH, STRAIGHT_FLUSH, FULL_HOUSE, ROYAL_FLUSH:
		{
			for(new i = 0; i < 5; i++)
			{
				TextDrawSetString(HoldsText[playerid][i], "LD_POKE:holdon");
				PP_Info[playerid][holdstate][i] = HOLDON;
			}
		}
		case TWO_PAIR:
		{
			for(new i = 0; i < 5; i++)
			{
				if( Card_Value[One_pair] == Card_Value[PP_Info[playerid][fivecards_hand][i]] ||
					Card_Value[Two_pair] == Card_Value[PP_Info[playerid][fivecards_hand][i]])
				{
					TextDrawSetString(HoldsText[playerid][i], "LD_POKE:holdon");
					PP_Info[playerid][holdstate][i] = HOLDON;
				}
			}
		}
		case ONE_PAIR, FOUR_OF_A_KIND, THREE_OF_A_KIND:
		{
			for(new i = 0; i < 5; i++)
			{
				if(Card_Value[One_pair] == Card_Value[PP_Info[playerid][fivecards_hand][i]])
				{
					TextDrawSetString(HoldsText[playerid][i], "LD_POKE:holdon");
					PP_Info[playerid][holdstate][i] = HOLDON;
				}
			}
		}
	}
//--+
	Poker_Dialog(playerid, rang_sor[win]);
//--+
	WinnText(playerid, win);
//--+
	return 1;
}

stock
	WinnText(playerid, win)
{
	new
		color[10] = { 'w', ... };

	color[win] = 'r';

	new
		str[256];
	format(str, sizeof str, "~%c~~n~Royal Flush \t \t\t\t:\t$ %d\
							~%c~~n~Straight Flush \t :\t$ %d\
							~%c~~n~4 of a Kind \t \t \t    :\t$ %d\
							~%c~~n~Full House \t \t \t \t :\t$ %d\
							~%c~~n~Flush \t \t \t \t \t \t \t \t:\t$ %d\
							~%c~~n~Straight \t \t \t \t \t \t:\t$ %d\
							~%c~~n~3 of a Kind\t \t \t \t \t:\t$ %d\
							~%c~~n~Two Pair \t \t \t \t \t \t:\t$ %d",
					color[9], PP_Info[playerid][Bet] * pot[9],
					color[8], PP_Info[playerid][Bet] * pot[8],
					color[7], PP_Info[playerid][Bet] * pot[7],
					color[6], PP_Info[playerid][Bet] * pot[6],
					color[5], PP_Info[playerid][Bet] * pot[5],
					color[4], PP_Info[playerid][Bet] * pot[4],
					color[3], PP_Info[playerid][Bet] * pot[3],
					color[2], PP_Info[playerid][Bet] * pot[2]);

	TextDrawSetString(WinText[playerid], str);
}

stock
	BetCredit(playerid)
{
	new
		str[128];
	format(str, sizeof str, "~g~Bet: ~w~$%d                                    ~g~Credit: ~w~$%d",
							PP_Info[playerid][Bet],
							PP_Info[playerid][Credit]);

	TextDrawSetString(BetCreditText[playerid], str);
	return 1;
}

stock
	Create_PokerTextDraw(playerid)
{
	BackGroundText[playerid] = TextDrawCreate(-0.500, -0.500, "loadsc8:loadsc8");
	TextDrawFont(BackGroundText[playerid], 4);
	TextDrawTextSize(BackGroundText[playerid], 640.000, 450.000);
	TextDrawColor(BackGroundText[playerid], -1);
// ..........................................
	BetCreditText[playerid] = TextDrawCreate(320.000000, 399.000000, "_");
	TextDrawAlignment(BetCreditText[playerid], 2);
	TextDrawBackgroundColor(BetCreditText[playerid], 255);
	TextDrawFont(BetCreditText[playerid], 3);
	TextDrawLetterSize(BetCreditText[playerid], 0.300000, 1.600000);
	TextDrawColor(BetCreditText[playerid], -1);
	TextDrawSetOutline(BetCreditText[playerid], 0);
	TextDrawSetProportional(BetCreditText[playerid], 1);
	TextDrawSetShadow(BetCreditText[playerid], 1);
	TextDrawUseBox(BetCreditText[playerid], 1);
	TextDrawBoxColor(BetCreditText[playerid], 335595560);
	TextDrawTextSize(BetCreditText[playerid], 6.000000, 302.000000);
// ..........................................
	WinText[playerid] = TextDrawCreate(410.000000, 164.000000, "_");
	TextDrawAlignment(WinText[playerid], 1);
	TextDrawBackgroundColor(WinText[playerid], 255);
	TextDrawFont(WinText[playerid], 2);
	TextDrawLetterSize(WinText[playerid], 0.260000, 1.400000);
	TextDrawColor(WinText[playerid], -1);
	TextDrawSetOutline(WinText[playerid], 1);
	TextDrawSetProportional(WinText[playerid], 1);
// ..........................................
	CardsText[playerid][0] = TextDrawCreate(167.500, 290.500, "LD_POKE:backcyan");
	TextDrawFont(CardsText[playerid][0], 4);
	TextDrawTextSize(CardsText[playerid][0], 59.500, 88.000);
	TextDrawColor(CardsText[playerid][0], -1);

	CardsText[playerid][1] = TextDrawCreate(229.000, 290.500, "LD_POKE:backcyan");
	TextDrawFont(CardsText[playerid][1], 4);
	TextDrawTextSize(CardsText[playerid][1], 59.500, 88.000);
	TextDrawColor(CardsText[playerid][1], -1);

	CardsText[playerid][2] = TextDrawCreate(290.500, 290.500, "LD_POKE:backcyan");
	TextDrawFont(CardsText[playerid][2], 4);
	TextDrawTextSize(CardsText[playerid][2], 59.500, 88.000);
	TextDrawColor(CardsText[playerid][2], -1);

	CardsText[playerid][3] = TextDrawCreate(352.000, 290.500, "LD_POKE:backcyan");
	TextDrawFont(CardsText[playerid][3], 4);
	TextDrawTextSize(CardsText[playerid][3], 59.500, 88.000);
	TextDrawColor(CardsText[playerid][3], -1);

	CardsText[playerid][4] = TextDrawCreate(413.500, 290.500, "LD_POKE:backcyan");
	TextDrawFont(CardsText[playerid][4], 4);
	TextDrawTextSize(CardsText[playerid][4], 59.500, 88.000);
	TextDrawColor(CardsText[playerid][4], -1);
// ..........................................
	HoldsText[playerid][0] = TextDrawCreate(167.500, 380.500, "LD_POKE:holdoff");
	TextDrawFont(HoldsText[playerid][0], 4);
	TextDrawTextSize(HoldsText[playerid][0], 59.500, 14.500);
	TextDrawColor(HoldsText[playerid][0], -1);

	HoldsText[playerid][1] = TextDrawCreate(229.000, 380.500, "LD_POKE:holdoff");
	TextDrawFont(HoldsText[playerid][1], 4);
	TextDrawTextSize(HoldsText[playerid][1], 59.500, 14.500);
	TextDrawColor(HoldsText[playerid][1], -1);

	HoldsText[playerid][2] = TextDrawCreate(290.500, 380.500, "LD_POKE:holdoff");
	TextDrawFont(HoldsText[playerid][2], 4);
	TextDrawTextSize(HoldsText[playerid][2], 59.500, 14.500);
	TextDrawColor(HoldsText[playerid][2], -1);

	HoldsText[playerid][3] = TextDrawCreate(352.000, 380.500, "LD_POKE:holdoff");
	TextDrawFont(HoldsText[playerid][3], 4);
	TextDrawTextSize(HoldsText[playerid][3], 59.500, 14.500);
	TextDrawColor(HoldsText[playerid][3], -1);

	HoldsText[playerid][4] = TextDrawCreate(413.500, 380.500, "LD_POKE:holdoff");
	TextDrawFont(HoldsText[playerid][4], 4);
	TextDrawTextSize(HoldsText[playerid][4], 59.500, 14.500);
	TextDrawColor(HoldsText[playerid][4], -1);
}

stock
	Delete_PokerTextDraw(playerid)
{
	TextDrawHideForPlayer(playerid, BackGroundText[playerid]);
	TextDrawHideForPlayer(playerid, WinText[playerid]);
	TextDrawHideForPlayer(playerid, BetCreditText[playerid]);
	TextDrawDestroy(BackGroundText[playerid]);
	TextDrawDestroy(WinText[playerid]);
	TextDrawDestroy(BetCreditText[playerid]);
	BackGroundText[playerid] = Text:INVALID_TEXT_DRAW;
	WinText[playerid] = Text:INVALID_TEXT_DRAW;
	BetCreditText[playerid] = Text:INVALID_TEXT_DRAW;

	for(new i = 0; i < 5; i++)
	{
		TextDrawHideForPlayer(playerid, CardsText[playerid][i]);
		TextDrawHideForPlayer(playerid, HoldsText[playerid][i]);
		TextDrawDestroy(CardsText[playerid][i]);
		TextDrawDestroy(HoldsText[playerid][i]);
		CardsText[playerid][i] = Text:INVALID_TEXT_DRAW;
		HoldsText[playerid][i] = Text:INVALID_TEXT_DRAW;
	}
	return 1;
}

stock
	PlaySound(playerid, sound)
{
	new
		Float:X,
		Float:Y,
		Float:Z;
	GetPlayerPos(playerid, X, Y, Z);
	PlayerPlaySound(playerid, sound, X, Y, Z);
	return sound;
}

stock
	HasDuplicateValues(const array[], size = sizeof array)
{
	for(new f = 0; f < size - 1; ++f)
	{
		for(new c = f + 1; c < size; ++c)
		{
			if(array[f] == array[c])
			{
				return true;
			}
		}
	}
	return false;
}

stock
	RandomNumber(value, array[], size = sizeof array)
{
	for(new p = 0; p < size; p++) array[p] = random(value);
}

stock
	Swap (&a, &b)
{
	new s;
	s = a;
	a = b;
	b = s;
}

stock
	strtok(const string[], &index)
{
	new length = strlen(string);
	while ((index < length) && (string[index] <= ' '))
	{
		index++;
	}
	new offset = index;
	new result[20];
	while ((index < length) && (string[index] > ' ') && ((index - offset) < (sizeof(result) - 1)))
	{
		result[index - offset] = string[index];
		index++;
	}
	result[index - offset] = EOS;
	return result;
}