#include "CycleSort.h"

CycleSort::CycleSort(int arraySize) : SorterBase(arraySize)
{
}

void CycleSort::Sort(bool recordSorting)
{
    int size = array.size();

    for (int start = 0; start < size - 1; start++) {
        int item = array[start];
        int pos = start;

        // Find the correct position for the current item
        for (int i = start + 1; i < size; i++) {
            if (array[i] < item) {
                pos++;
            }
        }

        // Skip if the item is already in the correct position
        if (pos == start) {
            continue;
        }

        // Move all the elements to the right of the current position
        while (item == array[pos]) {
            pos++;
        }

        // Swap the current item with the element at the new position
        std::swap(item, array[pos]);

        if (recordSorting) SaveFrame();

        // Move the rest of the elements to their correct positions
        while (pos != start) {
            pos = start;

            // Find the correct position for the current item
            for (int i = start + 1; i < size; i++) {
                if (array[i] < item) {
                    pos++;
                }
            }

            // Skip if the item is already in the correct position
            while (item == array[pos]) {
                pos++;
            }

            // Swap the current item with the element at the new position
            std::swap(item, array[pos]);

            if (recordSorting) SaveFrame();
        }
    }
}
