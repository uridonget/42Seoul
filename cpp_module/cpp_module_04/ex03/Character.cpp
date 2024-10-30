/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:37:40 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/29 19:04:06 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name(NULL) {
	for (int i=0; i < 4; i++) {
		_slot[i] = NULL;
	}
}

Character::Character(std::string name) : _name(name) {
	for (int i=0; i < 4; i++) {
		_slot[i] = NULL;
	}
}

Character::~Character() {
	for (int i=0; i < 4; i++)
	{
		if (_slot[i])
			delete (_slot[i]);
	}
}

Character::Character(Character const &other) {
	_name = other.getName();
	for (int i=0; i < 4; i++) {
		if (other._slot[i])
			_slot[i] = other._slot[i]->clone();
		else
			_slot[i] = NULL;
	}
}

Character& Character::operator=(const Character& other) {
	if (this != &other) {
		_name = other.getName();
		for (int i=0; i < 4; i++) {
			if (_slot[i])
				delete(_slot[i]);
			if (other._slot[i])
				_slot[i] = other._slot[i]->clone();
		}
	}
	return (*this);
}

std::string const & Character::getName() const {
	return (_name);
}

void Character::equip(AMateria* materia) {
	if (materia == NULL) {
		std::cout << "There is no Materia" << std::endl;
		return ;
	}
	for (int i=0; i < 4; i++) {
		if (_slot[i] == NULL) {
			_slot[i] = materia;
			std::cout << materia->getType() << " equiped!" << std::endl;
			return ;
		}
	}
	std::cout << "Can't equip more Materia, All slots are Full!" << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3) {
		std::cout << idx << " is invalid idx!" << std::endl;
		return ;
	}
	if (_slot[idx]) {
		std::cout << _slot[idx]->getType() << " unequiped!" << std::endl;
		_slot[idx] = NULL;
	}
	else
		std::cout << idx << " slot is empty!" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3) {
		std::cout << idx << " is invalid idx!" << std::endl;
		return ;
	}
	if (_slot[idx])
		_slot[idx]->use(target);
	else
		std::cout << idx << " slot is empty!" << std::endl;
}

AMateria* Character::getMateria(int idx) {
	return (_slot[idx]);
}