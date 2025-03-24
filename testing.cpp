#include <iostream>
#include "includes/fibonacci.h"

int main()
{
	constexpr int n{ 10 };

	namespace fb = Fibonacci;

	std::cout << "The " << n << "th Fibonacci number is: " << fb::naive_recursive(n) << '\n';
	std::cout << "The " << n << "th Fibonacci number is: " << fb::memoization(n) << '\n';
	std::cout << "The " << n << "th Fibonacci number is: " << fb::tabulation(n) << '\n';

	return 0;
}

