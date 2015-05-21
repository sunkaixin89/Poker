/*
 * MainStrategy.cpp
 *
 *  Created on: 2015年5月18日
 *      Author: zxb
 */


#include "MainStrategy.h"
#include "pokerGame.h"
#include "ProCalculator.h"
#include <algorithm>
#include <time.h>
#include <sys/time.h>

bool less_hold( Poker poker1,  Poker poker2){
    return poker1.point >= poker2.point;
}

MainStrategy::MainStrategy(pokerGame* pPokerGame):m_pPokerGame(pPokerGame){
	struct timeval tpstart;
		gettimeofday(&tpstart, NULL);
		srand(tpstart.tv_usec);
	}


string MainStrategy::ActionAsAllRaise(){
	return "raise 200 \n";
}
string MainStrategy::ActionAsAllFold(){
    return "fold \n";
}
string MainStrategy::ActionAsAllCheck(){
    return "check \n";
}
string MainStrategy::ActionAsAllCall(){
    return "call \n";
}
string MainStrategy::ActionAsAllAllin(){
    return "all_in \n";
}
string MainStrategy::ActionAsAllRandom()
{
	int n = rand()%5;
	if(n == 0)
		return "fold \n";
	else if(n == 1)
		return "check \n";
	else if(n == 2)
		return "call \n";
	else if(n == 3)
		return "raise 200 \n";
	else
		return "all_in \n";
}

string MainStrategy::Action(){

	if(m_pPokerGame->cround == pokerGame::ROUND_HOLD)
	{
		int type = HoldType();

			   switch(type){
			      case TOP_LEVEL:
			      return "raise 200 \n";
			      case HIGH_LEVEL:
			      return "call \n";
			      case BUTTOM_LEVEL:
			      return "fold \n";
			      default:
			    	  return "check \n";
			   }
	}
	else if(m_pPokerGame->cround == pokerGame::ROUND_FLOP
			|| m_pPokerGame->cround == pokerGame::ROUND_TURN
			|| m_pPokerGame->cround == pokerGame::ROUND_RIVER)
	{
		double p = ProCalculator::CalProLessThanMe(m_pPokerGame->hold_poker, m_pPokerGame->common_poker,
				m_pPokerGame->players.size() - 1);
		if(p > 0.7)
			return "raise 200 \n";
		else if(p > 0.6)
			return "call \n";
		else if(p > 0.35)
			return "check \n";
		else
			return "fold \n";
	}
	else
	{
		return "check \n";
	}

}





int MainStrategy::HoldType(){
    sort(m_pPokerGame->hold_poker.begin(),m_pPokerGame->hold_poker.end(),less_hold);
    if(
     (m_pPokerGame->hold_poker[0].point == m_pPokerGame->hold_poker[1].point && m_pPokerGame->hold_poker[0].point >= POINT_10)
	 || (m_pPokerGame->hold_poker[0].color == m_pPokerGame->hold_poker[1].color &&	m_pPokerGame->hold_poker[0].point >=POINT_Q && m_pPokerGame->hold_poker[1].point >=POINT_Q)
	 || (m_pPokerGame->hold_poker[0].point == POINT_A  && m_pPokerGame->hold_poker[1].point>=POINT_J)
	 || (m_pPokerGame->hold_poker[1].point == POINT_A  && m_pPokerGame->hold_poker[0].point>=POINT_J)
	 ){
       return TOP_LEVEL;
    }else if((m_pPokerGame->hold_poker[0].point == m_pPokerGame->hold_poker[1].point )
    		|| (m_pPokerGame->hold_poker[0].color == m_pPokerGame->hold_poker[1].color &&  m_pPokerGame->hold_poker[0].point >=POINT_6 && m_pPokerGame->hold_poker[1].point >=POINT_6)
			|| (m_pPokerGame->hold_poker[0].point + m_pPokerGame->hold_poker[1].point >= 18)){
       return HIGH_LEVEL;
    }else{
       return BUTTOM_LEVEL;
    }
}
