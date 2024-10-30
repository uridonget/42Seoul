/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghaechan <jeonghaechan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:14:58 by jeonghaecha       #+#    #+#             */
/*   Updated: 2024/06/15 12:23:25 by jeonghaecha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static void testVector(PmergeMe & sorter, size_t argumentNumber) {
    std::cout << "before : ";
    sorter.checkVec();
    clock_t start = clock();
    sorter.SortVec();
    clock_t end = clock();
    std::cout << std::endl; 
    std::cout << "after : "; 
    sorter.checkVec();
    std::cout << std::endl;
    double duration = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << argumentNumber << " elements with std::vector : " << duration << " us" << std::endl;
}

static void testDeque(PmergeMe & sorter, size_t argumentNumber) {
    clock_t start = clock();
    sorter.SortDeq();
    clock_t end = clock();
    double duration = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << argumentNumber << " elements with std::deque  : " << duration << " us" << std::endl;
}

int main(int ac, char const *av[])
{
    if (ac != 2) {
        std::cout << "Error" << std::endl;
        return (1);
    }
    PmergeMe sorter;
    size_t argumentNumber = sorter.Parsing(static_cast<std::string>(av[1]));
    testVector(sorter, argumentNumber);
    testDeque(sorter, argumentNumber);
    sorter.checkEqual();
    return (0);
}
