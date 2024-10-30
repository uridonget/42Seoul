/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:26:26 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/22 09:12:42 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void ) {

  ClapTrap dk = ClapTrap("Dplus Kia");
  
  dk.attack("T1");
  dk.attack("Gen.G");
  dk.attack("T1");
  dk.attack("Gen.G");
  dk.attack("T1");
  dk.attack("Gen.G");
  dk.takeDamage(9);
  dk.beRepaired(5);
  dk.attack("T1");
  dk.attack("Gen.G");
  dk.takeDamage(6);
  dk.attack("T1");
  dk.attack("Gen.G");
  dk.attack("T1");
  dk.attack("Gen.G");
  dk.beRepaired(5);
  return 0;
}