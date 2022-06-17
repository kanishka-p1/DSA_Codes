#include<unordered_map>
void printIntersection(int arr1[], int arr2[], int n, int m) {
    // Write your code here
    unordered_map<int,int> m1;
    
    for(int i = 0; i < n; i++){
        m1[arr1[i]]++;
    }
    
    for(int i = 0; i < m; i++){
        if(m1[arr2[i]] > 0){
            cout << arr2[i] << endl;
            m1[arr2[i]]--;
        }
    }
}
