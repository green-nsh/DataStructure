#include <iostream>

using namespace std;

class A{
public:
	int a;
	mutable int b;

public:
	A(int a, int b);
	void showInfo() const;
};

A::A(int a, int b)
{
	this->a = a;
	this->b = b;
}
void A::showInfo() const
{
	cout << this->b << endl;
}

void test01()
{
	const A obj_a = A(1,2);
	obj_a.b = 100;
	obj_a.showInfo();
}

int main(){

	test01();
	return 0;
}