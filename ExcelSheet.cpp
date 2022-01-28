 
TO NUMBER
int titleToNumber(string s) {
        int col = 0;
        for(int i = s.length(); i > 0; i--) {
            col += (s[i - 1] - 'A' + 1) * pow(26, (s.length() - i));
        }
        return col;
    }
    
TO STRING
string convertToTitle(int n) {
    string res;
    char tmp;
    while(n){
        n -= 1;
        tmp = 'A' + n % 26;
        res = tmp + res;
        n /= 26;
    }
    return res;
}
