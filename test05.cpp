#include <iostream>

using namespace std;

class A
{
	friend ostream& operator<<(ostream& out, const A& obj);
public:
    A(int a, int b) : m_a(a), m_b(b) {}
    A operator+(const A& obj) { return A(this->m_a + obj.m_a, this->m_b + obj.m_b); }
	A& operator++();
	A operator++(int);
	A& operator--();
	A operator--(int);
	void showInfo();

private:
    int m_a;
    int m_b;
};

void A::showInfo()
{
    cout << "a = " << this->m_a << ", b = " << this->m_b << endl;
}
A& A::operator++()
{
	this->m_a ++;
	this->m_b ++;
	return *this;
}
A A::operator++(int)
{
	A temp = *this;
	this->m_a ++;
	this->m_b ++;
	return temp;
}
A& A::operator--()
{
	this->m_a --;
	this->m_b --;
	return *this;
}
A A::operator--(int)
{
	A temp = *this;
	this->m_a --;
	this->m_b --;
	return temp;
}


ostream& operator<<(ostream& out, const A& obj)
{
	out << "a = " << obj.m_a << ", b= " << obj.m_b;
	return out;
}

int main()
{
    A obj1 = A(1, 3);
    A obj2 = A(2, 3);
    A obj3 = A(4, 6);
    A obj4 = A(7, 8);

	cout << ++obj1 << " " << obj2++ << " ";
	cout << --obj3 << " " << obj4-- << " ";
    return 0;
}