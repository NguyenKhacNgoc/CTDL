#include<bits\stdc++.h>
using namespace std;
struct VatTu
{
	int MaVT;
	string TenVT;
	double DonGia;
	int SL;
	string DonViTinh;
	double ThanhTien;
};
void NhapVT(VatTu &vt)
{
	cout<<"Ma vat tu: ";cin>>vt.MaVT;
	cout<<"Ten vat tu: ";cin>>vt.TenVT;
	fflush(stdin);
	cout<<"Don gia: ";cin>>vt.DonGia;
	cout<<"So luong: ";cin>>vt.SL;
	cout<<"Don vi tinh: ";cin>>vt.DonViTinh;
	fflush(stdin);
	vt.ThanhTien = vt.SL*vt.DonGia;
}
void InVT(VatTu vt)
{
	cout<<"\nMa vat tu: "<<vt.MaVT;
	cout<<"\nTen vat tu: "<<vt.TenVT;
	cout<<"\nDon gia: "<<vt.DonGia;
	cout<<"\nSo luong: "<<vt.SL;
	cout<<"\nDon vi tinh: "<<vt.DonViTinh;
	cout<<"\nThanh tien: "<<vt.ThanhTien;
}
