/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:56:27 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/29 19:07:49 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice()); // ice learned!
	src->learnMateria(new Cure()); // cure learned!
	ICharacter* me = new Character("me");

	AMateria	*tmp;	
	AMateria	*tmp1;
	AMateria	*tmp2;
	AMateria	*tmp3;
	AMateria	*tmp4;

	tmp = src->createMateria("ice"); // ice created!
	me->equip(tmp); // ice equiped!
	tmp1 = src->createMateria("cure"); // cure created!
	me->equip(tmp1); // cure equiped!
	tmp = src->createMateria("fire"); // There is no Materia named fire
	me->equip(tmp); // There is no Materia (because line above returned NULL)

	ICharacter* bob = new Character("bob");
	me->use(0, *bob); // * shoots an ice bolt at bob *
	me->use(1, *bob); // * heals bob’s wounds *
	me->use(2, *bob); // 2 slot is empty!
	me->use(-4, *bob); // -4 is invalid idx!
	me->use(18, *bob); // 18 is invalid idx!

	Character	*charles = new Character("Charles");
	tmp2 = src->createMateria("cure"); // cure created!
	charles->equip(tmp2); // cure equiped!
	tmp3 = src->createMateria("ice"); // ice created!
	charles->equip(tmp3); // ice equiped!
	tmp = src->createMateria("earth"); // There is no Materia named earth
	charles->equip(tmp); // There is no Materia
	Character	*charles_copy = new Character(*charles);

	charles->unequip(0); // cure unequiped!
	tmp4 = charles_copy->getMateria(1); 
	charles_copy->unequip(1); // ice unequiped!
	delete tmp4;
	tmp = src->createMateria("cure"); // cure created!
	charles_copy->equip(tmp); // cure equiped!
	tmp = src->createMateria("ice"); // ice created!
	charles_copy->equip(tmp); // ice equiped!

	charles->use(0, *bob); // 0 slot is empty!
	charles->use(1, *bob); // * shoots an ice bolt at bob *
	charles->use(2, *bob); // 2 slot is empty!
	charles->use(3, *bob); // 3 slot is empty!
	charles_copy->use(0, *bob); // * heals bob’s wounds *
	charles_copy->use(1, *bob); // * heals bob’s wounds *
	charles_copy->use(2, *bob); // * shoots an ice bolt at bob *
	charles_copy->use(3, *bob); // 3 slot is empty!

	me->unequip(-1); // -1 is invalid idx!
	me->unequip(18); // 18 is invalid idx!
	me->unequip(3); // 3 slot is empty!
	me->use(1, *charles); // * heals Charles’s wounds *
	me->unequip(1); // cure unequiped!
	me->use(1, *charles); // 1 slot is empty!

	delete bob;
	delete me;
	delete src;
	delete charles;
	delete charles_copy;
	delete tmp1;
	delete tmp2;
	return 0;
}