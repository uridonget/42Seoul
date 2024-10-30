/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:48:01 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/29 18:43:33 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat constructor called" << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete (_brain);
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat copy assignment constructor called" << std::endl;
	Animal::operator=(other);
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "Weong! Weong!" << std::endl;
}
