#include<stdio.h>
int main(){
int number ;
printf("Enter a number :");
scanf("%d",&number);
if(number<0){
    printf("Invalid \n");

}else{
printf("%d!=%d\n",number, factorial(number));
}

}
int factorial(int n){
if(n==0){
    return 1;
}else{
return n* factorial (n-1);
}
}
