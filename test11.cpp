#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	std::fstream fd;
	fd.open("./data.txt", std::ios::out);
	fd << "123" << endl;
	fd << "456" << endl;
	fd << "789" << endl;
	fd.close();

	std::fstream fs;
	string buf;
	fs.open("./data.txt", std::ios::in);
	if(fs.is_open() == false)
	{
		cout << "open file error!" << endl;
		return -1;
	}

	while(getline(fs, buf))
	{
		cout << buf << endl;
	}
	fs.close();

	return 0;
}