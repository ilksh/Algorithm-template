#include<bits/stdc++.h>
using namespace std;

struct Complex{
    int x,y;
    
    Complex(int _x, int _y){
        x = _x;
        y = _y;
    }
    // if no operator redefine process, Invalid operands to binary expression error occurs
    void operator += (Complex& rhs){
        x += rhs.x;
        y += rhs.y;
    }
    
    void operator -= (Complex& rhs){
        x -= rhs.x;
        y -= rhs.y;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    Complex p1(3,4), p2(-1, 6);
    p1 += p2;
    p2 -= p1;
    
    cout << p1.x << " " << p1.y << "\n";    // 2 10
    cout << p2.x << " " << p2.y << "\n";    // -3 -4
    
    return 0;
}
