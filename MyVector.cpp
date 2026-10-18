#include<iostream>
#include<vector>
using namespace std;
class MyVector{
private:
    int length;
    int* arr;
    int cap;

public:
    MyVector(int capacity, int default_value){
        cap = capacity;
        length = capacity;

        arr = new int[capacity];
        for(int i=0; i<capacity; i++){
            arr[i] = default_value;
        }
    }

    int size(){
        return length;
    }

    int capacity(){
        return cap;
    }

    void pop_back(){
        if(length==0){
            cout<<"Vector is Empty!"<<endl;
            return;
        }
        length--;
    }


    void push_back(int val){
        if(length==cap){
            cap = 2*cap;
            int* temp = new int[cap];
            for(int i=0; i<length; i++){
                temp[i] = arr[i];
            }

            delete[] arr;
            arr = temp;
        }

        arr[length++] = val;
    }

    int get(int idx){
        if(idx<0 || idx>=length){
            cout<<"Index out of bound"<<endl;
            return -1;
        }
        return arr[idx];
    }

    void set(int idx, int val){
        if(idx<0 || idx>=length){
            cout<<"Index out of bound"<<endl;
            return;
        }

        arr[idx] = val;


    }

    void print(){
        for(int i=0; i<length; i++){
            cout<<arr[i]<<" ";
        }

        cout<<endl;
    }
};

int main(){
    int m, n;
    cout<<"Enter the Size and Default Value of Vector: ";
    cin>>m>>n;
    MyVector v(m, n);
    v.print();
    v.pop_back();
    v.print();
    v.push_back(10);
    v.print();
    v.push_back(20);
    v.print();

    cout<<v.get(5)<<endl;
    v.set(2, 120);
    v.print();
}