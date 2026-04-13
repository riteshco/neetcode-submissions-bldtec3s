class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(int i=0;i<strs.size();i++){
            int n = strs[i].size();
            encoded += to_string(n);
            encoded += '#';
            encoded += strs[i];
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        string buff = "";
        int buff_number = 0;
        int i =0;
        while(i<s.size()){
            if(s[i] == '#'){
                for(int j=0;j<buff_number;j++){
                    i++;
                    buff += s[i];
                }
                decoded.push_back(buff);
                buff = "";
                buff_number = 0;
            } else {
                buff_number = buff_number*10 + (int)(s[i] - '0');
            }
            i++;
        }
        return decoded;
    }
};
