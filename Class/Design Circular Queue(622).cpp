/*Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Implementation the MyCircularQueue class:

MyCircularQueue(k) Initializes the object with the size of the queue to be k.
int Front() Gets the front item from the queue. If the queue is empty, return -1.
int Rear() Gets the last item from the queue. If the queue is empty, return -1.
boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
boolean isEmpty() Checks whether the circular queue is empty or not.
boolean isFull() Checks whether the circular queue is full or not.
You must solve the problem without using the built-in queue data structure in your programming language. */

class MyCircularQueue {
private:
     int rear=-1,front=-1,size=0;
     int *array;
public:
   

    MyCircularQueue(int k) {
        array=new int[k];
        size=k;
    }
    
    bool enQueue(int value) {
        if(rear==-1)
            rear=0,front=0;
        else if(isFull())
            return false;
        else
            rear=(rear+1)%size;
        array[rear]=value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        else if(front==rear)
            front=-1,rear=-1;
        else
            front=(front+1)%size;
        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        return array[front];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        return array[rear];
    }
    
    bool isEmpty() {
        return rear==-1;
    }
    
    bool isFull() {
        return (rear+1)%size==front;
    }
};
// r=0,f=0,r=0   / 0 1 2 3
/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
