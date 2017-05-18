#include "Motorcycle.h"
#include <iostream>

using namespace std;

Motorcycle::Motorcycle(String _name, int _EGN[20], String _date, String _plate, String _color,
        Engine _typeEngine, size_t _horsePower, size_t _cc, size_t _cylinders,
        EuroStandart _eStandart,
        Motor _typeMotorcycle) : Vehicle(_name, _EGN, _date, _plate, _color, _typeEngine, _horsePower, _cc, _cylinders, _eStandart)
        {
            setTypeMotorcycle(_typeMotorcycle);
        }

Motorcycle::Motorcycle() : Vehicle()
{
    setTypeMotorcycle(Motor::None);
}

Motorcycle::Motorcycle(const Motorcycle& other) : Vehicle(other)
{
    setTypeMotorcycle(other.typeMotorcycle);
}

Motorcycle& Motorcycle::operator=(const Motorcycle& other)
{
    if (this == &other)
        return *this;

    Vehicle::operator=(other);
    setTypeMotorcycle(other.typeMotorcycle);
    return *this;
}

Motorcycle::~Motorcycle()
{
}

void Motorcycle::getTypeMotorcycle () const
{
    switch(typeMotorcycle)
    {
    case Motor::None:
        cout << "None" << endl;
    case Motor::Sport:
        cout << "Sport" << endl;
    case Motor::Chopper:
        cout << "Chopper" << endl;
    case Motor::Cross:
        cout << "Cross" << endl;
    }
}

Motor Motorcycle::getTypeMotorcycleIdx() const
{
    return typeMotorcycle;
}

void Motorcycle::setTypeMotorcycle(Motor _typeMotorcycle)
{
    typeMotorcycle = _typeMotorcycle;
}
