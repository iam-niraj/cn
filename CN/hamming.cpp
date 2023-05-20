#include <iostream>
#include <math.h>
using namespace std;

void sender(){
    int data[4];
    int final[7];
    int m,r;
    int i,j;
    int x;
    
    cout<<"enter the number of data bits:\t";
    cin>>m;
    for(i = 0;;i++){
        x = pow(2,i);
        if(x>=m+i+1){
            r=i;
            break;
        }
    }
    cout<<"TOTAL PARITY BITS:\t"<<r;

    if(r!=3){
        return;
    }
    cout<<"\nEnter the data bits:\t";
    for(i=0;i<m;i++)
        cin>>data[i];
    
    j=0;
    for(i=0;i<7;i++){
        switch(i){
            case 0:
                    final[i] = data[0] ^ data[1] ^ data[3];
                    break;
            case 1:
                    final[i] = data[0] ^ data[2] ^ data[3];
                    break;
            case 3:
                    final[i] = data[1] ^ data[2] ^ data[3];
                    break;
            default:
                    final[i] = data[j];
                    j++;
        }
    }
    cout<<"THE DATA SENT IS:\t";
    for(i=0;i<7;i++)
        cout<<final[i]<<" ";
}

void receiver(){
    int final[7];
    int data[4];
    bool flag[7]={false};
    int i,j;
    int m = 4;
    int n = 7;
    
    cout<<"enter the data bits received:\t";
    for(i=0;i<n;i++){
        cin>>final[i];
    }
    j=0;
    for(i=2;i<n;i++){
        if(i!=3){
            data[j]=final[i];
            j++;}
    }

    for(i=0;i<7;i++){
        switch(i){
            case 0:
                    if(final[i] != data[0] ^ data[1] ^ data[3]){
                        flag[i] = true;
                    }
                    break;
            case 1:
                    if(final[i] != data[0] ^ data[2] ^ data[3]){
                        flag[i] = true;
                    }                    
                    break;
            case 3:
                    if(final[i] != data[1] ^ data[2] ^ data[3]){
                        flag[i] = true;
                    }
                    break;
            default:
                    continue;
        }
    }

    if((flag[0] && flag[1]) && flag[3]){
        cout<<"\nERROR AT BIT 7";
    }else if(flag[0] && flag[1]){
        cout<<"\nERROR AT BIT 3";
    }else if(flag[0] && flag[3]){
        cout<<"\nERROR AT BIT 5";
    }else if(flag[1] && flag[3]){
        cout<<"\nERROR AT BIT 6";
    }else{
        cout<<"\nTHE DATA IS:\t";
        for(i=0;i<m;i++)
            cout<<data[i]<<" ";
    }
}

int main(){

    sender();
    cout<<"\n---------------------------\n";
    receiver();

    return 0;
}
