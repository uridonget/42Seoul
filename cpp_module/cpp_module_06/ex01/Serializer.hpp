/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:54:49 by haejeong          #+#    #+#             */
/*   Updated: 2024/06/03 08:37:49 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include <string>

struct Data
{
	private:
		std::string name_;
		std::string intraID_;

	public:
		Data(std::string name, std::string intraID);
		std::string getName() const;
		std::string getIntraID() const;
};

std::ostream& operator <<(std::ostream &out, const Data &data);

class Serializer
{
	private:
		Serializer(); // default constructor
		Serializer(const Serializer& other); // copy constructor
		Serializer& operator=(const Serializer& other); // copy assignment operator
	public:
		~Serializer(); // destructor
		
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};



#endif