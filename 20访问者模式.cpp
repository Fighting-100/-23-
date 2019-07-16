#include <iostream>
#include <string>
#include <list>
using namespace std;

class ParkElement;
// ��ͬ�ķ����߷��ʹ�԰��ɲ�ͬ�Ķ���
class Visitor
{
public:
	virtual void visit(ParkElement *park) = 0;
};
class ParkElement
{
public:
	virtual void accept(Visitor *v) = 0;//��԰���շ������÷�����������
};

class ParkA : public ParkElement
{
public:
	virtual void accept(Visitor *v)
	{
		v->visit(this);
	}
};
class ParkB : public ParkElement
{
public:
	virtual void accept(Visitor *v)
	{
		v->visit(this);
	}
};
class Park : public ParkElement
{
public:
	Park()
	{
		m_list.clear();
	}
	void setPart(ParkElement *e)
	{
		m_list.push_back(e);
	}
public:
	void accept(Visitor *v)
	{
		for (list<ParkElement *>::iterator it = m_list.begin(); it != m_list.end(); it++)
		{
			(*it)->accept(v);
		}
	}
private:
	list<ParkElement *> m_list;
};

class VisitorA : public Visitor
{
public:
	virtual void visit(ParkElement *park)
	{
		cout << "��๤ A ���ʹ�԰ A ���֣���ɨ������� " << endl;
	}
};
class VisitorB : public Visitor
{
public:
	virtual void visit(ParkElement *park)
	{
		cout << "��๤ B ���ʹ�԰ B ���֣���ɨ������� " << endl;
	}
};
class VisitorManager : public Visitor
{
public:
	virtual void visit(ParkElement *park)
	{
		cout << "����Ա���������԰������ɨ��� " << endl;
	}
};

void main()
{
	Visitor *visitorA = new VisitorA;
	Visitor *visitorB = new VisitorB;
	ParkElement *partA = new ParkA;
	ParkElement *partB = new ParkB;
	// ��԰���ܷ����� a ����
	partA->accept(visitorA);
	partB->accept(visitorB);
	Visitor *visitorManager = new VisitorManager;
	Park * park = new Park;
	park->setPart(partA);
	park->setPart(partB);
	park->accept(visitorManager);

	cout << "hello..." << endl;
	system("pause");
	return;
}