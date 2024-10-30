/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghaechan <jeonghaechan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:36:36 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/25 21:10:00 by jeonghaecha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>

class NotFoundException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Not found!";   
        }
};

template <typename T>
typename T::iterator easyfind(T& stl, int value) {
    typename T::iterator it = std::find(stl.begin(), stl.end(), value);
    if (it == stl.end()) {
        throw NotFoundException();
    }
    return (it);
}

#endif