#include<iostream>
using namespace std;
int main(){
    int a;
    cout<<"a=";
    cin>>a;
    switch(a){
        case 1:{       //create
		
        int n;
        cout<<"size of array:";
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        break;
    }
        case 2:{      //display
			
		
        int brr[5]={1,2,3,4,5};
        for(int i=0;i<5;i++){
            cout<<brr[i]<<' ';
        }
        break;
    }
        case 3:{      //insert
        int size;
        cout<<"size:";
        cin>>size;
        int drr[size];
        int pos1;
        cout<<"pos1:";
        cin>>pos1;
        int num;
        cout<<"num:";
        cin>>num;
        for(int k=0;k<size;k++){
            cin>>drr[k];
        }
        size++;
        for(int a=size-1;a>pos1;a--){
            drr[a]=drr[a-1];
        }
        drr[pos1]=num;
        for(int i=0;i<size;i++){
            cout<<drr[i]<<' ';
        }
        break;
    }
        case 4:{    //deletion
        int crr[5]={1,2,3,4,5};
        int pos;
        cout<<"pos:";
        cin>>pos;
        for(int i=pos;i<5;i++){
            crr[i]=crr[i+1];
        }    
        for(int j=0;j<4;j++){
            cout<<crr[j]<<' ';
        }
        break;
    }
        case 5:{     //linear_search
        int count=0;
        int frr[5]={1,2,3,4,5};
        int x;
        cout<<"x:";
        cin>>x;
        for(int i=0;i<5;i++){
            if(frr[i]==x){
                count++;
            }
        }
        if(count!=0){
            cout<<"Found the number";
        }
        else{
            cout<<"Number not found";
        }
        break;
    }
        case 6:{     //Exit
        cout<<"Exit";
        break;
    }
        default:
        cout<<"Invalid input";
    }
    return 0;
}