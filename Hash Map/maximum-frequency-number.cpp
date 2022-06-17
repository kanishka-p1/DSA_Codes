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


//
#include <unordered_map>
int highestFrequency(int arr[], int n) {
    // Write your code here
    unordered_map<int, int> freq;
    int maxfreq = 0;
    int ans = 0;
    
    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
        maxfreq = max(maxfreq, freq[arr[i]]);
    }
    
    for(int i = 0; i < n; i++) {
        if(maxfreq == freq[arr[i]]) {
            ans = arr[i];
            break;
        }
    }
    return ans;
}
