#include <iostream>
#include <string>
#include <vector>

using namespace std;

void test01()
{
	vector<double> v1;
	v1.reserve(10000);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	cout << "capacity:" << v1.capacity() << "  size: " << v1.size() << endl;

	vector<double> (v1).swap(v1);
	cout << "capacity:" << v1.capacity() << "  size: " << v1.size() << endl;
}

void test02()
{
	vector<int> v1;
	v1.reserve(1e5);

	int *ptr = nullptr;
	int num = 0;

	for (size_t i = 0; i < 1e5; i++)
	{
		v1.push_back(i);
		if(ptr != &v1.at(0))
		{
			num++;
			ptr = &v1.at(0);
		}
	}

	cout << "assign : " << num << endl;
}

int main()
{
	test02();
	return 0;
}