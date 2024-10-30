/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:11:20 by haejeong          #+#    #+#             */
/*   Updated: 2024/06/03 08:45:24 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	struct Data* TestData = new Data("Haechan", "haejeong");
	std::cout << "------------------------" << std::endl;
	std::cout << "Data Address : " << TestData << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << *TestData << std::endl;
	std::cout << "------------------------" << std::endl;
	uintptr_t SerializedData = Serializer::serialize(TestData);
	std::cout << "------------------------" << std::endl;
	std::cout << "Serialized Data : " << SerializedData << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << "Serialized Data : " << std::hex << SerializedData << std::endl;
	std::cout << "------------------------" << std::endl;
	struct Data* DeserializedData = Serializer::deserialize(SerializedData);
	std::cout << "------------------------" << std::endl;
	std::cout << *DeserializedData << std::endl;
	std::cout << "------------------------" << std::endl;
	delete(TestData);
	return 0;
}
