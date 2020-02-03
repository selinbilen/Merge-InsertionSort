//============================================================================
// Name        : 150160223.cpp
// Author      : Selin Eylul Bilen
//============================================================================
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <time.h>

using namespace std;

void InsertionSort(int arr[],int size){
    for(int j=1;j<size;j++){
        int temp=arr[j];
        int i = j-1;
        while(i>=0 && arr[i]>temp){
            arr[i+1]=arr[i];
            i-=1;
        }
        arr[i+1]=temp;
    }
}

void Merge(int *a, int low, int high, int mid){
    int i, j, k, temp[high-low+1];
    i = low;
    k = 0;
    j = mid + 1;

    while (i <= mid && j <= high){
        if (a[i] < a[j]){
            temp[k] = a[i];
            k++;
            i++;
        }
        else{
            temp[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid){
        temp[k] = a[i];
        k++;
        i++;
    }
    while (j <= high){
        temp[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i <= high; i++){
        a[i] = temp[i-low];
    }
}

void MergeSort(int *a, int low, int high)
{
    int mid;
    if (low < high){
        mid=(low+high)/2;
        MergeSort(a, low, mid);
        MergeSort(a, mid+1, high);
        Merge(a, low, high, mid);
    }
}

int main(int argc, char** argv) {
    char *p;
    int size = strtol(argv[1],&p,10);
    ifstream eva;
    eva.open("data.txt");
    int line;
    int arr[size];
    vector<int> v;
    clock_t t;
    t=clock();
    while(eva>>line){
        v.push_back(line);
    }
    for(int i=0;i<size;i++){
        arr[i]=v[i];
    }
    if(string(argv[2])=="InsertionSort"){
        InsertionSort(arr,size);
        ofstream outfile ("sorted.txt");
        if (outfile.is_open()) {
            for (int i = 0 ; i < size ; i++) {
                outfile << arr[i] << "\n";
            }
            outfile.close();
        }
        t = clock()-t;
        cout<<(float(t)/CLOCKS_PER_SEC)<<endl;
    }
    if(string(argv[2])=="MergeSort"){
        MergeSort(arr,0,size-1);
        ofstream outfile ("sorted.txt");
        if (outfile.is_open()) {
            for (int i = 0 ; i < size ; i++) {
                outfile << arr[i] << "\n";
            }
            outfile.close();
        }
        t = clock()-t;
        cout<<(float(t)/CLOCKS_PER_SEC)<<endl;
    }
    eva.close();
    return 0;
}
