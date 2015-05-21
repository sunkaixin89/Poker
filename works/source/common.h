
#ifndef __COMMON__H__
#define __COMMON__H__
//定义2~A
#define POINT_2 2
#define POINT_3 3
#define POINT_4 4
#define POINT_5 5
#define POINT_6 6
#define POINT_7 7
#define POINT_8 8
#define POINT_9 9
#define POINT_10 10
#define POINT_J 11
#define POINT_Q 12
#define POINT_K 13
#define POINT_A 14

//定义花色
#define COLOR_HEATS 1   //红桃
#define COLOR_SPADES 2  //黑桃
#define COLOR_CLUBS 3   //梅花
#define COLOR_DIAMONDS 4//方片

//定义扑克牌
typedef struct Poker{
	int point;
	int color;
    bool operator<(Poker other){
        return this->point < other.point;    
    }
}Poker;

//动作类别
#define ACTION_FOLD 1//弃牌
#define ACTION_CHECK 2//让牌
#define ACTION_RAISE 3//加注
#define ACTION_CALL 4//跟注
#define ACTION_ALL_IN 5//全压
#define ACTION_BLIND 6//盲注

//玩家类别
#define TYPE_BIG_BLIND 1//大盲注
#define TYPE_SMALL_BLIND 2//小盲注
#define TYPE_BUTTON 3 //庄家
#define TYPE_COMMON 4 //普通

//牌型
#define POKER_HIGH_CARD 1//高牌
#define POKER_ONE_PAIR 2//一对
#define POKER_TWO_PAIR 3 //两对
#define POKER_THREE_OF_A_KIND 4 //三条
#define POKER_STRAIGHT 5 //顺子
#define POKER_FLUSH 6 //同花
#define POKER_FULL_HOUSE 7 //葫芦
#define POKER_FOUR_OF_A_KIND 8 //四条
#define POKER_STRAIGHT_FLUSH 9 //同花顺

#include<vector>
using namespace std;

int pokerType(vector<Poker> &pokers,int &highpt);
int pokerTypeTwo(vector<Poker> &pokers);
int pokerTypeAll(vector<Poker> &pokers,vector<Poker> &maxpoker);

//玩家
typedef struct Player{
	int pid;     //id
	int type;    //类型
	int jetton;  //筹码
	int bet;     //赌注
	int money;   //金钱
	int rank;    //排名
	int action;  //操作
	int action_money; //操作钱
	int nut_hand; //上一次成牌类型
	bool win_last; //判断上一次是否胜利
	int  win_num; //获胜钱
}Player;



#endif


