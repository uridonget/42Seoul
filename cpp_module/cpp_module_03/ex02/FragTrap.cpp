/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:39:30 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/22 11:52:14 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	this->setType("FragTrap");
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap constructor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	this->setType("FragTrap");
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << this->getType() << " " << this->getName();
	std::cout << " yeah~ HighFive!!!" << std::endl;
}
