#pragma once
/************************
策略接口
所有策略继承自其接口
create by skx
2015/5/16
************************/
#include "pokerGame.h"

class strategy{
public:
	strategy();
	virtual ~strategy();
	void reg(pokerGame *game){m_game = game;};
	virtual string action()=0;
protected:
	pokerGame *m_game;
        map<int,string> m_action_map;
};

