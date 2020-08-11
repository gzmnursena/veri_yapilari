#include <iostream>
#include <stdlib.h>

using namespace std;
//Listedeki sıralı-tekrarlı düğümleri silme
class Node
{
public:
    int data;
    Node *next;
    void removeDuplicates(Node *);
    void basaEkle(Node **, int);
    void yazdir(Node *);
};

void Node::removeDuplicates(Node *root)
{
    Node *next_next;

    if (root == NULL)//düğüm boş ise
        return;

    while (root->next != NULL)
    {
        if (root->data == root->next->data)//düğüm ile sonraki elemanı aynı ise
        {
            //Düğümü kopartılarak kök işaretçisi sonraki düğümü işaret eder
            next_next = root->next->next;
            free(root->next);
            root->next = next_next;
        }
        else//düğüm ile sonraki elemanı aynı değil ise
        {
            root = root->next;//kök işaretçisi sonraki düğümü işaret eder
        }
    }
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

    node.basaEkle(&root, 20);//node nesnesi ile basaEkle() fonksiyonu çağırılarak root'un başına 20,13,13,11,11,11 değerleri eklenir
    node.basaEkle(&root, 13);
    node.basaEkle(&root, 13);
    node.basaEkle(&root, 11);
    node.basaEkle(&root, 11);
    node.basaEkle(&root, 11);

    cout<<"Bağlı Liste:\n";
    node.yazdir(root);//bağlı liste yazdırılır

    node.removeDuplicates(root);//bağlı listedeki tekrar eden düğümlerdeki değerleri silmek için removeDuplicates() fonksiyonu çağırılır

    cout<<"\nYeni Bağlı Liste:\n";
    node.yazdir(root);//yeni bağlı liste yazdırılır

    return 0;
}