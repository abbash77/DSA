class ZeroEvenOdd {
private:
    int n;
    mutex m;
    condition_variable cv;
    int i;
    int num;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->i=0;
        this->num=1;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
         while(i<2*n){
             unique_lock<mutex> lock (m);
             
             // if the index is not even ,therefore it will wait 
             while(i<2*n && (i%2==0)==0)
                 cv.wait(lock);
             
             // i is even, therefore we will print 0
             // and increament i
             if(i<2*n){
                printNumber(0);
                i++;
            }
             
             // now notify the threads which were waiting , so that they can resume 
             cv.notify_all();
         }
        
    }

    void even(function<void(int)> printNumber) {
         while(i<2*n){
             unique_lock<mutex> lock (m);
             
             // if the index is not odd && num is not even ,therefore it will wait 
             while(i<2*n && (i%2!=0 && num%2==0)==0)
                 cv.wait(lock);
             
             // i is odd and num is even  , therefore we will print "num"
             // and increament i , num
             if(i<2*n){
                printNumber(num);
                i++;
                num++;
            }
             
             // now notify the threads which were waiting , so that they can resume 
             cv.notify_all();
         }
        
    }

    void odd(function<void(int)> printNumber) {
        while(i<2*n){
             unique_lock<mutex> lock (m);
             // if the index is not odd && num is not odd ,therefore it will wait 
             while(i<2*n && (i%2!=0&& num%2!=0)==0)
                 cv.wait(lock);
             
            // i is odd and num is odd  , therefore we will print "num"
             // and increament i , num
              if(i<2*n){
                printNumber(num);
                i++;
                num++;
            }
             
             // now notify the threads which were waiting , so that they can resume 
             cv.notify_all();
         }
        
    }
};