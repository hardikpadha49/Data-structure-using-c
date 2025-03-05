#include<stdio.h>
#include<stdlib.h>
int main (){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i =0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int value;
    scanf("%d",&value);
    for(int i=0;i<n;){
        if(arr[i]==value){
            for(int j=i;j<n-1;j++){
                arr[j]=arr[j+1];
            }
            n--;
        }else i++;
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}