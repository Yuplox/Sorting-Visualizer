#include <iostream>
#include "sorter.hpp"
#include "rand_vector.hpp"

int main() {
    std::vector<int>* nums1 = RandVector::random(100, 100);
    std::vector<int>* nums2 = RandVector::nonIncreasing(100, 100);
    std::vector<int>* nums3 = RandVector::equal(100, 100);

    Sorter::quickSort(*nums1);

    for (auto n : *nums1) {
        std::cout << n << " "; 
    }
    std::cout << std::endl;

    for (auto n : *nums2) {
        std::cout << n << " "; 
    }
    std::cout << std::endl;

}