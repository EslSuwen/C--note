#include <iostream>
using namespace std;
//const int size = 100;
template <class T>
class stack
{
  private:
    T stck[100];
    int tos;

  public:
    stack()
    {
        tos = 0;
    }
    void push(T ch)
    {
        if (tos == 100)
        {
            cout << "Stack is full!" << endl;
            return;
        }
        stck[tos] = ch;
        tos++;
    }
    void push(int n)
    {
        T ch;
        for (int i = tos; i < tos + n; i++)
        {
            if (tos == 100)
            {
                cout << "Stack is full!" << endl;
                return;
            }
            cin >> ch;
            stck[tos] = ch;
            tos++;
        }
    }
    T pop()
    {
        if (tos == 0)
        {
            cout << "Stack is empty!" << endl;
            return 0;
        }
        tos--;
        return stck[tos];
    }
    void pop(int n)
    {
        for (int i = tos; i > tos - n; i--)
        {
            if (tos == 0)
            {
                cout << "Stack is empty!" << endl;
                return;
            }
            tos--;
            cout << stck[tos] << endl;
        }
    }
    int ifMatch()
    {
        T ch;
        while ((ch = cin.get()) != '\n')
        {
            if (ch == '(')
            {
                stck[tos] = ch;
                tos++;
            }
            else if (ch == ')')
            {
                tos--;
            }
            else
            {
                continue;
            }
            if (tos < 0)
                return 0;
        }

        if (tos == 0)
            return 1;
        return 0;
    }
};
int main()
{
    stack<char> s;
    cout << s.ifMatch() << endl;
    return 0;
}
