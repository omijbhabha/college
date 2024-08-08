#include <stdio.h>
#include <stdlib.h>
int main(){
    int *array;
    int size;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    array=(int *)malloc(size * sizeof(int));
    if (array==NULL){
        printf("Memory failed\n");
        return 1;
    }
    printf("Enter the elements: ");
    for (int i=0;i<size;i++){
        scanf("%d",&array[i]);
    }
    printf("Elements are: \n");
    for (int i=0;i<size;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    free(array);
    return 0;
}