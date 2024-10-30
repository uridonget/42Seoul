/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:07:51 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/16 08:27:57 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

static bool ft_isprint(std::string data) {
	for (int i=0; data[i]; i++) {
		if ((data[i] < 32) || (126 < data[i])) {
			return (false);
		}
	}
	return (true);
}

void ft_getline(std::string& data) {
	while (true) {
		std::getline(std::cin, data);
		if (data.empty()) {
			if (std::cin.eof()) {
				std::cout << "** You entered EOF **" << std::endl;
				std::exit(1);
			}
			std::cout << "** You entered newline **" << std::endl;
			std::cout << "Pleas type again : ";
			continue;
		}
		else if (!ft_isprint(data)) {
			std::cout << "** You entered invalid value (non-printable) **" << std::endl;
			std::cout << "Pleas type again : ";
			continue;
		}
		break ;
	}
}

void Contact::SetData() {
	std::cout.width(14);
	std::cout << std::left << "First Name" << " : ";
	ft_getline(firstName_);
	std::cout.width(14);
	std::cout << std::left << "Last Name" << " : ";
	ft_getline(lastName_);
	std::cout.width(14);
	std::cout << std::left << "Nickname" << " : ";
	ft_getline(nickName_);
	std::cout.width(14);
	std::cout << std::left << "Phone Number" << " : ";
	ft_getline(phoneNumber_);
	std::cout.width(14);
	std::cout << std::left << "Darkest Secret" << " : ";
	ft_getline(darkestSecret_);
}

void Contact::ShowData(std::string data) {
	if (data.length() > 10) {
		std::cout << data.substr(0, 9) << ".";
	} else {
		std::cout.width(10);
		std::cout << std::right << data;
	}
}

void Contact::ShowAllData() {
	ShowData(this->firstName_);
	std::cout << "|";
	ShowData(this->lastName_);
	std::cout << "|";
	ShowData(this->nickName_);
	std::cout << "|";
	std::cout << std::endl;
}

void Contact::ShowDataOfIndex() {
	std::cout << "First Name     : ";
	std::cout << this->firstName_ << std::endl; 
	std::cout << "Last Name      : ";
	std::cout << this->lastName_ << std::endl;
	std::cout << "Nickname       : ";
	std::cout << this->nickName_ << std::endl;
	std::cout << "Phone Number   : ";
	std::cout << this->phoneNumber_ << std::endl;
	std::cout << "Darkest Secret : ";
	std::cout << this->darkestSecret_ << std::endl;
}