#include<stdio.h>

#define MAX 100
int temp[MAX];

void merge(int A[],int low, int mid, int high){
    int i=low;
    int j=mid+1;
    int k=low;

    while(i<=mid && j<=high){
        if(A[i]<=A[j]){
            temp[k]=A[i];
            i++;
        } else {
            temp[k]=A[j];
            j++;
        }
        k++;
    }

    if(i>mid){
        while (j<=high){
            temp[k]=A[j];
            j++;
            k++;
        }
    }
    else{
            while (i<=mid)
            {
                temp[k]=A[i];
                i++;
                k++;
            } 
        }

        for(k=low;k<=high;k++){
            A[k]=temp[k];
        }
    }

void mergesort(int A[], int low, int high){
        if(low<high){
            int mid = (low+high)/2;
            mergesort(A,low,mid);
            mergesort(A,mid+1,high);
            merge(A,low,mid,high);
        }
    }

    int main(){
        int n,i,A[MAX];
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&A[i]);
        }

        mergesort(A,0,n-1);

        for(i=0;i<n;i++){
            printf("%d ",A[i]);
        }


        return 0;
    }