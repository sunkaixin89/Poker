#include "simpleStrategy.h"

bool less_hold(Poker& poker1,Poker &poker2){
    return poker1.point >= poker2.point;
}

string SimpleStrategy::action(){
   int type = holdType();
  
   switch(type){
      case TOP_LEVEL:
      return "raise 200\n";
      case HIGH_LEVEL:
      return "call \n";
      case BUTTOM_LEVEL:
      return "fold \n";
   }
}

int SimpleStrategy::holdType(){
    sort(m_game->hold_poker.begin(),m_game->hold_poker.end(),less_hold);
    if((m_game->hold_poker[0].point == m_game->hold_poker[1].point
     && m_game->hold_poker[0].point >= POINT_9) ||
     (m_game->hold_poker[0].point == POINT_A
      &&m_game->hold_poker[0].point-m_game->hold_poker[1].point<3
      )){
       return TOP_LEVEL;
    }else if(m_game->hold_poker[0].point == m_game->hold_poker[1].point ||
     m_game->hold_poker[0].point+m_game->hold_poker[1].point > 22){
       return HIGH_LEVEL; 
    }else{
       return BUTTOM_LEVEL; 
    } 
}
