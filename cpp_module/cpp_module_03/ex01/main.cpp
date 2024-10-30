/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:26:26 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/22 11:41:40 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void ) {
  ScavTrap dk("DK");
  ClapTrap t1(dk);

  t1.setName("T1");
  dk.attack("geng");
  t1.attack("geng");
  t1.attack("geng");
  dk.guardGate();
  return 0;
}