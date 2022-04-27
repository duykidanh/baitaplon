#include"header.h"
//nhap thong tin nguoi muon
void Borrower(Human &human)
{
	printf("Nhap ten nguoi muon: ");
	fflush(stdin);
	gets(human.TenNguoiMuon);
	upperFirstLetter(human.TenNguoiMuon);
	do
	{
		printf("Nhap ngay muon: \n");
		inputDate(human.NgayMuon);
		printf("Nhap ngay tra: \n");
		inputDate(human.NgayTra);
		if (compareDate(human.NgayMuon, human.NgayTra) == 1)
		{
			printf("\nNgay muon va ngay tra khong hop le!\nYeu cau nhap lai.\n");
		}
		else{
			if(DateNow(human.NgayTra) == 0){
			strcpy(human.TinhTrang,"Qua han");
		    }
	    	else strcpy(human.TinhTrang," ");
			break;
		}
	} while ((compareDate(human.NgayMuon, human.NgayTra) == 1));
}
//muon sach
void Borrow(Book &a)
{
	if (a.SoLuong == 0)
	{
		printf("\nKhong du so luong de muon");
	}
	else
	{
		printf("\nNhap 0 de muon va 1 de bo qua: ");
		int u;
		scanf("%d", &u);
		switch (u)
		{
		case 0:
			Borrower(a.NguoiMuon[a.SLNguoiMuon]);
			if(CheckHuman(a.NguoiMuon,a.SLNguoiMuon)==1){
			a.SoLuong--;
			a.SLNguoiMuon++;
			}
			else printf("Sach nay hien %s dang muon . Khong the muon them.",a.NguoiMuon[a.SLNguoiMuon].TenNguoiMuon);
			break;
		case 1:
			break;
		default:
			printf("Nhap sai ");
			Borrow(a);
			break;
		}
	}
}
//Xuat thong tin nguoi muon
void outputBorrower(Human a, int STT, char tensach[])
{
	printf("\n|%-3d|%-45s|%-20s|", STT, tensach, a.TenNguoiMuon);
	outputDate(a.NgayMuon);
	printf("|");
	outputDate(a.NgayTra);
	printf("|%-10s|",a.TinhTrang);
	printLine(2);
}
//xuat thong tin nguoi muon theo ten sach
void bookBorrower(Book a)
{
	Contents(2);
	for (int i = 0; i < a.SLNguoiMuon; ++i)
	{
		outputBorrower(a.NguoiMuon[i], i + 1, a.TenSach);
	}
}
//xuat danh sach nguoi muon
void listBorrower(Book a[], int n)
{
	int SL = 0;
	for (int i = 0; i < n; ++i)
	{
		SL += a[i].SLNguoiMuon;
	}
	if (SL == 0)
		printf("\nDanh sach trong!\n");
	else
	{
		int dem = 0;
		Contents(2);
		for (int i = 0; i < n; ++i)
		{
			if (a[i].SLNguoiMuon > 0)
			{
				for (int j = 0; j < a[i].SLNguoiMuon; ++j)
				{
					++dem;
					outputBorrower(a[i].NguoiMuon[j], dem, a[i].TenSach);
				}
			}
		}
	}
}
//Tra sach
void returnBook(Book a[], char ten[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < a[i].SLNguoiMuon; ++j)
		{
			if (strcmp(a[i].NguoiMuon[j].TenNguoiMuon, ten) == 0)
			{
				if (dem == 0)
					Contents(2);
					outputBorrower(a[i].NguoiMuon[j], dem + 1, a[i].TenSach);
					++dem;
			}
		}
	}
	if (dem == 0)
		printf("\nKhong tim thay ten nguoi muon.");
	else
	{
		int x;
		do
		{
			printf("\nNhap STT nguoi muon tra sach: ");
			scanf("%d", &x);
		} while (x < 1 || x > dem);
		dem=0;
		for (int i = 0; i < n; ++i)
		{ 
            int y=0;
			for (int j = 0; j < a[i].SLNguoiMuon; ++j)
			{
				if (strcmp(a[i].NguoiMuon[j].TenNguoiMuon, ten) == 0)
				{
					if (dem == x - 1)
					{
						for (int k = dem; k < a[i].SLNguoiMuon; k++)
						{
							a[i].NguoiMuon[k] = a[i].NguoiMuon[k + 1];
						}
						--a[i].SLNguoiMuon;
						++a[i].SoLuong;
						++y;
						break;
					}
					++dem;
				}
			}
			if(y==1)
			break;
		}
	}
}
//Menu muon sach
void borrowBook(Book a[], int n)
{
	int x;
	do
	{
		printf("\n Nhap 1 de xuat danh sach nguoi muon sach.");
		printf("\n Nhap 2 de muon sach.");
		printf("\n Nhap 3 de tra sach.");
		printf("\n Nhap 4 de thoat.");
		printf("\n\n Nhap lua chon: ");
		scanf("%d", &x);
	} while (x < 1 || x > 4);
	switch (x)
	{
	case 1:
		listBorrower(a, n);
		break;
	case 2:
		int e;
		listBook(a, n);
		do
		{
			printf("\nNhap STT sach can muon: ");
			scanf("%d", &e);
		} while (e < 1 || e > n + 1);
		Borrow(a[e - 1]);
		break;
	case 3:
		int dem = 0;
		for (int i = 0; i < n; ++i)
		{
			dem += a[i].SLNguoiMuon;
		}
		if (dem > 0)
		{
			char ten[20];
			printf("\nNhap ten nguoi muon: ");
			keyWord(ten);
			returnBook(a,ten,n);
		}
	}
}
