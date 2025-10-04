#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    string m_Name;
    int    m_Age;

    Person(string name, int age)
        : m_Name(name)
        , m_Age(age)
    {}
};

template<typename T>  bool personCompare(const T& a, const T& b)
{
    if (a == b)
        return true;
    else
        return false;
}

template<> bool personCompare(const Person& a, const Person& b)
{
	if(a.m_Age == b.m_Age && a.m_Name == b.m_Name) return true;
	else return false;
}

void test()
{
    Person p1(string("Pucheng"), 18);
    Person p2(string("Pucheng"), 20);
	bool flag = personCompare(p1,p2);
	if(flag) cout << "p1 == p2" << endl;
	else cout << "p1 != p2" << endl;
}

int main()
{
	test();
    return 0;
}