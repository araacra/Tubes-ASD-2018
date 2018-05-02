#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
#include "listbuku.h"
#include "listpenulis.h"
#include "relasi.h"

using namespace std;

void menuadmin(list_b &p,list_p &q, list_r &r);
void menuuser(list_b &p,list_p &q, list_r &r);
void menuinput(list_b &p,list_p &q, list_r &r);
void menuhapus(list_b &p,list_p &q,list_r &s);
void menulihat(list_b p,list_p q, list_r r);
void penulisaktif (list_b &b,list_p &q, list_r &s);

#endif // MENU_H_INCLUDED
