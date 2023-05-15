#include <stdio.h>
#include <stdlib.h>

/*
	4.SORU
Kuyruklar�n ba�lant�l� liste uygulamas�n� g�steren bir program yaz�n�z. 
a) Ekleme, silme ve g�r�nt�leme i�lemleri de�er d�nd�rmeyen fonksiyon olarak tan�mlay�n.
b) Ekleme, silme ve g�r�nt�leme gibi t�m i�lemleri kullan�c�dan isteyin.
c) Girilen se�ene�e g�re switch ifadesini kullanarak ilgili fonksiyona eri�in.	

*/

// Kuyruk elemanlar� i�in d���m yap�s� tan�mlamas�
struct Dugum {
   int veri;
   struct Dugum* next;
};

// Yeni bir kuyruk olu�turma
struct Dugum* front = NULL; // Ba�taki d���m�n adresini tutar
struct Dugum* rear = NULL; // Kuyruk sonundaki d���m�n adresini tutar

// Kuyrukta eleman var m� kontrol� yapma : Bunun kullan�lma nedeni kuyrukta eleman olmad��� durumda hata meydana gelmemesi i�in
int isEmpty() {
   return (front == NULL);
}

// Kuyru�a eleman ekleme
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

// Kuyruktan eleman ��karma
void deQueue() {
   if (isEmpty())
      return;
   struct Dugum* temp = front;
   front = front->next;
   free(temp);
   if (front == NULL)
      rear = NULL;
}

// Kuyruk elemanlar�n� ekrana yazd�rma
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

