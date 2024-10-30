/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:04:37 by haejeong          #+#    #+#             */
/*   Updated: 2024/06/03 08:39:42 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Data::Data(std::string name, std::string intraID) : 
name_(name), 
intraID_(intraID) {}

std::string Data::getName() const {
	return (name_);
}

std::string Data::getIntraID() const {
	return (intraID_);
}

std::ostream& operator <<(std::ostream &out, const Data &data) {
	out << "Name     : " << data.getName() << std::endl;
	out << "Intra ID : " << data.getIntraID();
	return (out);
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr) {
	std::cout << "Serialize!" << std::endl;
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
	std::cout << "Deserialize!" << std::endl;
	return (reinterpret_cast<Data*>(raw));
}
