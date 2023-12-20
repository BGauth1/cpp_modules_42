#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int 				value;
		static const int	frac_bits = 8;
	public:
		Fixed();
		Fixed(Fixed &x);
		Fixed	&operator=(Fixed &x);
		~Fixed();
		int		getRawBits(void);
		void	setRawBits(int const raw);
};

#endif