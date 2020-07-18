#include <iostream>
#include <stdlib.h>

using namespace std;
//çift yönlü bağlı listenin boyutunu bulma...
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    void basaEkle(Node **, int);
    int boyutBul(Node *);
    void yazdir(Node *);
};

int Node::boyutBul(Node *node)
{
    //tüm liste dolaşılarak elemanSayisi arttırılır ve eleman sayısı bulunarak return edilir
    int elemanSayisi = 0;
    while (node != NULL) {
        elemanSayisi++;
        node = node->next;
    }
    return elemanSayisi;
}

void Node::basaEkle(Node** root_ref, int new_data){
    Node* new_node = new Node();//yeni bir bağlı liste oluşturulur

    new_node->data = new_data;//new_data değişkeni bağlı listeye eklenir

    new_node->next = (*root_ref);//root_ref' i bağlı listenin sonuna atar
    new_node->prev = NULL;//bağlı listenin önceki işaretçisine NULL atar

    if ((*root_ref) != NULL)
        (*root_ref)->prev = new_node;//root_ref'in prev konumunu new_node ile değiştirir

    (*root_ref) = new_node;//yeni düğümü(new_node) root_ref' eşitler
}

void Node::yazdir(Node *node)//yazdir() metodu ile düğümün tüm elemanları yazdırılır
{
    if (node == NULL)
        cout << "Cift katli bagli liste bos!!!";
    while (node != NULL)
    {
        cout<<" "<<node->data<<" ";//düğümdeki veriyi yazdırır
        node = node->next;//kök işaretçisi sonraki düğümü işaret eder
    }
}

int main()
{
    Node node;
    Node *root = NULL;
    node.basaEkle(&root, 4);//bağlı listenin  başına 4,3,2,1 değerleri eklenir
    node.basaEkle(&root, 3);
    node.basaEkle(&root, 2);
    node.basaEkle(&root, 1);
    cout<<"Baglantili liste:"<< endl;
    node.yazdir(root);//bağlı liste yazdırılır
    cout << "\nBoyut= "<< node.boyutBul(root);//listenin boyutu
    return 0;
}