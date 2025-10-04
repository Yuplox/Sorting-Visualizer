#ifndef RAND_VECTOR_HPP
#define RAND_VECTOR_HPP

#include <cstdlib>
#include <vector>

class RandVector {
public:
    /**
     * Creates a vector of random integers
     *
     * Numbers are randomly generated using the <random> library
     *
     * @param n Size of the created array
     * @param max Maximum integer randomly generated
     * @returns Pointer to a vector on the heap
     */
    static std::vector<int>* random(size_t n, int max);

    /**
     * Creates a vector of nondecreasing random integers
     *
     * Numbers are randomly generated using the <random> library
     * and then the vector is sorted in nondecreasing order using std::sort
     *
     * @param n Size of the created array
     * @param max Maximum integer randomly generated
     * @returns Pointer to a vector on the heap
     */
    static std::vector<int>* nondecreasing(size_t n, int max);

    /**
     * Creates a vector of nonincreasing random integers
     *
     * Numbers are randomly generated using the <random> library
     * and then the vector is sorted in nonincreasing order using std::sort
     *
     * @param n Size of the created array
     * @param max Maximum integer randomly generated
     * @returns Pointer to a vector on the heap
     */
    static std::vector<int>* nonincreasing(size_t n, int max);

    /**
     * Creates a vector of equal random integers
     *
     * A single random number is generated using the <random> library
     * and then the vector is filled with that number
     *
     * @param n Size of the created array
     * @param max Maximum integer randomly generated
     * @returns Pointer to a vector on the heap
     */
    static std::vector<int>* equal(size_t n, int max);
};

#endif