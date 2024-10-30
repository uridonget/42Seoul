/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:19:33 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/17 14:56:47 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {}

HumanA::~HumanA() {}

Weapon& HumanA::getWeapon() const {
	return (this->weapon);
}

const std::string& HumanA::getName() const {
	return (this->name);
}

void HumanA::attack() {
	std::cout << this->getName() << " attacks with their " << this->getWeapon().getType() << std::endl;
}
