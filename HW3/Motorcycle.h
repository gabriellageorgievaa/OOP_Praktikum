#pragma once
#include "Vehicle.h"

enum class Motor
{
    None,
    Sport,
    Chopper,
    Cross,
};

class Motorcycle : public Vehicle
{
private:
    Motor typeMotorcycle;

public:
    Motorcycle(String _name, int _EGN[20], String _date, String _plate, String _color,
            Engine _typeEngine, size_t _horsePower, size_t _cc, size_t _cylinders,
            EuroStandart _eStandart,
            Motor _typeMotorcycle);
    Motorcycle();
    Motorcycle(const Motorcycle& other);
    Motorcycle& operator=(const Motorcycle& other);
    ~Motorcycle();

    void getTypeMotorcycle () const;
    Motor getTypeMotorcycleIdx() const;

    void setTypeMotorcycle(Motor _typeMotorcycle);
};
