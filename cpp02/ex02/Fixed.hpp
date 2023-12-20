#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					value;
		static const int	frac_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &x);
		Fixed(const int i);
		Fixed(const float f);
		Fixed				&operator=(const Fixed &x);
		Fixed				operator+(const Fixed &x) const;
		Fixed				operator-(const Fixed &x) const;
		Fixed				operator*(const Fixed &x) const;
		Fixed				operator/(const Fixed &x) const;
		Fixed				operator++(void);
		Fixed				operator++(int);
		Fixed				operator--(void);
		Fixed				operator--(int);
		int					operator<(const Fixed &x) const;
		int					operator<=(const Fixed &x) const;
		int					operator>(const Fixed &x) const;
		int					operator>=(const Fixed &x) const;
		int					operator==(const Fixed &x) const;
		int					operator!=(const Fixed &x) const;
		static Fixed		&min(Fixed &x, Fixed &y);
		static const Fixed	&min(const Fixed &x, const Fixed &y);
		static Fixed		&max(Fixed &x, Fixed &y);
		static const Fixed	&max(const Fixed &x, const Fixed &y);
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
		~Fixed();
};

std::ostream		&operator<<(std::ostream &os, Fixed const &x);

#endif