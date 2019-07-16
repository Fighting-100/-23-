#include <iostream>
#include <list>
using namespace std;

class Doctor
{
public:
	void treat_eye()
	{
		cout << "医生 治疗 眼科病" << endl;
	}
	void treat_nose()
	{
		cout << "医生 治疗 鼻科病" << endl;
	}
};

class Command
{
public:
	virtual void treat() = 0;
};

class CommandTreatEye : public Command
{
public:
	CommandTreatEye(Doctor* doctor) :m_doctor(doctor) {}
	void treat()
	{
		m_doctor->treat_eye();
	}
private:
	Doctor * m_doctor;
};
class CommandTreatNose : public Command
{
public:
	CommandTreatNose(Doctor* doctor) :m_doctor(doctor) {}
	void treat()
	{
		m_doctor->treat_nose();
	}
private:
	Doctor * m_doctor;
};

class Nurse
{
public:
	Nurse(Command* command) :m_command(command) {}
	void SubmittedCase()
	{
		m_command->treat();
	}
private:
	Command* m_command;
};

class NurseHead		//护士长批量执行护士的命令
{
public:
	NurseHead()
	{
		m_list.clear();
	}
	void setCommand(Command* command)
	{
		m_list.push_back(command);
	}
	void SubmittedCase()
	{
		for (list<Command*>::iterator it = m_list.begin(); it != m_list.end(); it++)
			(*it)->treat();
	}
private:
	list<Command *> m_list;
};

int main()
{
	Doctor		*doctor = NULL;
	Command		*command1 = NULL;
	Command		*command2 = NULL;
	NurseHead	*nursehead = NULL;

	doctor = new Doctor;
	command1 = new CommandTreatEye(doctor);
	command2 = new CommandTreatNose(doctor);

	nursehead = new NurseHead();
	nursehead->setCommand(command1);
	nursehead->setCommand(command2);

	nursehead->SubmittedCase();

	delete doctor;
	delete command1;
	delete command2;
	delete nursehead;

	return 0;
}