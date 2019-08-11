#include <iostream>

using namespace std;

int main()
{
    int numberOfCyliders;
    int numberOfRings;
    cin >> numberOfCyliders;
    cin >> numberOfRings;
    if(numberOfRings > numberOfCyliders) {
        cout << 0;
        return 0;
    }

    long long cylinders[numberOfCyliders + 2];
    long long rings[numberOfRings];
    
    cylinders[0] = 1000000002;
    for(int i=1; i<numberOfCyliders + 1; ++i)
        cin >> cylinders[i];
    cylinders[numberOfCyliders + 1] = 0;

    for(int i=0; i<numberOfCyliders + 1; i++) {
        if(cylinders[i] < cylinders[i+1])
            cylinders[i+1] = cylinders[i];
    }

    int depth = numberOfCyliders + 1;

    for(int i=0; i<numberOfRings; ++i) {
        cin >> rings[i];
        if(depth == 0) {
            break;
        }
        while(rings[i] > cylinders[depth - 1]) {
            depth--;
        }
        depth--;
    }

    cout << depth;
    return 0;
}
