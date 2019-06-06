#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int arr[250002], pointer=1, posters=0, n, temp;
    arr[0]=0;

    ifstream infile;
    ofstream outfile;
    infile.open("pla10b.in", ios::in);
    outfile.open("pla10b.out", ios::out);
    infile>>n;
    for(int i=0; i<n; ++i) {
        infile>>temp;
        infile>>temp;
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
    outfile<<posters;
    infile.close();
    outfile.close();

    return 0;
}
