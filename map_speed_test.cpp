/********** Map Speed Test **********
* By: Öner Morkoç                   *
* Last Update: 24/01/2023           *
************************************/

# include <map>
# include <iostream>
# include <sys/time.h>
# include "./Sources/Containers/map.hpp"

# define SIZE 1000000 // 1M
# define RED "\e[31m"
# define GREEN "\e[32m"
# define WHITE "\e[97m"
# define YELLOW "\e[33m"

using namespace std;

long getTime(void){
    struct timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void printResult(long timeStd, long timeFt){
    cout << "Std: " << timeStd << "ms" << endl;
    cout << "Ft: " << timeFt << "ms" << endl;
    if (timeStd == 0)
        timeStd = 1;
    if(timeFt <= timeStd * 20)
        cout << "Status: " << GREEN << "OK" << WHITE << endl;
    else
        cout << "Status: " << RED << "K0" << WHITE << endl;
}

template<typename T, typename P>
long mapInsert(void){
    T map;
    long start = getTime();
    for(int i = 0; i < SIZE; i++){
        time(NULL);
        map.insert(P(rand(), rand()));
    }
    return (getTime() - start);
}

template<typename T, typename P>
long mapInsertV2(void){
    T map;
    T map2;
    for(int i = 0; i < SIZE; i++){
        time(NULL);
        map.insert(P(rand(), rand()));
    }
    long start = getTime();
    map2.insert(map.begin(), map.end());
    return (getTime() - start);
}

template<typename T, typename P>
long mapFind(void){
    T map;
    T map2;
    for(int i = 0; i < SIZE; i++){
        time(NULL);
        int number = rand();
        map.insert(P(number, number));
        if(i % 2 == 1)
            map2.insert(P(number, number));
    }
    long start = getTime();
    auto first = map2.begin();
    while(first != map2.end())
        map.find((first++)->first);
    return (getTime() - start);
}

template<typename T, typename P>
long mapCopy(void){
    T map;
    T map2;
    for(int i = 0; i < SIZE; i++){
        time(NULL);
        map.insert(P(rand(), rand()));
    }
    long start = getTime();
    map2 = map;
    return (getTime() - start);
}

template<typename T, typename P>
long mapErase(void){
    T map;
    int root;
    for(int i = 0; i < SIZE; i++){
        time(NULL);
        int number = rand();
        map.insert(P(number, number));
        if(i == 0)
            root = number;
    }
    long start = getTime();
    map.erase(root);
    return (getTime() - start);
}

template<typename T, typename P>
long mapEraseV2(void){
    T map;
    int pox;
    for(int i = 0; i < SIZE; i++){
        time(NULL);
        int number = rand();
        map.insert(P(number, number));
        if (i == SIZE / 3)
            pox = number;
    }
    long start = getTime();
    map.erase(map.find(pox), map.end());
    return (getTime() - start);
}

template<typename T, typename P>
long mapClear(void){
    T map;
    for(int i = 0; i < SIZE; i++){
        time(NULL);
        map.insert(P(rand(), rand()));
    }
    long start = getTime();
    map.clear();
    return (getTime() - start);
}

template<typename T, typename P>
long mapEqualRange(void){
    T map;
    int pox;
    for(int i = 0; i < SIZE; i++){
        time(NULL);
        int number = rand();
        map.insert(P(number, number));
        if(i == SIZE / 2)
            pox = number;
    }
    long start = getTime();
    map.equal_range(pox + 42);
    return (getTime() - start);
}

int main(void){

    cout << endl << RED <<"########################## => Test Map <= ##########################" << endl << endl;
    cout << YELLOW << "*************************** => Insert <= ***************************" << WHITE << endl;
    printResult(mapInsert<std::map<int, int>, std::pair<int, int> >(), mapInsert<ft::map<int, int>, ft::pair<int, int> >());

    //cout << YELLOW << "************************** => Insert v2 <= *************************" << WHITE << endl;
    //printResult(mapInsertV2<std::map<int, int>, std::pair<int, int> >(), mapInsertV2<ft::map<int, int>, ft::pair<int, int> >());
    
    cout << YELLOW << "**************************** => Find <= ****************************" << WHITE << endl;
    printResult(mapFind<std::map<int, int>, std::pair<int, int> >(), mapFind<ft::map<int, int>, ft::pair<int, int> >());

    cout << YELLOW << "*************************** => Copy(=) <= **************************" << WHITE << endl;
    printResult(mapCopy<std::map<int, int>, std::pair<int, int> >(), mapCopy<ft::map<int, int>, ft::pair<int, int> >());

    cout << YELLOW << "**************************** => Erase <= ***************************" << WHITE << endl;
    printResult(mapErase<std::map<int, int>, std::pair<int, int> >(), mapErase<ft::map<int, int>, ft::pair<int, int> >());

    cout << YELLOW << "************************** => Erase v2 <= **************************" << WHITE << endl;
    printResult(mapEraseV2<std::map<int, int>, std::pair<int, int> >(), mapEraseV2<ft::map<int, int>, ft::pair<int, int> >());

    cout << YELLOW << "**************************** => Clear <= ***************************" << WHITE << endl;
    printResult(mapClear<std::map<int, int>, std::pair<int, int> >(), mapClear<ft::map<int, int>, ft::pair<int, int> >());

    cout << YELLOW << "************************* => Equal range <= ************************" << WHITE << endl;
    printResult(mapEqualRange<std::map<int, int>, std::pair<int, int> >(), mapEqualRange<ft::map<int, int>, ft::pair<int, int> >());

    return (0);
}
