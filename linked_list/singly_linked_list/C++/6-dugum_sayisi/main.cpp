#include <iostream>

using namespace std;
//Listedeki düğüm sayısını bulma...
class Node//bir sınıf oluşturulur. Bu sınıf üzerinde data ve düğümün sonraki elemanlarını gösteren bir işaretçi ve fonksiyonlar tutulur.
{
public:
    int data;
    Node *next;
    void basaEkle(Node **, int);
    int dugumSayisi(Node *);
    void yazdir(Node *);
};

void Node::basaEkle(Node **root_ref, int new_data){
    Node* new_node = new Node();//Düğüm oluşturulur
    new_node->data = new_data;//Oluşturulan düğümün datasına gelen veri atanır
    new_node->next = (*root_ref);//Yeni düğümün next'ini kök olarak atar.
    (*root_ref) = new_node;//Kökü yeni düğümün işaretçisi olarak atar
}

int Node::dugumSayisi(Node *node)
{
    int sayac = 0;
    while (node != NULL) {//bir döngü ile tüm baglı liste dolaşılır
        sayac++;
        node = node->next;//bir sonraki düğüme gidilerek sayac arttılır
    }
    return sayac;//düğüm sayısını veren sayac değişkeni return edilir
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

    node.basaEkle(&root, 1);//node nesnesi ile basaEkle() fonksiyonu çağırılarak root'un başına 1,3,1,2,1 değerleri eklenir
    node.basaEkle(&root, 3);
    node.basaEkle(&root, 1);
    node.basaEkle(&root, 2);
    node.basaEkle(&root, 1);
    node.yazdir(root);//bağlı liste yazdırılır

    cout<<"\nDügüm sayisi: "<< node.dugumSayisi(root);//dugumSayisi() fonksiyonu ile bağlı listedeki düğüm sayısı bulunur
    return 0;
}
