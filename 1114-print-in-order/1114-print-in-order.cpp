class Foo {
    int turn;
    condition_variable(cv);
    mutex m;
public:
    Foo() { // constructor
        turn = 0;
    }

    void first(function<void()> printFirst) { // No condition on this as T1 will come first and execute it
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        turn = 1; // next turn is of T2
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex>lock(m);
        while(turn != 1){
            cv.wait(lock); // If it's not turn of T2, thread will wait
        }
        // when signalled by T1, will go in while loop and check if turn == 1, if not then again wait.
        // else print second
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        turn = 2; // next turn is of T3
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex>lock(m);
        // When T1 will signal, CPU will come and check T3 also but due to condition of while loop it will again wait
        while(turn != 2){
            cv.wait(lock);
        }
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};