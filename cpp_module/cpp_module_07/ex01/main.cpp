/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghaechan <jeonghaechan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:03:19 by haejeong          #+#    #+#             */
/*   Updated: 2024/06/04 10:29:32 by jeonghaecha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

static void addOne(int x) {
    std::cout << x + 1 << " ";
}

static void square(double x) {
    std::cout << x * x << " ";
}

static void checkInt() {
	int intArray[] = {1, 2, 3, 4, 5};
	for (int i = 0; i < 5; i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
    iter(intArray, 5, addOne);
    std::cout << std::endl;
}

static void checkDouble() {
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	for (int i = 0; i < 5; i++) {
        std::cout << doubleArray[i] << " ";
    }
    std::cout << std::endl;
    iter(doubleArray, 5, addOne);
    std::cout << std::endl;
}

int main() {
    checkInt();
    std::cout << "---------------------" << std::endl;
    checkDouble();
    return 0;
}