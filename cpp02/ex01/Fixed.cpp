#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}

Fixed::Fixed(const Fixed &x)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(x.getRawBits());
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	value = i << frac_bits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	value = std::roundf(f * (1 << frac_bits));
}

Fixed &Fixed::operator=(const Fixed &x)
{	
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(x.getRawBits());
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (value);
}

void Fixed::setRawBits(int const raw)
{	
	value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)value / (1 << frac_bits));
}

int		Fixed::toInt(void) const
{
	return (value >> frac_bits);
}

std::ostream	&operator<<(std::ostream &os, Fixed const &x)
{
	os << x.toFloat();
	return (os);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}