#include <iostream>
#include <string>

using namespace std;

void test01()
{
	pair<string, int> p1("Pucheng", 25);
	pair<string, int> p2 = make_pair("chaofan",24);

	cout << p1.first << ": " << p1.second << endl;
	cout << p2.first << ": " << p2.second << endl;
}

int main()
{
	test01();
	return 0;
}