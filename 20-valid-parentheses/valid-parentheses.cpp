class Solution {
public:
    bool isValid(string str) {
        stack <char> s;
    for (int i=0;i<str.size();i++)
    {
        char ch=str[i];
        if(ch=='(' || ch=='{' || ch=='[' )   //opening
        {
            s.push(ch);
        }
        else //closing 
        {
            if(s.empty())     
            {
                return false;
            }

            //matching
            char top=s.top();
            if((top=='(' && ch==')') || (top=='{' && ch=='}') || (top=='[' && ch==']'))
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return s.empty();
    }
};