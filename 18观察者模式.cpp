#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Secretary;
// ����Ϸ��ͬ���ࣨ�۲��ߣ�
class PlayserObserver
{
public:
	PlayserObserver(string name, Secretary *secretary)
	{
		m_name = name;
		m_secretary = secretary;
	}
	void update(string action)
	{
		cout << "�۲��ߣ�"<< m_name << " �յ� action:" << action << endl;
	}
private:
	string m_name;
	Secretary *m_secretary;
};
// �����ࣨ�������֪ͨ�ߣ�
class Secretary
{
public:
	void addObserver(PlayserObserver *o)
	{
		v.push_back(o);
	}
	void Notify(string action)
	{
		for (vector<PlayserObserver *>::iterator it = v.begin(); it != v.end(); it++)
			(*it)->update(action);
	}
private:
	vector<PlayserObserver *> v;
};
void main()
{
	//subject ���۲���
	Secretary *s1 = new Secretary;
	// ����Ĺ۲��߱�֪ͨ����
	PlayserObserver *po1 = new PlayserObserver(" С�� ", s1);
	PlayserObserver *po2 = new PlayserObserver(" С�� ", s1);
	s1->addObserver(po1);
	s1->addObserver(po2);

	s1->Notify(" �ϰ����� ");
	s1->Notify(" �ϰ����� ");

	cout << "hello..." << endl;
	system("pause");
	return;
}