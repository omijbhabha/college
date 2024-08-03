#include <stdio.h>
//FACT,MULTI,FIBB
int fac(int num){
    if (num==1){
        return 1;
    }
    else{
        return num*fac(num-1);
    }
}
int fib(int num){
    if (num<=1){
        return num;
    }
    return (fib(num-1)+fib(num-2));
}
int mul(int x,int y){
    if (y!=0){
        return x+mul(x,y-1);
    }
    return 0;
}
int binSearch(int arr[],int target,int low,int high){
    if (low>high){
        return -1;
    }
    else{
        int mid=(low+high)/2;
        if (target<arr[mid]){
            return binSearch(arr,target,low,mid-1);
        }
        else if(target>arr[mid]){
            return binSearch(arr,target,mid+1,high);
        }
        else{
            return mid;
        }
    }
}
int main(){
    int multi=mul(10,5);
    int fact=fac(5);
    int fibb=fib(9);
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int checkNum=binSearch(arr,5,0,10);
    checkNum==-1?printf("ELEMENT NOT FOUND\n"):printf("ELEMENT FOUND AT INDEX: %d\n",checkNum);
    printf("FACTORIAL:%d\n",fact);
    printf("FIBBONACCI:%d\n",fibb);
    printf("MULTIPLICATION:%d\n",multi);
    return 0;
}