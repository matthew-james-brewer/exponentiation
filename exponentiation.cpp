#include <cmath>
#include <iostream>

// Class for middle of eint **eint = eint *(*eint) = eint *zint
class zint
{
	private:
		int number;

	public:
		zint(int num): number(num) {}

	operator int() const
	{
		return number;
	}
};

class eint
{
	private:
		int number;

	public:
		eint(int num): number(num) {}

	eint(const eint &ext): number(ext.number) {}

	// Overload the *eint operator to create an zint for exponentiation
	zint operator*()
	{
		return zint(number);
	}

	// Overload the multiplication operator to handle eint *zint for exponentiation
	eint operator*(zint other)
	{
		return eint(std::pow(double(number), double(int(other))));
	}

	operator int() const
	{
		return number;
	}

	// Handle bool operators

	bool operator==(eint e)
	{
		return (number == int(e));
	}

	bool operator!=(eint e)
	{
		return (number != int(e));
	}

	bool operator < (eint e)
	{
		return (number < int(e));
	}

	bool operator>(eint e)
	{
		return (number > int(e));
	}

	bool operator<=(eint e)
	{
		return ((number < int(e)) || (number == int(e)));
	}

	bool operator>=(eint e)
	{
		return ((number > int(e)) || (number == int(e)));
	}

	// Handle[operator] and assign (and ++ / --)

	eint &operator+=(eint e)
	{
		number += int(e);
		return * this;
	}

	eint &operator++()
	{
		number++;
		return * this;
	}

	eint operator++(int dummy)
	{
		eint preserve = *this;	// Preseve old number
		number++;
		return preserve;
	}

	eint &operator-=(eint e)
	{
		number -= int(e);
		return * this;
	}

	eint &operator--()
	{
		number--;
		return * this;
	}

	eint operator--(int dummy)
	{
		eint preserve = *this;	// Preserve old number
		number--;
		return preserve;
	}

	eint &operator*=(eint e)
	{
		number *= int(e);
		return * this;
	}

	eint &operator/=(eint e)
	{
		number /= int(e);
		return * this;
	}

	eint &operator%=(eint e)
	{
		number %= int(e);
		return * this;
	}

	// Extra operators
	eint &operator^=(eint e)
	{
		number ^= int(e);
		return * this;
	}

	eint &operator&=(eint e)
	{
		number &= int(e);
		return * this;
	}

	eint &operator|=(eint e)
	{
		number |= int(e);
		return * this;
	}

	eint &operator>>=(eint e)
	{
		number >>= int(e);
		return * this;
	}

	eint &operator<<=(eint e)
	{
		number <<= int(e);
		return * this;
	}

	// Define +, -, *, /, % operators

	eint operator+(eint e)
	{
		return eint(number + int(e));
	}

	eint operator-(eint e)
	{
		return eint(number - int(e));
	}

	eint operator*(eint e)
	{
		return eint(number* int(e));
	}

	eint operator/(eint e)
	{
		return eint(number / int(e));
	}

	eint operator%(eint e)
	{
		return eint(number % int(e));
	}

	// Extra operators
	eint operator^(eint e)
	{
		return eint(number ^ int(e));
	}

	eint operator&(eint e)
	{
		return eint(number &int(e));
	}

	eint operator|(eint e)
	{
		return eint(number | int(e));
	}

	eint operator>>(eint e)
	{
		return eint(number >> int(e));
	}

	eint operator<<(eint e)
	{
		return eint(number << int(e));
	}

	// Define <<and>> operators

	friend std::ostream &operator<<(std::ostream &os, const eint &e)
	{
		os << int(e);
		return os;
	}

	friend std::istream &operator>>(std::istream &is, eint &e)
	{
		int value;
		is >> value;
		e = eint(value);
		return is;
	}
};
