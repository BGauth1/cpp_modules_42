#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}

Fixed::Fixed(Fixed &x)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(x.getRawBits());
}

Fixed &Fixed::operator=(Fixed &x)
{	
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(x.getRawBits());
	return (*this);
}

int Fixed::getRawBits(void)
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void Fixed::setRawBits(int const raw)
{	
	value = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
