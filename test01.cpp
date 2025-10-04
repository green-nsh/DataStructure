#include <iostream>
#include <cstring>

using namespace std;

class Person{
public:
	Person(const char *name, int height)
	{
		this->m_Name = new char[strlen(name) + 1];
		strcpy(this->m_Name, name);
		this->m_Height = new int(height);
	}

	Person(const Person& p)
	{
		this->m_Name = new char[strlen(p.m_Name) + 1];
		strcpy(this->m_Name, p.m_Name);
		this->m_Height = new int(*p.m_Height);
	}

	~Person()
	{
		if(this->m_Name != NULL) 
		{
			delete[] this->m_Name;
			this->m_Name = NULL;
		}

		if(this->m_Height != NULL) 
		{
			delete this->m_Height;
			this->m_Height = NULL;
		}
		cout << "Call xigou" << endl;
	}

	void showInfo()
	{
		cout << "Name: " << this->m_Name << " Height: " << *this->m_Height << endl;
	}
private:
	char* m_Name;
	int* m_Height;
};

void test()
{
	Person p1("pucheng", 170);
	p1.showInfo();
	Person p2 = Person(p1);
}

int main()
{
	test();
	return 0;
}