#include <iostream>

const int MAX_N = 1e6 + 10;

struct data{
    // 储存的数据是反的
    int num[MAX_N] { 0 };
    int size = 1;

    data& operator=(data a);

    bool operator>(data a);
    bool operator<(data a);
    bool operator==(data a);
    bool operator<=(data a);
    bool operator>=(data a);

    data operator+(const data &a);
};

data& data::operator=(data a) {
    size = a.size;
    for (int i = 0; i < size; ++i){
        num[i] = a.num[i];
    }
    return *this;
}

bool data::operator>(data a) {
    if(size > a.size) return true;
    for(int i = 0; i < size; ++i){
        if(num[i] > a.num[i]) return true;
    }
    return false;
}

bool data::operator<=(data a) {
    return !(*this > a);
}

bool data::operator>=(data a) {
    return !(*this < a);
}

bool data::operator<(data a) {
    if(size < a.size) return true;
    for(int i = 0; i < size; ++i){
        if(num[i] < a.num[i]) return true;
    }
    return false;
}

bool data::operator==(data a){
    if(size != a.size) return false;
    for(int i = 0; i < size; ++i){
        if(num[i] != a.num[i]) return false;
    }
    return true;
}


data data::operator+(const data &a) {
    int carry = 0;
    int org;
    int addSize = 1;
    for(int i = 0; i < (size > a.size ? size : a.size); ++i){
        org = (carry + num[i] + a.num[i]) % 10;
        carry = (carry + num[i] + a.num[i]) / 10;
        num[i] = org;
        if (!carry || num[i+1] != 0 || a.num[i+1] != 0) ++addSize;
    }
    return *this;
}




int main() {
    data a, b;
    for(int i = 0; i < 9; i++){
        a.num[i] = b.num[i] = i;
    }
    a.size = b.size = 10;

    data c = a + b;

    for(int i = c.size-1; i >= 0; --i){
        std::cout << c.num[i];
    }

    return 0;
}
