/**
 * 2 version v1 and v2 are provided, if v1 < v2 return -1; if v1 > v2 return 1; else return 0;
 */
#include <iostream>
#include <vector>

using namespace std;

    void split_str(string s, vector<int>& ret,string delimiter="."){
        auto sbegin = s.begin();
        while(true) {
            auto pos = s.find(delimiter);
            if(pos == string::npos) {
                if(s.size()) {
                    ret.push_back(stoi(s));    
                }
                break;
            } else {
                string tmp = s.substr(pos + 1);
                ret.push_back(stoi(s.substr(0, pos)));
                s = tmp;
            }
        }
    }

    int compareVersion(string version1, string version2) {
        vector<int>v1;
        vector<int>v2;
        split_str(version1, v1);
        split_str(version2, v2);
        const int firstMax = v1.size() <= v2.size()? v1.size():v2.size();
        int indx = 0;
        while(indx < firstMax){
            if(v1[indx] > v2[indx]) {
                return 1;
            } else if (v1[indx] < v2[indx]){
                return -1;
            }
            indx++;
        }
        if (indx < v1.size()){
            // parse remaining values
            for(auto i = indx; i < v1.size(); i++){
                if(v1[i] > 0){
                    return 1;
                }
            }
        }
        if (indx < v2.size()) {
            // parse remaining values
            for(auto i = indx; i < v2.size(); i++){
                if(v2[i] > 0){
                    return -1;
                }
            }
        }
        return 0;
    }

    vector<pair<pair<string,string>, int>> tests = {
        make_pair(make_pair("1.2", "1.10"), -1),
        make_pair(make_pair("1.01", "1.001"), 0),
        make_pair(make_pair("1.0", "1.0.0.0"), 0),
        make_pair(make_pair("1.0.0.1", "1.0.0"), 1)
    };

    int main(void) {
        for(auto test: tests){
            auto ret = compareVersion(test.first.first, test.first.second);
            if (ret == test.second){
                cout << "Test Passed " << test.first.first << " " << test.first.second << endl;
            } else {
                cout << "Test Failed " << test.first.first << " " << test.first.second << " expected " << test.second << " got " << ret << endl;
            }
        }
        return 1;
    }
