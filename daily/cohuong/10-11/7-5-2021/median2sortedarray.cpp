
// C++ code for finding median of the given two
// sorted arrays that exists in the merged array ((n+m) / 2 - 1 position)
#include<bits/stdc++.h>
using std::cout;

int maximum(int a, int b);

// Function to find median of given two sorted arrays
int findMedianSortedArrays(int *a, int n,
                           int *b, int m)
{

    int min_index = 0, max_index = n, i, j;

    while (min_index <= max_index)
    {
        i = (min_index + max_index) / 2;
        j = ((n + m + 1) / 2) - i;

        // if i = n, it means that Elements from a[] in
        // the second half is an empty set. If j = 0, it
        // means that Elements from b[] in the first half
        // is an empty set. so it is necessary to check that,
        // because we compare elements from these two groups.
        // searching on right
        if (i < n && j > 0 && b[j - 1] > a[i])
            min_index = i + 1;

        // if i = 0, it means that Elements from a[] in the
        // first half is an empty set and if j = m, it means
        // that Elements from b[] in the second half is an
        // empty set. so it is necessary to check that,
        // because we compare elements from these two groups.
        // searching on left
        else if (i > 0 && j < m && b[j] < a[i - 1])
            max_index = i - 1;

        // we have found the desired halves.
        else
        {
            // this condition happens when we don't have
            // any elements in the first half from a[] so
            // we returning the last element in b[] from
            // the first half.
            if (i == 0)
                return b[j - 1];

            // and this condition happens when we don't have any
            // elements in the first half from b[] so we
            // returning the last element in a[] from the first half.
            if (j == 0)
                return a[i - 1];
            else
                return maximum(a[i - 1], b[j - 1]);
        }
    }

    cout << "ERROR!!! " << "returning\n";
    return 0;
}

// Function to find maximum
int maximum(int a, int b)
{
    return a > b ? a : b;
}

// Driver code
int main()
{
    int a[] = {10};
    int b[] = {9};
    int n = sizeof(a) / sizeof(int);
    int m = sizeof(b) / sizeof(int);

    // we need to define the smaller array as the first
    // parameter to make sure that the time complexity
    // will be O(log(min(n,m)))
    if (n < m)
        cout << "The median is: "
             << findMedianSortedArrays(a, n, b, m);
    else
        cout << "The median is: "
             << findMedianSortedArrays(b, m, a, n);
    return 0;
}
