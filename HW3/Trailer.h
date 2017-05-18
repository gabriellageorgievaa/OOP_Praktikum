#pragma once
#include "OwnerCarInfo.h"

class Trailer : public OwnerCarInfo
{
private:
    size_t axii;
    double maxWeight;

public:
    Trailer(String _name, int _EGN[20], String _date, String _plate, String _color,
            size_t _axii, double _maxWeight);
    Trailer();
    Trailer(const Trailer& other);
    Trailer& operator=(const Trailer& other);
    ~Trailer();

    size_t getAxii() const;
    double getMaxWeight() const;

    void setAxii(size_t _axii);
    void setMaxWeight(double _maxWeight);
};
