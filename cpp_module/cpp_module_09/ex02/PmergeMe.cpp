/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghaechan <jeonghaechan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:11:18 by jeonghaecha       #+#    #+#             */
/*   Updated: 2024/06/15 12:23:18 by jeonghaecha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

size_t PmergeMe::Parsing(std::string input) {
    std::stringstream ss(input);
    std::string temp;
    while (ss >> temp) {
        size_t pos;
        int num = std::stoi(temp, &pos);
        if (pos != temp.size() || num < 0) {
            std::cout << "Error : Invalid input" << std::endl;
            std::exit(EXIT_FAILURE);
        }
        _vec.push_back(num);
        _deq.push_back(num);
    }
    if (_vec.size() == 0 || _deq.size() == 0) {
        std::cout << "Error : Invalid input" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return (_deq.size());
}

void PmergeMe::checkEqual() {
    if (_vec.size() != _deq.size()) {
        std::cout << "Error : not equal number in containers" << std::endl;
    }
    std::vector<int>::iterator vectorIt = _vec.begin();
    std::deque<int>::iterator dequeIt = _deq.begin();
    for (int i=0; i < _vec.size(); i++) {
        if (*vectorIt - *dequeIt) {
            std::cout << "Error : not equal" << std::endl;
            break ;
            vectorIt++;
            dequeIt++;    
        }
    }
    if (!(std::is_sorted(_vec.begin(), _vec.end()))) {
        std::cout << "Error : not sorted" << std::endl;
    }
}

///////////////////////////VECTOR///////////////////////////

std::vector<int> PmergeMe::getJacobsthalVec(size_t span) {
    size_t size = _tempVec.size() / span;
    std::vector<int> numbers;
    for (int i=1; i <= size; i++) {
        numbers.push_back(i);
    }
    std::vector<int> jacobsthalVec;
    int j0 = 0, j1 = 1;
    int j2 = j1 + 2 * j0;
    jacobsthalVec.push_back(j2);
    for (int i = 3; j2 < size; ++i) {
        int jn = j2 + 2 * j1;
        j1 = j2;
        j2 = jn;
        int val = jn;
        if (size < val)
            val = size;
        while (j1 < val) {
            jacobsthalVec.push_back(val - 1);
            val--;
        }
    }
    return (jacobsthalVec);
}

void PmergeMe::SwapBySpanVec(size_t span) {
    for (size_t i=0; i < _vec.size(); i += 2 * span) {
        if (_vec.size() < i + 2 * span)
            return ;
        std::vector<int>::iterator prev = _vec.begin() + i;
        std::vector<int>::iterator next = prev + span;
        if (*prev < *next) {
            for (size_t j=0; j < span; j++) {
                int temp = *(prev + j);
                *(prev + j) = *(next + j);
                *(next + j) = temp;
            }    
        }
    }
}

void PmergeMe::FordJohnsonVec(size_t & span) {
    SwapBySpanVec(span);
    if (_vec.size() <= span * 2) {
        return ;
    }
    span *= 2;
    FordJohnsonVec(span);
}

void PmergeMe::moveToMainVec(std::vector<int>::iterator mainIt, size_t tempIndex, size_t span) {
    std::vector<int>::iterator it = _tempVec.begin() + tempIndex * span;
    // if (mainIt == _vec.end()) 
    //     std::cout << "이동할 곳 : END" << std::endl;
    // else 
    //     std::cout << "이동할 곳 : " << *mainIt << std::endl;
    // std::cout << "이동할 값 : " << *it << std::endl;
    _vec.insert(mainIt, it, it + span);
    // testVec();
}

std::vector<int>::iterator PmergeMe::getInsertPointVec(size_t span, size_t jacob, size_t idx) {
    std::vector<int> compare;
    std::vector<int>::iterator it = _vec.begin();
    size_t cnt = jacob + idx;
    // std::cout << "compare : ";
    for (size_t i=0; i < cnt; i++) {
        compare.push_back(*it);
        // std::cout << *it << ' ';
        it += span;
    }
    // std::cout << std::endl;
    it = _tempVec.begin() + span * jacob;
    std::vector<int>::iterator point = std::upper_bound(compare.begin(), compare.end(), *it);
    if (point == compare.end())
        return (_vec.begin() + cnt * span);
    return (_vec.begin() + static_cast<size_t>(point - compare.begin()) * span);
}

void PmergeMe::insertionVec(size_t & span) {
    if (span == 0) {
        return ;
    }
    // std::cout << "** SPAN : " << span << " **" << std::endl;
    // testVec();
    std::vector<int>::iterator it = _vec.begin();
    size_t vecSize = _vec.size();
    for (size_t i=0; i < vecSize / (2 * span); i++) {
        it += span;
        for (size_t j=0; j < span; j++) {
            int temp = *it;
            it = _vec.erase(it);
            _tempVec.push_back(temp);   
        }
    }
    if (span <= vecSize % (2 * span)) {
        for (size_t j=0; j < span; j++) {
            int temp = *it;
            it = _vec.erase(it);
            _tempVec.push_back(temp);
        }
    }
    // testVec();
    std::vector<int> _jacob = getJacobsthalVec(span);
    size_t i = 0;
    if (vecSize / span >= 1) {
        moveToMainVec(_vec.begin(), i++, span);
    }
    size_t tempSize = _tempVec.size() / span;
    --vecSize = _vec.size() / span;
    for (; i < tempSize; i++) {
        moveToMainVec(getInsertPointVec(span, _jacob[i], i), _jacob[i], span);
    }
    _tempVec.erase(_tempVec.begin(), _tempVec.end());
    span /= 2;
    insertionVec(span);
}

void PmergeMe::checkVec() {
    for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}

// void PmergeMe::testVec() {
    // std::cout << std::endl;
    // std::cout << "MAIN : ";
    // for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it) {
    //     std::cout << *it << ' ';
    // }
    // std::cout << std::endl;
    // std::cout << "SUB  : ";
    // for (std::vector<int>::iterator it = _tempVec.begin(); it != _tempVec.end(); ++it) {
    //     std::cout << *it << ' ';
    // }
    // std::cout << std::endl;
// }

void PmergeMe::SortVec() {
    size_t span = 1;
    FordJohnsonVec(span);
    // std::cout << "MERGE END" << std::endl;
    // testVec();
    insertionVec(span);
}


















































































///////////////////////////DEQUE///////////////////////////

std::deque<int> PmergeMe::getJacobsthalDeq(size_t span) {
    size_t size = _tempDeq.size() / span;
    std::deque<int> numbers;
    for (int i=1; i <= size; i++) {
        numbers.push_back(i);
    }
    std::deque<int> jacobsthalDeq;
    int j0 = 0, j1 = 1;
    int j2 = j1 + 2 * j0;
    jacobsthalDeq.push_back(j2);
    for (int i = 3; j2 < size; ++i) {
        int jn = j2 + 2 * j1;
        j1 = j2;
        j2 = jn;
        int val = jn;
        if (size < val)
            val = size;
        while (j1 < val) {
            jacobsthalDeq.push_back(val - 1);
            val--;
        }
    }
    return (jacobsthalDeq);
}

void PmergeMe::SwapBySpanDeq(size_t span) {
    for (size_t i=0; i < _deq.size(); i += 2 * span) {
        if (_deq.size() < i + 2 * span)
            return ;
        std::deque<int>::iterator prev = _deq.begin() + i;
        std::deque<int>::iterator next = prev + span;
        if (*prev < *next) {
            for (size_t j=0; j < span; j++) {
                int temp = *(prev + j);
                *(prev + j) = *(next + j);
                *(next + j) = temp;
            }    
        }
    }
}

void PmergeMe::FordJohnsonDeq(size_t & span) {
    SwapBySpanDeq(span);
    if (_deq.size() <= span * 2) {
        return ;
    }
    span *= 2;
    FordJohnsonDeq(span);
}

void PmergeMe::moveToMainDeq(std::deque<int>::iterator mainIt, size_t tempIndex, size_t span) {
    std::deque<int>::iterator it = _tempDeq.begin() + tempIndex * span;
    _deq.insert(mainIt, it, it + span);
}

std::deque<int>::iterator PmergeMe::getInsertPointDeq(size_t span, size_t jacob, size_t idx) {
    std::deque<int> compare;
    std::deque<int>::iterator it = _deq.begin();
    size_t cnt = jacob + idx;
    for (size_t i=0; i < cnt; i++) {
        compare.push_back(*it);
        it += span;
    }
    it = _tempDeq.begin() + span * jacob;
    std::deque<int>::iterator point = std::upper_bound(compare.begin(), compare.end(), *it);
    if (point == compare.end())
        return (_deq.begin() + cnt * span);
    return (_deq.begin() + static_cast<size_t>(point - compare.begin()) * span);
}

void PmergeMe::insertionDeq(size_t & span) {
    if (span == 0) {
        return ;
    }
    std::deque<int>::iterator it = _deq.begin();
    size_t deqSize = _deq.size();
    for (size_t i=0; i < deqSize / (2 * span); i++) {
        it += span;
        for (size_t j=0; j < span; j++) {
            int temp = *it;
            it = _deq.erase(it);
            _tempDeq.push_back(temp);
        }
    }
    if (span <= deqSize % (2 * span)) {
        for (size_t j=0; j < span; j++) {
            int temp = *it;
            it = _deq.erase(it);
            _tempDeq.push_back(temp);
        }
    }
    std::deque<int> _jacob = getJacobsthalDeq(span);
    size_t i = 0;
    if (deqSize / span >= 1) {
        moveToMainDeq(_deq.begin(), i++, span);
    }
    size_t tempSize = _tempDeq.size() / span;
    --deqSize = _deq.size() / span;
    for (; i < tempSize; i++) {
        moveToMainDeq(getInsertPointDeq(span, _jacob[i], i), _jacob[i], span);
    }
    _tempDeq.erase(_tempDeq.begin(), _tempDeq.end());
    span /= 2;
    insertionDeq(span);
}

void PmergeMe::checkDeq() {
    for (std::deque<int>::iterator it = _deq.begin(); it != _deq.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}

void PmergeMe::SortDeq() {
    size_t span = 1;
    FordJohnsonDeq(span);
    insertionDeq(span);
}
