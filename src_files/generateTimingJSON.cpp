#include <fstream>
#include "../includes/generateTimingJSON.h"
#include "../includes/fibonacci.h"

void generateTimingJSON(const std::vector<std::string>& methodNames, const std::vector<int>& testCases)
{
	std::ofstream file("results.json");
	
	file << "{\n";
	for (size_t i{ 0 }; i < methodNames.size(); ++i)
	{
		file << "  \"" << methodNames[i] << "\": [";

		double timeTaken{};

		for (size_t j{ 0 }; j < testCases.size(); ++j)
		{
			if (i < Fibonacci::intMethods.size())
				timeTaken = measureTime(Fibonacci::intMethods[i], testCases[j]);
			else
				timeTaken = measureTime(Fibonacci::longLongMethods[i - Fibonacci::intMethods.size()], testCases[j]);

			file << timeTaken;

			if (j < testCases.size() - 1)
				file << ", ";
		}

		file << "]";

		if (i < methodNames.size() - 1)
			file << ",\n";
	}

	file << "\n}\n";
	file.close();
}

