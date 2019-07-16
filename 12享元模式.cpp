#include <iostream>
#include <string>
#include <map>
using namespace std;

class Person
{
public:
	Person(string name, int age):m_name(name),m_age(age){}
protected:
	string m_name;
	int m_age;
};

class Teacher : public Person
{
public:
	Teacher( string name, int age,string id) : Person(name, age),m_id(id){}
	string getId()
	{
		return m_id;
	}
	void printT()
	{
		cout << "id:" << m_id <<"\tname:" << m_name << "\tage:" << m_age << endl;
	}
private:
	string m_id;
};

class TeacherFactory
{
public:
	// 通过 Teacher 的 pool ，来存放老师结点，在 TeacherFactory 中创建老师、销毁老师
	Teacher *getTeacher(string tid)
	{
		string name;
		int age;
		Teacher *tmp = NULL;
		map<string, Teacher*>::iterator it = m_tpool.find(tid);
		if (it == m_tpool.end())
		{
			cout << "id 为: " << tid << " 的老师不存在 ,系统为你创建该老师， 请输入以下信息" <<endl;
			cout << "请输入老师姓名： ";
			cin >> name;
			cout << "请输入老师年龄： ";
			cin >> age;
			tmp = new Teacher(name, age,tid);
			m_tpool.insert(pair<string, Teacher*>(tid, tmp));
		}
		else
			tmp = it->second;
		return tmp;
	}

	~TeacherFactory()
	{
		// 内存管理永远是 c++程序员的痛
		while (!m_tpool.empty()) // 在工厂中创建老师结点，在工厂中销毁老师结点
		{
			Teacher *tmp = NULL;
			map<string, Teacher *>::iterator it = m_tpool.begin();
			tmp = it->second;
			m_tpool.erase(it);
			delete tmp;
		}
	}
private:
	map<string, Teacher *> m_tpool;
};

void main()
{
	TeacherFactory *teacherFactory = new TeacherFactory;
	Teacher *t1 = teacherFactory->getTeacher("001");
	t1->printT();
	Teacher *t2 = teacherFactory->getTeacher("001");
	t2->printT();
	delete teacherFactory;

	system("pause");
	return;
}