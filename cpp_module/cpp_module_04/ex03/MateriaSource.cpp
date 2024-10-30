/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:37:10 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/29 19:04:18 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i=0; i < 4; i++) {
		_slot[i] = NULL;
	}
}

MateriaSource::~MateriaSource() {
	for (int i=0; i < 4; i++) {
		if (_slot[i]) {
			delete(_slot[i]);
			_slot[i] = NULL;
		}
	}
}

MateriaSource::MateriaSource(MateriaSource const &other) {
	*this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i=0; i < 4; i++) {
			if (_slot[i])
				delete(_slot[i]);
			if (other._slot[i])
				_slot[i] = other._slot[i]->clone();
			else
				_slot[i] = NULL;
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *materia) {
	for (int i=0; i < 4; i++) {
		if (_slot[i] == NULL) {
			_slot[i] = materia;
			std::cout << materia->getType() << " learned!" << std::endl;
			return ;
		}
	}
	std::cout << "Can't learn more Materia, Slots are Full!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type) {
	for (int i=0; i < 4; i++) {
		if (_slot[i] && _slot[i]->getType() == type) {
			std::cout << type << " created!" << std::endl;
			return (_slot[i]->clone());
		}
	}
	std::cout << "There is no Materia named " << type << std::endl;
	return (NULL);
}
