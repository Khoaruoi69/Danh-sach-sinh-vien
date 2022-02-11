#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
void nhapn(int&n){
do{
	printf("\nEnter the number of students:%d",n);
	scanf("%d",&n);
	if(n<0){
		printf("\nEnter wrong, please enter again!");
	}
}while(n<0);
}
struct sinhvien{

	char students[30];
	char studentId[10];
	char studentSeek[10];
	char class[10];
	int yearofbird;
	int day;
	int month;
	int year;
	char gender;
	float physics,math,it,Avg;
};
typedef struct sinhvien sv;

void NDS1TSV(sv &a){
	fflush(stdin);
	printf("\nEnter the student's year: "); gets(a.students);
	fflush(stdin);
	printf("\nEnter student number: "); gets (a.studentId);
	fflush(stdin);
	printf("\nEnter class year: "); gets(a.class);
/*	fflush(stdin);
	printf("nhap year sinh: "); scanf("%d",&a.yearofbird);*/
///////////////////////////////////////////////////////
	fflush(stdin);	
	do{
		printf("\nGender (Male: Y/Female: X):");
		a.gender=getche();
		if(a.gender!='X'&&a.gender!='Y'){
			printf("\nwrong input");
		}
	}while(a.gender!='X'&&a.gender!='Y');
	if(a.gender=='X'){
		printf("\nGender: Female");
	}
	else{
		printf("\nGender: Male");
	}
///////////////////////////////////////////////////////
	fflush(stdin);
		printf("\n Enter date/month/year of birth: ");
	printf("\nYear: "); scanf("%d",&a.year);
	do{
		printf("\nMonth: "); scanf("%d",&a.month);
		if(a.month<1||a.month>12){
			printf("\nEnter wrong, re-enter! ");
		}
	} while(a.month<1||a.month>12);
	
	switch (a.month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
	    do{
	    	printf("\nEnter date of birth: "); scanf("%d",&a.day);
	    	if(a.day>31||a.day<1){
	    		printf("\nEnter the wrong day of the month %d re-enter!",a.month);
			}
		}while(a.day>31||a.day<1);
		break;	
	{
		case 4:
		case 6:
		case 9:
		case 11:
			do{
				printf("\nEnter date of birth: "); scanf("%d",&a.day);
			if(a.day>30||a.day<1){
				printf("\nEnter the wrong day of the month %d re-enter!",a.month);
			}
	}while(a.day>30|| a.day<1);
		break;
	} 
	{
		case 2: 
		if(a.year%4==0&&a.year%100!=0){
		do{
				printf("\nnhap day sinh: "); scanf("%d",&a.day);
			if(a.day>29||a.day<1){
				printf("\nnhap sai nagy trong month %d nhap lai",a.month);
			}
		}while(a.day>29|| a.day<1);
	}
	else{
		do{
				printf("\nnhap day sinh: "); scanf("%d",&a.day);
			if(a.day>28||a.day<1){
				printf("\nnhap sai nagy trong month %d nhap lai",a.month);
			}
		}while(a.day>28|| a.day<1);
	}
		break;
		}
}
    printf("\nday/month/year sinh: %d/%d/%d",a.day,a.month,a.year);
	printf("\nnhap diem math: "); scanf("%f",&a.math);
	printf("\nnhap diem physics: "); scanf("%f",&a.physics);
	printf("\nnhap diem it: "); scanf("%f",&a.it);
	a.Avg=(a.math+a.physics+a.it)/3;
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
	printf("\nHo va ten: "); puts(a.students);
	printf("\nMSSV: "); puts(a.studentId);
	printf("\nclass: "); puts(a.class);
/*	printf("\nyear sinh: %d",a.yearofbird);*/
    printf("\nday/month/year sinh: %d/%d/%d",a.day,a.month,a.year);
	if(a.gender=='X'){
	printf("\ngioi ith: Nu");
	}
	else{
		printf("\ngioi ith: year");
	}
	printf("\nDiem math: %0.2f",a.math);
	printf("\nDiem physics: %0.2f",a.physics);
	printf("\nDiem it: %0.2f",a.it);
	printf("\nDiem trung binh: %0.2f",a.Avg);

}
////////////////////////////////////////////////////////////
//*****************

	
void XDSTSV(sv s[],int n) {
	printf("\n\t\t****Thong it sinh vien*****");
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
		if(s[i].gender=='X'){
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
void XDSSVyear(sv s[],int n){
	printf("\n\t\t******Danh sach sinh vien year *******");
	int flag=0;
	for(int i=0;i<n;i++){
		if(s[i].gender=='Y'){
			XDS1TSV(s[i]);
			printf("\n*********************");
			flag=1;
		}
	}
	if(flag==0)
	printf("\n ko co sinh vien year :)");
}
////////////////
////////////////////////////////////////////////////////////
void DSSVTLai(sv s[],int n){
	printf("\n\t\t****** Danh sach sinh vien thi lai******");
	int flag=0;
	for(int i=0;i<n;i++){
		if(s[i].Avg<5){
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
	char students[30];
	char studentId[10];

	do{
	printf("\n ==========tim kiem thong it sinh vien=============");
	printf("\nnhap '10' tim kiem thong tim theo ma so sinh vien");
	printf("\nnhap '11' tim kiem thong tim theo ten sv ");
	printf("\nnhap '12' de sua thong it sinh vien");
	printf("\nnhap '20'de thoat tim kiem ");
	printf("\n Anh chon cai gi !!! nhanh di: ");
	scanf("%d",&search);
    printf("\n---------------------\n");
	switch (search){
		case 10:{
			printf("\nnhap ma so sinh vien muon tim: \t");
			fflush(stdin);
			gets(studentId);
			for(int i=0;i<n;i++){
				if(strcmp(studentId,s[i].studentId)==0){
					XDS1TSV(s[i]);
					flag ++;
				}
				if(flag==0){
					printf("\n khong co sinh vien nao co ma so sinh vien: %s",studentId);
				}
			}
		
			break;
		}
		case 11: {
			printf("search sv theo ten ");
			fflush(stdin);
			gets(students);
			for(int i=0;i<n;i++){
				if(strcmp(students,s[i].students)==0){
					XDS1TSV(s[i]);
					flag ++;
				}
			}
			if(flag==0){
				printf("\n ko cco sinh vien nao ten: %s",students);
		}
			break;
		}
		case 12: {
			printf("\n====================== chinh sua thong it sinh vien======");
			for(int i=0;i<n;i++){
				if(strcmp(studentId,s[i].studentId)==0){
					printf("\nchinh sua thong it sinh vien ma so:%s",studentId);
					fflush(stdin);
					printf("\nnhap ho ten sinh vien: "); gets(s[i].students);
					fflush(stdin);
					printf("\nnhap ma so sinh vien: "); gets (s[i].studentId);
					fflush(stdin);
					printf("\nnhap class: "); gets(s[i].class);
				/*	fflush(stdin);
					printf("nhap year sinh: "); scanf("%d",&a.yearofbird);*/
				///////////////////////////////////////////////////////
					fflush(stdin);	
					do{
						printf("\ngioi ith (year: Y/Nu: X):");
						s[i].gender=getche();
						if(s[i].gender!='X'&&s[i].gender!='Y'){
							printf("\nnhap sai");
						}
					}while(s[i].gender!='X'&&s[i].gender!='Y');
					if(s[i].gender=='X'){
						printf("\ngioi ith: Nu");
					}
					else{
						printf("\ngioi ith: year");
					}
				///////////////////////////////////////////////////////
					fflush(stdin);
						printf("\n nhap day /month/ year sinh: ");
					printf("\nnhap year: "); scanf("%d",&s[i].year);
					do{
						printf("\nnhap month: "); scanf("%d",&s[i].month);
						if(s[i].month<1||s[i].month>12){
							printf("\nnhap sai month nhap lai ");
						}
					} while(s[i].month<1||s[i].month>12);
					
					switch (s[i].month){
						case 1:
						case 3:
						case 5:
						case 7:
						case 8:
						case 10:
						case 12:
					    do{
					    	printf("\nnhap day sinh: "); scanf("%d",&s[i].day);
					    	if(s[i].day>31||s[i].day<1){
					    		printf("\nnhap sai nagy trong month %d nhap lai",s[i].month);
							}
						}while(s[i].day>31||s[i].day<1);
						break;	
					{
						case 4:
						case 6:
						case 9:
						case 11:
							do{
								printf("\nnhap day sinh: "); scanf("%d",&s[i].day);
							if(s[i].day>30||s[i].day<1){
								printf("\nnhap sai nagy trong month %d nhap lai",s[i].month);
							}
					}while(s[i].day>30|| s[i].day<1);
						break;
					} 
					{
						case 2: 
						if(s[i].year%4==0&&s[i].year%100!=0){
						do{
								printf("\nnhap day sinh: "); scanf("%d",&s[i].day);
							if(s[i].day>29||s[i].day<1){
								printf("\nnhap sai nagy trong month %d nhap lai",s[i].month);
							}
						}while(s[i].day>29|| s[i].day<1);
					}
					else{
						do{
								printf("\nnhap day sinh: "); scanf("%d",&s[i].day);
							if(s[i].day>28||s[i].day<1){
								printf("\nnhap sai nagy trong month %d nhap lai",s[i].month);
							}
						}while(s[i].day>28|| s[i].day<1);
					}
				break;
				}
		}
		    printf("\nday/month/year sinh: %d/%d/%d",s[i].day,s[i].month,s[i].year);
			printf("\nnhap diem math: "); scanf("%f",&s[i].math);
			printf("\nnhap diem physics: "); scanf("%f",&s[i].physics);
			printf("\nnhap diem it: "); scanf("%f",&s[i].it);
			s[i].Avg=(s[i].math+s[i].physics+s[i].it)/3;
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
void ghiFile(sv s[],int n, char*Fileyeare){
	FILE*k;
	k=fopen(Fileyeare,"a+");
	fwrite(&n,sizeof(n),1,k);
	for(int i=0;i<n;i++){
		fwrite(&s[i],sizeof(s[i]),1,k);
	}
	fclose(k);
}
void docFile(sv s[],int n, char*Fileyeare){
	FILE*k;
	k=fopen(Fileyeare,"a+");
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
	XDSSVyear(s,n);
	DSSVTLai(s,n);*/
	int chon;
	do{
	system("cls");
	printf("\n1: de nhap DSTSV ");
	printf("\n2: de xuat XDSTSV ");
	printf("\n3: de xuat XDSSVyear ");
	printf("\n4: de xuat XDSSNu ");
	printf("\n5: de xuat DDSVTlai ");
	printf("\n6: de ghi file ");
	printf("\n7: de doc File ");
	printf("\n9: them sinh vien ");
	printf("\n8: tim sinh vien co ma so, tim sinh vien bang ten, sua doi thong it sinh vien");
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
			XDSSVyear(s,n);
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


























