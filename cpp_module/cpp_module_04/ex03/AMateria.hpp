/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:27:40 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/29 16:27:18 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria
{
	private:
		AMateria();
		
	protected:
		std::string _type;
		
	public:
		AMateria(std::string const &type);
		virtual ~AMateria();
		AMateria(const AMateria& other);
		AMateria& operator=(const AMateria& other);
		
		std::string const & getType() const;
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);
};

#endif
