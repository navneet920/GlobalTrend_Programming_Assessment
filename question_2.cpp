#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int LengthOfLongSubstring(const string& s){
    int charIndex[256];
    memset(charIndex,-1,sizeof(charIndex));
    int maxLength=0;
    int start=0;
    for(int i =0 ;i<s.length();++i){
        char currentChar =s[i];
        if (charIndex[currentChar]>=start)
        {
            start = charIndex[currentChar]+1;
        }
        charIndex[currentChar]=i;
        maxLength=max(maxLength,i-start+1);
    }
    return maxLength;
}
int main(){
    string s = "abcabcbb";
    cout<<"The Length of substring :"<<LengthOfLongSubstring(s)<<endl;
    return 0;
}