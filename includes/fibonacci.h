#pragma once

#include <vector>

namespace Fibonacci
{
	int naive_recursive(int n);

	int memoization(int n);
	int memoization(int n, std::vector<int>& dp);

	int tabulation(int n);

	int optimized(int n);
	
	int matrixPowers(int n);
	void power(int F[2][2], int n);
	void multiply(int F[2][2], int M[2][2]);
}
