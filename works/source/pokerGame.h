#pragma once
/**
��Ϸ��¼������
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
#include "MainStrategy.h"

using namespace std;
class pokerGame{
public:
	MainStrategy* GetStrategy();

public:
	map<string, int> color_map; //��ɫӳ��
	map<string, int> action_map; //�ж�ӳ��
	map<string, int> point_map; //�Ƶ���ӳ��
	map<string, int> poker_map; //����ӳ��
	map<int,Player> players; //��ʾ���
	vector<Poker> common_poker; //������
	vector<Poker> hold_poker; //��ʾ����
	int total;  //��������
	int current; //��ǰ��ע��С
	int turn;  //��ʾ�ڼ���
	int cround; //��ʾ��ǰ����
	static const int ROUND_REGISTER = 0; //ע����
	static const int ROUND_SEAT = 1; //������λ��
	static const int ROUND_BLIND = 2; //äע
	static const int ROUND_HOLD = 3; //������
	static const int ROUND_FLOP = 4; //��������
	static const int ROUND_TURN = 5; //ת����
	static const int ROUND_RIVER = 6; //������
	static const int ROUND_SHOW_MESSAGE = 7; //������
	static const int ROUND_WIN_POT = 8; //���ع�����
	static const int ROUND_GAME_OVER = 9; //������
	pokerGame();
	~pokerGame();
	bool prase(string &command);
	//��ӡ��Ϣ
	friend ostream& operator<< (ostream &os, pokerGame &st){
		//os << st.name << "------" << st.age << "------" << st.address << endl;
		return os;
	}
private:
	bool praseSeat(string &command);
	bool praseBlind(string &command);
	bool praseInquire(string &command);
	bool praseNotify(string &command);
	bool praseHold(string &command);
	bool praseFlop(string &command);
	bool praseTurn(string &command);
	bool praseRiver(string &command);
	bool praseShowDown(string &command);
	bool praseWinPot(string &command);
	MainStrategy			m_mainStrategy;
};
