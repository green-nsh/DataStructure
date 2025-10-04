#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Person{
public:
	Person() : m_Age(0) {
		m_Name[0] = '\0';
	}

	Person(const char * name, int age) : m_Age(age) {
		strncpy(m_Name, name, sizeof(name)-1);
		m_Name[sizeof(name)-1] = '\0';
	}

	void showInfo();

private:
	char m_Name[64];
	int m_Age;
};

void Person::showInfo(){
	cout << "p_read: m_Name:" << this->m_Name << endl;
	cout << "p_read: m_Age:" << this->m_Age << endl;
}

int main()
{
	char fileName[64] = "./data.txt";
	Person p = Person("pucheng", 25);

	/*写入文件*/
	fstream fs;
	fs.open(fileName, ios::out | ios::binary);
	if(fs.is_open() == false) {
		cout << "file reading failed!";
		return -1;
	}
	fs.write( (const char*)&p, sizeof(Person));
	fs.close();

	/*读取文件*/
	Person p_read;
	fs.open(fileName, ios::in);
	if(fs.is_open() == false) {
		cout << "file reading failed!";
		return -1;
	}
	fs.read((char*)&p_read, sizeof(Person));
	fs.close();
	p_read.showInfo();

	return 0;
}