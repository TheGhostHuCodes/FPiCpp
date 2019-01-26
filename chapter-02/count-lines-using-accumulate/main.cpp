#include <iostream>
#include <numeric>

// Increments previous count by one if the input character is a newline
// character.
int counter(int previous_count, char c) {
    return (c != '\n') ? previous_count : previous_count + 1;
}

int count_lines(const std::string& s) {
    return std::accumulate(s.cbegin(), s.cend(), 0, counter);
}

int main(int argc, char* argv[]) {
    std::cout << count_lines("an ancient pond \n"
                             "a frog jumps in \n"
                             "the splash of water\n")
              << std::endl;
    return 0;
}
