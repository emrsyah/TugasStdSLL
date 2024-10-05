#include "sll.h"
#include <iostream>

using namespace std;

int main() {
    List mha;
    infotype inputData;
    address ptr1, ptr2, ptr3, ptr4, ptr5, ptr6, tmp1, tmp2;
    bool isFound;

    Create_List(mha);

    // Input data pertama
    cout << "Masukkan data pertama:" << endl;
    cout << "Kode Matkul: "; cin >> inputData.kode;
    cout << "Nama Matkul: "; cin >> inputData.nama;
    cout << "Jumlah SKS: "; cin >> inputData.sks;

    ptr1 = New_Elemen(inputData);
    Insert_First(mha, ptr1);

    // Input data kedua
    cout << "\nMasukkan data kedua:" << endl;
    cout << "Kode Matkul: "; cin >> inputData.kode;
    cout << "Nama Matkul: "; cin >> inputData.nama;
    cout << "Jumlah SKS: "; cin >> inputData.sks;

    ptr2 = New_Elemen(inputData);
    Insert_Last(mha, ptr2);

    // Input data ketiga
    cout << "\nMasukkan data ketiga:" << endl;
    cout << "Kode Matkul: "; cin >> inputData.kode;
    cout << "Nama Matkul: "; cin >> inputData.nama;
    cout << "Jumlah SKS: "; cin >> inputData.sks;

    ptr3 = New_Elemen(inputData);
    Insert_First(mha, ptr3);

    // Input data keempat
    cout << "\nMasukkan data keempat:" << endl;
    cout << "Kode Matkul: "; cin >> inputData.kode;
    cout << "Nama Matkul: "; cin >> inputData.nama;
    cout << "Jumlah SKS: "; cin >> inputData.sks;

    ptr4 = New_Elemen(inputData);
    Insert_First(mha, ptr4);

    // Input data kelima
    cout << "\nMasukkan data kelima:" << endl;
    cout << "Kode Matkul: "; cin >> inputData.kode;
    cout << "Nama Matkul: "; cin >> inputData.nama;
    cout << "Jumlah SKS: "; cin >> inputData.sks;

    ptr5 = New_Elemen(inputData);
    Insert_After(mha, ptr4, ptr5);

    // Input data keenam
    cout << "\nMasukkan data keenam:" << endl;
    cout << "Kode Matkul: "; cin >> inputData.kode;
    cout << "Nama Matkul: "; cin >> inputData.nama;
    cout << "Jumlah SKS: "; cin >> inputData.sks;

    ptr6 = New_Elemen(inputData);
    Insert_After(mha, ptr4, ptr6);

    cout << "\nDaftar Mata Kuliah sebelum pengurutan dan penghapusan:" << endl;
    Show(mha);

    // Penghapusan data kedua
    Delete_After(mha, ptr1, tmp1);

    // Penghapusan data keenam
    isFound = false;
    SearchByKode(mha, info(ptr6).kode, isFound);
    if (isFound) {
        Delete_After(mha, ptr4, tmp2);
    }

    cout << "\nMengurut berdasarkan jumlah SKS..." << endl;
    SortByJumlahSKSAscending(mha);

    cout << "\nDaftar Mata Kuliah setelah pengurutan dan penghapusan:" << endl;
    Show(mha);

    return 0;
}
