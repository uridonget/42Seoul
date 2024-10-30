/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:31:34 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/25 08:51:04 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = other;
}

Animal& Animal::operator=(const Animal& other) {
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if (this != &other) {
		_type = other.getType();
	}
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const {
	return (_type);
}

void Animal::makeSound() const {
	std::cout << "Animal Sound!" << std::endl;
}
