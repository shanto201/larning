#include<iostream>

int main(){
int n,value found=0,index=-1;
count<<"Enter the size of array";
cin>>n;
int arr[n];
count <<"Enter array element:";
for(int i=0;i<n;i++){
    cin>>arr[i];
}
count <<"Given the value you went to search";
cin>>value;
for (int i=0;i<n;i++){
    if(value==arr[i]){
        found=1;
        index=i;
        break;
    }
}
if(found ==1){
    count<<"Element found at position"<<index+1
}else{
    count<<"element not found";

}
return 0;
}
