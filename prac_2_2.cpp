//
// Created by Oliver_Sun on 2020/5/22.
//
#include <iostream>
#include <thread>

void do_something(int& i) { i++; }

struct func {
    int& i;
    func(int& _i) : i(_i) {}
    void operator() () {
        for (unsigned j = 0; j < 10; ++j) {
            do_something(i);
            std::cout << i << std::endl;
        }
    }
};

void do_something_in_current_thread() {
    std::cout << "do_something_in_current_thread" << std::endl;
}

void f() {
    int some_local_state=0;
    func my_func(some_local_state);
    std::thread t(my_func);
    try
    {
        do_something_in_current_thread();
    }
    catch(...)
    {
        t.join();
        throw;
    }
    t.join();
}

int main() {
    f();
    return 0;
}