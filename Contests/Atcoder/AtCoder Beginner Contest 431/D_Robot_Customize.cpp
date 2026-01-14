#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

class Spinlock{
public:
    Spinlock() : flag_(ATOMIC_FLAG_INIT) {}

    Spinlock(const Spinlock&) = delete;
    Spinlock& operator=(const Spinlock&) = delete;

    void lock(){
        while (flag_.test_and_set(std::memory_order_acquire)){
            this_thread::yield();
        }
    }

    void unlock(){
        flag_.clear(memory_order_release);
    }

private:
    atomic_flag flag_;
};

struct Node{
    bool isLocked;
    int lockedBy;

    Spinlock nodeSpinlock;
    string name;

    Node(string s) : name(s), isLocked(false), lockedBy(-1) {}
};


bool lock(Node* node, int threadId){
    node->nodeSpinlock.lock();

    bool success = false;
    if (node->isLocked){
        success = false;
    }
    else{
        node->isLocked = true;
        node->lockedBy = threadId;
        success = true;
    }

    node->nodeSpinlock.unlock();

    return success;
}

bool unlock(Node* node, int threadId){
    node->nodeSpinlock.lock();

    bool success = false;
    if (!node->isLocked){
        success = false;
    }
    else if (node->lockedBy != threadId){
        success = false;
    }
    else{
        node->isLocked = false;
        node->lockedBy = -1;
        success = true;
    }

    node->nodeSpinlock.unlock();

    return success;
}

void thread_task(Node* node, int threadId){
    for (int i = 0; i < 3; i++){
        if (lock(node, threadId)){
            this_thread::sleep_for(std::chrono::milliseconds(10 * threadId));
            unlock(node, threadId);
        }
        else{
            this_thread::sleep_for(std::chrono::milliseconds(5));
        }
    }
}