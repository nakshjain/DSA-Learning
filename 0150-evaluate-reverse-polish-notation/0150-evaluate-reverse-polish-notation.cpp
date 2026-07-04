class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(const string& s: tokens){
            if(s=="+" || s=="-" || s=="*" || s=="/"){
                int num2=st.top();
                st.pop();
                int num1=st.top();
                st.pop();
                if(s=="+") st.push(num1+num2);
                else if(s=="-") st.push(num1-num2);
                else if(s=="*") st.push(num1*num2);
                else if(s=="/") st.push(num1/num2);
            } else st.push(stoi(s));
        }
        return st.top();
    }
};