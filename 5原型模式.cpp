#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	virtual Person *Clone() = 0;
	virtual void printT() = 0;
};

class JavaProgrammer : public Person
{
public:
	JavaProgrammer()
	{
		this->m_name = "";
		this->m_age = 0;
		m_resume = NULL;
	}
	JavaProgrammer(string name, int age) :m_name(name), m_age(age), m_resume(NULL) {}
	
	~JavaProgrammer()
	{
		if (m_resume != NULL)
		{
			free(m_resume);
			m_resume = NULL;
		}
	}
	virtual Person *Clone()
	{
		JavaProgrammer *p = new JavaProgrammer;
		*p = *this;		//浅拷贝
		return p;
	}
	void setResume(char *resume)	//深拷贝
	{
		if (m_resume != NULL)
			delete m_resume;
		m_resume = new char[strlen(resume) + 1];
		strcpy(m_resume, resume);
	}
	virtual void printT()
	{
		cout << "m_name:" << m_name << "\t" << "m_age:" << m_age << endl;
		if (m_resume != NULL)
			cout << m_resume << endl;
	}
private:
	string m_name;
	int m_age;
	char *m_resume;
};
void main()
{
	JavaProgrammer javaperson1("张三 ", 30);
	javaperson1.setResume("我是 java 程序员 ");
	Person *p2 = javaperson1.Clone(); // 对象具有自我复制功能注意深拷贝和浅拷贝问题
	p2->printT();
	delete p2;

	cout << "hello..." << endl;
	system("pause");
	return;
}