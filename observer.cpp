#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Observer
{
public:
    virtual void update(int data) = 0;
};

class Subject
{
public:
    void attach(Observer* obj) { m_observer_list.push_back(obj); }

    void notify(int data)
    {
        for (Observer* it : m_observer_list) {
            it->update(data);
        }
    }

private:
    vector<Observer*> m_observer_list;
};

class LogSystem : public Observer
{
public:
    virtual void update(int data) override { cout << "log system: " << data << endl; }
};

class Alertor : public Observer
{
public:
    virtual void update(int data) override {
		if(data >= 100) cout << "the value is too high." << endl;
	}
};

int main()
{
	/*被观察者*/
	Subject sensor;
	/*观察者*/
	LogSystem log;
	Alertor ale;

	/*绑定*/
	sensor.attach(&log);
	sensor.attach(&ale);

	/*通知*/
	sensor.notify(10);
	sensor.notify(100);
	sensor.notify(120);

    return 0;
}