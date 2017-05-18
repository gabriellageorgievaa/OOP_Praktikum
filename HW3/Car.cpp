#include "Car.h"
#include <iostream>

using namespace std;

Car::Car(String _name, int _EGN[10], String _date, String _plate, String _color,
        Engine _typeEngine, size_t _horsePower, size_t _cc, size_t _cylinders,
        EuroStandart _eStandart,
        Coupe _typeCoupe) : Vehicle(_name, _EGN, _date, _plate, _color, _typeEngine, _horsePower, _cc, _cylinders, _eStandart)
        {
            setTypeCoupe(_typeCoupe);
        }
Car::Car() : Vehicle()
{
    setTypeCoupe(Coupe::None);
}

Car::Car(const Car& other) : Vehicle(other)
{
    setTypeCoupe(other.typeCoupe);
}

Car& Car::operator=(const Car& other)
{
    if (this == &other)
        return *this;

    Vehicle::operator=(other);
    setTypeCoupe(other.typeCoupe);
    return *this;
}

Car::~Car()
{
}

void Car::getTypeCoupe() const
{
    switch(typeCoupe)
    {
    case Coupe::None:
        cout << "None" << endl;
    case Coupe::Hatchback:
        cout << "Hatchback"<<endl;
    case Coupe::Sedan:
        cout << "Sedan" << endl;
    case Coupe::Combi:
        cout << "Combi"<<endl;
    case Coupe::Cabrio:
        cout << "Cabrio"<<endl;
    case Coupe::Liftback:
        cout << "Liftback"<<endl;
    }
}

Coupe Car::getTypeCoupeIdx() const
{
    return typeCoupe;
}

void Car::setTypeCoupe(Coupe _typeCoupe)
{
    typeCoupe = _typeCoupe;
}
