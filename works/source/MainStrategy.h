/*
 * MainStrategy.h
 *
 *  Created on: 2015年5月18日
 *      Author: zxb
 */

#ifndef SOURCE_MAINSTRATEGY_H_
#define SOURCE_MAINSTRATEGY_H_

#include "common.h"
#include <string>


using namespace std;

class pokerGame;

class MainStrategy
{
public:
	static const int TOP_LEVEL = 0;
	    static const int HIGH_LEVEL = 1;
	    static const int MID_LEVEL = 2;
	    static const int BUTTOM_LEVEL = 3;

	MainStrategy(pokerGame* pPokerGame):m_pPokerGame(pPokerGame){}

	//全让牌策略
	string ActionAsAllCheck();

	//全跟注策略
	string ActionAsAllCall();

	//全押策略
	string ActionAsAllAllin();

	string Action();
protected:
	int HoldType();

private:
	pokerGame* m_pPokerGame;
};

#endif /* SOURCE_MAINSTRATEGY_H_ */
