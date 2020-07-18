#include <iostream>
#include <stdlib.h>

using namespace std;
//Bağlı liste içerisinde sıralanmamış-tekrarlı verilerden tekrarlı olanları kaldırır
class Node {
public:
    int data;
    Node *next;
    Node *prev;
    void deleteNode(Node **, Node *);
    void removeDuplicates(Node **);
    void basaEkle(Node **, int);
    void yazdir(Node *);
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

void Node::removeDuplicates(Node **root_ref)
{
    if((*root_ref) == NULL ||
        (*root_ref)->next == NULL)
        return;

     Node *ptr1, *ptr2;

    for(ptr1 = *root_ref; ptr1 != NULL; ptr1 = ptr1->next) {
        ptr2 = ptr1->next;

        while (ptr2 != NULL) {

            if(ptr1->data == ptr2->data) {//düğümdeki veriler aynı ise

                 Node* next = ptr2->next;

                deleteNode(root_ref, ptr2);//deleteNode() fonksiyonu çağırılarak düğüm silinir

                ptr2 = next;
            }

            else//düğümdeki veriler aynı değilse
                ptr2 = ptr2->next;//bir sonraki düğüme geçilir
        }
    }
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

    //8<->4<->4<->6<->4<->8<->4<->10<->12<->12
    node.basaEkle(&root, 12);//bağlı listenin başına, 12,12,10,4,8,4,6,4,4,8 elemanları eklenir
    node.basaEkle(&root, 12);
    node.basaEkle(&root, 10);
    node.basaEkle(&root, 4);
    node.basaEkle(&root, 8);
    node.basaEkle(&root, 4);
    node.basaEkle(&root, 6);
    node.basaEkle(&root, 4);
    node.basaEkle(&root, 4);
    node.basaEkle(&root, 8);

    cout << "Linked List:\n";
    node.yazdir(root);//bağlı liste yazdırılır

    node.removeDuplicates(&root);//sıralamamış-tekrarlı düğümleri siler

    cout << "\nYeni Linked List:\n";
    node.yazdir(root);

    return 0;
}