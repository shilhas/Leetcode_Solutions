/**
 * See LC 1114 for PS
 */
#include <bits/stdc++.h>
#include <mutex>
#include <condition_variable>

using namespace std;

class Foo {
    mutex mu;
    condition_variable cv;
    int state = 0;
public:
    Foo() {
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        std::unique_lock<std::mutex> lock(mu);
        printFirst();
        state = 1;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        std::unique_lock<std::mutex> lock(mu);
        cv.wait(lock, [this]()->bool {
            return state == 1;
        });
        printSecond();
        state = 2;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        std::unique_lock<std::mutex> lock(mu);
        cv.wait(lock, [this]()->bool {
            return state == 2;
        });
        printThird();
        state = 3;
        cv.notify_all();
    }
};

int main() {
    auto func1 = [](){cout << "First";};
    auto func2 = [](){cout << "Second";};
    auto func3 = [](){cout << "Third";};
    vector<function<void()>> test_func{func1,func2,func3};

    vector<vector<int>> tests = {
        {3,2,1},
        {3,1,2},
        {2,3,1},
        {2,1,3},
        {1,3,2},
        {1,2,3},
    };
    int n = 0;
    for (auto test: tests) {
        cout << "\n---------------- Test case:" << n++ <<" ----------------\n";
        shared_ptr<Foo>foo = make_shared<Foo>();
        std::vector<thread> test_threads;
        for (int i: test) {
            if (i == 1) test_threads.emplace_back([=](){
                foo->first(test_func[0]);
            });
            else if (i == 2) test_threads.emplace_back([=](){
                foo->second(test_func[1]);
            });
            else test_threads.emplace_back([=](){
                foo->third(test_func[2]);
            });
        }

        for(auto &t: test_threads) {
            t.join();
        }
    }

}