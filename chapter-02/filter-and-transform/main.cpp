#include <algorithm>
#include <iostream>
#include <iterator>
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

    // Filtering the collection by copying.
    std::vector<person_t> females;
    std::copy_if(people.cbegin(), people.cend(), std::back_inserter(females),
                 is_female);
    //
    // Map over list of people and grab names.
    std::vector<std::string> names(females.size());
    std::transform(females.cbegin(), females.cend(), names.begin(), name);

    for (const auto& name : names) {
        std::cout << name << std::endl;
    }
    return 0;
}
