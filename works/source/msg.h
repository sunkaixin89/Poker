#ifndef	__H_MSG__
#define __H_MSG__

#include <vector>
#include<string>
#include "pokerGame.h"
#include "MainStrategy.h"

using namespace std;


//当前局状态
enum RoundStatus{
	RS_BEGIN = 0,				//牌局开始
	RS_ALL_IN,					//全押
	RS_FOLD,						//弃牌
	RS_CHECK,					//让牌
	RS_CALL,						//跟注
	RS_RAISE,						//加注
};

class MsgProcessor
{
public:
	MsgProcessor(int socket_id, string strategyName)
:m_socket(socket_id), m_strategyName(strategyName),m_pokergame()
{
		ResetRoundStatus();
		m_RoundCount = 0;
	}
	 int ProcessMsg(char* msg);
	 void SendMsgToServer();

	//void SetStrategy(strategy *stg){ m_strategy = stg; m_strategy->reg(&m_pokergame);};
protected:
	 void ResetRoundStatus();
private:
	 string 	m_strategyName;
	int m_socket;
	pokerGame	 			m_pokergame;



	vector<string> m_vecMsg;


	RoundStatus	m_rs;
	int 	m_RoundCount;
};

#endif
