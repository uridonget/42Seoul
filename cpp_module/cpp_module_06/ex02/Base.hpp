/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:40:57 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/24 14:52:49 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <string>
#include <ctime>

class Base
{
	public:
		virtual ~Base();
};

/*
It randomly instanciates A, B or C and returns the instance as a Base pointer. 
Feel free to use anything you like for the random choice implementation.
*/
Base* generate(void);

/*
It prints the actual type of the object pointed to by p: "A", "B" or "C".
*/
void identify(Base* p);

/*
It prints the actual type of the object pointed to by p: "A", "B" or "C". 
Using a pointer inside this function is forbidden.
*/
void identify(Base& p);


#endif