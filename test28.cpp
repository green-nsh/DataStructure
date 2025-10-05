#include <iostream>
#include <set>

using namespace std;

void showInfo(const set<int> s)
{
    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << ", ";
    }
    cout << endl;
}

void test01()
{
    set<int> s1;
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(4);
    s1.insert(2);
    showInfo(s1);

    auto it     = s1.begin();
    auto end_it = next(it, 2);
    s1.erase(it, end_it);
    showInfo(s1);

    it = s1.find(3);
    cout << *it << endl;
    cout << s1.count(3) << endl;
}

void test02()
{
    multiset<int> m1;
    m1.insert(1);
    m1.insert(3);
    m1.insert(1);
    m1.insert(3);
    m1.insert(1);
    m1.insert(3);

	for(auto it = m1.begin(); it != m1.end(); it++)
	{
		cout << *it << ", ";
 	}
	cout << endl;
}

int main()
{
    test02();
    return 0;
}