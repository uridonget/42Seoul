/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:39:00 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/29 18:59:47 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	// Animal* meta = new Animal();
	Animal* ddog = new Dog();
	Animal* ccat = new Cat();
	// std::cout << meta->getType() << std::endl;
	std::cout << ddog->getType() << std::endl;
	std::cout << ccat->getType() << std::endl;
	// meta->makeSound();
	ddog->makeSound();
	ccat->makeSound();
	// delete(meta);
	delete(ddog);
	delete(ccat);
}
