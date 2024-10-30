/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:52:43 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/17 14:48:18 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
	private:
		std::string type;

	public:
		Weapon(std::string WeaponName);
		~Weapon();
		const std::string& getType() const;
		void setType(std::string WeaponName);
};

#endif