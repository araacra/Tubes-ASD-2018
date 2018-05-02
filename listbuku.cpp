#include "listbuku.h"

void createlistB(list_b &l){
    first(l) = Nil;
    last(l) = Nil;
}

address_b alokasiB(infotype_b x){
    address_b p;
    p = new elmlist_buku;
    info_b(p).nama_buku = x.nama_buku;
    info_b(p).tahun = x.tahun;
    next(p) = Nil;
    prev(p) = Nil;
    return p;
}

void dealokasiB(address_b &p){
    delete(p);
}

void insertB(list_b &l, address_b p){
    if (first(l)==Nil){
        first(l)=p;
        last(l)=p;
    }
    else{
        next(p)=first(l);
        prev(first(l))= p;
        first(l)=p;
    }
}

void deletefirstB(list_b &l, address_b &p){
    if(first(l)==Nil && last(l)==Nil){
        cout<<"Data tidak ada"<<endl;
    }
    else{
        p = first(l);
        if (first(l)==last(l)){
            first(l)=Nil;
            last(l)=Nil;
            dealokasiB(p);
        }
        else{
            address_b q =next(p);
            next(p)=Nil;
            prev(q)=Nil;
            first(l)=q;
            dealokasiB(p);
        }
    }
}

void deleteafterB(list_b &l,address_b prec, address_b &p){
    if(first(l)!=Nil){
        if(prec==first(l)){
            deletefirstB(l,p);
        } else {
            p=next(prec);
            next(prec)=next(p);
            prev(next(p))= prec;
            next(p)=Nil;
        }
    } else {
        deletelastB(l,p);
    }
}

void deletelastB(list_b &l, address_b &p){
    address_b q;
    q = last(l);
    if(first(l)==Nil && last(l)==Nil){
        cout<<"Data tidak ada"<<endl;
    }
    else if (first(l)==last(l)){
        first(l)=Nil;
        last(l)=Nil;
        dealokasiB(q);

    }
    else{
        last(l)=prev(q);
        next(last(l))=Nil;
        prev(q)= Nil;
        dealokasiB(q);
    }
}

address_b findbukuB(list_b l, infotype_b x){
    address_b p;
    p = first(l);
    if (first(l)==Nil){
        return Nil;
    }
    else{
        while (next(p)!=Nil && info_b(p).nama_buku!=x.nama_buku){
            p = next(p);
        }
    }
    if (info_b(p).nama_buku==x.nama_buku){
        return p;
    }
    else {
        return Nil;
    }
}

void printinfoB(list_b l){
    address_b q;
    int i=1;
    q=first(l);
    if(first(l)==Nil){
        cout<<"         Data buku tidak ada         "<<endl;
    }
    else{
        cout<<"     "<<i<<". "<<info_b(q).nama_buku<<endl;
        while(next(q)!=Nil){
            q = next(q);
            i=i+1;
            cout<<"     "<<i<<". "<<info_b(q).nama_buku<<endl;

            }
        }
    }


void deleteB(list_b &l, infotype_b x){
    address_b p,q;
    if(first(l)!=Nil){
        p = findbukuB(l,x);
        if(p!=Nil){
            if(first(l)==p && last(l)==p){
                deletefirstB(l,p);
            }
            else if(prev(p)==Nil){
                deletefirstB(l,p);
            }
            else if(next(p)==Nil){
                deletelastB(l,p);
            }
            else {
                q = prev(p);
                deleteafterB(l,q,p);
            }
        }
    }
}
