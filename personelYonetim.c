#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char tcKimlikNo[12];
    char isim[16];
    char soyisim[16];
    char telefon[12];
    char calistigiBolum[31];
} Personel;

#define MAX_PERSONEL 100
#define DOSYA_ADI "personel.txt"

Personel personeller[MAX_PERSONEL];
int personelSayisi = 0;

void dosyadanOku() {
    FILE *dosya = fopen(DOSYA_ADI, "r");
    if (!dosya) {
        return;
    }

    while (fscanf(dosya, "%s %s %s %s %s\n", personeller[personelSayisi].tcKimlikNo, personeller[personelSayisi].isim, personeller[personelSayisi].soyisim, personeller[personelSayisi].telefon, personeller[personelSayisi].calistigiBolum) != EOF) {
        personelSayisi++;
    }

    fclose(dosya);
}

void dosyayaKaydet() {
    FILE *dosya = fopen(DOSYA_ADI, "w");
    if (!dosya) {
        return;
    }

    for (int i = 0; i < personelSayisi; i++) {
        fprintf(dosya, "%s %s %s %s %s\n", personeller[i].tcKimlikNo, personeller[i].isim, personeller[i].soyisim, personeller[i].telefon, personeller[i].calistigiBolum);
    }

    fclose(dosya);
}

void kayitEkle() {
    if (personelSayisi >= MAX_PERSONEL) {
        printf("Maksimum personel sayısına ulaşıldı.\n");
        return;
    }

    Personel yeniPersonel;
    printf("TC Kimlik No: ");
    scanf("%s", yeniPersonel.tcKimlikNo);
    printf("İsim: ");
    scanf("%s", yeniPersonel.isim);
    printf("Soyisim: ");
    scanf("%s", yeniPersonel.soyisim);
    printf("Telefon: ");
    scanf("%s", yeniPersonel.telefon);
    printf("Çalıştığı Bölüm: ");
    scanf("%s", yeniPersonel.calistigiBolum);

    personeller[personelSayisi++] = yeniPersonel;
    dosyayaKaydet();
}

void kayitSil() {
    char tcKimlikNo[12];
    printf("Silinecek personelin TC Kimlik No: ");
    scanf("%s", tcKimlikNo);

    int bulundu = 0;
    for (int i = 0; i < personelSayisi; i++) {
        if (strcmp(personeller[i].tcKimlikNo, tcKimlikNo) == 0) {
            for (int j = i; j < personelSayisi - 1; j++) {
                personeller[j] = personeller[j + 1];
            }
            personelSayisi--;
            bulundu = 1;
            break;
        }
    }

    if (bulundu) {
        printf("Personel silindi.\n");
        dosyayaKaydet();
    } else {
        printf("Personel bulunamadı.\n");
    }
}

void kayitGuncelle() {
    char tcKimlikNo[12];
    printf("Güncellenecek personelin TC Kimlik No: ");
    scanf("%s", tcKimlikNo);

    for (int i = 0; i < personelSayisi; i++) {
        if (strcmp(personeller[i].tcKimlikNo, tcKimlikNo) == 0) {
            printf("Yeni İsim: ");
            scanf("%s", personeller[i].isim);
            printf("Yeni Soyisim: ");
            scanf("%s", personeller[i].soyisim);
            printf("Yeni Telefon: ");
            scanf("%s", personeller[i].telefon);
            printf("Yeni Çalıştığı Bölüm: ");
            scanf("%s", personeller[i].calistigiBolum);

            dosyayaKaydet();
            return;
        }
    }

    printf("Personel bulunamadı.\n");
}

void kayitListele() {
    for (int i = 0; i < personelSayisi; i++) {
        printf("%s %s %s %s %s\n", personeller[i].tcKimlikNo, personeller[i].isim, personeller[i].soyisim, personeller[i].telefon, personeller[i].calistigiBolum);
    }
}

void kayitAra() {
    char aramaTerimi[31];
    printf("Arama terimi giriniz: ");
    scanf("%s", aramaTerimi);

    for (int i = 0; i < personelSayisi; i++) {
        if (strstr(personeller[i].tcKimlikNo, aramaTerimi) || strstr(personeller[i].isim, aramaTerimi) || strstr(personeller[i].soyisim, aramaTerimi) || strstr(personeller[i].telefon, aramaTerimi) || strstr(personeller[i].calistigiBolum, aramaTerimi)) {
            printf("%s %s %s %s %s\n", personeller[i].tcKimlikNo, personeller[i].isim, personeller[i].soyisim, personeller[i].telefon, personeller[i].calistigiBolum);
        }
    }
}

int main() {
    int secim;

    dosyadanOku();

    do {
        printf("\n1. Kayıt Listele\n");
        printf("2. Kayıt Ara\n");
        printf("3. Kayıt Ekle\n");
        printf("4. Kayıt Sil\n");
        printf("5. Kayıt Güncelle\n");
        printf("6. Programdan Çıkış\n");
        printf("Seciminizi giriniz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                kayitListele();
                break;
            case 2:
                kayitAra();
                break;
            case 3:
                kayitEkle();
                break;
            case 4:
                kayitSil();
                break;
            case 5:
                kayitGuncelle();
                break;
        }
    } while (secim != 6);

    return 0;
}
