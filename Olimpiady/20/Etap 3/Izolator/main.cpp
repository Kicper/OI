#include <iostream>
#include <stdlib.h>

using namespace std;

int compare (const void *a, const void *b) {
    return ( *(int*)a - *(int*)b );
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; ++i)
        cin >> arr[i];

    qsort(arr, n, sizeof(int), compare);

    int middle = (n+1)/2;

    long long sum;

    if(n%2==0) {
        sum = 0;
        for(int i=0; i<middle; ++i)
            sum = sum + arr[i] + arr[middle + i] + (arr[middle + i] - arr[i]);
    } else {
        sum = arr[middle - 1];
        for(int i=0; i<(middle-1); ++i)
            sum = sum + arr[i] + arr[middle + i] + (arr[middle + i] - arr[i]);
    }

    cout << sum;

    return 0;
}
