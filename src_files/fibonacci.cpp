#include "../includes/fibonacci.h"

namespace Fibonacci
{
	int naive_recursive(int n)
	{
		if (n <= 1)
			return n;

		return naive_recursive(n - 1) + naive_recursive(n - 2);
	}
}