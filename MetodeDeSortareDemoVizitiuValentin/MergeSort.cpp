#include "MergeSort.h"

MergeSort::MergeSort(int arraySize) : SorterBase(arraySize)
{
}

void MergeSort::Sort(bool recordSorting)
{
    this->recordSorting = recordSorting;
    MergeSortStart(array, 0, array.size() - 1);
}

void MergeSort::Merge(std::vector<int>&arr, int left, int mid, int right) {
    int size1 = mid - left + 1;
    int size2 = right - mid;

    // Create temporary sub-vectors
    std::vector<int> leftArr(size1);
    std::vector<int> rightArr(size2);

    // Copy data to temporary sub-vectors
    for (int i = 0; i < size1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < size2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    // Merge the temporary sub-vectors back into the original vector
    int i = 0;     // Initial index of first sub-vector
    int j = 0;     // Initial index of second sub-vector
    int k = left;  // Initial index of merged sub-vector

    while (i < size1 && j < size2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of the left sub-vector
    while (i < size1) {
        arr[k] = leftArr[i];
        i++;
        k++;
        if (recordSorting) SaveFrame();
    }

    // Copy the remaining elements of the right sub-vector
    while (j < size2) {
        arr[k] = rightArr[j];
        j++;
        k++;
        if (recordSorting) SaveFrame();
    }
}

void MergeSort::MergeSortStart(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively divide the vector into two halves
        MergeSortStart(arr, left, mid);
        MergeSortStart(arr, mid + 1, right);

        // Merge the two sorted halves
        Merge(arr, left, mid, right);
    }
}