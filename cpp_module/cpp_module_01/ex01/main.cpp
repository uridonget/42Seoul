/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:48:21 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/17 14:24:12 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	int N = 3;
	std::string name = "Harry Potter";
	Zombie *Zoms = zombieHorde(N, name);
	for (int i = 0; i < N; i++) {
		Zoms[i].announce();
	}
	delete[] Zoms;
	return (0);
}
