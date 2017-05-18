#pragma once
#include "Vehicle.h"

enum class Coupe
{
    None,
    Hatchback,
    Sedan,
    Combi,
    Cabrio,
    Liftback,
};

class Car : public Vehicle
{
private:
    Coupe typeCoupe;

public:
    Car(String _name, int _EGN[10], String _date, String _plate, String _color,
            Engine _typeEngine, size_t _horsePower, size_t _cc, size_t _cylinders,
            EuroStandart _eStandart,
            Coupe _typeCoupe);
    Car();
    Car(const Car& other);
    Car& operator=(const Car& other);
    ~Car();

    void getTypeCoupe() const;
    Coupe getTypeCoupeIdx() const;

    void setTypeCoupe(Coupe _typeCoupe);
};
