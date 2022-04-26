#include"header.h"
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
			addBook(a, soLuongSach);
			pressAnyKey();
			break;
		case '2':
			if (soLuongSach <= 0)
			{
				printf("Chua co thong tin, vui long nhap thong tin!!!!");
			}
			else
			{
				Sort(a, soLuongSach);
				listBook(a, soLuongSach);
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
				borrowBook(a, soLuongSach);
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
				UpdateBook(a, soLuongSach);
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

