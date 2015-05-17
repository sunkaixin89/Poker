#pragma once
/**
游戏记录核心类
class pokerGame
create by skx
2015/5/15
*/
#include<vector>
#include<string>
#include<iostream>
#include "common.h"
#include<sstream>
#include<string.h>
#include<stdio.h>
#include<map>

using namespace std;
class pokerGame{
public:
	map<string, int> color_map; //花色映射
	map<string, int> action_map; //行动映射
	map<string, int> point_map; //牌点数映射
	map<string, int> poker_map; //牌型映射
	map<int,Player> players; //表示玩家
	vector<Poker> common_poker; //公共牌
	vector<Poker> hold_poker; //表示手牌
	int total;  //奖池总数
	int current; //当前跟注大小
	int turn;  //表示第几轮
	int cround; //表示当前轮数
	static const int ROUND_REGISTER = 0; //注册轮
	static const int ROUND_SEAT = 1; //公布座位轮
	static const int ROUND_BLIND = 2; //盲注
	static const int ROUND_HOLD = 3; //发牌轮
	static const int ROUND_FLOP = 4; //公共牌轮
	static const int ROUND_TURN = 5; //转牌轮
	static const int ROUND_RIVER = 6; //河牌轮
	static const int ROUND_SHOW_MESSAGE = 7; //比牌轮
	static const int ROUND_WIN_POT = 8; //奖池公布轮
	static const int ROUND_GAME_OVER = 9; //结束轮
	pokerGame();
	~pokerGame();
	bool prase(string &command);
	//打印信息
	friend ostream& operator<< (ostream &os, pokerGame &st){
		//os << st.name << "------" << st.age << "------" << st.address << endl;
		return os;
	}
private:
	bool praseSeat(string &command);
	bool praseBlind(string &command);
	bool praseInquire(string &command);
	bool praseHold(string &command);
	bool praseFlop(string &command);
	bool praseTurn(string &command);
	bool praseRiver(string &command);
	bool praseShowDown(string &command);
};

