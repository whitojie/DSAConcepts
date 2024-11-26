#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

/*

    STACKS AND QUEUES
    Stack is a data structure with last in first out structure (cannot take out any other
    element until you take the first one out on top)
    Queues are a type of data structure the operates a first in first out

*/
class StackManager {
private:
    stack<string> stk;

public:
    // Constructor to initialize stack with elements
    StackManager() {
        stk.push("Eggs");
        stk.push("Bacon");
        stk.push("Grits");
        stk.push("Sausage");
        stk.push("Cereal");
    }

    // Function to display and empty the stack
    void processStack() {
        cout << "Processing Stack:" << endl;
        while (!stk.empty()) {
            cout << stk.top() << endl;
            stk.pop();
        }
    }
};

class QueueManager {
private:
    queue<int> queue;

public:
    // Constructor to initialize queue with elements
    QueueManager() {
        queue.push(23);
        queue.push(34);
        queue.push(98);
        queue.push(4);
        queue.push(18);
    }

    // Function to display the front, back, size, and contents of the queue
    void processQueue() {
        cout << "Front of the queue is " << queue.front() << endl;
        cout << "Back of the queue is " << queue.back() << endl;
        cout << "Size of the queue is " << queue.size() << endl;

        cout << "Processing Queue:" << endl;
        while (!queue.empty()) {
            cout << queue.front() << endl;
            queue.pop();
        }
    }
};