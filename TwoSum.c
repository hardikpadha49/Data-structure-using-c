#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

int n,value,i;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&value);
    for(i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==value){
                printf("%d %d",i,j);
                break;
            }
        }
    }
    return 0;
}