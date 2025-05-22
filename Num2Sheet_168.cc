/**
 * for given input coulmnNunber return the the column title e.g. 1 => A; 26 => Z 701 => "ZY"
 */
#include <iostream>
#include <vector>

using namespace std;

string AlphaBet[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", 
                    "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", 
                    "U", "V", "W", "X", "Y", "Z"};

string convertToTitle(int columnNumber) {
    string ret = "";
    while(columnNumber) {
        auto tmp = AlphaBet[(columnNumber - 1) % 26];
        ret = tmp + ret;
        if (columnNumber > 26) {
            columnNumber = (columnNumber - 1) / 26;
        } else {
            break;
        }
    }
    return ret;
}

pair<int, string> test[] = {make_pair(1, "A"), make_pair(28, "AB"), 
make_pair(701, "ZY"), make_pair(52, "AZ")};

int main (void) {
    for(auto t: test) {
        auto tmp = convertToTitle(t.first);
        if(t.second == tmp) {
            cout << "Test Passed, input " << t.first << " Output " << t.second << endl;
        } else {
            cout << "Test Failed for input " << t.first << endl;
        }
    }
}