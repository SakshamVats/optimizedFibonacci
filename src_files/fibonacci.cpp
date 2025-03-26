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

		return memoization(n - 1, dp) + memoization(n - 2, dp);
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
	int optimized(int n)
	{
		if (n <= 1)
			return n;

		int prev2{ 0 };
		int prev1{ 1 };
		int curr{};

		for (int i{ 2 }; i <= n; ++i)
		{
			curr = prev1 + prev2;
			prev2 = prev1;
			prev1 = curr;
		}

		return curr;
	}

	// Matrix Exponentiation (O(logN) Time, O(1) Space) 
	int matrixPowers(int n)
	{
		if (n == 0)
			return 0;

		int F[2][2] = { {1, 1},
						{1, 0} };

		power(F, n - 1);

		return F[0][0];
	}
	void power(int F[2][2], int n)
	{
		if (n == 0 || n == 1)
			return;

		int M[2][2] = { {1, 1},
						{1, 0} };
		power(F, n / 2);
		multiply(F, F);

		if (n % 2 != 0)
			multiply(F, M);
	}
	void multiply(int F[2][2], int M[2][2])
	{
		int a{ F[0][0] * M[0][0] + F[0][1] * M[1][0] };
		int b{ F[0][0] * M[0][1] + F[0][1] * M[1][1] };
		int c{ F[1][0] * M[0][0] + F[1][1] * M[1][0] };
		int d{ F[1][0] * M[0][1] + F[1][1] * M[1][1] };

		F[0][0] = a;
		F[0][1] = b;
		F[1][0] = c;
		F[1][1] = d;
	}
}
