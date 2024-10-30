/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghaechan <jeonghaechan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:09:45 by jeonghaecha       #+#    #+#             */
/*   Updated: 2024/06/15 12:19:01 by jeonghaecha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_MERGE_ME_HPP
# define P_MERGE_ME_HPP

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <ctime>

class PmergeMe
{
    private:
        std::vector<int> _vec;
        std::vector<int> _tempVec;
        
        std::deque<int> _deq;
        std::deque<int> _tempDeq;
        
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        
    public:
        PmergeMe();
        ~PmergeMe();
        
        size_t Parsing(std::string input);
        void checkEqual();
        
        // vector
        std::vector<int> getJacobsthalVec(size_t span);
        void SwapBySpanVec(size_t span);
        void FordJohnsonVec(size_t & span);
        void moveToMainVec(std::vector<int>::iterator vecIt, size_t tempIndex, size_t span);
        std::vector<int>::iterator getInsertPointVec(size_t span, size_t jacob, size_t idx);
        void insertionVec(size_t & span);
        void SortVec();
        void checkVec();
        // void testVec();

        // deque
        std::deque<int> getJacobsthalDeq(size_t span);
        void SwapBySpanDeq(size_t span);
        void FordJohnsonDeq(size_t & span);
        void moveToMainDeq(std::deque<int>::iterator DeqIt, size_t tempIndex, size_t span);
        std::deque<int>::iterator getInsertPointDeq(size_t span, size_t jacob, size_t idx);
        void insertionDeq(size_t & span);
        void checkDeq();
        void SortDeq();
};

#endif