#include <iostream>
#include <set>
#include <string>

using namespace std;

class Person
{
public:
    Person(string name, int age)
        : m_Name(name)
        , m_Age(age)
    {}

    string m_Name;
    int    m_Age;
};

class MyCompare{
public:
	bool operator()(Person* p1, Person* p2) const
	{
		return p1->m_Age > p2->m_Age;
	}
};

void showInfo(set<Person*, MyCompare> s)
{
	for(auto it = s.begin(); it != s.end(); it ++ )
	{
		cout << (*it)->m_Name << ", " << (*it)->m_Age << endl;
	}
}

void test() {
	Person p1("ÕÅ·É", 27);
	Person p2("¹ØÓð", 24);
	Person p3("Áõ±¸", 23);
	Person p4("ÕÔÔÆ", 20);
	Person p5("Öî¸ðÁÁ", 30);

	set<Person*, MyCompare> s;
	s.insert(&p1);
	s.insert(&p2);
	s.insert(&p3);
	s.insert(&p4);
	s.insert(&p5);
	showInfo(s);
}

int main()
{
    test();
    return 0;
}