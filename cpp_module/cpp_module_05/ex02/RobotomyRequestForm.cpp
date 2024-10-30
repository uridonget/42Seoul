/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:57:04 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/20 19:16:39 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
AForm(other.getName(), other.getGradeRequiredToSign(), other.getGradeRequiredToExecute()),
target_(other.getTarget()) {
	std::cout << "Copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
		const_cast<std::string&>(target_) = other.getTarget();
	}
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("robotomy request", 72, 45),
	target_(target) {
	std::cout << "RobotomyRequestForm " << target << " Constructor called" << std::endl;
}

const std::string RobotomyRequestForm::getTarget() const {
	return (target_);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) {
	if (this->getSigned() == false) {
		throw (AForm::FormNotSignedException());
	}
	else if (executor.getGrade() > this->getGradeRequiredToExecute()) {
		throw (Bureaucrat::GradeTooLowException());
	}
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	if (std::rand() % 2 == 0) {
		std::cout << this->getTarget() << " has been robotomized successfully 50% of the time!" << std::endl;
	}
	else {
		std::cout << "robotomize failed..." << std::endl;
	}
}

std::ostream& operator <<(std::ostream &out, const RobotomyRequestForm &form) {
	out << "name                      : " << form.getName() << std::endl;
	out << "signed(false:0, true:1)   : " << form.getSigned() << std::endl;
	out << "grade required to sign    : " << form.getGradeRequiredToSign() << std::endl;
	out << "grade required to execute : " << form.getGradeRequiredToExecute() << std::endl;
	out << "target                    : " << form.getTarget();
	return (out);
}