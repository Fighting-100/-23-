#include <iostream>
using namespace std;

class Subject
{
public:
	virtual void SaleBook() = 0;
};
class RealSubject : public Subject
{
public:
	virtual void SaleBook()
	{
		cout << "ʵ������� ....\n";
	}
};
class ProxyTaoBao : public Subject
{
public:
	virtual void SaleBook()
	{
		Double11();
		RealSubject rs;
		rs.SaleBook();
		Double11();
	}
	void Double11()
	{
		cout << "Double11 ���۰�� " << endl;
	}
};
class ProxyTaoBao2 : public Subject
{
public:
	void SetRealSubject(RealSubject *rs)
	{
		m_s = rs;
	}
	virtual void SaleBook()
	{
		Double11();
		m_s->SaleBook();
		Double11();
	}
	void Double11()
	{
		cout << "Double11 ���۰�� " << endl;
	}
private:
	RealSubject * m_s;
};

void main()
{
	ProxyTaoBao *ptb = new ProxyTaoBao;
	ptb->SaleBook();
	delete ptb;

	RealSubject* rs = new RealSubject;
	ProxyTaoBao2* ptb2 = new ProxyTaoBao2;
	ptb2->SetRealSubject(rs);
	ptb2->SaleBook();
	delete ptb2;

	return;
}