/*
 * ProCalculator.cpp
 *
 *  Created on: 2015年5月20日
 *      Author: zxb
 */

#include "ProCalculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//生成一副新牌
void NewAllPoker(vector<Poker>& allPoker)
{
	int i, j;
	allPoker.clear();
	for(i = POINT_2; i <= POINT_A; ++i )
	{
		for(j = COLOR_HEATS; j <= COLOR_DIAMONDS; ++j)
		{
			Poker p;
			p.color = j;
			p.point = i;
			allPoker.push_back(p);
		}
	}
}

//验证我的牌和公共牌是效性
bool ValidatePoker(vector<Poker> poker)
{
	for(int i = 0; i < poker.size() - 1; ++i)
	{
		for(int j = i + 1; j < poker.size(); ++j)
		{
			if(poker[i].point == poker[j].point && poker[i].color == poker[j].color)
				return false;
		}
	}
	return true;
}

long CalCMethod(int bottomNum, int topNum)
{
	long result = 1;
	int i;
	for(i = 0; i < topNum; ++i)
		result *= (bottomNum - i);
	for(i = topNum; i >= 1; --i)
		result /= i;
	return result;
}
double ProCalculator::CalProLessThanMe(vector<Poker> myPoker, vector<Poker>commonPoker, int otherPlayerNum)
{

	if(myPoker.size() != 2 || commonPoker.size() < 3 || commonPoker.size() > 5 || otherPlayerNum < 1 || otherPlayerNum > 7)
	{
		printf("ERROR:myPokerSize:%ld, commonPokerSize:%ld, otherPlayersNum:%d\n",myPoker.size(), commonPoker.size(),  otherPlayerNum);
		return 0.0;
	}
	//获取我牌的类型和最大的点数
	int myPokerType;
	myPoker.insert(myPoker.end(), commonPoker.begin(), commonPoker.end());
	vector<Poker> myMaxPoker;
	myPokerType = pokerTypeAll(myPoker, myMaxPoker);

	//验证我的牌和公共牌是否有效
	if(!ValidatePoker(myPoker))
	{
		printf("ERROR:ValidatePoker\n");
		for(int i = 0; i < myPoker.size(); ++i)
		{
			printf("(%d,%d)", myPoker[i].point, myPoker[i].color);
		}
		printf("\n");
		return 0.0;
	}
	//生成一副新牌
	vector<Poker> allPoker;
	NewAllPoker(allPoker);



	//从新牌中去除已知的牌
	vector<Poker> enumPoker;
	int i,j;
	for(i = 0; i < allPoker.size(); ++i)
	{
		bool bIn = false;
		for(j = 0; j < myPoker.size(); ++j)
		{
			if(myPoker[j].color == allPoker[i].color && myPoker[j].point == allPoker[i].point)
			{
				bIn = true;
				break;
			}
		}
		if(bIn == false)
			enumPoker.push_back(allPoker[i]);
	}


	//枚举比我小的牌的种数
	int totalNum = 0;
	int lessThanMeNum = 0;
	for(i = 0; i < enumPoker.size() -1; ++i)
	{
		for(j =  i + 1; j < enumPoker.size(); ++j)
		{
			vector<Poker> otherPoker = commonPoker;
			otherPoker.push_back(enumPoker[i]);
			otherPoker.push_back(enumPoker[j]);

			int otherPokerType;
			vector<Poker> otherMaxPoker;
			otherPokerType = pokerTypeAll(otherPoker, otherMaxPoker);


			if((otherPokerType < myPokerType))
				lessThanMeNum ++;
			else if(otherPokerType == myPokerType)
			{
				int k = 0;
				for(k = 0; k < 5; ++k)
				{
					if(myMaxPoker[k].point == otherMaxPoker[k].point)
						continue;
					if(myMaxPoker[k].point > otherMaxPoker[k].point)
					{
						lessThanMeNum ++;
						break;
					}
				}
				/*
				if(k == 5)
					lessThanMeNum ++;
					*/
			}

			totalNum++;
		}
	}

	printf("totolNum:%d,lessThanMeNum:%d\n", totalNum, lessThanMeNum);

	//计算概率
	int restPokerNum = 52 - myPoker.size();
	double p = 1.0 * lessThanMeNum / CalCMethod(restPokerNum, 2);

	double pp = 1.0;
	for(i = 0; i < otherPlayerNum; ++i)
		pp *= (lessThanMeNum-i);
	int x = CalCMethod(restPokerNum,2);
	for(i = 0; i < otherPlayerNum; ++i)
		pp /= (x - i);

/*
	for(i = 0; i < otherPlayerNum; ++i)
	{
		pp /= CalCMethod(restPokerNum - i*2, 2);

	}
*/
/*
	double ppp = 1.0*CalCMethod(lessThanMeNum, otherPlayerNum);
		for(i = 0; i < otherPlayerNum; ++i)
		{
			ppp /= CalCMethod(restPokerNum - i*2, 2);
		}
*/
	if(pp < 0.0  || pp > 1.0)
	{
		printf("ERROR:\n");
		for(int i = 0; i < myPoker.size(); ++i)
			printf("(%d,%d)", myPoker[i].point, myPoker[i].color);
		printf("\n");
	}
	if(fabs(pp) < 0.000001 || fabs(pp - 1.0 ) < 0.000001)
	{
		printf("INFO,p:%f\n",pp);
				for(int i = 0; i < myPoker.size(); ++i)
					printf("(%d,%d)", myPoker[i].point, myPoker[i].color);
				printf("\n");
	}

	return pp;
}
