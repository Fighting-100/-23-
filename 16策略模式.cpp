#include <iostream>
using namespace std;

class Strategy
{
public:
	virtual void SymEncrypt() = 0;
};

class DES : public Strategy
{
public:
	virtual void SymEncrypt()
	{
		cout << "DES ���� " << endl;
	}
};
class AES : public Strategy
{
public:
	virtual void SymEncrypt()
	{
		cout << "AES ���� " << endl;
	}
};

class Context
{
public:
	void setContext(Strategy *strategy)
	{
		m_strategy = strategy;
	}
	void Operator()
	{
		m_strategy->SymEncrypt();
	}
private:
	Strategy * m_strategy;
};
// �㷨��ʵ�ֺͿͻ��˵�ʹ�ý����
// ʹ���㷨�仯������Ӱ��ͻ���
void main()
{
	Strategy *strategy = NULL;
	Context  *context = NULL;
	//strategy = new AES;
	strategy = new DES;
	context = new Context();

	context->setContext(strategy);
	context->Operator();

	delete strategy;
	delete context;
	cout << "hello..." << endl;
	system("pause");
	return;
}