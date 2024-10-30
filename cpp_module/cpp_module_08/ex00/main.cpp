/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghaechan <jeonghaechan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:25:51 by haejeong          #+#    #+#             */
/*   Updated: 2024/06/04 11:56:39 by jeonghaecha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

static void testVector() {
	std::cout << "VECTOR TEST" << std::endl;
	int arr[] = {1, 2, 3, 4, 5, 100};
	std::vector<int> vec(arr, arr + 6);
	try {
        std::vector<int>::iterator it = easyfind(vec, 5);
		std::cout << "Found value : " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught : " << e.what() << std::endl;
    }
	try {
        std::vector<int>::iterator it = easyfind(vec, 100);
		std::cout << "Found value : " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught : " << e.what() << std::endl;
    }
}

static void testList() {
	std::cout << "LIST TEST" << std::endl;
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
	lst.push_back(100);
    try {
        std::list<int>::iterator it = easyfind(lst, 3);
        std::cout << "Found value : " << *it << std::endl;
    } catch (const NotFoundException& e) {
        std::cerr << "Exception caught : " << e.what() << std::endl;
    }
    try {
        std::list<int>::iterator it = easyfind(lst, 8);
        std::cout << "Found value : " << *it << std::endl;
    } catch (const NotFoundException& e) {
        std::cerr << "Exception caught : " << e.what() << std::endl;
    }
}

int main() {
    testVector();
    std::cout << "-----------------------" << std::endl;
	testList();
    return 0;
}