
#include<iostream>
#include<cstring>
using namespace std;
char *star;
char *p = new char[50];
char *strAdd(char *s1, char *s2)
{
    star = p;
    int count = 0;
    while(*(s1+count)!='\0')
        *p++ = *(s1 + count++);
    count = 0;
    while(*(s2+count)!='\0')
        *p++ = *(s2 + count++);
    return star;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        char ch1[50], ch2[50];
        cin >> ch1 >> ch2;
        cout << ch1 << " " << ch2 << " ";
        char *add = strAdd(ch1, ch2);
        while(*add!='\0')
        {
            cout << *add;
            add++;
        }
        cout << endl;
    }
    return 0;
}