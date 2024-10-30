/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghaechan <jeonghaechan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:03:19 by haejeong          #+#    #+#             */
/*   Updated: 2024/06/09 15:34:46 by jeonghaecha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char *av[]) {
    if (ac != 2) {
        std::cerr << "Invalid number of argument" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    std::string line = av[1];
    RPN rpn;
    rpn.makeRawStack(line);
    rpn.calculateStack();
    return 0;
}
