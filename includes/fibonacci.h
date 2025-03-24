#pragma once

#include <vector>

namespace Fibonacci
{
	int naive_recursive(int n);

	int memoization(int n);
	int memoization(int n, std::vector<int>& dp);

	int tabulation(int n);
}
