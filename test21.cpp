#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Person{
public:
	Person(string name, int age) : m_Name(name), m_Age(age) {}

	string m_Name;
	int m_Age;
};

void test1()
{
	Person p1("pucheng", 25);
	Person p2("sunwukong", 999);
	Person p3("chengnong", 25);

	vector<Person> v1;
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	
	for(vector<Person>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << "name: " << it->m_Name << ", age: " << it->m_Age << endl;
	}
}

void test2()
{
	Person p1("pucheng", 25);
	Person p2("sunwukong", 999);
	Person p3("chengnong", 25);

	vector<Person*> v1;
	v1.push_back(&p1);
	v1.push_back(&p2);
	v1.push_back(&p3);

	for(vector<Person*>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << "name: " << (*it)->m_Name << ", age: " << (*it)->m_Age << endl;
	}
}

int main()
{
	test1();
	test2();
	return 0;
}