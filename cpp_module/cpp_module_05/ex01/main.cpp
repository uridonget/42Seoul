/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:23:23 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/22 11:04:16 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat showmaker("showmaker", 50);
        std::cout << showmaker << std::endl;
        std::cout << "----------------------------" << std::endl;
        Form form1("DK", 60, 40);
        std::cout << "----------------------------" << std::endl;
        std::cout << form1 << std::endl;
        std::cout << "----------------------------" << std::endl;
        showmaker.signForm(form1);
        std::cout << "----------------------------" << std::endl;
        std::cout << form1 << std::endl;
        std::cout << "----------------------------" << std::endl;
        Form form2("DWG", 40, 30);
        std::cout << "----------------------------" << std::endl;
        std::cout << form2 << std::endl;
        std::cout << "----------------------------" << std::endl;
        showmaker.signForm(form2);
        std::cout << "----------------------------" << std::endl;
        std::cout << form2 << std::endl;
        std::cout << "----------------------------" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
