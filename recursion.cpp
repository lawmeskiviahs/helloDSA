#include <iostream>

int sumRecur(int num);
void printNameRecur(int num);
int factRecur(int num);
void arrayRevRecur(int arr[], int len);
int reverseStringRecur(int num, int reverse);
void fibonacciRecur(int a, int b, int num);

int main() {

    int num = 10;
    int arr[] = {6,7,8,9,10};
    int len = sizeof(arr)/sizeof(int);
    int zero = 0;
    int one = 1;
    // std::cout<< "sum of first "<< num << " integers is " << sumRecur(num) << "\n";
    // printNameRecur(num);
    // std::cout<< "factorial of "<< num << " is " << factRecur(num) << "\n";
    // arrayRevRecur(arr, len);
    // int reverse = reverseStringRecur(num, zero);
    // if(num == reverse)
    //     std::cout<<"isPalindrome.";
    // else 
    //     std::cout<<"isNotPalindrome.";
    std::cout<<zero<<"\n";
    fibonacciRecur(zero, one, num-2);

    return 0;

}

int sumRecur(int num) {

    if(num == 0)
        return num;
    else
        return num+sumRecur(num-1);
}

void printNameRecur(int num) {

    std::cout << "name " << num << "\n";
    if (num == 1)
        return;
    else 
        printNameRecur(num-1);
}

int factRecur(int num) {

    if(num == 1)
        return 1;
    else   
        return num*factRecur(num-1);
}

void arrayRevRecur(int arr[], int len) {

    std::cout<< arr[len-1]<< " and len is "<<len<<"\n";
    if (len == 1)
        return;
    else 
        arrayRevRecur(arr, len-1);
}

int reverseStringRecur(int num, int reverse) {

    reverse = reverse * 10 + num % 10;
    // std::cout<<"num is "<<num<<" and reverse is "<<reverse<<"\n";
    if(num>10)
        return reverseStringRecur(num/10, reverse);
    else
        return reverse;  
}

void fibonacciRecur(int a, int b, int num) {
    std::cout<<b<<"\n";
        if (num == 0)
            return;
        else
            return fibonacciRecur(b, a+b, num-1);
}