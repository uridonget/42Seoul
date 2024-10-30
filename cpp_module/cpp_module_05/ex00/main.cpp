/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:23:23 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/22 11:03:50 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    std::cout << "----------------------------" << std::endl;
    try {
        Bureaucrat Doosan("Doosan", 250);
        std::cout << Doosan << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "----------------------------" << std::endl;
    try {
        Bureaucrat SAMSUNG("SAMSUNG", 2);
        std::cout << SAMSUNG << std::endl;
        SAMSUNG.increaseGrade();
        std::cout << SAMSUNG << std::endl;
        SAMSUNG.increaseGrade(); // exception
        std::cout << SAMSUNG << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "----------------------------" << std::endl;
    try {
        Bureaucrat NC("NC", 149);
        std::cout << NC << std::endl;
        NC.decreaseGrade();
        std::cout << NC << std::endl;
        NC.decreaseGrade(); // exception
        std::cout << NC << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "----------------------------" << std::endl;
    try {
        Bureaucrat Hanhwa("Hanhwa", 100);
        std::cout << Hanhwa << std::endl;
        Bureaucrat HanhwaCopy(Hanhwa);
        std::cout << HanhwaCopy << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "----------------------------" << std::endl;
    try {
        Bureaucrat Lotte("Lotte", 75);
        std::cout << Lotte << std::endl;
        Bureaucrat LotteCopy("SSG", 50);
        std::cout << LotteCopy << std::endl;
        LotteCopy = Lotte;
        std::cout << LotteCopy << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}

