/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:11:49 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/17 15:16:51 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "Weapon.hpp"

class HumanA {
	private:
		std::string name;
		Weapon &weapon;

	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		Weapon& getWeapon() const;
		const std::string& getName() const;
		void attack();
};

#endif