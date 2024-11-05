#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[201][201] = {0};
int max_ans = -1; // 자연수만 들어있으므로 -1로 설정

int cal_case_1(int s_i, int s_j) {
    // ㄱ자 모양의 최댓값 = 2*2에서 최소를 빼기
    if ( (s_i + 1 < n ) && ( s_j + 1 < m )) {
        return arr[s_i][s_j] + arr[s_i+1][s_j] + arr[s_i][s_j+1]+ arr[s_i+1][s_j+1] - min({arr[s_i][s_j], arr[s_i+1][s_j], arr[s_i][s_j+1], arr[s_i+1][s_j+1]});
    }
    return 0;
}


int cal_case_2(int s_i, int s_j) {
    // ㅣ자 모양의 최댓값 = 가로 세로 모두 고려해야함
    if (s_i + 2 < n ) {
        return arr[s_i][s_j] + arr[s_i+1][s_j] + arr[s_i+2][s_j];
    }
    return 0;
}

int cal_case_3(int s_i, int s_j) {
    // ㅡ자 모양의 최댓값
    if (s_j + 2 < m ) {
        return arr[s_i][s_j] + arr[s_i][s_j+1] + arr[s_i][s_j+2];
    }
    return 0;
}



int main() {
    cin >> n >> m ;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j] ;
        }
    }


    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            max_ans = max(cal_case_1(i,j), max_ans);
            max_ans = max(cal_case_2(i,j), max_ans);
            max_ans = max(cal_case_3(i,j), max_ans);
            // cout << "i와 j가" << i << " " << j <<endl;
            // cout << cal_case_1(i,j) << " ㄱ" << endl;
            // cout << cal_case_2(i,j) << " | " << endl;
            // cout << cal_case_3(i,j) << " ㅡ " << endl;
        }
    }

    cout << max_ans;



    return 0;
}