#include <iostream>
using namespace std;
// 懒汉式
class Singelton
{
private:
	Singelton()
	{
		m_singer = NULL;
		m_count = 0;
		cout << "构造函数 Singelton ... do" << endl;
	}
public:
	static Singelton *getInstance()
	{
		if (m_singer == NULL) // 懒汉式： 1 每次获取实例都要判断		2 多线程会有问题
		{
			m_singer = new Singelton;
		}
		return m_singer;
	}
	static void printT()
	{
		cout << "m_count: " << m_count << endl;
	}
private:
	static Singelton *m_singer;
	static int m_count;
};
Singelton *Singelton::m_singer = NULL; // 懒汉式并没有创建单例对象
int Singelton::m_count = 0;

void main01_1()
{
	cout << "演示懒汉式 " << endl;
	Singelton *p1 = Singelton::getInstance(); // 只有在使用的时候，才去创建对象。
	Singelton *p2 = Singelton::getInstance();
	if (p1 != p2)
		cout << "不是同一个对象 " << endl;
	else
		cout << "是同一个对象 " << endl;

	p1->printT();
	p2->printT();
	system("pause");
	return;
}
/////////////////////////////////////////////////////////////////////////
// 饿汉式（较常使用）
class Singelton2
{
private:
	Singelton2()
	{
		m_singer = NULL;
		m_count = 0;
		cout << "构造函数 Singelton ... do" << endl;
	}
public:
	static Singelton2 *getInstance()
	{
		// if (m_singer == NULL )
		// {
		//		m_singer = new Singelton2;
		// }
		return m_singer;
	}
	static void Singelton2::FreeInstance()
	{
		if (m_singer != NULL)
		{
			delete m_singer;
			m_singer = NULL;
			m_count = 0;
		}
	}
	static void printT()
	{
		cout << "m_count: " << m_count << endl;
	}
private:
	static Singelton2 *m_singer;
	static int m_count;
};
Singelton2 *Singelton2::m_singer = new Singelton2; //不管你创建不创建实例，均把实例 new出来

int Singelton2::m_count = 0;
void main()
{
	cout << "演示饿汉式 " << endl;
	Singelton2 *p1 = Singelton2::getInstance(); // 只有在使用的时候，才去创建对象。
	Singelton2 *p2 = Singelton2::getInstance();
	if (p1 != p2)
		cout << "不是同一个对象 " << endl;
	else
		cout << "是同一个对象 " << endl;

	p1->printT();
	p2->printT();
	Singelton2::FreeInstance();
	Singelton2::FreeInstance();
	system("pause");
}
