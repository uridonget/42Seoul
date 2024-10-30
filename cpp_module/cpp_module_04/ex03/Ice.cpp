/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:26:57 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/29 17:25:26 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(Ice const &other) : AMateria(other) {}

Ice& Ice::operator=(const Ice& other) {
	AMateria::operator=(other);
	return (*this);
}

AMateria* Ice::clone() const {
	return (new Ice(*this));
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
