#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "person.h"

int main(int argc, char* argv[]) {

  // Set a default value to the number of people,
  // read it from the program arguments, if available.
  auto n_people = 5000;
  if (argc > 1) {
    n_people = std::atoi(argv[1]);
  }

  std::vector<Person> people;
  people.reserve(n_people);
  for (auto i = 0; i < n_people; i++) {
    people.push_back(Person({static_cast<double>(rand() % 10), static_cast<double>(rand() % 10)}));
  }

  std::vector<std::vector<double>> distances(n_people, std::vector<double>(n_people, 0));

  std::chrono::time_point<std::chrono::system_clock> start;
  std::chrono::time_point<std::chrono::system_clock> end;
  start = std::chrono::system_clock::now();

  for (auto i = 0; i < people.size(); i++) {
    for (auto j = 0; j < people.size(); j++) {
      if (i != j) {
        distances[j][i] =
            std::sqrt(std::pow(people[i].x() - people[j].x(), 2) + std::pow(people[i].y() - people[j].y(), 2));
      } else {
        distances[j][i] = 0;
      }
    }
  }

  end = std::chrono::system_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "Elapsed time: " << elapsed.count() / 1000.0 << " seconds" << std::endl;

  auto max = 0.0;
  for (auto i = 0; i < people.size(); i++) {
    auto row_max = *std::max_element(distances[i].begin(), distances[i].end());
    if (row_max > max) {
      max = row_max;
    }
  }
  std::cout << "Maximum distance between two people: " << max << std::endl;
}
