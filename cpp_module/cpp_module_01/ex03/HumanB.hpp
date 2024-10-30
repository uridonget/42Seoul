/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:11:49 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/17 14:56:21 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "Weapon.hpp"

class HumanB {
	private:
		std::string name;
		Weapon *weapon;

	public:
		HumanB(std::string name);
		~HumanB();
		void setWeapon(Weapon &weapon);
		Weapon* getWeapon() const;
		const std::string& getName() const;
		void attack();
};

#endif