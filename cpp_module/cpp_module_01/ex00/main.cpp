/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:48:21 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/17 12:08:14 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	Zombie *z1 = newZombie("showmaker");
	z1->announce();
	z1->announce();
	z1->announce();
	delete (z1);
	randomChump("lucid");
	return (0);
}
