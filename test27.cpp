#include <iostream>
#include <list>
#include <string>

using namespace std;

class Person
{
public:
    Person(string name, int age, int height)
        : m_Name(name)
        , m_Age(age)
        , m_Height(height)
    {}

    string m_Name;
    int    m_Age;
    int    m_Height;
};

void showInfo(const list<Person*>& L)
{
	for(list<Person*>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "name: " << (*it)->m_Name << ", age: " << (*it)->m_Age << ", height: " << (*it)->m_Height << endl;
	}
}

bool compare(Person* p1, Person* p2)
{
	if(p1->m_Age == p2->m_Age) return p1->m_Height < p2->m_Height;
	return p1->m_Age < p2->m_Age;
}

void test()
{
	Person p1("A", 18, 165);
	Person p2("B", 30, 165);
	Person p3("C", 26, 180);
	Person p4("D", 26, 165);
	Person p5("E", 30, 165);

	list<Person*> L1;
	L1.push_back(&p1);
	L1.push_back(&p2);
	L1.push_back(&p3);
	L1.push_back(&p4);
	L1.push_back(&p5);

	showInfo(L1);
	cout << "-----------------------------" << endl;
	L1.sort(compare);
	showInfo(L1);

}

int main()
{
	test();
    return 0;
}