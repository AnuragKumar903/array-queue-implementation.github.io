#include <bits/stdc++.h> 

class CircularQueue{
    public:
    int* arr;
    int size;
    int front;
    int rear;

    public:
    
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    
    bool enqueue(int value){
        if((front == 0 && rear == size-1) || (rear == (front - 1 + size) % size)){
            return false;
        }
        else if(front == -1){        // 1st element
            front = rear = 0;
        }
        else if(rear == size-1 && front != 0){        // circular
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear] = value;
        return true;
    }

   
    int dequeue(){
        if(front == -1){
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear){       // only one element
            front = rear = -1;
        }
        else if(front == size-1){
            front = 0;              // cycle
        }
        else{
            front++;
        }

        return ans;
    }
};

int main() {
    
    CircularQueue q(5); // Initialize queue with size 5

    // Enqueue elements
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    // Dequeue elements
    std::cout << "Dequeued: " << q.dequeue() << std::endl;
    std::cout << "Dequeued: " << q.dequeue() << std::endl;

    // Enqueue more elements
    q.enqueue(6);
    q.enqueue(7);

    // Dequeue remaining elements
    while(true) {
        int val = q.dequeue();
        if(val == -1) break;
        std::cout << "Dequeued: " << val << std::endl;
    }

    return 0;
}
