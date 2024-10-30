/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:20:08 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/21 18:04:46 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

AForm* Intern::makeShrubberyCreationForm(std::string target) {
	return (new ShrubberyCreationForm(target));	
}

AForm* Intern::makeRobotomyRequestForm(std::string target) {
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makePresidentialPardonForm(std::string target) {
	return (new PresidentialPardonForm(target));
}

Intern::Intern() {
	std::cout << "Intern constructor called" << std::endl;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
	std::cout << "Intern copy constructor called" << std::endl;
	static_cast<void>(other);
	*this = other;
}

Intern& Intern::operator=(const Intern& other) {
	std::cout << "Intern copy assignment operator called" << std::endl;
	static_cast<void>(other);
	return (*this);
}

const char* Intern::WrongNameException::what() const throw() {
	return ("Name is wrong!");
}

AForm *Intern::makeForm(std::string name, std::string target) {
	std::cout << "Intern make form called" << std::endl;
	AForm* (Intern::*f[3])(std::string target) = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm,
	};
	std::string lvls[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	try {
		for (int i = 0; i < 3; i++) {
			if (name == lvls[i]) {
				return ((this->*f[i])(target));
			}
		}
		throw Intern::WrongNameException();
	} catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
		return (NULL);
    }
}