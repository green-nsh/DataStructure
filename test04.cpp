#include <iostream>
using namespace std;


class A;
class B{
public:
	B(int a, char b, string c);
	~B();
	void visit();
private:
	A *m_obj_a;
};


class A{
	friend void showInfo(const A& obj);
	friend void B::visit();
public:
	int a;
	char b;

	A(int a, char b, string c){
		this->a = a;
		this->b = b;
		this->c = c;
	}
private:
	string c;
};

B::B(int a, char b, string c)
{
	m_obj_a = new A(a, b, c);
}
B::~B()
{
	if(m_obj_a != NULL)
	{
		delete m_obj_a;
		m_obj_a = NULL;
	}
}
void B::visit()
{
	cout << m_obj_a->c << endl;
}


void showInfo(const A& obj)
{
	cout << "a = " << obj.a << endl;
	cout << "b = " << obj.b << endl;
	cout << "c = " << obj.c << endl;
}

void test01()
{
	A obj = A(1,0x56,"pucheng");
	showInfo(obj);
}

void test02()
{
	B obj_b = B(1,0x57,"muchaofan");
	obj_b.visit();
}

int main()
{
	test02();
	return 0;
}