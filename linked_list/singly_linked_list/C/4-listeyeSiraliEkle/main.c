#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node dugum;

dugum *ilk=NULL,*son=NULL;

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


void siraliEkle(int a)
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
        if(yeni->data<ilk->data)
            basaEkle(yeni->data);

        else if(yeni->data>son->data)
            sonaEkle(yeni->data);

        else
        {
            dugum *sira=ilk;
            while(sira->next->data < yeni->data)
                sira=sira->next;
            yeni->next=sira->next;
            sira->next=yeni;
        }
    }
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


int main()
{
    /*printf("sona ekle"\n");
    sonaEkle(4);
    sonaEkle(7);
    sonaEkle(2);
    sonaEkle(3);

    sonaEkle(6);
    sonaEkle(9);
    sonaEkle(1);
    sonaEkle(8);*/

   /*printf("basa ekle"\n");
    basaEkle(4);
    basaEkle(7);
    basaEkle(2);
    basaEkle(3);

    basaEkle(6);
    basaEkle(9);
    basaEkle(1);
    basaEkle(8);*/


    printf("Sıralı liste\n");
    siraliEkle(4);
    siraliEkle(7);
    siraliEkle(2);
    siraliEkle(3);
    siraliEkle(6);
    siraliEkle(9);
    siraliEkle(1);
    siraliEkle(8);
    listele();

    return 0;
}
