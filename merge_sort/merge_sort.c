#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}



void merge(int *a, int l, int r, int n)
{
    int *b = (int *)malloc(n * sizeof(int));
    if (b == NULL)
    {
        printf("Can't Malloc! Please try again.");
        exit(EXIT_FAILURE);
    }
    int c = 1;
    int p1, p2;
    p1 = 1;
    p2 = ((l + r) / 2) + 1;
    while ((p1 < ((l + r) / 2) + 1) && (p2 < r + 1))
    {
        if (a[p1] <= a[p2])
        {
            b[c++] = a[p1];
            p1++;
        }
        else
        {
            b[c++] = a[p2];
            p2++;
        }
    }

    if (p2 == r + 1)
    {
        while ((p1 < ((l + r) / 2) + 1))
        {
            b[c++] = a[p1];
            p1++;
        }
    }
    else
    {
        while ((p2 < r + 1))
        {
            b[c++] = a[p2];
            p2++;
        }
    }

    for (c = 1; c < r; c++) a[c] =  b[c];

    free(b);
}



void merge_sort(int *a, int n, int l, int r)
{
    if (r - l == 1)
    {
        if(a[l] > a[r])
         swap(&a[l], &a[r]);
    }
    else if (l != r)
    {
        merge_sort(a, n, l, (l + r) / 2);
        merge_sort(a, n, ((l + r) / 2) + 1, r);
        merge(a, l, r, n);
    }
}



int main(void)
{
    int *a, n, i;
    printf("Enter Array size: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Array size must be Greater than 0!\n");
        return 1;
    }
    a = (int *)malloc(n * sizeof(int));
    if (a == NULL)
    {
        printf("Can't Malloc! Please try again.");
        return 1;
    }
    for (i = 0; i < n; i++)
    {
        printf("Enter number[%d]: ", i);
        scanf("%d", &a[i]);
    }
    
    merge_sort(a, n, 0, n - 1);
    printf("Sorted Array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    free(a);

    return 0;
}