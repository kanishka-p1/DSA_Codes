#include<unordered_map>

int highestFrequency(int arr[], int n) {
    // Write your code here
    unordered_map<int, int> max;
    
    for(int i = 0; i < n; i++){
        max[arr[i]]++;
    }
    
    int key = 0;
    int value = 0;
    
    for(int i = 0; i < n; i++){
        if(max[arr[i]] > value){
            key = arr[i];
            value = max[arr[i]];
        }
    }
    return key;
}
