/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:57:24 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/20 17:44:59 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_FORM_HPP
# define A_FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string name_;
		bool signed_;
		const int gradeRequiredToSign_;
		const int gradeRequiredToExecute_;
		AForm(); // default constructor
		
	public:
		virtual ~AForm(); // Destructor
		AForm(const AForm& other); // Copy Constructor
		AForm& operator=(const AForm& other); // Copy assignment operator
		
		AForm(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		const std::string getName() const;
		bool getSigned() const;
		int getGradeRequiredToSign() const;
		int getGradeRequiredToExecute() const;
		void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const & executor) = 0; // pure virtual function to make abstract class
};

std::ostream& operator <<(std::ostream &out, const AForm &Aform);

#endif