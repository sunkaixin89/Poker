#include "strategy.h"

strategy::strategy(){
    m_action_map.insert(pair<int,string>(ACTION_CHECK,"check"));
    m_action_map.insert(pair<int,string>(ACTION_FOLD,"fold"));    
    m_action_map.insert(pair<int,string>(ACTION_RAISE,"raise"));
    m_action_map.insert(pair<int,string>(ACTION_CALL,"call"));
    m_action_map.insert(pair<int,string>(ACTION_ALL_IN,"all_in"));
}


strategy::~strategy(){
}
