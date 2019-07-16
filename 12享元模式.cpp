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
	// ͨ�� Teacher �� pool ���������ʦ��㣬�� TeacherFactory �д�����ʦ��������ʦ
	Teacher *getTeacher(string tid)
	{
		string name;
		int age;
		Teacher *tmp = NULL;
		map<string, Teacher*>::iterator it = m_tpool.find(tid);
		if (it == m_tpool.end())
		{
			cout << "id Ϊ: " << tid << " ����ʦ������ ,ϵͳΪ�㴴������ʦ�� ������������Ϣ" <<endl;
			cout << "��������ʦ������ ";
			cin >> name;
			cout << "��������ʦ���䣺 ";
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
		// �ڴ������Զ�� c++����Ա��ʹ
		while (!m_tpool.empty()) // �ڹ����д�����ʦ��㣬�ڹ�����������ʦ���
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