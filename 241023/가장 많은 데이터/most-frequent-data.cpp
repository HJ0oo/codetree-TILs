#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    unordered_map <string, int> my_map;
    string arr[1000001];
    int max_num = 1;

    for (int i=0;i<n;i++){
        cin >> arr[i];
        my_map[arr[i]] += 1; 
        max_num = max(max_num,my_map[arr[i]]);
    }

    cout << max_num ;
    

    return 0;
}