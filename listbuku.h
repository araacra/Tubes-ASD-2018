#ifndef LISTBUKU_H_INCLUDED
#define LISTBUKU_H_INCLUDED
#include <stdio.h>
#include <iostream>
#include <cstddef>

#define Nil NULL
#define next(p) p->next
#define prev(p) p->prev
#define first(l) l.first
#define last(l) l.last
#define info_b(p) p->info_b

#include <string>

using namespace std;

typedef struct databuku infotype_b;
typedef struct elmlist_buku *address_b;

struct databuku{
    string nama_buku;
    int tahun;
};

struct elmlist_buku{
    infotype_b info_b;
    address_b next;
    address_b prev;
};

struct list_b{
    address_b first;
    address_b last;
};

void createlistB(list_b &l);
address_b alokasiB(infotype_b x);
void dealokasiB(address_b &p);
void insertB(list_b &l, address_b p);
void deletefirstB(list_b &l, address_b &p);
void deleteafterB(list_b &l,address_b prec, address_b &p);
void deletelastB(list_b &l, address_b &p);
address_b findbukuB(list_b l, infotype_b x);
void printinfoB(list_b l);
void deleteB(list_b &l, infotype_b x);


#endif // LISTBUKU_H_INCLUDED
