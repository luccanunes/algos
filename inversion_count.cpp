#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int cnt = 0;
vector<int> merge(const vector<int>& a, const vector<int>& b);
void mergeSort(vector<int>& v);

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    mergeSort(arr);
    for (int x : arr) cout << x << " ";
    cout << endl;
    cout << cnt << endl;
    return 0;
}

vector<int> merge(const vector<int>& a, const vector<int>& b) {
    vector<int> res;
    int i = 0, j = 0;
    while (i < a.size() || j < b.size()) {
        if (i < a.size() && (a[i] <= b[j] || j >= b.size())) {
            res.push_back(a[i]);
            i++;
        } else {
            cnt += a.size() - i;
            res.push_back(b[j]);
            j++;
        }
    }
    return res;
}

void mergeSort(vector<int>& v) {
    int s = v.size();
    if (s == 1) return;
    int mid = s / 2;
    vector<int> vl, vr;
    for (int i = 0; i < mid; i++) vl.push_back(v[i]);
    for (int i = mid; i < s; i++) vr.push_back(v[i]);
    mergeSort(vl);
    mergeSort(vr);
    v = merge(vl, vr);
}