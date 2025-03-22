#include <iostream>
#include "includes/fibonacci.h"

int main()
{
	constexpr int n{ 10 };

	std::cout << "The " << n << "th Fibonacci number is: " << Fibonacci::naive_recursive(n) << '\n';

	return 0;
}

