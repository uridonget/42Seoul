/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:44:43 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/21 11:55:00 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	private:
		AForm* makeShrubberyCreationForm(std::string target);
		AForm* makeRobotomyRequestForm(std::string target);
		AForm* makePresidentialPardonForm(std::string target);
		
	public:
		Intern(); // Default constructor
		~Intern(); // destructor
		Intern(const Intern& other); // Copy Constructor
		Intern& operator=(const Intern& other); // Copy assignment operator
		class WrongNameException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		AForm* makeForm(std::string name, std::string target);
};

#endif