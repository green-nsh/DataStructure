#include <iostream>
#include <string>
#include "MyArray.hpp"

using namespace std;

void test()
{
	MyArray<int> arr1(10);
	arr1.addElem(1);
	arr1.addElem(2);
	arr1.addElem(3);
	arr1.addElem(4);
	arr1.addElem(5);
	arr1.addElem(6);
	arr1.addElem(7);


	MyArray<int> arr2 = arr1;
	arr1.showInfo();
	arr2.showInfo();

	arr1.deleteElem();
	cout << "capacity: " << arr1.getCapacity() << ", " << "size: " << arr1.getSize() << endl;
	cout << "capacity: " << arr2.getCapacity() << ", " << "size: " << arr2.getSize() << endl;

	arr2 = arr1;
	arr2[0] = 101;
	arr2.showInfo();
}

int main()
{
	test();
	return 0;
}
