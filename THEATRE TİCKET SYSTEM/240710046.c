#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

struct bilgi{
		char ad[50];
		char soyad[50];
		long long int TC;
		int kno;
		char ktur[50];
		
		
	};

void menu() {
    printf("********** Tiyatro Bilet Sistemi **********\n");
    printf("1. VIP (1-5)\n");
    printf("2. Kategori 2 (6-10)\n");
    printf("3. Kategori 3 (11-15)\n");
    printf("4. Çýkýþ\n");
    printf("*******************************************\n");
}

int sal() {
    int i, a,f;
    printf("Lütfen seçim yapýnýz: ");
    while (1) {
        a = scanf("%d", &f);
        if (a == 1) {
            switch (f) {
                case 1: printf("VIP sýnýfý seçtiniz.\n\n"); return f;
                case 2: printf("2. sýnýfý seçtiniz.\n\n"); return f;
                case 3: printf("3. sýnýfý seçtiniz.\n\n"); return f;
                case 4: printf("Çýkýþ yapýlýyor.\n"); exit(0);
                default: printf("Geçersiz deðer girdiniz, lütfen tekrar deneyin: "); break;
            }
        } else {
            printf("Lütfen bir sayý giriniz: ");
            while (getchar() != '\n');
        }
    }
}

void durum(int d) {
    if (d == 0) {
        printf("Boþ");
    } else {
        printf("Dolu");
    }
}

void menu2(int koltuk[]) {
	int l;
    for (l = 0; l < 15; l++) {
        printf("Koltuk %d: ", l + 1);
        durum(koltuk[l]);
        printf("\n");
    }
}

int vip(int koltuk[]) {
int y;
    int k;

    printf("Lütfen 1 ile 5 arasindaki koltuklardan birini seciniz: ");
    while (1) {
        k = scanf("%d", &y);
        if (k != 1) {
            printf("Gecersiz giris, Lütfen bir tam sayi giriniz: ");
            while (getchar() != '\n'); 
            continue;
        }

        if (y >= 1 && y <= 5) {
            if (koltuk[y - 1] == 0) {
                koltuk[y - 1] = 1; 
                printf("Koltuk %d baþarýyla rezerve edildi!\n", y);
                break;
            } else {
                printf("Maalesef secmek istediginiz koltuk dolu. Lutfen farkli bir seçim yapiniz: ");
            }
        } else {
            printf("Geçersiz seçim! Lütfen 1 ile 5 arasýndaki bir koltuk numarasý giriniz: ");
        }
    }
    return y;
}

int iki(int koltuk[]) {
int y;
    int k;

    printf("Lütfen 6 ile 10 arasýndaki koltuklardan birini seçiniz: ");
    while (1) {
        k = scanf("%d", &y);
        if (k != 1) {
            printf("Gecersiz giris, Lütfen bir tam sayý giriniz: ");
            while (getchar() != '\n'); 
            continue;
        }

        if (y >=6 && y <= 10) {
            if (koltuk[y - 1] == 0) {
                koltuk[y - 1] = 1; 
                printf("Koltuk %d baþarýyla rezerve edildi!\n", y);
                break;
            } else {
                printf("Maalesef seçmek istediðiniz koltuk dolu. Lütfen farklý bir seçim yapýnýz: ");
            }
        } else {
            printf("Geçersiz seçim! Lütfen 6 ile 10 arasýndaki bir koltuk numarasý giriniz: ");
        }
    }
    return y;
}

int uc(int koltuk[]) {
    int y;
    int k;

    printf("Lütfen 11 ile 15 arasýndaki koltuklardan birini seçiniz: ");
    while (1) {
        k = scanf("%d", &y);
        if (k != 1) {
            printf("Gecersiz giris, Lütfen bir tam sayý giriniz: ");
            while (getchar() != '\n'); 
            continue;
        }

        if (y >= 11 && y <= 15) {
            if (koltuk[y - 1] == 0) {
                koltuk[y - 1] = 1; 
                printf("Koltuk %d baþarýyla rezerve edildi!\n", y);
                break;
            } else {
                printf("Maalesef seçmek istediðiniz koltuk dolu. Lütfen farklý bir seçim yapýnýz: ");
            }
        } else {
            printf("Geçersiz seçim! Lütfen 11 ile 15 arasýndaki bir koltuk numarasý giriniz: ");
        }
    }
    return y;
}

	




int okuma(int koltuk[]) {
    FILE *VIP = fopen("vipkoltuk.txt", "r");
    FILE *ikin = fopen("ikikoltuk.txt", "r");
    FILE *ucuncu = fopen("ukoltuk.txt", "r");

    if (!VIP || !ikin || !ucuncu) {
        printf("Dosya açýlamadý.\n");
        return -1;
    }
	int s;
    for ( s = 0; s < 5; s++) fscanf(VIP, "%d", &koltuk[s]);
    for ( s = 5; s < 10; s++) fscanf(ikin, "%d", &koltuk[s]);
    for ( s = 10; s < 15; s++) fscanf(ucuncu, "%d", &koltuk[s]);

    fclose(VIP);
    fclose(ikin);
    fclose(ucuncu);
    return 0;
}

void degerd(int koltuk[]) {
    FILE *VIP = fopen("vipkoltuk.txt", "w");
    FILE *ikin = fopen("ikikoltuk.txt", "w");
    FILE *ucuncu = fopen("ukoltuk.txt", "w");
	int z;
    for ( z = 0; z < 15; z++) {
        if (z < 5) {
            fprintf(VIP, "%d\n", koltuk[z]);
        } else if (z < 10) {
            fprintf(ikin, "%d\n", koltuk[z]);
        } else {
            fprintf(ucuncu, "%d\n", koltuk[z]);
        }
    }

    fclose(VIP);
    fclose(ikin);
    fclose(ucuncu);
}


isimal (struct bilgi kullanici, int  p, int y){
FILE *bil = fopen("bilgi.txt","a");
	printf("Bilet seçimini tamamlayabilmek için kimlik bilgilerinizi sýrayla girmeniz gerekmektedir.\n");
	fprintf(bil,"---------Alýcý Bilgileri----------\n");
	printf("lutfen isim girin :");
	scanf("%s",&kullanici.ad);
	fprintf(bil,"alýcý ismi: %s\n", kullanici.ad);

	printf("lutfen soyisim girin :");
	scanf("%s",&kullanici.soyad);
	fprintf(bil,"alýcý soyadý :%s \n",kullanici.soyad);
	
	kullanici.kno = y;
	fprintf(bil,"Koltuk numarasý :%d\n",kullanici.kno);
	
	
	printf("lutfen TC Kimlik Numaranýzý girin :");
	while(1){
		long long int j = scanf("%d",&kullanici.TC);
		if(j==0){
			printf("lütfen sadece rakamlardan oluþan bir numara giriniz: ");
			while (getchar() != '\n');
			
		}else{
			break;
		}
	}
	fprintf(bil,"T.C kimlik no : %d\n----------------------------\n\n", kullanici.TC);
	fclose(bil);
		
	printf("************Bilet Bilgileri************\n");
	printf("isim : %s\n",kullanici.ad);
	printf("soyisim: %s\n",kullanici.soyad);
	printf("TC Kimlik Numaranýz : %d\n",kullanici.TC);
	kullanici.kno = y;
		switch(p){
			case(1):	printf("Koltuk tipi :Vip tipi koltuk\n");break;
			case(2):    printf("Koltuk tipi :2.tip koltuk\n");break;
			case(3):    printf("Koltuk tipi :3.tip koltuk\n");break;
		}
	 
	printf("koltuk numaranýz : %d\n",kullanici.kno);
	printf("*************************************\n\n");	
		
		
		
}
void tekrar(){
	int f;
	printf("tekrar iþlem yapmak ister misin ?\n");
	printf("(1 evet/0 hayýr):");
	while (1) {
        int a = scanf("%d", &f);
        if (a == 1) {
            switch (f) {
                case 1: printf("tekrar iþlem yapmanýz için sayfaya yönlendiriliyorsunuz...\n\n\n");main();
                case 0: printf("çýkýþ yapýlýyor...");exit(0) ;break;
            	default: printf("Geçersiz deðer girdiniz, lütfen tekrar deneyin: "); break;
            }
        } else {
            printf("Lütfen bir sayý giriniz: ");
            while (getchar() != '\n');
        }
    }
	
	}




int main() {
	setlocale(LC_ALL, "Turkish");
	struct bilgi kullanici;
    int koltuk[15] = {0};
    	okuma(koltuk);
    	menu();
    	while(1){
		
    int p = sal();
    	menu2(koltuk);
    	int kategori;

    switch (p) {
        case 1: kategori = vip(koltuk); degerd(koltuk);isimal(kullanici, p,kategori);tekrar(); break;
        case 2: kategori = iki(koltuk); degerd(koltuk);isimal(kullanici, p,kategori);tekrar(); break;
        case 3: kategori = uc(koltuk); degerd(koltuk);isimal(kullanici, p ,kategori);tekrar(); break;
        default: break;
    }
    

    return 0;

}
}





