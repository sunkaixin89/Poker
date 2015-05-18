/*
 * MainStrategy.cpp
 *
 *  Created on: 2015年5月18日
 *      Author: zxb
 */

#include "MainStrategy.h"
#include "pokerGame.h"
#include <algorithm>

bool less_hold( Poker poker1,  Poker poker2){
    return poker1.point >= poker2.point;
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
string MainStrategy::Action(){
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





int MainStrategy::HoldType(){
    sort(m_pPokerGame->hold_poker.begin(),m_pPokerGame->hold_poker.end(),less_hold);
    if((m_pPokerGame->hold_poker[0].point == m_pPokerGame->hold_poker[1].point
     && m_pPokerGame->hold_poker[0].point >= POINT_9) ||
     (m_pPokerGame->hold_poker[0].point == POINT_A
      &&m_pPokerGame->hold_poker[0].point-m_pPokerGame->hold_poker[1].point<3
      )){
       return TOP_LEVEL;
    }else if(m_pPokerGame->hold_poker[0].point == m_pPokerGame->hold_poker[1].point ||
    		m_pPokerGame->hold_poker[0].point+m_pPokerGame->hold_poker[1].point > 22){
       return HIGH_LEVEL;
    }else{
       return BUTTOM_LEVEL;
    }
}
