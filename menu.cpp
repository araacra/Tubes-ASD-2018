#include "menu.h"
#include "listbuku.h"
#include "listpenulis.h"
#include "relasi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

using namespace std;

void menulihat(list_b p,list_p q, list_r r){
     int a,c;
     char b[100],d[100];
     address_b bk;
     address_p pn;
     infotype_b ii;
     infotype_p i;
     do{
         system("cls");
         cout<<"#-------------------------#"<<endl;
         cout<<"|      KELOMPOK QUERY     |"<<endl;
         cout<<"#-------------------------#"<<endl;
         cout<<"|                         |"<<endl;
         cout<<"|   1. Data Buku          |"<<endl;
         cout<<"|   2. Data Penulis       |"<<endl;
         cout<<"|   0. Kembali            |"<<endl;
         cout<<"|                         |"<<endl;
         cout<<"#-------------------------#"<<endl;
         cout<<" Masukan Pilihan : ";
         cin>>a;
         switch (a){
                case 1 :
                    system("cls");
                    cout<<"#------------------------------------#"<<endl;
                    cout<<"|            KELOMPOK QUERY          |"<<endl;
                    cout<<"#------------------------------------#"<<endl;
                    cout<<"|            [ DATA BUKU ]           |"<<endl;
                    cout<<"                                      "<<endl;
                    cout<<" Buku : "<<endl;
                    printinfoB(p);
                    cout<<endl;
                    if (first(p)==Nil){
                            cout<<"                                     "<<endl;
                            cout<<"         Tekan 0 untuk kembali       "<<endl;
                            cout<<"#------------------------------------#"<<endl;
                            getche();
                    }
                    else{
                            cout<<" Lihat nama penulis dari buku : ";
                            cin.ignore();
                            cin.getline(b,100);
                            ii.nama_buku = b;
                            if (findbukuB(p,ii)!=Nil){
                                cout<<endl;
                                cout<<" "<<ii.nama_buku<<endl;
                                printinfoRP(r, findbukuB(p,ii));
                                if (first(r)!=Nil){
                                    cout<<" Ingin lihat data penulis ?"<<endl;
                                    cout<<"   [1] Ya     [2] Tidak   "<<endl;
                                    cout<<endl;
                                    cout<<" Masukan jawaban : ";
                                    cin>>c;
                                    if (c==1){
                                        cout<<" Nama Penulis : ";
                                        cin.ignore();
                                        cin.getline(d,100);
                                        i.nama_penulis = d;
                                        if (findP(q,i)!=Nil){
                                            pn=findP(q,i);
                                            cout<<endl;
                                            cout<<" Nama penulis : "<<info_p(pn).nama_penulis<<endl;
                                            cout<<" Umur         : "<<info_p(pn).umur<<endl;
                                        }
                                    }
                                }
                            }
                            cout<<"                                     "<<endl;
                            cout<<"         Tekan 0 untuk kembali       "<<endl;
                            cout<<"#------------------------------------#"<<endl;
                            getche();
                    }
                    break;
                case 2 :
                    system("cls");
                    cout<<"#------------------------------------#"<<endl;
                    cout<<"|            KELOMPOK QUERY          |"<<endl;
                    cout<<"#------------------------------------#"<<endl;
                    cout<<"|           [ DATA PENULIS ]         |"<<endl;
                    cout<<"                                      "<<endl;
                    cout<<" Penulis : "<<endl;
                    printinfoP(q);
                    cout<<endl;
                    if (first(q)==Nil){
                        cout<<"                                     "<<endl;
                        cout<<"         Tekan 0 untuk kembali       "<<endl;
                        cout<<"#------------------------------------#"<<endl;
                        getche();
                    }
                    else{
                        cout<<" Lihat nama buku dari penulis : ";
                        cin.ignore();
                        cin.getline(b,100);
                        i.nama_penulis = b;
                        if (findP(q,i)!=Nil){
                            cout<<endl;
                            cout<<" "<<i.nama_penulis<<endl;
                            printinfoRB(r, findP(q,i));
                            if (first(r)!=Nil){
                                cout<<" Ingin lihat data Buku ?"<<endl;
                                cout<<"   [1] Ya     [2] Tidak   "<<endl;
                                cout<<endl;
                                cout<<" Masukan jawaban : ";
                                cin>>c;
                                if (c==1){
                                    cout<<" Judul dari buku : ";
                                    cin.ignore();
                                    cin.getline(d,100);
                                    ii.nama_buku= d;
                                    if (findbukuB(p,ii)!=Nil){
                                        bk=findbukuB(p,ii);
                                        cout<<endl;
                                        cout<<" Judul Buku : "<<info_b(bk).nama_buku<<endl;
                                        cout<<" Tahun      : "<<info_b(bk).tahun<<endl;
                                    }
                                }
                            }
                        }
                        cout<<"                                     "<<endl;
                        cout<<"         Tekan 0 untuk kembali       "<<endl;
                        cout<<"#------------------------------------#"<<endl;
                        getche();
                    }
                    break;
        }
    }while (a!=0);
}

void menuadmin(list_b &p,list_p &q, list_r &r){
    int c;
    do{
        system("cls");
        cout<<"#-------------------------#"<<endl;
        cout<<"|      KELOMPOK QUERY     |"<<endl;
        cout<<"#-------------------------#"<<endl;
        cout<<"|        [ ADMIN ]        |"<<endl;
        cout<<"|                         |"<<endl;
        cout<<"|   1. Input Data         |"<<endl;
        cout<<"|   2. Hapus Data         |"<<endl;
        cout<<"|   3. Lihat Data         |"<<endl;
        cout<<"|   4. Penulis Aktif      |"<<endl;
        cout<<"|   0. Kembali            |"<<endl;
        cout<<"#-------------------------#"<<endl;
        cout<<" Masukan Pilihan : ";
        cin>>c;
        switch (c){
            case 1:
                menuinput(p,q,r);
                break;
            case 2:
                menuhapus(p,q,r);
                break;
            case 3:
                menulihat(p,q,r);
                break;
            case 4:
                penulisaktif(p,q,r);
                break;
        }
    }while(c!=0);
}

void menuuser(list_b &p,list_p &q, list_r &r){
    int a;
    do {
        system("cls");
        cout<<"#-------------------------#"<<endl;
        cout<<"|      KELOMPOK QUERY     |"<<endl;
        cout<<"#-------------------------#"<<endl;
        cout<<"|         [ USER ]        |"<<endl;
        cout<<"|                         |"<<endl;
        cout<<"|  1. Lihat & Cari Data   |"<<endl;
        cout<<"|  2. Penulis Aktif       |"<<endl;
        cout<<"|  0. Kembali             |"<<endl;
        cout<<"#-------------------------#"<<endl;
        cout<<" Masukan Pilihan : ";
        cin>>a;
        switch(a){
            case 1 :
                menulihat(p,q,r);
                break;
            case 2 :
                penulisaktif(p,q,r);
        }
    }while(a!=0);
}

void menuinput(list_b &p,list_p &q,list_r &r){
    int a,c;
    char b[100],d[100],e[100];
    infotype_b ii;
    infotype_p i;
    address_b z;
    address_p x;
    address_r y;
    do{
        system("cls");
        cout<<"#-------------------------#"<<endl;
        cout<<"|      KELOMPOK QUERY     |"<<endl;
        cout<<"#-------------------------#"<<endl;
        cout<<"|      [ INPUT DATA ]     |"<<endl;
        cout<<"|                         |"<<endl;
        cout<<"|   1. Buku               |"<<endl;
        cout<<"|   2. Penulis            |"<<endl;
        cout<<"|   3. Data Relasi        |"<<endl;
        cout<<"|   0. Kembali            |"<<endl;
        cout<<"#-------------------------#"<<endl;
        cout<<" Masukan Pilihan : ";
        cin>>a;
        switch (a){
        case 1:
            system("cls");
            cout<<"#------------------------------------#"<<endl;
            cout<<"|            KELOMPOK QUERY          |"<<endl;
            cout<<"#------------------------------------#"<<endl;
            cout<<"             [ INPUT BUKU ]           "<<endl;
            cout<<"                                      "<<endl;
            cout<<" Judul      :  ";
            cin.ignore();
            cin.getline(b,100);
            ii.nama_buku = b;
            cout<<" Tahun      :  ";
            cin>>ii.tahun;
            z = alokasiB(ii);
            if (first(p)!=Nil){
                insertB(p,z);
            }
            else{
                insertB(p,z);
            }
            cout<<"                                     "<<endl;
            cout<<"         Tekan 0 untuk kembali       "<<endl;
            cout<<"#------------------------------------#"<<endl;
            getche();
            break;
        case 2:
            system("cls");
            cout<<"#------------------------------------#"<<endl;
            cout<<"|            KELOMPOK QUERY          |"<<endl;
            cout<<"#------------------------------------#"<<endl;
            cout<<"            [ INPUT PENULIS ]         "<<endl;
            cout<<"                                      "<<endl;
            cout<<" Nama       :  ";
            cin.ignore();
            cin.getline(b,100);
            i.nama_penulis = b;
            cout<<" Umur       :  ";
            cin>>i.umur;
            x = alokasiP(i);
            if(first(q)==Nil){
                insertP(q,x);
            }
            else{
                insertP(q,x);
            }
            cout<<"                                     "<<endl;
            cout<<"         Tekan 0 untuk kembali       "<<endl;
            cout<<"#------------------------------------#"<<endl;
            getche();
            break;
        case 3:
            system("cls");
            cout<<"#------------------------------------#"<<endl;
            cout<<"|            KELOMPOK QUERY          |"<<endl;
            cout<<"#------------------------------------#"<<endl;
            cout<<"                [ DATA ]              "<<endl;
            cout<<" Buku    : "<<endl;
            printinfoB(p);
            cout<<endl;
            cout<<" Penulis : "<<endl;
            printinfoP(q);
            cout<<endl;
            cout<<" [1] Buku-Penulis  [2] Penulis - Buku "<<endl;
            cout<<endl;
            cout<<" Masukan Pilihan : ";
            cin>>c;
            switch(c){
            case 1:
                cout<<" Masukan Judul         : ";
                cin.ignore();
                cin.getline(d,100);
                ii.nama_buku = d;
                z = findbukuB(p,ii);
                if (z==Nil){
                        cout<<" Nama buku "<<ii.nama_buku<<" Belum Terdaftar"<<endl;}
                else{
                        cout<<" Masukan Nama Penulis  : ";
                        cin.getline(e,100);
                        i.nama_penulis = e;
                        x = findP(q,i);
                        if (x==Nil){
                            cout<<" Nama penulis "<<i.nama_penulis<<" Belum Terdaftar"<<endl;}
                        else{
                            y = findelmR(r,z,x);
                            if (y==Nil){
                                info_p(x).status=info_p(x).status+1;
                                address_r e = alokasiR(findbukuB(p,ii),findP(q,i));
                                insertR(r,e);
                                cout<<endl;
                                cout<<"       Data Berhasil Diinputkan      "<<endl;
                            }
                            else{
                                cout<<endl;
                                cout<<"     Data sudah terdaftar    "<<endl;
                            }
                        }
                }
                break;
            case 2:
                cout<<" Masukan Nama Penulis  : ";
                cin.ignore();
                cin.getline(e,100);
                i.nama_penulis = e;
                x = findP(q,i);
                if (x==Nil){
                    cout<<" Nama penulis "<<i.nama_penulis<<" Belum Terdaftar"<<endl;}
                else{
                    cout<<" Masukan Judul         : ";
                    cin.getline(d,100);
                    ii.nama_buku = d;
                    z = findbukuB(p,ii);
                    if (z==Nil){
                        cout<<" Nama buku "<<ii.nama_buku<<" Belum Terdaftar"<<endl;}
                    else{
                        y=findelmR(r,z,x);
                        if (y==Nil){
                            info_p(x).status=info_p(x).status+1;
                            address_r e = alokasiR(findbukuB(p,ii),findP(q,i));
                            insertR(r,e);
                            cout<<endl;
                            cout<<"       Data Berhasil Diinputkan      "<<endl;
                        }
                        else{
                            cout<<endl;
                            cout<<"     Data sudah terdaftar        "<<endl;
                        }
                        }
                }
                break;
        }
        cout<<"                                     "<<endl;
        cout<<"         Tekan 0 untuk kembali       "<<endl;
        cout<<"#------------------------------------#"<<endl;
        getche();
        break;
    }
    }while(a!=0);
}


void menuhapus(list_b &p,list_p &q,list_r &s){
    int a,d,e;
    char b[100],c[100];
    infotype_b ii;
    infotype_p i;
    address_b y;
    address_p z;
    address_r r;
    do{
        system("cls");
        cout<<"#-------------------------#"<<endl;
        cout<<"|      KELOMPOK QUERY     |"<<endl;
        cout<<"#-------------------------#"<<endl;
        cout<<"|     [ DELETE DATA ]     |"<<endl;
        cout<<"|                         |"<<endl;
        cout<<"|   1. Relasi             |"<<endl;
        cout<<"|   2. Buku               |"<<endl;
        cout<<"|   3. Penulis            |"<<endl;
        cout<<"|   0. Kembali            |"<<endl;
        cout<<"|                         |"<<endl;
        cout<<"#-------------------------#"<<endl;
        cout<<" Masukan Pilihan : ";
        cin>>a;
        switch (a){
        case 1:
            do{
            system("cls");
            cout<<"#-------------------------#"<<endl;
            cout<<"|      KELOMPOK QUERY     |"<<endl;
            cout<<"#-------------------------#"<<endl;
            cout<<"|     [ DELETE DATA ]     |"<<endl;
            cout<<"|                         |"<<endl;
            cout<<"|   1. Buku               |"<<endl;
            cout<<"|   2. Penulis            |"<<endl;
            cout<<"|   0. Kembali            |"<<endl;
            cout<<"|                         |"<<endl;
            cout<<"#-------------------------#"<<endl;
            cout<<" Masukan Pilihan : ";
            cin>>e;
            switch (e){
                case 1:
                    system("cls");
                    cout<<"#-------------------------------------#"<<endl;
                    cout<<"|           KELOMPOK QUERY            |"<<endl;
                    cout<<"#-------------------------------------#"<<endl;
                    cout<<"            [ DELETE DATA ]            "<<endl;
                    cout<<"                                       "<<endl;
                    cout<<" Buku - Penulis :                      "<<endl;
                    printinfoR(s);
                    if (first(s)==Nil){
                        cout<<endl;
                        cout<<"         Maaf Data Tidak Ada       "<<endl;
                    }
                    else{
                        cout<<endl;
                        cout<<"   [1] Lanjutkan     [0] Kembali   "<<endl;
                        cout<<endl;
                        cout<<" Masukan jawaban anda : ";
                        cin>>d;
                        cout<<endl;
                        if(d==1){
                            cout<<" Masukan Judul Buku          : ";
                            cin.ignore();
                            cin.getline(b,100);
                            ii.nama_buku = b;
                            y = findbukuB(p,ii);
                            if (y==Nil){
                                cout<<" "<<ii.nama_buku<<" tidak ditemukan"<<endl;
                            }
                            else{
                                cout<<" Masukan Nama Penulis        : ";
                                cin.getline(c,100);
                                i.nama_penulis = c;
                                deleteR(s,y,findP(q,i));
                                cout<<endl;
                                cout<<"      Data relasi berhasil dihapus            "<<endl;
                            }
                        }
                    }
                    cout<<"                                     "<<endl;
                    cout<<"         Tekan 0 untuk kembali       "<<endl;
                    cout<<"#------------------------------------#"<<endl;
                    getche();
                    break;
                case 2:
                    system("cls");
                    cout<<"#-------------------------------------#"<<endl;
                    cout<<"|           KELOMPOK QUERY            |"<<endl;
                    cout<<"#-------------------------------------#"<<endl;
                    cout<<"            [ DELETE DATA ]            "<<endl;
                    cout<<"                                       "<<endl;
                    cout<<" Buku - Penulis :                      "<<endl;
                    printinfoR(s);
                    if (first(s)==Nil){
                        cout<<endl;
                        cout<<"         Maaf Data Tidak Ada       "<<endl;
                    }
                    else{
                        cout<<endl;
                        cout<<"   [1] Lanjutkan     [0] Kembali   "<<endl;
                        cout<<endl;
                        cout<<" Masukan jawaban anda        : ";
                        cin>>d;
                        cout<<endl;
                        if(d==1){
                            cout<<" Masukan Nama Penulis    : ";
                            cin.ignore();
                            cin.getline(c,100);
                            i.nama_penulis = c;
                            z = findP(q,i);
                            if (z==Nil){
                                cout<<" "<<i.nama_penulis<<" tidak ditemukan"<<endl;
                            }
                            else{
                                cout<<" Masukan Judul Buku      : ";
                                cin.getline(b,100);
                                ii.nama_buku = b;
                                deleteR(s,findbukuB(p,ii),z);
                                cout<<"      Data relasi berhasil dihapus            "<<endl;
                            }
                        }
                    }
                    cout<<"                                     "<<endl;
                    cout<<"         Tekan 0 untuk kembali       "<<endl;
                    cout<<"#------------------------------------#"<<endl;
                    getche();
                    break;
                }
            }while(e!=0);
            break;
        case 2 :
            system("cls");
            cout<<"#-------------------------------------#"<<endl;
            cout<<"|           KELOMPOK QUERY            |"<<endl;
            cout<<"#-------------------------------------#"<<endl;
            cout<<"            [ DELETE DATA ]            "<<endl;
            cout<<"                                       "<<endl;
            printinfoB(p);
            if (first(p)==Nil){
                cout<<endl;
                cout<<"         Maaf Data Tidak Ada       "<<endl;
            }
            else{
                cout<<endl;
                cout<<"   [1] Lanjutkan     [0] Kembali   "<<endl;
                cout<<endl;
                cout<<" Masukan jawaban anda        : ";
                cin>>d;
                cout<<endl;
                if(d==1){
                    cout<<" Masukan Judul Buku      : ";
                    cin.ignore();
                    cin.getline(b,100);
                    ii.nama_buku = b;
                    if(findbukuB(p,ii)){
                        deleteRB(s,p,ii);
                        deleteB(p,ii);
                        cout<<"       Data Buku berhasil dihapus           "<<endl;
                    }
                    else{
                        cout<<endl;
                        cout<<"       Maaf Data Buku Tidak Ditemukan         "<<endl;
                    }
                }
            }
            cout<<"                                     "<<endl;
            cout<<"         Tekan 0 untuk kembali       "<<endl;
            cout<<"#------------------------------------#"<<endl;
            getche();
            break;
        case 3 :
            system("cls");
            cout<<"#-------------------------------------#"<<endl;
            cout<<"|           KELOMPOK QUERY            |"<<endl;
            cout<<"#-------------------------------------#"<<endl;
            cout<<"            [ DELETE DATA ]            "<<endl;
            cout<<"                                       "<<endl;
            printinfoP(q);
            if (first(q)==Nil){
                cout<<endl;
                cout<<"         Maaf Data Tidak Ada       "<<endl;
            }
            else{
                cout<<endl;
                cout<<"   [1] Lanjutkan     [0] Kembali   "<<endl;
                cout<<endl;
                cout<<" Masukan jawaban anda        : ";
                cin>>d;
                cout<<endl;
                if(d==1){
                    cout<<" Masukan nama penulis      : ";
                    cin.ignore();
                    cin.getline(c,100);
                    i.nama_penulis = c;
                    if (findP(q,i)){
                        deleteRP(s,q,i);
                        deleteP(q,i);
                        cout<<endl;
                        cout<<"       Data penulis berhasil dihapus           "<<endl;
                    }
                    else{
                        cout<<"       Maaf Data Penulis Tidak Ditemukan       "<<endl;
                    }
                }
            }
            cout<<"                                     "<<endl;
            cout<<"         Tekan 0 untuk kembali       "<<endl;
            cout<<"#------------------------------------#"<<endl;
            getche();
            break;
        }
    }while(a!=0);
}

void penulisaktif (list_b &b,list_p &q, list_r &s){
    address_p Aktif;
    address_p pn;
    system("cls");
    cout<<"#-------------------------------------#"<<endl;
    cout<<"|           KELOMPOK QUERY            |"<<endl;
    cout<<"#-------------------------------------#"<<endl;
    cout<<"                                       "<<endl;
    printinfoR(s);
    cout<<endl;
    if (first(s)==Nil){
        cout<<"          Maaf Data Tidak Ada         "<<endl;
    }
    else{
        if(first(q)!=Nil){
        pn=first(q);
        Aktif=next(pn);
        while(next(pn)!=Nil){
            if(info_p(pn).status>info_p(next(pn)).status){
               Aktif=pn;
            }
            pn=next(pn);
        }
        }
        cout<<" Penulis teraktif adalah "<<info_p(Aktif).nama_penulis;
        cout<<endl;
    }
    cout<<"                                     "<<endl;
    cout<<"         Tekan 0 untuk kembali       "<<endl;
    cout<<"#------------------------------------#"<<endl;
    getche();
}
