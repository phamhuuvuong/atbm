#include<iostream>
#include<iomanip>
#include<string>
#include<cctype>
using namespace std;

// Tao Sinh Vien
 
struct SinhVien{
    string maSV;
    string hoTen;
    string gioiTinh;
    int namSinh;
    float diemTK;
};

// Tao con tro 
struct Node{
    SinhVien infor;
    Node *next;
};

typedef Node *t;

// Nhap du lieu cho sinh vien
 
void nhapSV(SinhVien &sv){
    cout<<"Nhap ma sinh vien: ";
    cin>>sv.maSV;
    cout<<"Nhap ho ten: ";
    cin>>sv.hoTen;
    cout<<"Nhap gioi tinh: ";
    cin>>sv.gioiTinh;
    cout<<"Nhap nam sinh: ";
    cin>>sv.namSinh;
    cout<<"Nhap diem tong ket: ";
    cin>>sv.diemTK;
}

// Them sinh vien vào danh sách móc nôi don 
void nhapDS(t &L){
    t P,Q;
    SinhVien x;
    int i = 0;
    L = NULL;
    do{
        cout<<endl;
        cout<<"Nhap sinh vien thu "<<i+1<<endl;
        nhapSV(x);
        P = new Node;
        P->infor = x;
        P->next = NULL;
        if(L==NULL){
            L=P;
        } else {
            Q->next = P;
        }
        Q=P;
        i++;
    } while (i<3);
} 

// In danh sach 
void inDS(t &L){
    if(L==NULL){
        cout<<"Danh sach rong";
        return;
    } else {
        cout<<"STT";
        cout<<setw(7)<<"MaSV";
        cout<<setw(13)<<"Ho Ten";
        cout<<setw(22)<<"Gioi Tinh";
        cout<<setw(25)<<"Nam Sinh";
        cout<<setw(30)<<"Diem Tong Ket"<<endl;
    }
    t Q=L;
    int i=0;
    while(Q!=NULL){
        SinhVien x = Q->infor;
        cout<<i+1;
        cout<<setw(7)<<x.maSV;
        cout<<setw(13)<<x.hoTen;
        cout<<setw(20)<<x.gioiTinh;
        cout<<setw(24)<<x.namSinh;
        cout<<setw(28)<<x.diemTK<<endl;
        Q=Q->next;
        i++;
    }
}

// Xoa sinh vien o vi tri dau 
void xoa_vtdau(t &L){
    t Q;
    Q = L;
    if(L == NULL){
        cout<<"Danh sach rong";
    } else {
        L = L->next;
        delete(Q);
    }
    
}

// Chen sinh vien o vi tri dau
 
void chen_vtdau(t &L){
    t P;
    SinhVien x;
    cout<<"Nhap thong tin sinh vien can chen vao vi tri dau"<<endl;
    nhapSV(x);
    if(L == NULL){
        cout<<"Danh sach rong";
    } else {
        P = new Node;
        P->infor=x;
        P->next = L;
        L = P;
    }
}

// Chen sinh vien vao vi tri bat ky 
void chen_vitri(t &L){
    t P,Q,M;
    Q=L;
    SinhVien x;
    int k;
    int d=1;
    cout<<"Nhap vi tri muon chen sinh vien: ";
    cin>>k;
    cout<<"Nhap thong tin sinh vien can chen"<<endl;
    nhapSV(x);
    if(L == NULL){
        cout<<"Danh sach rong";
    }
    while(Q!=NULL && d<k){
        M=Q;
        Q=Q->next;
        d++;
    }
    P = new Node;
    P->infor=x;
    M->next = P;
    P->next = Q;
}

// Sap xep sinh vien theo diem
 
void sx_diemTK(t &L){
    if(L==NULL){
        cout<<"Danh sach rong";
    }
    t P,Q;
    Q=L;
    while(Q->next!=NULL){
        P=Q->next;
        while(P!=NULL){
            if(Q->infor.diemTK>P->infor.diemTK){
                SinhVien x = Q->infor;
                Q->infor = P->infor;
                P->infor = x;
            }
            P=P->next;
        }
        Q=Q->next;
    }
}

// Xoa sinh vien theo mã 
void xoa_theoma(t &L){
    string ma;
    cout<<"Nhap ma sinh vien muon xoa: ";
    cin>>ma;
    t P,Q;
    Q=L;
    if(L==NULL){
        cout<<"Damh sach rong";
    }
    while(Q != NULL && Q->infor.maSV != ma){
        P=Q;
        Q=Q->next;
    }
    if(Q==L){
        L=L->next;
        delete(Q);
    } else {
        if(Q->infor.maSV == ma){
            P->next = Q->next;
            delete(Q);
        }
    }
}

// Xoa sinh vien có diêm lon nhat 
 
void xoa_diemmax(t &L){
    t P,Q;
    P=L->next;
    Q=L;
    if(L==NULL){
        cout<<"Damh sach rong";
    }
    while(P!=NULL){
        if(P->infor.diemTK>Q->infor.diemTK){
            Q=P;
            P=P->next;
        } else {
            P=P->next;
        }
    }
    if(Q==L){
        L=L->next;
        delete(Q);
    } else {
        t R;
        R->next=Q;
        delete(Q);
    }
}
// Chen sinh viên truoc sinh vien co mã 
void chen_truocma(t &L){
    string ma;
    cout<<"Nhap ma sinh vien de chen truoc: ";
    cin>>ma;
    SinhVien x;
    cout<<"Nhap thong tin sinh vien can chen"<<endl;
    nhapSV(x);
    t P,Q,R;
    P = new Node;
    P->infor = x;
    if(L==NULL){
        cout<<"Damh sach rong";
    } else {
        Q=L;
        while(Q != NULL && Q->infor.maSV != ma){
            R=Q;
            Q=Q->next;
        }
        if(Q==L){
            P->next = L;
            L=P;
        } else {
            P->next = Q;
            R->next = P;
        }
    }
}
// Sap xep theo diem-chon 
 
void sx_diem(t &L){
	t P,Q,R;
	P=L;
	while(P->next != NULL){
		R=P;
		Q=P->next;
		while(Q != NULL){
			if(Q->infor.diemTK < R->infor.diemTK){
				R=Q;
			}
			Q=Q->next;
		}
		SinhVien tg = P->infor;
		P->infor = R->infor;
		R->infor = tg;
		P=P->next;
	}
}
// Sap xep theo ten -chon 
void sx_ten(t &L){
	t P,Q,R;
	P=L;
	while(P->next != NULL){
		R=P;
		Q=P->next;
		while(Q != NULL){
			char x = tolower(Q->infor.hoTen[0]);
			char y = tolower(R->infor.hoTen[0]);
			if(x < y){
				R=Q;
			}
			Q=Q->next;
		}
		SinhVien tg = P->infor;
		P->infor = R->infor;
		R->infor = tg;
		P=P->next;
	}
}
int main(){
    t L;
    nhapDS(L);
    inDS(L);
    // xoa_vtdau(L);
    // inDS(L);
    // chen_vtdau(L);
    // inDS(L);
    // chen_vitri(L);
    // inDS(L);
    // sx_diemTK(L);
    // inDS(L);
    // xoa_theoma(L);
    // inDS(L);
    // xoa_diemmax(L);
    // inDS(L);
    // chen_truocma(L);
    // inDS(L);
    //sx_diem(L);
    //inDS(L);
     sx_ten(L);
     inDS(L);
}
