#include<bits/stdc++.h>
using namespace std;


bool check(string temp)
{
    stack<char> s;      // initialize stack
    
    for(int i=0; i< temp.size(); ++i)
    {
        if(temp[i] == '(')
            s.push(temp[i]);
        
        else if (temp[i] == ')')
        {
            // number of ( and that of ) do not match
            if(s.empty())
                return false;
            
            s.pop();
        }
    }
    
    if(s.empty())
        return true;
    // number of '(' and that of ')' do not match
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    while(n--)
    {
        string temp;
        
        cin >> temp;
        
        if (check(temp))
            cout << "No error";
        else
            cout << "Error";
        
        cout << "\n";
    }
    
    return 0;
}

/*
6
(())())
(((()())()
(()())((()))
((()()(()))(((())))()
()()()()(()()())()
(()((())()
    
Error
Error
No error
Error
No error
Error
*/
