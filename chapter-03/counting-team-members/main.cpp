#include <algorithm>
#include <iostream>
#include <vector>

#include "../../common/person.h"

class company_t {
  public:
    company_t(std::vector<person_t> employees);
    std::string team_name_for(const person_t& person) const;
    int count_team_members(const std::string& team_name) const;

  private:
    std::vector<person_t> m_employees;
};

company_t::company_t(std::vector<person_t> employees)
    : m_employees(employees) {}

std::string company_t::team_name_for(const person_t& person) const {
    return "Moon";
}

int company_t::count_team_members(const std::string& team_name) const {
    return std::count_if(m_employees.cbegin(), m_employees.cend(),
                         [this, &team_name](const person_t& employee) {
                             return team_name_for(employee) == team_name;
                         });
}

int main(int argc, char* argv[]) {
    std::vector<person_t> employees{
        {"Jane", person_t::FEMALE},   {"David", person_t::MALE},
        {"Tom", person_t::MALE},      {"Peter", person_t::MALE},
        {"Martha", person_t::FEMALE}, {"Rose", person_t::FEMALE},
        {"Jon", person_t::MALE},      {"Colin", person_t::MALE},
        {"Clara", person_t::FEMALE}};

    auto company = company_t(employees);
    std::cout << company.count_team_members("Moon") << std::endl;

    return 0;
}
