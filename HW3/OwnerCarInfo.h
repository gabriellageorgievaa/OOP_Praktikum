#pragma once
#include "String.h"

class OwnerCarInfo
{
private:
    String name;
    int EGN[20];
    String plate;
    String date;
    String color;

    bool isLegit(String _plate) const;


public:
    OwnerCarInfo(String _name, int _EGN[20], String _date, String _plate, String _color);
    OwnerCarInfo();
    OwnerCarInfo(const OwnerCarInfo& other);
    OwnerCarInfo& operator=(const OwnerCarInfo& other);
    ~OwnerCarInfo();

    String getName() const;
    const int* getEGN() const;
    String getPlate() const;
    String getDate() const;
    String getColor() const;

    void setName(String _name);
    void setEGN(const int _EGN[20]);
    void setPlate(String _plate);
    void setDate(String _date);
    void setColor(String _color);
    void setEGNnull();

        double getCoef(String _plate) const;
    size_t getAge(const int _EGN[20]) const;
};
