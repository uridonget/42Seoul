/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:25:34 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/19 11:24:52 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : FixedPoint(0) {
}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

Fixed::~Fixed() {
}

Fixed& Fixed::operator = (const Fixed& other) {
	if (this != &other) {
		this->FixedPoint = other.getRawBits();
	}
	return (*this);
}

int Fixed::getRawBits(void) const {
	return (this->FixedPoint);
}

void Fixed::setRawBits(const int raw) {
	this->FixedPoint = raw;
}

///////////////////////////////////////////////////////

Fixed::Fixed(const int intNum) : FixedPoint(intNum << this->FractionalBits) {
}

Fixed::Fixed(float const floatNum) : FixedPoint(roundf(floatNum * (1 << this->FractionalBits))) {
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

///////////////////////////////////////////////////////

bool Fixed::operator >(const Fixed &other) const {
	return (this->FixedPoint > other.FixedPoint);	
}

bool Fixed::operator <(const Fixed &other) const {
	return (this->FixedPoint < other.FixedPoint);	
}

bool Fixed::operator >=(const Fixed &other) const {
	return (this->FixedPoint >= other.FixedPoint);	
}

bool Fixed::operator <=(const Fixed &other) const {
	return (this->FixedPoint <= other.FixedPoint);	
}

bool Fixed::operator ==(const Fixed &other) const {
	return (this->FixedPoint == other.FixedPoint);	
}

bool Fixed::operator !=(const Fixed &other) const {
	return (this->FixedPoint != other.FixedPoint);
}

Fixed Fixed::operator +(const Fixed &other) const {
	Fixed res;
	res.FixedPoint = this->FixedPoint + other.FixedPoint;
	return (res);
}

Fixed Fixed::operator -(const Fixed &other) const {
	Fixed res;
	res.FixedPoint = this->FixedPoint - other.FixedPoint;
	return (res);
}

Fixed Fixed::operator *(const Fixed &other) const {
	Fixed res(this->toFloat() * other.toFloat());
	return (res);
}

Fixed Fixed::operator /(const Fixed &other) const {
	Fixed res(this->toFloat() / other.toFloat());
	return (res);
}

Fixed Fixed::operator ++() {
	this->FixedPoint += 1;
	return (*this);
}

Fixed Fixed::operator --() {
	this->FixedPoint -= 1;
	return (*this);
}

Fixed Fixed::operator ++(int) {
	Fixed res(*this);
	this->FixedPoint += 1;
	return (res);
}

Fixed Fixed::operator --(int) {
	Fixed res(*this);
	this->FixedPoint -= 1;
	return (res);
}

Fixed Fixed::min(Fixed &a, Fixed &b) {
	if (a <= b)
		return (a);
	return (b);
}

Fixed Fixed::min(const Fixed &a, const Fixed &b) {
	if (a <= b)
		return (a);
	return (b);
}

Fixed Fixed::max(Fixed &a, Fixed &b) {
	if (a >= b)
		return (a);
	return (b);
}

Fixed Fixed::max(const Fixed &a, const Fixed &b) {
	if (a >= b)
		return (a);
	return (b);
}
