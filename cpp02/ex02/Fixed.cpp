#include "Fixed.hpp"

Fixed::Fixed()
{
	this->setRawBits(0);
}

Fixed::Fixed(const Fixed &x)
{
	this->setRawBits(x.getRawBits());
}

Fixed::Fixed(const int i)
{
	value = i << frac_bits;
}

Fixed::Fixed(const float f)
{
	value = std::roundf(f * (1 << frac_bits));
}

Fixed &Fixed::operator=(const Fixed &x)
{
	this->setRawBits(x.getRawBits());
	return (*this);
}

Fixed	Fixed::operator+(const Fixed &x) const
{
	return (Fixed (this->toFloat() + x.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &x) const
{
	return (Fixed (this->toFloat() - x.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &x) const
{
	return (Fixed (this->toFloat() * x.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &x) const
{
	return (Fixed (this->toFloat() / x.toFloat()));
}

Fixed	Fixed::operator++(void)
{
	value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	x(*this);
	x.value = this->value++;
	return (x);
}

Fixed	Fixed::operator--(void)
{
	value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	x(*this);
	x.value = this->value--;
	return (x);
}

int	Fixed::operator<(const Fixed &x) const
{
	return (this->getRawBits() < x.getRawBits());
}

int	Fixed::operator<=(const Fixed &x) const
{
	return (this->getRawBits() <= x.getRawBits());
}

int	Fixed::operator>(const Fixed &x) const
{
	return (this->getRawBits() > x.getRawBits());
}

int	Fixed::operator>=(const Fixed &x) const
{
	return (this->getRawBits() >= x.getRawBits());
}

int	Fixed::operator==(const Fixed &x) const
{
	return (this->getRawBits() == x.getRawBits());
}

int	Fixed::operator!=(const Fixed &x) const
{
	return (this->getRawBits() != x.getRawBits());
}

Fixed &Fixed::min(Fixed &x, Fixed &y)
{
	if (x.getRawBits() <= y.getRawBits())
		return (x);
	return (y);
}

const Fixed &Fixed::min(const Fixed &x, const Fixed &y)
{
	if (x.getRawBits() <= y.getRawBits())
		return (x);
	return (y);
}

Fixed &Fixed::max(Fixed &x, Fixed &y)
{
	if (x.getRawBits() >= y.getRawBits())
		return (x);
	return (y);
}

const Fixed &Fixed::max(const Fixed &x, const Fixed &y)
{
	if (x.getRawBits() >= y.getRawBits())
		return (x);
	return (y);
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
	
}