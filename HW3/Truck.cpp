#include "Truck.h"
#include <iostream>

using namespace std;

Truck::Truck(String _name, int _EGN[20], String _date, String _plate, String _color,
        Engine _typeEngine, size_t _horsePower, size_t _cc, size_t _cylinders,
        EuroStandart _eStandart,
        eTruck _typeTruck) : Vehicle(_name, _EGN, _date, _plate, _color, _typeEngine, _horsePower, _cc, _cylinders, _eStandart)
        {
            setTypeTruck(_typeTruck);
        }
Truck::Truck() : Vehicle()
{
    setTypeTruck(eTruck::None);
}

Truck::Truck(const Truck& other) : Vehicle(other)
{
    setTypeTruck(other.typeTruck);
}

Truck& Truck::operator=(const Truck& other)
{
    if (this == &other)
        return *this;

    setTypeTruck(other.typeTruck);
    return *this;
}

Truck::~Truck()
{
}

void Truck::getTypeTruck() const
{
    switch(typeTruck)
    {
    case eTruck::None:
        cout << "None" << endl;
    case eTruck::Pull:
        cout << "Pull" << endl;
    case eTruck::Normal:
        cout << "Normal" << endl;
    case eTruck::Special:
        cout << "Special" << endl;
    }
}

eTruck Truck::getTypeTruckIdx() const
{
    return typeTruck;
}

void Truck::setTypeTruck(eTruck _typeTruck)
{
    typeTruck = _typeTruck;
}
