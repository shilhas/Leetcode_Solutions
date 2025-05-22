/**
 * For given Numerator and denominator return the fraction as string with repeating part enclosed in braces 
 * e.g. N= 4 D= 333 result = 0.(012)
 */
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;



    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)  return 0;
        string ret = "";
        if ((numerator > 0) ^ (denominator > 0)) ret = "-"; //since either N or D is '-' answer is '-'

        long d = labs(denominator);
        long q = labs(numerator) / d;
        long r = labs(numerator) % d;
        ret += to_string(q);
        if (r == 0) return ret;

        ret += ".";
        unordered_map<long, long>remainders;
        while(r != 0) {
            if(remainders.find(r) != remainders.end()){
                ret.insert(remainders[r],"(");
                ret += ")";
                return ret;
            } else {
                remainders[r] = ret.length();
                r *= 10;
                q = r / d;
                r %= d;
                ret += to_string(q);
            }

        }
        return ret;
    }

    vector<pair<pair<int, int>, string>> tests{
        make_pair(make_pair(4, 333), "0.(012)"),
        make_pair(make_pair(-9, 18), "-0.5"),
        make_pair(make_pair(578, -45), "-12.8(4)"),
    };

    int main(){
        for(auto test: tests){
            auto ret = fractionToDecimal(test.first.first, test.first.second);
            if (ret == test.second){
                cout << "Test Passed " << test.first.first << " " << test.first.second << endl;
            } else {
                cout << "Test Failed " << test.first.first << " " << test.first.second << " expected " << test.second << " got " << ret << endl;
            }
        }
    }