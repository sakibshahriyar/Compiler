#include <iostream>
using namespace std;
int main()
{string ch;
    getline(cin,ch);
   int x=ch.size();

        if((ch[0]>='a'&&ch[0]<='z')||ch[0]==' '||ch[0]=='.')
        cout<<"Grammatically not correct "<<endl;
        else if(ch[x-1]!='.')
        cout<<"Grammatically not correct "<<endl;
    else
    {
        int j=0;
        for(int i=0;i<ch.size()-1;i++)
        {
        if((ch[i]>='A'&&ch[i]<='Z')&&(ch[i+1]>='A'&&ch[i+1]<='Z'))
        {
                j=1;
                break;
        }
        if(ch[i]==' '&&ch[i+1]==' ')
        {
                j=1;
                break;
        }
        if((ch[i]>='a'&&ch[i]<='z')&&ch[i+1]>='A'&&ch[i+1]<='Z')
        {
                j=1;
                break;
        }
        if(ch[i]==' ' && ch[i+1]=='.')
        {
               j=1;
               break;
        }
        }
        if(j)
          cout<<"Grammatically not correct "<<endl;
        else
            cout<<"Grammatically correct "<<endl;
    }

}




