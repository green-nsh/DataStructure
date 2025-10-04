#include <iostream>

using namespace std;

class Animal{
public:
	virtual void speak(){
		cout << "������˵��" << endl;
	}
};

class Cat : public Animal{
public:
	virtual void speak() override {
		cout << "è��˵��" << endl;
	}
};

class Dog : public Animal{
public:
	virtual void speak() override {
		cout << "����˵��" << endl;
	}

};

void doSpeak(Animal& animal){
	animal.speak();
}

void test(){
	Cat cat;
	doSpeak(cat);

	Dog dog;
	doSpeak(dog);
}

int main(){
	test();
	return 0;
}