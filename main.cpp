#include<bits\stdc++.h>
#include "nhanvien.cpp"
#include "vattu.cpp"
#include "hoadon.cpp"
using namespace std;
int main(int argc, char const *argv[])
{
	int sel;
	do
	{
		cout<<"----------Cong ty san xuat xay dung----------";
		cout<<"\n 		 1. Quan ly nhan vien";
		cout<<"\n 		 2. Quan ly hoa don ban hang";
		cout<<"\n 		 3. Thoat chuong trinh";
		cout<<"\nHay chon: ";cin>>sel;
		switch(sel)
		{
			case 1:MenuNV();break;
			case 2:MenuHD();break;
			case 3:exit(1);
		}
	}
	while(sel!=0);
	return 0;
}