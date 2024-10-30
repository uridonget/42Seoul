/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:22:15 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/18 16:26:31 by haejeong         ###   ########.fr       */
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
};

std::ostream& operator <<(std::ostream &out, const Fixed &fixed);

#endif