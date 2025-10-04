#include <iostream>

using namespace std;

template<typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test()
{
	int a = 10, b = 20;
	double c = 1.1, d = 2.2;
	mySwap(a,b);
	mySwap<double>(c,d);

	cout << "a = " << a << ", b= " << b << endl;
	cout << "c = " << c << ", d= " << d << endl;
}

int main()
{
	test();
	return 0;
}