#include <stdio.h>

int main(void)
{
    long x;
    printf("X'i giriniz =>"); 
    scanf("%li", &x);
    long y;
    printf("Y'yi giriniz =>");
    scanf("%li", &y);

    double z = (double)x / (double)y ;          
    printf("%li\n", x+y );
    printf("%.20f\n", z );
}
