#include <iostream>
#include <string>
using namespace std;

class House
{
public:
	void setFloor(string floor)
	{
		this->m_floor = floor;
	}
	void setWall(string wall)
	{
		this->m_wall = wall;
	}
	void setDoor(string door)
	{
		this->m_door = door;
	}
	string getFloor()
	{
		return m_floor;
	}
	string setWall()
	{
		return m_wall;
	}
	string setDoor()
	{
		return m_door;
	}
private:
	string m_floor;
	string m_wall;
	string m_door;
};
class Builder
{
public:
	virtual void makeFloor() = 0;
	virtual void makeWall() = 0;
	virtual void makeDoor() = 0;
	virtual House *GetHouse() = 0;
};
// 公寓
class FlatBuild : public Builder
{
public:
	FlatBuild()
	{
		pHouse = new House;
	}
	virtual void makeFloor()
	{
		pHouse->setFloor("flat Door");
	}
	virtual void makeWall()
	{
		pHouse->setWall("flat Wall");
	}
	virtual void makeDoor()
	{
		pHouse->setDoor("flat Door");
	}
	virtual House *GetHouse()
	{
		return pHouse;
	}
private:
	House * pHouse;
};
// 别墅
class VillaBuild : public Builder
{
public:
	VillaBuild()
	{
		pHouse = new House;
	}
	virtual void makeFloor()
	{
		pHouse->setFloor("villa floor");
	}
	virtual void makeWall()
	{
		pHouse->setWall("villa Wall");
	}
	virtual void makeDoor()
	{
		pHouse->setDoor("villa Door");
	}
	virtual House *GetHouse()
	{
		return pHouse;
	}
private:
	House * pHouse;
};

class Director
{
public:
	void Construct(Builder *builder)
	{
		builder->makeWall();
		builder->makeFloor();
		builder->makeDoor();
	}
};

void main()
{
	// 指挥者（设计师）指挥工程队和建房子
	Director *director = new Director;
	// 建公寓
	Builder *builder = new FlatBuild;
	director->Construct(builder); // 设计师指挥工程队干活
	House *house = builder->GetHouse();
	cout << house->getFloor() << endl;
	delete house;
	delete builder;
	// 建别墅
	builder = new VillaBuild;
	director->Construct(builder); // 设计师指挥工程队干活
	house = builder->GetHouse();
	cout << house->getFloor() << endl;
	delete house;
	delete builder;
	delete director;

	system("pause");
	return;
}