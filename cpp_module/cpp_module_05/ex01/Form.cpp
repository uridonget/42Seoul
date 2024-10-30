/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:14:50 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/21 17:58:21 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::~Form() {
	std::cout << name_ << " Destructor called" << std::endl;
}

Form::Form(const Form& other) :
name_(other.getName()),
signed_(other.getSigned()),
gradeRequiredToSign_(other.getGradeRequiredToSign()),
gradeRequiredToExecute_(other.getGradeRequiredToExecute()) {
	std::cout << "Copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		const_cast<std::string&>(name_) = other.getName();
		signed_ = other.getSigned();
		const_cast<int&>(gradeRequiredToSign_) = other.getGradeRequiredToSign();
		const_cast<int&>(gradeRequiredToExecute_) = other.getGradeRequiredToExecute();
	}
	return (*this);
}

Form::Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute) :
name_(name),
signed_(false),
gradeRequiredToSign_(gradeRequiredToSign),
gradeRequiredToExecute_(gradeRequiredToExecute) {
	std::cout << "Form " << name_ << " Constructor called" << std::endl;
	if ((gradeRequiredToSign_ > 150) || (gradeRequiredToExecute_ > 150))
		throw GradeTooLowException();
	else if ((gradeRequiredToSign_ < 1) || (gradeRequiredToExecute_ < 1))
		throw GradeTooHighException();
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade is too High!");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low!");
}

const std::string Form::getName() const {
	return (name_);
}

bool Form::getSigned() const {
	return (signed_);
}

int Form::getGradeRequiredToSign() const {
	return (gradeRequiredToSign_);
}

int Form::getGradeRequiredToExecute() const {
	return (gradeRequiredToExecute_);
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() < this->getGradeRequiredToSign())
		this->signed_ = true;
}

std::ostream& operator <<(std::ostream &out, const Form &form) {
	out << "name                      : " << form.getName() << std::endl;
	out << "signed (false:0, true:1)  : " << form.getSigned() << std::endl;
	out << "grade required to sign    : " << form.getGradeRequiredToSign() << std::endl;
	out << "grade required to execute : " << form.getGradeRequiredToExecute();
	return (out);
}
