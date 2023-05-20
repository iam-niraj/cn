#include <iostream>
#include <cstring>
using namespace std;

char data[30];
char crc[30];
char divisor[10];
int n, m;

void XOR(){
    for(int j = 0; j < m; j++){     //START FROM 1 BECAUSE the first bit anyways ignored.
        if(crc[j] == divisor[j])
            crc[j]='0';
        else
            crc[j]='1';
    }
}

void check(){
    int i,j;
    for(i = 0; i < m; i++)
        crc[i] = data[i];

    do{

        if(crc[0]=='1')
            XOR();
        
        // SHIFTING=>
        for(j = 0; j < m-1; j++)
            crc[j] = crc[j+1];
        crc[j] = data[i];       //Getting the next bit from the data.
        i++;

    }while(i<=n+m-1);
}

void sender(){
    cout<<"enter the data:\t";
    cin>>data;
    cout<<"Enter generating polynomial/divisor/key:\t";
    cin>>divisor;

    n = strlen(data);
    m = strlen(divisor);

    // APPEND m-1 0s =>
    for(int i = n; i < m-1; i++)
        data[i] = '0';

    check();

    cout<<"THE CRC VALUE IS:\t"<<crc;
    for(int i = n; i < n+m-1; i++)
        data[i] = crc[i-n];
    cout<<"\nTHE FINAL DATA SENT IS:\t"<<data;
}

void receiver(){
    bool error = false;
    cout<<"enter the data:\t";
    cin>>data;
    cout<<"Enter generating polynomial/divisor/key:\t";
    cin>>divisor;

    n = strlen(data);
    m = strlen(divisor);

    check();

    for(int i = 0; i < m; i++){
        if(crc[i]=='1')
            error=true;
    }    

    if(error)
        cout<<"THERE IS AN ERROR";
    else{
        cout<<"NO ERRORS";
        cout<<"\nTHE DATA IS:\t";
        for(int i = 0; i < n; i++)
            cout<<data[i];
    }
}

int main(){

    sender();
    cout<<"\n---------------------------------\n";
    receiver();

    return 0;
}
