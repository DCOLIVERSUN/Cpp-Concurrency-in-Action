//
// Created by Oliver_Sun on 2020/5/22.
//
#include <iostream>
#include <thread>

void do_something(int& i) { i++; }

struct func{
    int& i;
    func(int& _i) : i(_i) {}
    void operator() () {
        for (unsigned j = 0; j < 1000000; ++j) {
            do_something(i);
        }
    }
};

void oop() {
    int local_parameter = 0;
    func my_func(local_parameter);
    std::thread t(my_func);
    t.detach();
}

int main() {
    oop();
    return 0;
}