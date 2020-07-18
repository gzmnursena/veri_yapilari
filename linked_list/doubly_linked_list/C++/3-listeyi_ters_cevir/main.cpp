#include <iostream>
#include <stdlib.h>

using namespace std;

//Çift yönlü bağlı listeyi ters çevirme

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    void reverse(Node **);
    void basaEkle(Node **, int);
    void yazdir(Node *);
};

void Node::reverse(Node **root_ref)
{
    Node *temp = NULL;
    Node *current = *root_ref;

    while (current != NULL)
    {
        temp = current->prev;//listenin önceki düğümü temp düğümünde tutulur
        current->prev = current->next;//listenin sonraki düğümü ile önceki düğümü yer değiştirir
        current->next = temp;//temp düğümünde tutulan önceki düğüm sonraki düğüme atılır
        current = current->prev;//current listesi önceki düğüme eşitlenir
    }

    if(temp != NULL )
        *root_ref = temp->prev;//root_ref listesi önceki düğüme eşitlenir
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
    Node node;//fonksiyonları çağırmak için bir nesne oluşturulur
    Node *root = NULL;//düğüm oluşturulur

    // 10->8->4->2
    node.basaEkle(&root, 2);//bağlı listeye 2,4,8,10 değerleri eklenir
    node.basaEkle(&root, 4);
    node.basaEkle(&root, 8);
    node.basaEkle(&root, 10);

    cout << "Linked list:\n";
    node.yazdir(root);//liste yazdırılır

    node.reverse(&root);//reverse() fonksiyonu çağrılır

    cout << "\nDegistirilmis Linked list:\n";
    node.yazdir(root);

    return 0;
}