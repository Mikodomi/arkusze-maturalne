#include <bits/stdc++.h>
using namespace std;
int N = 20;
ofstream out("wynik3.txt");
vector<int> ciagi[20];
ifstream in("bledne.txt");

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

int blad(vector<int> ciag) {
    if (ciag[1]-ciag[0] != ciag[2]-ciag[1]) {
        if (ciag[4]-ciag[3] == ciag[1]-ciag[0]) {
            return ciag[2];
        }
        else if (ciag[4]-ciag[3] == ciag[2]-ciag[1]) {
            return ciag[0];
        }
        else {
            return ciag[1];
        }
    }
    int roznica = ciag[1]-ciag[0];
    for (int i = 1; i<ciag.size(); i++) {
        if (ciag[i] - ciag[i-1] != roznica) {
            return ciag[i];
        }
    }
    return ciag[ciag.size()];
}

void zad3() {
    for (int i = 0; i<N; i++) {
        out << blad(ciagi[i]) << "\n";
    }
}
int main() {
    wczyt();
    out << "Zadanie 3:\n";
    zad3();
    out.close();
    return 0;
}