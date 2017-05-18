#pragma once
#include "Vehicle.h"

enum class eTruck
{
    None,
    Pull,
    Normal,
    Special,
};

class Truck : public Vehicle
{
private:
    eTruck typeTruck;

public:
    Truck(String _name, int _EGN[20], String _date, String _plate, String _color,
            Engine _typeEngine, size_t _horsePower, size_t _cc, size_t _cylinders,
            EuroStandart _eStandart,
            eTruck _typeTruck);
    Truck();
    Truck(const Truck& other);
    Truck& operator=(const Truck& other);
    ~Truck();

    void getTypeTruck() const;
    eTruck getTypeTruckIdx() const;

    void setTypeTruck(eTruck _typeTruck);
};
