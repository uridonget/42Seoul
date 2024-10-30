/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:11:05 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/17 15:12:16 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {
	Zombie *Zoms = new Zombie[N];
	for (int i = 0; i < N; i++) {
		Zoms[i].setName(name);
	}
	return (&Zoms[0]);
}
