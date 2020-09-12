#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
///////////////////////////////////////////////////////////////////
/////////// Karþýmýza Çýkan Menünün Fonksiyonu. (Void) ///////////
int menu (int secim_3){
	int secim;
	printf("\n__________MENU__________\n");
	printf("0- Program Kapat \n");
	printf("1- Diziyi Yaz \n");
	printf("2- Diziyi Rastgele Doldur \n");
	printf("3- Diziyi Sirala (Bubble Sort) \n");
	printf("4- Diziyi Sirala (Selection Sort)\n");
	printf("5- Dizide Ara (Linear Search)\n");
	printf("6- Dizide Ara (Binary Search)\n");
	printf("7- Ortalama (Mean)\n");
	printf("8- Ortanca (Median)\n");
	printf("9- Mod (Mod)\n");
	printf("____________________\n");
	printf("Seciminiz : ");
	scanf("%d",&secim);
	secim_3=secim;
}
/////////////////////////////////////////////////////////////////////////////////////////
///////////////// Diziyi Doldurduktan Sonra Karþýmýza Gelen Fonksiyon. //////////////////
void diziyiYaz(int *dizi,int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d   ",dizi[i]);
}
///////////////////////////////////////////////////////////////////
////////// Doðrusal Arama (Lineary Search) Fonksiyonu. ///////////
int dogrusalAra(int *dizi,int n,int aranan, int *yer){ 
	*yer=-1;
	int m;
	for (m=0;m<n;m++)
		if(dizi[m]==aranan)
			*yer=m;
}
///////////////////////////////////////////////////////////////////
////////// Mod (Sýklýk) Fonksiyonu. //////////////////////////////
int mod(int *dizi,int n, int *enBuyuk){
	int frekans[101]={0};
	int m;
	for(m=0;m<n;m++)
	{
		frekans[*dizi]++;
		dizi++;
	}
	*enBuyuk=0;
	for(m=0;m<101;m++)
		if(frekans[m]>frekans[*enBuyuk])
			*enBuyuk=m;
}
////////////////////////////////////////////////////////////////////
////// Seçme Sýralamasý (Selection Sort) Fonksiyonu. (Void) ///////
void secmeSirala(int *dizi,int n){
	int k,m,enKucuk,yedek;
	for(k=0;k<n-1;k++){
		enKucuk=k;
		for(m=k+1;m<n;m++){
			if(dizi[m]<dizi[enKucuk])
				enKucuk=m;
		}
		yedek=dizi[k];
		dizi[k]=dizi[enKucuk];
		dizi[enKucuk]=yedek;
	}
}
/////////////////////////////////////////////////////////////////////
//////// Diziyi Rastgele (Random) Dolduran Fonksiyon. (Void) ////////	
void doldur(int *dizi,int n){
	int m;
	for(m=0;m<n;m++)
	{
		*dizi=rand()%101;
		dizi++;
	}
}
/////////////////////////////////////////////////////////////////////
//////// Kabarcýk Sýralama (Bubble Sort) Fonksiyonu. (Void) /////////
void kabarcikSirala(int *dizi,int n){
	int gecis,yedek,j,yerDegisimi=1;
	for(gecis=0;gecis<n&&yerDegisimi;gecis++){
		yerDegisimi=0;
		for(j=0;j<n-1-gecis;j++)
			if(dizi[j]>dizi[j+1]){
				yedek=dizi[j];
				dizi[j]=dizi[j+1];
				dizi[j+1]=yedek;
				yerDegisimi=1;
			}
	}
}
//////////////////////////////////////////////////////////////////////
////////////// Ortanca (Median) Fonksiyonu. /////////////////////////
float ortanca(int *dizi,int n, float *ortanca)
{
	kabarcikSirala(dizi,n);
	if(n%2==0)
	*ortanca = (dizi[(n/2)-1]+dizi[((n+2)/2)-1])/2.0;
	else
	*ortanca = dizi [((n+1)/2)-1];
}
/////////////////////////////////////////////////////////////////////
////////// Ýkili Arama (Binary Search) Fonksiyonu. /////////////////
void ikiliAra(int *dizi, int n, int aranan, int *indis){
	
	int bas=0,son=n-1,orta;
	kabarcikSirala(dizi,n);
	while(bas<=son){
		orta=(bas+son)/2;
		if(dizi[orta]==aranan)
		{
			*indis = orta;
			return;
		}
		else if (dizi[orta]>aranan)
			son = orta-1;
		else
			bas=orta+1;
	}
	*indis = -1;
}
/////////////////////////////////////////////////////////////////////
////////// Ortalama (Mean) Fonksiyonu
void ortalama(int *dizi,int n, float *toplam){
	int k;
	for(k=0;k<n;k++)
	{
		*toplam=*toplam+*dizi;
		dizi++;
	}
	*toplam = *toplam/n;
}
//////////////////////////// Main Fonksiyonu. /////////////////////////
int main(){
	int dizi[N] = {0};
	int indis,secim=0,aranacak, modDeger,secim_2=0;
	float ortancaDeger, toplam;
	srand(time(NULL));
///////// Switch Ýle Fonksiyonlarý Çaðýrdýðýmýz Kýsým /////////////////
	do{
		secim=menu(secim_2);
		switch(secim){
			case 0:
				printf("Program sona erdi\n");
				break;
			case 1:
				diziyiYaz(dizi,N);
				break;
			case 2:
				doldur(dizi,N);
				printf("Dizi dolduruldu\n");
				break;
			case 3:
				kabarcikSirala(dizi,N);
				printf("Dizi siralandi\n");
				break;
			case 4:
				secmeSirala(dizi,N);
				printf("Dizi siralandi\n");
				break;
			case 5:
				printf("Aranacak : ");
				scanf("%d",&aranacak);
				dogrusalAra(dizi,N,aranacak, &indis);
				if(indis==-1)
					printf("\n Aranan eleman yok \n");
				else 
					printf("Aranan %d nolu yerde",indis);
				break;
			case 6:
				printf("Aranacak : ");
				scanf("%d",&aranacak);
				ikiliAra(dizi,N,aranacak, &indis);
				if(indis==-1)
					printf("\n Aranan eleman yok \n");
				else 
					printf("Aranan %d nolu yerde",indis);
				break;
			case 7:
				ortalama(dizi,N,&toplam);
				printf("Ortalama :%.2f",toplam);
			    break;
			case 8:
				ortanca(dizi,N,&ortancaDeger);
				printf("Ortanca : %.2f",ortancaDeger);
				break;
			case 9:
				mod(dizi,N,&modDeger);
				printf("Mod : %d \n",modDeger);
				break;
			default:
				printf("\n Hatali giris \a\n");
			}
		}
	while (secim!=0);
		return 0;
}
