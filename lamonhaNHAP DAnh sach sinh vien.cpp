#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void nhapn(int&n){
do{
	printf("\nso luong sinh vien muon nhap:%d",n);
	scanf("%d",&n);
	if(n<0){
		printf("\nnhap sai nhap lai");
	}
}while(n<0);
}
struct sinhvien{

	char hovaten[30];
	char massv[10];
	char muontimsinhvien[10];
	char lop[10];
	int namsinh;
	int ngay;
	int thang;
	int nam;
	char gioitinh;
	float ly,toan,tin,DTB;
};
typedef struct sinhvien sv;

void NDS1TSV(sv &a){
	fflush(stdin);
	printf("\nnhap ho ten sinh vien: "); gets(a.hovaten);
	fflush(stdin);
	printf("\nnhap ma so sinh vien: "); gets (a.massv);
	fflush(stdin);
	printf("\nnhap lop: "); gets(a.lop);
/*	fflush(stdin);
	printf("nhap nam sinh: "); scanf("%d",&a.namsinh);*/
///////////////////////////////////////////////////////
	fflush(stdin);	
	do{
		printf("\ngioi tinh (Nam: Y/Nu: X):");
		a.gioitinh=getche();
		if(a.gioitinh!='X'&&a.gioitinh!='Y'){
			printf("\nnhap sai");
		}
	}while(a.gioitinh!='X'&&a.gioitinh!='Y');
	if(a.gioitinh=='X'){
		printf("\ngioi tinh: Nu");
	}
	else{
		printf("\ngioi tinh: Nam");
	}
///////////////////////////////////////////////////////
	fflush(stdin);
		printf("\n nhap ngay /thang/ nam sinh: ");
	printf("\nnhap nam: "); scanf("%d",&a.nam);
	do{
		printf("\nnhap thang: "); scanf("%d",&a.thang);
		if(a.thang<1||a.thang>12){
			printf("\nnhap sai thang nhap lai ");
		}
	} while(a.thang<1||a.thang>12);
	
	switch (a.thang){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
	    do{
	    	printf("\nnhap ngay sinh: "); scanf("%d",&a.ngay);
	    	if(a.ngay>31||a.ngay<1){
	    		printf("\nnhap sai nagy trong thang %d nhap lai",a.thang);
			}
		}while(a.ngay>31||a.ngay<1);
		break;	
	{
		case 4:
		case 6:
		case 9:
		case 11:
			do{
				printf("\nnhap ngay sinh: "); scanf("%d",&a.ngay);
			if(a.ngay>30||a.ngay<1){
				printf("\nnhap sai nagy trong thang %d nhap lai",a.thang);
			}
	}while(a.ngay>30|| a.ngay<1);
		break;
	} 
	{
		case 2: 
		if(a.nam%4==0&&a.nam%100!=0){
		do{
				printf("\nnhap ngay sinh: "); scanf("%d",&a.ngay);
			if(a.ngay>29||a.ngay<1){
				printf("\nnhap sai nagy trong thang %d nhap lai",a.thang);
			}
		}while(a.ngay>29|| a.ngay<1);
	}
	else{
		do{
				printf("\nnhap ngay sinh: "); scanf("%d",&a.ngay);
			if(a.ngay>28||a.ngay<1){
				printf("\nnhap sai nagy trong thang %d nhap lai",a.thang);
			}
		}while(a.ngay>28|| a.ngay<1);
	}
		break;
		}
}
    printf("\nngay/thang/nam sinh: %d/%d/%d",a.ngay,a.thang,a.nam);
	printf("\nnhap diem toan: "); scanf("%f",&a.toan);
	printf("\nnhap diem ly: "); scanf("%f",&a.ly);
	printf("\nnhap diem tin: "); scanf("%f",&a.tin);
	a.DTB=(a.toan+a.ly+a.tin)/3;
		printf("\n++++++++++++++++++");
}
///////////////////////////////////////////////////////////
void NDSTSV(sv s[],int n)
{
	for(int i=0;i<n;i++){
		printf("\nnhap sinh vien thu %d",i);
		NDS1TSV (s[i]);
    }
}
/////////////////////////////////////////////////////////
////////////////////////////////////////////////////
void XDS1TSV(sv a){
	printf("\nHo va ten: "); puts(a.hovaten);
	printf("\nMSSV: "); puts(a.massv);
	printf("\nLop: "); puts(a.lop);
/*	printf("\nNam sinh: %d",a.namsinh);*/
    printf("\nngay/thang/nam sinh: %d/%d/%d",a.ngay,a.thang,a.nam);
	if(a.gioitinh=='X'){
	printf("\ngioi tinh: Nu");
	}
	else{
		printf("\ngioi tinh: Nam");
	}
	printf("\nDiem Toan: %0.2f",a.toan);
	printf("\nDiem Ly: %0.2f",a.ly);
	printf("\nDiem Tin: %0.2f",a.tin);
	printf("\nDiem trung binh: %0.2f",a.DTB);

}
////////////////////////////////////////////////////////////
//*****************

	
void XDSTSV(sv s[],int n) {
	printf("\n\t\t****Thong tin sinh vien*****");
	for(int i=0;i<n;i++){
		printf("\nSinh vien thu %d la: ",i);
		XDS1TSV(s[i]);
		printf("\n-----------------------");
	}
}
///////////////////////////////////////////////////////////
void XDSSVNu(sv s[],int n){
	printf("\n\t\t****** Danh sach sinh vien nu ******");
	int flag =0;
	for(int i=0;i<n;i++){
		if(s[i].gioitinh=='X'){
			XDS1TSV(s[i]);
			printf("\n*******************");
			flag =1;
		}
		}
		if(flag==0){
			printf("\n Ko co sinh vien nu :)");
	}
}
////////////////////////////////////////////////////////////
void XDSSVNam(sv s[],int n){
	printf("\n\t\t******Danh sach sinh vien nam *******");
	int flag=0;
	for(int i=0;i<n;i++){
		if(s[i].gioitinh=='Y'){
			XDS1TSV(s[i]);
			printf("\n*********************");
			flag=1;
		}
	}
	if(flag==0)
	printf("\n ko co sinh vien nam :)");
}
////////////////
////////////////////////////////////////////////////////////
void DSSVTLai(sv s[],int n){
	printf("\n\t\t****** Danh sach sinh vien thi lai******");
	int flag=0;
	for(int i=0;i<n;i++){
		if(s[i].DTB<5){
			XDS1TSV(s[i]);
			printf("\n........................");
			flag=1;
		}
	}
	if(flag==0)
	printf("\n ko co hoc sinh thi lai :)");
}
//////////
void timMSSV (sv s[],int n){
	int search;
	int flag=0;
	char hovaten[30];
	char massv[10];

	do{
	printf("\n ==========tim kiem thong tin sinh vien=============");
	printf("\nnhap '10' tim kiem thong tim theo ma so sinh vien");
	printf("\nnhap '11' tim kiem thong tim theo ten sv ");
	printf("\nnhap '12' de sua thong tin sinh vien");
	printf("\nnhap '20'de thoat tim kiem ");
	printf("\n Anh chon cai gi !!! nhanh di: ");
	scanf("%d",&search);
    printf("\n---------------------\n");
	switch (search){
		case 10:{
			printf("\nnhap ma so sinh vien muon tim: \t");
			fflush(stdin);
			gets(massv);
			for(int i=0;i<n;i++){
				if(strcmp(massv,s[i].massv)==0){
					XDS1TSV(s[i]);
					flag ++;
				}
				if(flag==0){
					printf("\n khong co sinh vien nao co ma so sinh vien: %s",massv);
				}
			}
		
			break;
		}
		case 11: {
			printf("search sv theo ten ");
			fflush(stdin);
			gets(hovaten);
			for(int i=0;i<n;i++){
				if(strcmp(hovaten,s[i].hovaten)==0){
					XDS1TSV(s[i]);
					flag ++;
				}
			}
			if(flag==0){
				printf("\n ko cco sinh vien nao ten: %s",hovaten);
		}
			break;
		}
		case 12: {
			printf("\n====================== chinh sua thong tin sinh vien======");
			for(int i=0;i<n;i++){
				if(strcmp(massv,s[i].massv)==0){
					printf("\nchinh sua thong tin sinh vien ma so:%s",massv);
					fflush(stdin);
					printf("\nnhap ho ten sinh vien: "); gets(s[i].hovaten);
					fflush(stdin);
					printf("\nnhap ma so sinh vien: "); gets (s[i].massv);
					fflush(stdin);
					printf("\nnhap lop: "); gets(s[i].lop);
				/*	fflush(stdin);
					printf("nhap nam sinh: "); scanf("%d",&a.namsinh);*/
				///////////////////////////////////////////////////////
					fflush(stdin);	
					do{
						printf("\ngioi tinh (Nam: Y/Nu: X):");
						s[i].gioitinh=getche();
						if(s[i].gioitinh!='X'&&s[i].gioitinh!='Y'){
							printf("\nnhap sai");
						}
					}while(s[i].gioitinh!='X'&&s[i].gioitinh!='Y');
					if(s[i].gioitinh=='X'){
						printf("\ngioi tinh: Nu");
					}
					else{
						printf("\ngioi tinh: Nam");
					}
				///////////////////////////////////////////////////////
					fflush(stdin);
						printf("\n nhap ngay /thang/ nam sinh: ");
					printf("\nnhap nam: "); scanf("%d",&s[i].nam);
					do{
						printf("\nnhap thang: "); scanf("%d",&s[i].thang);
						if(s[i].thang<1||s[i].thang>12){
							printf("\nnhap sai thang nhap lai ");
						}
					} while(s[i].thang<1||s[i].thang>12);
					
					switch (s[i].thang){
						case 1:
						case 3:
						case 5:
						case 7:
						case 8:
						case 10:
						case 12:
					    do{
					    	printf("\nnhap ngay sinh: "); scanf("%d",&s[i].ngay);
					    	if(s[i].ngay>31||s[i].ngay<1){
					    		printf("\nnhap sai nagy trong thang %d nhap lai",s[i].thang);
							}
						}while(s[i].ngay>31||s[i].ngay<1);
						break;	
					{
						case 4:
						case 6:
						case 9:
						case 11:
							do{
								printf("\nnhap ngay sinh: "); scanf("%d",&s[i].ngay);
							if(s[i].ngay>30||s[i].ngay<1){
								printf("\nnhap sai nagy trong thang %d nhap lai",s[i].thang);
							}
					}while(s[i].ngay>30|| s[i].ngay<1);
						break;
					} 
					{
						case 2: 
						if(s[i].nam%4==0&&s[i].nam%100!=0){
						do{
								printf("\nnhap ngay sinh: "); scanf("%d",&s[i].ngay);
							if(s[i].ngay>29||s[i].ngay<1){
								printf("\nnhap sai nagy trong thang %d nhap lai",s[i].thang);
							}
						}while(s[i].ngay>29|| s[i].ngay<1);
					}
					else{
						do{
								printf("\nnhap ngay sinh: "); scanf("%d",&s[i].ngay);
							if(s[i].ngay>28||s[i].ngay<1){
								printf("\nnhap sai nagy trong thang %d nhap lai",s[i].thang);
							}
						}while(s[i].ngay>28|| s[i].ngay<1);
					}
				break;
				}
		}
		    printf("\nngay/thang/nam sinh: %d/%d/%d",s[i].ngay,s[i].thang,s[i].nam);
			printf("\nnhap diem toan: "); scanf("%f",&s[i].toan);
			printf("\nnhap diem ly: "); scanf("%f",&s[i].ly);
			printf("\nnhap diem tin: "); scanf("%f",&s[i].tin);
			s[i].DTB=(s[i].toan+s[i].ly+s[i].tin)/3;
				printf("\n++++++++++++++++++");
		}
				}
				break;
				system("pause");
		}
		case 20:{
			printf("\n tim kiem hoan thanh !!!");
			break;
		}
	}
  } while(search !=12);
}
/////////////
void ghiFile(sv s[],int n, char*FileName){
	FILE*k;
	k=fopen(FileName,"a+");
	fwrite(&n,sizeof(n),1,k);
	for(int i=0;i<n;i++){
		fwrite(&s[i],sizeof(s[i]),1,k);
	}
	fclose(k);
}
void docFile(sv s[],int n, char*FileName){
	FILE*k;
	k=fopen(FileName,"a+");
	fread(&n,sizeof(n),1,k);
	for(int i=0;i<n;i++){
		fread(&s[i],sizeof(s[i]),1,k);
	}
	fclose(k);
}
void themsinhvien(sv s[],int n){
	n++;
	NDS1TSV(s[n-1]);
}
////////////////////////////////////////////////////////////////
int main (){
	int n;
	sv s[100];
	sv a;
	
//	nhapn(n);

/*	
	NDSTSV(s,n);
	XDSTSV(s,n);
	XDSSVNu(s,n);
	XDSSVNam(s,n);
	DSSVTLai(s,n);*/
	int chon;
	do{
	system("cls");
	printf("\n1: de nhap DSTSV ");
	printf("\n2: de xuat XDSTSV ");
	printf("\n3: de xuat XDSSVNam ");
	printf("\n4: de xuat XDSSNu ");
	printf("\n5: de xuat DDSVTlai ");
	printf("\n6: de ghi file ");
	printf("\n7: de doc File ");
	printf("\n9: them sinh vien ");
	printf("\n8: tim sinh vien co ma so, tim sinh vien bang ten, sua doi thong tin sinh vien");
	printf("\n0: de thoat chuong trinh");
	printf("\n------------------------\n");
	printf("\n nhap so cho cong viec ban muon chon: ");
    scanf("%d",&chon);
    printf("\n------------------------\n");
    switch(chon){
    	case 1: {
    		
    		nhapn(n);
    		NDSTSV(s,n);
			break;
		}
		case 2:{
			
		    XDSTSV(s,n);
		    system("pause");
			break;
		}
		case 3:{
			XDSSVNam(s,n);
			system("pause");
			break;
		}
		case 4: {
			
			XDSSVNu(s,n); 
		    system("pause");
			break;
		}
		case 5: {
			
			DSSVTLai(s,n);
            system("pause");
			break;
		}
		case 6:{
			ghiFile(s,n,"DSTSV.dat");
			printf("\nGhi thanh cong");
			system("pause");
			break;
		}
		case 7:{
			docFile(s,n,"DSTSV.dat");
			printf("\ndoc thanh cong ");
			system("pause");
			break;
		}
		case 8:{
			timMSSV(s,n);
			system("pause");
		}
		case 0:{
			system("cls");
			printf("\nket thuc chuong trinh !!! ");
			break;
		}
		case 9: {
			system("cls");
			themsinhvien(s,n);
			printf("\n them sinh vien");
			break;
		}
	}
	}while(chon!=0);
	return 0;
}


























