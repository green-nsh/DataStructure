#include <iostream>
#include <string>
using namespace std;

class Phone{
public:
	string m_Name;

	Phone(string phone_name):m_Name(phone_name)
	{
		cout << "����Phone���캯��" << endl;
	}
	~Phone()
	{
		cout << "����Phone��������" << endl;
	}
};

class Person{
public:
	string m_Name;
	Phone m_Phone;

	Person(string name, string phone):m_Name(name), m_Phone(phone)
	{
		cout << "����Person���캯��" << endl;
	}
	~Person()
	{
		cout << "����Person��������" << endl;
	}
};



int main()
{
	Person p("����","iphone 17");
	return 0;
}