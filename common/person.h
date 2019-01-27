#pragma once

#include <string>

class person_t {
  public:
    enum gender_t { FEMALE, MALE, OTHER };

    enum output_format_t { NAME_ONLY, FULL_NAME };

    person_t() : m_name("John"), m_surname("Doe"), m_gender(OTHER) {}
    person_t(std::string name, gender_t gender, int age = 0)
        : m_name(name), m_surname("Doe"), m_gender(gender), m_age(age) {}
    person_t(std::string name, const std::string& surname, gender_t gender,
             int age = 0)
        : m_name(name), m_surname(surname), m_gender(gender), m_age(age) {}

    std::string name() const { return m_name; }
    std::string surname() const { return m_surname; }
    gender_t gender() const { return m_gender; }
    int age() const { return m_age; }

    void print(std::ostream& out, person_t::output_format_t format) const {
        if (format == person_t::NAME_ONLY) {
            out << name() << std::endl;
        } else if (format == person_t::FULL_NAME) {
            out << name() << ' ' << surname() << std::endl;
        }
    }

  private:
    std::string m_name;
    std::string m_surname;
    gender_t m_gender;
    int m_age;
};
