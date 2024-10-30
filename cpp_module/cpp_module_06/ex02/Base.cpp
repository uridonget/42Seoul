/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:42:54 by haejeong          #+#    #+#             */
/*   Updated: 2024/06/03 08:46:40 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base* generate(void) {
	std::srand(static_cast<unsigned int>(std::clock()));
	unsigned int randomNumber = std::rand() % 3;
	switch (randomNumber) {
		case 0 :
			std::cout << "A generated" << std::endl;
			return (new A);
		case 1 :
			std::cout << "B generated" << std::endl;
			return (new B);
		case 2 :
			std::cout << "C generated" << std::endl;
			return (new C);
		default :
			std::cerr << "Error" << std::endl;
			std::exit(EXIT_FAILURE);
	}
}

void identify(Base* p) {
	std::cout << "* Identify : ";
	if (dynamic_cast<A*>(p))
		std::cout << "This is A!" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "This is B!" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "This is C!" << std::endl;
	else {
		std::cerr << "Error" << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

void identify(Base& p) {
	std::cout << "& Identify : ";
	try {
		A &a = dynamic_cast<A&>(p);
		std::cout << "This is A!" << std::endl;
	} catch (...) {
        // std::cout << "dynamic_cast failed" << std::endl;
    }
	try {
		B &b = dynamic_cast<B&>(p);
		std::cout << "This is B!" << std::endl;
	} catch (...) {
		// std::cout << "dynamic_cast failed" << std::endl;
	}
	try {
		C &c = dynamic_cast<C&>(p);
		std::cout << "This is C!" << std::endl;
	} catch (...) {
		// std::cout << "dynamic_cast failed" << std::endl;
	}
}
