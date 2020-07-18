#include <iostream>
#include <stdio.h>

using namespace std;
//Bağlı listedeki düğüm sayısını bulan program...
class Node {
public:
    int data;
    Node *next;
    void basaEkle(Node **, int);
    void yazdir(Node *);
    int dugumSayisi(Node *);
};

//dairesel bağlantılı listenin başında bir düğüm eklemek için fonksiyon
void Node::basaEkle(Node **root_ref, int data)
{
    Node *ptr1 = new Node();//Dinamik olarak bir düğüm oluşturulur
    Node *temp = *root_ref;
    ptr1->data = data;//Verilerin atanması
    ptr1->next = *root_ref;

    //Bagli liste NULL değilse, son düğümün bir sonraki öğesini ayarlayın
    if (*root_ref != NULL){
        while (temp->next != *root_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1;//İlk düğüm için

    *root_ref = ptr1;
}

void Node::yazdir(Node *root)//yazdir() metodu ile düğümün tüm elemanları yazdırılır
{
    Node *temp = root;//dairesel bagli listede düğümlerin tekrarlanmaması için temp isimli düğümde root düğümü saklanır
    if (root != NULL) {
        do {
            cout << temp->data << " ";//düğümdeki veriyi yazdırır
            temp = temp->next;//kök işaretçisi sonraki düğümü işaret eder
        } while (temp != root);
    }
}

//listedeki düğümlerin sayısını veren fonksiyon
int Node::dugumSayisi(Node *root)
{
    Node *temp = root;
    int sonuc = 0;
    if (root != NULL) {//root NULL olmadığı sürece tüm liste gezilerek(temp = temp->next ile) sonuc değişkeni arttırılır
        do {
            temp = temp->next;
            sonuc++;//düğüm sayısını verir
        } while (temp != root);
    }
    return sonuc;
}


int main()
{
    Node node;
    Node *root = NULL;
    node.basaEkle(&root, 12);//listenin başına 12,56,2,11 değerleri eklenir
    node.basaEkle(&root, 56);
    node.basaEkle(&root, 2);
    node.basaEkle(&root, 11);

    cout<< "Dairesel baglantili liste:"<< endl;
    node.yazdir(root);//liste yazdırılır

    cout<<"\nDugum sayisi= "<< node.dugumSayisi(root) << "  ";//dugumSayisi() fonksiyonu ile listedeki düğüm sayısı bulunur

    return 0;
}