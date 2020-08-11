#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};


void elemanEkle(){
    struct  node *root;
    root=(struct node*)malloc(sizeof(struct node));
    root->data=10;
    printf("%d\n",root->data);
    root->next=(struct node*)malloc(sizeof(struct node));
    root->next->data=20;
    printf("%d\n",root->next->data);
    root->next->next=(struct node*)malloc(sizeof(struct node));
    root->next->next->data=30;
    printf("%d\n",root->next->next->data);

    struct node *iter;
    iter=root;
    printf("iter:\n%d\n",iter->data);
    iter=iter->next;
    printf("%d\n",iter->data);
    iter=iter->next;
    printf("%d\n",iter->data);
}


struct node *ilk=NULL, *son=NULL;

void basaEkle(int a){
    struct node  *yeni=(struct node*) malloc(sizeof(struct node));
    yeni->data=a;

    if(ilk==NULL)
    {
        ilk=yeni;
        son=yeni;
        ilk->next=NULL;
    }

    else
    {
        yeni->next=ilk;  //yeni->next=son;
        ilk=yeni;
        son=yeni;
    }
}


void sonaEkle(int a){
    struct node *yeni=(struct node*)malloc(sizeof(struct node));
    yeni->data=a;

    if(ilk==NULL)
    {
        son=yeni;
        ilk=yeni;
        son->next=NULL;
    }

    else
    {
        son->next=yeni;
        son=yeni;
        //ilk=yeni;
        son->next=NULL;
    }
}

void listele(){
    struct node *liste;
    liste=ilk;

    while(liste!=NULL)
    {
        printf("%d ",liste->data);
        liste=liste->next;

    }
}

int ara(int x){
    struct node *ara;
    ara=ilk;
    int sayac=1;
    while(ara!=NULL)
    {
        if(ara->data==x)
        {
            return sayac;
        }
        sayac++;
        ara=ara->next;
    }
    return -1;
}

int main(){


    printf("eleman ekle\n");
    elemanEkle();

    printf("\n\nbasa ekle\n");
    basaEkle(4);
    basaEkle(7);
    basaEkle(8);
    listele();

    printf("\n\n\n sona ekle\n");
    sonaEkle(4);
    sonaEkle(7);
    sonaEkle(8);
    listele();

    printf("\n\nListe\n");
    listele();
    int aranan=ara(7);
    if(aranan==-1)
        printf("\nAranan deger listede yoktur");
    else
        printf("\nAranan deger %d. sıradadır",aranan);

    return 0;
}
