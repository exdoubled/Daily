#include <iostream>

#define MAX_N 100001

using namespace std;

long long * help = new long long [MAX_N];

void merge(long long *arr, int l, int m, int r){
    int i = l;
    int p = l;
    int q = m+1;
    while (p <= m && q <= r){
        help[i++] = arr[p] <= arr[q] ? arr[p++] : arr[q++];
    }

    while (p <= m){
        help[i++] = arr[p++];
    }
    while (q <= r){
        help[i++] = arr[q++];
    }

    for(int i = l; i <= r; ++i){
        arr[i] = help[i];
    }
}

void merge_sort(long long  *arr, int l, int r){
    if (l == r){
        return;
    }
    int m = (l + r) / 2;
    merge_sort(arr, l, m);
    merge_sort(arr, m+1,r);
    merge(arr, l, m ,r);
}

int main() {
    int N;
    cin >> N;
    long long a[MAX_N] = { 0 };

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    merge_sort(a, 0, N - 1);

    for (int i = 0; i < N; ++i){
        cout << a[i] << " ";
    }

    return 0;
}
