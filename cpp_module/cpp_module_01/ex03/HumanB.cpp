/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:54:18 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/17 14:56:10 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {
	this->weapon = NULL;
}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}

Weapon* HumanB::getWeapon() const {
	return (this->weapon);
}

const std::string& HumanB::getName() const {
	return (this->name);
}

void HumanB::attack() {
	if (this->weapon)
		std::cout << this->getName() << " attacks with their " << this->getWeapon()->getType() << std::endl;
	else
		std::cout << this->getName() << " has no weapon..." << std::endl;
	// if (this->weapon)
	// 	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	// else
	// 	std::cout << this->name << " has no weapon..." << std::endl;
}