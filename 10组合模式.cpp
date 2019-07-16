#include <iostream>
#include <string>
#include <list>
using namespace std;

class IFile
{
public:
	virtual void display() = 0;
	virtual int add(IFile *ifile) = 0;
	virtual int remove(IFile *ifile) = 0;
	virtual list<IFile *>* getChild() = 0;
};

class File : public IFile
{
public:
	File(string name):m_name(name){}

	virtual void display()
	{
		cout << m_name << endl;
	}

	virtual int add(IFile *ifile)
	{
		return -1;
	}

	virtual int remove(IFile *ifile)
	{
		return -1;
	}

	virtual list<IFile *>* getChild()
	{
		return NULL;
	}
private:
	string m_name;
};

class Dir : public IFile
{
public:
	Dir(string name) 
	{
		m_name = name;
		m_list = new list<IFile*>;
		m_list->clear();
	}

	virtual void display()
	{
		cout << m_name << endl;
	}

	virtual int add(IFile *ifile)
	{
		m_list->push_back(ifile);
		return 0;
	}

	virtual int remove(IFile *ifile)
	{
		m_list->remove(ifile);
		return 0;
	}

	virtual list<IFile *>* getChild()
	{
		return m_list;
	}
private:
	string m_name;
	list<IFile*>* m_list;
};
//µÝ¹éÏÔÊ¾Ä¿Â¼
void showTree(IFile* root,int num)
{
	if (root == NULL) return;
	for (int i = 0; i < num; i++)
		cout << " ";
	root->display();
	list<IFile*>* child = root->getChild();
	if (child == NULL) return;
	for (list<IFile*>::iterator it = child->begin(); it != child->end(); it++)
		showTree(*it, num + 1);
}

void main()
{
	IFile* dirC = new Dir("C");
	IFile* dirA = new Dir("A");
	IFile* fileB = new File("B");
	dirC->add(dirA);
	dirC->add(fileB);
	IFile* file1 = new File("1");
	IFile* Dir2 = new Dir("2");
	dirA->add(file1);
	dirA->add(Dir2);

	showTree(dirC,0);

	system("pause");
	return;
}