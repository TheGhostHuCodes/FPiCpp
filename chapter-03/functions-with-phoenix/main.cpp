#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#include "boost/phoenix/function/lazy_prelude.hpp"

using namespace boost::phoenix::arg_names;

int main(int argc, char* argv[]) {
    std::vector<int> numbers{21, 5, 62, 42, 53};
    std::partition(numbers.begin(), numbers.end(), arg1 <= 42);
    std::cout << "expected { 21 5 42 62 53 } got { ";
    for (auto i : numbers) {
        std::cout << i << " ";
    }
    std::cout << "}" << std::endl;

    std::cout << "expect 4441.5 got "
              << std::accumulate(numbers.cbegin(), numbers.cend(), 0.0,
                                 arg1 + arg2 * arg2 / 2.0)
              << std::endl;

    std::cout << "expected 14491260 got "
              << std::accumulate(numbers.cbegin(), numbers.cend(), 1,
                                 arg1 * arg2)
              << std::endl;

    std::sort(numbers.begin(), numbers.end(), arg1 > arg2);
    std::cout << "expected { 62 53 42 21 5 } got { ";
    for (auto i : numbers) {
        std::cout << i << " ";
    }
    std::cout << "}" << std::endl;
}
