#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n, H, h = 0, result = 0;
    char arr[1000000];
    cin >> n >> H;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (arr[i] == '(') {
            h++;
            if (h > H) {
                result++;
                h -= 2;
            }
        }
        else if (arr[i] == ')') {
            h--;
            if (h < 0) {
                result++;
                h += 2;
            }
        }
        else
        {
            return 0;
        }
    }
    cout << result;
    return 0;
}
