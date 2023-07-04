#include <iostream>
#include <map>

int main() {

    int arr[] = {1,2,1,3,2,6,6,6,6,6,5,4,4,4,2,2,0,69,2,2,2};
    int arrLength = sizeof(arr)/sizeof(int);
    int maxKey = 0;
    int maxNum = 0;
    int minKey = 0;
    int minNum = 99999999;
    std::map<int, int> freqMap;

    // int hashArr[72] = {0,0,0,0,0,0,0,0,0,0,0,0};

    for(int i = 0; i != arrLength; i++){
        freqMap[arr[i]] = freqMap[arr[i]] + 1;
    }

    std::map<int, int>::iterator j = freqMap.begin();
    while (j != freqMap.end()) {
        // std::cout<<"The array contains "<<j->first<<" "<<j->second<<" times.\n";
        if((j->second)>maxNum)
            {
                maxKey = j -> first;
                maxNum = j-> second;
            }
        ++j;
    }
    std::cout<<"The max element is "<<maxKey<<" and is there "<<maxNum<<" times.\n";

    std::map<int, int>::iterator k = freqMap.begin();
    while (k != freqMap.end()) {
        // std::cout<<"The array contains "<<j->first<<" "<<j->second<<" times.\n";
        if((k->second)<minNum)
            {
                minKey = k -> first;
                minNum = k-> second;
            }
        ++k;
    }
    std::cout<<"The min element is "<<minKey<<" and is there "<<minNum<<" times.\n";

    return 0;

}
