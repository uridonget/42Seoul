/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:23:23 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/21 18:12:00 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    try {
        std::cout << "----------------------------" << std::endl;
        Intern intern;
        std::cout << "----------------------------" << std::endl;
        Bureaucrat showmaker("Showmaker", 1);
        std::cout << "----------------------------" << std::endl;
        std::cout << showmaker << std::endl;
        std::cout << "----------------------------" << std::endl;
        AForm* form1 = intern.makeForm("shrubbery creation", "BERY");
        std::cout << "----------------------------" << std::endl;
        if (form1) {
            std::cout << *form1 << std::endl;
            std::cout << "target                    : " << form1->getTarget() << std::endl;
            std::cout << "----------------------------" << std::endl;
            showmaker.signForm(*form1);
            std::cout << "----------------------------" << std::endl;
            showmaker.executeForm(*form1);
            std::cout << "----------------------------" << std::endl;
            delete form1;
        }
        std::cout << "----------------------------" << std::endl;
        AForm* form2 = intern.makeForm("robotomy request", "ROBO");
        std::cout << "----------------------------" << std::endl;
        if (form2) {
            std::cout << *form2 << std::endl;
            std::cout << "target                    : " << form2->getTarget() << std::endl;
            std::cout << "----------------------------" << std::endl;
            showmaker.signForm(*form2);
            std::cout << "----------------------------" << std::endl;
            showmaker.executeForm(*form2);
            std::cout << "----------------------------" << std::endl;
            delete form2;
        }
        std::cout << "----------------------------" << std::endl;
        AForm* form3 = intern.makeForm("presidential pardon", "PARD");
        std::cout << "----------------------------" << std::endl;
        if (form3) {
            std::cout << *form3 << std::endl;
            std::cout << "target                    : " << form3->getTarget() << std::endl;
            std::cout << "----------------------------" << std::endl;
            showmaker.signForm(*form3);
            std::cout << "----------------------------" << std::endl;
            showmaker.executeForm(*form3);
            std::cout << "----------------------------" << std::endl;
            delete form3;
        }
        std::cout << "----------------------------" << std::endl;
        AForm* form4 = intern.makeForm("invalid form", "target"); // exception
        std::cout << "----------------------------" << std::endl;
        if (form4) {
            std::cout << *form4 << std::endl;
            std::cout << "target                    : " << form4->getTarget() << std::endl;
            std::cout << "----------------------------" << std::endl;
            showmaker.signForm(*form4);
            std::cout << "----------------------------" << std::endl;
            showmaker.executeForm(*form4);
            std::cout << "----------------------------" << std::endl;
            delete form4;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
