/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:22:09 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/15 16:50:26 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "phonebook.hpp"

PhoneBook::PhoneBook() {
	this->idx = 0;
}

void PhoneBook::AddNew() {
	this->contact[idx % 8].SetData();
	this->idx++;
}

void PhoneBook::Search() {
	std::string index;
	
	if (this->idx == 0) {
		std::cout << "** PHONEBOOK IS EMPTY **" << std::endl;
		return ;
	}
	std::cout << std::endl;
	std::cout << "      Index| FirstName|  LastName|  Nickname|" << std::endl;
	std::cout << " ----------+----------+----------+----------+" << std::endl;
	if (this->idx < 8) {
		for (int i = 0; i < this->idx; i++) {
			std::cout << "          " << i << "|";
			this->contact[i].ShowAllData();
		}
	}
	else {
		for (int i = 0; i < 8; i++) {
			std::cout << "          " << i << "|";
			this->contact[i].ShowAllData();
		}
	}
	std::cout << std::endl;
	while (true) {
		std::cout << "Enter the index : ";
		ft_getline(index);
		if (index.length() != 1 || (index[0] > '7' || index[0] < '0') || (index[0] > (this->idx + '0' - 1))) {
			std::cout << "Invalid index! Please type number between 0 and ";
			if (this->idx < 8) {
				std::cout << this->idx - 1 << std::endl;
			}
			else {
				std::cout << "7" << std::endl;
			}
			continue ;
		}
		std::cout << std::endl;
		this->contact[index[0] - '0'].ShowDataOfIndex();
		break ;
	}
	std::cout << std::endl;
}
