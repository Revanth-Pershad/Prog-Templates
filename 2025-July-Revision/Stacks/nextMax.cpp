#include <bits/stdc++.h>

using namespace std;

vector<int> leftHigh(vector<int> &arr){
    stack<int> st;
    vector<int> res;

    for(int x : arr){
        while(!st.empty() && st.top() < x)
            st.pop();
        
        if(!st.empty())
            res.push_back(st.top());
        else res.push_back(-1);

        st.push(x);
    }


    return res;
}

vector<int> rightHigh(vector<int> &arr){
    stack<int> st;
    vector<int> res(arr.size());

    for(int i = arr.size()-1; i >=0; i--){
        int x = arr[i];
        while(!st.empty() && x > st.top())
            st.pop();
        
        if(!st.empty())res[i] = st.top();
        else res[i] = -1;
        st.push(x);
    }


    return res;
}

int main(){
    int n; cin >> n;
    vector<int> arr(n);

    for(int &x : arr)
        cin >> x;

    for(int x : leftHigh(arr))
        cout << x << " ";

    cout << endl;

    for(int x : rightHigh(arr))
        cout << x << " ";
    
}