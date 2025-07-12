#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <clocale>
#include <vector>

using namespace std;

class hareket {
public:
    string ad;
    int guc;
    hareket(string ad = "", int guc = 0) : ad(ad), guc(guc) {}
};


class pokemon {
public:
    string ad;
    int Can;
    int saldiri, savunma, hiz, seviye, deneyim;
    hareket h1;
    hareket h2;
    hareket h3;
    hareket h4;

    pokemon(string ad = "", int saldiri = 0, int savunma = 0, int hiz = 0, int seviye = 1, int deneyim = 0)
        : ad(ad), saldiri(saldiri), savunma(savunma), hiz(hiz), seviye(seviye),Can(Can) ,deneyim(deneyim),h1(h1),h2(h2),h3(h3),h4(h4) {

 
    }

    void hareketleriGoster() {
        cout << ad << " adlı Pokémon'un hareketleri:" << endl
            << "1." << h1.ad<<"güc :"<<h1.guc << endl
            << "2." << h2.ad<<"güc :"<<h1.guc << endl
            << "3." << h3.ad<<"güc :"<<h1.guc << endl
            << "4." << h4.ad<<"güc :"<<h1.guc  << endl;
        
    }
};


class pokemontopu {
public:
    string ad;
    int yakalama_sansi;
    pokemontopu(string ad="", int yakalama_sansi=0) :ad(ad),yakalama_sansi(yakalama_sansi){}
};



class kullanici {
public:
    string isim;
    string sifre;
    int ktip; // 0: kullanıcı, 1: admin

    void kullaniciarayuz() {
        cout << endl << endl << "OYUNCU ARAYÜZÜ" << endl;
        cout << "1. Pokémonlarımı göster" << endl
            << "2. Pokémon sil" << endl
            << "3. Hareket et" << endl
            << "4. ÇIKIŞ YAP" << endl;
    }


    virtual void pokemonsil(vector<pokemon>& eldeki) {
        int secim;
        int adet = eldeki.size();
        if (adet == 1) {
            cout << "saddece 1 adet pokemonunuz bulunmakta , işlem yapamazsınız" << endl;
            exit(0);
        }
        for (int i = 0; i < adet; i++) {
            cout << i + 1 << "." << eldeki[i].ad << endl;
        }
        
        while (1) {
            cout << "Silmek istediğiniz Pokémon'u seçiniz (rakam olarak): ";
            cin >> secim;
            cout << "seçim yapınız : "; cin >> secim;
            if (cin.fail() || secim > eldeki.size() || secim < 0) {
                cout << "yanlış değer girdiniz " << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else { break; }
        }
        cin >> secim;
        if (secim < 1 || secim > adet) {
            cout << "Geçersiz seçim!" << endl;
            return;
        }
        eldeki.erase(eldeki.begin() + secim - 1);
    }

    void pokemonlarigoster(vector<pokemon>&eldeki) {
        int adet = eldeki.size();
        cout << "elinizdeki pokemonlar gosteriliyor" << endl;
        cout << "AD / CAN / SALDIRI / SAVUNMA / HIZ / DENEYİM / SEVİYE " << endl;
        for (int i = 0; i < adet; i++) {
            cout << i+1 <<". "<< eldeki[i].ad << "  " << eldeki[i].Can << "  " << eldeki[i].savunma << "  " << eldeki[i].savunma << "  " << eldeki[i].hiz << "  " << eldeki[i].deneyim << "  " << eldeki[i].seviye << endl;

        }

    }
    int savassecim(kullanici& giren, pokemon& dusman, vector<pokemon>& eldekipokemon, vector<pokemon>tumpokemonlar, vector<pokemontopu>tümpokemontopları, vector<hareket>& hareketler, vector<pokemontopu>& eldekipokemontopları);
    void yuruyus(kullanici& giren,vector<pokemon>&eldekipokemon, vector<pokemon>tumu, vector<pokemontopu>& hepsi,vector<pokemontopu>eldekipokemontopları, vector<hareket>&hareketler);
    void pokesectir(kullanici& giren, vector<pokemon>& eldekipokemon, vector<pokemon>& tumpokemonlar, pokemon& dusman, vector<pokemontopu>eldekipokemontopu, vector<pokemontopu>tümpokemontopları, vector<hareket>tumhareketler);
    void hareketsectirvesaldır(kullanici& giren, vector<pokemon>& eldekipokemon, vector<pokemon>& tumpokemonlar, pokemon& dusman, int secim, vector<pokemontopu>& tümpokemontopları, vector<hareket> htum, vector<pokemontopu>eldekipt);
    void dusmansaldır(kullanici& giren, vector<pokemon>& eldekipokemon, pokemon& dusman, vector<pokemontopu>tümpt, vector<pokemon>tumpokemonlar, int secim, vector<pokemontopu>eldekipokemontopları, vector<hareket>hareketler);
    void poketopuat(kullanici giren,pokemon dusman,vector<pokemontopu>eldekipt, vector<pokemontopu>tümpt, vector<pokemon>& eldekipokemon, vector<pokemon>tümpokemonlar, vector<hareket>hareketler);
};


class yonetici : public kullanici {
public:
    void yoneticiMenusu() {
        cout << endl << endl << "YÖNETİCİ MENÜSÜ" << endl;
        cout << "1. Pokémonları göster" << endl
            << "2. Pokémon ekle" << endl
            << "3. Pokémon sil" << endl
            << "4. Hareketleri listele" << endl
            << "5. Hareket ekle" << endl
            << "6. Hareket sil" << endl
            << "7.Pokemon Toplarini Listele" << endl
            << "8.Pokemon topu ekle" << endl
            << "9.Pokemon topu sil" << endl
            << "10.Kullanicilari listele" << endl
            << "11.Kullanici ekle" << endl
            << "12.Kullanici Sil" << endl
            << "0.CİKİS YAP" << endl;

    }

    void hareketleriListele(vector<hareket>&h) {
        int adet = h.size();
        for (int i = 0; i < adet; i++) {
            cout <<endl<< h[i].ad << " (Güç: " << h[i].guc << ")" << endl;
        }
    }

    void hareketekle(vector<hareket>&h) {
        hareket yedek;
        string isim;
        int hasar;
        cout << " lutfen eklemek istediginiz yeteneğin ismini giriniz : ";  cin >> isim; cout << endl;
        while (1) {
            while (1) {
                cout << " lutfen eklemek istediginiz yeteneğin hasarını giriniz : ";
                cin >> hasar;
                cout << "seçim yapınız : "; cin >> hasar;
                if (cin.fail() || hasar > h.size() || hasar < 0) {
                    cout << "yanlış değer girdiniz " << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                else { break; }
            }
        }
        yedek.ad = isim;
        yedek.guc = hasar;
        h.push_back(yedek);
        ofstream dosya("moves.txt", ios::app);
        if (!dosya) {
            cout << "moves.txt dosyasi acilamadi." << endl;
            return;
        }
        dosya << isim << "  " << hasar << "  " << endl;
        dosya.close();

    }

    void hareketsil(vector<hareket>&h) {
        int secim;
        int adet = h.size();

        for (int i = 0; i < adet; i++) {
            cout << i + 1 << ". ad :" << h[i].ad << "   guc :" << h[i].guc << endl;

        }
        cout << "Hangi hareketi silmek istersiniz ? :";
        while (1) {
            cin >> secim;
            cout << "seçim yapınız : "; cin >> secim;
            if (cin.fail()||secim>h.size()||secim<0) {
                cout << "yanlış değer girdiniz " << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else { break; }
        }
        if (adet > 4) {
            h.erase(h.begin() + secim - 1);
            ofstream("moves.txt", ios::out);
            for (secim = 0; secim < adet - 1; secim++) {
                cout << h[secim].ad << "  " << h[secim].guc;

            }
            fclose;
            adet = adet - 1;
        }
        







    }

    void pokemonekle(vector<pokemon>&p) {
        pokemon yedek;
        string isim;
        int can, savunma, saldiri, hiz;
    
        cout << "Pokemon ismi: "; cin >> isim;
       
        while (1) {
            cout << "Can: "; cin >> can;
            if (cin.fail()) {
                cout << "yanlış değer girdiniz " << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else { break; }
        }
        while (1) {
            cout << "Savunma: "; cin >> savunma;
            if (cin.fail()) {
                cout << "yanlış değer girdiniz " << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else { break; }
        }
        while (1) {
            cout << "Hiz: "; cin >> hiz;
            if (cin.fail()) {
                cout << "yanlış değer girdiniz " << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else { break; }
        }
        while (1) {
            cout << "Saldiri: "; cin >> saldiri;
            if (cin.fail()) {
                cout << "yanlış değer girdiniz " << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else { break; }
        }
       
        
        yedek.ad = isim;
        yedek.Can = can;
        yedek.savunma = savunma;
        yedek.hiz = hiz;
        yedek.saldiri = saldiri;
        p.push_back(yedek);
        ofstream dosya("pokemons.txt", ios::app);
        if (!dosya) {
            cout << "HATA: pokemons.txt dosyasi acilamadi.\n";
            return;
        }
        dosya << isim << " " << can << " " << saldiri << " " << savunma << " " << hiz << endl;
        dosya.close();
    }

    void pokemonlarigoster(vector<pokemon>&hepsi, int adet) {
        cout << " AD / CAN / SALDIRI / SAVUNMA / HIZ " << endl;;
        for (int i = 0; i < adet; i++) {
            cout << hepsi[i].ad << " " << hepsi[i].Can << " " <<hepsi[i].saldiri<<" " << hepsi[i].savunma << " " << hepsi[i].hiz << endl;
        }


    }

    void pokemonsil(vector<pokemon>&h) {
        int pokemonsayısı = h.size();
        int secim;
        for (int i = 0; i < pokemonsayısı; i++) {
            cout << i + 1 << ". " << h[i].ad << endl;
        }
        
        while (1) {
            cout << "silmek istediginiz pokemonu seciniz ( rakam olarak ) :" << endl; cin >> secim;
            if (cin.fail()||secim>h.size()||secim<0){
                cout << "yanlış değer girdiniz " << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else { break; }
        }
            h.erase(h.begin() + secim - 1);
            ofstream dosya("pokemons.txt", ios::out);
            if (!dosya) {
                cout << "pokemons.txt dosyasi acilamadi.\n";
            }
            for (int i = 0; i < pokemonsayısı - 1; i++) {

                dosya << h[i].ad << " " << h[i].Can << " " << h[i].saldiri << " " << h[i].savunma << " " << h[i].hiz << endl;
            }
            dosya.close();

    }

    void kullaniciekle(vector<kullanici>&k) {
        kullanici yedek;
        string isim;
        string sifre;
        int yetki;
        cout << " lutfen eklemek istediginiz kullanicinin ismini giriniz : ";  cin >> isim; cout << endl;
        cout << "lutfen eklemek istediginiz kullanicinin sifresini giriniz :"; cin >> sifre; cout << endl;
 
            while (true) {
                cout << "lutfen eklemek istediginiz kullanicinin yetkisi yonetici ise 1 , kullanıcı ise 0 i tuslayiniz : "; cin >> yetki; cout << endl;

                if (yetki < 0 || yetki>1 || cin.fail()) {
                    cout << "istenmeyen tuşlama ! Tekrar dene " << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                else {
                    break;
                }
            }
            yedek.isim = isim;
            yedek.sifre = sifre;
            yedek.ktip = yetki;
            k.push_back(yedek);

        ofstream dosya("users.txt", ios::app);
        if (!dosya) {
            cout << "users.txt dosyasi acilamadi." << endl;
            return;
        }
        dosya << isim << "  " << sifre << "  " << yetki << endl;
        dosya.close();
    }

    void kullanicilarigoster(vector<kullanici>&hepsi, int adet) {
        cout << " AD / SİFRE / YETKISI  "<<endl;
        for (int i = 0; i < adet; i++) {
            cout << hepsi[i].isim << " " << hepsi[i].sifre << " ";
            if (hepsi[i].ktip == 0) {
                cout << "kullanici " << endl;
            }
            else {
                cout << "yonetici " << endl;
            }
        }

    }

    void kullanicisil(vector<kullanici>&h) {
        int secim;
        int kisisayisi = h.size();

        for (int i = 0; i < kisisayisi; i++) {
            cout << i + 1 << ". " << h[i].isim << endl;

        }
        while (1) {
            cout << "silmek istediginiz kullanıcıyı seciniz ( rakam olarak ) :" << endl; cin >> secim;
            if (cin.fail()||secim>h.size()||secim<0){
                cout << "yanlış değer girdiniz " << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else { break; }
        }
        if (kisisayisi > 1) {
            h.erase(h.begin() + secim - 1);
            ofstream dosya("users.txt", ios::out);
            if (!dosya) {
                cout << "users.txt dosyasi acilamadi.\n";
            }
            for (int i = 0; i < kisisayisi - 1; i++) {

                dosya << h[i].isim<<" " <<h[i].sifre<<" "<<h[i].ktip << endl;
            }
            dosya.close();
        }

    }

    void poketopuekle(vector<pokemontopu>p) {
        string isim;
        int  sans;
        pokemontopu yedek;
        cout << " lutfen eklemek istediginiz poketopunun ismini giriniz : ";  cin >> isim; cout << endl;
    
            while (1) {
                cout << "lutfen eklemek istediginiz poketopunun yakalama sansini giriniz :"; cin >> sans; cout << endl;
                if (cin.fail()||sans>100) {
                    cout << "yanlış değer girdiniz " << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                else { break; }
            }
        
        yedek.ad = isim;
        yedek.yakalama_sansi = sans;
        p.push_back(yedek);
        ofstream dosya("pokeballs.txt", ios::app);
        if (!dosya) {
            cout << "pokeballs.txt dosyasi acilamadi." << endl;
            return;
        }
        dosya << isim << "  " << sans << endl;
        dosya.close();
    }

    void poketopgoster(vector<pokemontopu>&h, int adet) {
        cout << "pokemon topları gosteriliyor...";
        cout << "   AD      /   YAKALAMA ORANI"<<endl;
        for (int i = 0; i < adet; i++) {
            cout << h[i].ad << " " << h[i].yakalama_sansi << ")" << endl;
        }



    }

    void poketopsil(vector<pokemontopu>&h) {
        int secim;
        int boyut = h.size();
        cout << "POKEMON TOPLARI : ";
        for (int a = 0; a < boyut; a++) {
            cout << a + 1 << ". " << h[a].ad << "   " << h[a].yakalama_sansi << endl;
        }
       
        while (1) {
            cout << "kacinci pokemon topunu silmek istersiniz ? : "; cin >> secim;
            if (cin.fail() || secim > h.size() || secim < 0) {
                cout << "yanlış değer girdiniz " << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else { break; }
        }
        if (boyut > 1) {
            h.erase(h.begin() + secim - 1);

                ofstream dosya("pokeballs.txt", ios::out);
                if (!dosya) {
                    cout << "pokeballs.txt dosyasi acilamadi." << endl;
                    return;
                }
                for (int i = 0; i < boyut - 1; i++) {

                    dosya << h[i].ad << " " << h[i].yakalama_sansi << endl;
                }
                dosya.close();
            }
        else{
            cout << "programın düzgün çalışabilmesi için en az 1 poketopuna ihtiyaç vardır . Bu nedenle işleminiz yapılamaz "<<endl;
    




        }



    }
};


int rastgeleSayi(int sinir) {
   
    return rand() % sinir;
}

void giris(kullanici & giren) {
    cout << "*#####*****POKEMON*****#####*" << endl;
    cout << "*Kullanıcı adı: "; cin >> giren.isim;
    cout << "*Şifre: "; cin >> giren.sifre;
    cout << "*****************************" << endl;
}

void kullanicilariYukle(vector<kullanici>&tumu) {
    ifstream dosya("users.txt");
    int i = 0;

    if (!dosya) {
        cout << "users.txt dosyası açılamadı.\n";
    }

    kullanici k;

    while (dosya >> k.isim >> k.sifre >> k.ktip) {
        tumu.push_back(k);

    }

    dosya.close();
    
}

void pokemontoplariniYukle(vector<pokemontopu>&hepsi) {
    ifstream dosya("pokeballs.txt");
    if (!dosya) {
        cout << "Dosya açılamadı.\n";
    }
    pokemontopu p;
    while (dosya >> p.ad >> p.yakalama_sansi) {
        hepsi.push_back(p);
    }

    dosya.close();
}

void hareketleriYukle(vector<hareket>&hepsi) {
    ifstream dosya("moves.txt");
    int i = 0;
    if (!dosya) {
        cout << "moves.txt dosyası açılamadı.\n";
    }
    hareket h;
    while (dosya >> h.ad >> h.guc) {
        hepsi.push_back(h);
    }
    dosya.close();
    
}

void pokemonlariYukle(vector<pokemon>&hepsi) {
    ifstream dosya("pokemons.txt");
    int i = 0;
    if (!dosya) {
        cout << "pokemons.txt dosyası açılamadı.\n";
       
    }
    pokemon p;
    while (dosya >> p.ad >> p.Can >> p.saldiri >> p.savunma >> p.hiz) {
        p.seviye = 1;
        p.deneyim = 0;
        hepsi.push_back(p);
        
    }
    dosya.close();
}

int dogrula(kullanici &giren, vector<kullanici>tum, int adet, yonetici* y) {
    while (1) {
        for (int i = 0; i < adet; i++) {
            if (giren.isim == tum[i].isim && giren.sifre == tum[i].sifre) {
                if (tum[i].ktip == 1) {
                    giren.ktip = 1;
                    return 1;
                }
                else {
                    giren.ktip = 0;
                    return 0;
                }
                break;
            }

        }
        cout << "yanlis kullanıcı adı veya şifre girdiniz , lütfen tekrar deneyiniz " << endl; giris(giren);
    }
}

void pokemonlaraHareketAta(vector<pokemon>&eldeki,vector<hareket> h) {
    int rast;
    int adet = eldeki.size();
    int hareketsayi = h.size();
    for (int i = 0; i < adet; i++) {
            rast = rastgeleSayi(hareketsayi);
            eldeki[i].h1 = h[rast];
            rast = rastgeleSayi(hareketsayi);
            eldeki[i].h2 = h[rast];
            rast = rastgeleSayi(hareketsayi);
            eldeki[i].h3 = h[rast];
            rast = rastgeleSayi(hareketsayi);
            eldeki[i].h4 = h[rast];
        }
    }


void menugoster(kullanici& giren,yonetici *yon) {
    if (giren.ktip == 0) {
        giren.kullaniciarayuz();
    }
    else {
        yon->yoneticiMenusu();
    }

}

void yoneticisec(yonetici* a, vector<pokemon>hepsi, vector<hareket>hareketler, vector<pokemontopu>p, vector<kullanici>tumu) {//yoneticinin menüyü secme sansı verir
    int secim;
    while (true) {
        
        while (true) {
            
            
            cout << "yapmak istediginiz islem icin secim yapiniz : "; cin >> secim;

            if (secim < 0 || secim>12 || cin.fail()) {
                cout << "istenmeyen tuşlama ! Tekrar dene " << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                a->yoneticiMenusu();
            }
            else {
                break;
            }
        }
        switch (secim) {
        case 0:cout << "cikis yapiliyor... "; exit(0);
        case 1:a->pokemonlarigoster(hepsi, hepsi.size()); a->yoneticiMenusu(); break;
        case 2:a->pokemonekle(hepsi); a->yoneticiMenusu(); break;
        case 3:a->pokemonsil(hepsi); a->yoneticiMenusu(); break;
        case 4:a->hareketleriListele(hareketler); a->yoneticiMenusu(); break;
        case 5:a->hareketekle(hareketler); a->yoneticiMenusu(); break;
        case 6:a->hareketsil(hareketler); a->yoneticiMenusu(); break;
        case 7:a->poketopgoster(p, hepsi.size()); a->yoneticiMenusu(); break;
        case 8:a->poketopuekle(p); a->yoneticiMenusu(); break;
        case 9:a->poketopsil(p); a->yoneticiMenusu(); break;
        case 10:a->kullanicilarigoster(tumu, tumu.size()); a->yoneticiMenusu(); break;
        case 11:a->kullaniciekle(tumu); a->yoneticiMenusu(); break;
        case 12:a->kullanicisil(tumu); a->yoneticiMenusu(); break;
        default: break;
        }
    }
}

void kullanicisec(kullanici& giren, vector<pokemon>p, vector<pokemon>tumu, vector<pokemontopu> hepsi, vector<hareket>hareketler, vector<pokemontopu>eldekipokemontopları) {
    int secim;

    while (1) {

        while (true) {

            cout << "yapmak istediginiz islemi seciniz : "; cin >> secim;

            if (secim < 1 || secim>4 || cin.fail()) {
                cout << "istenmeyen tuşlama ! Tekrar dene " << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                giren.kullaniciarayuz();
            }
            else {
                break;
            }
        }
        if (secim == 1) {
            giren.pokemonlarigoster(p); giren.kullaniciarayuz();
        }
        if (secim == 2) {
            giren.pokemonsil(p); giren.kullaniciarayuz();
        }
            if (secim == 3) {
                giren.yuruyus(giren, p, tumu, hepsi, eldekipokemontopları, hareketler); giren.kullaniciarayuz();
            }
         if (secim == 4) {
                    cout << "cikis yapiliyor"; exit(0); giren.kullaniciarayuz();
                }
            
        }
    
}



void kullanici::dusmansaldır(kullanici&giren,vector<pokemon>& eldekipokemon, pokemon& dusman,vector<pokemontopu>tümpt,vector<pokemon>tumpokemonlar, int secim,vector<pokemontopu>eldekipokemontopları,vector<hareket>hareketler) {
    int rast;
    rast = rastgeleSayi(4);
    switch(rast) {
    
    case 1:cout << "düşman " << dusman.h1.ad << "hareketini kullandı ..." << endl;
        eldekipokemon[secim-1].Can = eldekipokemon[secim-1].Can - dusman.h1.guc;

        if (eldekipokemon[secim].Can < 0) {
            cout << "pokemonunuz kaybetti , farklı bir saldırı seçimi için arayüze yönlendiriliyorsunuz" << endl;   
            savassecim(giren, dusman, eldekipokemon, tumpokemonlar, tümpt, hareketler, eldekipokemontopları);
            break;
        }
        else { hareketsectirvesaldır(giren, eldekipokemon, tumpokemonlar, dusman, secim, tümpt, hareketler, eldekipokemontopları); break; }
    
    case 2:cout << "düşman " << dusman.h2.ad << "hareketini kullandı ..." << endl;
        eldekipokemon[secim - 1].Can = eldekipokemon[secim - 1].Can - dusman.h2.guc;

        if (eldekipokemon[secim].Can < 0) {
            cout << "pokemonunuz kaybetti , farklı bir saldırı seçimi için arayüze yönlendiriliyorsunuz" << endl;
            savassecim(giren, dusman, eldekipokemon, tumpokemonlar, tümpt, hareketler, eldekipokemontopları);
            break;
        }
        else { hareketsectirvesaldır(giren, eldekipokemon, tumpokemonlar, dusman, secim, tümpt, hareketler, eldekipokemontopları); break; }
    
    case 3:cout << "düşman " << dusman.h3.ad << "hareketini kullandı ..." << endl;
        eldekipokemon[secim - 1].Can = eldekipokemon[secim - 1].Can - dusman.h3.guc;

        if (eldekipokemon[secim].Can < 0) {
            cout << "pokemonunuz kaybetti , farklı bir saldırı seçimi için arayüze yönlendiriliyorsunuz" << endl;
            savassecim(giren, dusman, eldekipokemon, tumpokemonlar, tümpt, hareketler, eldekipokemontopları);
            break;
        }
        else { hareketsectirvesaldır(giren, eldekipokemon, tumpokemonlar, dusman, secim, tümpt, hareketler, eldekipokemontopları); break; }

    case 4:cout << "düşman " << dusman.h4.ad << "hareketini kullandı ..." << endl;
        eldekipokemon[secim - 1].Can = eldekipokemon[secim - 1].Can - dusman.h4.guc;

        if (eldekipokemon[secim].Can < 0) {
            cout << "pokemonunuz kaybetti , farklı bir saldırı seçimi için arayüze yönlendiriliyorsunuz" << endl;
            savassecim(giren, dusman, eldekipokemon, tumpokemonlar, tümpt, hareketler, eldekipokemontopları);
            break;
        }
        else { hareketsectirvesaldır(giren, eldekipokemon, tumpokemonlar, dusman, secim, tümpt, hareketler, eldekipokemontopları); break; }


    }

}

void kullanici::hareketsectirvesaldır(kullanici& giren, vector<pokemon>& eldekipokemon, vector<pokemon>& tumpokemonlar,pokemon& dusman,int secim,vector<pokemontopu>& tümpokemontopları,vector<hareket> htum,vector<pokemontopu>eldekipt) {
    int hsecim;
    cout << "Kullanabileceğiniz saldırılar : " << endl;
    cout << "1. ad :" << eldekipokemon[secim - 1].h1.ad << "  hasar  :" << eldekipokemon[secim - 1].h1.guc << endl;
    cout << "2. ad :" << eldekipokemon[secim - 1].h2.ad << "  hasar  :" << eldekipokemon[secim - 1].h2.guc << endl;
    cout << "3. ad :" << eldekipokemon[secim - 1].h3.ad << "  hasar  :" << eldekipokemon[secim - 1].h3.guc << endl;
    cout << "4. ad :" << eldekipokemon[secim - 1].h4.ad << "  hasar  :" << eldekipokemon[secim - 1].h4.guc << endl;
    while (true) {
        cout << "saldırı seçimini yap : "; cin >> hsecim;

        if (secim < 1 || secim>4|| cin.fail()) {
            cout << "istenmeyen tuşlama ! Tekrar dene " << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else {
            break;
        }
    }
    switch (hsecim) {
    case 1:dusman.Can = dusman.Can - eldekipokemon[secim - 1].h1.guc;
        if (dusman.Can < 0) {
            cout << "dusman yenildi , geri çekiliyor ..." << endl;
            eldekipokemon[secim - 1].deneyim = eldekipokemon[secim - 1].deneyim + 60;
            if (eldekipokemon[secim - 1].deneyim > 100) {
                eldekipokemon[secim - 1].seviye = eldekipokemon[secim - 1].seviye + 1;   
                eldekipokemon[secim - 1].deneyim = eldekipokemon[secim - 1].deneyim - 100;
            }
            giren.kullaniciarayuz();
            kullanicisec(giren, eldekipokemon, tumpokemonlar, tümpokemontopları, htum, eldekipt);
        }
        else {
            dusmansaldır(giren,eldekipokemon, dusman,tümpokemontopları,tumpokemonlar, secim,eldekipt,htum);
        }
        break;
    case 2:
        dusman.Can = dusman.Can - eldekipokemon[secim - 1].h2.guc;
        if (dusman.Can < 0) {
            cout << "dusman yenildi , geri çekiliyor ...";
            eldekipokemon[secim - 1].deneyim = eldekipokemon[secim - 1].deneyim + 60;
            if (eldekipokemon[secim - 1].deneyim > 100) {
                eldekipokemon[secim - 1].seviye = eldekipokemon[secim - 1].seviye + 1;
                eldekipokemon[secim - 1].deneyim = eldekipokemon[secim - 1].deneyim - 100;
                  }
            giren.kullaniciarayuz();
            kullanicisec(giren, eldekipokemon, tumpokemonlar, tümpokemontopları, htum, eldekipt);
        }
        else {
            dusmansaldır(giren, eldekipokemon, dusman, tümpokemontopları, tumpokemonlar, secim, eldekipt, htum);
        }
        break;
    case 3:
        dusman.Can = dusman.Can - eldekipokemon[secim - 1].h3.guc;
        if (dusman.Can < 0) {
            cout << "dusman yenildi , geri çekiliyor ...";
            eldekipokemon[secim - 1].deneyim = eldekipokemon[secim - 1].deneyim + 60;
            if (eldekipokemon[secim - 1].deneyim > 100) {
                eldekipokemon[secim - 1].seviye = eldekipokemon[secim - 1].seviye + 1;
                eldekipokemon[secim - 1].deneyim = eldekipokemon[secim - 1].deneyim - 100;
            }
            giren.kullaniciarayuz();
            kullanicisec(giren, eldekipokemon, tumpokemonlar, tümpokemontopları, htum, eldekipt);
        }
        else {
            dusmansaldır(giren, eldekipokemon, dusman, tümpokemontopları, tumpokemonlar, secim, eldekipt, htum);
        }
        break;
    case 4:
        dusman.Can = dusman.Can - eldekipokemon[secim - 1].h4.guc;
        if (dusman.Can < 0) {
            cout << "dusman yenildi , geri çekiliyor ...";
            eldekipokemon[secim - 1].deneyim = eldekipokemon[secim - 1].deneyim + 60;
            if (eldekipokemon[secim - 1].deneyim > 100) {
                eldekipokemon[secim - 1].seviye = eldekipokemon[secim - 1].seviye + 1;
                eldekipokemon[secim - 1].deneyim = eldekipokemon[secim - 1].deneyim - 100;
            }
            giren.kullaniciarayuz();
            kullanicisec(giren, eldekipokemon, tumpokemonlar, tümpokemontopları, htum, eldekipt);

        }
        else {
            dusmansaldır(giren, eldekipokemon, dusman, tümpokemontopları, tumpokemonlar, secim, eldekipt, htum); break;
        }
        break;
    }

   
}

void kullanici::pokesectir(kullanici& giren,vector<pokemon>&eldekipokemon, vector<pokemon>&tumpokemonlar,pokemon& dusman,vector<pokemontopu>eldekipokemontopu,vector<pokemontopu>tümpokemontopları,vector<hareket>tumhareketler){
    int secim;
    cout << "savaşmayı seçtin dostum büyük adamsın . Buyur elindeki pokemonlar :" << endl;
    giren.pokemonlarigoster(eldekipokemon);
    while (true) {
        cout << "pokemon seçimini yap : "; cin >> secim;

        if (secim < 1 || secim>eldekipokemon.size()||cin.fail()) {
            cout << "istenmeyen tuşlama ! Tekrar dene " << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else {
            break;
        }
    }
    hareketsectirvesaldır(giren, eldekipokemon,tumpokemonlar, dusman,secim,tümpokemontopları,tumhareketler,eldekipokemontopu);

}

void kullanici::poketopuat(kullanici giren ,pokemon dusman, vector<pokemontopu>eldekipt, vector<pokemontopu>tümpt, vector<pokemon>& eldekipokemon,vector<pokemon>tümpokemonlar,vector<hareket>hareketler) {
    int seçim;
    int rast;
    if (eldekipt.size() > 0) {
        cout << "poketoplarınız gösteriliyor : " << endl;
        for (int i = 0; i < eldekipt.size(); i++) {
            cout << i + 1 << ". Ad: " << eldekipt[i].ad << "yakalama sansı %: " << eldekipt[i].yakalama_sansi << endl;
        }
        while (1) {
            cout << "seçim yapınız : "; cin >> seçim;
            if (cin.fail() || seçim < 0 || seçim > eldekipt.size()) {
                cout << "yanlış değer girdiniz " << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else { break; }
        }
        int sans = eldekipt[seçim-1].yakalama_sansi;
        rast = rastgeleSayi(100);
        if (sans > rast) {
            cout << "tebrikler, pokemonu " << eldekipt[seçim-1].ad << " isimli poketopu kullanarak yakaladınız . Artık sizindir ." << endl << "kullanıcı arayüzüne yönlendiriliyorsunuz..." << endl;
            eldekipokemon.push_back(dusman);
            kullaniciarayuz(); kullanicisec(giren, eldekipokemon, tümpokemonlar, tümpt, hareketler, eldekipt);
        }
        else {
            cout << "topunuz pokemonu ne yazık ki yakalayamadı ... geriye yönlendiriliyorsunuz ...." << endl;
            savassecim(giren, dusman, eldekipokemon, tümpokemonlar, tümpt, hareketler, eldekipt);

        }

    }
    else {
        cout << "poketopunuz bulunmamaktadır . Farklı bir saldırı deneyiniz veya kaçınız" << endl;
        savassecim(giren, dusman, eldekipokemon, tümpokemonlar, tümpt, hareketler, eldekipt);

    }

}

int kullanici::savassecim(kullanici& giren, pokemon& dusman, vector<pokemon>& eldekipokemon, vector<pokemon>tumpokemonlar, vector<pokemontopu>tümpokemontopları, vector<hareket>& hareketler, vector<pokemontopu>& eldekipokemontopları) {
    int secim;
    cout << "1.Savaş " << endl;
    cout << "2.Pokemon Toplarını kullan" << endl;   
    cout << "3.Topukla " << endl;
    while(true){
        cout << "Seçim yap : "; cin >> secim;
        if (secim < 0 || secim>3 || cin.fail()) {
            cout << "istenmeyen tuşlama ! Tekrar dene " << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else { break; }
    }
        if (secim == 1) {
            if (eldekipokemon.size() == 0) {
                cout << "elinizde ileri sürmek için pokemon şuanlık bulunmamakta . Bir sonraki yürüyüşte tekrar deneyin veya başka bir seçim yapın ..." << endl;
                savassecim(giren, dusman, eldekipokemon, tumpokemonlar, tümpokemontopları, hareketler, eldekipokemontopları);
            }
            pokesectir(giren, eldekipokemon, tumpokemonlar, dusman, eldekipokemontopları,tümpokemontopları, hareketler);
        }
        if (secim == 2) { poketopuat(giren, dusman, eldekipokemontopları, tümpokemontopları, eldekipokemon, tumpokemonlar, hareketler); }
        if (secim == 3) {
            cout << "ödlek gibi kaçtınız ...";
            kullaniciarayuz(); kullanicisec(giren, eldekipokemon, tumpokemonlar, tümpokemontopları, hareketler, eldekipokemontopları); }

        return secim;
    
}

void kullanici::yuruyus(kullanici& giren, vector<pokemon>& eldekipokemon, vector<pokemon>tumu, vector<pokemontopu>& hepsi, vector<pokemontopu>eldekipokemontopları, vector<hareket>& hareketler) {
    int rast = rastgeleSayi(tumu.size());
    pokemon dusman;
    


    int secim;
    cout << "yuruyuse cıktınız..." << endl;
    rast = rastgeleSayi(100);
    if (rast <= 40) {
        rast = rastgeleSayi(tumu.size());

        dusman = tumu[rast];
        rast = rastgeleSayi(hareketler.size());
        dusman.h1 = hareketler[rast];
        rast = rastgeleSayi(hareketler.size());
        dusman.h2 = hareketler[rast];
        rast = rastgeleSayi(hareketler.size());
        dusman.h3 = hareketler[rast];
        rast = rastgeleSayi(hareketler.size());
        dusman.h4 = hareketler[rast];

        cout << "karşına büyüğünden bir " << dusman.ad << " çıktı , ne yapacaksın ? " << endl;

        savassecim(giren, dusman, eldekipokemon, tumu, hepsi, hareketler,eldekipokemontopları);
        

    }
    else {
        cout << "kimseyle karşılaşılmadı ana menüye yönlendiriliyorsun ..." << endl;
        giren.kullaniciarayuz(); kullanicisec(giren, eldekipokemon, tumu, hepsi, hareketler, eldekipokemontopları);
    }

}


int main() {

    setlocale(LC_ALL, "Turkish");
    srand(time(NULL));


    kullanici giren;
    vector<kullanici>kullanicilar;
    vector<pokemon>tumpokemonlar;
    vector<pokemon>eldekiPokemonlar(3);
    vector<hareket>hareketler;
    yonetici* yon = new yonetici;
    vector<pokemontopu>tümpokemontopları;
    vector<pokemontopu>eldekipokemontopları;

    kullanicilariYukle(kullanicilar);
    int kisisayisi = kullanicilar.size();


    hareketleriYukle(hareketler);
     int hareketSayisi = hareketler.size();
    

    pokemonlariYukle(tumpokemonlar);
     int pokemonSayisi = tumpokemonlar.size();
   

    pokemontoplariniYukle(tümpokemontopları);
     int poketopsayisi = tümpokemontopları.size();

    giris(giren);

    dogrula(giren, kullanicilar, kisisayisi, yon);

    if (giren.ktip == 0) {
        for (int i = 0; i < 3; i++) {
            int r = rastgeleSayi(pokemonSayisi);
            eldekiPokemonlar[i] = tumpokemonlar[r];
             r = rastgeleSayi(tümpokemontopları.size());
            eldekipokemontopları.push_back(tümpokemontopları[r]);
        }

        pokemonlaraHareketAta(eldekiPokemonlar, hareketler);
    }
   
    menugoster(giren, yon);


    switch (giren.ktip)
    {
    case 1:yoneticisec(yon, tumpokemonlar, hareketler, tümpokemontopları, kullanicilar); break;

    case 0:kullanicisec(giren, eldekiPokemonlar,tumpokemonlar, tümpokemontopları, hareketler,eldekipokemontopları); break;
    
    default:break;
    }


        return 0;

    }

