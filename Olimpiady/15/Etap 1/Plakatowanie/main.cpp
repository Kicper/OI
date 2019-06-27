#include <iostream>

using namespace std;

int main()
{
    int arr[250002], pointer=1, posters=0, n, temp;
    arr[0]=0;

    cin>>n;
    for(int i=0; i<n; ++i) {
        cin>>temp;
        cin>>temp;
        if(arr[pointer-1] < temp) {
            posters++;
            arr[pointer]=temp;
            pointer++;
        }
        else {
            while(arr[pointer-1]>temp) {
                arr[pointer-1]=0;
                pointer--;
            }
            if(arr[pointer-1]<temp) {
                arr[pointer]=temp;
                pointer++;
                posters++;
            }
        }
    }
    cout<<posters;

    return 0;
}
