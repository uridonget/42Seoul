/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:23:23 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/21 18:00:23 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void checkShrubberyCreationForm() {
    try {
        Bureaucrat showmaker("Showmaker", 130);
        std::cout << showmaker << std::endl;
        std::cout << "----------------------------" << std::endl;
        ShrubberyCreationForm form("tree");
        std::cout << "----------------------------" << std::endl;
        std::cout << form << std::endl;
        std::cout << "----------------------------" << std::endl;
        ShrubberyCreationForm form_copy1(form);
        std::cout << "----------------------------" << std::endl;
        std::cout << form_copy1 << std::endl;
        std::cout << "----------------------------" << std::endl;
        ShrubberyCreationForm form_copy2("dummy");
        form_copy2 = form;
        std::cout << "----------------------------" << std::endl;
        std::cout << form_copy2 << std::endl;
        std::cout << "----------------------------" << std::endl;
        showmaker.signForm(form);
        std::cout << "----------------------------" << std::endl;
        std::cout << form << std::endl;
        std::cout << "----------------------------" << std::endl;
        ShrubberyCreationForm form_copy3("dummy");
        form_copy3 = form;
        std::cout << "----------------------------" << std::endl;
        showmaker.executeForm(form);
        std::cout << "----------------------------" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}

static void checkRobotomyRequestForm() {
    try {
        Bureaucrat nuguri("Nuguri", 50);
        std::cout << nuguri << std::endl;
        std::cout << "----------------------------" << std::endl;
        RobotomyRequestForm form("Robobobot");
        std::cout << "----------------------------" << std::endl;
        std::cout << form << std::endl;
        std::cout << "----------------------------" << std::endl;
        RobotomyRequestForm form_copy1(form);
        std::cout << "----------------------------" << std::endl;
        std::cout << form_copy1 << std::endl;
        std::cout << "----------------------------" << std::endl;
        RobotomyRequestForm form_copy2("dummy");
        form_copy2 = form;
        std::cout << "----------------------------" << std::endl;
        std::cout << form_copy2 << std::endl;
        std::cout << "----------------------------" << std::endl;
        nuguri.signForm(form);
        std::cout << "----------------------------" << std::endl;
        std::cout << form << std::endl;
        std::cout << "----------------------------" << std::endl;
        RobotomyRequestForm form_copy3("dummy");
        form_copy3 = form;
        std::cout << "----------------------------" << std::endl;
        nuguri.executeForm(form);
        std::cout << "----------------------------" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}

static void checkPresidentialPardonForm() {
    try {
        Bureaucrat canyon("canyon", 133);
        std::cout << canyon << std::endl;
        std::cout << "----------------------------" << std::endl;
        PresidentialPardonForm form("tree");
        std::cout << "----------------------------" << std::endl;
        std::cout << form << std::endl;
        std::cout << "----------------------------" << std::endl;
        PresidentialPardonForm form_copy1(form);
        std::cout << "----------------------------" << std::endl;
        std::cout << form_copy1 << std::endl;
        std::cout << "----------------------------" << std::endl;
        PresidentialPardonForm form_copy2("dummy");
        form_copy2 = form;
        std::cout << "----------------------------" << std::endl;
        std::cout << form_copy2 << std::endl;
        std::cout << "----------------------------" << std::endl;
        canyon.signForm(form);
        std::cout << "----------------------------" << std::endl;
        std::cout << form << std::endl;
        std::cout << "----------------------------" << std::endl;
        PresidentialPardonForm form_copy3("dummy");
        form_copy3 = form;
        std::cout << "----------------------------" << std::endl;
        canyon.executeForm(form);
        std::cout << "----------------------------" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}

int main() {
    checkShrubberyCreationForm();
    std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;
    std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;
    std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;
    checkRobotomyRequestForm();
    std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;
    std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;
    std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;
    checkPresidentialPardonForm();
    return 0;
}
