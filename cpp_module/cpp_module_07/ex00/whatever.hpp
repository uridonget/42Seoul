/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghaechan <jeonghaechan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:36:36 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/25 12:57:15 by jeonghaecha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T& a, T& b) {
	std::cout << "SWAP!" << std::endl;
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T a, T b) {
	if (a >= b)
		return (b);
	return (a);
}

template <typename T>
T max(T a, T b) {
	if (a > b)
		return (a);
	return (b);
}

#endif