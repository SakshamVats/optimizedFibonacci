#pragma once

#include <array>
#include <vector>
#include <cmath>

namespace Fibonacci
{
	int naive_recursive(int n);

	int memoization(int n);
	int memoization(int n, std::vector<int>& dp);

	int tabulation(int n);

	long long optimized(int n);
	
	long long matrixPowers(int n);
	void power(long long F[2][2], int n);
	void multiply(long long F[2][2], long long M[2][2]);

	long long binetsFormula(int n);

	using IntFuncPtr = int (*)(int);
	using LongLongFuncPtr = long long (*)(int);
	extern const std::array<IntFuncPtr, 3> intMethods;
	extern const std::array<LongLongFuncPtr, 3> longLongMethods;
}
