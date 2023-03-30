//Bilgisayar mağazası otomasyonu

Bu projede ilk başta do while döngüsü kullandım ve yapılan bütün 
işlemler do içinde oldu. While döngüsünde ise kullanıcın isteğine 
göre programdan çıkış yapılmasını sağladım. Hazırladığım program 
bir bilgisayar firmasının ürünlerine , müşteri bilgilerine ve sipariş 
bilgilerine erişebildiği ve ekleme, silme, raporlama, listeleme, arama, 
düzeltme gibi işlemleri gerçekleştirebilen bir programdır. 
İlk olarak ürün işlemleri kısmında ürün ekleme, ürün silme, ürün 
arama, tüm ürünleri listeleme, ürün bilgisi düzeltme işlemleri 
yapılmaktadır. Müşteri işlemleri kısmında müşteri ekleme,müşteri 
silme, müşteri bilgilerini düzeltme ve müşteri arama yapılmaktadır. 
Sipariş kısmında da sipariş oluşturma, sipariş arama, sipariş bilgilerini 
düzeltme, tüm siparişleri raporlama ve sipariş silme yapılmaktadır. 
Ürün bilgilerini urun.txt dosyasında, müşteri bilgilerini cari.txt 
dosyasında, sipariş bilgilerini siparis.txt ve sipariş listesini list.txt 
dosyasında tuttum. Kullanıcının girmek istediği menülere if ile 
girmesini sağladım. Silme ve düzeltme işlemleri yaparken geçici 
dosya oluşturup if else ile güncel bilgileri burada tuttum. Ardından 
eski dosyayı silip geçici dosyanın adıyla değiştirdim. Böylece 
dosyaları güncellemiş oldum.Bunları rename ve remove fonksiyonları 
ile yaptım. Arama kısmında ifstream fonksiyonu ile istenilen bilginin 
olduğu dosyayı okuttum ve if yapısı ile istenilen bilgiyi bulup ekrana 
yazdırdım. Listeleme ve raporlama kısmında dosyaları ifstream ile 
okuyup while döngüsüne sokarak ekrana yazdırdım. Ayrıca 
programda ofstream fonksiyonu kullanarak dosyalara bilgileri 
yazdım
