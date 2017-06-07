#ifndef BIGINT2_H_INCLUDED
#define BIGINT2_H_INCLUDED

#include <string>

using namespace std;

class BigInt2
{

public:
	BigInt2();
	BigInt2(string s);
	BigInt2(string s, bool sin);
	BigInt2(int n);

	void setNumber(string s);
	const string& getNumber();
	void setSign(bool s);
	const bool& getSign();
	BigInt2 absolute();

	void operator = (BigInt2 b);
	bool operator == (BigInt2 b);
	bool operator != (BigInt2 b);
	bool operator > (BigInt2 b);
	bool operator < (BigInt2 b);
	bool operator >= (BigInt2 b);
	bool operator <= (BigInt2 b);
	BigInt2& operator ++();
	BigInt2  operator ++(int);
	BigInt2& operator --();
	BigInt2  operator --(int);
	BigInt2 operator + (BigInt2 b);
	BigInt2 operator - (BigInt2 b);
	BigInt2 operator * (BigInt2 b);
	BigInt2 operator / (BigInt2 b);
	BigInt2 operator % (BigInt2 b);
	BigInt2& operator += (BigInt2 b);
	BigInt2& operator -= (BigInt2 b);
	BigInt2& operator *= (BigInt2 b);
	BigInt2& operator /= (BigInt2 b);
	BigInt2& operator %= (BigInt2 b);
	BigInt2& operator [] (int n);
	BigInt2 operator -();
	operator string();

private:

    string number;
	bool sign;

/////////////////////////////////////////

	bool equals(BigInt2 n1, BigInt2 n2);
	bool less(BigInt2 n1, BigInt2 n2);
	bool greater(BigInt2 n1, BigInt2 n2);

	string add(string number1, string number2);
	string subtract(string number1, string number2);
	string multiply(string n1, string n2);
	pair<string, long long> divide(string n, long long den);
	string toString(long long n);

	long long toInt(string s);

};

#endif // BIGINT2_H_INCLUDED
