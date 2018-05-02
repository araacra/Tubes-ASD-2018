#ifndef LISTPENULIS_H_INCLUDED
#define LISTPENULIS_H_INCLUDED
#include <stdio.h>
#include <iostream>
#include <cstddef>

#define Nil NULL
#define next(p) p->next
#define first(l) l.first
#define info_p(p) p->info_p
#include <string>
using namespace std;


typedef struct datapenulis infotype_p;
typedef struct elmlist_penulis *address_p;

struct datapenulis{
    string nama_penulis;
    int umur;
    int status=0;
};
struct elmlist_penulis {
    address_p next;
    infotype_p info_p;
    };
struct list_p{
    address_p first;
};

void createlistP(list_p &l);
address_p alokasiP(infotype_p x);
void dealokasiP(address_p &p);
void insertP(list_p &l, address_p p);
void deletefirstP(list_p &l, address_p &p);
void deleteafterP(list_p &l,address_p prec, address_p &p);
void deletelastP(list_p &l, address_p &p);
void deleteP(list_p &l, infotype_p x);
address_p findP(list_p l, infotype_p x);
void printinfoP(list_p l);
#endif // LISTPENULIS_H_INCLUDED
