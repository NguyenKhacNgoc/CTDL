#include<bits\stdc++.h>
using namespace std;
struct HoaDon:VatTu
{
	int MaHD;
	string NguoiLap;
	string NgayLap;
	VatTu ds[30];
	int soVT;
	double tongtien;
};
struct NodeHD
{
	HoaDon info;
	struct NodeHD *next;
	struct NodeHD *pre;
};
struct ListHD
{
	NodeHD *Head;
	NodeHD *Tail;

};
void initHD (ListHD &HD)
{
	HD.Head = NULL;
	HD.Tail = NULL;
}
NodeHD* get_nodeHD (HoaDon hd)
{
	NodeHD *p;
	p = new NodeHD;
	if (p == NULL)
	{
		cout<<"Khong du bo nho";
		exit(1);
	}
	p->info = hd;
	p->next = NULL;
	p->pre = NULL;
	return p;
}
void InsertLastHD (ListHD &HD, NodeHD *new_element)
{
	if (HD.Head == NULL)
	{
		HD.Head = new_element;
		HD.Tail = HD.Head;
	}
	else 
	{
		new_element->pre = HD.Tail;
		HD.Tail->next = new_element;
		HD.Tail = new_element;
	}

}
void NhapHD (HoaDon &hd)
{
	cout<<"Ma hoa don: ";cin>>hd.MaHD;
	cout<<"Nguoi lap: ";cin>>hd.NguoiLap;
	fflush(stdin);
	cout<<"Ngay lap: ";cin>>hd.NgayLap;
	fflush(stdin);
	cout<<"Nhap so luong vat tu: ";cin>>hd.soVT;
	for (int i = 0;i<hd.soVT;i++)
	{
		NhapVT (hd.ds[i]);
		hd.tongtien+=hd.ds[i].ThanhTien;

	}	
}
void InHD (HoaDon hd)
{
	cout<<"\nMa hoa don: "<<hd.MaHD;
	cout<<"\nNguoi lap: "<<hd.NguoiLap;
	cout<<"\nNgay lap: "<<hd.NgayLap;
	cout<<"\nSo vat tu: "<<hd.soVT;
	for (int i = 0;i<hd.soVT;i++)
	{
		InVT (hd.ds[i]);
	}
	cout<<"\nTong tien hoa don la: "<<hd.tongtien;
	cout<<"\n";
}
void NhapDSHD (ListHD &HD)
{
	NodeHD *p;
	HoaDon hd;
	int n;
	cout<<"\nNhap danh sach hoa don: ";cin>>n;
	for (int i=0;i<n;i++)
	{
		NhapHD(hd);
		p = get_nodeHD(hd);
		InsertLastHD(HD, p);
	}
}
void InDSHD(ListHD HD)
{
	NodeHD *p;
	for (p=HD.Head;p!=NULL;p=p->next)
	{
		InHD(p->info);
	}
}
void Luufile_HD(FILE *f, ListHD &HD)
{
	f = fopen("hoadon.txt", "wb");
	int n = 0;
	NodeHD *p;
	for (p=HD.Head;p!=NULL;p=p->next)
	{
		n = n+1;
	}
	fwrite(&n, sizeof(int), 1, f);
	for (p = HD.Head;p!=NULL;p=p->next)
	{
		fwrite(&p->info, sizeof(HoaDon), 1, f);

	}

	fclose(f);

}
void Docfile_HD(FILE *f, ListHD &HD)
{
	initHD(HD);
	cout<<"\nLuu file thanh cong";
	HoaDon hd;
	int n;
	NodeHD *p;
	f = fopen("hoadon.txt", "rb");
	fread(&n, sizeof(int), 1, f);
	for (int i =0; i<n;i++)
	{
		fread((char*)&hd, sizeof(HoaDon), 1, f);
		p = get_nodeHD(hd);
		InsertLastHD(HD, p);
	}
	InDSHD(HD);
	
	fclose(f);
}
void Them_HD (ListHD &HD)
{
	NodeHD *p;
	int n;
	HoaDon hd;
	cout<<"\nNhap so hoa don muon them:";cin>>n;
	for (int i = 0;i<n;i++)
	{
		NhapHD (hd);
		p = get_nodeHD(hd);
		InsertLastHD(HD, p);
	}
	cout<<"\n----------Them hoa don thanh cong----------\n";
	
}
void Sua_HD (ListHD &HD)
{
	NodeHD *p;
	int mhd;
	cout<<"\nNhap ma hoa don muon sua: ";cin>>mhd;
	for (p = HD.Head;p!=NULL;p=p->next)
	{
		if (mhd == p->info.MaHD)
		{
			NhapHD(p->info);
		}
	}
	cout<<"\n----------Sua thanh cong----------\n";
	
}
void Xoa_HD(ListHD &HD)
{
	NodeHD *p;
	int mhd;
	cout<<"\nNhap ma hoa don can xoa: ";cin>>mhd;
	p = HD.Head;
	while(p!=NULL)
	{
		if (p->info.MaHD == mhd)
		{
			break;
		}
		p = p->next;
	}

	if (p == NULL)
	{
		cout<<"Khong tim thay";
	}
	else
	{
		if ((p == HD.Head) && (p == HD.Tail))
		{
			HD.Head = NULL;
			HD.Tail = NULL;
		}
		else if (p = HD.Head)
		{
			HD.Head = p->next;

		}
		else if (p = HD.Tail)
		{
			p->pre->next = NULL;
			HD.Tail = p->pre;
		}
		else
		{
			p->pre->next = p->next;
			p->next->pre = p->pre;
		}
		free(p);
	}
	cout<<"\n----------Xoa hoa don thanh cong----------\n";
	
}
void TongTien(ListHD HD)
{
	NodeHD *p;
	double sum = 0;
	for (p=HD.Head;p!=NULL;p=p->next)
	{
		sum = sum + p->info.tongtien;
	}
	cout<<"\nTong tien cua tat ca hoa don la: "<<sum;
}
void Search_MaHD (ListHD HD)
{
	NodeHD *p;
	int mhd;
	cout<<"\nNhap ma hoa don muon tim: ";cin>>mhd;
	cout<<"\nHoa don ban tim la:\n ";
	for (p=HD.Head;p!=NULL;p=p->next)
	{
		if (mhd == p->info.MaHD)
		{
			InHD(p->info);
		}
	}
}

void Search_TongTienMax (ListHD HD)
{
	NodeHD *p;
	double max = 0;
	for (p=HD.Head;p!=NULL;p=p->next)
	{
		if (p->info.tongtien > max)
		{
			max = p->info.tongtien;
		}
	}
	cout<<"\nHoa don co tong tien lon nhat la:\n ";
	for (p=HD.Head;p!=NULL;p=p->next)
	{
		if (p->info.tongtien == max)
		{
			InHD(p->info);
		}
	}

}
void Search_TongTienMin (ListHD HD)
{
	NodeHD *p;
	double min = HD.Head->info.tongtien;
	for (p=HD.Head->next;p!=NULL;p=p->next)
	{
		if (p->info.tongtien < min)
		{
			min = p->info.tongtien;
		}
	}
	cout<<"\nHoa don co don gia nho nhat la:\n ";
	for (p=HD.Head;p!=NULL;p=p->next)
	{
		if (p->info.tongtien == min)
		{
			InHD(p->info);
		}
	}

}


void Dem_HD (ListHD HD)
{
	NodeHD *p;
	int dem = 0;
	double tongtiencandem;
	cout<<"\nHoa don tong tien nhieu hon: ";cin>>tongtiencandem;
	for (p=HD.Head;p!=NULL;p=p->next)
	{
		if (p->info.ThanhTien > tongtiencandem)
		{
			dem++;
		}
	}
	cout<<"So hoa don co luong lon hon "<<tongtiencandem<<" la: "<<dem;
}
void LietKe_HD (ListHD HD)
{
	NodeHD *p;
	double tongtiencanlietke;
	cout<<"\nHoa don tong tien nhieu hon: ";cin>>tongtiencanlietke;
	cout<<"\n=====Danh sach hoa don co tong tien lon hon "<< tongtiencanlietke<<" la=====\n";
	for (p=HD.Head;p!=NULL;p=p->next)
	{
		if (p->info.tongtien > tongtiencanlietke)
		{
			InHD (p->info);
		}

	}
}
void Sapxep_TangdanHD(ListHD &HD)
{
	NodeHD *p, *q;
	HoaDon temp;
	for (p = HD.Head;p!=NULL;p=p->next)
	{
		for (q = p->next;q!=NULL;q=q->next)
		{
			if (p->info.tongtien > q->info.tongtien)
			{
				temp = p->info;
				p->info = q->info;
				q->info = temp;
			}
		}
	}
	cout<<"\n----------Hoa don sau khi sap xep tang dan tong tien la----------\n";
	InDSHD(HD);
}
void Sapxep_GiamdanHD(ListHD &HD)
{
	NodeHD *p, *q;
	HoaDon temp;
	for (p = HD.Head;p!=NULL;p=p->next)
	{
		for (q = p->next;q!=NULL;q=q->next)
		{
			if (p->info.tongtien < q->info.tongtien)
			{
				temp = p->info;
				p->info = q->info;
				q->info = temp;
			}
		}
	}
	cout<<"\n----------Hoa don sau khi sap xep giam dan tong tien la----------\n";
	InDSHD(HD);
}
void Edit_HD (ListHD &HD)
{
	int edit;
	do
	{
		cout<<"\nBan co muon sua doi khong?";
		cout<<"\n 0. Khong";
		cout<<"\n 1. Them hoa don";
		cout<<"\n 2. Sua hoa don";
		cout<<"\n 3. Xoa hoa don";
		cout<<"\nHay chon: ";
		cin>>edit;
		switch(edit)
		{
			case 0: break;
			case 1: Them_HD(HD);break;
			case 2: Sua_HD(HD);break;
			case 3: Xoa_HD(HD);break;
		}

	}
	while(edit!=0);
}
void Timkiem_LietKe_HD(ListHD HD)
{
	int tk;
	do
	{
		cout<<"\n -----Tim kiem va liet ke----- ";
		cout<<"\n 0. Khong tim kiem";
		cout<<"\n 1. Tong tien cua tat ca cac hoa don";
		cout<<"\n 2. Tim kiem hoa don theo ma ";
		cout<<"\n 3. Tim kiem hoa don tong tien nhieu nhat ";
		cout<<"\n 4. Tim kiem hoa don tong tien it nhat ";
		cout<<"\n 5. Dem hoa don tong tien theo y muon";
		cout<<"\n 6. Liet ke hoa don tong tien theo y muon";
		cout<<"\nHay chon: ";
		cin>>tk;
		switch(tk)
		{
			case 0: break;
			case 1: TongTien(HD);break;
			case 2: Search_MaHD(HD);break;
			case 3: Search_TongTienMax(HD);break;
			case 4: Search_TongTienMin(HD);break;
			case 5: Dem_HD(HD);break;
			case 6: LietKe_HD(HD);break;
		}
	}
	while(tk!=0);

}


void Sapxep_HD (ListHD &HD)
{
	int sx;
	do
	{
		cout<<"\n 	-----Sap xep-----";
		cout<<"\n0. Khong sap xep";
		cout<<"\n1. Sap xep tang dan theo tong tien hoa don ";
		cout<<"\n2. Sap xep giam dan theo tong tien hoa don ";
		cout<<"\nHay chon: ";
		cin>>sx;
		switch(sx)
		{
			case 0:break;
			case 1:Sapxep_TangdanHD(HD);break;
			case 2:Sapxep_GiamdanHD(HD);break;
		}
	}
	while(sx!=0);	
}
void MenuHD()
{
	ListHD HD;
	initHD(HD);
	FILE *f;
	f = new FILE;
	int menu;
	do
	{
		cout<<"\n 	-----Quan ly hoa don ban hang-----";
		cout<<"\n 1. Nhap danh sach hoa don";
		cout<<"\n 2. In danh sach hoa don";
		cout<<"\n 3. Luu danh sach vao file";
		cout<<"\n 4. Doc danh sach tu file";
		cout<<"\n 5. Sua thong tin";
		cout<<"\n 6. Tim kiem va liet ke";
		cout<<"\n 7. Sap xep";
		cout<<"\n 0. Thoat";
		cout<<"\nHay chon: ";
		cin>>menu;
		switch(menu)
		{
			case 1:NhapDSHD(HD);break;
			case 2:InDSHD(HD);break;
			case 3:Luufile_HD(f, HD);break;
			case 4:Docfile_HD(f, HD);break;
			case 5:Edit_HD(HD);break;
			case 6:Timkiem_LietKe_HD(HD);break;
			case 7:Sapxep_HD(HD);break;
		}
	}
	while(menu!=0);
}



