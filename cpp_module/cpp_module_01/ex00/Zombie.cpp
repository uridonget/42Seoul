/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:25:34 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/17 14:13:57 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
	this->name = "default";
}

Zombie::Zombie(std::string name) {
	this->name = name;
}

Zombie::~Zombie() {
	std::cout << this->name << " has been eliminated." << std::endl;
}

void Zombie::announce() {
	std::cout << this->name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
