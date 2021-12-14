#include<bits\stdc++.h>
using namespace std;
struct NhanVien
{
	int maNV;
	char TenNV[20];
	char GioiTinh[20];
	char LienHe[20];
	char NgaySinh[20];
	int LCB;
	double HSL;
	double Luong;
	
};
struct NodeNV
{
	NhanVien info;
	struct NodeNV *next;
};
struct ListNV
{
	NodeNV *Head;
	NodeNV *Tail;
};
void initNV (ListNV &NV)
{
	NV.Head = NULL;
	NV.Tail = NULL;
}
NodeNV* get_NodeNV (NhanVien nv)
{
	NodeNV *p;
	p = new NodeNV;
	if (p == NULL)
	{
		cout<<"Khong du bo nho";
		exit(1);
	}
	p->info = nv;
	p->next = NULL;
	return p;

}
void InsertLastNV (ListNV &NV, NodeNV *new_element)
{
	if (NV.Head == NULL)
	{
		NV.Head = new_element;
		NV.Tail = NV.Head;
	}
	else 
	{
		NV.Tail->next = new_element;
		NV.Tail = new_element;
	}
}
void NhapNV (NhanVien &nv)
{
	cout<<"Ma nhan vien: ";cin>>nv.maNV;
	fflush(stdin);
	cout<<"Ten nhan vien: ";gets(nv.TenNV);
	fflush(stdin);
	cout<<"Gioi tinh: ";gets(nv.GioiTinh);
	fflush(stdin);
	cout<<"Lien he: ";gets(nv.LienHe);
	fflush(stdin);
	cout<<"Ngay sinh: ";gets(nv.NgaySinh);
	fflush(stdin);
	nv.LCB = 1350;
	cout<<"He so luong: ";cin>>nv.HSL;
	nv.Luong = nv.LCB*nv.HSL;

}
void InNV (NhanVien nv)
{
	cout<<"\nMa nhan vien: "<<nv.maNV;
	cout<<"\nTen nhan vien: "<<nv.TenNV;
	cout<<"\nGioi tinh: "<<nv.GioiTinh;
	cout<<"\nLien he: "<<nv.LienHe;
	cout<<"\nNgay sinh: "<<nv.NgaySinh;
	cout<<"\nLuong co ban: "<<nv.LCB;
	cout<<"\nHe so luong: "<<nv.HSL;
	cout<<"\nLuong: "<<nv.Luong;
	cout<<"\n";

}
void NhapDSNV (ListNV &NV)
{
	NodeNV *p;
	int n;
	NhanVien nv;
	cout<<"Nhap so nhan vien:";cin>>n;
	for (int i = 0;i<n;i++)
	{
		NhapNV (nv);
		p = get_NodeNV(nv);
		InsertLastNV(NV, p);

	}
}
void InDSNV (ListNV NV)
{
	NodeNV *p;
	for (p = NV.Head;p!=NULL;p=p->next)
	{
		InNV(p->info);
	}
}

void Luufile_NV(FILE *f, ListNV &NV)
{
	f = fopen("nhanvien.txt", "wb");
	int n = 0;
	NodeNV *p;
	for (p=NV.Head;p!=NULL;p=p->next)
	{
		n = n+1;
	}
	fwrite(&n, sizeof(int), 1, f);
	
	for (p = NV.Head;p!=NULL;p=p->next)
	{
		fwrite(&p->info, sizeof(NhanVien), 1, f);

	}
	
	fclose(f);

}
void Docfile_NV(FILE *f, ListNV &NV)
{
	initNV(NV);
	NhanVien nv;
	int n;
	NodeNV *p;
	f = fopen("nhanvien.txt", "rb");
	fread(&n, sizeof(int), 1, f);
	for (int i =0; i<n;i++)
	{
		fread((char*)&nv, sizeof(NhanVien), 1, f);
		p = get_NodeNV(nv);
		InsertLastNV(NV, p);
	}
	InDSNV(NV);

	fclose(f);
}
void TongLuong (ListNV NV)
{
	NodeNV *p;
	double tongluong = 0;
	for (p = NV.Head;p!=NULL;p=p->next)
	{
		tongluong = tongluong + p->info.Luong;
	}
	cout<<"Tong luong cua tat ca nhan vien la: "<<tongluong;
}

void Them_NV (ListNV &NV)
{
	NodeNV *p;
	int n;
	NhanVien nv;
	cout<<"\nNhap so nhan vien muon them:";cin>>n;
	for (int i = 0;i<n;i++)
	{
		NhapNV (nv);
		p = get_NodeNV(nv);
		InsertLastNV(NV, p);
	}
	cout<<"\n----------Them nhan vien thanh cong----------\n";
	
	
}
void Sua_NV (ListNV &NV)
{
	NodeNV *p;
	int mnv;
	char tenmoi[20];
	cout<<"\nNhap ma nhan vien muon sua: ";cin>>mnv;
	for (p = NV.Head;p!=NULL;p=p->next)
	{
		if (mnv == p->info.maNV)
		{
			fflush(stdin);
			cout<<"\nNhap ten nhan vien moi:";gets(tenmoi);
			strcpy(p->info.TenNV, tenmoi);

		}
	}
	cout<<"\n----------Sua thanh cong----------\n";
	
}
void Xoa_NV(ListNV &NV)
{
	int mnv;
	cout<<"Nhap ma nhan vien can xoa: ";cin>>mnv;
	NodeNV *p = NV.Head;
	NodeNV *q = NULL;
	while(p!=NULL)
	{
		if (p->info.maNV == mnv)
		{
			break;
		}
		q = p;
		p = p->next;

	}
	if (p == NULL)
	{
		cout<<"Khong tim thay";//khong tim thay
	}
	if (q!=NULL)
	{
		if (p == NV.Tail)
		{
			NV.Tail = q;
		}
		q->next = p->next;
		delete p;
	}
	else // p la phan tu dau xau
	{
		NV.Head = p->next;
		if (NV.Head == NULL)
		{
			NV.Tail = NULL;
		}

	}
	cout<<"\n----------Xoa thanh cong----------\n";
	
}
	
void Search_MNV (ListNV NV)
{
	NodeNV *p;
	int mnv;
	cout<<"\nNhap ma nhan vien muon tim: ";cin>>mnv;
	cout<<"\nNhan vien ban tim la:\n";
	for (p = NV.Head;p!=NULL;p=p->next)
	{
		if (mnv == p->info.maNV)
		{
			InNV(p->info);
		}
	}
}
void Search_LuongMax (ListNV NV)
{
	NodeNV *p;
	double max = 0;
	for (p = NV.Head;p!=NULL;p=p->next)
	{
		if (p->info.Luong > max)
		{
			max = p->info.Luong;
		}
	}
	cout<<"\nNhan vien co luong lon nhat la:\n";
	for (p = NV.Head;p!=NULL;p=p->next)
	{
		if (p->info.Luong == max)
		{
			InNV(p->info);
		}
	}

}
void Search_LuongMin (ListNV NV)
{
	NodeNV *p;
	double min = NV.Head->info.Luong;
	for (p = NV.Head->next;p!=NULL;p=p->next)
	{
		if (p->info.Luong < min)
		{
			min = p->info.Luong;
		}
	}
	cout<<"\nNhan vien co luong nho nhat la:\n";
	for (p = NV.Head;p!=NULL;p=p->next)
	{
		if (p->info.Luong == min)
		{
			InNV(p->info);
		}
	}

}
void Dem_NV (ListNV NV)
{
	NodeNV *p;
	int dem = 0;
	double luongcandem;
	cout<<"\nNhan vien luong nhieu hon: ";cin>>luongcandem;

	for (p = NV.Head;p!=NULL;p=p->next)
	{
		if (p->info.Luong > luongcandem)
		{
			dem++;
		}

	}
	cout<<"So nhan vien co luong lon hon "<<luongcandem<<" la: "<<dem;
}
void LietKe_NV (ListNV NV)
{
	NodeNV *p;
	double luongcanlietke;
	cout<<"\nNhan vien luong nhieu hon: ";cin>>luongcanlietke;
	cout<<"\n-----Danh sach nhan vien co luong lon hon "<<luongcanlietke<< " la-----\n";
	for (p = NV.Head;p!=NULL;p=p->next)
	{
		if (p->info.Luong > luongcanlietke)
		{
			InNV(p->info);
		}
	}

}
void Sapxep_Tangdan(ListNV &NV)
{
	NodeNV *p;
	NodeNV *q;
	NhanVien temp;
	for (p=NV.Head;p!=NULL;p=p->next)
	{
		for (q=p->next;q!=NULL;q=q->next)
		{
			if (p->info.Luong > q->info.Luong)
			{
				temp = p->info;
				p->info = q->info;
				q->info = temp;
			}
		}
	}
	cout<<"\n----------Danh sach nhan vien sau khi sap xep tang dan dan theo luong la----------\n";
	InDSNV(NV);

}
void Sapxep_Giamdan(ListNV &NV)
{
	NodeNV *p, *q;
	NhanVien temp;
	for (p=NV.Head;p!=NULL;p=p->next)
	{
		for (q=p->next;q!=NULL;q=q->next)
		{
			if (p->info.Luong < q->info.Luong)
			{
				temp = p->info;
				p->info = q->info;
				q->info = temp;
			}
		}
	}
	cout<<"\n----------Danh sach nhan vien sau khi sap xep giam dan dan theo luong la----------\n";
	InDSNV(NV);

}
void Edit_NV (ListNV &NV)
{
	int edit;
	do
	{
		cout<<"\nBan can sua doi gi khong?";
		cout<<"\n 0. Khong";
		cout<<"\n 1. Them nhan vien";
		cout<<"\n 2. Sua nhan vien";
		cout<<"\n 3. Xoa nhan vien";
		cout<<"\nHay chon: ";
		cin>>edit;
		switch(edit)
		{
			case 0: break;
			case 1: Them_NV(NV);break;
			case 2: Sua_NV(NV);break;
			case 3: Xoa_NV(NV);break;
		}

	}
	while(edit!=0);

}


void Timkiem_Lietke_NhanVien (ListNV NV)
{
	int tk;
	do
	{
		cout<<"\n 	 -----Tim kiem va liet ke-----";
		cout<<"\n 0. Khong tim kiem";
		cout<<"\n 1. Tong luong cua tat ca nhan vien";
		cout<<"\n 2. Tim kiem nhan vien theo ma ";
		cout<<"\n 3. Tim kiem nhan vien luong nhieu nhat ";
		cout<<"\n 4. Tim kiem nhan vien luong it nhat ";
		cout<<"\n 5. Dem nhan vien luong nhieu hon theo y muon";
		cout<<"\n 6. Liet ke nhan vien luong nhieu hon theo y muon";
		cout<<"\nHay chon: ";
		cin>>tk;
		switch(tk)
		{
			case 0: break;
			case 1: TongLuong(NV);
			case 2: Search_MNV(NV);break;
			case 3: Search_LuongMax(NV);break;
			case 4: Search_LuongMin(NV);break;
			case 5: Dem_NV(NV);break;
			case 6: LietKe_NV(NV);break;
		}


	}
	while(tk!=0);
}

void Sapxep_NV(ListNV &NV)
{
	int sx;
	do
	{
		cout<<"\n 	-----Sap xep nhan vien-----";
		cout<<"\n0. Khong sap xep ";
		cout<<"\n1. Sap xep tang dan theo luong ";
		cout<<"\n2. Sap xep giam dan theo luong ";
		cout<<"\nHay chon: ";
		cin>>sx;
		switch(sx)
		{
			case 0: break;
			case 1: Sapxep_Tangdan(NV);break;
			case 2: Sapxep_Giamdan(NV);break;
		}
		
	}
	while(sx!=0);

}

void MenuNV()
{
	ListNV NV;
	initNV(NV);
	FILE *f;
	f = new FILE;
	int menu;
	do
	{
		cout<<"\n ------Quan ly nhan vien-----";
		cout<<"\n 1. Nhap danh sach nhan vien va luu file tu dong";
		cout<<"\n 2. In danh sach nhan vien";
		cout<<"\n 3. Luu danh sach vao file";
		cout<<"\n 4. Doc danh sach tu file";
		cout<<"\n 5. Sua thong tin va luu file tu dong";
		cout<<"\n 6. Tim kiem va liet ke";
		cout<<"\n 7. Sap xep";
		cout<<"\n 0. Thoat";
		cout<<"\nHay chon: ";
		cin>>menu;
		switch(menu)
		{
			case 1:NhapDSNV(NV);Luufile_NV(f, NV);break;
			case 2:InDSNV(NV);break;
			case 3:Luufile_NV(f, NV);break;
			case 4:Docfile_NV(f, NV);break;
			case 5:Edit_NV(NV);Luufile_NV(f, NV);break;
			case 6:Timkiem_Lietke_NhanVien(NV);break;
			case 7:Sapxep_NV(NV);break;
		}
	}
	while(menu!=0);
}





