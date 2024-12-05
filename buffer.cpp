#include "buffer.h"

// Overloaded Constructor
Buffer::Buffer(int capacity){
    if(capacity < 1){
        m_capacity = 0;
        m_buffer = nullptr;
    }else{
        m_capacity = capacity;
        m_buffer = new int [capacity];
    }
    m_count = 0;
    m_start = 0;
    m_end = 0;
}

// Destructor Function
void Buffer::clear(){
    m_capacity = 0;
    m_count = 0;
    m_start = 0;
    m_end = 0;
    // Deletes the buffer array
    delete [] m_buffer;
    m_buffer = nullptr;

}

// Calls Clear to delete the data in the buffer
Buffer::~Buffer(){
    clear();
}

// Returns the value of Count
int Buffer::count(){return m_count;}

// Returns the value of Capacity
int Buffer::capacity(){return m_capacity;}

// Determines if the Buffer is Full
bool Buffer::full(){
    if(m_count == m_capacity){
        return true;
    }else{
        return false;
    }
}

// Determines if the Buffer is Empty
bool Buffer::empty(){
    if(m_count == 0){
        return true;
    }else{
        return false;
    }
}

// Add data to the end of the buffer
void Buffer::enqueue(int data){
    if(!full()){ // Check if this buffer is full
        if(empty()){ // Case if the buffer is empty
            m_buffer[m_end] = data;
        }else{
            // If the Buffer is at the end of the list's range
            if(m_end == m_capacity-1){
                m_end = 0;
                m_buffer[m_end] = data;
            }else{ // Default for the buffer
                m_end++;
                m_buffer[m_end] = data;
            }
        }
        m_count++;
    }else{ // In the case of a full buffer
        throw overflow_error ("Buffer enqueue");
    }
}

// Remove data from the top of the buffer
int Buffer::dequeue(){
    int temp;
    if(!empty()){ // Ensures that the Buffer is not empty
        temp = m_buffer[m_start];
        if(m_start == m_capacity-1){
            m_start = 0;
        }else{
            m_start++;
        }
        m_count--;
    }else{
        throw underflow_error ("Buffer dequeue");
    }
    return temp;
}

// Copy Constructor (Creates a deep copy)
Buffer::Buffer(const Buffer & rhs){

    m_capacity = rhs.m_capacity; // m_capacity copy

    m_end = rhs.m_end; // m_end copy

    m_start = rhs.m_start; // m_start copy

    m_count = rhs.m_count; // m_count copy

    m_next = nullptr; // m_next becomes nullptr

    m_buffer = new int [m_capacity]; // create new buffer

    // Loop through both buffers and creates copies in a the new buffer
    for(int i = m_start; i <= m_count - 1; i++){
        m_buffer[i] = rhs.m_buffer[i];
    }
}

// Overloaded assignment operator (Creates a deep copy)
const Buffer & Buffer::operator=(const Buffer & rhs){
    this->clear();

    this->m_capacity = rhs.m_capacity; // m_capacity copy

    this->m_start = rhs.m_start; // m_start copy

    this->m_end = rhs.m_end; // m_end copy

    this->m_count = rhs.m_count; // m_count copy

    this->m_next = nullptr; // m_next becomes nullptr

    this->m_buffer = new int [m_capacity]; // m_buffer copy

    // Loop through to assign the members of rhs buffer to the new buffer
    for(int i = this->m_start; i <= this->m_count - 1; i++){
        this->m_buffer[i] = rhs.m_buffer[i];
    }
    // Return back the pointer to this new buffer
    return *this;
}

// Dumps to the terminal (as an output)
void Buffer::dump(){
    int start = m_start;
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