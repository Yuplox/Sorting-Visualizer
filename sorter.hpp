#ifndef SORTER_HPP
#define SORTER_HPP

#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <vector>

class Sorter {
public:
    template <typename T>
    static std::vector<T>& selectionSort(std::vector<T>& nums) {
        size_t length = nums.size();
        for (size_t i = 0; i < length; ++i) {
            size_t minInd = i;
            for (size_t j = i; j < length; ++j) {
                if (nums[j] < nums[minInd])
                    minInd = j;
            }
            T temp = nums[i];
            nums[i] = nums[minInd];
            nums[minInd] = temp;
        }
        return nums;
    }

    template <typename T>
    static std::vector<T>& bubbleSort(std::vector<T>& nums) {
        size_t length = nums.size();
        for (size_t i = length - 1; i > 0; --i) {
            for (size_t j = 1; j <= i; ++j) {
                if (nums[j - 1] > nums[j]) {
                    T temp = nums[j - 1];
                    nums[j - 1] = nums[j];
                    nums[j] = temp;
                }
            }
        }
        return nums;
    }

    template <typename T>
    static std::vector<T>& insertionSort(std::vector<T>& nums) {
        size_t length = nums.size();
        for (size_t i = 1; i < length; ++i) {
            T key = nums[i];

            // Inserts elements from index 1 to i - 1
            size_t j = i - 1;
            while(j > 0 && key < nums[j]) {
                nums[j + 1] = nums[j];
                --j;
            }

            // Because j is type size_t and can underflow
            // Index 0 is handled outside the loop
            if (j == 0 && key < nums[0]) {
                nums[1] = nums[0];
                nums[0] = key;
            } else {
                nums[j + 1] = key; 
            }
        }
        return nums;
    }

    template <typename T>
    static std::vector<T>& quickSort(std::vector<T>& nums) {
        return quickSortHelper(nums, 0, nums.size());
    }

    template <typename T>
    static std::vector<T>& mergeSort(std::vector<T>& nums) {
        return mergeSortHelper(nums, 0, nums.size());
    }

    template <typename T>
    static std::vector<T>& heapSort(std::vector<T>& nums);

    template <typename T>
    static std::vector<T>& radixSort(std::vector<T>& nums);

private:
    template <typename T>
    static std::vector<T>& countingSort(std::vector<T>& nums);
    
    template <typename T>
    static std::vector<T>& quickSortHelper(std::vector<T>& nums, size_t begin, size_t end) {
        // Base case of length <= 1
        if (end - begin <= 1)
            return nums;

        
        // Randomly select pivot and sawp with last element
        srand(time(NULL));
        size_t pi =  (rand() % (end - begin - 1)) + begin;
        T temp = nums[pi];
        nums[pi] = nums[end - 1];
        nums[end - 1] = temp;

        // Elements <= pivot are moved 
        // to the left half of the array
        size_t i = begin;
        for (size_t j = begin; j < end - 1; ++j) {
            if (nums[j] <= nums[end - 1]) {
                T temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                ++i;
            }
        }

        // Swap pivot with the first element 
        // in the right half of the array
        temp = nums[i];
        nums[i] = nums[end - 1];
        nums[end - 1] = temp;

        // Call quick sort on both halves of 
        // the array excluding the pivot
        quickSortHelper(nums, begin, i);
        quickSortHelper(nums, i + 1, end);
        return nums;
    }

    template <typename T>
    static std::vector<T>& mergeSortHelper(std::vector<T>& nums, size_t begin, size_t end) {
        if (end - begin <= 1)
            return nums;
        
        size_t mid = begin + (end - begin) / 2;
        mergeSortHelper(nums, begin, mid);
        mergeSortHelper(nums, mid, end);

        std::vector<T> left(nums.begin() + begin, nums.begin() + mid);
        std::vector<T> right(nums.begin() + mid, nums.begin() + end);
        size_t li = 0;
        size_t ri = 0;

        while (li < left.size() && ri < right.size()) {
            if (left[li] <= right[ri]) {
                nums[begin + li + ri] = left[li];
                ++li;
            } else {
                nums[begin + li + ri] = right[ri];
                ++ri;
            }
        }

        while (li < left.size()) {
            nums[begin + li + ri] = left[li];
            ++li;
        }

        while (ri < right.size()) {
            nums[begin + li + ri] = right[ri];
            ++ri;
        }

        return nums;
    }
};

#endif