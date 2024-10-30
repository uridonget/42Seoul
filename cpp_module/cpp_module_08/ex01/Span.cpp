/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghaechan <jeonghaechan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:00:29 by jeonghaecha       #+#    #+#             */
/*   Updated: 2024/06/04 12:29:41 by jeonghaecha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : maxSize(0), curSize(0) {}

Span::~Span() {}

Span::Span(const Span& other) {
    *this = other;
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        maxSize = other.maxSize;
        curSize = 0;
        std::multiset<int>::iterator it = other.arr.begin();
        for (int i=0; i < other.curSize; i++) {
            addNumber(*it);
            it++;
        }    
    }
    return (*this);
}

Span::Span(size_t N) : maxSize(N), curSize(0) {
    if (INT_MAX < static_cast<int>(N)) {
        throw OutOfRangeException();
    }
}

const char* Span::OutOfRangeException::what() const throw() {
    return ("Value out of range!");
}

const char* Span::AlreadyFullException::what() const throw() {
    return ("Span is already full!");
}

void Span::addNumber(int number) {
    if (curSize == maxSize) {
        throw AlreadyFullException();
    }
    curSize++;
    arr.insert(number);
}

const char* Span::NotEnoughNumbersException::what() const throw() {
    return ("There's not enough numbers!");
}

size_t Span::shortestSpan() {
    if (curSize < 2) {
        throw NotEnoughNumbersException();
    }
    size_t shortest = INT_MAX;
    std::multiset<int>::iterator prev = arr.begin();
    std::multiset<int>::iterator next = ++arr.begin();
    for (int i=0; i < curSize - 1; i++) {
        if (static_cast<size_t>(*next - *prev) < shortest) {
            shortest = static_cast<size_t>(*next - *prev);
        }
        prev++;
        next++;
    }
    return (shortest);
}

size_t Span::longestSpan() {
    if (curSize < 2) {
        throw NotEnoughNumbersException();
    }
    std::multiset<int>::iterator smallest = arr.begin();
    std::multiset<int>::iterator biggest = --arr.end();
    return (static_cast<size_t>(*biggest - *smallest));
}

void Span::addNumbers(size_t N) {
    if (curSize + N > maxSize) {
        throw AlreadyFullException();
    }
    curSize += N;
    std::srand(static_cast<unsigned int>(std::clock()));
    std::multiset<int> randomNumbers;
    for (size_t i=0; i < N; i++) {
        randomNumbers.insert(std::rand() % 1000);
    }
    arr.insert(randomNumbers.begin(), randomNumbers.end());
}

void Span::showNumbers() {
    std::cout << "-----------------------" << std::endl;
    std::cout << "MAX SIZE : " << maxSize << std::endl;
    std::cout << "CUR SIZE : " << curSize << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::multiset<int>::iterator it = arr.begin();
    for (int i=0; i < curSize; i++) {
        std::cout << "Span[" << i << "] : " << *it << std::endl;
        it++;
    }
    std::cout << "-----------------------" << std::endl;
    std::cout << "SHORTEST : " << shortestSpan() << std::endl;
    std::cout << "LONGEST  : " << longestSpan() << std::endl;
    std::cout << "-----------------------" << std::endl;
}
