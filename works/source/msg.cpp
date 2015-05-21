#include "msg.h"
#include <iostream>
#include <string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>

using namespace std;
void MsgProcessor::ResetRoundStatus()
 {
		m_rs = RS_BEGIN;
 }
 int MsgProcessor::ProcessMsg(char* msg)
{
	 //m_orgMsg.push_back(msg);

	vector < string > vecMsg;

	string strMsg = msg;
	string strset = "\n";
	size_t prevBeginPos = 0;
	string keyWord = "";

	string singleMsg = "";

	do
	{
		size_t enterPos = strMsg.find(strset, prevBeginPos);
		if (enterPos != string::npos)
		{
			string line = strMsg.substr(prevBeginPos,
					enterPos - prevBeginPos + 1);
			singleMsg += line;
			size_t fixPos = line.find('/', 0);
			if (fixPos > 0)
			{
				if (keyWord == "")
					keyWord = line.substr(0, fixPos);

			}
			else if (fixPos == 0)
			{
				string name = line.substr(1, line.size() - 3);
				if (name == keyWord)
				{
					vecMsg.push_back(singleMsg);
					singleMsg = "";
					keyWord = "";
				}
			}
		}
		else
		{
			string line = strMsg.substr(prevBeginPos,
					strMsg.size() - prevBeginPos);
			singleMsg += line;
			vecMsg.push_back(singleMsg);

			break;
		}
		prevBeginPos = enterPos + 1;
	} while (1);



	for (int i = 0; i < vecMsg.size(); ++i)
	{
		m_pokergame.prase(vecMsg[i]);
		m_vecMsg.push_back(vecMsg[i]);
		if (vecMsg[i].find("seat") == 0)//座次信息，包含庄家，小盲注，大盲注和其他玩家筹码和金币数
		{
			//ResetRoundStatus();
			m_RoundCount++;
		}
		else if (vecMsg[i].find("blind") == 0)	//小大盲注信息
		{

		}
		else if (vecMsg[i].find("hold") == 0)				//手牌消息
		{

		}
		else if (vecMsg[i].find("inquire") == 0)			//询问消息
		{

			SendMsgToServer();

		}
		else if (vecMsg[i].find("flop", 0) == 0)				//公牌消息
		{

		}
		else if (vecMsg[i].find("turn") == 0)				//转牌消息
		{

		}
		else if (vecMsg[i].find("river") == 0)				//河牌消息
		{

		}
		else if (vecMsg[i].find("showdown") == 0)			//摊牌消息
		{

		}
		else if (vecMsg[i].find("pot-win") == 0)			//彩池分配消息
		{

		}
		else if (vecMsg[i].find("game-over") == 0)		//本场比赛结束
		{
			/*
			for (int i = 0; i < m_vecMsg.size(); ++i)
				cout << m_vecMsg[i].c_str() << endl << "------------" << endl
						<< endl << endl;
						*/

/*
			for(int i = 0; i < m_orgMsg.size(); ++i)
				cout<< "!!!!!" << endl << m_orgMsg[i].c_str() << "!!!!!" << endl;
*/
			return 1;
		}

	}

	return 0;
}


 void MsgProcessor::SendMsgToServer()
{
	if (m_strategyName == "check")	//当前策略总是让牌
	{
		string s = m_pokergame.GetStrategy()->ActionAsAllCheck();
		const char* szMsg = s.c_str();
		send(m_socket, szMsg, strlen(szMsg), 0);
		m_rs = RS_CHECK;
	}
	else if (m_strategyName == "raise")	//当前策略总是加注
		{
			string s =  m_pokergame.GetStrategy()->ActionAsAllRaise();
			const char* szMsg = s.c_str();
			send(m_socket, szMsg, strlen(szMsg), 0);
			m_rs = RS_CALL;
		}
	else if (m_strategyName == "call")	//当前策略总是跟注
	{
		string s =  m_pokergame.GetStrategy()->ActionAsAllCall();
		const char* szMsg = s.c_str();
		send(m_socket, szMsg, strlen(szMsg), 0);
		m_rs = RS_CALL;
	}
	else if (m_strategyName == "allin")	//当前策略总是全押
	{
		string s =  m_pokergame.GetStrategy()->ActionAsAllAllin();
		const char* szMsg = s.c_str();
		send(m_socket, szMsg, strlen(szMsg), 0);
		m_rs = RS_ALL_IN;
	}
	else if (m_strategyName == "fold")	//当前策略总是弃牌
		{
			string s =  m_pokergame.GetStrategy()->ActionAsAllFold();
			const char* szMsg = s.c_str();
			send(m_socket, szMsg, strlen(szMsg), 0);
			m_rs = RS_FOLD;
		}
	else if (m_strategyName == "random")	//当前策略总是随机
		{
			string s =  m_pokergame.GetStrategy()->ActionAsAllRandom();
			const char* szMsg = s.c_str();
			send(m_socket, szMsg, strlen(szMsg), 0);
		}
	else
	{
		string s =  m_pokergame.GetStrategy()->Action();
		const char* szMsg = s.c_str();
		send(m_socket, szMsg, strlen(szMsg), 0);

	}
}
