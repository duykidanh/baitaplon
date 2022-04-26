#include"header.h"
void Delete(Book a[], int &n)
{
	//Tim kiem phan tu ma ban muon xoa
	int x, dem = 0;
	char s[100];
	do
	{
		printf("\n Nhap 1 de tim kiem theo ten sach");
		printf("\n Nhap 2 de tim kiem theo ma sach");
		printf("\n Nhap 3 de thoat");
		printf("\n Nhap cach thuc tim kiem: ");
		scanf("%d", &x);
	} while (x < 1 || x > 3);
	switch (x)
	{
	case 1: //Tim ten phan tu muon xoa
		printf("\nNhap ten cuon sach can xoa: ");
		fflush(stdin);
		keyWord(s);
		for (int i = 0; i < n; i++)
		{
			if (findString(a[i].TenSach,s) == 1)
			{
				Contents(1);
				Output(a[i], i + 1);
				int choice;
				do
				{
					printf("\nNhap 0 de xoa va 1 de bo qua:");
					scanf("%d", &choice);
				} while (choice < 0 || choice > 1);
				if (choice == 0)
				{
					if (n > 1)
					{
						for (int j = i; j < n; j++)
							a[j] = a[j + 1];
					}
					--n;
				}
				++dem;
			}
		}
		if (dem == 0)
		{
			printf("\nPhan tu can xoa khong co trong danh sach");
			break;
		}
		printf("\nDanh sach da duoc cap nhat.");
		break;
	case 2: //Tim ma sach can xoa
		printf("\nNhap ma cua cuon sach can xoa: ");
		fflush(stdin);
		gets(s);
		upperAll(s);
		for (int i = 0; i < n; i++)
		{
			if (findString(a[i].MaSach,s) == 1)
			{
				Contents(1);
				Output(a[i], i + 1);
				int choice;
				do
				{
					printf("\nNhap 0 de xoa va 1 de bo qua:");
					scanf("%d", &choice);
				} while (choice < 0 || choice > 1);
				if (choice == 0)
				{
					if (n > 1)
					{
						for (int j = i; j < n; j++)
							a[j] = a[j + 1];
					}
					--n;
				}
				++dem;
			}
		}
		if (dem == 0)
		{
			printf("\nPhan tu can xoa khong co trong danh sach");
			break;
		}
		printf("\nDanh sach da duoc cap nhat.");
		break;
	case 3:
		break;
	}
}
void UpdateBorrower(Human &human, int e)
{
	switch (e)
	{
	case 1:
	{
		printf("\nNhap lai ten nguoi muon: ");
		fflush(stdin);
		gets(human.TenNguoiMuon);
		upperFirstLetter(human.TenNguoiMuon);
		break;
	}
	case 2:
	case 3:
	{
		do
		{
			if (e == 2)
			{
				printf("Nhap ngay muon: \n");
				inputDate(human.NgayMuon);
			}
			else
			{
				printf("Nhap ngay tra: \n");
				inputDate(human.NgayTra);
			}
			if (compareDate(human.NgayMuon, human.NgayTra) == 1)
			{
				printf("\nNgay muon va ngay tra khong hop le!\nYeu cau nhap lai.\n");
			}
			else{
				if(DateNow(human.NgayTra) == 0){
			    strcpy(human.TinhTrang,"Qua han");
	        	}
		        else strcpy(human.TinhTrang, "");
				break;
			}
		} while ((compareDate(human.NgayMuon, human.NgayTra) == 1));
	}
	}
}
void UpdatelistBorrower(Human human[], int e, int n)
{
	int i;
	do
	{
		printf("Chon vi tri nguoi muon can sua: ");
		scanf("%d", &i);
	} while (i <= 0 || i > n);
	UpdateBorrower(human[i - 1], e);
}
void Update1(Book &a)
{
	//Chon phan thong tin can sua
	int x;
	do
	{
		printf("\n Nhap 1 de sua ten sach");
		printf("\n Nhap 2 de sua tac gia");
		printf("\n Nhap 3 de sua the loai");
		printf("\n Nhap 4 de sua ma sach");
		printf("\n Nhap 5 de sua nha xuat ban");
		printf("\n Nhap 6 de sua nam xuat ban");
		printf("\n Nhap 7 de sua so luong");
		printf("\n Nhap 8 de sua nguoi muon");
		printf("\n Nhap 9 de bo qua");
		printf("\n\n Nhap lua chon: ");
		scanf("%d", &x);
	} while (x < 1 || x > 9);
	switch (x)
	{
	case 1: //Ten sach
	{
		printf("\nTen sau khi sua la ");
		keyWord(a.TenSach);
		break;
	}
	case 2: //Tac gia
	{
		printf("\nTen tac gia sau khi sua la ");
		keyWord(a.TacGia);
		break;
	}
	case 3: //The loai
	{
		printf("\nThe loai sau khi sua la ");
		keyWord(a.TheLoai);
		break;
	}
	case 4: //Ma sach
	{
		printf("\nMa sach sau khi sua la");
		keyWord(a.MaSach);
		break;
	}
	case 5: //Nha xuat ban
	{
		printf("\nTen nha xb sau khi sua la ");
		keyWord(a.NhaXuatBan);
		break;
	}
	case 6: //Nam xuat ban
	{
		printf("\nNam xuat ban sau khi sua la ");
		scanf("%d", &a.NamXB);
		break;
	}
	case 7: //So luong
	{
		do
		{
			printf("\nSo luong sach sau khi sua la ");
			fflush(stdin);
			scanf("%d", a.SoLuong);
		} while (a.SoLuong > 0);
		break;
	}
	case 8: // Thong tin nguoi muon
	{
		//Nhap phan thong tin cua nguoi muon can sua
		bookBorrower(a);
		int e;
		do
		{
			printf("\n Nhap 1 de sua ten sach");
		    printf("\n Nhap 2 de sua tac gia");
		    printf("\n Nhap 3 de sua the loai");
			printf("\n\nNhap phan muon sua trong thong tin nguoi muon: ");
			scanf("%d", &e);
		} while (e < 1 || e > 3);
		UpdatelistBorrower(a.NguoiMuon, e, a.SLNguoiMuon);
		break;
	}
	}
}
void Update(Book a[], int n)
{
	int x;
	char o[100];
	do
	{
		printf("\n Nhap 1 de tim kiem theo ten sach");
		printf("\n Nhap 2 de tim kiem theo ma sach");
		printf("\n Nhap 3 de thoat");
		printf("\n Nhap cach thuc tim kiem: ");
		scanf("%d", &x);
	} while (x < 1 || x > 3);
	switch (x)
	{
	case 1:
	{
		printf("\nNhap ten sach: ");
		fflush(stdin);
		keyWord(o);
		for (int i = 0; i < n; i++)
		{
			if (findString(a[i].TenSach,o) == 1)
			{
				Contents(1);
				Output(a[i], i + 1);
				do
				{
					printf("\n");
					Update1(a[i]);
					if (Check(a, n, i) == 0)
					{
						printf("\nMa sach/Ten sach da duoc su dung! Xin moi nhap lai Ma sach/Ten Sach.");
					}
				} while (Check(a, n, i) == 0);
				printf("\nThong tin sach sau khi sua:\n");
				Contents(1);
				Output(a[i], i + 1);
			}
		}
		break;
	}
	case 2:
	{
		printf("\nNhap ma sach: ");
		fflush(stdin);
		keyWord(o);
		upperAll(o);
		for (int i = 0; i < n; i++)
		{
			if (findString(a[i].MaSach,o) == 1)
			{
				Contents(1);
				Output(a[i], i + 1);
				do
				{
					printf("\n");
					Update1(a[i]);
					if (Check(a, n, i) == 0)
					{
						printf("\nMa sach/Ten sach da duoc su dung! Xin moi nhap lai Ma sach/Ten Sach.");
					}
				} while (Check(a, n, i) == 0);
				printf("\nThong tin sach sau khi sua:\n");
				Contents(1);
				Output(a[i], i + 1);
			}
		}
		break;
	}
	case 3:
		break;
	}
}
void UpdateBook(Book a[], int &n)
{
	int x;
	do
	{
		printf("\n Nhap 1 de sua thong tin sach ");
		printf("\n Nhap 2 de xoa sach");
		printf("\n Nhap 3 de thoat");
		printf("\n\n Nhap thao tac: ");
		scanf("%d", &x);
	} while (x < 1 || x > 3);
	switch (x)
	{
	case 1:
		Update(a, n);
		break;
	case 2:
		Delete(a, n);
		break;
	default:
		break;
	}
}

