#include "Trailer.h"

Trailer::Trailer(String _name, int _EGN[20], String _date, String _plate, String _color,
        size_t _axii, double _maxWeight) : OwnerCarInfo(_name, _EGN, _date, _plate, _color)
        {
            setAxii(_axii);
            setMaxWeight(_maxWeight);
        }
Trailer::Trailer() : OwnerCarInfo()
{
    setAxii(0);
    setMaxWeight(0.0);
}

Trailer::Trailer(const Trailer& other)
{
    setAxii(other.axii);
    setMaxWeight(other.maxWeight);
}

Trailer& Trailer::operator=(const Trailer& other)
{
    if (this == &other)
        return *this;

    OwnerCarInfo::operator=(other);
    setAxii(other.axii);
    setMaxWeight(other.maxWeight);
    return *this;
}

size_t Trailer::getAxii() const
{
    return axii;
}

double Trailer::getMaxWeight() const
{
    return maxWeight;
}

void Trailer::setAxii(size_t _axii)
{
    axii = _axii;
}

void Trailer::setMaxWeight(double _maxWeight)
{
    maxWeight = _maxWeight;
}
