#include "sll.h"
#include <iostream>

void Create_List(List &L) {
    first(L) = NULL;
}

address New_Elemen(infotype data) {
    address p = new elmlist;
    info(p) = data;
    next(p) = NULL;
    return p;
}

void Insert_First(List &L, address p) {
    if (first(L) == NULL) {
        first(L) = p;
    } else {
        next(p) = first(L);
        first(L) = p;
    }
}

void Insert_Last(List &L, address p) {
    if (first(L) == NULL) {
        first(L) = p;
    } else {
        address currP = first(L);
        while (next(currP) != NULL) {
            currP = next(currP);
        }
        next(currP) = p;
    }
}

void Insert_After(List &L, address prec, address p) {
    if (next(prec) == NULL) {
        Insert_Last(L, p);
    } else {
        next(p) = next(prec);
        next(prec) = p;
    }
}

void Delete_First(List &L, address &p) {
    if (first(L) != NULL) {
        p = first(L);
        first(L) = next(first(L));
        next(p) = NULL;
    } else {
        p = NULL;
    }
}

void Delete_Last(List &L, address &p) {
    if (first(L) == NULL) {
        p = NULL;
    } else if (next(first(L)) == NULL) {
        p = first(L);
        first(L) = NULL;
    } else {
        address currP = first(L);
        address beforeLastP = NULL;
        while (next(currP) != NULL) {
            beforeLastP = currP;
            currP = next(currP);
        }
        p = currP;
        next(beforeLastP) = NULL;
    }
}

void Delete_After(List &L, address prec, address &p) {
    if (next(prec) != NULL) {
        p = next(prec);
        next(prec) = next(p);
        next(p) = NULL;
    } else {
        p = NULL;
    }
}

void Show(List L) {
    if (first(L) == NULL) {
        cout << "List kosong" << endl;
    } else {
        address lp = first(L);
        while (lp != NULL) {
            cout << "Kode Matkul: " << info(lp).kode << endl;
            cout << "Nama Matkul: " << info(lp).nama << endl;
            cout << "Jumlah SKS: " << info(lp).sks << endl;
            cout << endl;
            lp = next(lp);
        }
    }
}

void SortByJumlahSKSAscending(List &L) {
    if (first(L) == NULL || next(first(L)) == NULL) {
        cout << "List kosong atau hanya memiliki satu elemen" << endl;
        return;
    }

    List sorted;
    Create_List(sorted);

    while (first(L) != NULL) {
        // Remove first element from original list
        address current = first(L);
        first(L) = next(first(L));
        next(current) = NULL;

        // Insert into sorted list
        if (first(sorted) == NULL || info(first(sorted)).sks >= info(current).sks) {
            // Insert at beginning of sorted list
            next(current) = first(sorted);
            first(sorted) = current;
        } else {
            // Find position to insert
            address temp = first(sorted);
            while (next(temp) != NULL && info(next(temp)).sks < info(current).sks) {
                temp = next(temp);
            }
            next(current) = next(temp);
            next(temp) = current;
        }
    }

    // Copy sorted list back to original list
    first(L) = first(sorted);
}

void SearchByKode(List L, string data, bool &isFound) {
    if (first(L) == NULL) {
        cout << "List kosong" << endl;
        isFound = false;
        return;
    }

    address current = first(L);
    while (current != NULL && info(current).kode != data) {
        current = next(current);
    }

    if (current != NULL && info(current).kode == data) {
        cout << "Matkul dengan Kode " << data << " ditemukan: " << info(current).nama << endl;
        isFound = true;
    } else {
        cout << "Matkul tak dapat ditemukan" << endl;
        isFound = false;
    }
}
