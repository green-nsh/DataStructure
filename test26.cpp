#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void test1()
{
	stack<int> s1;
	if(s1.empty()) cout << "empty." << endl;
	cout << "size: " << s1.size() << endl;

	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	cout << s1.top() << endl;
	s1.pop();
	cout << s1.top() << endl;
}

void test02()
{
	queue<int> q1;
	if(q1.empty()) cout << "empty." << endl;
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);
	q1.push(5);

	cout << "front: " << q1.front() << endl;
	cout << "back: " << q1.back() << endl;
	q1.pop();
	cout << "front: " << q1.front() << endl;
	cout << "back: " << q1.back() << endl;
	
}

int main()
{
	test02();
}