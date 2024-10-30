/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:57:04 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/20 19:56:33 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
AForm(other.getName(), other.getGradeRequiredToSign(), other.getGradeRequiredToExecute()),
target_(other.getTarget()) {
	std::cout << "Copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
		const_cast<std::string&>(target_) = other.getTarget();
	}
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("presidential pardon", 25, 5),
	target_(target) {
	std::cout << "PresidentialPardonForm " << target << " Constructor called" << std::endl;
}

const std::string PresidentialPardonForm::getTarget() const {
	return (target_);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) {
	if (this->getSigned() == false) {
		throw (AForm::FormNotSignedException());
	}
	else if (executor.getGrade() > this->getGradeRequiredToExecute()) {
		throw (Bureaucrat::GradeTooLowException());
	}
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream& operator <<(std::ostream &out, const PresidentialPardonForm &form) {
	out << "name                      : " << form.getName() << std::endl;
	out << "signed(false:0, true:1)   : " << form.getSigned() << std::endl;
	out << "grade required to sign    : " << form.getGradeRequiredToSign() << std::endl;
	out << "grade required to execute : " << form.getGradeRequiredToExecute() << std::endl;
	out << "target                    : " << form.getTarget();
	return (out);
}