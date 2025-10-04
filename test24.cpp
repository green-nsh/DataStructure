#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

void showInfo(const deque<int>& d)
{
	for (deque<int>::const_iterator it=d.begin(); it != d.end(); it++)
	{
		cout << *(it) << " ";
	}
	cout << endl;
}

void test01()
{
	deque<int> d1;
	for (size_t i = 0; i < 100; i++)
	{
		d1.push_front(i);
	}

	deque<int> d2(d1.begin(),d1.end());
	showInfo(d2);

	deque<int> d3(10,100);
	showInfo(d3);

	deque<int> d4;
	d4.assign(d1.begin(), d1.begin()+10);
	showInfo(d4);


}

void test02()
{
	deque<int> d1;
	for (size_t i = 0; i < 10; i++)
	{
		d1.push_back(i+1);
	}
	showInfo(d1);

	deque<int>::iterator it = d1.begin();
	d1.insert(it,5,5);
	showInfo(d1);

	sort(d1.begin(), d1.begin() + 7);
	showInfo(d1);
}

int main()
{
	test02();
	return 0;
}