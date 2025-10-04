#include <iostream>
#include <string>

using namespace std;

template<typename T1, typename T2>
class Person{
public:
	T1 m_Name;
	T2 m_Age;

	Person(T1 name, T2 age) : m_Name(name), m_Age(age) {}
	void showInfo(void);

};

template<typename T1, typename T2>
void Person<T1,T2>::showInfo()
{
	cout << "name: " << this->m_Name << ", " << "age: " << this->m_Age << "." << endl;
}

/*类模板对象做函数参数 1指定传入类型*/
void print1(Person<string,int> &s)
{
	s.showInfo();
}

/*类模板对象做函数参数 2参数模板化*/
template<typename T1, typename T2>
void print2(Person<T1, T2> &s)
{
	s.showInfo();
}

/*类模板对象做函数参数 3整个类参数化*/
template<typename T>
void print3(T& s)
{
	s.showInfo();
}

void test()
{
	
	Person<string,int> p("pucheng", 26);
	print1(p);
	print2(p);
	print3(p);
}

int main()
{
	test();
	return 0;
}