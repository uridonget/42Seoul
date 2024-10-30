/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:23:19 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/21 10:35:22 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		const std::string target_;
		RobotomyRequestForm(); // Default constructor
		
	public:
		~RobotomyRequestForm(); // destructor
		RobotomyRequestForm(const RobotomyRequestForm& other); // Copy Constructor
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other); // Copy assignment operator
		
		RobotomyRequestForm(std::string target);
		const std::string getTarget() const;
		void execute(Bureaucrat const & executor);
};

std::ostream& operator <<(std::ostream &out, const RobotomyRequestForm &form);

#endif