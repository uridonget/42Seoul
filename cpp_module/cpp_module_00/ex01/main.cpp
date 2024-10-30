/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:14:56 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/13 14:56:30 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main(void) {
	PhoneBook	pb;
	std::string cmd;
	
	while (true) {
		std::cout << "(1) ADD (2) SEARCH (3) EXIT" << std::endl;
		std::cout << "ENTER THE COMMAND : ";
		ft_getline(cmd);
		if (cmd == "ADD" || cmd == "1") {
			std::cout << std::endl;
			pb.AddNew();
			std::cout << std::endl;
		}
		else if (cmd == "SEARCH" || cmd == "2") {
			pb.Search();
		}
		else if (cmd == "EXIT" || cmd == "3") {
			std::cout << "EXIT";
			break ;
		}
		else {
			std::cout << "command not found" << std::endl;
		}
	}
	return (0);
}
