#include "../utils.h"

statistics_t insertion_sort(int *arr, int n)
{
    printf("Sorting array with insertion sort...\n\n");
    statistics_t ret = {0};

    uint64_t start_t = microsSinceEpoch();
    for(int i = 1; i < n; i++)
    {
        for(int j = i; j > 0; j--)
        {
        	ret.comparisons++;
        	ret.array_accesses = ret.array_accesses + 2;
            if (*(arr + j) < * (arr + j - 1))
            {
                // Swap them!
                int tmp = *(arr + j);
                *(arr + j) = *(arr + j - 1);
                *(arr + j - 1) = tmp;

                ret.array_accesses = ret.array_accesses + 4;
            }
        }
    }


    ret.time = microsSinceEpoch() - start_t;
    return ret;
}