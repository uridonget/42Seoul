/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:23:19 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/20 19:17:02 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		const std::string target_;
		PresidentialPardonForm(); // Default constructor

	public:
		~PresidentialPardonForm(); // destructor
		PresidentialPardonForm(const PresidentialPardonForm& other); // Copy Constructor
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other); // Copy assignment operator
		
		PresidentialPardonForm(std::string target);
		const std::string getTarget() const;
		void execute(Bureaucrat const & executor);
};

std::ostream& operator <<(std::ostream &out, const PresidentialPardonForm &form);

#endif