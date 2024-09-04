#include <stdio.h>
int prod(int x,int y){
    if (y!=0){
        return (x+prod(x,y-1));
    }
    else{
        return 0;
    }
}
int fib(int num)
{
    if (num <= 1)
        return num;
    return fib(num - 1) + fib(num - 2);
}
int fact(int num){
    if (num==0){
        return 1;
    }
    else{
        return num*fact(num-1);
    }
}
int main(){
    int fac=fact(5);
    int fibbo=fib(9);
    int pro=prod(10,5);
    printf("Prod:%d\n",pro);
    printf("Fibbo:%d\n",fibbo);
    printf("Fact:%d\n",fac);
    return 0;
}