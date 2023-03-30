/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…...: PROJE ODEVI
**				ÖĞRENCİ ADI...............: MERT ESER MERAL
**				ÖĞRENCİ NUMARASI.: G211210047
**				DERS GRUBU…………: IKINCI OGRETIM A GRUBU
****************************************************************************/


#include <windows.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    int secim, urunSecim, musteriSecim, siparisSecim, teminSuresi, urunKodu, urunKodu2, fiyat, ozelFiyat, kdv, stokAdedi, firmaNo, firmaTel;
    int adet, tutar, oztutar, siparisNo;
    string urunismi, ureticiIsmi, firmaAdi, firmaSorumlu, adres, musKategori,siparisTarih, uretimTarihi;
    char cevap = 'y';


    do {//tum islemleri barindiran do blogu.

        cout << "Lutfen yapmak istediginiz islemi seciniz. " << endl;
        cout << "1- Urun islemleri" << endl;
        cout << "2- Musteri islemleri" << endl;
        cout << "3- Siparis islemleri" << endl;
        cout << "4- Programdan cikis" << endl;
        cin >> secim;
        if (secim == 1) {//urun islemleri yapan kisim.
            cout << "1- Urun ekleme" << endl;
            cout << "2- Urun arama" << endl;
            cout << "3- Urun listeleme" << endl;
            cout << "4- Urun duzeltme" << endl;
            cout << "5- Urun silme" << endl;
            cin >> urunSecim;
            if (urunSecim == 1) {//urun ekleyen kisim.
                ofstream dosyaYaz("urun.txt", ios::app);

                cout << "Urun kodu: ";
                cin >> urunKodu;
                cout << "Urun ismi: ";
                cin >> urunismi;
                cout << "Uretici ismi: ";
                cin >> ureticiIsmi;
                cout << "Temin Suresi: ";
                cin >> teminSuresi;
                cout << "Uretim Tarihi: ";
                cin >> uretimTarihi;
                cout << "Fiyati: ";
                cin >> fiyat;
                cout << "Ozel Fiyat: ";
                cin >> ozelFiyat;
                cout << "KDV orani: ";
                cin >> kdv;
                cout << "Stok adedi: ";
                cin >> stokAdedi;
                dosyaYaz << urunKodu << "  " << urunismi << "  " << ureticiIsmi << "  " << teminSuresi << "  " << uretimTarihi << "  " << fiyat << "  " << ozelFiyat << "  " << kdv << "  " << stokAdedi << "\n";
                dosyaYaz.close();
                cout << "urun basariyla eklendi" << endl;
            }
            if (urunSecim == 2) {//urun arama kismi.
                int kod;
                ifstream dosyaOku("urun.txt");
                cout << "Lutfen aramak istediginiz urunun kodunu giriniz." << endl;
                cin >> kod;
                while (!dosyaOku.eof()) {//urun dosyasini sonuna kadar okuyan dongu.
                    dosyaOku >> urunKodu >> urunismi >> ureticiIsmi >> teminSuresi >> uretimTarihi >> fiyat >> ozelFiyat >> kdv >> stokAdedi;
                    if (kod == urunKodu) {//girilen kod ile urun dosyasinda kayitli urunun urun kodu ayni oldugunda istenilen urun bilgilerini ekrana yazdiran if blogu.
                        cout << "Aradiginiz Urun: " << endl;
                        cout << "Urun Kodu: " << urunKodu << endl;
                        cout << "Urun Ismi: " << urunismi << endl;
                        cout << "Uretici Ismi: " << ureticiIsmi << endl;
                        cout << "Temin suresi: " << teminSuresi << endl;
                        cout << "Uretim tarihi: " << uretimTarihi << endl;
                        cout << "Fiyati: " << fiyat << endl;
                        cout << "Ozel fiyat: " << ozelFiyat << endl;
                        cout << "KDV orani: " << kdv << endl;
                        cout << "Stok adedi: " << stokAdedi << endl;
                        break;
                    }

                }
                dosyaOku.close();



            }
            if (urunSecim == 3) {//urun dosyasinda kayitli tum urunlerin bilgilerini ekrana yazdiran if blogu.
                ifstream dosyaOku("urun.txt");


                while (dosyaOku >> urunKodu >> urunismi >> ureticiIsmi >> teminSuresi >> uretimTarihi >> fiyat >> ozelFiyat >> kdv >> stokAdedi) {//urun dosyasini okuyup tum urun bilgilerini ekrana yazdiran while dongusu.


                    cout << "Aradiginiz Urun: " << endl;
                    cout << "Urun Kodu: " << urunKodu << endl;
                    cout << "Urun Ismi: " << urunismi << endl;
                    cout << "Uretici Ismi: " << ureticiIsmi << endl;
                    cout << "Temin suresi: " << teminSuresi << endl;
                    cout << "Uretim tarihi: " << uretimTarihi << endl;
                    cout << "Fiyati: " << fiyat << endl;
                    cout << "Ozel fiyat: " << ozelFiyat << endl;
                    cout << "KDV orani: " << kdv << endl;
                    cout << "Stok adedi: " << stokAdedi << endl;

                }
                dosyaOku.close();


            }
            if (urunSecim == 4) {//istenilen urunun bilgilerini duzelten if blogu.
                int duzelt;
                ifstream dosyaOku("urun.txt");
                ofstream dosyaDuzelt("urun.tmp", ios::app);//guncel bilgileri tuttugumuz gecici urun dosyasi.
                cout << "Duzeltmek istediginiz urunun kodunu giriniz." << endl;
                cin >> duzelt;
                while (dosyaOku >> urunKodu >> urunismi >> ureticiIsmi >> teminSuresi >> uretimTarihi >> fiyat >> ozelFiyat >> kdv >> stokAdedi) {//urun dosyasini okumamizi saglayan while dongusu.
                    
                    if (duzelt == urunKodu) {//duzeltilmek istenilen urunun kodu kullanicidan alindi. Girilen kod urun dosyasindaki urun koduna esit olursa girilen ve urun bilgilerinin duzeltilmesini saglayan if blogu.
                        cout << "Duzeltmek Istediginiz Urun: " << endl;
                        cout << "Urun Kodu: " << urunKodu << endl;
                        cout << "Urun Ismi: " << urunismi << endl;
                        cout << "Uretici Ismi: " << ureticiIsmi << endl;
                        cout << "Temin suresi: " << teminSuresi << endl;
                        cout << "Uretim tarihi: " << uretimTarihi << endl;
                        cout << "Fiyati: " << fiyat << endl;
                        cout << "Ozel fiyat: " << ozelFiyat << endl;
                        cout << "KDV orani: " << kdv << endl;
                        cout << "Stok adedi: " << stokAdedi << endl;
                        cout << endl;
                        cout << "Lutfen guncel bilgileri giriniz." << endl;
                        cout << "Urun kodu: ";
                        cin >> urunKodu;
                        cout << "Urun ismi: ";
                        cin >> urunismi;
                        cout << "Uretici ismi: ";
                        cin >> ureticiIsmi;
                        cout << "Temin Suresi: ";
                        cin >> teminSuresi;
                        cout << "Uretim Tarihi: ";
                        cin >> uretimTarihi;
                        cout << "Fiyati: ";
                        cin >> fiyat;
                        cout << "Ozel Fiyat: ";
                        cin >> ozelFiyat;
                        cout << "KDV orani: ";
                        cin >> kdv;
                        cout << "Stok adedi: ";
                        cin >> stokAdedi;

                        dosyaDuzelt << urunKodu << "  " << urunismi << "  " << ureticiIsmi << "  " << teminSuresi << "  " << uretimTarihi << "  " << fiyat << "  " << ozelFiyat << "  " << kdv << "  " << stokAdedi << endl;
                        //duzeltilen urun bilgileri gecici urun dosyasina yaziliyor.
                        


                    }
                    else {
                        dosyaDuzelt << urunKodu << "  " << urunismi << "  " << ureticiIsmi << "  " << teminSuresi << "  " << uretimTarihi << "  " << fiyat << "  " << ozelFiyat << "  " << kdv << "  " << stokAdedi << endl;
                        //duzeltilmeyen diger bilgiler else bloguna girip gecici urun dosyasina yaziliyor.
                    }




                }
                cout << "urun bilgileri basariyla guncellendi." << endl;
                dosyaDuzelt.close();
                dosyaOku.close();
                remove("urun.txt");
                rename("urun.tmp", "urun.txt");
                //yukarida remove fonksiyonu ile guncel olmayan urun dosyasi silindi. 
                //Guncel bilgilerin tutuldugu gecici urun dosyasi rename fonksiyonu ile isim degistirip urun.txt yerine gecmis oldu. 







            }
            
            if (urunSecim == 5) {//urun silme kismi
                int sil;
                cout << "Lutfen silmek istediginiz urunun kodunu giriniz." << endl;
                cin >> sil;
                ofstream dosyaYaz("urun.tmp", ios::app);//guncel urun bilgileri gecici urun dosyasi olusturularak tutuldu.
                ifstream dosyaOku("urun.txt");
                while (dosyaOku >> urunKodu >> urunismi >> ureticiIsmi >> teminSuresi >> uretimTarihi >> fiyat >> ozelFiyat >> kdv >> stokAdedi) {
                    

                    if (sil == urunKodu) {//silinen urun bilgilerini ekrana yazdiran if blogu.
                        cout << "Silinen Urun Bilgileri: " << endl;
                        cout << "Urun Kodu: " << urunKodu << endl;
                        cout << "Urun Ismi: " << urunismi << endl;
                        cout << "Uretici Ismi: " << ureticiIsmi << endl;
                        cout << "Temin suresi: " << teminSuresi << endl;
                        cout << "Uretim tarihi: " << uretimTarihi << endl;
                        cout << "Fiyati: " << fiyat << endl;
                        cout << "Ozel fiyat: " << ozelFiyat << endl;
                        cout << "KDV orani: " << kdv << endl;
                        cout << "Stok adedi: " << stokAdedi << endl;
                        
                    }
                    else if (urunKodu == 0) {
                        break;
                    }

                    else {//silinmeyecek diger bilgileri gecici urun dosyasina yazan else blogu.

                        dosyaYaz << urunKodu << "  " << urunismi << "  " << ureticiIsmi << "  " << teminSuresi << "  " << uretimTarihi << "  " << fiyat << "  " << ozelFiyat << "  " << kdv << "  " << stokAdedi << "\n";
                        urunKodu = 0;
                    }





                }
                dosyaYaz.close();
                dosyaOku.close();
                remove("urun.txt");
                rename("urun.tmp", "urun.txt");
                //guncel olmayan urun.txt dosyasi silinip guncel olan gecici urun.tmp dosyasi isim degistirerek urun.txt yerine gecti.





            }


            cout << "Baska bir islem yapmak ister misiniz?(y/n)" << endl;
            cin >> cevap;

        }
        if (secim == 2) {//musteri islemlerinin yapildigi kisim.
            cout << "1- Musteri ekle" << endl;
            cout << "2- Musteri arama" << endl;
            cout << "3- Musteri duzeltme" << endl;
            cout << "4- Musteri silme" << endl;
            cin >> musteriSecim;

            if (musteriSecim == 1) {//musteri ekleyen if blogu.
                ofstream dosyaYaz("cari.txt", ios::app);

                cout << "Firma no: ";
                cin >> firmaNo;
                cout << "Firma adi: ";
                cin >> firmaAdi;
                cout << "Firma tel: ";
                cin >> firmaTel;
                cout << "Firma sorumlusu: ";
                cin >> firmaSorumlu;
                cout << "Musteri kategorisi:(genel/ozel) ";
                cin >> musKategori;
                cout << "Adres: ";
                cin >> adres;

                dosyaYaz << firmaNo << "  " << firmaAdi << "  " << firmaTel << "  " << firmaSorumlu << "  " << musKategori << "  " << adres << "\n";
                dosyaYaz.close();
                cout << "Musteri basariyla eklendi." << endl;



            }
            if (musteriSecim == 2) {//Musteri arama kismi.
                int kod;
                ifstream dosyaOku("cari.txt");
                cout << "Lutfen aramak istediginiz musterinin firma no'sunu giriniz." << endl;
                cin >> kod;
                while (!dosyaOku.eof()) {//musteri dosyasinin sonuna kadar devam eden dongu.
                    dosyaOku >> firmaNo >> firmaAdi >> firmaTel >> firmaSorumlu >> musKategori >> adres;
                    if (kod == firmaNo) {//istenilen musteri bilgilerini ekrana yazdiran if blogu.
                        cout << "Aradiginiz Musteri: " << endl;
                        cout << "Firma no: " << firmaNo << endl;
                        cout << "Firma adi: " << firmaAdi << endl;
                        cout << "Firma tel: " << firmaTel << endl;
                        cout << "Firma sorumlusu: " << firmaSorumlu << endl;
                        cout << "Musteri kategorisi: " << musKategori << endl;
                        cout << "Adresi: " << adres << endl;

                        break;
                    }

                }
                dosyaOku.close();
            }
            if (musteriSecim == 3) {//istenilen musterinin bilgilerinin duzeltildigi kisim.
                int duzelt;
                ifstream dosyaOku("cari.txt");
                ofstream dosyaDuzelt("cari.tmp", ios::app);//guncel musteri bilgilerini tutacak gecici musteri dosyasi.
                cout << "Duzeltmek istediginiz musterinin firma no'sunu giriniz." << endl;
                cin >> duzelt;
                while (dosyaOku >> firmaNo >> firmaAdi >> firmaTel >> firmaSorumlu >> musKategori >> adres) {//musteri dosyasinin sonuna kadar donen dongu.
                    
                    if (duzelt == firmaNo) {//istenilen musterinin bilgilerinin duzeltildigi if blogu.
                        cout << "Duzeltmek Istediginiz Musteri Bilgileri: " << endl;
                        cout << "Firma no: " << firmaNo << endl;
                        cout << "Firma adi: " << firmaAdi << endl;
                        cout << "Firma tel: " << firmaTel << endl;
                        cout << "Firma sorumlusu: " << firmaSorumlu << endl;
                        cout << "Musteri kategorisi: " << musKategori << endl;
                        cout << "Adresi: " << adres << endl;

                        cout << "Lutfen guncel bilgileri giriniz." << endl;
                        cout << "Firma no: ";
                        cin >> firmaNo;
                        cout << "Firma adi: ";
                        cin >> firmaAdi;
                        cout << "Firma tel: ";
                        cin >> firmaTel;
                        cout << "Firma sorumlusu: ";
                        cin >> firmaSorumlu;
                        cout << "Musteri kategorisi:(genel/ozel) ";
                        cin >> musKategori;
                        cout << "Adres: ";
                        cin >> adres;

                        dosyaDuzelt << firmaNo << "  " << firmaAdi << "  " << firmaTel << "  " << firmaSorumlu << "  " << musKategori << "  " << adres << "\n";

                        


                    }
                    else {
                        dosyaDuzelt << firmaNo << "  " << firmaAdi << "  " << firmaTel << "  " << firmaSorumlu << "  " << musKategori << "  " << adres << "\n";

                    }




                }
                dosyaDuzelt.close();
                dosyaOku.close();
                remove("cari.txt");//guncel olmayan cari.txt dosyasi silindi.
                rename("cari.tmp", "cari.txt");
                //yukarida guncel bilgilerin girildigi gecici cari.tmp dosyasi isim degistirip cari.txt yerine gecti.

            }
            if (musteriSecim == 4) {//musteri silme kismi.
                int sil;
                cout << "Lutfen silmek istediginiz musterinin firma no'sunu giriniz." << endl;
                cin >> sil;
                ofstream dosyaYaz("cari.tmp", ios::app);
                ifstream dosyaOku("cari.txt");
                while (dosyaOku >> firmaNo >> firmaAdi >> firmaTel >> firmaSorumlu >> musKategori >> adres) {
                    

                    if (sil == firmaNo) {//silinen musteri bilgilerini ekrana yazdiran if blogu.
                        cout << "Silinen Musteri Bilgileri: " << endl;
                        cout << "Firma no: " << firmaNo << endl;
                        cout << "Firma adi: " << firmaAdi << endl;
                        cout << "Firma tel: " << firmaTel << endl;
                        cout << "Firma sorumlusu: " << firmaSorumlu << endl;
                        cout << "Musteri kategorisi: " << musKategori << endl;
                        cout << "Adresi: " << adres << endl;
                        break;
                    }
                    else if (firmaNo == 0) {
                        break;
                    }

                    else {
                        //silinmeyen bilgilerin gecici musteri dosyasina yazildigi kisim.
                        dosyaYaz << firmaNo << "  " << firmaAdi << "  " << firmaTel << "  " << firmaSorumlu << "  " << musKategori << "  " << adres << "\n";
                        firmaNo = 0;
                    }





                }

                dosyaYaz.close();
                dosyaOku.close();
                remove("cari.txt");
                rename("cari.tmp", "cari.txt");
                //guncel olmayan cari.txt dosyasi silinip guncel bilgilerin tutuldugu cari.tmp dosyasi isim degistirip cari.txt dosyasi haline geldi.

            }
            cout << "Baska bir islem yapmak ister misiniz?(y/n)" << endl;
            cin >> cevap;

        }
        if (secim == 3) {//siparis islemlerinin yapildigi kisim. 
            cout << "1- Siparis olustur" << endl;
            cout << "2- Siparis arama" << endl;
            cout << "3- Siparis silme" << endl;
            cout << "4- Siparis duzeltme" << endl;
            cout << "5- Siparis raporlama" << endl;
            cin >> siparisSecim;

            if (siparisSecim == 1) {//siparis eklenmesini saglayan if blogu.
                ifstream dosyaokuMusteri("cari.txt");
                ifstream dosyaokuUrun("urun.txt");
                ofstream dosyaYaz("siparis.txt", ios::app);
                ofstream dosyaekle("list.txt", ios::app);
                int firmaNum = 0;

                int gir = 0;
                adet = tutar = oztutar = 0;
                cout << "Firma no: ";
                cin >> firmaNum;
                cout << "Siparis no: ";
                cin >> siparisNo;
                cout << "Siparis tarihi: ";
                cin >> siparisTarih;
                cout << "Siparis edilecek urun kodu: ";
                cin >> gir;
                cout << "urun adedi: ";
                cin >> adet;
                cout << "Siparis tutari: ";
                while (!dosyaokuMusteri.eof()) {
                    dosyaokuMusteri >> firmaNo >> firmaAdi >> firmaTel >> firmaSorumlu >> musKategori >> adres;
                    if (firmaNo == firmaNum) {
                        while (dosyaokuUrun >> urunKodu >> urunismi >> ureticiIsmi >> teminSuresi >> uretimTarihi >> fiyat >> ozelFiyat >> kdv >> stokAdedi) {//urun dosyasinin sonuna kadar donen dongu.

                            if (urunKodu == gir) {
                                //buradaki if else yapisi ile musterinin ozel veya genel olmasina gore fiyat belirleniyor ve ekrana yazdiriliyor.
                                if (musKategori == "genel")
                                {
                                    tutar = fiyat * adet;
                                    cout << tutar << endl;
                                }
                                else {
                                    oztutar = ozelFiyat * adet;
                                    cout << oztutar << endl;
                                }
                                cout << "Siparisi alan: ";
                                cout << firmaAdi << endl;

                                dosyaekle << urunKodu << "  " << adet << endl;
                                dosyaekle.close();

                                dosyaYaz << firmaNo << "  " << siparisNo << "  " << siparisTarih << "  " << urunKodu << "  " << adet << "  " << tutar << "  " << oztutar << "  " << firmaAdi << "  " << musKategori << "\n";
                                dosyaYaz.close();


                                firmaNo = 0;
                                cout << "Siparis basariyla eklendi." << endl;

                            }
                        }
                    }

                }
                dosyaokuMusteri.close();
                dosyaokuUrun.close();

            }
            if (siparisSecim == 2) {//istenilen siparisin arandigi if blogu.
                int kod;
                

                ifstream dosyaOku("siparis.txt");
                ifstream dosyaokuUrun("urun.txt");
                cout << "Lutfen aramak istediginiz siparisin siparis no'sunu giriniz." << endl;
                cin >> kod;
                while (dosyaOku >> firmaNo >> siparisNo >> siparisTarih >> urunKodu2 >> adet >> tutar >> oztutar >> firmaAdi >> musKategori) {//siparis dosyasinin sonuna kadar donen dongu.

                    while (kod == siparisNo) {
                        dosyaokuUrun >> urunKodu >> urunismi >> ureticiIsmi >> teminSuresi >> uretimTarihi >> fiyat >> ozelFiyat >> kdv >> stokAdedi;
                        if (urunKodu == urunKodu2) {//istenilen siparis bilgilerinin ekrana yazdirildigi if blogu.

                            cout << "Aradiginiz Siparis Bilgileri: " << endl;
                            cout << "Firma no: " << firmaNo << endl;
                            cout << "Urun adi: " << urunismi << endl;
                            cout << "Siparis Tarihi: " << siparisTarih << endl;
                            cout << "Urun Kodu: " << urunKodu2 << endl;
                            cout << "Urun adedi: " << adet << endl;
                            cout << "Siparis tutari: ";
                            if (musKategori == "genel")//musterinin kategorisine gore fiyat belirleyen if else blogu.
                            {

                                cout << tutar << endl;
                            }
                            else {

                                cout << oztutar << endl;
                            }
                            cout << "Firma adi: " << firmaAdi << endl;
                            dosyaOku.close();
                            dosyaokuUrun.close();
                            break;
                        }

                    }

                }



            }
            if (siparisSecim == 3) {//istenilen siparisin silindigi if blogu.
                int sil;
                cout << "Lutfen silmek istediginiz siparisin siparis no'sunu giriniz." << endl;
                cin >> sil;
                ofstream listYaz("list.tmp", ios::app);
                ofstream dosyaYaz("siparis.tmp", ios::app);
                ifstream listOku("list.txt");
                ifstream dosyaOku("siparis.txt");
                while (dosyaOku >> firmaNo >> siparisNo >> siparisTarih >> urunKodu >> adet >> tutar >> oztutar >> firmaAdi >> musKategori&& listOku >> urunKodu >> adet) {
                    //siparis listesi dosyasinin ve siparis dosyasinin sonuna kadar donen dongu.
                    
                    
                    if (sil == siparisNo) {//silinen siparis bilgilerini ekrana yazdiran if blogu.
                        cout << "Silinen Siparis Bilgileri: " << endl;
                        cout << "Firma no: " << firmaNo << endl;
                        cout << "Siparis Tarihi: " << siparisTarih << endl;
                        cout << "Urun Kodu: " << urunKodu << endl;
                        cout << "Urun adedi: " << adet << endl;
                        cout << "Siparis tutari: ";
                        if (musKategori == "genel")
                        {

                            cout << tutar << endl;
                        }
                        else {

                            cout << oztutar << endl;
                        }
                        cout << "Firma adi: " << firmaAdi << endl;
                        
                    }
                    else if (siparisNo == 0) {
                        break;
                    }

                    else {//guncel bilgilerin girildigi else blogu.
                        listYaz<< urunKodu << "  " << adet << endl;
                        dosyaYaz << firmaNo << "  " << siparisNo << "  " << siparisTarih << "  " << urunKodu << "  " << adet << "  " << tutar << "  " << oztutar << "  " << firmaAdi << "  " << musKategori << "\n";
                        siparisNo = 0;
                    }

                }
                dosyaYaz.close();
                dosyaOku.close();
                listOku.close();
                listYaz.close();
                remove("list.txt");
                remove("siparis.txt");
                rename("siparis.tmp", "siparis.txt");
                rename("list.tmp", "list.txt");
                //guncel bilgiler gecici dosyalara yazildi. Sonrasinda eski dosyalar silinip guncel olan gecici dosyalarin ismi degistirilerek siparis ve siparis listesi dosyalari guncellendi.








            }
            if (siparisSecim == 4) {//istenilen siparisin duzeltildigi kisim.
                int duzelt;
                ifstream dosyaokuMusteri("cari.txt");
                ifstream dosyaokuUrun("urun.txt");
                ifstream dosyaOku("siparis.txt");
                ifstream listOku("list.txt");
                ofstream dosyaDuzelt("siparis.tmp", ios::app);
                ofstream dosyaekle("list.tmp", ios::app);
                cout << "Duzeltmek istediginiz siparisin no'sunu giriniz." << endl;
                cin >> duzelt;
                while (dosyaOku >> firmaNo >> siparisNo >> siparisTarih >> urunKodu >> adet >> tutar >> oztutar >> firmaAdi >> musKategori&& listOku >> urunKodu >> adet) {
                    //siparis listesi dosyasinin ve siparis dosyasinin sonuna kadar donen dongu.
                    
                    if (duzelt == siparisNo) {//duzeltilecek siparis bilgilerinin ekrana yazdirildigi kisim.
                        cout << "Duzeltmek Istediginiz Siparis Bilgileri: " << endl;
                        cout << "Firma no: " << firmaNo << endl;
                        cout << "Siparis no: " << siparisNo << endl;
                        cout << "Siparis Tarihi: " << siparisTarih << endl;
                        cout << "Urun Kodu: " << urunKodu << endl;
                        cout << "Urun adedi: " << adet << endl;
                        cout << "Siparis tutari: ";
                        if (musKategori == "genel")
                        {

                            cout << tutar << endl;
                        }
                        else {

                            cout << oztutar << endl;
                        }
                        cout << "Firma adi: " << firmaAdi << endl;
                        cout << endl;

                        cout << "Lutfen guncel bilgileri giriniz." << endl;


                        int firmaNum = 0;
                        int gir = 0;
                        adet = tutar = oztutar = 0;
                        cout << "Firma no: ";
                        cin >> firmaNum;
                        cout << "Siparis no: ";
                        cin >> siparisNo;
                        cout << "Siparis tarihi: ";
                        cin >> siparisTarih;
                        cout << "Siparis edilecek urun kodu: ";
                        cin >> gir;
                        cout << "urun adedi: ";
                        cin >> adet;
                        cout << "Siparis tutari: ";
                        while (!dosyaokuMusteri.eof()) {//musteri dosyasinin sonuna kadar donen dongu.
                            dosyaokuMusteri >> firmaNo >> firmaAdi >> firmaTel >> firmaSorumlu >> musKategori >> adres;
                            if (firmaNo == firmaNum) {
                                while (dosyaokuUrun >> urunKodu >> urunismi >> ureticiIsmi >> teminSuresi >> uretimTarihi >> fiyat >> ozelFiyat >> kdv >> stokAdedi) {

                                    if (urunKodu == gir) {

                                        if (musKategori == "genel")
                                        {
                                            tutar = fiyat * adet;
                                            cout << tutar << endl;
                                        }
                                        else {
                                            oztutar = ozelFiyat * adet;
                                            cout << oztutar << endl;
                                        }
                                        cout << "Siparisi alan: ";
                                        cout << firmaAdi << endl;

                                        dosyaDuzelt << firmaNo << "  " << siparisNo << "  " << siparisTarih << "  " << urunKodu << "  " << adet << "  " << tutar << "  " << oztutar << "  " << firmaAdi << "  " << musKategori << "\n";
                                        dosyaekle << urunKodu << "  " << adet << endl;
                                        //guncellenen bilgiler gecici dosyalara yazildi.






                                    }
                                }
                            }

                        }
                        

                       


                       
                    }
                    
                    else {
                        dosyaDuzelt << firmaNo << "  " << siparisNo << "  " << siparisTarih << "  " << urunKodu << "  " << adet << "  " << tutar << "  " << oztutar << "  " << firmaAdi << "  " << musKategori << "\n";
                        dosyaekle << urunKodu << "  " << adet << endl;
                        //degistirilmeyen bilgiler gecici dosyalara yazdirildi.
                    }




                }
                cout << "siparis basariyla duzeltildi." << endl;
                dosyaokuMusteri.close();
                dosyaokuUrun.close();
                dosyaDuzelt.close();
                dosyaOku.close();
                listOku.close();
                dosyaekle.close();
                remove("siparis.txt");
                remove("list.txt");
                rename("siparis.tmp", "siparis.txt");
                rename("list.tmp", "list.txt");
                //guncel olmayan dosyalar silinip guncel olan gecici dosyalar isim degistirip siparis.txt ve list.txt olarak guncellendi.




            }
            if (siparisSecim == 5) {//tum siparislerin raporlandigi siparis raporlama kismi.
                ifstream dosyaOku("siparis.txt");

                cout << "Alinan Tum Siparisler: " << endl;
                cout << endl;
                while (dosyaOku >> firmaNo >> siparisNo >> siparisTarih >> urunKodu >> adet >> tutar >> oztutar >> firmaAdi >> musKategori) {
                    //tum siparis dosyasini okuyan ve ekrana yazdiran while dongusu.
                    
                    cout << "Siparis Bilgileri: " << endl;
                    cout << "Firma no: " << firmaNo << endl;
                    cout << "Siparis no: " << siparisNo << endl;
                    cout << "Siparis Tarihi: " << siparisTarih << endl;
                    cout << "Urun Kodu: " << urunKodu << endl;
                    cout << "Urun adedi: " << adet << endl;
                    cout << "Siparis tutari: ";
                    if (musKategori == "genel")
                    {

                        cout << tutar << endl;
                    }
                    else {

                        cout << oztutar << endl;
                    }
                    cout << "Firma adi: " << firmaAdi << endl;
                    cout << endl;

                }
                dosyaOku.close();



            }
            cout << "Baska bir islem yapmak ister misiniz?(y/n)" << endl;
            cin >> cevap;







        }
        if (secim == 4) {//programdan cikan kisim.
            exit(1);
        }
    } while (cevap != 'n');//kullanicinin girdigi cevap eger n ise programdan cikan while dongusu.
}