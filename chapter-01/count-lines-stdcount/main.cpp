#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>
#include <vector>

// This function opens a file specified by the filename argument and counts the
// number of lines in the file. The number of lines is defined in this case as
// the number of newline characters encountered.
int count_lines(const std::string& filename) {
    std::ifstream in(filename);
    in.unsetf(std::ios_base::skipws);
    return std::count(std::istream_iterator<char>(in),
                      std::istream_iterator<char>(), '\n');
}

// Given a list of files, this function returns a list of line counts for each
// file.
std::vector<int> count_lines_in_files(const std::vector<std::string>& files) {
    std::vector<int> results;
    for (const auto& file : files) {
        results.push_back(count_lines(file));
    }
    return results;
}

int main(int argc, char* argv[]) {
    auto results = count_lines_in_files({"main.cpp", "CMakeLists.txt"});
    for (auto result : results) {
        std::cout << result << " lines(s)\n";
    }
    return 0;
}
