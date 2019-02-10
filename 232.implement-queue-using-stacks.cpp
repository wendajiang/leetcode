/*
 * [232] Implement Queue using Stacks
 *
 * https://leetcode.com/problems/implement-queue-using-stacks
 *
 * Easy (36.43%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '["MyQueue","empty"]\n[[],[]]'
 *
 *
 * Implement the following operations of a queue using stacks.
 *
 *
 * push(x) -- Push element x to the back of queue.
 *
 *
 * pop() -- Removes the element from in front of queue.
 *
 *
 * peek() -- Get the front element.
 *
 *
 * empty() -- Return whether the queue is empty.
 *
 *
 * Notes:
 *
 * You must use only standard operations of a stack -- which means only push to
 * top, peek/pop from top, size, and is empty operations are valid.
 * Depending on your language, stack may not be supported natively. You may
 * simulate a stack by using a list or deque (double-ended queue), as long as
 * you use only standard operations of a stack.
 * You may assume that all operations are valid (for example, no pop or peek
 * operations will be called on an empty queue).
 *
 *
 */
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stackone.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(stacktwo.empty()){
            while(!stackone.empty()){
                stacktwo.push(stackone.top());
                stackone.pop();
            }
        }

        int tmp = stacktwo.top();
        stacktwo.pop();
        return tmp;
    }

    /** Get the front element. */
    int peek() {
        if(stacktwo.empty()){
            while(!stackone.empty()){
                stacktwo.push(stackone.top());
                stackone.pop();
            }
        }

        return stacktwo.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stackone.empty() && stacktwo.empty();
    }
private:
    stack<int> stackone;
    stack<int> stacktwo;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
