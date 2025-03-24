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
}