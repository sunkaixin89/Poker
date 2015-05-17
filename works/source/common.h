#pragma once
//����2~A
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

//���廨ɫ
#define COLOR_HEATS 1   //����
#define COLOR_SPADES 2  //����
#define COLOR_CLUBS 3   //÷��
#define COLOR_DIAMONDS 4//��Ƭ

//�����˿���
typedef struct Poker{
	int point;
	int color;
}Poker;

//�������
#define ACTION_FOLD 1//����
#define ACTION_CHECK 2//����
#define ACTION_RAISE 3//��ע
#define ACTION_CALL 4//��ע
#define ACTION_ALL_IN 5//ȫѹ
#define ACTION_BLIND 6//äע

//������
#define TYPE_BIG_BLIND 1//��äע
#define TYPE_SMALL_BLIND 2//Сäע
#define TYPE_BUTTON 3 //ׯ��
#define TYPE_COMMON 4 //��ͨ

//����
#define POKER_HIGH_CARD 1//����
#define POKER_ONE_PAIR 2//һ��
#define POKER_TWO_PAIR 3 //����
#define POKER_THREE_OF_A_KIND 4 //����
#define POKER_STRAIGHT 5 //˳��
#define POKER_FLUSH 6 //ͬ��
#define POKER_FULL_HOUSE 7 //��«
#define POKER_FOUR_OF_A_KIND 8 //����
#define POKER_STRAIGHT_FLUSH 9 //ͬ��˳


//���
typedef struct Player{
	int pid;     //id
	int type;    //����
	int jetton;  //����
	int bet;     //��ע
	int money;   //��Ǯ
	int rank;    //����
	int action;  //����
	int action_money; //����Ǯ
	int nut_hand; //��һ�γ�������
}Player;