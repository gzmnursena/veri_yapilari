#include <iostream>
#include <stdlib.h>

using  namespace std;

//Listeden parametre olarak verilen düğümü silme...
class Node//bir sınıf oluşturulur. Bu sınıf üzerinde data ve düğümün sonraki elemanlarını gösteren bir işaretçi ve fonksiyonlar tutulur.
{
public:
    int data;
    Node *next;
    void basaEkle(Node **,int);
    void deleteNode(Node **,int);
    void yazdir(Node *);
};

void Node::basaEkle(Node **root_ref, int new_data){
    Node* new_node = new Node();//Düğüm oluşturulur
    new_node->data = new_data;//Oluşturulan düğümün datasına gelen veri atanır
    new_node->next = (*root_ref);//Yeni düğümün next'ini kök olarak atar.
    (*root_ref) = new_node;//Kökü yeni düğümün işaretçisi olarak atar
}

void deleteNode(Node **root_ref, int key)
{
    Node* temp = *root_ref, *prev;

    if (temp != NULL && temp->data == key)//Eğer varsa
    {
        *root_ref = temp->next;//düğümün başında bulunan kök düğüme temp bağlanır
        free(temp);//bağlı listeden eleman çıkarılır. [ free(temp) ]
        return;
    }

    while (temp != NULL && temp->data != key)//Aranan eleman tüm bağlı listede aranır. [ while döngüsü ile ]
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    //döngü sonrasında temp NULL değilse
    prev->next = temp->next; // düğümler koparılan yerden bağlanır.[ prev->next = temp->next; ]
    free(temp);//bağlı listeden eleman çıkarılır. [ free(temp) ]
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

    node.basaEkle(&root, 7);//node nesnesi ile basaEkle() fonksiyonu çağırılarak root'un başına 7,1,3,2 değerleri eklenir
    node.basaEkle(&root, 1);
    node.basaEkle(&root, 3);
    node.basaEkle(&root, 2);

    cout<<"Oluşturulan Linked List:"<<endl;
    node.yazdir(root);//oluşturulan bağlı liste yazdırılır
    deleteNode(&root, 1);//düğümdeki 1 değeri silinir
    cout<<"\nYeni Linked List:"<<endl;
    node.yazdir(root);//yeni bağlı liste yazdırılır
    return 0;
}