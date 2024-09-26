#include "iostream"
using namespace std;


int order;
unsigned int mask;


union db{
    long double numDouble;
    int arr[2];
};


void DoubleInMemory(union db num){
    cout << "\nДвоичное представление числа " << num.numDouble << ":\n";
    order = sizeof(num.numDouble) * 8;
    mask = 1 << (order - 1);

    for (int i = 0; i < order / 2; ++i){
        cout << ((num.arr[1] & mask)? 1 : 0);
        mask >>= 1;
        if (!i || i == 11){
            cout << " ";
        }
    }

    mask = 1 << (order - 1);

    for (int i = 0; i < order / 2; ++i){
        cout << ((num.arr[0] & mask)? 1 : 0);
        mask >>= 1;
    }
    cout << "\n";
}


void CharInMemory(unsigned char ch){
    order = sizeof(ch) * 8;
    mask = 1 << (order - 1);
    for ( int i = 0; i < order; i++ ){
        cout << ((ch & mask) ? 1 : 0);
        mask >>= 1;
    }
    cout << "\n";
}



int main(){
    db DoubleNum;
    unsigned char ch;

    cout << "Введите число типа long double: ";
    cin >> DoubleNum.numDouble;
    DoubleInMemory(DoubleNum);

    cout << "Введите числа типа unsigned char: ";
    cin >> ch;
    CharInMemory(ch);

}