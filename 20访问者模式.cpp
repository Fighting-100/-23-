#include <iostream>
#include <string>
#include <list>
using namespace std;

class ParkElement;
// 不同的访问者访问公园完成不同的动作
class Visitor
{
public:
	virtual void visit(ParkElement *park) = 0;
};
class ParkElement
{
public:
	virtual void accept(Visitor *v) = 0;//公园接收访问者让访问者做操作
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
		cout << "清洁工 A 访问公园 A 部分，打扫卫生完毕 " << endl;
	}
};
class VisitorB : public Visitor
{
public:
	virtual void visit(ParkElement *park)
	{
		cout << "清洁工 B 访问公园 B 部分，打扫卫生完毕 " << endl;
	}
};
class VisitorManager : public Visitor
{
public:
	virtual void visit(ParkElement *park)
	{
		cout << "管理员检查整个公园卫生打扫情况 " << endl;
	}
};

void main()
{
	Visitor *visitorA = new VisitorA;
	Visitor *visitorB = new VisitorB;
	ParkElement *partA = new ParkA;
	ParkElement *partB = new ParkB;
	// 公园接受访问者 a 访问
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