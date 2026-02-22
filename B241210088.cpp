/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…...:Güz Dönemi 1.Ödev
**				ÖĞRENCİ ADI...............:Enes Çağrı ÇALIŞKAN
**				ÖĞRENCİ NUMARASI.:b241210088
**				DERS GRUBU…………:A grubu
****************************************************************************/


#include <iostream>
#include<string> //String veri tipini kullanmak için yüklendi
#include<stdlib.h> //rand ve srand komutlarını kullanmak için yüklendi
#include<clocale> //Türkçe karakterler kullanmak için yüklendi
#include<iomanip> //Hizalama komutlarını (setw ve setprecsion) kullanmak için yüklendi
#include<climits> // INT_MAX ve INT_MIN değerlerini kullanmak için yüklendi
using namespace std;
int ay;
int fiyat_artış_periyodu;//Alış fiyatının artış periyodunun tutulduğu değişken
double fiyat_artış_oranı;//Alış fiyatının artış oranının tutulduğu değişken
int yillik_en_cok_satilan = 0, yillik_en_az_satilan = INT_MAX; // Bu değişkenler ay'dan aya sıfırlanmaması için ana fonksiyonun dışına yazılmıştır
int yillik_en_cok_urun = -1, yillik_en_az_urun = -1;
double toplam_gelir = 0;
double toplam_maliyet = 0;

int main()
{
    setlocale(LC_ALL, "Turkish");
    string Ürün_listesi[20]{ "Kek", "Gofret", "Yüzey Temizleyici", "Bisküvi", "Kola", "Soğuk Çay", "Mısır Gevreği", "Sigara", "Sakız", "Cips", "Islak Mendil", "Peçete", "Soğuk kahve", "Süt(1L)", "Pil", "Çakmak", "Erkek Şampuanı", "Kadın Şampuanı", "Diş Macunu", "Diş Fırçası" };
    float Alış_Fiyatı[20]{ 3,4,50,5,8,8,20,50,10,20,20,10,5,30,18,45,20,40,80,50 };
    double Satış_fiyatı[20];
    double KDV_dahil_satıs_fiyatı[20];
    double Stok_miktarı[20] = { 300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300 };

    //Bu döngü belirtilen orana göre ürünlerin kdv dahil satış fiyatını belirlemesi için yapılmıştır. (KDV oranı tüm ürünlerde %8 olarak tutulmuştur.)
    for (int i = 0; i < 20; i++) {
        double fiyat_farkı = (70 + rand() % 21) / 100.0; //%50 ile %70 arasında rasgtele bir değer verir.
        Satış_fiyatı[i] = Alış_Fiyatı[i] + Alış_Fiyatı[i] * fiyat_farkı;
        KDV_dahil_satıs_fiyatı[i] = Satış_fiyatı[i] + (Satış_fiyatı[i] * 8) / 100;
    }

    //Ticarethanenin ilk açıldığında olan değerleri listeleler.
    cout << "BAŞLANGIÇ TABLOSU:" << endl;
    cout << left << setw(5) << "No"
        << setw(20) << "Ürün"
        << setw(15) << "Alış Fiyatı"
        << setw(15) << "Satış Fiyatı"
        << setw(15) << "Stok Miktarı" << endl;
    cout << "-------------------------------------------------------------" << endl;


    for (int a = 0; a < 20; a++) {
        cout << setw(5) << a + 1
            << setw(20) << Ürün_listesi[a]
            << setw(15) << fixed << setprecision(2) << Alış_Fiyatı[a]
            << setw(15) << fixed << setprecision(2) << KDV_dahil_satıs_fiyatı[a]
            << setw(15) << fixed << setprecision(2) << Stok_miktarı[a]
            << endl << endl;
    }


    cout << "ÜRÜNLERİNİZİN ALIŞ FİYATININ ARTTIĞI ARALIĞI BELİRTİNİZ:";
    cin >> fiyat_artış_periyodu;
    cout << "ÜRÜNLERİNİZİN ALIŞ FİYATININ ARTTIĞI ORANI BELİRTİNİZ:";
    cin >> fiyat_artış_oranı;
    fiyat_artış_oranı /= 100;

    int yillik_satislar[20] = { 0 }; // Yıllık en fazla ve en az satılan ürünleri ve bu ürünlerin değerlerini bulmamız için tanımlanan dizi değişkeni.

    for (ay = 1; ay <= 12; ay++) {  // 12 ay boyunca oluşturulan döngü

        //Belirtilen aydaki ürünlerin alış ve satış fiyatlarını listeler.
        cout << left << setw(5) << "No:"
            << setw(20) << "Ürün:"
            << setw(15) << "Alış Fiyatı:"
            << setw(15) << "Satış Fiyatı:"
            << setw(15) << "Stok Miktarı:" << endl << endl;

        for (int a = 0; a < 20; a++) {
            cout << setw(5) << a + 1
                << setw(20) << Ürün_listesi[a]
                << setw(15) << fixed << setprecision(2) << Alış_Fiyatı[a]
                << setw(15) << fixed << setprecision(2) << KDV_dahil_satıs_fiyatı[a]
                << setw(15) << fixed << setprecision(2) << Stok_miktarı[a]
                << endl << endl;
        }






        cout << ay << ".AY" << " - KAR ZARAR DURUMU" << endl;
        //Belirtilen periyoda ve belirtilen orana göre alış fiyatını ve bu alış fiyatına göre satış fiyatını günceller.
        if (ay % fiyat_artış_periyodu == 0) {
            for (int i = 0;i < 20; i++) {
                Alış_Fiyatı[i] = Alış_Fiyatı[i] + Alış_Fiyatı[i] * (fiyat_artış_oranı / 100);
                KDV_dahil_satıs_fiyatı[i] = KDV_dahil_satıs_fiyatı[i] + KDV_dahil_satıs_fiyatı[i] * (fiyat_artış_oranı / 100);
            }
        }




        int en_cok_satilan_miktar = 0;
        int en_az_satilan_miktar = INT_MAX;
        int en_cok_satilan_ürün = -1;
        int en_az_satilan_ürün = -1;

        //Diğer giderler dinamik olması açısından belirlenen aralıkta rastgele belirlenmiştir
        double elektrik = rand() % (2001) + 1000; //Elektrik faturası için 1000TL ile 3000TL arasında rastgele bir değer belirler
        double su = rand() % (201) + 100; //Su faturası için 100TL ile 300TL  arasında rastgele bir değer belirler.
        double internet = 500; //İnternet faturası
        double kira = 5000; //Kira
        double personel_gideri = 22000;//Personel maaşı ve sigortasının toplam değeri
        double diğer_giderler = elektrik + su + internet + kira + personel_gideri;

        double aylık_gelir;
        double aylık_maliyet;

        //Her ürün için aylık stok ve kar-zarar hesaplama döngüsü.
        for (int i = 0; i < 20; i++) {
            // Satış miktarını %60 ile %80 arasında belirler.
            double oran = 0.60 + (rand() % 21) / 100.0;
            int satış_miktarı = Stok_miktarı[i] * oran;
            yillik_satislar[i] += satış_miktarı;
            Stok_miktarı[i] -= satış_miktarı;


            //Belirtilen ay için maaliyet ve gelir hesaplar.
            aylık_gelir = satış_miktarı * KDV_dahil_satıs_fiyatı[i];
            aylık_maliyet = satış_miktarı * Alış_Fiyatı[i] + diğer_giderler;

            toplam_gelir += aylık_gelir;
            toplam_maliyet += aylık_maliyet;

            // Yeni stok miktarını belirler: 2 * kalan stok + satılan miktarın %70 - %100'ü.
            double yenileme_oranı = 0.70 + (rand() % 31) / 100.0;  //Yenileme oranını %70 ile %100 arasında tutar.
            int yeni_stok = (2 * Stok_miktarı[i] + satış_miktarı * yenileme_oranı);

            // Güncel stok miktarını yeni hesaplanan stok miktarına ayarlar.
            Stok_miktarı[i] = yeni_stok;

            //Belirtilen ay için en çok ve en az satılan ürünleri ve bu ürünlerin miktarlarını belirler. 
            if (satış_miktarı > en_cok_satilan_miktar) {
                en_cok_satilan_miktar = satış_miktarı;
                en_cok_satilan_ürün = i;
            }
            if (satış_miktarı < en_az_satilan_miktar) {
                en_az_satilan_miktar = satış_miktarı;
                en_az_satilan_ürün = i;
            }
        }

        //Belirtilen ayın kar-zarar hesabını yapar.
        double kar_zarar = aylık_gelir - aylık_maliyet;


        //Belirtilen aya ait istatistik verileri yazdırır.
        cout << "Aylık Gelir: " << fixed << setprecision(2) << aylık_gelir << " TL" << endl;
        cout << "Aylık Maliyet: " << fixed << setprecision(2) << aylık_maliyet << " TL" << endl;
        cout << "Diğer Giderler:" << fixed << setprecision(2) << diğer_giderler << "TL" << endl;
        cout << "Kar/Zarar: " << fixed << setprecision(2) << kar_zarar << " TL" << endl << endl;

        //Belirtilen ay için en çok ve en az satılan ürünleri ve bu ürünlerin miktarlarını yazdırır.
        if (en_cok_satilan_ürün != 0) {
            cout << "Bu Ay En Çok Satılan Ürün:" << Ürün_listesi[en_cok_satilan_ürün] << "(" << en_cok_satilan_miktar << " Adet)" << endl;

        }
        if (en_az_satilan_ürün != -1) {
            cout << "Bu Ay En Az Satılan Ürün:" << Ürün_listesi[en_az_satilan_ürün] << "(" << en_az_satilan_miktar << " Adet)" << endl;

        }

        cout << "----------------------------------------------------------" << endl;


        //Yıllık en çok ve en az satılan ürünleri ve bu ürünlerin miktarlarını belirler.
        for (int i = 0; i < 20; i++) {
            if (yillik_satislar[i] > yillik_en_cok_satilan) {
                yillik_en_cok_satilan = yillik_satislar[i];
                yillik_en_cok_urun = i;
            }
            if (yillik_satislar[i] < yillik_en_az_satilan) {
                yillik_en_az_satilan = yillik_satislar[i];
                yillik_en_az_urun = i;
            }
        }

        cout << "----------------------------------------------------------" << endl;



    }

    //Yıllık raporu yazdırır.
    cout << "YILLIK RAPOR:" << endl;
    cout << "En Çok Satılan Ürün: " << Ürün_listesi[yillik_en_cok_urun] << " (" << yillik_en_cok_satilan << " Adet)" << endl;
    cout << "En Az Satılan Ürün: " << Ürün_listesi[yillik_en_az_urun] << " (" << yillik_en_az_satilan << " Adet)" << endl;
    cout << "Toplam Gelir:" << toplam_gelir << endl;
    cout << "Toplam Maaliyet:" << toplam_maliyet << endl;
    cout << "Toplam Kar-Zarar:" << toplam_gelir - toplam_maliyet << endl;



    return 0;



}


























