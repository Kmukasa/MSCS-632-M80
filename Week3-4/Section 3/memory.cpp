#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

int main() {
    // C++11: Use smart pointers for automatic memory management
    cout << "=== Smart Pointer Approach ===" << endl;
    
    // Allocate memory using unique_ptr (similar to Rust's Box)
    vector<int>* vec_ptr = new vector<int>();
    vec_ptr->push_back(1);
    vec_ptr->push_back(2);
    vec_ptr->push_back(3);
    vec_ptr->push_back(4);
    vec_ptr->push_back(5);
    unique_ptr<vector<int> > data(vec_ptr);
    cout << "Original data: ";
    for (vector<int>::const_iterator it = data->begin(); it != data->end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // Transfer ownership of the vector from 'data' to 'vec_owner'
    unique_ptr<vector<int> > vec_owner = move(data);
    
    // Borrow the data (get raw pointer/reference)
    const vector<int>* borrowed_ptr = vec_owner.get();
    cout << "Borrowed data: ";
    for (vector<int>::const_iterator it = borrowed_ptr->begin(); it != borrowed_ptr->end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // Create mutable data
    unique_ptr<string> mutable_data(new string("Hello"));
    
    // Modify through reference
    {
        string& mutable_ref = *mutable_data;
        mutable_ref += ", World!";
    } // Reference goes out of scope
    
    cout << "Modified data: " << *mutable_data << endl;
    
    // Memory automatically freed when unique_ptr goes out of scope
    cout << "Memory will be automatically freed" << endl;
    
    cout << "\n=== Raw Pointer Approach (Traditional C++) ===" << endl;
    
    // Raw pointer allocation (manual memory management)
    int* raw_data = new int[5];
    raw_data[0] = 1; raw_data[1] = 2; raw_data[2] = 3; raw_data[3] = 4; raw_data[4] = 5;
    cout << "Raw allocated data: ";
    for (int i = 0; i < 5; i++) {
        cout << raw_data[i] << " ";
    }
    cout << endl;

    // Manual deletion of raw data that was allocated memory is required
    delete[] raw_data;
    raw_data = nullptr; // Good practice to avoid dangling pointers
    cout << "Manual memory cleanup completed" << endl;
    
    return 0;
}