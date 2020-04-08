#include <iostream>

using std::endl;
using std::cout;
using std::cin;

struct regular_val {
    int data;
    regular_val *next;
};

class regular {
private:
    int len_ = 0;
    regular_val *first;
public:
    regular(){
        first = new regular_val;
        first->next = NULL;
    };
    regular(regular_val *first_){
        first = first_;
    };
    regular add(int data){
        regular_val *now = first;
        while(now->next != NULL){
            now = now->next;
        }
        now->next = new regular_val;
        now = now->next;
        now->data = data;
        len_++;
        return regular(first);
    };
    void view(){
        regular_val *now = first;
        cout << "~(";
        while(now->next != NULL){
            now = now->next;
            cout << now->data << ", ";
        }
        cout << ")~" << endl;
    };

    void sort(){
        regular_val *now_1 = first,
                    *now_2 = first;
        int temp;
        while(now_1->next != NULL){
            now_2 = first->next;
            while(now_2->next != NULL){
                if (now_2->data > now_2->next->data){
                    temp = now_2->data; 
                    now_2->data = now_2->next->data;
                    now_2->next->data = temp;
                }
                now_2 = now_2->next;
            }
            now_1 = now_1->next;
        }
    }

    int len(){
        return len_;
    }

    int get(int key){
        regular_val *now = first;
        for (int i = 0; i < key+1; i++){
            if (now == NULL){
                now = first;
                break;
            }
            now = now->next;
        }
        return now->data;
    }


    void remove(int key){
        regular_val *now = first, 
                    *temp;
        for (int i = 0; i < key; i++){
            if (now == NULL){
                now = first;
                break;
            }
            now = now->next;
        }
        temp = now->next;
        now->next = now->next->next;
        delete temp;
    }

    int &operator[](const int key){
        regular_val *now = first;
        for (int i = 0; i < key+1; i++){
            if (now == NULL){
                now = first;
                break;
            }
            now = now->next;
        }
        return now->data;
    };

    void operator += (const int right){
        regular new_regular = regular(first);
        new_regular.add(right);
    };
};