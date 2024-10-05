#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED

#include <string>
using namespace std;

struct Matkul {
    string kode;
    string nama;
    int sks;
};

typedef Matkul infotype;
typedef struct elmlist *address;

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

struct elmlist {
    infotype info;
    address next;
};

struct List {
    address first;
};

void Create_List(List &L);
address New_Elemen(infotype data);
void Insert_First(List &L, address p);
void Insert_Last(List &L, address p);
void Insert_After(List &L, address prec, address p);
void Delete_First(List &L, address &p);
void Delete_Last(List &L, address &p);
void Delete_After(List &L, address prec, address &p);
void Show(List L);
void SortByJumlahSKSAscending(List &L);
void SearchByKode(List L, string data, bool &isFound);

#endif // SLL_H_INCLUDED
