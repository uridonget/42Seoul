/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ITER.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:36:36 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/23 12:25:45 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <set>
#include <cstdlib>
#include <ctime>

class Span 
{
	private:
		size_t	maxSize;
		size_t	curSize;
		std::multiset<int> arr;
		
	public:
		Span(); // Default constructor
		~Span(); // Destructor
		Span(const Span& other); // Copy Constructor
		Span& operator=(const Span& other); // Copy assignment operator

		class OutOfRangeException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class AlreadyFullException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		Span(size_t N);
		void addNumber(int number);
		class NotEnoughNumbersException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		size_t shortestSpan();
		size_t longestSpan();
		void addNumbers(size_t N);
		void showNumbers();
};

#endif