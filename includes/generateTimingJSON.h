#pragma once

#include <chrono>

template <typename Func>
double measureTime(Func fbFunc, int n)
{
	auto start{ std::chrono::high_resolution_clock::now() };
	fbFunc(n);
	auto end{ std::chrono::high_resolution_clock::now() };

	std::chrono::duration<double, std::nano> elapsed{ end - start };
	return elapsed.count();
}

void generateTimingJSON(const std::vector<std::string>& methodNames, const std::vector<int>& testCases);
