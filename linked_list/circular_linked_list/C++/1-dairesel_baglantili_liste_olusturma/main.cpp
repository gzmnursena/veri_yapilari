#include <iostream>

using namespace std;
//Dairesel bağlı liste oluşturma...
class Node{//bir sınıf oluşturulur. Bu sınıf üzerinde data ve düğümün sonraki elemanlarını gösteren bir işaretçi ve fonksiyonları tutulur.
public:
    int data;
    Node *next;
    void basaEkle(Node **, int);
    void yazdir(Node *);
};

//dairesel bağlantılı listenin başında bir düğüm eklemek için fonksiyon
void Node::basaEkle(Node **root_ref, int data)
{
    Node *ptr1 = new Node();//Dinamik olarak bir düğüm oluşturulur
    Node *temp = *root_ref;
    ptr1->data = data;//Verilerin atanması
    ptr1->next = *root_ref;

    //Bagli liste NULL değilse, son düğümün bir sonraki öğesini ayarlayın
    if (*root_ref != NULL){
        while (temp->next != *root_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1;//İlk düğüm için

    *root_ref = ptr1;
}

void Node::yazdir(Node *root)//yazdir() metodu ile düğümün tüm elemanları yazdırılır
{
    Node *temp = root;//dairesel bagli listede düğümlerin tekrarlanmaması için temp isimli düğümde root düğümü saklanır
    if (root != NULL){
        do{
            cout << temp->data << " ";//düğümdeki veriyi yazdırır
            temp = temp->next;//kök işaretçisi sonraki düğümü işaret eder
        }while (temp != root);
    }
}

int main()
{
    Node node;
    Node *root = NULL;

    // 11->2->56->12
    node.basaEkle(&root, 12);//bağlı listeye 12,56,2,11 değerleri eklenir
    node.basaEkle(&root, 56);
    node.basaEkle(&root, 2);
    node.basaEkle(&root, 11);

    cout << "Dairesel baglantili liste\n";
    node.yazdir(root);//bagli liste yazdırılır

    return 0;
}
