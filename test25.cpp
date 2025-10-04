#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <random>
#include <iomanip>

using namespace std;

/*使用随机数*/
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<> real_dis(60.0, 100.0);

class Person{
	friend void showInfo(const Person p);

public:
	Person(string name) : m_Name(name) {}

	void setScore(float score)
	{
		this->m_Score.push_back(score);
	}
	
	float getAverageScore(){
		if(this->m_Score.empty()) return 0.0f;
		sort(this->m_Score.begin(), this->m_Score.end());
		this->m_Score.pop_back();
		this->m_Score.pop_front();

		float averageScore = 0;
		for(size_t i = 0; i < this->m_Score.size(); i++)
		{
			averageScore += this->m_Score.at(i);
		}
		
		return averageScore / this->m_Score.size();
	}

private:
	string m_Name;
	deque<float> m_Score;
};

void showInfo(const Person p)
{
	cout << p.m_Name << ": ";
	for (deque<float>::const_iterator it = p.m_Score.begin(); it != p.m_Score.end(); it++)
	{
		cout << std::fixed << std::setprecision(2);
		cout << *it << ", ";
	}
	cout << "." << endl;
}

int main()
{
	Person p1("A"),p2("B"),p3("C"),p4("D"),p5("E");
	vector<Person*> player;
	player.push_back(&p1);
	player.push_back(&p2);
	player.push_back(&p3);
	player.push_back(&p4);
	player.push_back(&p5);

	/*输入成绩*/
	for (vector<Person*>::iterator it = player.begin(); it != player.end(); it++)
	{
		for(size_t i = 0; i < 10; i++)
		{
			(*it)->setScore(real_dis(gen));
		}
	}

	/*打印成绩*/
	for (vector<Person*>::iterator it = player.begin(); it != player.end(); it++)
	{
		showInfo(**it);
	}

	/*计算平均成绩*/
	for (vector<Person*>::iterator it = player.begin(); it != player.end(); it++)
	{
		cout << (*it)->getAverageScore() << ", ";
	}
	cout << endl;
	return 0;
}
