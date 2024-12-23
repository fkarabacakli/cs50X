
#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    } 
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));
}

int max(int array[], int n)
{
    int change;
    int max = array[0];
    for(int i=1; i<n; i++)
    {
        if(max<array[i])
        {
            change=array[i];
            array[i]=max;
            max=change;
        }
    }
    return max;
}
