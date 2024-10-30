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

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <cstdlib>
#include <sstream>
#include <cctype>

class RPN
{
    private:
        std::stack<char> rawStack;
        std::stack<int> calStack;
        void calculate(char c);

    public:
        RPN();
        ~RPN();
        RPN(const RPN &other);
        RPN& operator=(const RPN& other);

        void makeRawStack(std::string line);
        void calculateStack();
};




#endif