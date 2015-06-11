/*Implement Stack using Queues
 Implement the following operations of a stack using queues.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    empty() -- Return whether the stack is empty.

Notes:

    You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
    Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue -- which means only push to back, pop from front, size, and is empty operations are valid.
*/
class Stack {
private:
    deque<int> mqueqe;
public:
    // Push element x onto stack.
    void push(int x) {
        int size = mqueqe.size();
        mqueqe.push_back(x);
        //move ahead of x element to x back
        for(int i = 0;size > 0 && i < size;i++){
            mqueqe.push_back(mqueqe.front());
            mqueqe.pop_front();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        mqueqe.pop_front();
    }

    // Get the top element.
    int top() {
        return mqueqe.front();
    }
    // Return whether the stack is empty.
    bool empty() {
        return mqueqe.empty();
    }
};