/*
 * PlayerInfo.cpp
 *
 *  Created on: 2015年5月18日
 *      Author: zxb
 */

#include "PlayerStatInfo.h"

PlayerStatInfo::PlayerStatInfo(string playID, int jetton, int money)
: m_playerID(playerID), m_jetton(jetton), m_money(money)
{

	m_countOfRound = 0;
	m_countOfWin = 0;
	m_countOfAllin = 0;
	m_winCountOfAllin = 0;
	m_countOfRaise = 0;
	m_winCountOfRaise = 0;
}

