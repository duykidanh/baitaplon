#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct
{
	int ngay, thang, nam;
} Date;

typedef struct
{
	char TenNguoiMuon[100];
	Date NgayMuon;
	Date NgayTra;
} Human;

typedef struct Sach
{
	char TenSach[100];
	char TacGia[100];
	char TheLoai[50];
	char MaSach[10];
	char NhaXuatBan[50];
	int NamXB;
	int SoLuong;
	int SLNguoiMuon;
	Human NguoiMuon[50];
} Book;

//Nguyen mau ham
void Upper(char &c);
void upperAll(char c[]);
void upperFirstLetter(char c[]);
void keyWord(char keyword[]);
void NhapDate(Date &a);
int SoSanhNgay(Date a, Date b);
void printLine(int n);
void mucLuc(int n);
int CheckHuman(Human a[],int x);
void Borrower(Human &human);
void Borrow(Book &a);
int Check(Book a[], int n, int x);
void Nhap(Book &a);
void ThemSach(Book a[], int &SoSach);
void XuatDate(Date a);
void XuatNguoiMuon(Human a, int STT, char tensach[]);
void nguoiMuonTheoSach(Book a);
void DSNguoiMuon(Book a[], int n);
void Xuat(Book a, int n);
void XuatDS(Book a[], int n);
void SapXepMa(Book a[], int n);
int findString(char str[],char keyword[]);
Book Search(Book a[], int n);
void replace_underscores(char *str);
void replace_string_underscores(Book a[], int n);
void replace_spaces(char *str);
void outPutFile(Book a[], char fileName[], int n);
int inputFile(Book a[], char fileName[]);
void pressAnyKey();
void TraSach(Book a[], char ten[], int n);
void MuonSach(Book a[], int n);
void Xoa(Book a[], int &n);
void SuaNguoiMuon(Human &human, int e);
void SuaDSNguoiMuon(Human human[], int e, int n);
void Sua1(Book &a);
void Sua(Book a[], int n);
void ChinhSua(Book a[], int &n);

//Ham Main
int main()
{
	/*luu y: chi can nhap thong tin thi file se tu dong tao o o dia D voi ten la quanLiThuVien
			 hoac co the tu tao file va thay doi dia chi o fileName	 */
	char fileName[] = "D:\\quanLiThuVien.txt";
	
	Book a[50];
	int soLuongSach = inputFile(a, fileName);
	char choice;
	replace_string_underscores(a, soLuongSach);
	
	do
	{
		printf("\n                  QUAN LI THU VIEN           \n");
		printf("   _--------------------_ _-------------------_\n");
		printf("  | |                    |                   | |\n");
		printf("  | | 1/ Them sach       | 2/Xuat DS sach    | |\n");
		printf("  | |                    |                   | |\n");
		printf("  | | 3/ Muon sach       | 4/Ghi File        | |\n");
		printf("  | |                    |                   | |\n");
		printf("  | | 5/ Tim kiem        | 6/Chinh sua       | |\n");
		printf("  | |                    |                   | |\n");
		printf("  | | 0/ Thoat           |                   | |\n");
		printf("  | |_------------------_^_-----------------_| |\n");
		printf("  |_--------------------_|_-------------------_|\n");
		printf("\n\nMoi nhap lua chon: ");
		fflush(stdin);
		scanf("%c", &choice);
		fflush(stdin);
		switch (choice)
		{
		case '1':
			ThemSach(a, soLuongSach);
			pressAnyKey();
			break;
		case '2':
			if (soLuongSach <= 0)
			{
				printf("Chua co thong tin, vui long nhap thong tin!!!!");
			}
			else
			{
				SapXepMa(a, soLuongSach);
				XuatDS(a, soLuongSach);
			}
			pressAnyKey();
			break;
		case '3':
			if (soLuongSach <= 0)
			{
				printf("Chua co thong tin, vui long nhap thong tin!!!!");
			}
			else
			{
				MuonSach(a, soLuongSach);
			}
			pressAnyKey();
			break;
		case '4':
			if (soLuongSach <= 0)
			{
				printf("Chua co thong tin, vui long nhap thong tin!!!!");
			}
			else
			{
				outPutFile(a, fileName, soLuongSach);
			}
			printf("\nGhi thong tin vao file %s thanh cong!", fileName);
			pressAnyKey();
			break;
		case '5':
			if (soLuongSach <= 0)
			{
				printf("Chua co thong tin, vui long nhap thong tin!!!!");
			}
			else
			{
				Search(a, soLuongSach);
			}
			pressAnyKey();
			break;
		case '6':
			if (soLuongSach <= 0)
			{
				printf("Chua co thong tin, vui long nhap thong tin!!!!");
			}
			else
			{
				ChinhSua(a, soLuongSach);
			}
			pressAnyKey();
			break;

		case '0':
			printf("Ban da chon thoat chuong trinh");
			break;
		default:
			printf("Nhap sai vui long nhap lai.\n");
			pressAnyKey();
			break;
		}
	} while (choice != '0');
}

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
void keyWord(char keyword[])
{
	fflush(stdin);
	gets(keyword);
	upperFirstLetter(keyword);
}
//Nhap Ngay Thang Nam
void NhapDate(Date &a)
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
//So sanh ngay muon va ngay tra
int SoSanhNgay(Date a, Date b)
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
		for(int i=0;i<94;++i){
			if(i==0 || i == 4 || i == 50 || i == 71 || i== 82 || i== 93)
			printf("|");
			else printf("_");
		}
	}
}
//Muc Luc
void mucLuc(int n)
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
		for (int i = 0; i < 92; ++i)
		{
			printf("_");
		}
		printf("\n|%-3s|%-45s|%-20s|%-10s|%-10s|", "STT", "Ten sach", "Ten nguoi muon", "Ngay muon", "Ngay tra");
		printLine(n);
	}
}

int CheckHuman(Human a[],int x){
	for(int i=0;i<x;++i){
		if(strcmp((a[i].TenNguoiMuon),(a[x].TenNguoiMuon))==0){
			return 0;
			break;
		}
	}
	return 1;
}
void Borrower(Human &human)
{
	printf("Nhap ten nguoi muon: ");
	fflush(stdin);
	gets(human.TenNguoiMuon);
	upperFirstLetter(human.TenNguoiMuon);
	do
	{
		printf("Nhap ngay muon: \n");
		NhapDate(human.NgayMuon);
		printf("Nhap ngay tra: \n");
		NhapDate(human.NgayTra);
		if (SoSanhNgay(human.NgayMuon, human.NgayTra) == 1)
		{
			printf("\nNgay muon va ngay tra khong hop le!\nYeu cau nhap lai.\n");
		}
		else
			break;
	} while ((SoSanhNgay(human.NgayMuon, human.NgayTra) == 1));
}
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
//Nhap thong tin sach
void Nhap(Book &a)
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
void ThemSach(Book a[], int &SoSach)
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
			Nhap(a[i]);
			if (Check(a, SoSach, i) == 0)
			{
				printf("Ma sach/Ten sach da duoc su dung! Xin moi nhap lai.");
			}
		} while (Check(a, SoSach, i) == 0);
	}
}
//Xuat ngay thang nam
void XuatDate(Date a)
{
	printf("%2d/%2d/%4d", a.ngay, a.thang, a.nam);
}
//Xuat DS nguoi muon
void XuatNguoiMuon(Human a, int STT, char tensach[])
{
	printf("\n|%-3d|%-45s|%-20s|", STT, tensach, a.TenNguoiMuon);
	XuatDate(a.NgayMuon);
	printf("|");
	XuatDate(a.NgayTra);
	printf("|");
	printLine(2);
}
void nguoiMuonTheoSach(Book a)
{
	mucLuc(2);
	for (int i = 0; i < a.SLNguoiMuon; ++i)
	{
		XuatNguoiMuon(a.NguoiMuon[i], i + 1, a.TenSach);
	}
}
void DSNguoiMuon(Book a[], int n)
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
		mucLuc(2);
		for (int i = 0; i < n; ++i)
		{
			if (a[i].SLNguoiMuon > 0)
			{
				for (int j = 0; j < a[i].SLNguoiMuon; ++j)
				{
					++dem;
					XuatNguoiMuon(a[i].NguoiMuon[j], dem, a[i].TenSach);
				}
			}
		}
	}
}
//Xuat DS Sach
void Xuat(Book a, int n)
{
	upperAll(a.MaSach);
	printf("\n|%-3d|%-7s|%-45s|%-20s|%-18s|%-5d|%-10s|%-4d|", n, a.MaSach, a.TenSach, a.TacGia, a.TheLoai, a.NamXB, a.NhaXuatBan, a.SoLuong);
	printLine(1);
}
void XuatDS(Book a[], int n)
{
	mucLuc(1);
	for (int i = 0; i < n; i++)
	{
		Xuat(a[i], i + 1);
	}
}
//ham sap xep
void SapXepMa(Book a[], int n)
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

int findString(char str[],char keyword[]){
	char b[100];
	
	if(strstr(strupr(strcpy(b,str)), strupr(keyword)) != NULL){
		return 1;
	}
	return 0;
}

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
				mucLuc(1);
				Xuat(a[i], 1);
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
				mucLuc(1);
				Xuat(a[i], 1);
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
				mucLuc(1);
				Xuat(a[i], dem);
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
				mucLuc(1);
				Xuat(a[i], dem);
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
//Ham xuat file
void outPutFile(Book a[], char fileName[], int n)
{
	FILE *fileptr;
	fileptr = fopen(fileName, "w");
	//bien phu de mang gia tri copy
	char tenSach[100] = "";
	char tacGia[50] = "";
	char theLoai[50] = "";
	char maSach[10] = "";
	char nhaXB[50] = "";
	char tenNguoiMuon[20] = "";
	fprintf(fileptr, "%45s%20s%18s%7s%13s%13s%15s%18s\n", "Ten Sach", "Tac gia", "The Loai", "Ma Sach", "NXB", "Nam XB", "So Luong", "SL nguoi muon");
	fflush(stdin);
	for (int i = 0; i < n; i++)
	{
		//copy chuoi va thay the cac khoang trang trong chuoi bang dau '_'
		strcpy(tenSach, a[i].TenSach);
		replace_spaces(tenSach);
		strcpy(tacGia, a[i].TacGia);
		replace_spaces(tacGia);
		strcpy(theLoai, a[i].TheLoai);
		replace_spaces(theLoai);
		strcpy(maSach, a[i].MaSach);
		replace_spaces(maSach);
		strcpy(nhaXB, a[i].NhaXuatBan);
		replace_spaces(nhaXB);
		fprintf(fileptr, "%45s%20s%18s%7s%13s%13d%15d%18d\n", tenSach, tacGia, theLoai, maSach, nhaXB, a[i].NamXB, a[i].SoLuong, a[i].SLNguoiMuon);
	for(int j=0;j<a[i].SLNguoiMuon;j++){
		strcpy(tenNguoiMuon, a[i].NguoiMuon[j].TenNguoiMuon);
				replace_spaces(tenNguoiMuon);
		fprintf(fileptr, "%20s%8d%8d%8d%8d%8d%8d\n", tenNguoiMuon, a[i].NguoiMuon[j].NgayMuon.ngay, a[i].NguoiMuon[j].NgayMuon.thang, a[i].NguoiMuon[j].NgayMuon.nam, a[i].NguoiMuon[j].NgayTra.ngay, a[i].NguoiMuon[j].NgayTra.thang, a[i].NguoiMuon[j].NgayTra.nam);
	}
//	}			
	}
	fclose(fileptr);
}
//Ham doc file
int inputFile(Book a[], char fileName[])
{
	FILE *fileptr;
	fileptr = fopen(fileName, "r");
	int i = 0;
	char line[300];

	if (fileptr == NULL)
	{
		printf("Khong tim thay file!.\n");
	}
	// doc thong tin sach

	//ham fgets se lay mot dong va dat con tro chuot o dau dong tiep theo
	fgets(line, sizeof(line), fileptr);

	while (fscanf(fileptr, "%45s%20s%18s%7s%13s%13d%15d%18d\n", &a[i].TenSach, &a[i].TacGia,
				  &a[i].TheLoai, &a[i].MaSach, &a[i].NhaXuatBan, &a[i].NamXB, &a[i].SoLuong,
				  &a[i].SLNguoiMuon) != EOF)
	{
		if(a[i].SLNguoiMuon>0){	
			for(int j=0;j<a[i].SLNguoiMuon;++j){
				fscanf(fileptr, "%20s%8d%8d%8d%8d%8d%8d\n", &a[i].NguoiMuon[j].TenNguoiMuon, &a[i].NguoiMuon[j].NgayMuon.ngay, &a[i].NguoiMuon[j].NgayMuon.thang, &a[i].NguoiMuon[j].NgayMuon.nam, &a[i].NguoiMuon[j].NgayTra.ngay, &a[i].NguoiMuon[j].NgayTra.thang, &a[i].NguoiMuon[j].NgayTra.nam);
	}
		}
		i++;
	}
	printf("So luong sach co san trong file la: %d\n", i);
	fclose(fileptr);
	// tra ve so luong sach duoc doc tu file
	return i;
}
void pressAnyKey()
{
	printf("\n\nNhan phim bat ky de tiep tuc...");
	fflush(stdin);
	getch();
	system("cls");
}
//Tra sach
void TraSach(Book a[], char ten[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < a[i].SLNguoiMuon; ++j)
		{
			if (strcmp(a[i].NguoiMuon[j].TenNguoiMuon, ten) == 0)
			{
				if (dem == 0)
					mucLuc(2);
					XuatNguoiMuon(a[i].NguoiMuon[j], dem + 1, a[i].TenSach);
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
//Muon sach
void MuonSach(Book a[], int n)
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
		DSNguoiMuon(a, n);
		break;
	case 2:
		int e;
		XuatDS(a, n);
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
			TraSach(a,ten,n);
		}
	}
}
void Xoa(Book a[], int &n)
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
				mucLuc(1);
				Xuat(a[i], i + 1);
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
				mucLuc(1);
				Xuat(a[i], i + 1);
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
void SuaNguoiMuon(Human &human, int e)
{
	switch (e)
	{
	case 1:
	{
		printf("\nNhap lai ten nguoi muon: ");
		fflush(stdin);
		gets(human.TenNguoiMuon);
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
				NhapDate(human.NgayMuon);
			}
			else
			{
				printf("Nhap ngay tra: \n");
				NhapDate(human.NgayTra);
			}
			if (SoSanhNgay(human.NgayMuon, human.NgayTra) == 1)
			{
				printf("\nNgay muon va ngay tra khong hop le!\nYeu cau nhap lai.\n");
			}
			else
				break;
		} while ((SoSanhNgay(human.NgayMuon, human.NgayTra) == 1));
	}
	}
}
void SuaDSNguoiMuon(Human human[], int e, int n)
{
	int i;
	do
	{
		printf("Chon vi tri nguoi muon can sua: ");
		scanf("%d", &i);
	} while (i <= 0 || i > n);
	SuaNguoiMuon(human[i - 1], e);
}
void Sua1(Book &a)
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
		nguoiMuonTheoSach(a);
		int e;
		do
		{
			printf("\nNhap phan muon sua trong thong tin nguoi muon: ");
			scanf("%d", &e);
		} while (e < 1 || e > 3);
		SuaDSNguoiMuon(a.NguoiMuon, e, a.SLNguoiMuon);
		break;
	}
	}
}
void Sua(Book a[], int n)
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
				mucLuc(1);
				Xuat(a[i], i + 1);
				do
				{
					printf("\n");
					Sua1(a[i]);
					if (Check(a, n, i) == 0)
					{
						printf("\nMa sach/Ten sach da duoc su dung! Xin moi nhap lai Ma sach/Ten Sach.");
					}
				} while (Check(a, n, i) == 0);
				printf("\nThong tin sach sau khi sua:\n");
				mucLuc(1);
				Xuat(a[i], i + 1);
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
				mucLuc(1);
				Xuat(a[i], i + 1);
				do
				{
					printf("\n");
					Sua1(a[i]);
					if (Check(a, n, i) == 0)
					{
						printf("\nMa sach/Ten sach da duoc su dung! Xin moi nhap lai Ma sach/Ten Sach.");
					}
				} while (Check(a, n, i) == 0);
				printf("\nThong tin sach sau khi sua:\n");
				mucLuc(1);
				Xuat(a[i], i + 1);
			}
		}
		break;
	}
	case 3:
		break;
	}
}
void ChinhSua(Book a[], int &n)
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
		Sua(a, n);
		break;
	case 2:
		Xoa(a, n);
		break;
	default:
		break;
	}
}
