/*
 * ProCalculator.h
 *
 *  Created on: 2015年5月20日
 *      Author: zxb
 */

#ifndef PROCALCULATOR_H_
#define PROCALCULATOR_H_

#include "common.h"

class ProCalculator
{
public:
	//计算当前牌情况下，别人都比我牌小的概率
	static double CalProLessThanMe(vector<Poker> myPoker, vector<Poker> commonPoker, int otherPlayerNum);
};

#endif /* PROCALCULATOR_H_ */
