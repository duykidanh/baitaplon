#include"header.h"
//Xuat DS Sach
void Output(Book a, int n)
{
	upperAll(a.MaSach);
	printf("\n|%-3d|%-7s|%-45s|%-20s|%-18s|%-5d|%-10s|%-4d|", n, a.MaSach, a.TenSach, a.TacGia, a.TheLoai, a.NamXB, a.NhaXuatBan, a.SoLuong);
	printLine(1);
}
void listBook(Book a[], int n)
{
	Contents(1);
	for (int i = 0; i < n; i++)
	{
		Output(a[i], i + 1);
	}
}
