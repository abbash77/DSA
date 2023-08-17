class MyCircularDeque {
public:
    int *arr;
    int front;
    int rear;
    int size;
    MyCircularDeque(int k) {
        arr=new int[k];
        front=-1;
        rear=-1;
        size=k;
    }
    
    bool insertFront(int value) {
        if(isEmpty()){
            front=0;
            rear=0;
            arr[front]=value;
        }
        else if(isFull()){
            return false;
        }
        else if(front==0){
            front=size-1;
            arr[front]=value;
        }
        else{
            front--;
            arr[front]=value;
        }
        return true;
    }
    
    bool insertLast(int value) {
        if(isEmpty()){
            front=0;
            rear=0;
            arr[rear]=value;
        }
        else if(isFull()){
            return false;
        }
        else if(rear==size-1){
            rear=0;
            arr[rear]=value;
        }
        else{
            rear++;
            arr[rear]=value;
        }
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else if(front==size-1){
            front=0;
        }
        else{
            front++;
        }
        return true;
        
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else if(rear==0){
            rear=size-1;
        }
        else{
            rear--;
        }
        return true;
        
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return arr[front];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return ((rear + 1) % size) == front;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */