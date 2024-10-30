/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:39:00 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/25 08:54:24 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal *zoo[10];
	
	for (int i=0; i < 10; i++) {
		if (i % 2)
			zoo[i] = new Dog();
		else
			zoo[i] = new Cat();
	}
	zoo[0]->makeSound();
	zoo[1]->makeSound();
	for (int i=0; i < 10; i++) {
		delete (zoo[i]);
	}
	return 0;
}