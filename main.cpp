#include <iostream>
#include "includes/fibonacci.h"
#include "includes/testAllMethods.h"
#include "includes/generateTimingJSON.h"

int main()
{
	testAllMethods(10);

    std::vector<std::string> methodNames
    {
        "Naive Recursive", "Memoization", "Tabulation",
        "Optimized", "Matrix Exponentiation", "Binet's Formula"
    };

    std::vector<int> testCases{ 5, 10, 15, 20, 25, 30, 35, 40, 45};

    std::cout << "Generating timing JSON..." << std::endl;
    generateTimingJSON(methodNames, testCases);

    std::cout << "Timing data written to results.json" << std::endl;

    return 0;
}


