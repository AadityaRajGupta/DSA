#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
    vector<char> forw;
    vector<char> back;
    int f = 0, b = 0;
    char str[20];
    gets(str);
    int i = 0;
    while (str[i] != '\0')
    {
        if ((toupper(str[i + 1]) - 65) - (toupper(str[i]) - 65) == 1 ||(toupper(str[i]) - 65) - (toupper(str[i-1]) - 65) == 1 )
        {
           // cout<<toupper('a')-65;
           //cout<<str[i]-65<<endl;
            f++;
            forw.push_back(str[i]);
        }
        else if((toupper(str[i + 1]) - 65) - (toupper(str[i]) - 65) == -1 ||(toupper(str[i]) - 65) - (toupper(str[i-1]) - 65) == -1 )
        {
            b++;
            back.push_back(str[i]);
        }
        i++;
    }
    if (f >= b)
    {
        cout << f << " ";
        for (int i=0;i<forw.size();i++)
        {
            cout << forw[i];
        }
        cout << endl;
    }
    else
    {
        cout << b << " ";
        for (int i=0;i<back.size();i++)
        {
            cout << back[i];
        }
        cout << endl;
    }
    return 0;
}
