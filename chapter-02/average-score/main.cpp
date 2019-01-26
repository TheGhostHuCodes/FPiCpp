#include <iostream>
#include <numeric>
#include <vector>

double imperative_average_score(const std::vector<int>& scores) {
    int sum = 0;
    for (int score : scores) {
        sum += score;
    }
    return sum / (double)scores.size();
}

// Takes a vector of ints and uses std::accumulate to calculate the average.
double functional_avereage_score(const std::vector<int>& scores) {
    return std::accumulate(scores.cbegin(), scores.cend(), 0)
           / (double)scores.size();
}

// Supply a custom operation to std::accumulate to multiply all scores.
double functional_scores_product(const std::vector<int>& scores) {
    return std::accumulate(scores.cbegin(), scores.cend(), 1,
                           std::multiplies<int>());
}

int main(int argc, char* argv[]) {
    std::cout << "Imperative Average Score: "
              << imperative_average_score({1, 2, 3, 4}) << std::endl;
    std::cout << "Functional Average Score: "
              << functional_avereage_score({1, 2, 3, 4}) << std::endl;
    std::cout << "Functional Score Product: "
              << functional_scores_product({1, 2, 3, 4}) << std::endl;
}
