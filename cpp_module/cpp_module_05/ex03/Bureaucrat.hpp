/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:27:28 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/21 18:01:16 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string name_;
		int grade_;
		Bureaucrat(); // Default Constructor
		void setGrade(int grade);
		
	public:
		~Bureaucrat(); // Destuctor
		Bureaucrat(const Bureaucrat& other); // Copy Constructor
		Bureaucrat& operator=(const Bureaucrat& other); // Copy assignment operator
		
		Bureaucrat(std::string name, int grade);
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		void increaseGrade();
		void decreaseGrade();
		std::string getName() const;
		int	getGrade() const;
		
		void signForm(AForm &Aform); // ex01
		void executeForm(AForm &Aform); // ex02
};

std::ostream& operator <<(std::ostream &out, const Bureaucrat &bur);

#endif