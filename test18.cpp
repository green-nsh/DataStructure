#include <iostream>
#include <string>

using namespace std;

template<typename T1, typename T2>
class Person;

template<typename T1, typename T2>
void showInfo2(Person<T1,T2> &s)
{
	cout << "name: " << s.m_Name << ", age: " << s.m_Age << "." << endl;
}

template<typename T1, typename T2>
class Person{
	/*全局函数做友元 类内实现*/
	friend void showInfo1(Person<T1,T2> &s)
	{
		cout << "name: " << s.m_Name << ", age: " << s.m_Age << "." << endl;
	}
	/*全局函数做友元 类外实现*/
	friend void showInfo2<>(Person<T1,T2> &s);

public:
	Person(T1 name, T2 age) : m_Name(name), m_Age(age) {}

private:
	T1 m_Name;
	T2 m_Age;
};



void test01()
{
	Person<string, int> p("pucheng", 26);
	showInfo1(p);
}

void test02()
{
	Person<string, int> p("muchaofan", 25);
	showInfo2(p);
}

int main()
{
	test01();
	test02();
	return 0;
}