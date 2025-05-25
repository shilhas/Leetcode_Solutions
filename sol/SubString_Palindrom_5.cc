/**
 * Write code to find longest substring palindrome
 */
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

    string reverse_str(string s){
        string ret = "";
        for(auto c:s){
            ret = c + ret;
        }
        return ret;
    }

    void Palindrome(queue<string>& q, string& pd){
        while(!q.empty()){
            string s = q.front();
            q.pop();
            if (pd == ""){
                if(s == reverse_str(s)){
                    pd = s;
                } else {
                    q.push(s.substr(0, s.length() - 1));
                    q.push(s.substr(1, s.length()));
                }
            }
        }
    }

    string longestPalindrome(string s) {
        if (s.length() < 2){
            return s;
        }
        string palindrome = "";
        queue<string> q;
        q.push(s);
        Palindrome(q, palindrome);
        return palindrome;
    }

vector<string>tests{"babad", "cbbd", "malayalam_music", "ac"};

int main (){
    for(auto test: tests){
        auto ret = longestPalindrome(test);

        cout << "Longest Palindrome in string \'" << test << "\' is \'" << ret << "\'\n";
    }
}