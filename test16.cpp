#include <iostream>
#include <string>

using namespace std;

template<typename nameType, typename ageType = int> class Person
{
public:
    nameType m_Name;
    ageType  m_Age;

    Person(nameType name, ageType age)
        : m_Name(name)
        , m_Age(age)
    {}
    void showInfo();
};

template<typename nameType, typename ageType> void Person<nameType, ageType>::showInfo()
{
    cout << "name: " << this->m_Name << ", age: " << this->m_Age << endl;
}

void test() {
	Person<string> p1 = Person<string>("pucheng",25);
	Person<string,double> p2 = Person<string,double>("pucheng",25.5);
	p1.showInfo();
	p2.showInfo();
}

int main()
{
	test();
    return 0;
}
