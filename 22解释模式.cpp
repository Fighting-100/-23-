#include <iostream>
#include <string>
using namespace std;

class Context
{
public:
	Context(int num)
	{
		m_num = num;
	}
	void setNum(int num)
	{
		m_num = num;
	}
	int getNum()
	{
		return m_num;
	}
	void setRes(int res)
	{
		m_res = res;
	}
	int getRes()
	{
		return m_res;
	}
private:
	int m_num;
	int m_res;
};

class Expression
{
public:
	virtual void interpreter(Context *context) = 0;
};
class PlusExpression : public Expression
{
public:
	virtual void interpreter(Context *context)
	{
		int num = context->getNum();
		num++;
		context->setNum(num);
		context->setRes(num);
	}
};
class MinusExpression : public Expression
{
public:
	virtual void interpreter(Context *context)
	{
		int num = context->getNum();
		num--;
		context->setNum(num);
		context->setRes(num);
	}
};

void main()
{
	Context		*pcxt = new Context(10);
	Expression	*e1 = new PlusExpression;

	cout << "start context:" << pcxt->getNum() << endl;
	e1->interpreter(pcxt);
	cout << "PlusExpression:" << pcxt->getRes() << endl;
	Expression *e2 = new MinusExpression;
	e2->interpreter(pcxt);
	cout << "MinusExpression:" << pcxt->getRes() << endl;

	delete pcxt;
	delete e2;
	delete e1;

	system("pause");
	return;
}