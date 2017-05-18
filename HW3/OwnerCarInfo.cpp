#include "OwnerCarInfo.h"

double OwnerCarInfo::getCoef(String _plate) const
{
    if (_plate[0] == 'A')
        return 1.2;
    if (_plate[0] == 'H')
        return 1.0;
    if (_plate[0] == 'B')
        return 0.9;
    if (_plate[0] == 'C')
        return 0.8;
    if (_plate[0] == 'P')
        return 0.9;
    if (_plate[0] == 'T')
        return 1.0;
    if (_plate[0] == 'E')
        return 0.6;
    if (_plate[0] == 'X')
        return 0.7;
    if (_plate[0] == 'Y')
        return 1.1;
    if (_plate[0] == 'M')
        return 0.6;
    if (_plate[0] == 'K')
        return 0.7;
    if (_plate[0] == 'C' && _plate[1] == 'A')
        return 0.8;
    if (_plate[0] == 'C' && _plate[1] == 'B')
        return 0.8;
    if (_plate[0] == 'C' && _plate[1] == 'O')
        return 0.8;
    if (_plate[0] == 'C' && _plate[1] == 'C')
        return 1.1;
    if (_plate[0] == 'C' && _plate[1] == 'T')
        return 0.7;
    if (_plate[0] == 'C' && _plate[1] == 'M')
        return 0.8;
    if (_plate[0] == 'C' && _plate[1] == 'H')
        return 0.6;
    if (_plate[0] == 'P' && _plate[1] == 'A')
        return 0.7;
}

OwnerCarInfo::OwnerCarInfo(String _name, int _EGN[20], String _date, String _plate, String _color)
{
    setName(_name);
    setEGN(_EGN);
    setDate(_date);
    setPlate(_plate);
    setColor(_color);
}
OwnerCarInfo::OwnerCarInfo()
{
    setName("");
    setEGNnull();
    setDate("");
    setPlate("");
    setColor("");

}

OwnerCarInfo::OwnerCarInfo(const OwnerCarInfo& other)
{
    setName(other.name);
    setEGN(other.EGN);
    setDate(other.date);
    setPlate(other.plate);
    setColor(other.color);
}

OwnerCarInfo& OwnerCarInfo::operator=(const OwnerCarInfo& other)
{
    if (this == &other) return *this;
    {
    setName(other.name);
    setEGN(other.EGN);
    setDate(other.date);
    setPlate(other.plate);
    setColor(other.color);
    }
    return *this;
}

OwnerCarInfo::~OwnerCarInfo()
{
}

String OwnerCarInfo::getName() const
{
    return name;
}

const int* OwnerCarInfo::getEGN() const
{
    return EGN;
}

String OwnerCarInfo::getPlate() const
{
    return plate;
}

String OwnerCarInfo::getDate() const
{
    return date;
}

String OwnerCarInfo::getColor() const
{
    return color;
}


void OwnerCarInfo::setName(String _name)
{
    name = _name;
}

void OwnerCarInfo::setEGN(const int _EGN[20])
{
    for (size_t i = 0; i < 20; i++)
    {
        EGN[i] = _EGN[i];
    }
}

void OwnerCarInfo::setPlate(String _plate)
{
    plate = _plate;
}

void OwnerCarInfo::setDate(String _date)
{
    date = _date;
}

void OwnerCarInfo::setColor(String _color)
{
    color = _color;
}

void OwnerCarInfo::setEGNnull()
{
    for(size_t i = 0; i < 20; i++)
    {
        EGN[i] = 0;
    }
}

size_t OwnerCarInfo::getAge(const int _EGN[20]) const
{
    return 2017 - (1900 + EGN[0] * 10 + EGN[1]);
}
