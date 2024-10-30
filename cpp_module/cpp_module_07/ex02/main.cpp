#include <iostream>
#include "Array.hpp"
#include <ctime>

// static void chk() {
//     system("leaks a.out");
// }

int main()
{
    // atexit(chk);
    Array<int> numbers(10);
    std::srand(static_cast<unsigned int>(std::clock()));
    try {
        for (int i = 0; i < numbers.size(); i++) {
            numbers[i] = rand() % 100;
        }
        for (int i = 0; i < 10; i++) {
            std::cout << "numbers[" << i << "] : " << numbers[i] << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "exception caught: " << e.what() << std::endl;
    }
    std::cout << "----------------------------" << std::endl;
    Array<int> numbers_copy_1 = numbers;
    try {
        for (int i = 0; i < 10; i++) {
            std::cout << "numbers_copy_1[" << i << "] : " << numbers_copy_1[i] << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "exception caught: " << e.what() << std::endl;
    }
    std::cout << "----------------------------" << std::endl;
    Array<int> numbers_copy_2(numbers_copy_1);
    try {
        for (int i = 0; i < 10; i++) {
            std::cout << "numbers_copy_2[" << i << "] : " << numbers_copy_2[i] << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "exception caught: " << e.what() << std::endl;
    }
    return 0;
}