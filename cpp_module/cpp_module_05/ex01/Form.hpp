/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:57:24 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/21 17:52:29 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string name_;
		bool signed_;
		const int gradeRequiredToSign_;
		const int gradeRequiredToExecute_;
		Form(); // default constructor
		
	public:
		~Form(); // Destructor
		Form(const Form& other); // Copy Constructor
		Form& operator=(const Form& other); // Copy assignment operator
		
		Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		const std::string getName() const;
		bool getSigned() const;
		int getGradeRequiredToSign() const;
		int getGradeRequiredToExecute() const;
		void beSigned(Bureaucrat &bureaucrat);
};

std::ostream& operator <<(std::ostream &out, const Form &form);

#endif