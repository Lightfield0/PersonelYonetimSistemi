# Personel Yönetim Sistemi

Bu proje, bir şirketin personel bilgilerini yönetmek için kullanılan basit bir C programıdır. Kullanıcılar, personel bilgilerini kaydetmek, güncellemek, silmek ve aramak için bu programı kullanabilirler. Tüm veriler, yerel bir dosyada saklanır.

## Özellikler

- Personel bilgilerini kaydetme ve dosyaya yazma
- Kayıtlı personel bilgilerini listeleme
- Belirli kriterlere göre personel arama
- Mevcut personel kaydını güncelleme
- Personel kaydını silme

## Nasıl Kullanılır

Programı kullanmadan önce, C dilinde yazılmış olduğundan emin olun ve C derleyicinizin olduğundan emin olun. Programı çalıştırmak için aşağıdaki adımları izleyin:

1. Kaynak kodunu klonlayın veya indirin.
2. Terminal veya komut istemcisini açın ve kaynak kodun bulunduğu dizine gidin.
3. `gcc -o personelYonetim personelYonetim.c` komutunu kullanarak programı derleyin.
4. Derlenmiş programı `./personelYonetim` komutu ile çalıştırın.

## Program Menüsü

Program başladığında, kullanıcılara aşağıdaki seçenekler sunulur:

1. Kayıt Listele
2. Kayıt Ara
3. Kayıt Ekle
4. Kayıt Sil
5. Kayıt Güncelle
6. Programdan Çıkış

Kullanıcı, istediği işlemi gerçekleştirmek için ekrandaki talimatları takip edebilir.

## Katkıda Bulunma

Bu proje, açık kaynaklıdır ve katkılara açıktır. Katkıda bulunmak istiyorsanız, lütfen aşağıdakileri yapın:

1. Projeyi forklayın.
2. Özellik dalınızı oluşturun (`git checkout -b feature/AmazingFeature`).
3. Değişikliklerinizi commit edin (`git commit -m 'Add some AmazingFeature'`).
4. Dalınızı Push edin (`git push origin feature/AmazingFeature`).
5. Bir Pull Request oluşturun.

## Lisans

Bu proje [MIT lisansı](LICENSE) altında lisanslanmıştır. Daha fazla bilgi için `LICENSE` dosyasına bakın.
