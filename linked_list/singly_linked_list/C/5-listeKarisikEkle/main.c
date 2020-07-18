#include <stdio.h>
#include <stdlib.h>

struct n
{
    int veri;
    struct n * next;
};

typedef struct n dugum;

void bastir (dugum * r)
{
    while(r!=NULL)
    {
        printf("%d ",r->veri);
        r=r->next;
    }
}

//root ile r ayni yeri point ettigi için
//degisen root u main e alir.
struct node * siraliEkle(dugum * r,int veri)
{
    if(r==NULL)
    {
        r=(dugum*)malloc(sizeof(dugum));
        r->next=NULL;
        r->veri=veri;
        return r;
    }
    node * iter=r;
//listenin sonuna gelinmediyse ve
//listenin içinde su anda baktıgım elemanın veri degeri benim ekledigim elemandan kucukse o zman bir sonrakine gitmem lazim.
    while(iter->next!=NULL && iter->next->veri < x)
    {
        iter=iter->next;
    }
    //Tek bir kutu varsa
    if(r->next==NULL)
    {
        // yeni eklenecek olan kutudan kucuk ise
        //400  varken 40 eklemek gibi
        if(r->veri>veri)
        {
            dugum * temp=(dugum*)malloc(sizeof(dugum));
            //temp->next=NULL;
            temp->veri=veri;
            temp->next=root;
            //  r=temp;//root artik temp i gosterir
            //  return r;
            return temp;
        }
            // yeni eklenecek olan kutudan buyukse ise
            //400  varken 450 eklemek gibi   veya esitlik varsa
        else
        {

            dugum * temp=(dugum*)malloc(sizeof(dugum));

            temp->veri=veri;
            temp->next=NULL;
            r->next=temp;//root artik temp i gosterir
            return r;
        }
    }
}
int main()
{
    dugum * root;
    root=NULL;

    root= siraliEkle(root,400);
    root=siraliEkle(root,40);
    root= siraliEkle(root,4);
    root=siraliEkle(root,450);
    root=siraliEkle(root,50);

    bastir(root);

    dugum * iter=root;
    int i=0;
    for(i=0; i<3; i++)
    {
        iter=iter->next;
    }

//degerin tutulmasý için gecici dugum olusturuldu
//temp=gecici
    dugum * temp=(dugum*)malloc(sizeof(dugum));
    temp->next=iter->next;
    iter->next=temp;
    temp->veri=100;
    bastir(root);
}
