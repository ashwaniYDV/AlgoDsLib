#include<iostream>
#include "Vector.h"

template<typename T>
void PrintVector(const Vector<T>& vector) {
    for (size_t i = 0; i < vector.Size(); i++) {
        std::cout << vector[i] << std::endl;
    }
    std::cout << "------------------" << std::endl;
}

struct st {
    int a, b;
};

int main() {
    Vector<std::string> data1;
    data1.PushBack("ashwani");
    data1.PushBack("yadav");
    data1.EmplaceBack("C++");
    std::cout << data1.Size() << std::endl;
    PrintVector(data1);
    data1.PopBack();
    std::cout << data1.Size() << std::endl;
    PrintVector(data1);
    data1.Clear();
    std::cout << data1.Size() << std::endl;
    PrintVector(data1);

    std::cout << std::endl << std::endl;

    Vector<std::string> data2(3);
    std::cout << data2.Size() << std::endl;
    PrintVector(data2);
    data2[0] = "ashwani";
    data2[1] = "yadav";
    data2[2] = "C++";
    std::cout << data2.Size() << std::endl;
    PrintVector(data2);
    data2.EmplaceBack("C");
    data2.PushBack("Java");
    std::cout << data2.Size() << std::endl;
    PrintVector(data2);

    std::cout << std::endl << std::endl;

    Vector<st> data3;
    st structData = {3, 4};
    data3.PushBack({1, 2});
    data3.PushBack({3, 4});
    data3.PushBack({1, 2});
    data3.EmplaceBack((st){3, 4});
    data3.EmplaceBack(structData);
    std::cout << data3.Size() << std::endl;
    for(int i = 0; i < data3.Size(); ++i) {
        std::cout << data3[i].a << " " << data3[i].b << std::endl;
    }
    return 0;
}




/*
Output:
3
ashwani
yadav
C++
------------------
2
ashwani
yadav
------------------
0
------------------
3
------------------
3
ashwani
yadav
C++
------------------
5
ashwani
yadav
C++
C
Java
------------------
5
1 2
3 4
1 2
3 4
3 4
*/
