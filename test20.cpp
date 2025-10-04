#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void showInfo(int val)
{
	cout << val << ", ";
}

int main()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(8);

	/*第一种遍历*/
	vector<int>::iterator itB = v1.begin();
	vector<int>::iterator itE = v1.end();
	while(itB != itE){
		cout << *itB << ", ";
		itB ++;
	}
	cout << "." << endl;

	/*第二种遍历*/
	for(vector<int>::iterator it = v1.begin(); it<v1.end(); it++)
	{
		cout << *it << ", ";
	}
	cout << "." << endl;

	/*第三种遍历*/
	for_each(v1.begin(), v1.end(), showInfo);
	cout << "." << endl;
}