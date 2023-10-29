#include<stdio.h>
#define cin(i)  scanf("%d",&i)
#define cend    printf("\n")
#define cout(i) printf("%d, ",i)
void merge(int arr[],int start,int mid,int end){
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int arr1[10],arr2[10];
    for(int i =0;i<n1;i++) arr1[i] = arr[i+start];
    for(int i = 0;i<n2;i++) arr2[i] = arr[mid+1+i];
    int i=0,j=0,k=start;
    while(i<n1 && j<n2){
        if(arr1[i] < arr2[j]) {
            arr[k] = arr1[i];
            i++;
        }
        else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }
    while(i<n1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = arr2[j];
        j++;
        k++;
    }
}
void merge_sort(int arr[],int start,int end){
    if(start<end){
        int mid=(end+start)/2;
        merge_sort(arr,start,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}
int main(){
    int arr[100];
    int n;
    cin(n);
    for(int i=0;i<n;i++) cin(arr[i]);
    for(int i=0;i<n;i++) cout(arr[i]);
    cend;
    merge_sort(arr,0,n-1);
    for(int i=0;i<n;i++) cout(arr[i]);
    return 0;
}
