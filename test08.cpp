#include <iostream>
#include <string>

using namespace std;

class Person{
public:
	void operator()(string name){
		cout << name << endl;
	}
};

void test()
{
	Person myprintf;
	myprintf("pucheng");

}
int main()
{
	test();
	return 0;
}