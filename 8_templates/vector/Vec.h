#ifndef __VEC_DOUBLE_H_
#define ___VEC_DOUBLE_H_
#include <algorithm>
#include <cstddef>

template <typename T>
class Vec {
  private:
    std::size_t _capacity{};
    std::size_t _size{};
    T *_arr = nullptr;

  public:
    Vec<T>() = default;

    Vec(std::size_t capacity, T initial_val)
        : _capacity(capacity), _size(capacity), _arr(new T[capacity]) {
        // set initial value
        std::fill(_arr, _arr + _size, initial_val);
    }

    std::size_t capacity() const {
        return _capacity;
    }

    std::size_t size() const {
        return _size;
    }

    void push(const T &value) {
        // TODO 2: if _size < _capacity, add value directly.
        // Otherwise: size == capacity means there's no space for
        // new elements and we need to allocate
        // a new array, copy over elements from the old one
        //  and then add the new value.
        std::size_t new_capacity = _capacity != 0 ? _capacity * 2 : 1;

        if (_size < _capacity) {
            _arr[_size++] = value;
        } else {
            T *tmp = new T[new_capacity];
            std::copy(begin(), end(), tmp);
            std::swap(_arr, tmp);

            delete[] tmp;

            _arr[_size++] = value;
            _capacity = new_capacity;
        }
    }

    // TODO 3: Define operator [] for Vec that returns double& at "index"
    T &operator[](std::size_t index) {
        return _arr[index];
    }

    // TODO 4: Allow ranged based for loops by defining
    // begin and end methods.
    // begin: returns a pointer to the first element
    // end:   return a pointer to one past the last element
    T *begin() {
        // Implementation here
        return _arr;
    }
    T *end() {
        // Implementation here
        return _arr + _size;
    }
};

#endif
