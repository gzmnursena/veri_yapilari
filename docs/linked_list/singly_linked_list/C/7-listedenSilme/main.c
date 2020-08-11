#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node dugum;

dugum *ilk=NULL,*son=NULL;

void basaEkle(int a){

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

void sil(int x){

    dugum *sil=ilk, *once=NULL;
    while(sil!=NULL)
    {
        if(sil->data==x)
            break;
        else
        {
            once=sil;
            sil=sil->next;
        }
    }
    if(sil!=NULL)
    {
        if(sil==ilk)
        {
            ilk=ilk->next;
        }
        else if(sil==son)
        {
            son=once;
            once->next=NULL;
        }
        else
        {
            once->next=sil->next;
        }
        free(sil);
    }
}

void listele(){
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

    /*printf("\nsona ekle\n");
    sonaEkle(4);
    sonaEkle(7);
    sonaEkle(2);
    sonaEkle(3);
    sonaEkle(6);
    sonaEkle(9);
    sonaEkle(1);
    sonaEkle(8);
    listele();*/

    sil(6);
    printf("\nSilindikten Sonra\n");
    listele();

    sil(3);
    sil(7);
    printf("\nSilindikten Sonra\n");
    listele();

    return 0;
}