#include "msg.h"
#include <iostream>
#include <string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>

using namespace std;
void MsgProcessor::ResetRoundStatus()
 {
	 m_bAllIn = false;
 }
 int MsgProcessor::ProcessMsg(char* msg)
{
	 vector<string> vecMsg;

	string strMsg = msg;
	string strset = "\n";
	size_t prevBeginPos = 0;
	string keyWord = "";

	string singleMsg = "";
	do
	{

		size_t enterPos = strMsg.find_first_of(strset, prevBeginPos);
		if (enterPos != string::npos)
		{
			string line = strMsg.substr(prevBeginPos,
					enterPos - prevBeginPos + 1);
			singleMsg += line;
			size_t fixPos = line.find_first_of('/', 0);
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
			//cout<<line.c_str();
		}
		else
		{
			string line = strMsg.substr(prevBeginPos,
					strMsg.size() - prevBeginPos);
			singleMsg += line;
			vecMsg.push_back(singleMsg);

			// cout<<line.c_str();
			break;
		}
		prevBeginPos = enterPos + 1;
	} while (1);

	for(int i = 0; i < vecMsg.size(); ++i)
	{
        m_pokergame.prase(vecMsg[i]);
		m_vecMsg.push_back(vecMsg[i]);
		if(vecMsg[i].find_first_of("seat", 0) == 0)
					{
						ResetRoundStatus();
						m_RoundCount++;
					}
					else if(vecMsg[i].find_first_of("inquire", 0) == 0)
					{
						if (1 ||  m_bAllIn == false)
						{
							//char szMsg[] = "call \n";

							string s = m_strategy->action();
                            				const char* szMsg = s.c_str();
							send(m_socket, szMsg, strlen(szMsg), 0);
							m_bAllIn = true;
						}
					}
					else if(vecMsg[i].find_first_of("game-over", 0) == 0)
					{
							for(int i = 0; i < m_vecMsg.size(); ++i)
								cout<<m_vecMsg[i].c_str()<<endl<<"------------"<<endl<<endl<<endl;
							return 1;
					}

	}



	return 0;
}

