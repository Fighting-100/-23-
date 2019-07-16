#include <iostream>
using namespace std;

class Current18v
{
public:
	virtual void use18vCurrent()
	{
		cout << "使用 18v 的交流电 " << endl;
	}
};

class Current220v
{
public:
	void use220vCurrent()
	{
		cout << "使用 220v 的交流电 " << endl;
	}
};

class Adapter : public Current18v
{
public:
	Adapter(Current220v *p220v)
	{
		m_p220v = p220v;
	}
	void use18vCurrent()
	{
		cout << "adapter 中使用电流 " << endl;
		m_p220v->use220vCurrent();
	}
private:
	Current220v * m_p220v;
};

void main()
{
	Current220v *p220v = new Current220v;
	Adapter *padapter = new Adapter(p220v);
	padapter->use18vCurrent();

	delete p220v;
	delete padapter;

	system("pause");
	return;
}
