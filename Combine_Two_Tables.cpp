#include <iostream>
#include <vector>
#include <string>
#include <optional> // para manejar campos opcionales (como null)

using namespace std;

struct Person {
    int personId;
    string lastName;
    string firstName;
};

struct Address {
    int addressId;
    int personId;
    string city;
    string state;
};

struct Result {
    string firstName;
    string lastName;
    optional<string> city;
    optional<string> state;
};

int main() {
    vector<Person> persons = {
        {1, "Wang", "Allen"},
        {2, "Alice", "Bob"}
    };

    vector<Address> addresses = {
        {1, 2, "New York City", "New York"},
        {2, 3, "Leetcode", "California"}
    };

    vector<Result> results;

    for (const auto& person : persons) {
        bool found = false;
        for (const auto& address : addresses) {
            if (person.personId == address.personId) {
                results.push_back({
                    person.firstName,
                    person.lastName,
                    address.city,
                    address.state
                });
                found = true;
                break;
            }
        }
        if (!found) {
            results.push_back({
                person.firstName,
                person.lastName,
                nullopt,
                nullopt
            });
        }
    }

    for (const auto& res : results) {
        cout << res.firstName << " "
             << res.lastName << " "
             << (res.city.has_value() ? res.city.value() : "Null") << " "
             << (res.state.has_value() ? res.state.value() : "Null") << endl;
    }

    return 0;
}
