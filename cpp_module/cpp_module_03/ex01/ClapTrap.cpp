/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 08:52:09 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/22 11:44:04 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), HitPoints(10), EnergyPoints(10), AttackDamage(0), type("ClapTrap") {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0), type("ClapTrap") {
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->setName(other.getName());
		this->setHitPoints(other.getHitPoints());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setAttackDamage(other.getAttackDamage());
		this->setType(other.getType());
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor called" << std::endl;
}

bool ClapTrap::checkClapTrap(void) {
	if (this->HitPoints <= 0) {
		std::cout << this->getType() << " " << this->getName();
		std::cout << " is broken..." << std::endl;
		return (false);
	}
	else if (this->EnergyPoints <= 0) {
		std::cout << this->getType() << " " << this->getName();
		std::cout << " has no energy..." << std::endl;
		return (false);
	}
	return (true);
}

void ClapTrap::attack(const std::string& target) {
	if (ClapTrap::checkClapTrap()) {
		std::cout << this->getType() << " " << this->getName();
		std::cout << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (ClapTrap::checkClapTrap()) {
		std::cout << this->getType() << " " << this->getName();
		std::cout << " is being attacked and lost " << amount << " Hit Points!";
		std::cout << "(" << this->getHitPoints() << "->";
		this->setHitPoints(this->getHitPoints() - amount);
		std::cout << this->getHitPoints() << ")" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (ClapTrap::checkClapTrap()) {
		std::cout << this->getType() << " " << this->getName(); 
		std::cout << " repairs itself and gained " << amount << " Hit Points!";
		this->setEnergyPoints(this->getEnergyPoints() - 1);
		std::cout << "(" << this->getHitPoints() << "->";
		this->setHitPoints(this->getHitPoints() + amount);
		std::cout << this->getHitPoints() << ")" << std::endl;
	}	
}

///// GETTER /////

std::string ClapTrap::getName() const {
	return (this->name);
}

int ClapTrap::getHitPoints() const {
	return (this->HitPoints);
}

int ClapTrap::getEnergyPoints() const {
	return (this->EnergyPoints);
}

int ClapTrap::getAttackDamage() const {
	return (this->AttackDamage);
}

std::string ClapTrap::getType() const {
	return (this->type);
}

///// SETTER /////

void ClapTrap::setName(std::string const name) {
	this->name = name;
}

void ClapTrap::setHitPoints(int const HitPoints) {
	this->HitPoints = HitPoints;
}

void ClapTrap::setEnergyPoints(int const EnergyPoints) {
	this->EnergyPoints = EnergyPoints;
}

void ClapTrap::setAttackDamage(int const AttackDamage) {
	this->AttackDamage = AttackDamage;
}

void ClapTrap::setType(std::string const type) {
	this->type = type;
}
