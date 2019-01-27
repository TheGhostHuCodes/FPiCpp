#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../../common/person.h"

typedef std::pair<std::string, bool> list_item;

std::string title(const list_item& item) {
    return item.first + std::string(item.second, '*');
    //                  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    //                  std::string fill constructor with the signature,
    //                  std::string(size_t n, char c). It fills the string with
    //                  n consecutive copies of of character c. We're using
    //                  implicit bool conversion to generate an empty string or
    //                  a string with a single *.
}

bool is_selected(const list_item& item) { return item.second; }

bool is_not_selected(const list_item& item) { return !item.second; }

// This function groups the selected items in a collection and moves them to
// the desired location.
template <typename It>
void move_selected_to(It first, It last, It destination) {
    std::stable_partition(first, destination, is_not_selected);
    std::stable_partition(destination, last, is_selected);
}

int main(int argc, char* argv[]) {
    std::vector<list_item> people{{"David", true},   {"Jane", false},
                                  {"Martha", false}, {"Peter", false},
                                  {"Rose", true},    {"Tom", true}};

    // This algorithm takes the true values {"David", "Rose", "Tom"} and moves
    // them into the position people.begin() + 3 in the order that they are
    // encountered.
    //
    // David  <- people.begin()
    // Jane
    // Martha
    // Peter <- people.begin() + 3
    // Rose
    // Tom
    //
    // David     Jane
    // Jane      Martha
    // Martha -> David*
    // Peter     Rose*
    // Rose      Tom*
    // Tom       Peter
    move_selected_to(people.begin(), people.end(), people.begin() + 3);

    for (const auto& person : people) {
        std::cout << title(person) << std::endl;
    }
    return 0;
}
