#include"header.h"
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
    char tinhTrang[12] = "";
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
		strcpy(tinhTrang, a[i].NguoiMuon[j].TinhTrang);
				replace_spaces(tenNguoiMuon);
				replace_spaces(tinhTrang);
		fprintf(fileptr, "%20s%8d%8d%8d%8d%8d%8d%12s\n", tenNguoiMuon, a[i].NguoiMuon[j].NgayMuon.ngay, a[i].NguoiMuon[j].NgayMuon.thang, a[i].NguoiMuon[j].NgayMuon.nam, a[i].NguoiMuon[j].NgayTra.ngay, a[i].NguoiMuon[j].NgayTra.thang, a[i].NguoiMuon[j].NgayTra.nam,tinhTrang);
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
				fscanf(fileptr, "%20s%8d%8d%8d%8d%8d%8d%12s\n", &a[i].NguoiMuon[j].TenNguoiMuon, &a[i].NguoiMuon[j].NgayMuon.ngay, &a[i].NguoiMuon[j].NgayMuon.thang, &a[i].NguoiMuon[j].NgayMuon.nam, &a[i].NguoiMuon[j].NgayTra.ngay, &a[i].NguoiMuon[j].NgayTra.thang, &a[i].NguoiMuon[j].NgayTra.nam,&a[i].NguoiMuon[j].TinhTrang);
				if(DateNow(a[i].NguoiMuon[j].NgayTra) == 0)
				strcpy(a[i].NguoiMuon[j].TinhTrang,"Qua han");
				else strcpy(a[i].NguoiMuon[j].TinhTrang," ");
	}
		}
		i++;
	}
	printf("So luong sach co san trong file la: %d\n", i);
	fclose(fileptr);
	// tra ve so luong sach duoc doc tu file
	return i;
}
