/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 08:48:18 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/22 11:45:05 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
	private:
		std::string name;
		int HitPoints;
		int EnergyPoints;
		int AttackDamage;
		std::string type;
		
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		virtual ~ClapTrap();
		bool checkClapTrap(void);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
		// GETTER
		std::string getName() const;
		int getHitPoints() const;
		int getEnergyPoints() const;
		int getAttackDamage() const;
		std::string getType() const;
		// SETTER
		void setName(std::string const name);
		void setHitPoints(int const HitPoints);
		void setEnergyPoints(int const EnergyPoints);
		void setAttackDamage(int const AttackDamage);
		void setType(std::string const type);
};

#endif