/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ITER.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:36:36 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/23 12:25:45 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T, typename U>
void iter(T* t, int length, void (*func)(U)) {
	for (int i=0; i < length; i++) {
		(*func)(t[i]);
	}
}

#endif