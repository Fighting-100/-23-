#include <iostream>
using namespace std;
#include <string>

class Mediator;
class Person
{
public:
	Person(string name, int sex, int condition, Mediator *m)
	{
		m_name = name;
		m_sex = sex;
		m_condition = condition;
		m_m = m;
	}
	string getName()
	{
		return m_name;
	}
	int getSex()
	{
		return m_sex;
	}
	int getCondit()
	{
		return m_condition;
	}
	Mediator *getMediator()
	{
		return m_m;
	}
public:
	virtual void getParter(Person *p) = 0;
protected:
	string m_name; //
	int m_sex; //1 �� 2 Ů
	int m_condition; //123456789;
	Mediator *m_m;
};

class Mediator
{
public:
	Mediator()
	{
		pMan = NULL;
		pWoman = NULL;
	}
	void setWoman(Person *p)
	{
		pWoman = p;
	}
	void setMan(Person *p)
	{
		pMan = p;
	}
	void getPartner()
	{
		if (pMan->getSex() == pWoman->getSex())
		{
			cout << "No No No �Ҳ���ͬ���� " << endl;
		}
		if (pMan->getCondit() == pWoman->getCondit())
		{
			cout << pMan->getName() << " �� " << pWoman->getName() << " ���� " << endl;
		}
		else
		{
			cout << pMan->getName() << " �� " << pWoman->getName() << " ���� " << endl;
		}
	}
private:
	Person * pMan;
	Person * pWoman;
};

class Woman : public Person
{
public:
	Woman(string name, int sex, int condition, Mediator *m) : Person(name, sex, condition,m){}
	virtual void getParter(Person *p)
	{
		this->getMediator()->setWoman(this);
		this->getMediator()->setMan(p);
		this->getMediator()->getPartner();
	}
};
class Man : public Person
{
public:
	Man(string name, int sex, int condition, Mediator *m) : Person(name, sex, condition, m){}
	virtual void getParter(Person *p)
	{
		this->getMediator()->setMan(this);
		this->getMediator()->setWoman(p);
		this->getMediator()->getPartner();
	}
};

void main1902()
{
	Mediator *mediator = new Mediator;
	Woman *w1 = new Woman(" С�� ", 2, 4, mediator);
	Man *m1 = new Man(" ���� ", 1, 3, mediator);
	Man *m2 = new Man(" ���� ", 1, 4, mediator);
	w1->getParter(m1);
	w1->getParter(m2);
	delete w1;
	delete m1;
	delete m2;
	delete mediator;
}

void main()
{
	//main1901(); // ���������
	main1902(); // ���н���ģʽ�����Ż�
	system("pause");
}