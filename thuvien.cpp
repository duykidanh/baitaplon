
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
//Nhap Ngay Thang Nam
int PlusBorrow(Book a[],int n);
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
//Nhap nguoi muon
void Borrower(Human &human) {
	printf("Nhap ten nguoi muon: ");
	fflush(stdin);
	gets(human.TenNguoiMuon);
	do {
		printf("Nhap ngay muon: \n");
		NhapDate(human.NgayMuon);
		printf("Nhap ngay tra: \n");
		NhapDate(human.NgayTra);
		if (SoSanhNgay(human.NgayMuon, human.NgayTra) == 1){
			printf("\nNgay muon va ngay tra khong hop le!\nYeu cau nhap lai.\n");
		}else
			break;
	} while((SoSanhNgay(human.NgayMuon, human.NgayTra) == 1));
}
void Borrow(Book &a) {
	if(a.SoLuong== 0){
		printf("\nKhong du so luong de muon");
	}else {
		printf("\nNhap 0 de muon va 1 de bo qua: ");
		int u;
		scanf("%d",&u);
		switch (u) {
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
	printf("Nhap ma sach: ");
	fflush(stdin);
	gets(a.MaSach);
	printf("Nhap ten sach: ");
	gets(a.TenSach);
	printf("Nhap ten tac gia: ");
	gets(a.TacGia);
	printf("Nhap the loai: ");
	gets(a.TheLoai);
	printf("Nhap nam xuat ban: ");
	scanf("%d", &a.NamXB);
	printf("Nhap ten nha xuat ban: ");
	fflush(stdin);
	gets(a.NhaXuatBan);
	do
	{
		printf("Nhap so luong hien co: ");
		scanf("%d", &a.SoLuong);
		if (a.SoLuong <0)
		{
			printf("So luong khong hop le!\nYeu cau nhap lai.\n");
		}
	} while (a.SoLuong < 0);
	
//	do{
//		printf("Nhap So Luong Nguoi Muon: ");
//		scanf("%d",&a.SLNguoiMuon);
//	}while(a.SLNguoiMuon < 0||a.SLNguoiMuon > a.SoLuong);
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
	printf("%d/%d/%d", a.ngay, a.thang, a.nam);
}
//Xuat DS nguoi muon
void XuatNguoiMuon(Human a)
{
	printf("\nNguoi muon: %s", a.TenNguoiMuon);
	printf("\nNgay muon: ");
	XuatDate(a.NgayMuon);
	printf("\nNgay Tra: ");
	XuatDate(a.NgayTra);
}
void DSNguoiMuon(Human a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		XuatNguoiMuon(a[i]);
	}
}
//Xuat DS Sach
void Xuat(Book a)
{
if(a.NamXB==0&&a.SoLuong==0){
	printf("\nKhong co du lieu ");
}
else{
	printf("\nMa sach: %s", a.MaSach);
	printf("\nTen sach: %s", a.TenSach);
	printf("\nTac gia: %s", a.TacGia);
	printf("\nThe loai: %s", a.TheLoai);
	printf("\nNam xuat ban: %d", a.NamXB);
	printf("\nNha xuat ban: %s", a.NhaXuatBan);
	printf("\nSoLuong: %d", a.SoLuong);
	if(a.SLNguoiMuon > 0) {
		printf("\nSo luong nguoi muon: %d", a.SLNguoiMuon);
		for(int i = 0; i < a.SLNguoiMuon; i++) {
		XuatNguoiMuon(a.NguoiMuon[i]);
		}
    }
}
}
void XuatDS(Book a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\n");
		Xuat(a[i]);
	}
}
//H�m d?i ch?
void DoiCho(Book &a, Book &b)
{
	Book c = a;
	a = b;
	b = c;
}
//S?p x?p theo t�n
void SapXepTen(Book a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(a[i].TenSach, a[j].TenSach) > 0)
			{
				DoiCho(a[i], a[j]);
			}
		}
	}
}
int Search(Book a[],int n) {
	
		
	char keyword[100];
	printf("\n Nhap 1 de tim kiem theo ten sach");
	printf("\n Nhap 2 de tim kiem theo the loai");
	printf("\n Nhap 3 de tim kiem theo tac gia");
	printf("\n Nhap 4 de tim kiem theo nha san xuat");
	printf("\n Nhap 5 de bo qua");
	int x;
	printf("\nXin moi chon theo y muon: ");
	scanf("%d",&x);
	switch (x) {
		case 1:
			printf("\nNhap tu khoa can tim: ");
			fflush(stdin);
			gets(keyword);
			for(int i = 0; i < n; i++) {
				if(strcmp(keyword, a[i].TenSach) == 0) {
					Xuat(a[i]);
					Borrow(a[i]);
					
					break;
			}else
				printf("Khong tim thay tu khoa");
				break;
			}
			break;
		case 2:
			printf("\nNhap tu khoa can tim: ");
			fflush(stdin);
			gets(keyword);
			for(int i = 0; i < n; i++) {
				if(strcmp(keyword, a[i].TheLoai) == 0) {
					Xuat(a[i]);
					Borrow(a[i]);
					break;
			}else
				printf("Khong tim thay tu khoa");
				break;
			}
			break;
		case 3:
			printf("\nNhap tu khoa can tim: ");
			fflush(stdin);
			gets(keyword);
			for(int i = 0; i < n; i++) {
				if(strcmp(keyword, a[i].TacGia) == 0) {
					Xuat(a[i]);
					Borrow(a[i]);
					break;
			}else
				printf("Khong tim thay tu khoa");
				break;
			}
			break;
		case 4:
			printf("\nNhap tu khoa can tim: ");
			fflush(stdin);
			gets(keyword);
			for(int i = 0; i < n; i++) {
				if(strcmp(keyword, a[i].NhaXuatBan) == 0) {
					Xuat(a[i]);
					Borrow(a[i]);
					break;
			}else
				printf("Khong tim thay tu khoa");
				break;
			}
			break;
		case 5:
			return 1;
			break;
		default:
			printf("Nhap sai");
			Search(a, n);
			return 1;
			break;
	}
	
	if(Search(a, n) == 1)	
		return 0;
		
	
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
void replace_string_underscores(Book a[],int n){
	
	for(int i = 0;i < n;i++){
		replace_underscores(a[i].TenSach);
		replace_underscores(a[i].MaSach);
		replace_underscores(a[i].TacGia);
		replace_underscores(a[i].TheLoai);
		replace_underscores(a[i].NhaXuatBan);
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
void outPutFile(Book a[],char fileName[],int n){
	FILE *fileptr;
	fileptr = fopen(fileName,"w");
	//bien phu de mang gia tri copy
	char tenSach[100] = "";
	char tacGia[50]  = "";
	char theLoai[50] = "";
	char maSach[10]  = "";
	char nhaXB[50]   = "";
	
	fprintf(fileptr,"%25s%18s%25s%15s%13s%13s%15s%18s\n","Ten Sach","Tac gia","The Loai","Ma Sach","NXB","Nam XB","So Luong","SL nguoi muon");
	fflush(stdin);
	for(int i = 0;i < n;i++){
		//copy chuoi va thay the cac khoang trang trong chuoi bang dau '_'
		strcpy(tenSach,a[i].TenSach);  replace_spaces(tenSach);
		strcpy(tacGia,a[i].TacGia);    replace_spaces(tacGia);
		strcpy(theLoai,a[i].TheLoai);  replace_spaces(theLoai);
		strcpy(maSach,a[i].MaSach);    replace_spaces(maSach);
		strcpy(nhaXB,a[i].NhaXuatBan); replace_spaces(nhaXB);
		
		fprintf(fileptr,"%25s%18s%25s%15s%13s%13d%15d%18d\n",tenSach,tacGia,theLoai,maSach,nhaXB,a[i].NamXB,a[i].SoLuong,a[i].SLNguoiMuon);
	}
	
	fclose(fileptr);
}
//Ham doc file
int inputFile(Book a[], char fileName[]) {
    
	FILE * fileptr;
    fileptr = fopen (fileName, "r");
    int i = 0;
    char line[300];
    
    if(fileptr == NULL){
    	printf("Khong tim thay file!.\n");
	}
    // doc thong tin sach
    
	//ham fgets se lay mot dong va dat con tro chuot o dau dong tiep theo
    fgets(line, sizeof(line), fileptr);
    
    while (fscanf(fileptr, "%25s%18s%25s%20s%13s%13d%15d%18d\n", &a[i].TenSach, &a[i].TacGia, 
            &a[i].TheLoai, &a[i].MaSach, &a[i].NhaXuatBan, &a[i].NamXB, &a[i].SoLuong, 
            &a[i].SLNguoiMuon) != EOF) {
       i++;
    }
    
    printf("So luong sach co san trong file la: %d\n",i); 
    fclose (fileptr);
    
    // tra ve so luong sach duoc doc tu file
    return i;
}
void pressAnyKey() {
    printf("\n\nNhan phim bat ky de tiep tuc...");
    getch();
    system("cls");
}
void Xoa(Book a[], int n){
    //Tim kiem phan tu ma ban muon xoa
    int x,dem=0;   char s[100];
   do{ printf("\nNhap du lieu de tim kiem phan tu can xoa ");
    scanf("%d",&x);
   } while(x<1||x>4);
   switch(x){
       case 1://Tim ten phan tu muon xoa
       printf("\nNhap ten phan tu can xoa ");
       fflush(stdin);
       gets(s);
          for (int i=0;i<n;i++){
           if(strcmp(s,a[i].TenSach)==0){
               dem++;
               for( int j=i;j<n;j++)
               a[j]=a[j+1];
           }
           if(dem==0) { printf("\nPhan tu can xoa khong co trong danh sach");
           break;    
           }
           --n;
          }
          break;
          case 2://Tim ma sach can xoa
          printf("\nNhap ma cua cuon sach can xoa ");
          fflush(stdin);
          gets(s);
          for (int i=0;i<n;i++){
              if(strcmp(s,a[i].MaSach)==0){
                  dem++;
                  for (int j=i;j<n;j++)
                  a[j]=a[j+1];
              }
               if(dem==0) { printf("\nPhan tu can xoa khong co trong danh sach");
           break;
           }
              --n;
          }
               break;
 }
}

void Sua1(Book &a, Human &b){
    //Chon phan thong tin can sua
    int x;
    do{
    printf("\nNhap vi tri phan tu can sua ");
    scanf("%d",&x);
    } while(x<1||x>9);
    switch(x){
    case 1: //Ten sach
    
        printf("\nTen sau khi sua la ");
        fflush(stdin);
        gets(a.TenSach);
         break;
    case 2: //Tac gia
    
        printf("\nTen tac gia sau khi sua la ");
        fflush(stdin);
        gets(a.TacGia);
        
         break;
    case 3: //The loai
    
        printf("\nThe loai sau khi sua la ");
        fflush(stdin);
        gets(a.TheLoai);
         break;
    case 4: //Ma sach
    
           printf("\nMa sach sau khi sua la");
        fflush(stdin);
        gets(a.MaSach);
         break;
    case 5: //Nha xuat ban
    
           printf("\nTen nha xb sau khi sua la ");
        fflush(stdin);
        gets(a.NhaXuatBan);
         break;
    case 6: //Nam xuat ban
    
        printf("\nNam xua ban sau khi sua la ");
        scanf("%d",&a.NamXB);
         break;
    case 7: //So luong
    
           printf("\nSo luong sach sau khi sua la ");
        fflush(stdin);
        scanf("%d",a.SoLuong);
         break;
    case 8: // So luong nguoi muon
   
           printf("\nSo luong nguoi muon sach sau khi sua la ");
        fflush(stdin);
        scanf("%d",a.SLNguoiMuon);
         break;
    case 9:	 // Thong tin nguoi muon
    
        //Nhap phan thong tin cua nguoi muon can sua
        int e;
        do{
        printf("\nNhap phan mua sua trong thong tin nguoi muon ");
        scanf("%d",&e);
        }while(e<1||e>3);
        switch(e){
        case 1:
        
            printf("\nNhap lai ten nguoi muon ");
            fflush(stdin);
            gets(b.TenNguoiMuon); 
             break;
        case 2:
      
          printf("\nNhap lai ngay muon va ngay tra ");
    
         NhapDate(b.NgayMuon); 
         NhapDate(b.NgayTra);
         SoSanhNgay(b.NgayMuon,b.NgayTra);
              break;
     }
          break;
 }
}
void Sua(Book a[], Human b[] ,int n ){
	int x; char o[100];
	do {
	printf("\nNhap cach thuc tim kiem ");
	scanf("%d",&x);
    } while (x<0||x>2);
    switch(x){
    	case 1:
    		printf("\nNhap ten de tim kiem cuon sach can sua ");
    		fflush(stdin);
    		gets(o);
    		for (int i=0;i<n;i++){
    			if(strcmp(o,a[i].TenSach)==0){
    				Xuat(a[i]);
    				Sua1(a[i],b[i]);
    				Xuat(a[i]);
				}
			}
			     break;
		case 2:
    	    printf("\nNhap ma sach de tim kiem cuon sach can sua ");
        	fflush(stdin);
    		gets(o);
    		for (int i=0;i<n;i++){
    			if(strcmp(o,a[i].MaSach)==0){
    				Xuat(a[i]);
    				Sua1(a[i],b[i]);
    				Xuat(a[i]);
				}
			}
			     break;
	}
}

//Ham Main
int main()
{
	/*luu y: chi can nhap thong tin thi file se tu dong tao o o dia D voi ten la quanLiThuVien
			 hoac co the tu tao file va thay doi dia chi o fileName	 */
	
	char fileName[] = "D:\\quanLiThuVien.txt";
	Book a[50];  Date b[50]; Human c[50];
	int soLuongSach = inputFile(a, fileName);
	int choice;
	replace_string_underscores(a, soLuongSach);
	
	do{
	printf("\n**********************************************************************\n");
	printf("*                     QUAN LI THU VIEN                               *\n");
	printf("* 1/ Them sach                                        2/Xuat DS sach *\n");
	printf("* 3/ Tim sach                                         4/Ghi File     *\n");
	printf("* 5/ Sua                                              6/Xoa          *\n");
	printf("* 0/Thoat                                                            *\n");
	printf("**********************************************************************\n");
	printf("Moi nhap lua chon: ");
	scanf("%d",&choice);
			switch(choice){
		case 1:
			ThemSach(a, soLuongSach);
			pressAnyKey();
			break;
		case 2:
			if(soLuongSach <= 0){
				printf("Chua co thong tin, vui long nhap thong tin!!!!");
			}else{
				XuatDS(a, soLuongSach);
			}
			pressAnyKey();
			break;
		case 3:
			if(soLuongSach <= 0){
				printf("Chua co thong tin, vui long nhap thong tin!!!!");
			}else{
				Search(a, soLuongSach);
			}
			pressAnyKey();
			break;
		case 4:
				if(soLuongSach <= 0){
				printf("Chua co thong tin, vui long nhap thong tin!!!!");
			}else{
				outPutFile(a,fileName,soLuongSach);
			}
			printf("\nGhi thong tin vao file %s thanh cong!", fileName);
			pressAnyKey();
			break;
			case 5:
					if(soLuongSach <= 0){
				printf("Chua co thong tin, vui long nhap thong tin!!!!");
			}else{
				Sua(a,c,soLuongSach);
			}
			printf("\nGhi thong tin vao file %s thanh cong!", fileName);
			pressAnyKey();
			break;
			case 6:
					if(soLuongSach <= 0){
				printf("Chua co thong tin, vui long nhap thong tin!!!!");
			}else{
					Xoa(a,soLuongSach);
			}
			printf("\nGhi thong tin vao file %s thanh cong!", fileName);
			pressAnyKey();
			break;
				
		case 0:
			printf("Ban da chon thoat chuong trinh");
			break;
		
		}
	}while(choice != 0);




	ThemSach(a, soLuongSach);
	Search(a, soLuongSach);

	XuatDS(a, soLuongSach);

	outPutFile(a,fileName,soLuongSach);
	Xoa(a,soLuongSach);
	Sua(a,c,soLuongSach);

}

