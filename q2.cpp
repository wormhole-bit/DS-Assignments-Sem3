//REMOVING DUPLICATE FROM AN ARRAY

#include <iostream>
using namespace std;
int main()
{   			
    int k;
    int pos;
    int size;
    cout<<"size:";
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]==arr[j]){
                pos=j;
                for(int k=pos;k<size-1;k++){
                        arr[k]=arr[k+1];
                }
                size--;
                j--;
            }
        }
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<' ';
    }
    return 0;
}