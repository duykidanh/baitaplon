#include"header.h"
//Ham in hoa
void Upper(char &c)
{
	if (c >= 'a' && c <= 'z')
		c -= ('a' - 'A');
}
//Ham in hoa toan bo
void upperAll(char c[])
{
	for (int i = 0; i < strlen(c); ++i)
	{
		Upper(c[i]);
	}
}
//Ham in hoa chu cai dau
void upperFirstLetter(char c[])
{
	Upper(c[0]);
	for (int i = 0; i < strlen(c); ++i)
	{
		if (c[i] == ' ')
		{
			Upper(c[i + 1]);
		}
	}
}
//ham nhap tu khoa
void keyWord(char keyword[])
{
	fflush(stdin);
	gets(keyword);
	upperFirstLetter(keyword);
}
//Nhap Ngay Thang Nam
void inputDate(Date &a)
{
	int dem = 0;
	while (true)
	{
		printf("\tNgay: ");
		scanf("%d", &a.ngay);
		printf("\tThang: ");
		scanf("%d", &a.thang);
		printf("\tNam: ");
		scanf("%d", &a.nam);
		if (a.nam > 1900)
		{
			switch (a.thang)
			{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
			{
				if (a.ngay < 1 || a.ngay > 31)
				{
					dem = 1;
					break;
				}
				else
					break;
			}
			case 4:
			case 6:
			case 9:
			case 11:
			{
				if (a.ngay < 1 || a.ngay > 30)
				{
					dem = 1;
					break;
				}
				else
					break;
			}
			case 2:
			{
				if (a.nam % 4 == 0)
				{
					if (a.ngay < 1 || a.ngay > 29)
					{
						dem = 1;
						break;
					}
					else
						break;
				}
				else
				{
					if (a.ngay < 1 || a.ngay > 28)
					{
						dem = 1;
						break;
					}
					else
						break;
				}
			}
			default:
			{
				dem = 1;
				break;
			}
			}
		}
		else
			dem = 1;
		if (dem == 1)
		{
			printf("\nNgay thang nam khong hop le!\nVui long nhap lai.\n");
			dem = 0;
		}
		else
			break;
	}
}
//Xuat ngay thang nam
void outputDate(Date a)
{
	printf("%2d/%2d/%4d", a.ngay, a.thang, a.nam);
}
//So sanh ngay muon va ngay tra
int compareDate(Date a, Date b)
{
	if (a.nam > b.nam)
	{
		return 1;
	}
	else if (a.nam == b.nam)
	{
		if (a.thang > b.thang)
		{
			return 1;
		}
		else if (a.thang == b.thang)
		{
			if (a.ngay > b.ngay)
			{
				return 1;
			}
		}
	}
	return 0;
}
//so sanh ngay vua nhap voi ngay hien tai
int DateNow(Date a){
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int dayNow = tm.tm_mday;
	int monNow = tm.tm_mon + 1;
	int yearNow = tm.tm_year + 1900;
		if (a.nam > yearNow)
	{
		return 1;
	}
	else if (a.nam == yearNow)
	{
		if (a.thang > monNow)
		{
			return 1;
		}
		else if (a.thang == monNow)
		{
			if (a.ngay > dayNow)
			{
				return 1;
			}
		}
	}
	return 0;
}

//ham ke ngang
void printLine(int n)
{
	if (n == 1)
	{
		printf("\n");
		for(int i=0;i<121;++i){
			if(i==0 || i==4 || i == 12 || i== 58 || i == 79 || i ==98 || i==104 || i ==115 || i == 120)
				printf("|");
			else printf("_");
			//in dau '|' o vi tri i va in '_' o nhung vi tri con lai
		}
	}
	else
	{
		printf("\n");
		for(int i=0;i<105;++i){
			if(i==0 || i == 4 || i == 50 || i == 71 || i== 82 || i== 93 || i == 104)
			printf("|");
			else printf("_");
		}
	}
}
//Muc Luc
void Contents(int n)
{
	if (n == 1)
	{
		printf(" ");
		for (int i = 0; i < 119; i++)
		{
			printf("_");
		}
		printf("\n|%-3s|%-7s|%-45s|%-20s|%-18s|%-5s|%-10s|%-4s|", "STT", "Ma sach", " Ten sach", " Tac gia", " The loai", " Nam", " NXB", " SL");
		printLine(n);
	}
	else
	{
		printf(" ");
		for (int i = 0; i < 103; ++i)
		{
			printf("_");
		}
		printf("\n|%-3s|%-45s|%-20s|%-10s|%-10s|%-10s|", "STT", "Ten sach", "Ten nguoi muon", "Ngay muon", "Ngay tra", "Ghi chu");
		printLine(n);
	}
}
//kiem tra ten nguoi muon co bi trung
int CheckHuman(Human a[],int x){
	for(int i=0;i<x;++i){
		if(strcmp((a[i].TenNguoiMuon),(a[x].TenNguoiMuon))==0){
			return 0;
			break;
		}
	}
	return 1;
}
//Ham kiem tra ma sach hoac ten sach bi trung
int Check(Book a[], int n, int x)
{
	if (n > 0)
	{
		for (int i = 0; i < n; ++i)
		{
			if (i != x)
			{
				if (strcmp(a[x].MaSach, a[i].MaSach) == 0 || strcmp(a[x].TenSach, a[i].TenSach) == 0)
				{
					return 0;
					break;
				}
			}
		}
	}
	return 1;
}
//ham sap xep
void Sort(Book a[], int n)
{
	int pos;
	Book x;
	for (int i = 1; i < n; ++i)
	{
		x = a[i];
		pos = i - 1;
		while ((pos >= 0) && (strcmp(a[pos].MaSach, x.MaSach) > 0))
		{
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
	}
}
//ham tim kiem tu khoa
int findString(char str[],char keyword[]){
	char b[100];
	
	if(strstr(strupr(strcpy(b,str)), strupr(keyword)) != NULL){
		return 1;
	}
	return 0;
}
//ham thay the ky tu '_' bang khoang trang
void replace_underscores(char *str)
{
	while (*str)
	{
		if (*str == '_')
			*str = ' ';
		str++;
	}
}
//ham thay the ki tu '_' bang khoang trang cua thong tin trong mang
void replace_string_underscores(Book a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		replace_underscores(a[i].TenSach);
		replace_underscores(a[i].MaSach);
		replace_underscores(a[i].TacGia);
		replace_underscores(a[i].TheLoai);
		replace_underscores(a[i].NhaXuatBan);
		if (a[i].SLNguoiMuon > 0)
		{
			for (int j = 0; j < a[i].SLNguoiMuon; ++j)
			{
				replace_underscores(a[i].NguoiMuon[j].TenNguoiMuon);
			}
		}
	}
}
//ham thay the khoang trong bang dau'_'
void replace_spaces(char *str)
{
	while (*str)
	{
		if (*str == ' ')
			*str = '_';
		str++;
	}
}
//nhan phim bat ky de tiep tuc
void pressAnyKey()
{
	printf("\n\nNhan phim bat ky de tiep tuc...");
	fflush(stdin);
	getch();
	system("cls");
}
