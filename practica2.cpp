#include <iostream>
#include <fstream>
#include <cstring>
#include "ZNAK.h"
#include "My_Array.h"
using namespace std;

const int m = 10; 

void createHashTable(int hashTable[][2], My_Array<Znak>& arr) {
    
    for (int i = 0; i < m; i++) {
        hashTable[i][0] = -1; 
    }

    for (int i = 0; i < 8; i++) {
        Znak& z = arr[i];
        int key = z.data[0] + z.data[1] + z.data[2]; 
        int hash = key % m; 

        int i1 = 0;
        int j;
        while (true) {
            j = (hash + i1 * i1) % m;
            if (hashTable[j][0] == -1) break;
            i1++;
        }

        hashTable[j][0] = key;
        hashTable[j][1] = i; 
    }
}

// Поиск в хеш-таблице
int searchHashTable(int hashTable[][2], int day, int month, int year) {
    int key = day + month + year;
    int hash = key % m;

    int i1 = 0;
    int j;
    while (true) {
        j = (hash + i1 * i1) % m;
        if (hashTable[j][0] == key) break;
        if (hashTable[j][0] == -1) return -1;
        i1++;
    }

    return hashTable[j][1];
}

int main() {
    My_Array<Znak> arr;
    ifstream in("text.txt");
    if (!in) {
        cout << "\n not open \n";
        return 1;
    }

    in >> arr;
    cout << arr;

    arr.sort(Znak::compZodiak);
    cout << "\nafter sort\n" << arr;

    // Запись в двоичный файл
    ofstream outbin("a.bin", ios_base::binary);
    arr.writeBin(outbin);

    // Создание хеш-таблицы
    int hashTable[m][2];
    createHashTable(hashTable, arr);

    // Вывод хеш-таблицы
    for (int i = 0; i < m; i++) {
        cout << i << ": " << hashTable[i][0] << " " << hashTable[i][1] << "\n";
    }

   
    int day, month, year;
    cout << "\nEnter data: ";
    cin >> day >> month >> year;

    int index = searchHashTable(hashTable, day, month, year);
    if (index != -1) {
        cout << index << ":\n";
        cout << arr[index] << "\n";
    }else {
        cout << "\n No \n";
    }

    return 0;
}

//#include <iostream>
//#include <fstream>
//#include <ios>
//#include <string.h>
//#include "ZNAK.h"
//#include "My_Array.h"
////#include "MyList.h" 
//using namespace std;
//void printArr(int* a, int n) {
//    for (int i = 0; i < n; i++)
//        cout << a[i] << " ";
//}
//
//const int m = 10;
//void createHashTable(int hashTable[][2], int in[6][2], int n) {
//    int j;
//    for (int i = 0; i < m; i++)hashTable[i][0] = -1;
//    for (int i = 0; i < n; i++) {
//        int i1 = 0;
//        int k = in[i][0];
//        while (true) {
//            j = (k + i1 * i1) % m;
//            if (hashTable[j][0] == -1)break;
//            i1++;
//        }
//        hashTable[j][0] = k;
//        hashTable[j][1] = in[i][1];
//    }
//}
//int search(int hashTable[][2], int key) {
//    int i1 = 0;
//    int j;
//    while (true) {
//        j = (key + i1 * i1) % m;
//        if (hashTable[j][0] == key)break;
//        i1++;
//    }
//
//    return  hashTable[j][1];
//}
//
//int main()
//{    
//    My_Array<Znak> arr;
//    ifstream in("text.txt");
//    if (!in)cout << "\nfile not open\n";
//    in >> arr;
//    cout << arr;
//    ofstream outbin("a.bin", ios_base::binary);
//    arr.writeBin(outbin);
//    ifstream inbin("a.bin", ios_base::binary);
//    
//
//    int in[6][2] = { 2002,0,1914,1,1939,2,1945,3,1953,4,1944,5 };
//    for (int i = 0; i < 6; i++) {
//        cout << in[i][0] << " " << in[i][1] << "\n";
//    }
//    cout << "\n";
//    int hashTable[m][2];
//    createHashTable(hashTable, in, 6);
//    for (int i = 0; i < m; i++) {
//        cout << hashTable[i][0] << " " << hashTable[i][1] << "\n";
//    }
//    int index = search(hashTable, 1944);
//    cout << "index = " << index;
//    return 0;
//}


