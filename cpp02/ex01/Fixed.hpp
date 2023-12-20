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
		~Fixed();
		Fixed	&operator=(const Fixed &x);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &os, Fixed const &x);

#endif