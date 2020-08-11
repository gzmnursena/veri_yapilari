#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node dugum;

dugum *ilk=NULL,*son=NULL;

void basaEkle(int a)
{
    dugum *yeni = (dugum*) malloc(sizeof(dugum));
    yeni->data=a;
    if(ilk==NULL)
    {
        ilk=yeni;
        ilk->next=NULL;
        son=ilk;
    }
    else
    {
        yeni->next=ilk;
        ilk=yeni;
    }
}

void sonaEkle(int a)
{
    dugum *yeni = (dugum*) malloc(sizeof(dugum));
    yeni->data=a;
    if(ilk==NULL)
    {
        ilk=yeni;
        son=yeni;
        son->next=NULL;
    }
    else
    {
        son->next=yeni;
        son=yeni;
        son->next=NULL;
    }
}

int ara(int x)
{
    dugum *ara;
    ara=ilk;
    int sira=1;
    while(ara!=NULL)
    {
        if(ara->data==x)
        {
            return sira;
        }
        sira++;
        ara=ara->next;
    }
    return -1;
}

void listele()
{
    dugum *liste;
    liste=ilk;
    while(liste!=NULL)
    {
        printf("%d ",liste->data);
        liste=liste->next;
    }
}


int main() {

    printf("basa ekle\n");
    basaEkle(4);
    basaEkle(7);
    basaEkle(2);
    basaEkle(3);

    basaEkle(6);
    basaEkle(9);
    basaEkle(1);
    basaEkle(8);
    listele();

   /* printf("sona ekle\n");
    sonaEkle(4);
    sonaEkle(7);
    sonaEkle(2);
    sonaEkle(3);
    sonaEkle(6);
    sonaEkle(9);
    sonaEkle(1);
    sonaEkle(8);
    listele();*/

    printf("\nAranan değer= %d. sıradadır",ara(6));
    return 0;
}