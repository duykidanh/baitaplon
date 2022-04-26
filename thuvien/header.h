#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

typedef struct
{
	int ngay, thang, nam;
} Date;

typedef struct
{
	char TenNguoiMuon[100];
	Date NgayMuon;
	Date NgayTra;
	char TinhTrang[12];
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
void inputDate(Date &a);
int compareDate(Date a, Date b);
int DateNow(Date a);
void printLine(int n);
void Contents(int n);
int CheckHuman(Human a[],int x);
void Borrower(Human &human);
void Borrow(Book &a);
int Check(Book a[], int n, int x);
void Input(Book &a);
void addBook(Book a[], int &SoSach);
void outputDate(Date a);
void outputBorrower(Human a, int STT, char tensach[]);
void bookBorrower(Book a);
void listBorrower(Book a[], int n);
void Output(Book a, int n);
void listBook(Book a[], int n);
void Sort(Book a[], int n);
int findString(char str[],char keyword[]);
Book Search(Book a[], int n);
void replace_underscores(char *str);
void replace_string_underscores(Book a[], int n);
void replace_spaces(char *str);
void outPutFile(Book a[], char fileName[], int n);
int inputFile(Book a[], char fileName[]);
void pressAnyKey();
void returnBook(Book a[], char ten[], int n);
void borrowBook(Book a[], int n);
void Delete(Book a[], int &n);
void UpdateBorrower(Human &human, int e);
void UpdatelistBorrower(Human human[], int e, int n);
void Update1(Book &a);
void Update(Book a[], int n);
void UpdateBook(Book a[], int &n);
