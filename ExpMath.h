#include <cmath>	// Needed for std::pow
#include <iostream>	// Needed for << / >> operators

namespace ExpMath
{
	// Class for middle of:(efloat **efloat == efloat *(*efloat) == efloat *zfloat)
	class zfloat
	{
		private:
			float number;

		public:
			zfloat(float num): number(num) {}

		operator float() const
		{
			return number;
		}
	};

	class efloat
	{
		private:
			float number;

		public:
			efloat()
			{
				number = 0.0 f;
			}

		efloat(float num): number(num) {}

		efloat(const efloat &ext): number(ext.number) {}

		/*
		▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇
		                   𝐌𝐀𝐈𝐍 𝐒𝐄𝐂𝐓𝐈𝐎𝐍
		▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇
		*/
		// Overload the *efloat operator to create a zfloat for exponentiation
		zfloat operator*()
		{
			return zfloat(number);
		}

		// Overload the multiplication operator to handle (efloat *zfloat) for exponentiation
		efloat operator*(zfloat other)
		{
			return efloat(std::pow(number, float(other)));
		}

		/*
		▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇
		                 𝐄𝐍𝐃 𝐌𝐀𝐈𝐍 𝐒𝐄𝐂𝐓𝐈𝐎𝐍
		▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇
		*/

		operator float() const
		{
			return number;
		}

		// Handle bool operators
		bool operator==(const efloat &e) const
		{
			return (number == float(e));
		}

		bool operator!=(const efloat &e) const
		{
			return (number != float(e));
		}

		// Define +, -, *, / operators
		efloat operator+(const efloat &e) const
		{
			return efloat(number + float(e));
		}

		efloat operator- ()const
		{
			return efloat(-number);
		}

		efloat operator-(const efloat &e) const
		{
			return efloat(number - float(e));
		}

		efloat operator*(const efloat &e) const
		{
			return efloat(number* float(e));
		}

		efloat operator/(const efloat &e) const
		{
			return efloat(number / float(e));
		}

		// Define +=, ++, -=, --, *=, /= operators
		efloat &operator+=(const efloat &e)
		{
			number += float(e);
			return * this;
		}

		efloat &operator++()
		{
			number++;
			return * this;
		}

		efloat operator++(int dummy)
		{
			efloat preserve = *this;	// Preseve old number
			number++;
			return preserve;
		}

		efloat &operator-=(const efloat &e)
		{
			number -= float(e);
			return * this;
		}

		efloat &operator--()
		{
			number--;
			return * this;
		}

		efloat operator--(int dummy)
		{
			efloat preserve = *this;	// Preserve old number
			number--;
			return preserve;
		}

		efloat &operator*=(const efloat &e)
		{
			number *= float(e);
			return * this;
		}

		efloat &operator/=(const efloat &e)
		{
			number /= float(e);
			return * this;
		}

		// Define <<and>> operators
		friend std::ostream &operator<<(std::ostream &os, const efloat &e)
		{
			os << float(e);
			return os;
		}

		friend std::istream &operator>>(std::istream &is, efloat &e)
		{
			float value;
			is >> value;
			e = efloat(value);
			return is;
		}
	};

	class zint	// Similar to zfloat, but for eint
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

	class eint	// Similar to efloat
	{
		private:
			int number;

		public:
			eint()
			{
				number = 0;
			}

		eint(int num): number(num) {}

		eint(const eint &ext): number(ext.number) {}

		/*
		▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇
		                   𝐌𝐀𝐈𝐍 𝐒𝐄𝐂𝐓𝐈𝐎𝐍
		▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇
		*/
		// Overload the *eint operator to create a zint for exponentiation
		zint operator*()
		{
			return zint(number);
		}

		// Overload the multiplication operator to handle eint *zint for exponentiation
		eint operator*(zint other)
		{
			return eint(std::pow(float(number), int(other)));
		}

		/*
		▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇
		                 𝐄𝐍𝐃 𝐌𝐀𝐈𝐍 𝐒𝐄𝐂𝐓𝐈𝐎𝐍
		▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇
		*/

		operator int() const
		{
			return number;
		}

		// Handle bool operators
		bool operator==(const eint &e) const
		{
			return (number == int(e));
		}

		bool operator!=(const eint &e) const
		{
			return (number != int(e));
		}

		// Define +, -, *, /, % operators
		eint operator+(const eint &e) const
		{
			return eint(number + int(e));
		}

		eint operator- ()const
		{
			return eint(-number);
		}

		eint operator-(const eint &e) const
		{
			return eint(number - int(e));
		}

		eint operator*(const eint &e) const
		{
			return eint(number* int(e));
		}

		eint operator/(const eint &e) const
		{
			return eint(number / int(e));
		}

		eint operator%(const eint &e) const
		{
			return eint(number % int(e));
		}

		// Extra operators
		eint operator^(const eint &e) const
		{
			return eint(number ^ int(e));
		}

		eint operator&(const eint &e) const
		{
			return eint(number &int(e));
		}

		eint operator|(const eint &e) const
		{
			return eint(number | int(e));
		}

		eint operator>>(const eint &e) const
		{
			return eint(number >> int(e));
		}

		eint operator<<(const eint &e) const
		{
			return eint(number << int(e));
		}

		// Define +=, ++, -=, --, *=, /=, %= operators
		eint &operator+=(const eint &e)
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

		eint &operator-=(const eint &e)
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

		eint &operator*=(const eint &e)
		{
			number *= int(e);
			return * this;
		}

		eint &operator/=(const eint &e)
		{
			number /= int(e);
			return * this;
		}

		eint &operator%=(const eint &e)
		{
			number %= int(e);
			return * this;
		}

		// Extra operators
		eint &operator^=(const eint &e)
		{
			number ^= int(e);
			return * this;
		}

		eint &operator&=(const eint &e)
		{
			number &= int(e);
			return * this;
		}

		eint &operator|=(const eint &e)
		{
			number |= int(e);
			return * this;
		}

		eint &operator>>=(const eint &e)
		{
			number >>= int(e);
			return * this;
		}

		eint &operator<<=(const eint &e)
		{
			number <<= int(e);
			return * this;
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

}	// namespace ExpMath
