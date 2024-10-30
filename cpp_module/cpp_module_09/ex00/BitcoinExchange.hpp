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

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <fstream>
#include <cstdlib>
#include <sstream>

class BitcoinExchange {
    private:
        std::map<std::string, double> database_;
        void insertDataToDB(std::string line);
        double getExchangeRateOfDate(std::string date);
        void showValue(std::string line);
        
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);

        void makeDatabase(std::string DatabaseName);
        void readTextFile(std::string TextFileName);
};

#endif