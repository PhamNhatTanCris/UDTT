#include<bits/stdc++.h>

using namespace std;

const int n = 6;

void xuat(string S[]){
	for(int i = 0; i <= n; i++){
		cout<<S[i]<<endl;
	}
}
void change(string S[]){
	int d[6];
	for(int i = 0; i < 6; i++){
		
	}
}
int partition(int arr[], int low, int high) 
    { 
        // ch?t du?c ch?n ? d�y l� ph?n t? cu?i m?ng
        int pivot = arr[high];  
        int i = (low-1);  
        for (int j=low; j<high; j++) 
        {  
            // n?u ph?n t? nh? hon ho?c b?ng v?i ch?t
            if (arr[j] <= pivot) 
            { 
                i++; 
  
                // d?i ch? arr[i] v� arr[j] 
                int temp = arr[i]; 
                arr[i] = arr[j]; 
                arr[j] = temp; 
            } 
        } 
        
        // d?i ch? arr[i+1] v� arr[high] (ch?t)
        int temp = arr[i+1]; 
        arr[i+1] = arr[high]; 
        arr[high] = temp; 
        
        // tr? v? ch? s? c?a ch?t
        return i+1; 
    } 
    
    // H�m th?c hi?n quicksort
    void sort(int arr[], int low, int high) 
    { 
        // n?u ch? s? c?a d?u m?ng nh? hon ch? s? cu?i m?ng
        if (low < high) 
        { 
            // t�m ch? s? c?a ch?t sau khi d� th?c hi?n s?p x?p
            int pi = partition(arr, low, high); 
  
            // l?p l?i c�c bu?c v?i m?ng t? ph?n t? d?u ti�n d?n ch?t - 1
            // v� t? ch?t + 1 d?n ph?n t? cu?i c�ng c?a m?ng.
            sort(arr, low, pi-1); 
            sort(arr, pi+1, high); 
        } 
    } 

int main(){
	int d[6];
	string S[6] = {"childrend", "my parents", "my home", "my favorite", "my dog", "tomorrow"};
	xuat(S);
	cout<<sizeof(S[3]);
}

