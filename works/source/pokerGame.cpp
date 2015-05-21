#include "pokerGame.h"
#include<algorithm>


pokerGame::pokerGame():turn(0),total(0),m_mainStrategy(this){
	point_map.insert(pair<string, int>("2", 2));
	point_map.insert(pair<string, int>("3", 3));
	point_map.insert(pair<string, int>("4", 4));
	point_map.insert(pair<string, int>("5", 5));
	point_map.insert(pair<string, int>("6", 6));
	point_map.insert(pair<string, int>("7", 7));
	point_map.insert(pair<string, int>("8", 8));
	point_map.insert(pair<string, int>("9", 9));
	point_map.insert(pair<string, int>("10", 10));
	point_map.insert(pair<string, int>("J", 11));
	point_map.insert(pair<string, int>("Q", 12));
	point_map.insert(pair<string, int>("K", 13));
	point_map.insert(pair<string, int>("A", 14));

	color_map.insert(pair<string, int>("HEARTS", COLOR_HEATS));
	color_map.insert(pair<string, int>("DIAMONDS", COLOR_DIAMONDS));
	color_map.insert(pair<string, int>("SPADES", COLOR_SPADES));
	color_map.insert(pair<string, int>("CLUBS", COLOR_CLUBS));

	action_map.insert(pair<string, int>("raise", ACTION_RAISE));
	action_map.insert(pair<string, int>("fold", ACTION_FOLD));
	action_map.insert(pair<string, int>("check", ACTION_CHECK));
	action_map.insert(pair<string, int>("call", ACTION_CALL));
	action_map.insert(pair<string,int>("all_in",ACTION_ALL_IN));
	action_map.insert(pair<string, int>("blind", ACTION_BLIND));

	poker_map.insert(pair<string, int>("HIGH_CARD", POKER_HIGH_CARD));
	poker_map.insert(pair<string, int>("TWO_PAIR", POKER_TWO_PAIR));
	poker_map.insert(pair<string, int>("ONE_PAIR", POKER_ONE_PAIR));
	poker_map.insert(pair<string, int>("THREE_OF_A_KIND", POKER_THREE_OF_A_KIND));
	poker_map.insert(pair<string, int>("POKER_STRAIGHT", POKER_STRAIGHT));
	poker_map.insert(pair<string, int>("POKER_FLUSH", POKER_FLUSH));
	poker_map.insert(pair<string, int>("FOUR_OF_A_KIND", POKER_FOUR_OF_A_KIND));
	poker_map.insert(pair<string, int>("FULL_HOUSE", POKER_FULL_HOUSE));
	poker_map.insert(pair<string, int>("STRAIGHT_FLUSH", POKER_STRAIGHT_FLUSH));
}


pokerGame::~pokerGame(){
}
MainStrategy* pokerGame::GetStrategy()
{
	return &m_mainStrategy;
}
bool pokerGame::prase(string &command){
	char type[15];
	char *cmd_str = const_cast<char *>(command.c_str());
	sscanf(cmd_str, "%[^/]", type);

	if (strcmp(type, "seat")==0){

		praseSeat(command);

	}else if (strcmp(type, "blind")==0){

		praseBlind(command);

	}else if (strcmp(type, "river") == 0){

		praseRiver(command);

	}else if (strcmp(type, "flop") == 0){

		praseFlop(command);

	}else if (strcmp(type, "turn") == 0){

		praseTurn(command);

	}else if (strcmp(type, "inquire") == 0){

		praseInquire(command);

	}else if (strcmp(type, "hold") == 0){

		praseHold(command);

	}else if (strcmp(type, "showdown") == 0){

		praseShowDown(command);

	}else if(strcmp(type, "pot-win") == 0){

		praseWinPot(command);

	}else if(strcmp(type, "notify") == 0){

		praseNotify(command);

	}
	return true;
}

bool pokerGame::praseSeat(string &command){
	stringstream ss_stream;
	ss_stream << command;
	this->players.clear();
	this->hold_poker.clear();
	this->common_poker.clear();
	while (true){
		string type;
		ss_stream >> type;
		Player player;
		memset(&player, 0, sizeof(player));
		if (type == "seat/"){
			continue;
		}else if (type == "/seat"){
			break;
		}else if (type == "button:"){
			ss_stream >> player.pid;
			ss_stream >> player.jetton;
			ss_stream >> player.money;
			player.type = TYPE_BUTTON;
			this->players.insert(pair<int, Player>(player.pid, player));
		}else if (type == "small"){
			ss_stream >> type;
			ss_stream >> player.pid;
			ss_stream >> player.jetton;
			ss_stream >> player.money;
			player.type = TYPE_SMALL_BLIND;
			this->players.insert(pair<int, Player>(player.pid,player));
		}else if (type == "big"){
			ss_stream >> type;
			ss_stream >> player.pid;
			ss_stream >> player.jetton;
			ss_stream >> player.money;
			player.type = TYPE_BIG_BLIND;
			this->players.insert(pair<int, Player>(player.pid, player));
		}else{
			stringstream cvt;
			cvt << type;
			cvt >> player.pid;
			ss_stream >> player.jetton;
			ss_stream >> player.money;
			player.type = TYPE_COMMON;
			this->players.insert(pair<int, Player>(player.pid, player));
		}
	}
	this->cround = ROUND_SEAT;
	turn++;
	return true;
}

bool pokerGame::praseHold(string &command){
	stringstream ss_stream;
	ss_stream << command;
	string type;
	string color;
        string point;
	int i = 0;
	ss_stream >> type;
	while (i < 2){
		Poker poker;
		ss_stream >> color >> point;
		poker.color = color_map[color];
		poker.point = point_map[point];
		this->hold_poker.push_back(poker);
		i++;
	}
	ss_stream >> type;
	this->cround = ROUND_HOLD;
	return true;
}

bool pokerGame::praseFlop(string &command){
	stringstream ss_stream;
	ss_stream << command;
	string type;
	string color;
	string point;
	int i = 0;
	ss_stream >> type;
	while (i < 3){
		Poker poker;
		ss_stream >> color >> point;
		poker.color = color_map[color];
		poker.point = point_map[point];
		this->common_poker.push_back(poker);
		i++;
	}
	ss_stream >> type;
	this->cround = ROUND_FLOP;
	return true;
}

bool pokerGame::praseTurn(string &command){
	stringstream ss_stream;
	ss_stream << command;
	string type;
	string color;
	string point;
	ss_stream >> type;
	Poker poker;
	ss_stream >> color >> point;
	poker.color = color_map[color];
	poker.point = point_map[point];
	this->common_poker.push_back(poker);

	ss_stream >> type;
	this->cround = ROUND_TURN;
	return true;
}

bool pokerGame::praseRiver(string &command){
	stringstream ss_stream;
	ss_stream << command;
	string type;
	string color;
	string point;
	ss_stream >> type;
	Poker poker;
	ss_stream >> color >> point;
	poker.color = color_map[color];
	poker.point = point_map[point];
	this->common_poker.push_back(poker);

	ss_stream >> type;
	this->cround = ROUND_RIVER;
	return true;
}

bool pokerGame::praseBlind(string &command){
	stringstream ss_stream;
	ss_stream << command;
	while (true){
		string type;
		ss_stream >> type;
		if (type == "blind/"){
			continue;
		}else if (type == "/blind"){
			break;
		}else{
			int pid;
			stringstream cvt;
			cvt << type;
			cvt >> pid;
			int bet;
			ss_stream >> bet;
			players[pid].bet += bet;
			players[pid].jetton -= bet;
		}
	}

	this->cround = ROUND_BLIND;
	return true;
}

bool pokerGame::praseInquire(string &command){
	stringstream ss_stream;
	ss_stream << command;
	string type;
	bool bFirst = true;
	while (true){
		ss_stream >> type;
		if (type == "inquire/" || type == "total"){
			continue;
		}else if (type == "/inquire"){
			break;
		}else if (type == "pot:"){
			ss_stream >> this->total;
		}else{
			int pid;
			stringstream cvt;
			cvt << type;
			cvt >> pid;
			ss_stream>>players[pid].jetton;
			ss_stream >> players[pid].money;
			int bet;
			ss_stream >> bet;
			string action;
			ss_stream >> action;
			players[pid].action = action_map[action];
			players[pid].action_money = bet-players[pid].bet;
			players[pid].bet = bet;
			if(bFirst){
				this->current = players[pid].action_money;
				bFirst = false;
			}
		}
	}
	return true;
}
bool pokerGame::praseWinPot(string &command){

    stringstream ss_stream;
    ss_stream << command;
    string type;
    for(int i = 0;i < players.size();i++){
	players[i].win_last = false;
	players[i].win_num = 0;
    }
    while (true){
	ss_stream >> type;
	if (type == "pot-win/"){
	    continue;
	}else if (type == "/pot-win"){
	    break;
	}else if (type.find_last_of(':') != string::npos){
	     int pid;
	     stringstream type_stream;
	     type_stream << type;
	     type_stream >> pid;
	     players[pid].win_last = true;
	     ss_stream >>players[pid].win_num;
	}
    }
    return true;
}
bool pokerGame::praseNotify(string &command){
	stringstream ss_stream;
	ss_stream << command;
	string type;
	bool bFirst = true;
	while (true){
		ss_stream >> type;
		if (type == "notify/" || type == "total"){
			continue;
		}else if (type == "/notify"){
			break;
		}else if (type == "pot:"){
			ss_stream >> this->total;
		}else{
			int pid;
			stringstream cvt;
			cvt << type;
			cvt >> pid;
			ss_stream>>players[pid].jetton;
			ss_stream >> players[pid].money;
			int bet;
			ss_stream >> bet;
			string action;
			ss_stream >> action;
			players[pid].action = action_map[action];
			players[pid].action_money = bet-players[pid].bet;
			players[pid].bet = bet;
			if(bFirst){
				this->current = players[pid].action_money;
				bFirst = false;
			}
		}
	}
	return true;
}
bool pokerGame::praseShowDown(string &command){
	stringstream ss_stream;
	ss_stream << command;
	string type;
	while (true){
		ss_stream >> type;
		if (type == "showdown/"){
			continue;
		}else if (type == "/showdown"){
			break;
		}else if (type.find_last_of(':') != string::npos){
			int pid;
			ss_stream >> pid;
			int i = 0;
			string nut_hand;
			while (i < 5){
				ss_stream >> nut_hand;				
				i++;
			}
			players[pid].nut_hand = poker_map[nut_hand];
		}
	}
	return true;
}


