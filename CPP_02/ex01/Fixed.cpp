/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demrodri <demrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:33:40 by demacinema        #+#    #+#             */
/*   Updated: 2024/12/10 23:46:43 by demrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_value = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(value * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other): _value(other.getRawBits()) // _value(other._value)
{
	std::cout << "Copy constructor called" << std::endl;
	// _value = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_value = other.getRawBits(); //_value = other._value;
	return *this;
}

int Fixed::getRawBits() const
{
	//std::cout << " getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(int value)
{
	//std::cout << " setRawBits member function called" << std::endl;
	_value = value;
}

float	Fixed::toFloat() const
{
	return static_cast<float>(_value) / (1 << _fractionalBits);
}

int		Fixed::toInt() const
{
	return (_value >> _fractionalBits);
}

float Fixed::getValueForOutput() const
{
	return this->toFloat();
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.getValueForOutput();
	return os;
}

// std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
// {
// 	os << fixed.toFloat();
// 	return (os);
// }