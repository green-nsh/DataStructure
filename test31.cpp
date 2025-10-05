#include <iostream>
#include <map>

using namespace std;

void test()
{
	map<int,int> m1;
	m1.insert(make_pair(1,10));
	m1.insert(make_pair(2,9));
	m1.insert(make_pair(3,13));
	m1.insert(make_pair(5,8));

	for(auto it = m1.begin(); it != m1.end(); it ++ )
	{
		cout << "Key: " << it->first << ", value: " << it->second << endl;
	}
}

int main()
{
	test();
	return 0;
}