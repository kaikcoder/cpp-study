#include <iostream>
#include "vector.h"

int main() {
    guokai::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    std::cout << "Vector contents: ";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }

    std::cout << "\nSize: " << v.size() << ", Capacity: " << v.capacity() << std::endl;

    v.pop_back();
    std::cout << "After pop_back(), size: " << v.size() << std::endl;

    v.clear();
    std::cout << "After clear(), size: " << v.size() << std::endl;

    return 0;
}
