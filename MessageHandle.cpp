#include <iostream>
#include "TcpMessageHandle.h"

using namespace std;

void showInfo(std::vector<std::vector<std::string>> List)
{
	for (std::vector<std::string> i : List)
	{
		for (std::string j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}
}

int main()
{
	TcpMessageHandle *tcpMsgHandle = new TcpMessageHandle;

	tcpMsgHandle->Recieve("hello,pu$,cheng,world;");
	tcpMsgHandle->Recieve("123,mu$,chang$,fan,world;");
	tcpMsgHandle->Recieve("456,ma$,cheng$,yang,world;");
	tcpMsgHandle->Recieve("12345$;");
	tcpMsgHandle->Recieve(";");
	std::vector<std::vector<std::string>> messageList = tcpMsgHandle->GetMessageList();

	showInfo(messageList);
	cout << tcpMsgHandle->CreateMessage(messageList[0]) << endl;

	return 0;
}