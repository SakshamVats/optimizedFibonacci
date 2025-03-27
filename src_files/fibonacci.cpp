#include "../includes/fibonacci.h"

namespace Fibonacci
{
	// Naive recursive approach (O(2^N))
	int naive_recursive(int n)
	{
		if (n <= 1)
			return n;

		return naive_recursive(n - 1) + naive_recursive(n - 2);
	}

	// Memoization (Top-Down DP) (O(N))
	int memoization(int n)
	{
		std::vector<int> dp(n + 1, -1);
		return memoization(n, dp);
	}
	int memoization(int n, std::vector<int>& dp)
	{
		if (n <= 1)
			return n;

		if (dp[n] != -1)
			return dp[n];

		return dp[n] = memoization(n - 1, dp) + memoization(n - 2, dp);
	}

	// Tabulation (Bottom-Up DP) (O(N))
	int tabulation(int n)
	{
		if (n <= 1)
			return n;

		std::vector<int> dp(n + 1);

		dp[0] = 0;
		dp[1] = 1;

		for (int index{ 2 }; index <= n; ++index)
		{
			dp[index] = dp[index - 1] + dp[index - 2];
		}

		return dp[n];
	}

	// Optimized (3-variable) (O(N) Time, O(1) Space)
	long long optimized(int n)
	{
		if (n <= 1)
			return n;

		long long prev2{ 0 };
		long long prev1{ 1 };
		long long curr{};

		for (int i{ 2 }; i <= n; ++i)
		{
			curr = prev1 + prev2;
			prev2 = prev1;
			prev1 = curr;
		}

		return curr;
	}

	// Matrix Exponentiation (O(logN) Time, O(1) Space) 
	long long matrixPowers(int n)
	{
		if (n == 0)
			return 0;

		long long F[2][2] = { {1, 1},
						{1, 0} };

		power(F, n - 1);

		return F[0][0];
	}
	void power(long long F[2][2], int n)
	{
		if (n == 0 || n == 1)
			return;

		long long M[2][2] = { {1, 1},
						{1, 0} };
		power(F, n / 2);
		multiply(F, F);

		if (n % 2 != 0)
			multiply(F, M);
	}
	void multiply(long long F[2][2], long long M[2][2])
	{
		long long a{ F[0][0] * M[0][0] + F[0][1] * M[1][0] };
		long long b{ F[0][0] * M[0][1] + F[0][1] * M[1][1] };
		long long c{ F[1][0] * M[0][0] + F[1][1] * M[1][0] };
		long long d{ F[1][0] * M[0][1] + F[1][1] * M[1][1] };

		F[0][0] = a;
		F[0][1] = b;
		F[1][0] = c;
		F[1][1] = d;
	}

	// Binet's Formula (accurate for N<70) (O(1) Time, O(1) Space)
	long long binetsFormula(int n)
	{
		long double sqrt5{ std::sqrtl(5.0L) };
		long double phi{ (1.0L + sqrt5) / 2.0L };
		long double fib{ std::powl(phi, n) / sqrt5 };

		return static_cast<long long>(std::roundl(fib));
	}

	const std::array<IntFuncPtr, 3> intMethods
	{
		naive_recursive,
		memoization,
		tabulation
	};

	const std::array<LongLongFuncPtr, 3> longLongMethods
	{
		optimized,
		matrixPowers,
		binetsFormula
	};
}
