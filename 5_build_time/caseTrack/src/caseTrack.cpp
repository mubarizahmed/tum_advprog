/*
** Yes, yes we know this is long but, you have
** seen most of this code before in worksheet 2.
** There are also some auxiliary functions here,
** which we could have put into a separate file.
** We'll see how to do this next week. ;)
** In the meantime, you can skip to the next long
** banner / comment.
*/

#include <algorithm>
#include <array>
#include <cassert>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <memory>
#include <random>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

#include "helper.hpp"

int main() {

    // populate vector from worksheet 2
    std::vector<unsigned int> global_cases(num_countries, 0);
    populate_vector(global_cases);

    std::cout << "**********Choose**********\n"
              << "Press (d) for dummy data\n"
              << "Press (r) for real data" << std::endl;
    char choice;
    std::cin >> choice;

    std::unique_ptr<DataFrame> data_frame;
    if (choice == 'd') {
        // create DataFrame members for dummy data
        std::vector<std::vector<unsigned>> dummy_cases;
        std::vector<unsigned> dummy_population;

        for (size_t country_num = 0; country_num < countries.size(); ++country_num) {
            // reuse global_cases -
            dummy_cases.push_back(std::vector<unsigned>{global_cases[country_num]});
            dummy_population.push_back(1);
        }

        // Make a unique_ptr and assign it to the
        // data_frame declared above.
        // Make sure that cases = dummy_cases
        // and population = dummy_population
        // and regions = countries.
        // Hint: You need to dereference the pointer first.

        // only works in c++20 because struct does not have explicit constructor
        data_frame = std::make_unique<DataFrame>(countries, dummy_population, dummy_cases);
        // DataFrame dummy_df{countries, dummy_population, dummy_cases};

        // data_frame = std::make_unique(dummy_df);

        // Since this is not yet implemented, throw an exception.
        // This would make more sense in another function, which we
        // could then wrap in a try{}catch(){} block.
        // throw std::runtime_error("Tracking is not yet implemented for dummy data.\n");
    } else if (choice == 'r') {
        // get a unique_ptr from read_from_csv()
        // and assign it to the data_frame variable.
        // This unique pointer provides you real data.
        data_frame = read_from_csv();

    } else {
        std::cout << "It's fine if you cannot make up your mind. Maybe another time then...\n";
        std::exit(EXIT_FAILURE);
    }

    // Use a for loop to print "cases" for each country using the
    // data_frame pointer you just initialized. Hint: You can use the existing
    // operator<< overload (implemented above) for printing vectors.

    std::cout << "Cases by country" << std::endl;

    for (auto i = 0; i < num_countries; ++i) {
        std::cout << std::left << std::setw(15) << data_frame->regions[i].substr(0, 15) << " | ";
        std::cout << data_frame->cases[i] << "\n";
    }
    // std::cout << static_cast<int>(data_frame->cases) << std::endl;

    // TODO: After implementing normalize_per_capita()
    // 1. Call normalize_per_capita
    // 2. Print out the new normalized case numbers.
    // Hint: You can use the example in the worksheet to
    // iterate over the map.

    std::map<std::string, std::vector<double>> normalized_cases = normalize_per_capita(data_frame);

    std::cout << "Normalized Cases by country" << std::endl;

    for (const auto& [region, cases] : normalized_cases) {
        std::cout << std::left << std::setw(15) << region.substr(0, 15) << " | ";
        std::cout << cases << "\n";
    }
}
