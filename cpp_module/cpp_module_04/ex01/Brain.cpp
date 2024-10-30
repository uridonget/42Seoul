/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:17:38 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/29 18:48:57 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {}

Brain::~Brain() {}

Brain::Brain(const Brain& other) {
	*this = other;
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i=0; i < 100; i++) {
			this->ideas[i] = other.ideas[i];
		}
	}
	return (*this);
}
