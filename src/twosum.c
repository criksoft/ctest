#include <stdio.h>

struct result {
    int index1;
    int index2;
};

struct result function(int *nums, int n, int target)
{
    int i = 0;
    int j = 1;
    struct result result;
    while (i < n - 1) {
        int sum = nums[i] + nums[j];
        if (sum == target) {
            result.index1 = i;
            result.index2 = j;
            break;
        }
        j = j + 1;
        if (j == n) {
            i = i + 1;
            j = i + 1;
        }
    }
    return (struct result){-1, -1};
}

struct result function2(int nums[], int n, int target)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                return (struct result){i, j};
            }
        }
    }
    return (struct result){-1, -1};
}

int main(void)
{
    int nums[5] = {434, 235, 666, 176, 98};
    int target = 764;
    struct result result = function(nums, 5, target);
    printf("%d,%d\n", result.index1, result.index2);
}
