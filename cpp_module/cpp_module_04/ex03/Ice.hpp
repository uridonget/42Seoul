/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:24:10 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/29 14:14:10 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria 
{
	public :
		Ice();
		~Ice();
		Ice(Ice const &other);
		Ice& operator=(const Ice& other);
		
		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif