#include <iostream>
#include <string>

using namespace std;

string * help = new string[20];

bool compare(const string& str1, const string& str2){
    // 用于指向两个数字的指针
    int p = 0, q = 0;
    // 用于判断是否都遍历了一次
    bool p_key = true, q_key = true;
    while (true){
        while (p < str1.size() && q < str2.size()){
            if (str1[p] > str2[q]){
                return true;
            }
            else if (str1[p] < str2[q]){
                return false;
            }
            else{
                ++p;
                ++q;
            }
        }
        if (p < str1.size() && q_key){
            q = 0;
            q_key = false;
            continue;
        }
        if (q < str2.size() && p_key){
            p = 0;
            p_key = false;
            continue;
        }
        break;
    }
    return true;
}

void merge(string * arr, int l, int m, int r){
    int p = l;
    int q = m+1;
    int i = l;
    while (p <= m && q <= r){
        help[i++] = compare(arr[p], arr[q]) ? arr[p++] : arr[q++];
    }
    while (p <= m){
        help[i++] = arr[p++];
    }
    while (q <= r){
        help[i++] = arr[q++];
    }

    for (int j = l; j <= r; ++j) {
        arr[j] = help[j];
    }
}

void merge_sort(string * arr, int l, int r){
    if (l == r){
        return;
    }

    int m = (l + r) / 2;
    merge_sort(arr, l, m);
    merge_sort(arr, m+1, r);
    merge(arr, l, m, r);
}

int main() {
    int n;
    cin >> n;
    string *arr = new string[n];
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    string result;
    merge_sort(arr, 0, n-1);

    for(int i = 0; i < n; ++i){
        result += arr[i];
    }

    cout << result;
    return 0;
}