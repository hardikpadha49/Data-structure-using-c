#include<stdio.h>
#include<stdlib.h>
int main (){
    int n,count =0;
    scanf("%d",&n);
    int arr[n];
    for(int i =0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int freq[n];
    for(int i=0;i<n;i++){
    freq[i]=-1;
    }
    for(int i =0;i<n;i++){
        count=1;
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
                freq[j]=0;
            }
        }
        if(freq[i]!=0){
            freq[i]=count;
        }
    }
    for(int i=0;i<n;i++){
        if(freq[i]==1){
            printf("%d ",arr[i]);
        }
    }
}