#include <iostream>

using namespace std;

#define MAX 89

int findComponent(long long number, long long arrayOfFib[]) {
    int i = 0;
    long long up;
    long long down;

    while(arrayOfFib[i] < number) {
        i++;
    }
    if(arrayOfFib[i] == number) {
        return 1;
    }
    up = arrayOfFib[i] - number;
    down = number - arrayOfFib[i - 1];
    number = (up > down) ? down : up;
    return findComponent(number, arrayOfFib) + 1;

}

int main()
{
    long long arrayOfFib[MAX];
    long long Fib0 = 0;
    long long Fib1 = 0;
    long long Fib2 = 1;
    arrayOfFib[0] = Fib1;
    arrayOfFib[1] = Fib2;

    for(int i=2; i<MAX; ++i) {
        Fib0 = Fib1;
        Fib1 = Fib2;
        Fib2 = Fib0 + Fib1;
        arrayOfFib[i] = Fib2;
    }

    int numberOfQuestions;
    cin >> numberOfQuestions;
    long long number;
    for(int question=0; question<numberOfQuestions; ++question) {
        cin >> number;
        cout << findComponent(number, arrayOfFib) << "\n";
    }

    return 0;
}
