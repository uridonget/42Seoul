/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:04:47 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/16 08:28:53 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Contact {
	private:
		std::string firstName_;
		std::string lastName_;
		std::string nickName_;
		std::string phoneNumber_;
		std::string darkestSecret_;

	public:
		void SetData();
		void ShowData(std::string data);
		void ShowAllData();
		void ShowDataOfIndex();
};

void ft_getline(std::string& data);

#endif