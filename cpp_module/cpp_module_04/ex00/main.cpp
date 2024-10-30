/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:39:00 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/29 18:56:59 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void NormalFlow() {
	Animal* meta = new Animal();
	Animal* ddog = new Dog();
	Animal* ccat = new Cat();
	std::cout << meta->getType() << std::endl;
	std::cout << ddog->getType() << std::endl;
	std::cout << ccat->getType() << std::endl;
	meta->makeSound();
	ddog->makeSound();
	ccat->makeSound();
	delete(meta);
	delete(ddog);
	delete(ccat);
}

void WrongFlow() {
	WrongAnimal* meta = new WrongAnimal();
	WrongAnimal* wcat = new WrongCat();
	std::cout << meta->getType() << " " << std::endl;
	std::cout << wcat->getType() << " " << std::endl;
	meta->makeSound();
	wcat->makeSound();
	delete(meta);
	delete(wcat);
}

int main() {
	NormalFlow();
	// WrongFlow();
	return 0;
}