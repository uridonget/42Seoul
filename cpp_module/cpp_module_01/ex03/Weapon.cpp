/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:58:44 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/17 14:48:20 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string WeaponName) : type(WeaponName) {}

Weapon::~Weapon() {}

const std::string& Weapon::getType() const {
	return (this->type);
}

void Weapon::setType(std::string WeaponName) {
	this->type = WeaponName;
}

