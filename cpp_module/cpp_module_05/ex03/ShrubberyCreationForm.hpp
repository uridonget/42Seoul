/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:23:19 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/21 10:32:18 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

#include <fstream>
#include <cstdlib>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		const std::string target_;
		ShrubberyCreationForm(); // Default constructor
		
	public:
		~ShrubberyCreationForm(); // destructor
		ShrubberyCreationForm(const ShrubberyCreationForm& other); // Copy Constructor
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other); // Copy assignment operator
		
		ShrubberyCreationForm(std::string target);
		const std::string getTarget() const;
		void execute(Bureaucrat const & executor);
};

std::ostream& operator <<(std::ostream &out, const ShrubberyCreationForm &form);

#endif