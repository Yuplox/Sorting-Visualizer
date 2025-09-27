#include <iostream>
#include "sorter.hpp"
#include "rand_vector.hpp"

int main() {
    std::vector<int>* nums1 = RandVector::random(100, 100);
    std::vector<int> nums2(*nums1);

    Sorter::radixSort(*nums1);
    Sorter::mergeSort(nums2);

    for (int n : *nums1) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    for (int n : nums2) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    delete nums1;
}