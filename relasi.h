#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include "listbuku.h"
#include "relasi.h"
#include "listpenulis.h"
#include <iostream>


#define next(p) p->next
#define first(l) l.first
#define buku(p) p->buku
#define penulis(p) p->penulis

using namespace std;
typedef struct elmlist_relasi *address_r;

struct elmlist_relasi{
    address_b buku;
    address_p penulis;
    address_r next;
};

struct list_r{
    address_r first;
};

void createlistR(list_r &l);
address_r alokasiR(address_b x, address_p y);
void dealokasiR(address_r &p);
void insertR(list_r &l, address_r p);
void deleteR(list_r &l, address_b p, address_p q);
void deleteRKhusus(list_r &l, address_b b, address_p p);
void deleteRB(list_r &l, list_b &p, infotype_b x);
void deleteRP(list_r &l, list_p &q,infotype_p x);
address_r findelmR(list_r l, address_b b, address_p p);
void printinfoR(list_r l);
void printinfoRB(list_r l, address_p p);
void printinfoRP(list_r l, address_b b);


#endif // RELASI_H_INCLUDED
