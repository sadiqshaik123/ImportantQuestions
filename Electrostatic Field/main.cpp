#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char arr[100];
    char ch[100];
    int len;
    cin.getline(arr, 100);
    cin.getline(ch, 100);

    cin>>len;
    int charge[100];

    int ct = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] != ' ')
        {
            charge[ct] = arr[i] - '0';
            ct++;
        }
    }

    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        if (ch[i] == 'P')
        {
            sum = sum + charge[i];
        }
        else
        {
            sum = sum - charge[i];
        }
    }
    if(sum>0){
        cout<<sum*100<<endl;
    }else{
        cout<<-sum*100<<endl;
    }

    return 0;
}
