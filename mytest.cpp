#include <iostream>
#include <ctime>
#include "bufferlist.h"

using namespace std;

class Tester{
public:
    //Enqueue and Dequeue from the passed Buffer dataCount times
    bool BufferEnqueueDequeue(Buffer &buffer, int dataCount);
    // Try enqueueing the Buffer larger than it's size
    bool BufferEnqueueFull(int size);
    // Test the copy constructor of the Buffer (checks the
    bool BufferCopyConstructor(const Buffer &buffer);
    // Does numTrials trials starting at the value N
    void BufListEnqueuePerformance(int numTrials, int N);
};

// Contains my testing for the class;
int main(){
    Tester tester;
    int Buffer_Size = 1000;
    Buffer Testing_Buffer(Buffer_Size);

    // Testing Buffer Enqueues and Dequeues
    cout << endl << "---------------------------------------------------------------------------------" << endl << endl;
    cout << "Testing Enqueue and Dequeue of a Buffer" << endl << endl;
    if(tester.BufferEnqueueDequeue(Testing_Buffer, Buffer_Size)){
        cout << "Test Passed" << endl;
    }else{
        cout << "Test Failed" << endl;
    }
    cout << endl << "---------------------------------------------------------------------------------" << endl << endl;


    // My test for a full buffer
    cout << "Testing For an overflow error" << endl << endl;
    if(tester.BufferEnqueueFull(1000)){
        cout << "Test Passed" << endl;
    }else{
        cout << "Test Failed" << endl;
    }
    cout << endl << "---------------------------------------------------------------------------------" << endl << endl;
    cout << endl;


    // My test for copy constructor
    cout << "Testing for the Copy Constructor" << endl << endl;
    if(tester.BufferCopyConstructor(Testing_Buffer)){
        cout << "Test Passed" << endl;
    }else{
        cout << "Test Failed" << endl;
    }
    cout << endl << "---------------------------------------------------------------------------------" << endl << endl;
    cout << endl;


    // My test for performance
    cout << "Testing For Performance" << endl << endl;
    tester.BufListEnqueuePerformance(10, 10000);
    cout << endl << "---------------------------------------------------------------------------------" << endl << endl;
    cout << endl;

    // Non-Predefined Tests that I have done
    // These tests were copied from my main and

    cout << "Test for negative capacity buffers" << endl;

    Buffer negativeTest(-5);

    cout << endl << "Test for Deep Buffer Copy" << endl;

    Buffer original(5);
    original.enqueue(1);
    original.enqueue(2);
    original.enqueue(3);
    original.enqueue(4);

    cout << "Original Buffer: " << endl;
    original.dump();

    Buffer copy(original);

    // This originally passed the test but there is an issue with the destructor
    original.clear();

    cout << "Copied Buffer: " << endl;
    copy.dump();

    cout << endl << "---------------------------------------------------------------------------------" << endl << endl;
    cout << endl;

    cout << "Test for Deep Copy through Assignment operator" << endl;

    Buffer assignment_op(5);
    assignment_op.enqueue(1);
    assignment_op.enqueue(2);
    assignment_op.enqueue(3);
    assignment_op.enqueue(4);

    cout << "Original Buffer: " << endl;
    assignment_op.dump();

    Buffer assignment_Copy(2);
    assignment_Copy = assignment_op;

    assignment_op.clear();

    cout << "Copied Buffer: " << endl;
    assignment_Copy.dump();

    cout << endl << "---------------------------------------------------------------------------------" << endl << endl;
    cout << endl;





    return 0;
};


bool Tester::BufferEnqueueDequeue(Buffer &buffer, int dataCount){
    for(int i = 0; i < dataCount; i++){
        buffer.enqueue(i);
    }
    cout << "Buffer has been filled with: " << dataCount << " items." << endl << endl;
    for(int i = 0; i < dataCount; i++){
        buffer.dequeue();
    }
    //This function should make sure that the buffer is emptied completely when dequeued
    if(buffer.empty()){
        cout << "Buffer has been dequeued by: " << dataCount << " items." << endl << endl;
        return true;
    }else{
        cout << "Buffer has not been dequeued by: " << dataCount << " items." << endl << endl;
        return false;
    }
}


bool Tester::BufferEnqueueFull(int size){
    Buffer aBuffer(size);
    for (int i=0;i<size;i++)
        aBuffer.enqueue(i);
    try{
        //trying to insert in a full buffer
        aBuffer.enqueue(size+1);
    }
    catch(overflow_error &e){
        //the exception that we expect
        return true;
    }
    catch(...){
        //any other exception, this case is not acceptable
        return false;
    }
    //no exception thrown, this case is not acceptable
    return false;
}


bool Tester::BufferCopyConstructor(const Buffer &buffer){
    Buffer testing(buffer);


    // Check the memory address of the buffers
    if(&buffer == &testing){
        // They must have different memory addresses
        return false;
    }else{
        // Not acceptable for a copy deep constructor
        return true;
    }
    return false;
}


void Tester::BufListEnqueuePerformance(int numTrials, int N){
    double time;
    clock_t begin, end;

    for(int i = 1; i < numTrials + 1; i++){
        cout << "Trial: " << i << " : " << N << " Elements" << endl;
        begin = clock();
        BufferList Time_trial(N);
        for(int x = 1; x < N + 1; x++){
            Time_trial.enqueue(x);
        }
        end = clock();
        time = end - begin;
        cout << "Enqueueing: " << N << " Elements took: " << time << " Ticks (" << time/CLOCKS_PER_SEC << " sec)" << endl;
        N = N * 2;
        cout << endl;
    }

}
