#include <stdio.h>
#include <stdlib.h>

#include "uthash.h"

typedef struct map_entry {
    int key;
    int val;
    UT_hash_handle hh;
} map_entry_t;

int *twoSum(int *nums, int nums_size, int target, int *return_size)
{
    int *retval = NULL;
    *return_size = 0;
    map_entry_t *complement_map = NULL;
    map_entry_t *entry_pool = malloc(nums_size * sizeof(*entry_pool));
    for (int i = 0; i < nums_size; i++) {
        int complement = target - nums[i];
        map_entry_t *complement_entry = NULL;
        HASH_FIND_INT(complement_map, &complement, complement_entry);
        if (complement_entry != NULL) {
            retval = malloc(2 * sizeof(*retval));
            *return_size = 2;
            retval[0] = complement_entry->val;
            retval[1] = i;
            break;
        }
        map_entry_t *entry = &entry_pool[i];
        entry->key = nums[i];
        entry->val = i;
        HASH_ADD_INT(complement_map, key, entry);
    }
    HASH_CLEAR(hh, complement_map);
    free(entry_pool);
    return retval;
}

int main(void)
{
    int nums[] = {2, 7, 11, 15};
    int nums_size = sizeof(nums) / sizeof(nums[0]);
    int target = 9;
    int return_size = 0;

    int *result = twoSum(nums, nums_size, target, &return_size);
    if (!result || return_size == 0) {
        printf("Failed to find answer\n");
        exit(1);
    }
    printf("Found answer: [%d, %d]", result[0], result[1]);
}
