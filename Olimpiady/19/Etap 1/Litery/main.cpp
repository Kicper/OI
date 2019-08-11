#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define MAX 1000005

int n;
vector<int> arr_first[150], arr_second[150];

char first[MAX], second[MAX];
int p[MAX], pom[MAX];

long long inversion(int x, int y){
    if (x==y) {
        return 0ll;
    }
    int i1=0, i2=0;
    long long wynik=0;
    int z = (x+y)/2;
    int *ciag = p;
    int *ciag1 = pom+x;
    int *ciag2 = pom+z+1;
    for (int i=x; i<=y; ++i) {
        if (ciag[i]<=z){
            wynik+=i2;
            ciag1[i1++]=ciag[i];
        }
        else {
            ciag2[i2++]=ciag[i];
        }
    }
    for (int i=x; i<=y; ++i) {
        p[i]=pom[i];
    }
    return wynik + inversion(x, z) + inversion(z+1, y);
}

int main(){
    cin>>n;
    cin>>first;
    for (int i=n-1; i>=0; --i) {
        arr_first[int(first[i])].push_back(i);
    }

    cin>>second;
    for (int i=n-1; i>=0; --i) {
        arr_second[int(second[i])].push_back(i);
    }

    for (int ch='A'; ch<='Z'; ++ch) {
        for (int i=0; i<(int)arr_first[ch].size(); ++i) {
            p[arr_first[ch][i]] = arr_second[ch][i];
        }
    }

    cout<<inversion(0, n-1);

    return 0;
}
