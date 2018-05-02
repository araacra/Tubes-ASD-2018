#include "listpenulis.h"

void createlistP(list_p &l){
    first(l)=Nil;
}

address_p alokasiP(infotype_p x){
    address_p p = new elmlist_penulis;
    next(p)=Nil;
    info_p(p).nama_penulis=x.nama_penulis;
    info_p(p).umur=x.umur;
    return p;
}
void dealokasiP(address_p &p){
    delete(p);
}
void insertP(list_p &l, address_p p){
    if (first(l)==Nil){
        first(l) = p;
    }
    else{
        next(p)=first(l);
        first(l)=p;
    }
}

void deletefirstP(list_p &l, address_p &p){
    if (first(l)==Nil){
        cout<<"tidak ada data"<<endl;
    }
    else if (next(first(l))==Nil){
        p=first(l);
        first(l)=Nil;
    }
    else{
        p=first(l);
        first(l)=next(p);
    }
}

void deleteafterP(list_p &l,address_p prec, address_p &p){
    if(first(l)!=Nil){
        if(next(prec)!=Nil){
            p=next(prec);
            next(prec)=next(p);
            next(p)=Nil;
        }
        else {
            deletefirstP(l,p);
        }
    }
    else {
        deletelastP(l,p);
    }
}


void deletelastP(list_p &l, address_p &p){
    address_p s;
    p=first(l);
    while (next(p)!=Nil){
        s=p;
        p=next(p);
    }
    next(s)=Nil;
    }

address_p findP(list_p l, infotype_p x){
    address_p p=first(l);
    if (first(l)==Nil){
        cout<<"tidak ada data"<<endl;
    }
    else{
        while (next(p)!=Nil && x.nama_penulis!=info_p(p).nama_penulis){
            p=next(p);
        }
        if (info_p(p).nama_penulis==x.nama_penulis){
            return p;
        }
        else{
            return Nil;
        }

    }
}

void printinfoP(list_p l){
    address_p q;
    q = first(l);
    int i=1;
    if (first(l)==Nil){
        cout<<endl;
        cout<<"    Data Penulis Tidak Ada     "<<endl;
    }
    else{
        cout<<"     "<<i<<". "<<info_p(q).nama_penulis<<endl;
        while(next(q)!=Nil){
            q = next(q);
            i=i+1;
            cout<<"     "<<i<<". "<<info_p(q).nama_penulis<<endl;
        }
    }
}

void deleteP(list_p &l, infotype_p x){
    address_p p,q;
    if (first(l)!=Nil){
        p = findP(l,x);
        if(p!=Nil){
            if(first(l)==p&&next(p)==Nil){
                deletefirstP(l,p);
            }
            else if(first(l)==p){
                deletefirstP(l,p);
            }
            else if(next(p)==Nil){
                deletelastP(l,p);
            }
            else {
                q = first(l);
                while(next(q)!=p){
                    q = next(q);
                }
                deleteafterP(l,q,p);
            }
            delete p;
        } else {
            cout<<"Data tidak ditemukan"<<endl;
        }
    }else{
        cout<<"Data Kosong"<<endl;
    }
}





