#include <iostream>
using namespace std;
int main()
{
   int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
   int sum_row;
   int sum_col;
   for(int i=0;i<3;i++){                                        //SUM OF EACH ROW OF AN ARRAY
       int sum_row=0;
       for(int j=0;j<3;j++){
           sum_row+=arr[i][j];
       }
       cout<<"Sum_row"<<i+1<<":"<<sum_row<<endl;
   }
   for(int j=0;j<3;j++){
       int sum_col=0;
       for(int i=0;i<3;i++){                                     //SUM OF EACH COLUNM OF AN ARRAY
           sum_col+=arr[j][i];
       }
       cout<<"Sum_column"<<j+1<<":"<<sum_col<<endl;
   }
    return 0;
}