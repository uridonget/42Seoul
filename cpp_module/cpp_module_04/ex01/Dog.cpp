/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:24:37 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/29 18:54:19 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog constructor called" << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete (_brain);
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog copy assignment constructor called" << std::endl;
	Animal::operator=(other);
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "Mung! Mung!" << std::endl;
}
