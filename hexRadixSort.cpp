#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int getDigit(int num, int sortedTime, int radix) {
    int digit = 1;
    while (sortedTime-- > 0) digit *= radix;

    return num / digit % radix;
}

int getDigitHex(int num, int sortedTime) {
    // 4 bit
    sortedTime *= 4;
    return (num & (0xF << sortedTime)) >> sortedTime;
}

void radixSort(int radix, vector<int> &v) {
    vector<int> bucket[radix];

    int sortingTime = (32.0 * log(2) / log(radix));

    for (int sorted = 0; sorted < sortingTime; sorted++) {
        // put to bucket
        for (int i = 0; i < v.size(); i++)
            if (radix == 16)
                bucket[getDigitHex(v[i], sorted)].push_back(v[i]);
            else
                bucket[getDigit(v[i], sorted, radix)].push_back(v[i]);

        // put to back
        int count = 0;
        for (int i = 0; i < radix; i++)
            for (int j = 0; j < bucket[i].size(); j++)
                v[count++] = bucket[i][j];

        // clean buckets
        for (int i = 0; i < radix; i++) bucket[i].clear();
    }
}

void genVector(vector<int> &v, int size) {
    for (; size > 0; size--) v.push_back(rand() % 100000);
}

clock_t time1;

void timingStart() { time1 = clock(); }

void timingEnd() {
    time1 = clock() - time1;
    cout << "cost:" << time1 << endl;
}

int main() {
    vector<int> v, sortv;

    genVector(v, 100000);

    // decimal radix
    sortv = v;
    timingStart();
    radixSort(10, sortv);
    timingEnd();
    // for (auto i : sortv) cout << setw(10) << i << endl;

    // hex radix
    sortv = v;
    timingStart();
    radixSort(16, sortv);
    timingEnd();
    // for (auto i : sortv) cout << setw(10) << i << endl;

    return 0;
}
