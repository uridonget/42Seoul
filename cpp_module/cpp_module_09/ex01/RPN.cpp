/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghaechan <jeonghaechan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:00:29 by jeonghaecha       #+#    #+#             */
/*   Updated: 2024/06/09 15:36:53 by jeonghaecha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) {
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        rawStack = other.rawStack;
        calStack = other.calStack;
    }
    return (*this);
}

static bool checkValidChar(char c) {
    const std::string valids = "+-/*0123456789";
    for (int i=0; i < 14; i++) {
        if (c == valids[i]) {
            return true ;
        }
    }
    return false ;
}

void RPN::makeRawStack(std::string line) {
    int len = line.length() - 1;
    for (int i=len; 0 <= i; i--) {
        if ((i % 2) != 0 && line[i] != ' ') {
            std::cerr << line[i] << std::endl;
            std::cerr << "Error" << std::endl;
            std::exit(EXIT_FAILURE);
        }
        else if ((i % 2) == 0) {
            if (checkValidChar(line[i])) {
                rawStack.push(line[i]);
            }
            else {
                std::cerr << "Error" << std::endl;
                std::exit(EXIT_FAILURE);    
            }
        }
    }
}

void RPN::calculate(char c) {
    if (calStack.size() < 2) {
        std::cerr << "Error" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    int b = calStack.top();
    calStack.pop();
    int a = calStack.top();
    calStack.pop();
    if (c == '+') {
        calStack.push(a + b);
    }
    else if (c == '-') {
        calStack.push(a - b);
    }
    else if (c == '*') {
        calStack.push(a * b);
    }
    else if (c == '/') {
        if (b == 0) {
            std::cerr << "Error" << std::endl;
            std::exit(EXIT_FAILURE);
        }
        calStack.push(a / b);
    }
}

void RPN::calculateStack() {
    const std::string valids = "+-/*";
    while (!rawStack.empty()) {
        
        char c = rawStack.top();
        rawStack.pop();
        if (isdigit(c)) {
            calStack.push(c - '0');
        }
        else
            calculate(c);
    }
    if (calStack.size() != 1) {
        std::cerr << "Error" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    int result = calStack.top();
    calStack.pop();
    std::cout << result << std::endl;
}
