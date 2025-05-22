#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void sortChar(string& word){
  for(auto i = 0; i < word.length(); i++){
    auto tmp = word[i];
    for(auto j = i + 1; j < word.length(); j++){
      if (tmp > word[j]){
        auto tmp2 = tmp;
        tmp = word[j];
        word[j] = tmp2;
        word[i] = tmp;
      }
    }
  }
}

vector<vector<string>> findAnagrams(vector<string> wordlist) {
  vector<vector<string>> result;

  // TODO: Implement this function
  map<string, vector<string>>wordMap;

  for(auto i = 0; i < wordlist.size(); i++){
    auto tmp = wordlist[i];
    sortChar(tmp);
    wordMap[tmp].push_back(wordlist[i]);
  }

  map<string, vector<string>>::iterator it;
  for(it = wordMap.begin(); it != wordMap.end();it++){
    if (it->second.size() > 1)
    result.push_back(it->second);
  }

  return result;
}

vector<vector<string>> tests{
    {"cat", "atc", "cta", "dog"},
    {"created", "catered", "crafted", "reacted"}
};

int main(void){
    for(auto test: tests){
        auto ret = findAnagrams(test);
        for(auto e: ret){
            cout << "\n";
            for(auto v: e){
                cout << v << ", ";
            }
        }
    }
}