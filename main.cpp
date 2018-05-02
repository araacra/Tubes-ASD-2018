#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <iostream>
#include "listbuku.h"
#include "listpenulis.h"
#include "relasi.h"
#include "menu.h"

using namespace std;

int main()
{
    list_b p;
    list_p q;
    list_r r;
    createlistB(p);
    createlistP(q);
    createlistR(r);
    infotype_b ii;
    infotype_p i;
    int a;
    string b,c;
    ii.nama_buku="Merah";
    ii.tahun=2010;
    i.nama_penulis="Budi";
    i.umur=21;
    insertB(p,alokasiB(ii));
    insertP(q,alokasiP(i));
    ii.nama_buku="Putih";
    ii.tahun=2014;
    i.nama_penulis="Gege";
    i.umur=23;
    insertB(p,alokasiB(ii));
    insertP(q,alokasiP(i));


    do{
    system("cls");
        cout<<"#-------------------------#"<<endl;
        cout<<"|      KELOMPOK QUERY     |"<<endl;
        cout<<"#-------------------------#"<<endl;
        cout<<"|                         |"<<endl;
        cout<<"|  Admin            User  |"<<endl;
        cout<<"|   (1)              (2)  |"<<endl;
        cout<<"|                         |"<<endl;
        cout<<"|          Keluar         |"<<endl;
        cout<<"|           (0)           |"<<endl;
        cout<<"#-------------------------#"<<endl;
        cout<<" Masukan Pilihan :  ";
        cin>>a;
        switch (a){
        case 1:
            /*system("cls");
            cout<<"#-------------------------#"<<endl;
            cout<<"|      KELOMPOK QUERY     |"<<endl;
            cout<<"#-------------------------#"<<endl;
            cout<<"                           "<<endl;
            cout<<"  Username : ";
            cin>>b;
            cout<<"  Password : ";
            cin>>c;
            if(b=="admin" && c=="admin"){*/
                    menuadmin(p,q,r);
            //}
            //else{
              //  menuuser(p,q,r);
            //}
            break;
        case 2:
            menuuser(p,q,r);
            break;
        }
    }while(a!=0);
    system("cls");
    cout<<"#-------------------------#"<<endl;
    cout<<"|      Terima Kasih       |"<<endl;
    cout<<"#-------------------------#"<<endl;
    return 0;
}


