/**
 * See LC 1115 for PS
 */
#include <bits/stdc++.h>

using namespace std;

class FooBar {
private:
    const int n;
    mutex mu;
    condition_variable cv;
    int state;
public:
    FooBar(int n): n(n), state(0) {
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> l(mu);
        	// printFoo() outputs "foo". Do not change or remove this line.
            cv.wait(l, [this]() {
                return state == 0;
            });
        	printFoo();
            state = 1;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> l(mu);
        	// printFoo() outputs "foo". Do not change or remove this line.
            cv.wait(l, [this]() {
                return state == 1;
            });
        	printBar();
            state = 0;
            cv.notify_all();
        	// printBar() outputs "bar". Do not change or remove this line.
        }
    }
};