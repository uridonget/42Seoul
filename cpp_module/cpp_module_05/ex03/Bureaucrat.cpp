/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:39:41 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/22 10:43:48 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat() {
	std::cout << name_ << " Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : 
name_(other.getName()),
grade_(other.getGrade()) {
	std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		const_cast<std::string&>(name_) = other.getName();
		grade_ = other.getGrade();
	}
	return (*this);
}

void Bureaucrat::setGrade(int grade) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade_ = grade;
};

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name) {
	std::cout << "Bureaucrat " << name_ << " constructor called" << std::endl;
	setGrade(grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low!");
}

void Bureaucrat::increaseGrade() {
	try {
		setGrade(this->getGrade() - 1);
		std::cout << this->getName() << " increased it's grade to " << grade_ << std::endl;
	} catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}

void Bureaucrat::decreaseGrade() {
	try {
		setGrade(this->getGrade() + 1);
		std::cout << this->getName() << " decreased it's grade to " << grade_ << std::endl;
	} catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}

std::string Bureaucrat::getName() const {
	return (name_);
}

int	Bureaucrat::getGrade() const {
	return (grade_);
}

void Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		if (form.getSigned() == false)
			throw GradeTooLowException();
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm &Aform) {
	try {
		Aform.execute(*this);
		std::cout << this->getName() << " executed " << Aform.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << this->getName() << " couldn't execute " << Aform.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator <<(std::ostream &out, const Bureaucrat &bur) {
	out << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".";
	return (out);
}
