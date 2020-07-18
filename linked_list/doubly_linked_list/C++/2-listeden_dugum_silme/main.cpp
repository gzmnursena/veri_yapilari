#include <iostream>
#include <stdlib.h>

using namespace std;

//Çift yönlü bağlı listeden düğüm silme

class Node{//bir sınıf oluşturulur. Bu sınıf üzerinde data ve düğümün sonraki elemanlarını gösteren bir işaretçi ve fonksiyonları tutulur.
public:
    int data;
    Node *next; //sonraki
    Node *prev; //onceki
    void deleteNode(Node **, Node *);
    void basaEkle(Node** , int);
    void yazdir(Node *);
};

void Node::deleteNode(Node **root_ref, Node *sil)
{
    if (*root_ref == NULL || sil == NULL)//fonksiyondan gelen bağlı liste NULL ise return komutu çalışır
        return;

    if (*root_ref == sil)//silinecek düğüm kök düğüm(root_ref) ise
        *root_ref = sil->next;

    if (sil->next != NULL)//silinecek düğüm son düğüm değilse sil bağlı listesindeki sonraki değeri ile değiştirir
        sil->next->prev = sil->prev;

    if (sil->prev != NULL)//silinecek düğüm ilk düğüm değilse il bağlı listesindeki önceki değeri ile değiştirir
        sil->prev->next = sil->next;

    free(sil);//sil tarafından işgal edilen bellek silinir
    return;
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

    // 10<->8<->4<->2
    node.basaEkle(&root, 2);//bağlı listeye 2,4,8,10 değerleri eklenir
    node.basaEkle(&root, 4);
    node.basaEkle(&root, 8);
    node.basaEkle(&root, 10);


    cout << "Linked list:\n";
    node.yazdir(root);//liste yazdırılır

    node.deleteNode(&root, root); //ilk dugumu sil
    node.deleteNode(&root, root->next); //orta dugumu sil
    node.deleteNode(&root, root->next); //son dugumu sil

    cout << "\nDegistirilmis Linked list:\n";
    node.yazdir(root);

    return 0;
}