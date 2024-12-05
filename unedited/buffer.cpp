#include "buffer.h"

Buffer::Buffer(int capacity){
    // **************************************
    // Implement the alternative constructor
    // No need to set m_next to nullptr, 
    // it will be handled by linked list,
    // because it is used by linked list
    // **************************************
}

void Buffer::clear(){
    // ***********************************
    // Implement clear() function
    // No need to set m_next to nullptr, 
    // it will be handled by linked list,
    // because it is used by linked list
    // ***********************************
}

Buffer::~Buffer(){
    clear();
}

int Buffer::count(){return m_count;}

int Buffer::capacity(){return m_capacity;}

bool Buffer::full(){
    // **************************
    // Implement full() function
    // **************************
}

bool Buffer::empty(){
    // **************************
    // Implement empty() function
    // **************************
}

void Buffer::enqueue(int data){
    // ********************************
    // Implement enqueue(...) function
    // ********************************
}

int Buffer::dequeue(){
    // *****************************
    // Implement dequeue() function
    // *****************************
}

Buffer::Buffer(const Buffer & rhs){
    // *******************************
    // Implement the copy constructor
    // *******************************
}

const Buffer & Buffer::operator=(const Buffer & rhs){
    // ******************************
    // Implement assignment operator
    // ******************************
    return *this;
}

void Buffer::dump(){
    int start = m_start;
    int end = m_end;
    int counter = 0;
    cout << "Buffer size: " << m_capacity << " : ";
    if (!empty()){
        while(counter < m_count){
            cout << m_buffer[start] << "[" << start << "]" << " ";
            start = (start + 1) % m_capacity;
            counter++;
        }
        cout << endl;
    }
    else cout << "Buffer is empty!" << endl;
}