#include"header.h"
//Nhap thong tin sach
void Input(Book &a)
{
	a.SLNguoiMuon = 0;
	printf("Nhap ma sach: ");
	keyWord(a.MaSach);
	upperAll(a.MaSach);
	printf("Nhap ten sach: ");
	keyWord(a.TenSach);
	printf("Nhap ten tac gia: ");
	keyWord(a.TacGia);
	printf("Nhap the loai: ");
	keyWord(a.TheLoai);
	printf("Nhap nam xuat ban: ");
	scanf("%d", &a.NamXB);
	printf("Nhap ten nha xuat ban: ");
	keyWord(a.NhaXuatBan);
	do
	{
		printf("Nhap so luong hien co: ");
		scanf("%d", &a.SoLuong);
		if (a.SoLuong < 1)
		{
			printf("So luong khong hop le!\nYeu cau nhap lai.\n");
		}
	} while (a.SoLuong < 1);
}
//Them Sach
void addBook(Book a[], int &SoSach)
{
	int n, add;
	n = SoSach;
	printf("Nhap so luong sach muon them: ");
	scanf("%d", &add);
	SoSach = n + add;
	for (int i = n; i < SoSach; i++)
	{
		do
		{
			printf("\n\nNhap thong tin sach thu %d\n", i + 1);
			Input(a[i]);
			if (Check(a, SoSach, i) == 0)
			{
				printf("Ma sach/Ten sach da duoc su dung! Xin moi nhap lai.");
			}
		} while (Check(a, SoSach, i) == 0);
	}
}
