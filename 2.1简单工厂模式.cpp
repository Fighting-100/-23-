#include "iostream"
using namespace std;
// 思想： 核心思想是用一个工厂， 来根据输入的条件产生不同的类， 然后根据不同类的 virtual函数得到不同的结果。
// 元素分析：
// 抽象产品类：水果类
// 具体的水果了：香蕉类、苹果类、梨子
// 优点适用于不同情况创建不同的类时
// 缺点客户端必须要知道基类和工厂类，耦合性差增加一个产品，需要修改工厂类
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
		cout << " 香蕉 " << endl;
	}
};
class Pear : public Fruit
{
public:
	virtual void getFruit()
	{
		cout << " 梨子 " << endl;
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
		cout << " 创建 pear 失败 \n";
	}
	pear->getFruit();
	Fruit *banana = Factory::Create("banana");
	banana->getFruit();

	system("pause");
}
