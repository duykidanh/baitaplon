#include"header.h"
//ham tim kiem
Book Search(Book a[], int n)
{
	char keyword[100];
	char b[100] = "";
	int dem = 0;
	printf("\n Nhap 1 de tim kiem theo ten sach");
	printf("\n Nhap 2 de tim kiem theo the loai");
	printf("\n Nhap 3 de tim kiem theo tac gia");
	printf("\n Nhap 4 de tim kiem theo nha san xuat");
	printf("\n Nhap 5 de bo qua");
	int x;
	printf("\nXin moi chon theo y muon: ");
	scanf("%d", &x);
	switch (x)
	{
	case 1:
		printf("\nNhap tu khoa can tim: ");
		keyWord(keyword);
		for (int i = 0; i < n; i++)
		{
			if (findString(a[i].TenSach,keyword) == 1)
			{
				dem++;
				Contents(1);
				Output(a[i], 1);
				printf("\n");
			}
		}
		if (dem == 0)
			printf("\nKhong tim thay tu khoa");
		break;
	case 2:
		printf("\nNhap tu khoa can tim: ");
		keyWord(keyword);
		for (int i = 0; i < n; i++)
		{
			if (findString(a[i].TheLoai,keyword) == 1)
			{
				dem++;
				Contents(1);
				Output(a[i], 1);
				printf("\n");
			}
		}
		if (dem == 0)
			printf("\nKhong tim thay tu khoa");
		break;
	case 3:
		printf("\nNhap tu khoa can tim: ");
		keyWord(keyword);
		for (int i = 0; i < n; i++)
		{
			if (findString(a[i].TacGia,keyword) == 1)
			{
				++dem;
				Contents(1);
				Output(a[i], dem);
			}
		}
		if (dem == 0)
			printf("\nKhong tim thay tu khoa");
		break;
	case 4:
		printf("\nNhap tu khoa can tim: ");
		keyWord(keyword);
		for (int i = 0; i < n; i++)
		{
			if (findString(a[i].NhaXuatBan,keyword) == 1)
			{
				++dem;
				Contents(1);
				Output(a[i], dem);
			}
		}
		if (dem == 0)
			printf("\nKhong tim thay tu khoa");
		break;
	case 5:
		break;
	default:
		printf("\nNhap sai");
		break;
	}
}
