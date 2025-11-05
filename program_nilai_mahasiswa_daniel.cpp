#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct studentType {
    string studentFName;   
    string studentLName;   
    int testScore;         
    char grade;            
};

void getData(studentType s[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Masukkan nama depan mahasiswa ke-" << i + 1 << ": ";
        cin >> s[i].studentFName;
        cout << "Masukkan nama belakang mahasiswa ke-" << i + 1 << ": ";
        cin >> s[i].studentLName;
        cout << "Masukkan nilai ujian (0–100): ";
        cin >> s[i].testScore;

        if (s[i].testScore < 0) s[i].testScore = 0;
        if (s[i].testScore > 100) s[i].testScore = 100;

        cout << endl;
    }
}

void assignGrade(studentType s[], int n) {
    for (int i = 0; i < n; i++) {
        int skor = s[i].testScore;
        if (skor >= 90)
            s[i].grade = 'A';
        else if (skor >= 80)
            s[i].grade = 'B';
        else if (skor >= 70)
            s[i].grade = 'C';
        else if (skor >= 60)
            s[i].grade = 'D';
        else
            s[i].grade = 'F';
    }
}

int cariNilaiTertinggi(studentType s[], int n) {
    int tertinggi = s[0].testScore;
    for (int i = 1; i < n; i++)
        if (s[i].testScore > tertinggi)
            tertinggi = s[i].testScore;
    return tertinggi;
}

void tampilkanHasil(studentType s[], int n, int tertinggi) {
    cout << "--------------------------------------------------\n";
    cout << left << setw(25) << "Nama" << setw(10) << "Nilai" << "Huruf\n";
    cout << "--------------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        string namaLengkap = s[i].studentLName + ", " + s[i].studentFName;
        cout << left << setw(25) << namaLengkap
             << setw(10) << s[i].testScore
             << s[i].grade << endl;
    }

    cout << "--------------------------------------------------\n";
    cout << "Nilai ujian tertinggi: " << tertinggi << endl;
    cout << "Mahasiswa dengan nilai tertinggi:\n";

    for (int i = 0; i < n; i++)
        if (s[i].testScore == tertinggi)
            cout << "- " << s[i].studentFName << " " << s[i].studentLName << endl;

    cout << "--------------------------------------------------\n";
}

int main() {
    const int jumlahMahasiswa = 8;
    studentType mahasiswa[jumlahMahasiswa] = {
        {"Evan", "Siregar", 87},
        {"Ramos", "Sinaga", 91},
        {"Dzakwan", "Hutapea", 75},
        {"Mikhail", "Mendrofa", 60},
        {"Ozaki", "Manurung", 92},
        {"Daniel", "Panggabean", 95}, 
        {"Ali", "Situmorang", 85},
        {"Wildan", "Hutabarat", 87}
    };

    assignGrade(mahasiswa, jumlahMahasiswa);
    int tertinggi = cariNilaiTertinggi(mahasiswa, jumlahMahasiswa);
    tampilkanHasil(mahasiswa, jumlahMahasiswa, tertinggi);

    return 0;
}
