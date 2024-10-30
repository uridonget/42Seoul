/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:27:32 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/29 17:30:29 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter 
{
	private:
		std::string	_name;
		AMateria*	_slot[4];
		Character();
		
	public:
		Character(std::string name);
		~Character();
		Character(Character const &other);
		Character& operator=(const Character& other);

		std::string const & getName() const;
		void equip(AMateria* materia);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		AMateria	*getMateria(int idx);
};

#endif