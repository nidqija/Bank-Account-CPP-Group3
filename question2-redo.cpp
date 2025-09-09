#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// --------------------- Stack Class ---------------------

template <class T>
class Stack {
private:
    T* data;
    int currentSize;
    int capacity = 5;

public:
   
    Stack(int cap);
    Stack(const Stack& ot);
    Stack(Stack&& ot);
    Stack& operator=(const Stack& ot);
    ~Stack() { delete[] data; }

    bool full() { return currentSize == capacity; }
    bool empty() { return currentSize == 0; }

    bool push(T v);
    bool pop();
    T top();
    int getSize() { return currentSize; }
    int getCapacity() { return capacity; }
};

// Constructor
template <class T>
Stack<T>::Stack(int cap) : capacity(cap), currentSize(0) {
    data = new T[cap];
}

// Copy constructor
template <class T>
Stack<T>::Stack(const Stack& ot) {
    capacity = ot.capacity;
    currentSize = ot.currentSize;
    data = new T[capacity];
    for (int i = 0; i < currentSize; i++)
        data[i] = ot.data[i];
}

// Move constructor
template <class T>
Stack<T>::Stack(Stack&& ot) {
    capacity = ot.capacity;
    currentSize = ot.currentSize;
    data = ot.data;
    ot.data = nullptr;
    ot.currentSize = 0;
}

// Copy assignment
template <class T>
Stack<T>& Stack<T>::operator=(const Stack& ot) {
    if (this != &ot) {
        delete[] data;
        capacity = ot.capacity;
        currentSize = ot.currentSize;
        data = new T[capacity];
        for (int i = 0; i < currentSize; i++)
            data[i] = ot.data[i];
    }
    return *this;
}

// Push
template <class T>
bool Stack<T>::push(T v) {
    if (!full()) {
        data[currentSize++] = v;
        return true;
    }
    return false;
}

// Pop
template <class T>
bool Stack<T>::pop() {
    if (!empty()) {
        currentSize--;
        return true;
    }
    return false;
}

// Top
template <class T>
T Stack<T>::top() {
    if (!empty()) {
        return data[currentSize - 1];
    } else {
        throw runtime_error("Stack is empty!");
    }
}


template <class T>

class Queue{
    private:
      T* data;
      int front;
      int rear;
      int capacity;
      int currentSize;


     public:
      Queue(int cap):capacity(cap) , front(0) ,rear(0) , currentSize(0){
        data = new T[cap];
      }


      ~Queue() {
        delete[] data;

      }

      bool full() {
        return currentSize == capacity;
      }

      bool empty(){
        return currentSize == 0;
      }

      int getSize(){
        return currentSize;
      }

      bool enqueue(T v){
        if(!full()){
          data[rear] = v;
          rear = (rear + 1) % capacity;
          currentSize++;
          return true;
        }  else {
          cout << "Queue is full!" << endl;
          cout << "Total items in the queue: " << currentSize << endl;
          return false;
        }
      }

      bool dequeue(){
       if(!empty()){
        front = (front + 1) % capacity;
        currentSize--;
        return true;
       } else {
        cout << "Queue is empty!" << endl;
        return false;
       }
      }

      T peek(){
        if(!empty()){
          return data[front];
        } else {
          throw runtime_error("Queue is empty!");
        }
      }


      





};

// --------------------- Product Class ---------------------


class Product {
private:
    string item;

public:
    Product() = default;
    Product(string item) { 
      this->item = item; 
    }

    void setItem(string item) { 
      this->item = item; 
    }
    string getItem() { 
      return item; 
    }

    void display() { 
      cout << "Item: " << item << endl; 
    }
};



// --------------------- Main Program ---------------------


int main() {

    int choice;
    Stack<Product> stack(5);
    Queue<Product> queue(5);
    

    while (true){
    cout << "********************************" << endl;
    cout << "Welcome to Inventory System!" << endl;
    cout << "********************************" << endl;
    cout << "Enter your choice: " << endl;
    cout << "1. Add Incoming Item " << endl;
    cout << "2. Process Incoming Item " << endl;
    cout << "3. Ship Item " << endl;
    cout << "4. View Last Incoming Item " << endl;
    cout << "5. View Next Shipment" << endl;
    cout << "6. Exit" << endl;
    cout << "Your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      if(stack.getSize() == stack.getCapacity()){
        cout << "Stack is full! Cannot add more products." << endl;
      } else {
        string itemName;
        cout << "Enter the item to add: ";
        cin >> itemName;
        Product p(itemName);
        if(stack.push(p)){
          cout << "Done! Item \"" << itemName << "\" is added to incoming items!" << endl;
        } else {
          cout << "Failed to add item!" << endl;
        }
      }
      break;

    case 2:
      if(stack.empty()){
        cout << "There are no incoming items to process!" << endl;

      } else {
         Product lastItem = stack.top();
         stack.pop();
         cout << "Processed Item: " << endl;
         lastItem.display();

         if(queue.enqueue(lastItem)){
            cout << "Item " << lastItem.getItem() << " added to the shipping queue!" << endl;
            cout << "total items in the shipping queue: " << queue.getSize() << endl;
         } else if (queue.full()){
           cout << "Shipping queue is full! Cannot add more items to ship. " << endl;
           cout << "Total items in the shipping queue: " << queue.getSize() << endl;
          
         }
      }
      break;


    case 3:
     if(queue.empty()){
      cout << "There are no items to ship!" << endl;
     } else {
       Product ShippedItem = queue.peek();
       queue.dequeue();
       cout << "Shipped Item: " << ShippedItem.getItem() << endl;
       cout << "Total items left in the shipping queue: " << queue.getSize() << endl;
     }
    break;
    case 4:
      if(stack.empty()){
        cout << "There are no incoming items!" << endl;
      } else {
         Product lastIncomingItem = stack.top();
         cout << "Last Incoming Item: " << endl;
         lastIncomingItem.display();
      }
      break;

    case 5:
      if(queue.empty()){
        cout << "There are no items to ship!" << endl;

      } else {
         Product nextShipment = queue.peek();
         cout << "Next Shipment Item: " << nextShipment.getItem() << endl;

      }
      break;

    case 6:
      cout << "Thank you for using the Inventory System. Goodbye!" << endl;
      return 0;
      break;
      
    default:
      break;
    }
      }
   
   

    

   
   

  
   

    return 0;
}
