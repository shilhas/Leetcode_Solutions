/**
 * See LC 1226 for PS
 */
#include <bits/stdc++.h>

using namespace std;


class DiningPhilosophers {
    array<bool,5>forks;
    mutex getfork;
    condition_variable cv;
public:
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		if (philosopher > 5) return;
        int left = philosopher, right = (philosopher+1) % 5;
        unique_lock<mutex> l_fork(getfork);
        cv.wait(l_fork, [&](){
            return forks[left] == false && forks[right] == false;
        });
        forks[left] = forks[right] = true;
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
        forks[left] = forks[right] = false;
        // l_fork.unlock();
        cv.notify_all();
    }
};

int main() {
    auto get_fork_func = [](int i, string hand) {
        return [i, hand]() {
            cout << "Philosopher " << i << " picked " << hand << " fork\n";
        };
    };

    auto put_fork_func = [](int i, string hand) {
        return [i, hand]() {
            cout << "Philosopher " << i << " put down " << hand << " fork\n";
        };
    };

    auto eat_func = [](int i) {
        return [i]() {
            cout << "Philosopher " << i << " ate food\n";
        };
    };

    vector<vector<int>> test = {
        {3, 4, 2, 0, 1},
        {1, 4, 2, 3, 0},
        {3, 0, 2, 4, 1},
        {3, 4, 1, 0, 2},
        {0, 4, 2, 3, 1},
    };
    DiningPhilosophers d;
    for (auto c: test) {
        vector<thread> threads;
        for (int v: c) {
            threads.emplace_back([&](){
                d.wantsToEat(v, 
                    get_fork_func(v, "left"),
                    get_fork_func(v, "right"),
                    eat_func(v),
                    put_fork_func(v, "left"),
                    put_fork_func(v, "right")
                );
            });
        }
        for (auto &t: threads) {
            t.join();
        }
    }

}