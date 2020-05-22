//
// Created by Oliver_Sun on 2020/5/22.
//

#include <iostream>
#include <thread>

void hello() {
    std::cout << "Hello Concurrency World\n";
}

int main() {
    std::thread t(hello);
    t.join();
}