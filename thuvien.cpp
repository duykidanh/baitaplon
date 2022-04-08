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
void gachngang(int n)
{
	if(n==1){
	printf("\n|___|");
	for (int i = 0; i < 7; i++)
	{
		printf("_");
	}
	printf("|");
	for (int i = 0; i < 45; i++)
	{
		printf("_");
	}
	printf("|");
	for (int i = 0; i < 20; i++)
	{
		printf("_");
	}
	printf("|");
	for (int i = 0; i < 18; i++)
	{
		printf("_");
	}
	printf("|");
	for (int i = 0; i < 5; i++)
	{
		printf("_");
	}
	printf("|");
	for (int i = 0; i < 10; i++)
	{
		printf("_");
	}
	printf("|");
	for (int i = 0; i < 4; i++)
	{
		printf("_");
	}
	printf("|");
	}
	else{
		printf("\n|___|");
			for (int i = 0; i < 45; i++)
	{
		printf("_");
	}
	printf("|");
	for (int i = 0; i < 20; i++)
	{
		printf("_");
	}
	printf("|");
	for (int i = 0; i < 10; i++)
	{
		printf("_");
	}
	printf("|");
	for (int i = 0; i < 10; i++)
	{
		printf("_");
	}
	printf("|");
	}
}
//Muc Luc
void mucLuc(int n){
		if(n==1){
		printf(" ");
	for (int i = 0; i < 119; i++)
	{
		printf("_");
	}
	printf("\n|%-3s|%-7s|%-45s|%-20s|%-18s|%-5s|%-10s|%-4s|","STT", "Ma sach", " Ten sach", " Tac gia", " The loai", " Nam", " NXB", " SL");
	gachngang(n);}
	else{
	printf(" ");
		for(int i=0;i<93;++i){
			printf("_");
		}
		printf("\n|%-3s|%-45s|%-20s|%-10s|%-10s|","STT","Ten sach","Ten nguoi muon","Ngay muon","Ngay tra");
		gachngang(n);}
}
//Nhap nguoi muon
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
			a.SoLuong--;
			a.SLNguoiMuon++;
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

//Nhap thong tin sach
void Nhap(Book &a)
{
	a.SLNguoiMuon=0;
	printf("Nhap ma sach: ");
	fflush(stdin);
	gets(a.MaSach);
	upperAll(a.MaSach);
	printf("Nhap ten sach: ");
	gets(a.TenSach);
	upperFirstLetter(a.TenSach);
	printf("Nhap ten tac gia: ");
	gets(a.TacGia);
	upperFirstLetter(a.TacGia);
	printf("Nhap the loai: ");
	gets(a.TheLoai);
	upperFirstLetter(a.TheLoai);
	printf("Nhap nam xuat ban: ");
	scanf("%d", &a.NamXB);
	printf("Nhap ten nha xuat ban: ");
	fflush(stdin);
	gets(a.NhaXuatBan);
	upperFirstLetter(a.NhaXuatBan);
	do
	{
		printf("Nhap so luong hien co: ");
		scanf("%d", &a.SoLuong);
		if (a.SoLuong < 0)
		{
			printf("So luong khong hop le!\nYeu cau nhap lai.\n");
		}
	} while (a.SoLuong < 0);
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
		printf("\n\nNhap thong tin sach thu %d\n", i + 1);
		Nhap(a[i]);
	}
}
//Xuat ngay thang nam
void XuatDate(Date a)
{
	printf("%2d/%2d/%4d", a.ngay, a.thang, a.nam);
}
//Xuat DS nguoi muon
void XuatNguoiMuon(Human a,int STT, char tensach[])
{
	printf("\n|%-3d|%-45s|%-20s|",STT,tensach,a.TenNguoiMuon);
	XuatDate(a.NgayMuon);
	printf("|");
	XuatDate(a.NgayTra);
	printf("|");
}
void nguoiMuonTheoSach(Book a){
	mucLuc(2);
	for(int i=0;i<a.SLNguoiMuon;++i){
		XuatNguoiMuon(a.NguoiMuon[i],i+1,a.TenSach);
	}
}	
void DSNguoiMuon(Book a[],int n)
{
	int SL=0;
	for(int i=0;i<n;++i)
	{
		SL+=a[i].SLNguoiMuon;
	}
	if(SL==0)printf("\nDanh sach trong!\n");
	else
	{
		int dem=0;
		mucLuc(2);
		for(int i=0;i<n;++i)
		{
			if(a[i].SLNguoiMuon>0)
			{
				for(int j=0;j<a[i].SLNguoiMuon;++j)
				{
					++dem;
					XuatNguoiMuon(a[i].NguoiMuon[j],dem,a[i].TenSach);
					gachngang(2);
				}
			}
		}
	}
}
//Xuat DS Sach
void Xuat(Book a,int n)
{
	upperAll(a.MaSach);
	printf("|%-3d|%-7s|%-45s|%-20s|%-18s|%-5d|%-10s|%-4d|",n, a.MaSach, a.TenSach, a.TacGia, a.TheLoai, a.NamXB, a.NhaXuatBan, a.SoLuong);
}
void XuatDS(Book a[], int n)
{
	mucLuc(1);
	for (int i = 0; i < n; i++)
	{
		printf("\n");
		Xuat(a[i],i+1);
		gachngang(1);
	}
}
//ham sap xep
void SapXepTen(Book a[], int n)
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
//nhap keyword
void keyWord(char keyword[])
{
	fflush(stdin);
	gets(keyword);
	upperFirstLetter(keyword);
}
//ham tim kiem
Book Search(Book a[], int n)
{
	char keyword[100];
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
			if (strcmp(keyword, a[i].TenSach) == 0)
			{
				mucLuc(1);
				Xuat(a[i],1);
				++dem;
				break;
			}
		}
		if (dem == 0)
			printf("Khong tim thay tu khoa");
		break;
	case 2:
		printf("\nNhap tu khoa can tim: ");
		keyWord(keyword);
		for (int i = 0; i < n; i++)
		{
			if (strcmp(keyword, a[i].TheLoai) == 0)
			{
				mucLuc(1);
				Xuat(a[i],1);
				++dem;
				break;
			}
		}
		if (dem == 0)
			printf("Khong tim thay tu khoa");
		break;
	case 3:
		printf("\nNhap tu khoa can tim: ");
		keyWord(keyword);
		for (int i = 0; i < n; i++)
		{
			if (strcmp(keyword, a[i].TacGia) == 0)
			{
				++dem;
				mucLuc(1);
				Xuat(a[i],dem);
			}
		}
		if (dem == 0)
			printf("Khong tim thay tu khoa");
		break;
	case 4:
		printf("\nNhap tu khoa can tim: ");
		keyWord(keyword);
		for (int i = 0; i < n; i++)
		{
			if (strcmp(keyword, a[i].NhaXuatBan) == 0)
			{
				++dem;
				mucLuc(1);
				Xuat(a[i],dem);
			}
		}
		if (dem == 0)
			printf("Khong tim thay tu khoa");
		break;
	case 5:
		break;
	default:
		printf("Nhap sai");
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
		if(a[i].SLNguoiMuon>0){
			for(int j=0;j<a[i].SLNguoiMuon;++j){
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
void outPutFile(Book a[], char fileName[], char fileName2[], int n)
{
	FILE *fileptr;
	fileptr = fopen(fileName, "w");
	//bien phu de mang gia tri copy
	char tenSach[100] = "";
	char tacGia[50] = "";
	char theLoai[50] = "";
	char maSach[10] = "";
	char nhaXB[50] = "";

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
	}

	fclose(fileptr);
	
		FILE *file2ptr;
	file2ptr = fopen(fileName2, "w");
	//bien phu de mang gia tri copy
	char tenNguoiMuon[100] = "";
		fprintf(file2ptr,"%20s%8s%8s%8s%8s%8s%8s\n", "Ten Nguoi Muon", "NgayM", "ThangM", "NamM", "NgayT", "ThangT", "Nam T");
	fflush(stdin);
	for(int i=0;i<n;++i){
		if(a[i].SLNguoiMuon>0){
			for(int j=0;j<a[i].SLNguoiMuon;++j){
				strcpy(tenNguoiMuon,a[i].NguoiMuon[j].TenNguoiMuon);
				replace_spaces(tenNguoiMuon);
				
				fprintf(file2ptr,"%20s%8d%8d%8d%8d%8d%8d", tenNguoiMuon, a[i].NguoiMuon[j].NgayMuon.ngay, a[i].NguoiMuon[j].NgayMuon.thang, a[i].NguoiMuon[j].NgayMuon.nam, a[i].NguoiMuon[j].NgayTra.ngay, a[i].NguoiMuon[j].NgayTra.thang, a[i].NguoiMuon[j].NgayTra.nam);
			}
		}
	}
	
	fclose(file2ptr);
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
		i++;
	}

	printf("So luong sach co san trong file la: %d\n", i);
	fclose(fileptr);

	// tra ve so luong sach duoc doc tu file
	return i;
}
int inputFileBorrow(Book a[], char fileName[],int n)
{
	Book b[200];
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

	while (fscanf(fileptr, "%20s%8d%8d%8d%8d%8d%8d\n", &b[i].NguoiMuon[0].TenNguoiMuon, &b[i].NguoiMuon[0].NgayMuon.ngay, &b[i].NguoiMuon[0].NgayMuon.thang, &b[i].NguoiMuon[0].NgayMuon.nam, &b[i].NguoiMuon[0].NgayTra.ngay, &b[i].NguoiMuon[0].NgayTra.thang, &b[i].NguoiMuon[0].NgayTra.nam) != EOF)
	{
		i++;
	}
	int dem=0;
	for(int j=0;j<n;++j){
		if(a[j].SLNguoiMuon>0){
		for(int k=0;k<a[j].SLNguoiMuon;++k){
			for(int h=0;h<strlen(b[dem].NguoiMuon[0].TenNguoiMuon);++h){
			a[j].NguoiMuon[k].TenNguoiMuon[h] = b[dem].NguoiMuon[0].TenNguoiMuon[h];}
			a[j].NguoiMuon[k].NgayMuon.ngay = b[dem].NguoiMuon[0].NgayMuon.ngay;
			a[j].NguoiMuon[k].NgayMuon.thang = b[dem].NguoiMuon[0].NgayMuon.thang;
			a[j].NguoiMuon[k].NgayMuon.nam = b[dem].NguoiMuon[0].NgayMuon.nam;
			a[j].NguoiMuon[k].NgayTra.ngay = b[dem].NguoiMuon[0].NgayTra.ngay;
			a[j].NguoiMuon[k].NgayTra.thang = b[dem].NguoiMuon[0].NgayTra.thang;
			a[j].NguoiMuon[k].NgayTra.nam = b[dem].NguoiMuon[0].NgayTra.nam;
			
			dem++;
		}
		}
	}
	printf("So luong nguoi muon co san trong file la: %d\n", i);
	fclose(fileptr);
	return i;
}

void pressAnyKey()
{
	printf("\n\nNhan phim bat ky de tiep tuc...");
	getch();
	fflush(stdin);
	system("cls");
}
//Muon sach
void MuonSach(Book a[],int n)
{
	int x;
	do{
	printf("\n Nhap 1 de xuat danh sach nguoi muon sach.");
	printf("\n Nhap 2 de muon sach.");
	printf("\n Nhap 3 de thoat.");
	printf("\n\n Nhap lua chon: ");
	scanf("%d",&x);
	}while(x<1 || x>3);
	switch(x)
	{
		case 1:
		DSNguoiMuon(a,n);
		break;
		case 2:
		int e;
		XuatDS(a,n);
		do
		{
		printf("\nNhap STT sach can muon: ");
		scanf("%d",&e);
		}while(e<1||e>n+1);
		Borrow(a[e-1]);
	}
}
void Xoa(Book a[], int n)
{
	//Tim kiem phan tu ma ban muon xoa
	int x, dem = 0;
	char s[100];
	do
	{
		printf("\nNhap du lieu de tim kiem phan tu can xoa ");
		scanf("%d", &x);
	} while (x < 1 || x > 4);
	switch (x)
	{
	case 1: //Tim ten phan tu muon xoa
		printf("\nNhap ten phan tu can xoa ");
		fflush(stdin);
		gets(s);
		for (int i = 0; i < n; i++)
		{
			if (strcmp(s, a[i].TenSach) == 0)
			{
				dem++;
				for (int j = i; j < n; j++)
					a[j] = a[j + 1];
			}
			if (dem == 0)
			{
				printf("\nPhan tu can xoa khong co trong danh sach");
				break;
			}
			--n;
		}
		break;
	case 2: //Tim ma sach can xoa
		printf("\nNhap ma cua cuon sach can xoa ");
		fflush(stdin);
		gets(s);
		for (int i = 0; i < n; i++)
		{
			if (strcmp(s, a[i].MaSach) == 0)
			{
				dem++;
				for (int j = i; j < n; j++)
					a[j] = a[j + 1];
			}
			if (dem == 0)
			{
				printf("\nPhan tu can xoa khong co trong danh sach");
				break;
			}
			--n;
		}
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
		if(e==2){
		printf("Nhap ngay muon: \n");
		NhapDate(human.NgayMuon);
		}
		else{
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
	    printf("\n Nhap 3 de sua tac gia");
	    printf("\n Nhap 4 de sua the loai");
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
		fflush(stdin);
		gets(a.TenSach);
		break;
	}
	case 2: //Tac gia
	{
		printf("\nTen tac gia sau khi sua la ");
		fflush(stdin);
		gets(a.TacGia);
		break;
	}
	case 3: //The loai
	{
		printf("\nThe loai sau khi sua la ");
		fflush(stdin);
		gets(a.TheLoai);
		break;
	}
	case 4: //Ma sach
	{
		printf("\nMa sach sau khi sua la");
		fflush(stdin);
		gets(a.MaSach);
		break;
	}
	case 5: //Nha xuat ban
	{
		printf("\nTen nha xb sau khi sua la ");
		fflush(stdin);
		gets(a.NhaXuatBan);
		break;
	}
	case 6: //Nam xuat ban
	{
		printf("\nNam xua ban sau khi sua la ");
		scanf("%d", &a.NamXB);
		break;
	}
	case 7: //So luong
	{
		printf("\nSo luong sach sau khi sua la ");
		fflush(stdin);
		scanf("%d", a.SoLuong);
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
		printf("\nNhap ten sach: ");
		fflush(stdin);
		keyWord(o);
		for (int i = 0; i < n; i++)
		{
			if (strcmp(o, a[i].TenSach) == 0)
			{
				mucLuc(1);
				Xuat(a[i],i);
				Sua1(a[i]);
				Xuat(a[i],i);
			}
		}
		break;
	case 2:
		printf("\nNhap ma sach: ");
		fflush(stdin);
		keyWord(o);
		for (int i = 0; i < n; i++)
		{
			if (strcmp(o, a[i].MaSach) == 0)
			{
				mucLuc(1);
				Xuat(a[i],i);
				Sua1(a[i]);
				Xuat(a[i],i);
			}
		}
		break;
	case 3:
	    break;
	}
}
void ChinhSua(Book a[],int n){
	int x;
	do{
		printf("\n Nhap 1 de sua thong tin sach ");
		printf("\n Nhap 2 de xoa sach");
		printf("\n Nhap 3 de thoat");
		printf("\n\n Nhap thao tac: ");
		scanf("%d",&x);
	}while(x<1||x>3);
	switch(x){
		case 1:
		Sua(a,n);
		break;
		case 2:
		Xoa(a,n);
		break;
		default: break;
	}
}
//Ham Main
int main()
{
	/*luu y: chi can nhap thong tin thi file se tu dong tao o o dia D voi ten la quanLiThuVien
			 hoac co the tu tao file va thay doi dia chi o fileName	 */
	//	char fileName[] = "D:\\quanLiThuVien.txt";
//	char fileName[] = "C:\\aaa\\QuanLyThuViena.txt";
		char fileName[] = "/storage/emulated/0/txtpad/QuanLyThuViena.txt";
		char fileName2[] = "/storage/emulated/0/txtpad/DSnguoimuon.txt";
	Book a[50];
	int soLuongSach = inputFile(a, fileName);
	int slnguoimuon = inputFileBorrow(a, fileName2, soLuongSach);
	char choice;
	replace_string_underscores(a, soLuongSach);

	do
	{
		printf("\n**********************************************************************\n");
		printf("*                     QUAN LI THU VIEN                               *\n");
		printf("* 1/ Them sach                                        2/Xuat DS sach *\n");
		printf("* 3/ Muon sach                                        4/Ghi File     *\n");
		printf("* 5/ Tim kiem                                         6/Chinh sua    *\n");  
		printf("* 0/Thoat                                                            *\n");
		printf("**********************************************************************\n");
		printf("Moi nhap lua chon: ");
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
				SapXepTen(a, soLuongSach);
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
				outPutFile(a, fileName, fileName2, soLuongSach);
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
			printf("\nGhi thong tin vao file %s thanh cong!", fileName);
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
			printf("\nGhi thong tin vao file %s thanh cong!", fileName);
			pressAnyKey();
			break;

		case '0':
			printf("Ban da chon thoat chuong trinh");
			break;
		}
	} while (choice != '0');
}
