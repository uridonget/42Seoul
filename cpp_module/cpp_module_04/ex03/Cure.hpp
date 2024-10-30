/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:40:59 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/29 17:30:42 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria 
{
	public :
		Cure();
		~Cure();
		Cure(Cure const &other);
		Cure& operator=(const Cure& other);
		
		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif
