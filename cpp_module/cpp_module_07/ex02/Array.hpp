/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghaechan <jeonghaechan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:18:40 by haejeong          #+#    #+#             */
/*   Updated: 2024/06/04 10:36:30 by jeonghaecha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include <cstdlib>

template <typename T>
class Array {
    private:
		T* array_;
		unsigned int length_;
		
	public:
		/*
		Construction with no parameter: Creates an empty array.
		*/
		Array() : length_(1), array_(new T()) {};
		
		/*
		Construction by copy and assignment operator. 
		In both cases, modifying either the original array or its 
		copy after copying musn’t affect the other array.
		*/
		Array(const Array& other) : length_(0), array_(0) {
			*this = other;
		};

		Array& operator=(const Array& other) {
			if (this != &other) {
				length_ = other.size();
				if (array_)
					delete [] array_;
				array_ = new T[length_];
				for (int i=0; i < length_; i++) {
					array_[i] = other.array_[i];
				}
			}
			return (*this);
		};

		/*
		Destructor.
		If length of array is not zero. There is array_ allocated in heap area.
		*/
		~Array() {
			if (array_)
				delete [] array_;
		};
		
		/*
		Construction with an unsigned int n as a parameter.
		Creates an array of n elements initialized by default.
		*/
		Array(unsigned int n) {
			if (n == 0) {
				n = 1;
			}
			length_ = n;
			array_ = new T[n];
		};
		
		/*
		A member function size() that returns the number of elements in the array. 
		This member function takes no parameter and musn’t modify the current instance.
		*/
		unsigned int size() const {
			return (length_);
		};

		/*
		std::exception
		*/
		class IndexOutOfBoundException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Accessing index out of bound!");
				};
		};

		/*
		When accessing an element with the [ ] operator, if its index is out of bounds, an
		std::exception is thrown.
		*/
		T& operator[](unsigned int i) {
			if (length_ <= i) {
				throw IndexOutOfBoundException();
			}
			return (array_[i]);
		};
};

#endif
