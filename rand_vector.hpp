#ifndef RAND_VECTOR_HPP
#define RAND_VECTOR_HPP

#include <cstdlib>
#include <vector>

class RandVector {
public:
    static std::vector<int>* random(size_t n, int max);
    static std::vector<int>* nonDecreasing(size_t n, int max);
    static std::vector<int>* nonIncreasing(size_t n, int max);
    static std::vector<int>* equal(size_t n, int max);
};

#endif