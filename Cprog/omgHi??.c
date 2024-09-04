#include <stdio.h>

int main() {
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6};
    int arr3[] = {7, 8, 9};

    int *arr[3];

    arr[0] = arr1;
    arr[1] = arr2;
    arr[2] = arr3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
        }
    }

    return 0;
}
