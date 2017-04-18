#ifndef BIGINT_H
#define BIGINT_H
#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

class BigInt
{
    public:
        BigInt(char* newNumber, size_t newLength, char newSign);
        BigInt();
        ~BigInt();
        BigInt(const BigInt& other);
        BigInt& operator=(const BigInt& other);
        BigInt& operator+(const BigInt& rhs);
        BigInt& operator-(const BigInt& rhs);
        BigInt& operator+=(const BigInt& rhs);
        BigInt& operator-=(const BigInt& rhs);
        BigInt& operator--(const BigInt& rhs);

        char* Getnumber();
        void Setnumber(char* val);
        size_t Getlength();
        void Setlength(size_t val);
        char Getsign();
        void Setsign(char val);

        friend BigInt std::ostream& operator<<(std::ostream output, const BigInt& num);
        friend BigInt std::istream& operator>>(std::istream input, const BigInt& num);


    protected:

    private:
        char* number;
        size_t length;
        char sign;
};

#endif // BIGINT_H
