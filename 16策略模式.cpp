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
		cout << "DES 加密 " << endl;
	}
};
class AES : public Strategy
{
public:
	virtual void SymEncrypt()
	{
		cout << "AES 加密 " << endl;
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
// 算法的实现和客户端的使用解耦合
// 使得算法变化，不会影响客户端
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