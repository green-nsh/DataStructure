#include <iostream>

using namespace std;

class Animal{
public:
	virtual void speak(){
		cout << "动物在说话" << endl;
	}
};

class Cat : public Animal{
public:
	virtual void speak() override {
		cout << "猫在说话" << endl;
	}
};

class Dog : public Animal{
public:
	virtual void speak() override {
		cout << "狗在说话" << endl;
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