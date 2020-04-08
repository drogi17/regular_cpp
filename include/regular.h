#include <iostream>

using std::endl;
using std::cout;
using std::cin;

struct regular_val {
    int data;
    regular_val *next = NULL;
};

class regular {
private:
    int len_ = 0;
    regular_val *first;
public:
    regular(){
        first = new regular_val;
    };
    ~regular(){
        regular_val *temp;
        while (first != NULL){
            temp = first->next;
            delete first;
            first = temp;
        };
    };
    regular &add(int data){
        regular_val *now = first;
        while(now->next != NULL){
            now = now->next;
        }
        now->next = new regular_val;
        now = now->next;
        now->data = data;
        len_++;
        return *this;
    };

    regular &add_to_start(const int data){
        regular_val *new_element = new regular_val;
        new_element->data = data;
        new_element->next = first->next;
        first->next = new_element;
        len_++;
        return *this;
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

    // void sort(){
    //     int min_, max_, temp;
    //     regular *array = this;
    //     // while()
    //     // cout << array->len();
    //     if (array->get(array->len()/2) > array->get(array->len()/2 + 1)){
    //         max_ = array->get(array->len()/2);
    //         min_ = array->get(array->len()/2 + 1);
    //     } else{
    //         min_ = array->get(array->len()/2);
    //         max_ = array->get(array->len()/2 + 1);
    //     }
    //     // cout << array->get(array->len()/2) << ", " << array->get(array->len()/2) << endl;
    //     for (int i = 0; i < array->len()/2; i++){
    //         // cout << array->get(i) << endl;
    //         array->view();
    //         if (array->get(i) < min_){
    //             temp = array->get(0);
    //             array->get(0) = array->get(i);
    //             array->get(i) = temp;
    //         } else if (array->get(i) > max_){
    //             temp = array->get(array->len()-1);
    //             array->get(array->len()-1) = array->get(i);
    //             array->get(i) = temp;
    //         }
    //     } 
    // }

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

    void clear(){
        regular_val *temp;
        while (first->next != NULL){
            temp = first->next;
            delete first;
            first = temp;
        };
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
        (*this).add(right);
    };

    void operator = (regular &right){
        (*this).clear();
        for (int i = 0; i < right.len(); i++){
            (*this) += right[i];
        }
        right.view();
    };

};
