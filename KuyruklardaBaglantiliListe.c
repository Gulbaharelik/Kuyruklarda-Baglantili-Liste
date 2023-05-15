#include <stdio.h>
#include <stdlib.h>

/*
	4.SORU
Kuyruklarýn baðlantýlý liste uygulamasýný gösteren bir program yazýnýz. 
a) Ekleme, silme ve görüntüleme iþlemleri deðer döndürmeyen fonksiyon olarak tanýmlayýn.
b) Ekleme, silme ve görüntüleme gibi tüm iþlemleri kullanýcýdan isteyin.
c) Girilen seçeneðe göre switch ifadesini kullanarak ilgili fonksiyona eriþin.	

*/

// Kuyruk elemanlarý için düðüm yapýsý tanýmlamasý
struct Dugum {
   int veri;
   struct Dugum* next;
};

// Yeni bir kuyruk oluþturma
struct Dugum* front = NULL; // Baþtaki düðümün adresini tutar
struct Dugum* rear = NULL; // Kuyruk sonundaki düðümün adresini tutar

// Kuyrukta eleman var mý kontrolü yapma : Bunun kullanýlma nedeni kuyrukta eleman olmadýðý durumda hata meydana gelmemesi için
int isEmpty() {
   return (front == NULL);
}

// Kuyruða eleman ekleme
void enQueue(int veri) {
   struct Dugum* newDugum = (struct Dugum*) malloc(sizeof(struct Dugum)); 
   newDugum->veri = veri;
   newDugum->next = NULL;
   if (isEmpty()) {
      front = rear = newDugum;
      return;
   }
   rear->next = newDugum;
   rear = newDugum;
}

// Kuyruktan eleman çýkarma
void deQueue() {
   if (isEmpty())
      return;
   struct Dugum* temp = front;
   front = front->next;
   free(temp);
   if (front == NULL)
      rear = NULL;
}

// Kuyruk elemanlarýný ekrana yazdýrma
void display() {
   struct Dugum* temp = front;
   while (temp != NULL) {
      printf("%d ", temp->veri);
      temp = temp->next;
   }
   printf("\n");
}

int main() {
   int secim, deger;
   
   do {
    printf("Islem Turleri:\n\n");
    printf("1.Eleman Ekleme\n");
    printf("2.Eleman Silme\n");
    printf("3.Elemanlari Goruntuleme\n");
    printf("4.Cikis");
   
    printf("\n");
   
    printf("Lutfen yukaridaki islemlerden birini seciniz:");
    scanf("%d",&secim);
    printf("\n");
      
      switch(secim) {
       	// Kuyruga eleman ekleniyor
		 case 1:
            printf("\nEklemek istediginiz degeri girin: ");
            scanf("%d", &deger);
            enQueue(deger);
            break;
       	// Kuyruktan eleman cikariliyor
         case 2:
            deQueue();
            break;
    	// Kuyruktaki elemanlar ekrana yazdiriliyor.	
         case 3:
            display();
            break;
      	// Kuyruktan cikis yapiliyor
         case 4:
            printf("\nProgramdan cikiliyor.\n");
            exit(0);
        // Gecersiz islem 
         default:
            printf("\nGecersiz secim. Lutfen tekrar deneyin.\n");
      }
   } while (1);
   
   return 0;
}

