#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../../common/person.h"

std::string name(const person_t& person) { return person.name(); }

bool is_female(const person_t& person) {
    return person.gender() == person_t::FEMALE;
}

bool is_not_female(const person_t& person) { return !is_female(person); }

int main(int argc, char* argv[]) {

    std::vector<person_t> people{
        {"David", person_t::MALE},    {"Jane", person_t::FEMALE},
        {"Martha", person_t::FEMALE}, {"Peter", person_t::MALE},
        {"Rose", person_t::FEMALE},   {"Tom", person_t::MALE}};

    // Filtering with the erase-remove idiom.
    people.erase(std::remove_if(people.begin(), people.end(), is_not_female),
                 people.end());
    for (const person_t& person : people) {
        std::cout << person.name() << std::endl;
    }
    return 0;
}
