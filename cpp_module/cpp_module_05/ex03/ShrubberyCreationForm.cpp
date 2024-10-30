/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:57:04 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/21 17:44:17 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
AForm(other.getName(), other.getGradeRequiredToSign(), other.getGradeRequiredToExecute()),
target_(other.getTarget()) {
	std::cout << "Copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
		const_cast<std::string&>(target_) = other.getTarget();
	}
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("shrubbery creation", 145, 137),
	target_(target) {
	std::cout << "ShrubberyCreationForm " << target << " constructor called" << std::endl;
}

const std::string ShrubberyCreationForm::getTarget() const {
	return (target_);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) {
	if (this->getSigned() == false) {
		throw (AForm::FormNotSignedException());
	}
	else if (executor.getGrade() > this->getGradeRequiredToExecute()) {
		throw (Bureaucrat::GradeTooLowException());
	}
	std::ofstream file((this->target_ + "_shrubbery").c_str());
	if (!file.is_open()) {
		std::cerr << "fail to open file" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	file << 
		"                                              .         ;  \n"
		"                 .              .              ;%     ;;   \n"
		"                   ,           ,                :;%  %;   \n"
		"                    :         ;                   :;%;'     .,   \n"
		"           ,.        %;     %;            ;        %;'    ,; \n"
		"             ;       ;%;  %%;        ,     %;    ;%;    ,%' \n"
		"              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
		"               ;%;      %;        ;%;        % ;%;  ,%;' \n"
		"                `%;.     ;%;     %;'         `;%%;.%;' \n"
		"                 `:;%.    ;%%. %@;        %; ;@%;%' \n"
		"                    `:%;.  :;bd%;          %;@%;' \n"
		"                      `@%:.  :;%.         ;@@%;'   \n"
		"                        `@%.  `;@%.      ;@@%;         \n"
		"                          `@%%. `@%%    ;@@%;        \n"
		"                            ;@%. :@%%  %@@%;       \n"
		"                              %@bd%%%bd%%:;     \n"
		"                                #@%%%%%:;; \n"
		"                                %@@%%%::; \n"
		"                                %@@@%(o);  . '         \n"
		"                                %@@@o%;:(.,'         \n"
		"                            `.. %@@@o%::;         \n"
		"                               `)@@@o%::;         \n"
		"                                %@@(o)::;        \n"
		"                               .%@@@@%::;         \n"
		"                               ;%@@@@%::;.          \n"
		"                              ;%@@@@%%:;;;. \n"
		"                          ...;%@@@@@%%:;;;;,..\n";
	file.close();
}

std::ostream& operator <<(std::ostream &out, const ShrubberyCreationForm &form) {
	out << "name                      : " << form.getName() << std::endl;
	out << "signed(false:0, true:1)   : " << form.getSigned() << std::endl;
	out << "grade required to sign    : " << form.getGradeRequiredToSign() << std::endl;
	out << "grade required to execute : " << form.getGradeRequiredToExecute() << std::endl;
	out << "target                    : " << form.getTarget();
	return (out);
}