# get_next_line
get_next_line, C dilinde yazılmış bir fonksiyon olup, bir dosyadan ya da standart girdiden (STDIN) satır satır veri okumayı sağlar. Bu işlev, okuma işlemlerini kolaylaştırarak satır bazında işlem yapmaya imkan tanır.

Değişkenler, programın işleyebilmesi için belirli bir bellek alanına atanan isimlendirilmiş depolama birimleridir. Türlerine (char, int, long) göre bellek miktarını belirleriz. Ayrıca, değişkenlerin bildiriminde yaşam sürelerini ve erişim alanlarını da kontrol edebiliriz. Bu nedenle, C dilinde kod yazarken yerel, global ve statik değişkenlerin farklarını anlamak önemlidir.

## **Buffer Nedir?**

C dilinde, buffer (arabellek) bir bellek alanıdır. Genellikle, **veri okuma veya yazma işlemlerinde** kullanılır. Bir buffer, verileri geçici olarak depolamak için kullanılır ve daha sonra diğer işlemlerde kullanılmak üzere veri işlemeye yönlendirilir.

Buffer kullanımı veri işlemleri sırasında hız ve verimliliği arttırmak için kullanılır. Örneğin, bir dosyadan veri okurken, buffer kullanarak okunan veri arabellekte tutulur ve daha sonra işlem yapılacak diğer yere taşınır. Bu işlem, dosyayı sürekli olarak açık tutmak yerine, buffer kullanarak verileri tek seferde okumayı sağlar ve bu da hız ve verimliliği arttırır.

C dilinde buffer kullanmak için `malloc()` veya `calloc()` gibi fonksiyonlar kullanılabilir, veya direkt olarak isim verilmeden tanımlanabilir.

## **Read()**

C dilinde, `read()` fonksiyonu, bir dosyadan veya sistem kaynaklarından veri okumak için kullanılır. Bu fonksiyon, `unistd.h` kütüphanesinde tanımlıdır.

`read()` fonksiyonunun ilk parametresi, okunacak dosyanın file descriptor'ıdır. File descriptor, sistem tarafından atanan bir dosya için benzersiz bir tanımlayıcıdır. İkinci parametresi, okunacak verinin yer alacağı buffer'dır. Üçüncü parametresi ise okunacak verinin maksimum boyutudur.

- Okunacak boyut eger 0 ise, fonksiyon 0 dondurur.
- Eğer okuma işlemi başarılı olduysa, geri dönen değer okunan verinin gerçek boyutudur.
- Eğer okuma işlemi başarısız olduysa, fonksiyon -1 değerini döndürür.
- Eger okuma islemi basarili olduysa ve daha fazla okunacak byte kalmadiysa, fonksiyon dosyanin bittigini gostermek adina 0 dondurur.

Not: Aslinda dosya icerikleri grafiksel olarak satir satir gorunse de, arkaplan da oyle degildir. Her bir satirin sonunda /n vardir ve metin hemen pesinden devam eder. O yuzden read fonksiyonunun okurken alt satira gecme gibi bir durumu yoktur. Yani read fonksiyonu metin'i bizim gibi satir satir gormez tek satir olarak gorur fakat aralarda /n ile gorur.

## **Statik Degiskenler**

Kisaca, tuttugu degeri, baska fonksiyonlara gecse de, program bitse de saklayan degiskenlerdir.

C dilinde, statik değişkenler, programın çalışması sırasında bellekte yer ayrılarak, programın çalışma süresi boyunca saklanır. Bu değişkenlerin değerleri programın sona ermesinden sonra da kalır. Bu nedenle, bir sonraki program çalışması sırasında, statik değişkenlerin değerleri daha önceki çalışması sırasında kullanılmış değerlerdir.

Ayrıca, statik değişkenler sadece fonksiyon veya global alanda tanımlanabilir. ve global alanda tanımladığınızda programın tüm bölümlerinde erişilebilir, fonksiyon içerisinde tanımladığınızda sadece o fonksiyon içerisinde erişilebilir.

- Statik değişkenler, ilk değer ataması yapılmamışsa, varsayılan olarak 0 olarak başlatılır.
- Statik bir değişken işaretçi olarak tanımlanırsa, varsayılan olarak null pointer (0) olarak başlatılır. Yani, işaretçi statik olarak tanımlanmış bir değişkene işaret etmiyor.

Bu degiskenleri get_next_line projesinde girdi bolunmelerindeki kaybolabilecek, arada kalabilecek verileri kaybetmemek icin kullaniyoruz.

### **STATİK DEĞİŞKENLER HAFIZADA NASIL KAYDOLURLAR**

C programlama dilinde `static` değişkenler, **programın çalışma ömrü boyunca bir kez oluşturulan** ve aynı bellek adresinde saklanan değişkenlerdir. Hafızada, **"data segment"** denilen bir bölgede saklanırlar. Bu bölge genellikle iki alt kısma ayrılır:

1. **.data segment** (Başlatılmış static değişkenler): Değeri başlangıçta belirlenen (örneğin: `static int x = 5;`) değişkenler burada saklanır.
2. **.bss segment** (Başlatılmamış static değişkenler): Değeri başlangıçta belirtilmeyen (örneğin: `static int y;`) değişkenler buraya atanır ve otomatik olarak `0` ile başlatılır.

## **File Descriptor (fd) nedir?**

"file descriptor" (dosya tanımlayıcısı), dosyalara veya diğer giriş/çıkış kaynaklarına erişmek için kullanılan bir tamsayı değeridir. Dosya tanımlayıcısı, işletim sistemi tarafından oluşturulan bir işaretçi gibidir,

Dosya tanımlayıcıları, işletim sisteminde açık olan her dosya için benzersiz bir numaralandırmaya sahiptir. Örneğin, UNIX ve Linux sistemlerinde, 0, 1 ve 2 numaralı dosya tanımlayıcıları özel olarak aşağıdaki şekilde atanır:

- 0: Standart giriş (stdin) - Klavyeden okuma için kullanılır.
- 1: Standart çıkış (stdout) - Ekran yazdırma için kullanılır.
- 2: Standart hata (stderr) - Hata mesajlarını göndermek için kullanılır.

Ayrıca, 3 ve sonraki numaralar, açık olan diğer dosyalar için atanır. Bu dosya tanımlayıcıları, `open()` veya `fopen()` gibi dosya açma işlevleri kullanılarak elde edilir. Dosya tanımlayıcıları, `int` türünden değişkenlerde saklanır.

## **Fd icin open fonksiyonu nasil kullanilir?**

Fonksiyonun prototipi şu şekildedir:

```
int open(const char *path, int flags, mode_t mode);`
```

Burada, `path` parametresi açılacak dosyanın yolu ve adını içeren bir karakter dizisidir. `flags` parametresi açma modunu belirlemek için kullanılır ve hangi türde dosya erişimi yapılacağını belirtir. `mode` parametresi ise yeni bir dosya oluşturulduğunda izinlerin belirlenmesi için kullanılır (bu parametre sadece dosya oluşturulduğunda önemlidir).

`open()` işlevi, bir dosya tanımlayıcısı (file descriptor) döndürür. Dosya tanımlayıcısı, dosyaya erişim ve dosya üzerinde işlem yapmak için kullanılır. Eğer işlem başarısız olursa, -1 değeri döndürür.

---

**En Sık Kullanılan `flags` Parametreleri ve Açıklamaları:**

1. `O_RDONLY`: Dosyayı sadece okuma modunda açar. Dosyanın içeriği değiştirilemez, sadece okunabilir.
2. `O_WRONLY`: Dosyayı sadece yazma modunda açar. Dosyanın içeriği okunamaz, sadece değiştirilebilir.
3. `O_RDWR`: Dosyayı hem okuma hem de yazma modunda açar. Dosya içeriğini okuyabilir ve değiştirebilirsiniz.
4. `O_CREAT`: Eğer dosya yoksa, yeni bir dosya oluşturur. Bu bayrak, dosya açma işleminin yeni bir dosya oluşturma işlemi için kullanılacağını belirtir.
5. `O_TRUNC`: Dosya varsa, içeriğini temizler (sıfırlar). Dosyayı açarken içeriği silmek ve dosyayı boşaltmak için kullanılır.
6. `O_APPEND`: Dosya varsa, dosyanın sonuna ekler. Yani, her yazma işlemi dosyanın sonuna eklenir, varolan içeriği değiştirmez.
7. `O_EXCL`: Dosya varsa, hata döndürür. Bu bayrak, `O_CREAT` bayrağıyla birlikte kullanılır ve eğer dosya zaten varsa hata döndürür.
8. `O_TRUNC | O_CREAT`: Eğer dosya varsa içeriğini siler, eğer dosya yoksa yeni bir dosya oluşturur. Bu bayrak, dosya içeriğini sıfırlayarak mevcut dosyayı kullanmak için kullanılır.

## ssize_t nedir?

`ssize_t` türü, POSIX standartlarında tanımlanmış bir türdür ve genellikle **`<unistd.h>`** başlık dosyasında bulunur. Bu tür, negatif değer alabilen bir `size_t` türüdür ve tipik olarak `read`, `write` gibi sistem çağrılarının döndürdüğü bayt sayısını temsil eder.

Eğer kodunda bu türü kullanıyorsan, mutlaka `#include <unistd.h>` eklediğinden emin olmalısın. Bu, `ssize_t` tanımını ve `read` işlevini kullanmana olanak tanır.

## POSIX

POSIX’te bulunan iki kavram ile ne olduğunu açıklamaya açalışırsak; portable(taşınabilir) demek tamamen kaynak kodu ile ilgilidir. Kodun başka bir ortama taşındığında da çalışabilmesidir. Interface (arayüz) kelimesi ise geliştirilen kodun farklı kodlarla iletişim kurması, bir arayüz sağlayan yerdir.

POSIX 1985 yılında Richard Stallman tarafından proje olarak geliştirilmeye başlanmıştır ve 1988 yılında IEEE Std 1003.1–1988 ile resmileşmiştir ve uluslararası standart adı ISO/IEC 9945’dir. Genel olarak Linux işletim sistemleri POSIX standartlarına uymayı hedeflemektedir.

İşletim sisteminin POSIX uyumlu olması geliştiricilerin aynı kodları kullanarak farklı işletim sistemleri için uygulamalar vs. geliştirebilmesine imkan sağlamaktadır. POSIX uyumlu kod yazmanın bu avantajı ile kendinize büyük bir artı katabilirsiniz.

### POSIX'in Temel Amaçları:

1. **Taşınabilirlik**: POSIX, yazılımların birden fazla işletim sistemi üzerinde çalışabilmesini sağlamak için ortak bir arayüz sunar. Yani, POSIX uyumlu bir uygulama, POSIX uyumlu herhangi bir işletim sisteminde çalışabilir.
2. **Uyumluluk**: POSIX, UNIX ve UNIX-benzeri işletim sistemlerinde aynı işlevlerin aynı şekilde çalışmasını garanti eder. Bu, yazılım geliştiricilerin bir platformdan diğerine geçişte uyum sorunları yaşamamasını sağlar.
3. **Sistemi Kolaylaştırma**: POSIX, sistem çağrılarını ve temel işlevsellikleri tanımlar. Bu, özellikle C dili ile sistem programlaması yapan geliştiriciler için kritik önem taşır.

*Daha fazla bilgi : [https://birolemekli.medium.com/posix-portable-operating-system-interface-taşınabilir-i̇şletim-sistemi-arayüzü-fcf184f8c146](https://birolemekli.medium.com/posix-portable-operating-system-interface-ta%C5%9F%C4%B1nabilir-i%CC%87%C5%9Fletim-sistemi-aray%C3%BCz%C3%BC-fcf184f8c146)*

### POSIX İşlevleri:

POSIX, birçok farklı işlev ve özellik sunar. Bunlar, dosya işlemleri, işlem yönetimi, bellek yönetimi, zaman yönetimi, ve hata yönetimi gibi pek çok alanda sistem çağrılarını kapsar. Örnekler:

- **Dosya ve dizin yönetimi**: `open()`, `read()`, `write()`, `close()` gibi fonksiyonlar.
- **İşlem yönetimi**: `fork()`, `exec()`, `wait()`.
- **Zaman ve sinyal yönetimi**: `sleep()`, `signal()`, `setitimer()`.
- **Bellek yönetimi**: `mmap()`, `munmap()`.
- **Hata yönetimi**: `perror()`, `strerror()`.

### POSIX Standartlarının Kullanımı:

POSIX, özellikle C dilinde, sistem programlaması ve düşük seviyede yazılım geliştirme yapan kişiler için çok önemli bir kaynaktır. Örneğin, **`read`** ve **`write`** gibi işlevler POSIX standartları çerçevesinde tanımlanmıştır.

POSIX, aynı zamanda **UNIX** sistemlerinde yaygın olan komut satırı araçlarını da içerir. Bu araçlar, bir işletim sistemi üzerinde programlar arasında etkileşimi sağlamak için kullanılır.

### Sonuç:

POSIX işlevleri, genellikle **UNIX benzeri işletim sistemlerinde** bulunan düşük seviyeli sistem çağrılarıdır. Bu işlevler, taşınabilir ve uyumlu yazılımlar geliştirebilmek için standartlaştırılmıştır.

## FONKSİYONLAR VE SİSTEM ÇAĞRILARI ARASINDAKİ FARKLAR

**Sistem çağrıları** ve **fonksiyonlar** arasındaki farkları anlamak, temel olarak işletim sistemi ile kullanıcı programı arasındaki etkileşimi anlamakla ilgilidir. **`open()`**, **`read()`**, ve **`close()`** gibi POSIX işlevleri, sistem çağrılarıdır ve bu, onları geleneksel C fonksiyonlarından farklı kılar. İşte bu farkları açıklayalım:

### 1. **Sistem Çağrısı ve Fonksiyon Farkı:**

- **Fonksiyonlar (Library Functions)**: Kullanıcı tarafından yazılan ve genellikle bir yazılım kütüphanesinde tanımlanan işlevlerdir. Bu fonksiyonlar, kullanıcı programının çalışma alanı içinde çalışır ve işletim sisteminin çekirdeğiyle doğrudan etkileşime girmezler.
    - Örnek: `printf()`, `strlen()`, `malloc()`, `free()` gibi fonksiyonlar.
- **Sistem Çağrıları (System Calls)**: İşletim sisteminin çekirdeğiyle doğrudan etkileşime giren ve donanım, bellek yönetimi veya dosya sistemleri gibi düşük seviyeli işlemleri gerçekleştiren işlevlerdir. Bir sistem çağrısı, kullanıcı seviyesindeki programdan işletim sistemi çekirdeğine geçiş yapar. Bu, programın işletim sistemi kaynaklarını kullanabilmesini sağlar.
    - Örnek: `open()`, `read()`, `write()`, `close()`, `fork()` gibi POSIX işlevleri.

### 2. **Çalışma Şekli:**

- **Fonksiyonlar**: Programın belleğinde çalışır ve genellikle işletim sistemiyle ilgili düşük seviyeli işlemleri doğrudan yapmazlar. C kütüphaneleri tarafından sağlanan fonksiyonlar, genellikle daha yüksek seviyeli işlemler gerçekleştirir (örneğin, belleği yönetmek, string işlemleri yapmak).
- **Sistem Çağrıları**: Kullanıcı programından işletim sistemine yapılan geçişi gerektirir. Bir sistem çağrısı yapıldığında, işletim sistemi çekirdeği çalıştırılır ve bu çağrıdan gelen işlemi yerine getirir (dosya açma, veri okuma/yazma, işlem başlatma vb.).

### 3. **Performans ve Güvenlik:**

- **Fonksiyonlar**: Genellikle daha hızlıdır çünkü sadece kullanıcı seviyesinde çalışırlar ve çekirdek modunda çalışma gerektirmezler. Ayrıca, fonksiyonlar genellikle yalnızca uygulama mantığıyla ilgilenir, işletim sistemi seviyesinde güvenlik sorunları yaratmazlar.
- **Sistem Çağrıları**: Sistem çağrıları, çekirdek modunda çalışır, bu da ek bir güvenlik ve performans yükü anlamına gelir. Sistem çağrıları, işletim sistemi kaynaklarını doğrudan manipüle ettiği için daha fazla güvenlik denetimi gerektirir ve sistemin istikrarını sağlar.

### 4. **Kullanım Alanı:**

- **Fonksiyonlar**: Genellikle kullanıcı programlarının ihtiyaç duyduğu daha genel amaçlı işlemleri gerçekleştirir. Örneğin, veri yapılarını yönetme, string manipülasyonu, bellek ayırma gibi işlemler.
- **Sistem Çağrıları**: Genellikle daha düşük seviyeli işlemler için kullanılır, örneğin dosya işlemleri (açma, okuma, yazma), bellek yönetimi, işlem yönetimi gibi.

### 5. **Hata Yönetimi:**

- **Fonksiyonlar**: Hataları çoğunlukla kullanıcı seviyesinde yönetirler. Örneğin, bir fonksiyon hata durumunda genellikle `NULL` döner veya `errno` gibi hata kodları kullanır.
- **Sistem Çağrıları**: Hatalar genellikle sistemin çekirdek tarafından yönetilir ve kullanıcı programı sistem çağrısı sonucu dönen hata kodlarını kullanarak bu hataları kontrol eder. Örneğin, `open()` hatası **`1`** döner, `read()` hatası da **`1`** döner ve `errno` değişkeni bu hatayı daha ayrıntılı gösterir.

### Özet:

- **Fonksiyonlar**: Kullanıcı seviyesinde çalışır ve genellikle kütüphane işlevleridir. Daha yüksek seviyede ve daha kolay işlevler sunar.
- **Sistem Çağrıları**: İşletim sisteminin çekirdeğiyle doğrudan etkileşime girer ve donanım veya düşük seviyeli kaynaklarla ilgili işlemleri gerçekleştirir.

**Örnek:**

- **`open()`**, **`read()`** ve **`close()`** gibi fonksiyonlar, doğrudan işletim sisteminin dosya yönetimi işlevlerine erişim sağlar, bu nedenle bunlar sistem çağrılarıdır.

## Fd Write Komutu 0,1 ve 2 için dosya oluşturmayız, neden?

`write` fonksiyonu, işletim sisteminin bir dosya tanımlayıcısına (file descriptor, fd) yazı yazmasını sağlar. `fd` parametresi ile hangi dosyaya veya cihaza yazılacağını belirtiyoruz. Standart dosya tanımlayıcılar (`fd`) aşağıdaki şekilde işletim sistemi tarafından varsayılan olarak atanır:

1. **0**: **Standard Input (stdin)**Klavyeden veri almak için kullanılır.
2. **1**: **Standard Output (stdout)**Normal çıktıların yazıldığı yer. Varsayılan olarak terminale yazılır.
3. **2**: **Standard Error (stderr)**Hata mesajlarının yazıldığı yer. Bu da varsayılan olarak terminaldir.

Bu tanımlamalar, POSIX standartlarının bir parçasıdır ve tüm modern işletim sistemlerinde aynıdır.

### Neden Terminale Yazar?

Çünkü:

- Varsayılan olarak `stdout` terminale bağlıdır. Bu bağlantı, program başlatıldığında işletim sistemi tarafından yapılır.
- Eğer `stdout` başka bir dosyaya veya cihaza yönlendirilmemişse (`>` veya `|` ile), çıktıyı terminalde görürsünüz.

Varsayılan olarak `stdout`'un (ve diğer standart dosya tanımlayıcıların) terminale bağlı olması, **Unix felsefesinin ve POSIX standartlarının bir sonucu**dur. İşte bunun nedenleri ve bağlantının nasıl kurulduğu:

---

### **Neden `stdout` Terminale Bağlıdır?**

1. **Kullanıcı ile İletişim Kolaylığı:**
Bir program genellikle çalıştırıldığı terminal üzerinden kullanıcı ile etkileşim kurar. Bu nedenle, `stdout` ve `stderr` varsayılan olarak terminale bağlanır, böylece programın çıktısı ve hata mesajları kullanıcıya anında gösterilebilir.
2. **Varsayılan Çalışma Mantığı:**
Eğer her program için çıktı hedefi (dosya veya cihaz) ayrı ayrı belirtilmek zorunda olsaydı, kullanım karmaşıklaşırdı. Bu yüzden, hiçbir şey belirtilmezse terminal kullanılır.
3. **Yönlendirme Esnekliği:**
Standart çıktıların (stdout ve stderr) terminale bağlanması, `>` (çıktı yönlendirme) ve `|` (pipe) gibi mekanizmalarla başka yerlere yönlendirilmesini kolaylaştırır. Bu sayede terminal dışında dosyalara veya başka programlara veri aktarımı yapılabilir.

---

### **Bu Bağlantı Nasıl Oluşturulur?**

1. **İşletim Sistemi Seviyesinde:**
Bir program çalıştırıldığında, işletim sistemi onun için bir **process control block (PCB)** oluşturur. Bu blok, süreç ile ilgili bilgiler (dosya tanımlayıcılar, bellek alanları, çalışma durumu gibi) içerir.
2. **Terminal Bağlantısı:**
Program başlatıldığında:
    - **stdin (fd = 0):** Terminalin klavye girişine bağlanır.
    - **stdout (fd = 1):** Terminalin ekran çıktısına bağlanır.
    - **stderr (fd = 2):** Terminalin ekran çıktısına bağlanır (ama genellikle hata mesajları için ayrılmıştır).
3. **C Kütüphaneleri Üzerinden Erişim:**
C'deki `printf`, `fprintf` gibi fonksiyonlar da aslında altta yatan `write` çağrılarını kullanır ve bu bağlantılar sayesinde terminale yazabilir.

---

### **Oluşturulan "Bağlantı" Hangi Dosyayı İfade Eder?**

- Terminalde çalıştırdığınız programlar için bu bağlantılar **pseudo-terminal cihazlarına** işaret eder.
- Bu cihazlar, genellikle `/dev` dizininde bulunur:
    - `/dev/tty`: Terminale bağlı genel cihaz dosyası.
    - `/dev/pts/N`: Pseudo-terminal cihazları (örneğin bir terminal emülatöründeki belirli oturum).

Örnek: Bir terminalde `ls -l /dev/pts` komutunu çalıştırdığınızda, o terminal için oluşturulan cihaz dosyasını görebilirsiniz.

---

### **Eğer Yönlendirme Yapılırsa?**

Eğer `stdout` başka bir yere yönlendirilirse (örneğin bir dosyaya), işletim sistemi bu bağlantıyı ilgili dosyaya yapar. Örneğin:

```bash
bash
Kodu kopyala
./program > output.txt

```

Bu durumda:

- `stdout` artık terminal yerine `output.txt` dosyasına bağlıdır.
- Dosya, çalıştırdığınız dizinde oluşturulur (aksi belirtilmedikçe).

---

### Özet:

- **Neden terminale bağlı?** Çünkü varsayılan çıktı hedefi terminaldir ve bu standartlaştırılmış bir iletişim modelidir.
- **Nereye bağlı?** Varsayılan olarak `/dev/tty` veya `/dev/pts/N` gibi terminal cihazlarına bağlıdır. Bu cihazlar sanal terminal veya fiziksel terminali temsil eder.

---

![image](https://github.com/user-attachments/assets/bab9409d-2acf-46f7-97c8-04aedbb79095)

Bu standart dosyaların bulunduğu yer.

### TTY – Teletypewriter

**TTY , Teletype’ın** kısaltmasıdır . 1800’lerde mesaj yazmak ve göndermek için kullanılan eski bir elektromekanik cihaz olan **Teletypewriter’dan** türetilmiştir .

Linux/UNIX’te **TTY** , sunucunuza bağlı konsol gibi standart bir terminal aygıtına atıfta bulunur. Esasen, veri girerek ve çıktıyı görüntüleyerek sistemle etkileşime girmenizi sağlayan bir cihazdır.

# MAN READ (  )

```
ssize_t read(intfd, voidbuf[.count], size_tcount);
```

## **AÇIKLAMA**

```
read () 
       fd dosya tanımlayıcısından
       başlayarak tampona kadar olan baytı okumaya çalışır.
       
       Aramayı destekleyen dosyalarda okuma işlemi şu şekilde başlar:
       dosya ofseti ve dosya ofseti sayı kadar artırılır
       okunan bayt sayısı. 
       Dosya ofseti dosyanın sonunda veya sonrasında ise,
       hiçbir bayt okunmaz veread () sıfır döndürür.
       
       Eğersayım sıfırsa,read ()aşağıda açıklanan hataları tespit edebilir.
       Herhangi bir hata yoksa veyaread () kontrol etmiyorsa
       hatalar, 0sayımı olan birread ()sıfır döndürür ve başka bir şeye sahip değildir
       etkileri.
       
       POSIX.1'e göre,sayımSSIZE_MAX'tan büyükse,
       sonuç uygulama tarafından tanımlanmıştır; üst sınır için NOTLAR'a bakın
       Linux'ta.
```

## **DÖNÜŞ DEĞERİ**

```
       Başarılı olursa, okunan bayt sayısı döndürülür (sıfır,
       (dosya sonu) ve dosya konumu bu sayı kadar ilerletilir.
       Bu sayının, sayının altında olması hata değildir.
       talep edilen bayt sayısı; bu durum örneğin daha az bayt olması nedeniyle gerçekleşebilir
       aslında şu anda mevcut (belki de yakın olduğumuz için)
       dosya sonu veya bir borudan veya bir
       terminal) veyaread () bir sinyal tarafından kesintiye uğradığı için. Bkz.
       ayrıca NOTLAR.
       Hata durumunda -1 döndürülür vehatayı belirtmek içinerrno değeri ayarlanır.
       Bu durumda, dosya konumunun belirtilmesi gerekmemektedir.
       (eğer varsa) değişiklikler.
```

*Not:* 

```
*Linux'taread () (ve benzeri sistem çağrıları) en fazla şu şekilde aktarılır:
       0x7ffff000 (2.147.479.552) bayt, bayt sayısını döndürüyor
       aslında transfer edildi. (Bu hem 32 bit hem de 64 bit için geçerlidir
       (sistemler.)*
```
## Static Değişkeni Neden Tanımlarken Neden Değerini Null’a Eşitleriz?

`static` türündeki bir değişkenin başta `NULL` olarak tanımlanmasının birkaç önemli nedeni vardır. Bu davranış, hem işlevsellik hem de programın doğru şekilde çalışmasını sağlamak için gereklidir. İşte detaylı bir açıklama:

---

### **1. `static` Değişkenlerin Başlangıç Değeri**

C dilinde, bir `static` değişken, otomatik olarak sıfır değerine (ya da bir pointer için `NULL`) ayarlanır. Ancak, bunu açıkça belirtmek, kodun okunabilirliğini ve niyetini netleştirir.

```c
static char *line = NULL;

```

Yukarıdaki kod, değişkenin başlangıçta bir pointer olarak herhangi bir geçerli bellek adresini göstermediğini ifade eder.

---

### **2. İlk Durumu Belirlemek**

`get_next_line` fonksiyonu her çağrıldığında, `line` değişkeni bir önceki çağrının sonucunu taşıyabilir. Ancak, ilk çağrıda `line`'ın kesinlikle geçerli bir başlangıç durumu olması gerekir. Bu nedenle `NULL` ile başlatılır:

- Eğer `line` başlangıçta `NULL` değilse, belirsiz bir değere sahip olabilir ve bu durum, bellek erişim hatalarına veya tanımsız davranışlara neden olabilir.
- `read_line(fd, line)` fonksiyonu, `line` değişkeninin `NULL` olduğunu bilerek ilk kez veri okuma işlemine başlayabilir.

---

### **3. Bellek Yönetimi ve Devamlılık**

`static` değişkenler bir fonksiyonun her çağrısı arasında değerini korur. Bu, `get_next_line` fonksiyonunun önceki okuma işlemini hatırlaması için gereklidir:

- İlk çağrıda, `line` değişkeni `NULL` olduğundan, fonksiyon yeni bir veri okuma işlemi başlatır.
- Sonraki çağrılarda, `line`'ın bir önceki veriyi sakladığını varsayar ve kaldığı yerden devam eder.

---

### **4. Hata Durumlarını Doğru Ele Alma**

Eğer `line` başlangıçta `NULL` olarak ayarlanmazsa ve belirsiz bir değere sahip olursa:

- `read_line(fd, line)` gibi bir fonksiyona geçersiz bir pointer gönderilebilir, bu da programın çökmesine neden olabilir.
- `ft_get_next_line(line)` gibi bir fonksiyonun geçersiz bir veriyi işlemesi, beklenmeyen sonuçlara yol açabilir.

---

### **5. Kodun Anlaşılabilirliğini Artırmak**

`NULL` ile başlatmak, kodun işlevselliğini ve niyetini netleştirir:

- Başlangıçta `line` değişkeninin geçerli bir veri içermediğini açıkça belirtir.
- Fonksiyonun bu `static` değişkeni nasıl kullandığını anlamayı kolaylaştırır.

---

### **Özet**

- `static` değişkenlerin başlangıçta `NULL` olarak ayarlanması, belirsizlikleri önler ve kodun güvenliğini artırır.
- Bu, `get_next_line` fonksiyonunun her çağrısında doğru şekilde çalışmasını sağlar.
- `NULL` ile başlatma, hem hata yönetimini kolaylaştırır hem de kodun okunabilirliğini artırır.

*Aslında bakacak olursanız biz bunu staticte direkt olarak eşitleyerek belirtiriz fakat zaten tüm değişkenler ilk adımda NULL olarak atanırlar.

### Ben aynı kodu çağırdığımda Static değişken tekrar Null’a eşitlenmez mi?
```
Hayır, `static` değişkenler, aynı kodu tekrar tekrar çağırdığınızda **başlangıçta tanımlanan değeri korur** ve **yeniden başlatılmaz**. Bu, `static` değişkenlerin önemli bir özelliğidir.

### **`static` Değişkenlerin Davranışı**
```
- **Fonksiyon içinde tanımlanan `static` değişkenler**, program çalışırken bir kez oluşturulur ve yaşam döngüsü programın tamamı boyunca devam eder.
- Eğer bir `static` değişken bir fonksiyonun içinde tanımlanmışsa, fonksiyon çağrıldığında önceki değerini hatırlar ve aynı değeri kullanır.
- Ancak, programın başlatıldığı sırada sadece bir kez varsayılan değere (örneğin, `NULL`) atanır.

## **Segmantation Fault Nedir?**
```
Segmentation fault (bazen “segmentation violation” olarak da adlandırılır) bir yazılım hatasıdır ve genellikle programın bellek hatası yaptığını gösterir. Bu hatanın oluştuğu durumlarda, programın bellekte izin verilmeyen bir alana erişmeye çalıştığı için oluşur.

Segmentation Fault hataları :

- "malloc" ile tahsis edilmiş belleği "free" ile serbest bırakıldıktan sonra elde kalan pointer adresine erişmeye çalışmış olabilirsiniz.
- "static" olmayan ve "malloc" ile tahsis edilmemiş "automatic" belleğe boşaltıldıktan sonra erişiyor olabilirsiniz. (fonksiyon içerisinde oluşturulmuş değişkenin adresini fonksiyondan dönmek gibi)
- ya da, farkında olmadan pointer adresini yanlış bir şeye yönlendirdiniz.
- **Dizi Taşması (Buffer Overflow)**:
    - Bir dizinin sınırları dışında bir alana erişmeye çalışmak.

```c
c
int arr[5];
arr[10] = 42; // arr dizisinin sınırları dışında!

```

- **Yanlış İşaretçi Kullanımı**:
    - Serbest bırakılmış (`free()` edilmiş) bir belleğe erişimi

```c
c
int *ptr = malloc(sizeof(int));
free(ptr);
*ptr = 10; // Serbest bırakılan bellek!

```
