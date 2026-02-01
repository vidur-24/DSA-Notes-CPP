#include <iostream>
using namespace std;

int* fun(int a){
    int* ans = &a;
    return ans;
}

int main() {
    int n = 5;

    cout<<fun(n);

    // array and pointers


}