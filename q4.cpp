#include <iostream>
using namespace std;
int main()
{
    int a;
    cout<<"a:";
    cin>>a;
    switch(a){
        case 1:{                                    //ARRAY REVERSING
            int size;
            cout<<"size of array:";
            cin>>size;
        int arr[size];
        for(int i=0;i<size;i++){
            cin>>arr[i];
        }
        for(int i=0;i<size/2;i++){
            int temp;
            temp=arr[i];
            arr[i]=arr[size-i-1];
            arr[size-i-1]=temp;
        }
        for(int i=0;i<size;i++){
            cout<<arr[i]<<' ';
        }
        break;
        }
        case 2:{                                      //MATRIX MULTIPLICATION
            int result[3][3];
            int arr[3][2]={{1,2},{3,4},{5,6}};
            int brr[2][3]={{10,11,12},{13,14,15}};
            int rc=2;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    result[i][j]=0;
                    for(int k=0;k<rc;k++){
                        result[i][j]+=arr[i][k]*brr[k][j];
                        
                    }
                }
            }
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    cout<<result[i][j]<<' ';
                }
                cout<<endl;
            }
            break;
        }
        case 3:{                                       //MATRIX TRANSPORSE
            int crr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
            for(int i=0;i<3;i++){
                for(int j=i+1;j<3;j++){
                    int temp;
                    temp=crr[i][j];
                    crr[i][j]=crr[j][i];
                    crr[j][i]=temp;
                }
            }
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    cout<<crr[i][j]<<' ';
                }
                cout<<endl;
            }
            break;
        }
        default:{
            cout<<"Invalid operation";
        }
    }

    return 0;
}