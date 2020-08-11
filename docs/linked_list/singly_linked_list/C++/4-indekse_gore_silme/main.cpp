#include <iostream>
#include <stdlib.h>

using  namespace std;
//Listedeki düğümü indekse göre silme...
class Node{//bir sınıf oluşturulur. Bu sınıf üzerinde data ve düğümün sonraki elemanlarını gösteren bir işaretçi ve fonksiyonlar tutulur.
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

void Node::deleteNode(Node **root_ref, int index)
{
   if (*root_ref == NULL)
      return;

    Node *temp = *root_ref;

    if (index == 0)//bağlı listeden kök(root) silinecek ise(0.index)
    {
        *root_ref = temp->next;//düğümün kök işaretçi bir sonraki düğüm olur
        free(temp);//kök işaretçi free yapılıp return edilir.
        return;
    }

    //silinecek index 0'dan farklı ise Node sınıfından *temp tipindeki değişkene root_ref'teki tüm değerler atılır
    for (int i=0; temp!=NULL && i<index-1; i++)
         temp = temp->next;

    //bağlı liste boş ise deleteNode() fonksiyonundan çıkar
    if (temp == NULL || temp->next == NULL)
         return;

    //bağlı liste boş değilse ve silinecek index 0 değilse;
    Node *next = temp->next->next;

    free(temp->next);//indekse eşit olan elemanın işaretçisi free yapılıp return edilir

    temp->next = next;
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
    Node node;;//fonksiyonları çağırmak için bir nesne oluşturulur
    Node *root = NULL;//düğüm oluşturulur

    node.basaEkle(&root, 7);//node nesnesi ile basaEkle() fonksiyonu çağırılarak root'un başına 7,1,3,2,8 değerleri eklenir
    node.basaEkle(&root, 1);
    node.basaEkle(&root, 3);
    node.basaEkle(&root, 2);
    node.basaEkle(&root, 8);

    cout<<"Oluşturulan Linked List:"<<endl;
    node.yazdir(root);//oluşturulan bağlı liste yazdırılır
    node.deleteNode(&root, 3);//deleteNode(&root, 3) fonksiyonu başlangıç adresi verilen düğümdeki 3. ve 0. indexteki elemanları siler
    node.deleteNode(&root, 0);
    cout<<"\nYeni Linked List:"<<endl;
    node.yazdir(root);//yeni bağlı liste yazdırılır
    return 0;
}