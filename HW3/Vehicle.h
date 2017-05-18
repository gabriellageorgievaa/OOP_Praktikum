#pragma once
#include "OwnerCarInfo.h"

enum class Engine
{
    None,
    Diesel,
    Petrol,
    Gaz,
};

enum class EuroStandart
{
    None,
    Euro1,
    Euro2,
    Euro3,
    Euro4,
};



class Vehicle : public OwnerCarInfo
{
private:
    Engine typeEngine;
    size_t horsePower;
    size_t cc;
    size_t cylinders;
    EuroStandart eStandart;

    double getCoef(String _plate) const;

public:
    Vehicle(String _name, int _EGN[20], String _date, String _plate, String _color,
            Engine _typeEngine, size_t _horsePower, size_t _cc, size_t _cylinders,
            EuroStandart _eStandart);
    Vehicle();
    Vehicle(const Vehicle& other);
    Vehicle operator=(const Vehicle& other);
    ~Vehicle();

    void getTypeEngine() const;
    Engine getTypeEngineIdx() const;
    size_t getHorsePower() const;
    size_t getCC() const;
    size_t getCylinders() const;
    void getStandart() const;
    EuroStandart getStandartIdx() const;

    void setTypeEngine(Engine _typeEngine);
    void setHorsePower(size_t _horsePower);
    void setCC(size_t _cc);
    void setCylinders(size_t _cylinders);
    void setStandart(EuroStandart _eStandart);

    int getTax() const;
    int getInsurance() const;

};
