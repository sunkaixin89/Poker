#ifndef	__H_MSG__
#define __H_MSG__
#include <vector>
#include<string>
#include "pokerGame.h"
#include "strategy.h"

using namespace std;


class MsgProcessor
{
public:
	MsgProcessor(int socket_id):m_socket(socket_id){
		ResetRoundStatus();
		m_RoundCount = 0;
	}
	 int ProcessMsg(char* msg);
	void SetStrategy(strategy *stg){ m_strategy = stg; m_strategy->reg(&m_pokergame);};
protected:
	 void ResetRoundStatus();
private:
	int m_socket;
	pokerGame m_pokergame;
	strategy *m_strategy;
	vector<string> m_vecMsg;


	bool m_bAllIn;
	int 	m_RoundCount;
};

#endif
