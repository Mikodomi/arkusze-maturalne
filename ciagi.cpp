#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int N = 100;
ofstream out("wynik1.txt");
vector<int> ciagi[100];
ifstream in("ciagi.txt");

void wczyt() {
    for (int i = 0; i<N; i++) {
        int n, a;
        in >> n;
        for (int j = 0; j<n; j++) {
            in >> a;
            ciagi[i].push_back(a);
        }
    }
}

pair<bool, int> czyAr(vector<int> ciag) {
    int r = ciag[1]-ciag[0];
    for (int i = 1; i<ciag.size(); i++) {
        if (ciag[i]-ciag[i-1] != r) {
            return {false, 0};
        }
    }
    return {true, r};
}

void zad1() {
    int suma = 0, top = 0;
    for (int i = 0; i<N; i++) {
        if (czyAr(ciagi[i]).first) {
            // cout << i << " ";
            suma++;
            if (czyAr(ciagi[i]).second > top) {
                top = czyAr(ciagi[i]).second;
            }
        }
    }
    out << suma << " " << top << "\n";
}

int main() {
    wczyt();
    out << "Zadanie 1:\n";
    zad1();
    // vector<int> vect{ 668, 88156, 175644 ,263132, 350620, 438108 ,525596 ,613084 ,700572 ,788060, 875548};
    // cout << czyAr(vect).first << " " << czyAr(vect).second;
    out.close();
    // for (int i = 0; i<10; i++) {
    //     for (auto el: ciagi[i]) {
    //         cout << el << " ";
    //     }
    //     cout << "\n";
    // }
    return 0;
}