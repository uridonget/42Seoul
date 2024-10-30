/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:25:34 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/19 11:27:58 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : FixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator = (const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->FixedPoint = other.getRawBits();
	}
	return (*this);
}

int Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->FixedPoint);
}

void Fixed::setRawBits(const int raw) {
	this->FixedPoint = raw;
}

///////////////////////////////////////////////////////

Fixed::Fixed(const int intNum) : FixedPoint(intNum << this->FractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const floatNum) : FixedPoint(roundf(floatNum * (1 << this->FractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const {
	return ((float)this->FixedPoint / (1 << this->FractionalBits));	
}

int Fixed::toInt(void) const {
	return (this->FixedPoint >> this->FractionalBits);
}

std::ostream& operator <<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

