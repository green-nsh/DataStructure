#include <iostream>
#include <string>
using namespace std;

class Phone{
public:
	string m_Name;

	Phone(string phone_name):m_Name(phone_name)
	{
		cout << "调用Phone构造函数" << endl;
	}
	~Phone()
	{
		cout << "调用Phone析构函数" << endl;
	}
};

class Person{
public:
	string m_Name;
	Phone m_Phone;

	Person(string name, string phone):m_Name(name), m_Phone(phone)
	{
		cout << "调用Person构造函数" << endl;
	}
	~Person()
	{
		cout << "调用Person析构函数" << endl;
	}
};



int main()
{
	Person p("张三","iphone 17");
	return 0;
}