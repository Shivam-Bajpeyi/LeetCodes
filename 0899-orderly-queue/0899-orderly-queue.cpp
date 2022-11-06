class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1)
        {
            sort(s.begin(),s.end());
            return s;
        }
        else{
            string res = s;
            while(true)
            {
                string temp  = "";
                for(int i = 1;i<s.length();i++)
                {
                    temp += s[i];
                }
                temp += s[0];
                if(res == temp)
                    break;
                s = temp;
                res = min(res,temp);
            }
            return res;
        }
    }
};