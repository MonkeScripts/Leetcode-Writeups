class MyQueue {
public:
    //create 2 stacks, 1 buffer and 1 fake 'queue'
    stack<int> buffer;
    stack<int> fakeQueue;  
    MyQueue() {
      
    }
    
    void push(int x) {
        buffer.push(x);
    }
    int pop() {
        //if queue is empty, resup from buffer
        if(fakeQueue.empty()){
            while(!buffer.empty()){
                int a = buffer.top();
                buffer.pop();
                fakeQueue.push(a);
            }
        }
        int b = fakeQueue.top();
        fakeQueue.pop();
        return b;        
    }
    
    int peek() {
        //if queue is empty, resup from buffer
         if(fakeQueue.empty()){
            while(!buffer.empty()){
                int a = buffer.top();
                buffer.pop();
                fakeQueue.push(a);
            }
        }
        return fakeQueue.top();        
    }
    bool empty() {
        if(fakeQueue.empty() && buffer.empty() ) return true;
        return false;        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
