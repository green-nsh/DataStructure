#include <iostream>

using namespace std;

class Person{
public:
	Person(int age){
		m_Age = new int(age);
	}
	~Person()
	{
		if(m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}
	
	void showInfo()
	{
		cout << "ang = " << *m_Age << endl;
	}

	Person& operator=(Person& obj)
	{
		if(this->m_Age != NULL)
		{
			delete this->m_Age;
			this->m_Age = NULL;
		}
		this->m_Age = new int(*obj.m_Age);

		return *this;
	}

private:
	int* m_Age;
};

void test()
{
	Person p1 = Person(12);
	Person p2 = Person(18);
	Person p3 = Person(30);
	p1 = p2 = p3;
	p1.showInfo();
	p1.showInfo();
	p1.showInfo();
}

int main()
{
	test();
	return 0;
}