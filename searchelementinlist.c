
#include<stdio.h>
#include<stdlib.h>
int main (){
    int n,key,flag=0;
    scanf("%d",&n);
    int arr[n];
    for(int i =0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&key);
    for(int i=0;i<n;i++){
    if(arr[i]==key){
       flag=1;
       break;
    }
}
if(flag==1){
    printf("Found");
}
else{
    printf("Not Found");
}
   return 0;
}