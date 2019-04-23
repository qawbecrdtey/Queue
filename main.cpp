#include <iostream>
#include "Queue.hpp"
int main() {
    Queue<int> q;
    q.push(3);
    int i = 2;
    q.push(i);
    q.pop();
    std::cout << q.front() << std::endl;
    q.clear();
    std::cout << q.size();
}