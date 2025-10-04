#include <iostream>
#include <string>

using namespace std;

class Person{
public:
	Person(string name, int age) : m_Name(name), m_Age(age){}

	bool operator==(const Person& obj)
	{
		if(this->m_Name == obj.m_Name && this->m_Age == obj.m_Age)
		{
			return true;
		}
		return false;
	}

	bool operator!=(const Person& obj)
	{
		if(this->m_Name == obj.m_Name && this->m_Age == obj.m_Age)
		{
			return false;
		}
		return true;
	}

private:
	string m_Name;
	int m_Age;
};

void test()
{
	Person p1("pucheng",20);
	Person p2("pucheng",20);
	Person p3("pucheng",40);

	if(p1 == p2)
	{
		cout << "p1 与 p2 相等" << endl;
	}

	if(p2 != p3)
	{
		cout << "p2 与 p3 不相等" << endl;
	}
}

int main()
{
	test();
	return 0;
}