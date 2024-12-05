#include "bufferlist.h"

BufferList::BufferList(int minBufCapacity) {
    if(minBufCapacity < 1) {
        m_minBufCapacity = DEFAULT_MIN_CAPACITY;
    } else {
        m_minBufCapacity = minBufCapacity;
    }
    // My new buffer sticks around after deletion and I don't know why (with clear)
    m_cursor = new Buffer(minBufCapacity);
    m_cursor->m_next = m_cursor;
    m_listSize = 1;
}
// Called at the end of the function
BufferList::~BufferList() {
    clear();
}

// Deallocates the memory allocated
void BufferList::clear() {
    // Need to implement the deletion of the buffers, works perfectly otherwise
    Buffer* temp = m_cursor;
    for(int i = 0; i < m_listSize; i++) {
        temp->clear();
        temp = temp->m_next;
    }
    Buffer* temp2;
    for(int i = 0; i < m_listSize; i++) {
        temp2 = temp->m_next;
        delete temp;
        temp = temp2;

    }
    m_cursor = nullptr;
    m_minBufCapacity = 0;
    m_listSize = 0;
}

//Adds new data to existing buffers, and creates new buffers as needed.
void BufferList::enqueue(const int& data) {
    try{
        m_cursor->enqueue(data);
    } catch (overflow_error &over) {
        // Generate the size of the Buffer List
        int temp_Int = m_cursor->capacity() * INCREASE_FACTOR;

        // Handles for values greater than the size limit
        if(temp_Int >= (MAX_FACTOR * 100)){
            temp_Int = DEFAULT_MIN_CAPACITY;
        }

        // Generate the new buffer dynamically
        Buffer *temp_Buff = new Buffer(temp_Int);

        // Ensures that the list is looping
        temp_Buff->m_next = m_cursor->m_next;

        // Integrate the cursor
        m_cursor->m_next = temp_Buff;
        m_cursor = m_cursor->m_next;
        m_listSize++;

        // Add the element
        m_cursor->enqueue(data);
    }
}

int BufferList::dequeue() {
    int tempInt = 0;
    Buffer* tempDel;
    // Checks for empty head list and removes it
    if(m_cursor->m_next->empty()) {
        try {
            // This block manages deletion of a Buffer
            tempDel = m_cursor->m_next;
            m_cursor->m_next = m_cursor->m_next->m_next;
            m_cursor->m_next->dequeue();
            // Deallocates the empty buffer
            tempDel->clear();
        } catch(const underflow_error &under) {
            cout << "underflow_error - "<< under.what() << endl;
            return tempInt;
        }
        m_listSize--;
    } else {
        //The standard dequeue process
        tempInt = m_cursor->m_next->dequeue();
    }
    //Returns the dequeued value
    return tempInt;
}

BufferList::BufferList(const BufferList & rhs) {
    //m_cursor will be handled outside the loop
    // Unchanging non-dynamic variables
    m_listSize = 1;
    m_minBufCapacity = rhs.m_minBufCapacity;

    // A temporary cursor to copy the list without changing rhs.cursor
    Buffer *rhs_temp = rhs.m_cursor;
    m_cursor = new Buffer(*rhs_temp);
    m_cursor->m_next = m_cursor;
    rhs_temp = rhs.m_cursor->m_next;

    // For loop to ensure that all elements are copied
    for(int i = 0; i < rhs.m_listSize-1; i++){
        // Creates a new buffer and holds the previous
        Buffer *lhs_temp = new Buffer(*rhs_temp);

        lhs_temp->m_next = m_cursor->m_next;

        m_cursor->m_next = lhs_temp;

        m_cursor = lhs_temp;

        rhs_temp = rhs_temp->m_next;

        m_listSize++;
    }
    m_cursor = m_cursor->m_next;
}

const BufferList & BufferList::operator=(const BufferList & rhs) {
    // m_cursor will be handled outside the loop
    // Clear the existing buffer list
    this->clear();

    // Unchanging non-dynamic variables
    this->m_listSize = 1;
    this->m_minBufCapacity = rhs.m_minBufCapacity;

    // A temporary cursor to copy the list without changing rhs.cursor
    Buffer *rhs_temp = rhs.m_cursor;
    this->m_cursor = new Buffer(*rhs_temp);
    this->m_cursor->m_next = m_cursor;
    rhs_temp = rhs.m_cursor->m_next;

    // For loop to ensure that all elements are copied
    for(int i = 0; i < rhs.m_listSize-1; i++){
        // Creates a new buffer and holds the previous
        Buffer *lhs_temp = new Buffer(*rhs_temp);

        lhs_temp->m_next = this->m_cursor->m_next;

        this->m_cursor->m_next = lhs_temp;

        this->m_cursor = lhs_temp;

        // Move to next RHS buffer
        rhs_temp = rhs_temp->m_next;

        this->m_listSize++;
    }
    this->m_cursor = this->m_cursor->m_next;
    return *this;
}

// Prints the buffer list to terminal
void BufferList::dump() {
    Buffer* temp = m_cursor->m_next;
    for(int i = 0; i < m_listSize; i++) {
        temp->dump();
        temp = temp->m_next;
        cout << endl;
    }
    cout << endl;
}