#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


/*
double largestTriangleArea(vector<vector<int>>& points) {

    double ans = 0;
    int n = (int)points.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                double area = abs((points[i][0] * (points[j][1] - points[k][1]) +
                                   points[j][0] * (points[k][1] - points[i][1]) +
                                   points[k][0] * (points[i][1] - points[j][1])) / 2.0);
                ans = max(ans, area);
            }
        }
    }
    return ans;
}
*/

struct P { int x, y; };

long long cross(const P& a, const P& b, const P& c) {
    return 1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (b.y - a.y) * (c.x - a.x);
}

double area(const P& a, const P& b, const P& c) {
    return std::abs(cross(a, b, c)) / 2.0;
}

vector<P> hull(vector<P> v) {
    sort(v.begin(), v.end(), [](const P& a, const P& b){
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });
    v.erase(unique(v.begin(), v.end(), [](const P& a, const P& b){
        return a.x == b.x && a.y == b.y;
    }), v.end());
    if (v.size() <= 2) return v;
    vector<P> st;
    // 下
    for (auto& p : v) {
        while (st.size() >= 2 && cross(st[st.size()-2], st.back(), p) <= 0) st.pop_back();
        st.push_back(p);
    }
    // 上
    size_t k = st.size();
    for (int i = (int)v.size() - 2; i >= 0; --i) {
        while (st.size() > k && cross(st[st.size()-2], st.back(), v[i]) <= 0) st.pop_back();
        st.push_back(v[i]);
    }
    if (!st.empty()) st.pop_back();
    return st;
}

double largestTriangleArea(vector<vector<int>>& points) {
    if (points.size() < 3) return 0.0;
    vector<P> pts; pts.reserve(points.size());
    for (auto& t : points) pts.push_back({t[0], t[1]});
    vector<P> ch = hull(pts);
    int h = (int)ch.size();
    if (h < 3) return 0.0;

    // 旋转卡壳
    vector<P> ext = ch;
    ext.insert(ext.end(), ch.begin(), ch.end());
    double ans = 0.0;
    for (int i = 0; i < h; ++i) {
        int k = i + 2;
        for (int j = i + 1; j < i + h - 1; ++j) {
            while (k + 1 <= i + h && area(ext[i], ext[j], ext[k + 1]) >= area(ext[i], ext[j], ext[k]))
                ++k;
            ans = max(ans, area(ext[i], ext[j], ext[k]));
        }
    }
    return ans;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}