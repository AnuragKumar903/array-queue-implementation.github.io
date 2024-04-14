#include <iostream>
using namespace std;

class Queue {
public:
    int* arr;
    int qfront;
    int rare;
    int size;
public:
    Queue() {
        // Implement the Constructor
        size = 10001;
        arr = new int[size];
        qfront = 0;
        rare = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront == rare){
            return true;
        }
        return false;
    }

    void enqueue(int data) {
        if(rare == size){
            cout<<"Queue is full"<<endl;
            return;
        }
        arr[rare] = data;
        rare++;
    }

    int dequeue() {
        if(qfront == rare){
            return -1;
        }
        else{
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == rare){
                qfront = 0;
                rare = 0;
            }
            return ans;
        }
    }

    int front() {
        if(qfront == rare){
            return -1;
        }
        else{
            return arr[qfront];
        }
    }
};

int main() {
  
}