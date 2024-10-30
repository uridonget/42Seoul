/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:29:48 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/29 17:32:26 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
#define CHARACTER_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *_slot[4];
		
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(MateriaSource const &other);
		MateriaSource& operator=(const MateriaSource& other);
		
		void learnMateria(AMateria *);
		AMateria *createMateria(std::string const &type);
};

#endif
