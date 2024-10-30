/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghaechan <jeonghaechan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:03:19 by haejeong          #+#    #+#             */
/*   Updated: 2024/06/09 13:13:23 by jeonghaecha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char *av[]) {
    if (ac != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    BitcoinExchange btc;

    btc.makeDatabase("data.csv");
    std::string TextFileName = av[1];
    btc.readTextFile(TextFileName);
    
    return 0;
}
