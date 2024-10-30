/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:41:28 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/29 17:31:38 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::~Cure() {}

Cure::Cure(Cure const &other) : AMateria(other) {}

Cure& Cure::operator=(const Cure& other) {
	AMateria::operator=(other);
	return (*this);
}

AMateria* Cure::clone() const {
	return (new Cure(*this));
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
