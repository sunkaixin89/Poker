/*
 * PlayerInfo.h
 *
 *  Created on: 2015年5月18日
 *      Author: zxb
 */
#ifndef SOURCE_PLAYERSTATINFO_H_
#define SOURCE_PLAYERSTATINFO_H_

#include <string>

using namespace std;

class PlayerStatInfo
{
public:
	PlayerStatInfo(string playID, int jetton, int money);
private:
	string			m_playerID;		//选手ID
	int				m_jetton;				//筹码
	int 				m_money;			//金币

	int 				m_countOfRound; 		//选手已经玩的局数
	int 				m_countOfWin;				//选手赢的局数

	int				m_countOfAllin;				//allin 次数
	int				m_winCountOfAllin;		//allin赢的次数
	int 				m_countOfRaise;			//加注次数
	int 				m_winCountOfRaise;	//加注赢的次数


};

#endif /* SOURCE_PLAYERSTATINFO_H_ */
