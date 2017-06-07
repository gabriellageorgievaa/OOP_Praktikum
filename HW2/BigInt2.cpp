#include <iostream>
#include <string.h>
#include <streambuf>
#include <cmath>
#include "BigInt2.h"
#define MAX 10000

BigInt2::BigInt2()
{
	number = "0";
	sign = false;
}

BigInt2::BigInt2(string s)
{
	if (isdigit(s[0]))
	{
		setNumber(s);
		sign = false;
	}
	else
	{
		setNumber(s.substr(1));
		sign = (s[0] == '-');
	}
}

BigInt2::BigInt2(string s, bool sin)
{
	setNumber(s);
	setSign(sin);
}

BigInt2::BigInt2(int n)
{
	stringstream ss;
	string s;
	ss << n;
	ss >> s;


	if (isdigit(s[0]))
	{
		setNumber(s);
		setSign(false);
	}
	else
	{
		setNumber(s.substr(1));
		setSign(s[0] == '-');
	}
}

void BigInt2::setNumber(string s)
{
	number = s;
}

const string& BigInt2::getNumber()
{
	return number;
}

void BigInt2::setSign(bool s)
{
	sign = s;
}

const bool& BigInt2::getSign()
{
	return sign;
}

//////////////////////////////////////////

BigInt2 BigInt2::absolute()
{
	return BigInt(getNumber());
}

void BigInt2::operator = (BigInt2 b)
{
	setNumber(b.getNumber());
	setSign(b.getSign());
}

bool BigInt2::operator == (BigInt2 b)
{
	return equals((*this), b);
}

bool BigInt2::operator != (BigInt2 b)
{
	return !equals((*this), b);
}

bool BigInt2::operator > (BigInt2 b)
{
	return greater((*this), b);
}

bool BigInt2::operator < (BigInt2 b)
{
	return less((*this), b);
}

bool BigInt2::operator >= (BigInt2 b)
{
	return equals((*this), b)
		|| greater((*this), b);
}

bool BigInt2::operator <= (BigInt2 b)
{
	return equals((*this), b)
		|| less((*this), b);
}

BigInt2& BigInt2::operator ++()
{
	(*this) = (*this) + 1;
	return (*this);
}

BigInt2 BigInt2::operator ++(int)
{
	BigInt2 before = (*this);

	(*this) = (*this) + 1;

	return before;
}

BigInt2& BigInt2::operator --()
{
	(*this) = (*this) - 1;
	return (*this);

}

BigInt2 BigIn2t::operator --(int)
{
	BigInt before = (*this);

	(*this) = (*this) - 1;

	return before;
}

BigInt2 BigInt2::operator + (BigInt2 b)
{
	BigInt addition;
	if (getSign() == b.getSign())
	{
		addition.setNumber(add(getNumber(), b.getNumber()));
		addition.setSign(getSign());
	}
	else
	{
		if (absolute() > b.absolute())
		{
			addition.setNumber(subtract(getNumber(), b.getNumber()));
			addition.setSign(getSign());
		}
		else
		{
			addition.setNumber(subtract(b.getNumber(), getNumber()));
			addition.setSign(b.getSign());
		}
	}
	if (addition.getNumber() == "0")
		addition.setSign(false);

	return addition;
}

BigInt2 BigInt2::operator - (BigInt2 b)
{
	b.setSign(!b.getSign()); // x - y = x + (-y)
	return (*this) + b;
}

BigInt2 BigInt2::operator * (BigInt2 b)
{
	BigInt2 mul;

	mul.setNumber(multiply(getNumber(), b.getNumber()));
	mul.setSign(getSign() != b.getSign());

	if (mul.getNumber() == "0")
		mul.setSign(false);

	return mul;
}

BigInt2 BigInt2::operator / (BigInt2 b)
{
	long long den = toInt(b.getNumber());
	BigInt2 div;

	div.setNumber(divide(getNumber(), den).first);
	div.setSign(getSign() != b.getSign());

	if (div.getNumber() == "0")
		div.setSign(false);

	return div;
}

BigInt2 BigInt2::operator % (BigInt2 b)
{
	long long den = toInt(b.getNumber());

	BigInt2 rem;
	long long rem_int = divide(number, den).second;
	rem.setNumber(toString(rem_int));
	rem.setSign(getSign() != b.getSign());

	if (rem.getNumber() == "0")
		rem.setSign(false);

	return rem;
}

BigInt2& BigInt2::operator += (BigInt2 b)
{
	(*this) = (*this) + b;
	return (*this);
}

BigInt2& BigInt2::operator -= (BigInt2 b)
{
	(*this) = (*this) - b;
	return (*this);
}

BigInt2& BigInt2::operator *= (BigInt2 b)
{
	(*this) = (*this) * b;
	return (*this);
}

BigInt2& BigInt2::operator /= (BigInt2 b)
{
	(*this) = (*this) / b;
	return (*this);
}

BigInt2& BigInt2::operator %= (BigInt2 b)
{
	(*this) = (*this) % b;
	return (*this);
}

BigInt2& BigInt2::operator [] (int n)
{
	return *(this + (n * sizeof(BigInt2)));
}

BigInt2 BigInt2::operator -()
{
	return (*this) * -1;
}

BigInt2::operator string()
{
	string signedString = (getSign()) ? "-" : "";
	signedString += number;
	return signedString;
}

////////////////////////////////////////////////

bool BigInt2::equals(BigInt2 n1, BigInt2 n2)
{
	return n1.getNumber() == n2.getNumber()
		&& n1.getSign() == n2.getSign();
}

bool BigInt2::less(BigInt2 n1, BigInt2 n2)
{
	bool sign1 = n1.getSign();
	bool sign2 = n2.getSign();

	if (sign1 && !sign2)
		return true;

	else if (!sign1 && sign2)
		return false;

	else if (!sign1)
	{
		if (n1.getNumber().length() < n2.getNumber().length())
			return true;
		if (n1.getNumber().length() > n2.getNumber().length())
			return false;
		return n1.getNumber() < n2.getNumber();
	}
	else
	{
		if (n1.getNumber().length() > n2.getNumber().length())
			return true;
		if (n1.getNumber().length() < n2.getNumber().length())
			return false;
		return n1.getNumber().compare(n2.getNumber()) > 0;
	}
}

bool BigInt2::greater(BigInt2 n1, BigInt2 n2)
{
	return !equals(n1, n2) && !less(n1, n2);
}

string BigInt2::add(string number1, string number2)
{
	string add = (number1.length() > number2.length()) ? number1 : number2;
	char carry = '0';
	int differenceInLength = abs((int)(number1.size() - number2.size()));

	if (number1.size() > number2.size())
		number2.insert(0, differenceInLength, '0');

	else
		number1.insert(0, differenceInLength, '0');

	for (int i = number1.size() - 1; i >= 0; --i)
	{
		add[i] = ((carry - '0') + (number1[i] - '0') + (number2[i] - '0')) + '0';

		if (i != 0)
		{
			if (add[i] > '9')
			{
				add[i] -= 10;
				carry = '1';
			}
			else
				carry = '0';
		}
	}
	if (add[0] > '9')
	{
		add[0] -= 10;
		add.insert(0, 1, '1');
	}
	return add;
}

string BigInt2::subtract(string number1, string number2)
{
	string sub = (number1.length()>number2.length()) ? number1 : number2;
	int differenceInLength = abs((int)(number1.size() - number2.size()));

	if (number1.size() > number2.size())
		number2.insert(0, differenceInLength, '0');

	else
		number1.insert(0, differenceInLength, '0');

	for (int i = number1.length() - 1; i >= 0; --i)
	{
		if (number1[i] < number2[i])
		{
			number1[i] += 10;
			number1[i - 1]--;
		}
		sub[i] = ((number1[i] - '0') - (number2[i] - '0')) + '0';
	}

	while (sub[0] == '0' && sub.length() != 1)
		sub.erase(0, 1);

	return sub;
}

string BigInt2::multiply(string n1, string n2)
{
	if (n1.length() > n2.length())
		n1.swap(n2);

	string res = "0";
	for (int i = n1.length() - 1; i >= 0; --i)
	{
		string temp = n2;
		int currentDigit = n1[i] - '0';
		int carry = 0;

		for (int j = temp.length() - 1; j >= 0; --j)
		{
			temp[j] = ((temp[j] - '0') * currentDigit) + carry;

			if (temp[j] > 9)
			{
				carry = (temp[j] / 10);
				temp[j] -= (carry * 10);
			}
			else
				carry = 0;

			temp[j] += '0';
		}

		if (carry > 0)
			temp.insert(0, 1, (carry + '0'));

		temp.append((n1.length() - i - 1), '0');

		res = add(res, temp);
	}

	while (res[0] == '0' && res.length() != 1)
		res.erase(0, 1);

	return res;
}

pair<string, long long> BigInt2::divide(string n, long long den)
{
	long long rem = 0;
	string result; result.resize(MAX);

	for (int indx = 0, len = n.length(); indx<len; ++indx)
	{
		rem = (rem * 10) + (n[indx] - '0');
		result[indx] = rem / den + '0';
		rem %= den;
	}
	result.resize(n.length());

	while (result[0] == '0' && result.length() != 1)
		result.erase(0, 1);

	if (result.length() == 0)
		result = "0";

	return make_pair(result, rem);
}

string BigInt2::toString(long long n)
{
	stringstream ss;
	string temp;

	ss << n;
	ss >> temp;

	return temp;
}

long long BigInt2::toInt(string s)
{
	long long sum = 0;

	for (int i = 0; i<s.length(); i++)
		sum = (sum * 10) + (s[i] - '0');

	return sum;
}
