#include <iostream>
#include <stdlib.h>

using namespace std;
//Çift yönlü bağlı listeden index numarası ile düğüm silme
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    void deleteNode(Node **,  Node*);
    void deleteNodeAtGivenPos(Node **, int);
    void basaEkle(Node **, int);
    void yazdir(Node* );
};

void Node::deleteNode(Node **root_ref,  Node* del)
{
    if (*root_ref == NULL || del == NULL)
        return;

    //silinecek düğüm kök düğümse
    if (*root_ref == del)
        *root_ref = del->next;

    //silinecek düğüm son düğüm değilse del bagli listesinin sonraki düğümünü değiştir
    if (del->next != NULL)
        del->next->prev = del->prev;

    //silinecek düğüm ilk düğüm değilse del bagli listesinin önceki düğümünü değiştir
    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);//del tarafından tutulan belleği boşaltır
}

void Node::deleteNodeAtGivenPos(Node **root_ref, int index)
{
    if (*root_ref == NULL || index <= 0)
        return;

    Node* current = *root_ref;

    for (int i = 1; current != NULL && i < index; i++)
        current = current->next;//tüm listeyi dolaşır

    if (current == NULL)//liste NULL ise fonksiyondan öıkar
        return;

    deleteNode(root_ref, current);//deleteNode() fonksiyonu ile verilen indeksi siler
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
    while (node != NULL)
    {
        cout<<" "<<node->data<<" ";//düğümdeki veriyi yazdırır
        node = node->next;//kök işaretçisi sonraki düğümü işaret eder
    }
}

int main()
{
    Node node;
    Node* root = NULL;

    // 10<->8<->4<->2<->5
    node.basaEkle(&root, 5);//bağlı listenin başına 5,2,4,8,10 değerlerini ekler
    node.basaEkle(&root, 2);
    node.basaEkle(&root, 4);
    node.basaEkle(&root, 8);
    node.basaEkle(&root, 10);

    cout << "Baglantili Liste\n";
    node.yazdir(root);//bağlı listeyi yazdırır

    int n = 2;//listeden silinecek index


    node.deleteNodeAtGivenPos(&root, n);//2. sıradaki veriyi siler
    //node.deleteNode(&root,root->next);//verilen adresteki bağlı listenin root->next'indeki düğümü siler

    cout << "\nSilindikten Sonra Baglantili Liste\n";
    node.yazdir(root);

    return 0;
}