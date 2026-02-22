# 🛒 Market Stok ve Kar/Zarar Simülasyonu

Bu proje, Sakarya Üniversitesi Bilgisayar Mühendisliği **Programlamaya Giriş** dersi Güz Dönemi 1. Ödevi kapsamında geliştirilmiş bir C++ konsol uygulamasıdır. 

Uygulama, 20 farklı ürünün bulunduğu bir ticarethanenin 12 aylık stok durumunu, aylık satışlarını, dinamik giderlerini ve yıl sonundaki toplam kar/zarar durumunu simüle eder.

## 🌟 Projenin Özellikleri

* **Dinamik Fiyatlandırma:** Ürünlerin satış fiyatları, alış fiyatı üzerine rastgele bir kar marjı (%50-%70 arası) ve sabit %8 KDV eklenerek otomatik oluşturulur.
* **Enflasyon / Fiyat Artış Simülasyonu:** Kullanıcıdan alınan "Fiyat artış periyodu" ve "Fiyat artış oranına" göre ürünlerin alış ve satış fiyatları aydan aya güncellenir.
* **Aylık Satış ve Stok Yönetimi:** Her ay stokların rastgele bir kısmı (%60-%80 arası) satılır ve kalan stoklara göre yeni aydaki stok miktarı dinamik formüllerle yenilenir.
* **Dinamik Gider Hesaplama:** Sabit giderlerin (Kira, Personel) yanı sıra her ay değişen rastgele faturalar (Elektrik, Su) hesaplamaya dahil edilir.
* **İstatistik ve Raporlama:** * Her ayın gelir, gider ve kar/zarar tablosu.
  * Aylık bazda en çok ve en az satılan ürünler.
  * 12. ayın sonunda **Yıllık Rapor** (Yılın en çok/en az satılan ürünü ve toplam finansal tablo).

## 💻 Kullanılan Teknolojiler

* **Dil:** C++
* **Kullanılan Kütüphaneler:** * `<iostream>`, `<string>`, `<clocale>` (Temel G/Ç ve metin işlemleri)
  * `<stdlib.h>` (Rastgele sayı üretimi için `rand()`)
  * `<iomanip>` (Konsol çıktılarının düzenli hizalanması için)
  * `<climits>` (Maksimum/Minimum limit kontrolleri için)

## 🚀 Kurulum ve Çalıştırma

Projeyi yerel bilgisayarınızda çalıştırmak için:

1. Projeyi bilgisayarınıza klonlayın:
   ```bash
   git clone [https://github.com/kullanici-adiniz/proje-repo-adi.git](https://github.com/kullanici-adiniz/proje-repo-adi.git)
