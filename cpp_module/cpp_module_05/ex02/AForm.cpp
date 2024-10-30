/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:14:50 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/20 15:12:11 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::~AForm() {
	std::cout << name_ << " Destructor called" << std::endl;
}

AForm::AForm(const AForm& other) :
name_(other.getName()),
signed_(other.getSigned()),
gradeRequiredToSign_(other.getGradeRequiredToSign()),
gradeRequiredToExecute_(other.getGradeRequiredToExecute()) {
	std::cout << "Copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		const_cast<std::string&>(name_) = other.getName();
		signed_ = other.getSigned();
		const_cast<int&>(gradeRequiredToSign_) = other.getGradeRequiredToSign();
		const_cast<int&>(gradeRequiredToExecute_) = other.getGradeRequiredToExecute();
	}
	return (*this);
}

AForm::AForm(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute) :
name_(name),
signed_(false),
gradeRequiredToSign_(gradeRequiredToSign),
gradeRequiredToExecute_(gradeRequiredToExecute) {
	std::cout << "AForm " << name_ << " Constructor called" << std::endl;
	if ((gradeRequiredToSign_ > 150) || (gradeRequiredToExecute_ > 150))
		throw GradeTooLowException();
	else if ((gradeRequiredToSign_ < 1) || (gradeRequiredToExecute_ < 1))
		throw GradeTooHighException();
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too low!");
}

const char* AForm::FormNotSignedException::what() const throw() {
	return ("Form is not signed!");
}

const std::string AForm::getName() const {
	return (name_);
}

bool AForm::getSigned() const {
	return (signed_);
}

int AForm::getGradeRequiredToSign() const {
	return (gradeRequiredToSign_);
}

int AForm::getGradeRequiredToExecute() const {
	return (gradeRequiredToExecute_);
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() < this->getGradeRequiredToSign())
		this->signed_ = true;
}

std::ostream& operator <<(std::ostream &out, const AForm &Aform) {
	out << "name                      : " << Aform.getName() << std::endl;
	out << "signed(false:0, true:1)   : " << Aform.getSigned() << std::endl;
	out << "grade required to sign    : " << Aform.getGradeRequiredToSign() << std::endl;
	out << "grade required to execute : " << Aform.getGradeRequiredToExecute();
	return (out);
}
