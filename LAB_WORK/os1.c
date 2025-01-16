#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{   
    //1
    // int n1, n2, sum;
    // printf("Enter two numbers: ");
    // scanf("%d %d", &n1, &n2);
    // sum = n1 + n2;
    // printf("Sum of %d and %d is %d\n", n1, n2, sum);

    //2
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if(n%2 == 0)
        printf("%d is even\n", n);
    else
        printf("%d is odd\n", n);
    return 0;
}