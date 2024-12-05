#include <iostream>
#include "buffer.h"
#include "bufferlist.h"

using namespace std;

int main() {
    /*
    cout << endl << "---------------------------------------------------------------------------------" << endl << endl;

    cout << "Enqueue Buffer test" << endl;
    Buffer testBuffer(3);
    testBuffer.enqueue(1);
    testBuffer.enqueue(2);
    testBuffer.enqueue(3);
    testBuffer.dump();

    cout << endl << "---------------------------------------------------------------------------------" << endl << endl;

    cout << "Buffer Copy Constructor Test" << endl;
    Buffer test_copy(testBuffer);
    test_copy.dump();

    cout << endl << "---------------------------------------------------------------------------------" << endl << endl;

    testBuffer.dump();
    cout << "Dumping!" << endl;
    testBuffer.dequeue();
    testBuffer.dump();

    cout << endl << "---------------------------------------------------------------------------------" << endl << endl;

    Buffer copytestBuffer(5);
    copytestBuffer.enqueue(1);
    copytestBuffer.enqueue(2);
    copytestBuffer.enqueue(3);
    copytestBuffer.dump();
    Buffer d_copy(copytestBuffer);
    cout << "Dumping D_copy!" << endl;
    d_copy.dump();

    cout << endl << "---------------------------------------------------------------------------------" << endl << endl;

    cout << "Testing Full Empty of Buffer " << endl;
    // This will ensure that the entire buffer can be dequeued at once (just a test of one buffer)

    Buffer newBuffer(3);
    newBuffer.enqueue(0);
    newBuffer.enqueue(1);
    newBuffer.enqueue(2);
    newBuffer.dump();
    // 3 Dequeues
    newBuffer.dequeue();
    newBuffer.dequeue();
    newBuffer.dequeue(); // Need to implement some form of checking for Dequeue from empty buffers
    newBuffer.dump();
    // 3 Enqueues
    newBuffer.enqueue(-1);
    newBuffer.enqueue(-2);
    newBuffer.enqueue(-3);
    newBuffer.dump();

    */

    cout << endl << "---------------------------------------------------------------------------------" << endl << endl;

     cout << "Begin Testing BufferList.cpp and BufferList.h " << endl;

    cout << endl << "---------------------------------------------------------------------------------" << endl << endl;

    cout << "First test of BufferList " << endl;

    // Fills 3 lists to Capacity
    BufferList test_list(5);
    /*
    for(int i = 0; i < 21; i++){
        test_list.enqueue(i);
    }
    // Dumps the lists
    test_list.dump();

    cout << "Dequeue test" << endl;

    test_list.dequeue();

    test_list.dump();

    cout << "Testing Buffer List deletion" << endl;

    test_list.dequeue();
    test_list.dequeue();
    test_list.dequeue();
    test_list.dequeue();
    test_list.dequeue();

    test_list.dump();

    cout << endl << "---------------------------------------------------------------------------------" << endl << endl;

    BufferList new_list(2);
    for(int i = 0; i < 5; i++){
        new_list.enqueue(i);
    }

    cout << "Original Buffer List" << endl;

    new_list.dump();

    cout << "Dequeue Buffer List" << endl;

    new_list.dequeue();
    new_list.dequeue();
    new_list.dequeue();
    new_list.dequeue();
    new_list.dequeue();
    new_list.dequeue();

    new_list.dump();

    cout << endl << "---------------------------------------------------------------------------------" << endl << endl;

    cout << "Copy Constructor Test" << endl;

    BufferList copy_list(5);
    for(int i = 0; i < 50; i++){
        copy_list.enqueue(i);
    }

    copy_list.dump();

    BufferList copy2list(copy_list);
    //copy_list.clear();
    //cout << "Copied List: " << endl;

    copy2list.dump();

    cout << "FINAL MAIN OUTPUT FOR EOF TEST" << endl;
*/
    return 0;
}
