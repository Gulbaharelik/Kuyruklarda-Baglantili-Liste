#include <stdio.h>
#include <stdlib.h>

// Kuyruk elemanları için düğüm yapısı tanımlaması
struct Dugum {
   int veri;
   struct Dugum* next;
};

// Yeni bir kuyruk oluşturma
struct Dugum* front = NULL; // Baştaki düğümün adresini tutar
struct Dugum* rear = NULL; // Kuyruk sonundaki düğümün adresini tutar

// Kuyrukta eleman var mı kontrolü yapma : Bunun kullanılma nedeni kuyrukta eleman olmadığı durumda hata meydana gelmemesi için
int isEmpty() {
   return (front == NULL);
}

// Kuyruğa eleman ekleme
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

// Kuyruktan eleman çıkarma
void deQueue() {
   if (isEmpty())
      return;
   struct Dugum* temp = front;
   front = front->next;
   free(temp);
   if (front == NULL)
      rear = NULL;
}

// Kuyruk elemanlarını ekrana yazdırma
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

