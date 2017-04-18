#include "BigInt.h"

BigInt::BigInt(char* newNumber, size_t newLength, char newSign)
{
    number = nullptr;
    Setnumber(newNumber);
    Setlength(newLength);
    Setsign(newSign);

}

BigInt::BigInt()
{
    number = nullptr;
    Setnumber("");
    Setlength(0);
    Setsign('\0');
}

BigInt::~BigInt()
{
    delete [] number;
}

BigInt::BigInt(const BigInt& other)
{
    number = nullptr;
    Setnumber(other.number);
    Setlength(other.length);
    Setsign(other.sign);

}

BigInt& BigInt::operator=(const BigInt& rhs)
{
    if (this != &rhs)
    {
        Setnumber(rhs.number);
        Setlength(rhs.length);
        Setsign(rhs.sign);

    }
    return *this;
}

char* BigInt::Getnumber()
{
    return number;
}

void BigInt::Setnumber(char* val)
{
    delete [] number;

    if(val != nullptr)
    {
        size_t len = strlen(val);
        if(len > 0)
        {
            number = new char [len + 1];
            strcpy(number, val);
            return;
        }
    }

    number = new char [1];
    number = '\0';
}

size_t BigInt::Getlength()
{
    return length;
}

void BigInt::Setlength(size_t val)
{
    length = val;
}

char BigInt::Getsign()
{
    return sign;
}

void BigInt::Setsign(char val)
{
    sign = val;
}