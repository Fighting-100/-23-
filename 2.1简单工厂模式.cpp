#include "iostream"
using namespace std;
// ˼�룺 ����˼������һ�������� ���������������������ͬ���࣬ Ȼ����ݲ�ͬ��� virtual�����õ���ͬ�Ľ����
// Ԫ�ط�����
// �����Ʒ�ࣺˮ����
// �����ˮ���ˣ��㽶�ࡢƻ���ࡢ����
// �ŵ������ڲ�ͬ���������ͬ����ʱ
// ȱ��ͻ��˱���Ҫ֪������͹����࣬����Բ�����һ����Ʒ����Ҫ�޸Ĺ�����
class Fruit
{
public:
	virtual void getFruit() = 0;
};
class Banana : public Fruit
{
public:
	virtual void getFruit()
	{
		cout << " �㽶 " << endl;
	}
};
class Pear : public Fruit
{
public:
	virtual void getFruit()
	{
		cout << " ���� " << endl;
	}
};
class Factory
{
public:
	static Fruit* Create(char *name)
	{
		Fruit *tmp = NULL;
		if (strcmp(name, "pear") == 0)
		{
			tmp = new Pear();
		}
		else if (strcmp(name, "banana") == 0)
		{
			tmp = new Banana();
		}
		else
		{
			return NULL;
		}
		return tmp;
	}
};
void main()
{
	Fruit *pear = Factory::Create("pear");
	if (pear == NULL)
	{
		cout << " ���� pear ʧ�� \n";
	}
	pear->getFruit();
	Fruit *banana = Factory::Create("banana");
	banana->getFruit();

	system("pause");
}
