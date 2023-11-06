#include <bits/stdc++.h>
using namespace std;
int N = 100;
ofstream out("wynik2.txt");
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

int maxCube (vector<int> ciag){
    int max = 0;
        for (int j = 0; j<ciag.size(); j++) {
            int root = cbrt(ciag[j]);
            if (root*root*root == ciag[j]) {
                max = (ciag[j]>max) ? ciag[j] : max;                
            }
        }
    return max;
}

void zad2() {
    for (int i = 0; i<N; i++) {
        if (maxCube(ciagi[i]) > 0) {
            out << maxCube(ciagi[i]) << "\n";
        }
    }
}

int main() {
    wczyt();
    out << "Zadanie 2:\n";
    zad2();
    out.close();
    return 0;
}