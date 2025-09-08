#include <iostream>
#include <stack>
#include <queue>
#include <string>


using namespace std;


int main(){

    int choice;
    string item;
    stack<string> incomingItems;
    queue<string> shipmentItems;

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

    switch(choice){
      
        
// ==================================================================================



        case 1:
        cout << "Enter the item to add: " << endl;
        cin >> item;
        incomingItems.push(item);
        cout << "Done! Item " << item <<" is added to incoming items!" << endl;
        break;




// ==================================================================================



        case 2:
         if (!incomingItems.empty()) {
                item = incomingItems.top();
                incomingItems.pop();
                shipmentItems.push(item);
                cout << "Done! Item \"" << item << "\" is processed for shipment!" << endl;
            } else {
                cout << "There are no incoming items to process!" << endl;
            }
        break;


// ==================================================================================


        case 3:
         if(!shipmentItems.empty()){
            item = shipmentItems.front();
            shipmentItems.pop();
            cout << "Done! Item " << item << " is shipped!" << endl;
         } else {
            cout << "There are no items to ship!" << endl;
         }
         break;
         
         
// ==================================================================================

         case 4:
         if(!incomingItems.empty()){
            cout << "Last incoming item: " << incomingItems.top() << endl;
         } else {
            cout << "There are no incoming items!" << endl;
         }

         break;


// ==================================================================================

         case 5:
         if(!shipmentItems.empty()){
            cout << "Next shipment item: " << shipmentItems.front() << endl;

         } else {
            cout << "There are no items to ship!" << endl;
         }

         break;

// ==================================================================================

         case 6:
         cout << "Exiting the program. Thank you for using our service!" << endl;
         exit(0);
         break;

         

        
          
    }

}
   

   
   
  
 
   return 0;
}

