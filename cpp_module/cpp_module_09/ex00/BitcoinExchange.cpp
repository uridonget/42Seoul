/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:00:29 by jeonghaecha       #+#    #+#             */
/*   Updated: 2024/06/16 10:56:52 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::~BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        database_ = other.database_;
    }
    return (*this);
}

static bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } else {
        return false;
    }
}

static bool isValidDate(const std::string& date) {
    int year, month, day;
    char dash1, dash2;

    std::istringstream iss(date);
    if (!(iss >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-') {
        return false;
    }
    if (month < 1 || month > 12 || day < 1) {
        return false;
    }
    static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int days = daysInMonth[month - 1];
    if (month == 2 && isLeapYear(year)) {
        days = 29;
    }
    if (day > days) {
        return false;
    }
    return true;
}

void BitcoinExchange::insertDataToDB(std::string line) {
    std::string::size_type N = line.find(',');
    std::string date = line.substr(0, N);
    if (!isValidDate(date)) {
        std::cerr << "Error: bad input => " << date << std::endl;
        std::exit(EXIT_FAILURE);
    }
    double value = std::atof(line.substr(N + 1).c_str());
    std::pair<std::map<std::string, double>::iterator, bool> result = database_.insert(std::make_pair(date, value));
    if (!(result.second)) {
        std::cerr << "Error: bad input => " << date << "(already exist in DB)" << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

void BitcoinExchange::makeDatabase(std::string DatabaseName) {
    std::ifstream infile(DatabaseName);
    if (!infile.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    std::string line;
    std::getline(infile, line);
    std::string::size_type N = line.find(',');
    if (line.substr(0, N) != "date" || line.substr(N + 1) != "exchange_rate") {
        std::cerr << "Invalid DB file attribute" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    while (std::getline(infile, line)) {
        insertDataToDB(line);
        if (infile.eof()) {
            break ;
        }
    }
    infile.close();
}

double BitcoinExchange::getExchangeRateOfDate(std::string date) {
    std::map<std::string, double>::const_iterator it = database_.upper_bound(date);
    if (it == database_.begin())
        return (-1);
    --it;
    return (it->second);
}

void BitcoinExchange::showValue(std::string line) {
    std::string::size_type N = line.find('|');
    std::string date = line.substr(0, N - 1);
    if (line[N - 1] != ' ' || line[N + 1] != ' ' || !isValidDate(date)) {
        std::cerr << "Error: bad input => " << date << std::endl;
        return ;
    }
    
    double value = std::atof(line.substr(N + 2).c_str());
    if (value <= 0) {
        std::cerr << "Error: not a positive number." << std::endl;
    }
    else if (1000 <= value) {
        std::cerr << "Error: too large a number." << std::endl;
    }
    else {
        double exchangeRate = getExchangeRateOfDate(date);
        if (exchangeRate < 0) {
            std::cerr << "Error: date with no bitcoin" << std::endl;
        }
        else 
            std::cout << date << " => " << value << " = " << value * exchangeRate << std::endl;
    }
}

void BitcoinExchange::readTextFile(std::string TextFileName) {
    std::ifstream infile(TextFileName);
    if (!infile.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    std::string line;
    std::getline(infile, line);
    std::string::size_type N = line.find('|');
    if (line.substr(0, N) != "date " || line.substr(N + 1) != " value") {
        std::cerr << "Error: bad input => " << line << std::endl;
        std::exit(EXIT_FAILURE);
    }
    while (std::getline(infile, line)) {
        showValue(line);
        if (infile.eof()) {
            break ;
        }
    }
    infile.close();
}
