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

void bubleLink()
{
    dugum *liste;
    int t;
    while(1)
    {
        int kont=0;
        liste=ilk;
        while(liste->next!=NULL)
        {
            if(liste->data>liste->next->data)
            {
                int t=liste->data;
                liste->data=liste->next->data;
                liste->next->data=t;
                kont=1;
            }
            liste=liste->next;
        }
        if(kont==0)
            break;
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

    /*printf("başa ekle\n");
    basaEkle(4);
    basaEkle(7);
    basaEkle(2);
    basaEkle(3);
    basaEkle(6);
    basaEkle(9);
    basaEkle(1);
    basaEkle(8);
    listele();*/

    printf("sona ekle\n");
    sonaEkle(4);
    sonaEkle(7);
    sonaEkle(2);
    sonaEkle(3);
    sonaEkle(6);
    sonaEkle(9);
    sonaEkle(1);
    sonaEkle(8);
    listele();

    printf("\nSıralandıktan sonra\n");
    bubleLink();
    listele();

    return 0;
}