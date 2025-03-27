#include <iostream>
#include "../includes/testAllMethods.h"
#include "../includes/fibonacci.h"

void testAllMethods(int n)
{
	namespace fb = Fibonacci;

	std::cout << "The " << n << "th Fibonacci number is: " << fb::naive_recursive(n) << '\n';
	std::cout << "The " << n << "th Fibonacci number is: " << fb::memoization(n) << '\n';
	std::cout << "The " << n << "th Fibonacci number is: " << fb::tabulation(n) << '\n';
	std::cout << "The " << n << "th Fibonacci number is: " << fb::optimized(n) << '\n';
	std::cout << "The " << n << "th Fibonacci number is: " << fb::matrixPowers(n) << '\n';
	std::cout << "The " << n << "th Fibonacci number is: " << fb::binetsFormula(n) << '\n';
}