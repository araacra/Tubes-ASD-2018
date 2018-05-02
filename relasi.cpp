#include "relasi.h"

void createlistR(list_r &l){
    first(l)=Nil;
}

address_r alokasiR(address_b x, address_p y){
    address_r p = new elmlist_relasi;
    buku(p)=x;
    penulis(p)=y;
    next(p)=Nil;
    return p;
    }

void dealokasiR(address_r &p){
    delete p;
}

void insertR(list_r &l, address_r p){
    if (first(l)==Nil){
        first(l) = p;
    }
    else{
        next(p)=first(l);
        first(l)=p;
    }
}

void deleteR(list_r &l, address_b p, address_p q){
    address_r r=findelmR(l,p,q);
    address_r s;
    address_r t = first(l);
    if (r!=Nil){
        if(t==r){
            if (next(t)!=Nil){
                s=t;
                first(l)=next(t);
                dealokasiR(s);
            }
            else{
                first(l)=Nil;
                dealokasiR(t);
            }
        }
        else{
            while(next(t)!=Nil&&next(t)!=r){
                t=next(t);
            }
            if (next(t)==r&&next(next(t))!=Nil){
                s = next(t);
                next(t)=next(s);
                dealokasiR(s);
            }
            else if (next(t)==r&&next(next(t))==Nil){
                s=next(t);
                next(t)=Nil;
                dealokasiR(s);
            }
        }
    }
}

void deleteRKhusus(list_r &l, address_b b, address_p p){
        address_r q = findelmR(l,b,p);
        address_r s;
        if (q!=Nil){
            if (q==first(l)&&next(q)==Nil){
                first(l)=Nil;
            }
            else if (q==first(l)&&next(q)!=Nil){
                s=next(q);
                next(q)=Nil;
                first(l)=s;
            }
            else {
                s =first(l);
                while(next(s)!=Nil&&s!=q){
                    s=next(s);
                }
                next(s)= next(q);
                next(q)=Nil;
            }
        }
}


void deleteRB(list_r &l, list_b &p, infotype_b x){
    address_r r = first(l);
    address_b a= findbukuB(p,x);
    while(a!=Nil&&r!=Nil){
        deleteRKhusus(l,a,penulis(r));
        r=next(r);
    }
    deleteB(p,x);
}

void deleteRP(list_r &l, list_p &q,infotype_p x){
    address_r r = first(l);
    address_p b = findP(q,x);
    while(b!=Nil&&r!=Nil){
        deleteRKhusus(l,buku(r),b);
        r=next(r);
    }
    deleteP(q,x);
}

address_r findelmR(list_r l, address_b b, address_p p){
    address_r z = first(l);
    if (z==Nil){
        return Nil;
    }
    while (next(z)!= Nil && (buku(z)!=b || penulis(z)!=p)){
            z=next(z);
    }
        if (buku(z)==b && penulis(z)==p){
            return z;
        }
        else{
            return Nil;
        }
}

void printinfoR(list_r l){
    int i=1;
    if (first(l)!=Nil){
        address_r p = first(l);
        cout<<"  "<<i<<". "<<info_b(buku(p)).nama_buku<<" - "<<info_p(penulis(p)).nama_penulis<<endl;
        while(next(p)!=Nil){
            p=next(p);
            i=i+1;
            cout<<"  "<<i<<". "<<info_b(buku(p)).nama_buku<<" - "<<info_p(penulis(p)).nama_penulis<<endl;
        }
    } else {
        cout<<"Data kosong"<<endl;
    }

}


void printinfoRB(list_r l, address_p p){
    int i = 1;
    address_r q = first(l);
    if(q==Nil){
        cout<<"       Data Buku Tidak Tersedia    "<<endl;
    }
    else{
        while(q != Nil){
            if (penulis(q)==p){
                cout<<"  "<<i<<". "<<info_b(buku(q)).nama_buku<<endl;
                i++;
            }
            q= next(q);
        }
        cout<<endl;
    }
}

void printinfoRP(list_r l, address_b b){
    int i = 1;
    address_r q = first(l);
    if(q==Nil){
        cout<<"       Data Penulis Tidak Tersedia    "<<endl;
    }
    else {
        while(q != Nil){
            if (buku(q)==b){
                cout<<"  "<<i<<". "<<info_p(penulis(q)).nama_penulis<<endl;
                i++;
            }
        q= next(q);
        }
        cout<<endl;
    }
}
