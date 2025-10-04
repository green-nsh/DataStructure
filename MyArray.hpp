#pragma once

#include <iostream>
#include <string>

using namespace std;

template<typename T>
class MyArray{
public:
	MyArray(size_t capacity) : m_Capacity(capacity) { this->m_Size = 0; this->m_ArrayPtr = new T[capacity]; }
	MyArray(const MyArray& other);
	~MyArray();
	size_t getCapacity();
	size_t getSize();
	void addElem(T a);
	void deleteElem();
	void showInfo();
	MyArray& operator=(const MyArray& other);
	T& operator[](size_t index);



private:
	T* m_ArrayPtr = nullptr;
	size_t m_Capacity;
	size_t m_Size;
};

template<typename T>
MyArray<T>::MyArray(const MyArray& other){
	this->m_Capacity = other.m_Capacity;
	this->m_Size = other.m_Size;
	this->m_ArrayPtr = new T[this->m_Capacity];
	for(size_t i = 0; i < this->m_Size; i++)
	{
		this->m_ArrayPtr[i] = other.m_ArrayPtr[i];
	}
}

template<typename T>
MyArray<T>::~MyArray()
{
	if (m_ArrayPtr != nullptr)
	{
		delete[] m_ArrayPtr;
		m_ArrayPtr = nullptr;
	}
}

template<typename T>
size_t MyArray<T>::getCapacity()
{
	return this->m_Capacity;
}

template<typename T>
size_t MyArray<T>::getSize()
{
	return this->m_Size;
}

template<typename T>
void MyArray<T>::addElem(T a)
{
	if(this->m_Size == this->m_Capacity) return;
	this->m_ArrayPtr[this->m_Size] = a;
	this->m_Size ++;
}

template<typename T>
void MyArray<T>::deleteElem()
{
	if(this->m_Size == 0) return;
	if(this->m_Size != 0) this->m_Size --;
}

template<typename T>
void MyArray<T>::showInfo()
{
	cout << "element: ";
	for (size_t i = 0; i < this->m_Size - 1; i++)
	{
		cout << this->m_ArrayPtr[i] << ", ";
	}
	cout << this->m_ArrayPtr[this->m_Size - 1] << "." << endl;
}

template<typename T>
MyArray<T>& MyArray<T>::operator=(const MyArray<T>& other)
{
	if(this->m_ArrayPtr != nullptr) 
	{
		delete[] this->m_ArrayPtr;
	}

	this->m_Capacity = other.m_Capacity;
	this->m_Size = other.m_Size;
	this->m_ArrayPtr = new T[this->m_Capacity];
	for(size_t i = 0; i < this->m_Size; i++)
	{
		this->m_ArrayPtr[i] = other.m_ArrayPtr[i];
	}

	return *this;
}

template<typename T>
T& MyArray<T>::operator[](size_t index)
{
	return this->m_ArrayPtr[index];
}