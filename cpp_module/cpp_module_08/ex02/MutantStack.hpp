/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghaechan <jeonghaechan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:18:40 by haejeong          #+#    #+#             */
/*   Updated: 2024/06/05 16:15:56 by jeonghaecha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack() : std::stack<T>() {} // Default constructor
		~MutantStack() {} // Destructor
		MutantStack(const MutantStack<T>& other) : std::stack<T>(other) {
			*this = other;
		} // Copy constructor
		MutantStack& operator=(const MutantStack<T>& other) {
			if (this != &other) {
				std::stack<T>::operator=(other);
			}
			return (*this);
		} // Copy assignment operator
		
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() { return (this->c.begin()); }
		iterator end() { return (this->c.end()); }

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator begin() const { return (this->c.begin()); }
		const_iterator end() const { return (this->c.end()); }

		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin() { return (this->c.rbegin()); }
		reverse_iterator rend() { return (this->c.rend()); }

		typedef typename std::stack<T>::container_type::reverse_iterator reverse_const_iterator;
		reverse_const_iterator rbegin() const { return (this->c.rbegin()); }
		reverse_const_iterator rend() const { return (this->c.rend()); }
};

#endif
