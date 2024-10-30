/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:12:07 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/29 19:03:55 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type(NULL) {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::~AMateria() {}

AMateria::AMateria(const AMateria& other) {
	*this = other;
}

AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other) {
		_type = other.getType();
	}
	return (*this);
}

std::string const & AMateria::getType() const {
	return (this->_type);
}

void AMateria::use(ICharacter &target) {
	std::cout << "* Use Materia to " << target.getName() << " *" << std::endl;
}