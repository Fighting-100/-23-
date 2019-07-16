#include "iostream"
using namespace std;

class Fruit
{
public:
	virtual void sayname() = 0;
};
class AbstractFactory
{
public:
	virtual Fruit* CreateBanana() = 0;
	virtual Fruit* CreateApple() = 0;
};

// �����㽶
class NorthBanana : public Fruit
{
public:
	virtual void sayname()
	{
		cout << "���Ǳ����㽶" << endl;
	}
};
//����ƻ��
class NorthApple : public Fruit
{
public:
	virtual void sayname()
	{
		cout << "���Ǳ���ƻ��" << endl;
	}
};
//��������
class NorthFoctory : public AbstractFactory
{
public:
	virtual Fruit* CreateBanana()
	{
		return new NorthBanana;
	}
	virtual Fruit* CreateApple()
	{
		return new NorthApple;
	}
};

// �Ϸ��㽶
class SourthBanana : public Fruit
{
public:
	virtual void sayname()
	{
		cout << "�����Ϸ��㽶" << endl;
	}
};
//�Ϸ�ƻ��
class SourthApple : public Fruit
{
public:
	virtual void sayname()
	{
		cout << "�����Ϸ�ƻ��" << endl;
	}
};
//�Ϸ�����
class SourthFoctory : public AbstractFactory
{
public:
	virtual Fruit* CreateBanana()
	{
		return new SourthBanana;
	}
	virtual Fruit* CreateApple()
	{
		return new SourthApple;
	}
};


void main()
{
	Fruit *fruit = NULL;
	AbstractFactory *af = NULL;
	//1�Ϸ�����
	af = new SourthFoctory;
	fruit = af->CreateBanana();
	fruit->sayname();
	delete fruit;
	fruit = af->CreateApple();
	fruit->sayname();
	delete fruit;
	//2 ��������
	af = new NorthFoctory;
	fruit = af->CreateBanana();
	fruit->sayname();
	delete fruit;
	fruit = af->CreateApple();
	fruit->sayname();
	delete fruit;

	cout << "hello....\n";
	system("pause");
}