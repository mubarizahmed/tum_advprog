#include <algorithm>
#include <iostream>
#include <vector>

// TODO 1: Implement the Sortable concept.
template <typename T>
concept Sortable = requires(T x) { x < x; };

// TODO 4: Provide an additional constraint such that animal_sort
// only works for Sortable and Cute animals. You will need to define
// the concept Cute.
template <typename T>
concept Cute = requires(T x) { x.cuteness(); };

template <typename T>
    requires Sortable<T> && Cute<T>
void animal_sort(std::vector<T> &arr) {
    std::sort(arr.begin(), arr.end());
    std::cout << "{ ";
    for (const auto &elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << "}\n";
}

class Penguin {
  private:
    int _height{};
    int _weight{};
    int _cuteness{};

  public:
    Penguin() = default;
    Penguin(int height, int weight, int cuteness)
        : _height(height), _weight(weight), _cuteness(cuteness) {}

    int cuteness() const {
        return _cuteness;
    }

    friend std::ostream &operator<<(std::ostream &os, const Penguin &penguin) {
        std::cout << "{ " << penguin._cuteness << " }";
        return os;
    }

    // TODO 3: Make Penguin Sortable. You will need to define a criterion for ordering Penguins.
    bool operator<(const Penguin &penguin) const {
        return _cuteness < penguin._cuteness;
    }
};

int main() {
    std::vector<Penguin> penguins;
    penguins.push_back(Penguin(10, 10, 5));
    penguins.push_back(Penguin(7, 13, 1));
    penguins.push_back(Penguin(9, 15, 3));

    // TODO 2: Call animal_sort on the penguins vector.
    animal_sort(penguins);
}