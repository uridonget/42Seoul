/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:22:15 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/15 18:07:42 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed {
	private:
		int	FixedPoint;
		static const int FractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		
		Fixed(int const intNum);
		Fixed(float const floatNum);
		float toFloat(void) const;
		int toInt(void) const;

		// >, <, >=, <=, ==, !=
		bool operator >(const Fixed &other) const;
		bool operator <(const Fixed &other) const;
		bool operator >=(const Fixed &other) const;
		bool operator <=(const Fixed &other) const;
		bool operator ==(const Fixed &other) const;
		bool operator !=(const Fixed &other) const;
		// +, -, *, /
		Fixed operator +(const Fixed &other) const;
		Fixed operator -(const Fixed &other) const;
		Fixed operator *(const Fixed &other) const;
		Fixed operator /(const Fixed &other) const;
		// ++, --
		Fixed operator ++();
		Fixed operator --();
		Fixed operator ++(int);
		Fixed operator --(int);
		// min, max
		static Fixed min(Fixed &a, Fixed &b);
		static Fixed min(const Fixed &a, const Fixed &b);
		static Fixed max(Fixed &a, Fixed &b);
		static Fixed max(const Fixed &a, const Fixed &b);
};

std::ostream& operator <<(std::ostream &out, const Fixed &fixed);

#endif