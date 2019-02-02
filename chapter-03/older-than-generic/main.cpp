#include <algorithm>
#include <iostream>
#include <vector>

#include "../../common/person.h"

// Implements a generic function object that compares an object's age against a
// predefined integer limit.
class older_than {
  public:
    older_than(int limit) : m_limit(limit) {}

    // Defining a call operator as a template function, we will
    // create a generic function object that deduces the type of
    // its argument when invoked.
    template <typename T> bool operator()(T&& object) const {
        return std::forward<T>(object).age() > m_limit;
    }

  private:
    int m_limit;
};

int main(int argc, char* argv[]) {
    std::vector<person_t> people{
        {"David", person_t::MALE, 1},    {"Jane", person_t::FEMALE, 2},
        {"Martha", person_t::FEMALE, 3}, {"Peter", person_t::MALE, 42},
        {"Rose", person_t::FEMALE, 43},  {"Tom", person_t::MALE, 44}};

    older_than predicate(42);

    std::cout << std::count_if(people.cbegin(), people.cend(), predicate)
              << std::endl;
    return 0;
}
