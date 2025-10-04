#include <iostream>

using namespace std;

template<typename T>
void mySort(T arr[], int len)
{
    int minInd;
    for (size_t i = 0; i < len; i++) {
        minInd = i;
        for (size_t j = i + 1; j < len; j++) {
            if (arr[j] < arr[minInd]) minInd = j;
        }

        T temp    = arr[minInd];
        arr[minInd] = arr[i];
        arr[i]      = temp;
    }
}

template<typename T>
void showInfo(T arr[], int len)
{
    cout << "sorted data: ";
    for (size_t i = 0; i < len; i++) {
        cout << arr[i];
        if (i < len - 1)
            cout << ", ";
        else
            cout << ".";
    }
	cout << endl;
}

void test()
{
    int intArray[] = {2, 5, 3, 1, 7};
	char charArray[] = "dbacjbgtedbgaj";

    mySort(intArray, sizeof(intArray) / sizeof(int));
    showInfo(intArray, sizeof(intArray) / sizeof(int));

	mySort(charArray, sizeof(charArray) / sizeof(char) - 1);
    showInfo(charArray, sizeof(charArray) / sizeof(char) - 1);
}

int main()
{
    test();
    return 0;
}