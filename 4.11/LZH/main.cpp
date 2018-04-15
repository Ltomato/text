#include "task.h"
int main()
{
    char nbl[100]={0};
    char ch[100]={0};
    cin.get(ch,100);
    Transfer(ch,nbl);
    int i=0;
    cout<<"\n½á¹ûÎª£º"<<endl;
    cout<<calcval(nbl)<<endl;   
    return 0;
}