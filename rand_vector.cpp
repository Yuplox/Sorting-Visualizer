#include <algorithm>
#include <functional>
#include <random>
#include "rand_vector.hpp"

std::vector<int>* RandVector::random(size_t n, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, max);
    std::vector<int> *nums = new std::vector(n, 0);

    for (size_t i = 0; i < nums->size(); ++i) {
        nums->at(i) = dist(gen);
    }

    return nums;
}

std::vector<int>* RandVector::nondecreasing(size_t n, int max) {
    std::vector<int>* nums = RandVector::random(n, max);
    std::sort(nums->begin(), nums->end());
    return nums;

}

std::vector<int>* RandVector::nonincreasing(size_t n, int max) {
    std::vector<int>* nums = RandVector::random(n, max);
    std::sort(nums->begin(), nums->end(), std::greater<>());
    return nums;
}

std::vector<int>* RandVector::equal(size_t n, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, max);
    return new std::vector<int>(n, dist(gen));
}