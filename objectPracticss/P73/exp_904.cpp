#include <iostream>
using namespace std;
template <class T>
void arrayIn(T array[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> array[i];
}
template <class T>
void arrayOut(T array[], int n)
{
    for (int i = 0; i < n; i++)
        cout << array[i] << endl;
}
template <class T>
T arrayAvg(T array[], int n)
{
    T avg = 0;
    for (int i = 0; i < n; i++)
        avg += array[i];
    return avg / n;
}
template <class T>
T arrayMax(T array[], int n)
{
    T max = 0;
    for (int i = 0; i < n; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}
int main()
{
    int a1[5];
    arrayIn(a1, 5);
    arrayOut(a1, 5);
    cout<<arrayAvg(a1, 5)<<endl;
    cout<<arrayMax(a1, 5)<<endl;
    return 0;
}