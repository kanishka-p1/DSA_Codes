#include <unordered_map>
int pairSum(int *arr, int n) {
	// Write your code here
    unordered_map<int, int> freq;
    int count = 0;
    
    for(int i = 0; i < n; i++) {
        int temp = -arr[i];
        
        if(freq.find(temp) != freq.end()) {
            count += freq[temp];
        }
        freq[arr[i]]++;
    }
    return count;
}
