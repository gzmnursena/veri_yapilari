#include <iostream>
#include <stdlib.h>

using  namespace std;
//Tek yönlü bağlı listeyi silme
class Node//bir sınıf oluşturulur. Bu sınıf üzerinde data ve düğümün sonraki elemanlarını gösteren bir işaretçi ve fonksiyonlar tutulur.
{
public:
    int data;
    Node *next;
    void deleteList(Node**);
    void basaEkle(Node **, int);
    void yazdir(Node *);
};

void Node::deleteList(Node** root_ref)
{
    Node *current = *root_ref;
    Node *next;

    while (current != NULL) {//while döngüsü ile tüm bağlı liste üzerinde dolaşılır
        next = current->next;
        free(current);
        current = next;//sonraki düğümlere gidilerek teker teker tüm düğümler free edilir
    }
    *root_ref = NULL;//kök düğümünde silinmesi için NULL atanır
}

void Node::basaEkle(Node **root_ref, int new_data){
    Node* new_node = new Node();//Düğüm oluşturulur
    new_node->data = new_data;//Oluşturulan düğümün datasına gelen veri atanır
    new_node->next = (*root_ref);//Yeni düğümün next'ini kök olarak atar.
    (*root_ref) = new_node;//Kökü yeni düğümün işaretçisi olarak atar
}


void Node::yazdir(Node *node) //yazdir() metodu ile düğümün tüm elemanları yazdırılır
{
    while (node != NULL) {
        cout << node->data << "  ";//düğümdeki veriyi yazdırır
        node = node->next;//kök işaretçisi sonraki düğümü işaret eder
    }
}

int main()
{
    Node node;//fonksiyonları çağırmak için bir nesne oluşturulur
    Node *root = NULL;//düğüm oluşturulur

    //1->12->1->4->1
    node.basaEkle(&root, 1);//node nesnesi ile basaEkle() fonksiyonu çağırılarak root'un başına 1,4,1,12,1 değerleri eklenir
    node.basaEkle(&root, 4);
    node.basaEkle(&root, 1);
    node.basaEkle(&root, 12);
    node.basaEkle(&root, 1);
    node.yazdir(root);//oluşturulan bağlı liste yazdırılır

    cout << "\nDeleting linked list";
    node.deleteList(&root);//bağlı liste silinir
    node.yazdir(root);//yeni bağlı liste yazdırılır

    cout << "\nLinked list deleted";
}