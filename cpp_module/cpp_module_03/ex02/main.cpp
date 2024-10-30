/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:26:26 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/22 11:53:27 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ) {
  FragTrap t1("T1");

  t1.highFivesGuys();
  t1.attack("GenG");
  t1.attack("GenG");
  t1.attack("GenG");
  t1.attack("GenG");
  t1.attack("GenG");
  t1.takeDamage(50);
  return 0;
}