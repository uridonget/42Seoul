/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:48:21 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/19 10:35:01 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main() {
    Fixed a(10);
    Fixed const b(5);
    Fixed c(2.5f);

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;

    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < c: " << (a < c) << std::endl;
    std::cout << "b >= c: " << (b >= c) << std::endl;
    std::cout << "b <= a: " << (b <= a) << std::endl;
    std::cout << "a == a: " << (a == a) << std::endl;
    std::cout << "b != c: " << (b != c) << std::endl;

    std::cout << "a + b: " << (a + b) << std::endl;
    std::cout << "a - c: " << (a - c) << std::endl;
    std::cout << "a * b: " << (a * b) << std::endl;
    std::cout << "a / b: " << (a / b) << std::endl;

    std::cout << "++a: " << (++a) << std::endl;
    std::cout << "a++: " << (a++) << std::endl;
    std::cout << "a: " << a << std::endl;

    std::cout << "--a: " << (--a) << std::endl;
    std::cout << "a--: " << (a--) << std::endl;
    std::cout << "a: " << a << std::endl;

    std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
    std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;

    return 0;
}