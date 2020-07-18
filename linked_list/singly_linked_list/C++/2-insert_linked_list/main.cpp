#include <iostream>
#include <stdlib.h>

using namespace std;

//Listenin başına,sonuna ve araya düğüm ekleme...

class Node//bir sınıf oluşturulur. Bu sınıf üzerinde data ve düğümün sonraki elemanlarını gösteren bir işaretçi ve fonksiyonları tutulur.
{
public:
    int data;
    Node *next;
    void basaEkle(Node **, int);
    void dugumdenSonraEkle(Node *,int);
    void sonaEkle(Node **, int);
    void yazdir(Node *);

};

void Node::basaEkle(Node **root_ref, int new_data){
    Node* new_node = new Node();//Düğüm oluşturulur
    new_node->data = new_data;//Oluşturulan düğümün datasına gelen veri atanır
    new_node->next = (*root_ref);//Yeni düğümün next'ini kök olarak atar.
    (*root_ref) = new_node;//Kökü yeni düğümün işaretçisi olarak atar
}


void Node::dugumdenSonraEkle(Node *gelen_node, int new_data){

    if (gelen_node == NULL){//gelen düğümün bağlanacağı önceki düğümün boş olmaması gerektiği için kontrol yapılır
        cout<<"Önceki düğüm NULL olamaz";
        return;
    }

    Node *yeni_node = new Node();//Listenin ortasına veri eklemek için bir tane düğüm oluşturulur.

    yeni_node->data = new_data;// Oluşturulan düğümün datasına gelen veri atar.

    yeni_node->next = gelen_node->next;

    gelen_node->next = yeni_node;
    //Bağlı listedeki düğüm koparak yeni düğüm koparılan yere bağlanır ve datası atanır.
}

void Node::sonaEkle(Node **root_ref, int new_data){

    Node* new_node = new Node();//Listenin sonuna veri eklemek için bir tane düğüm oluşturulur. (new_node)

    Node *last = *root_ref;//Bir düğüm daha oluşturulur ve buna kök düğümün işaretçisi atanır. (last)

    new_node->data = new_data;//Oluşturulan düğümün datasına gelen veri atanır.

   new_node->next = NULL;//Düğümün sonraki işaretçisi NULL olarak gösterilir.

    if (*root_ref == NULL){
        *root_ref = new_node;//Eğer kök düğümün işaretçisi NULL'u gösteriyorsa yeni oluşturulan düğüm kök düğüme atanır.
        return;
    }

    while (last->next != NULL)//Bir döngü ile son eleman bulunur.
        last = last->next;

    last->next = new_node;//son düğüme yeni oluşturlan düğüm atanır
    return;
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

    node.basaEkle(&root, 7);//node nesnesi ile basaEkle() fonksiyonu çağırılarak root'un başına 7,1,8 değerleri eklenir
    node.basaEkle(&root, 1);
    node.basaEkle(&root,8);

    node.sonaEkle(&root, 4);//node' nesnesi ile sonaEkle() fonksiyonu çağırılarak root'un sonuna 4,5,6,22 değerleri eklenir
    node.sonaEkle(&root, 5);
    node.sonaEkle(&root, 6);
    node.sonaEkle(&root, 22);

    node.dugumdenSonraEkle(root->next, 900);//root'un next'inin işaret ettiği düğüme 900
    node.dugumdenSonraEkle(root->next->next, 100);//root'un next->next'inin işaret ettiği düğüme 100 değerleri eklenir
    node.dugumdenSonraEkle(root->next->next->next, 800);
    node.dugumdenSonraEkle(root->next->next->next->next, 300);

    node.yazdir(root);//düğüm yazdırılır

    return 0;
}
