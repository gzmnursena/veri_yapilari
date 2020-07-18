#include <iostream>

using namespace std;
//Dairesel bağlı listeyi ikiye bölerek iki tane dairesel bağlı liste oluşturma...
class Node{//bir sınıf oluşturulur. Bu sınıf üzerinde data ve düğümün sonraki elemanlarını gösteren bir işaretçi ve fonksiyonları tutulur.
public:
    int data;
    Node *next;
    void listeyiBol(Node *, Node **, Node **);
    void basaEkle(Node **, int);
    void yazdir(Node *);
};

//Bir listeyi (root'tan başlayarak) iki listeye bölmek için kullanılan fonksiyon
// root1_ref ve root2_ref, iki bağlantılı bağlantılı listenin root düğümlerine yapılan referanslardır
void Node::listeyiBol(Node *root, Node **root1_ref, Node **root2_ref)
{
    Node *slow_ptr = root;
    Node *fast_ptr = root;

    if(root == NULL)//liste boş ise return edilir
        return;

    //Dairesel listede tek düğüm varsa
    //fast_ptr->next root olur ve hatta düğümler için fast_ptr->next->next root olur
    while(fast_ptr->next != root && fast_ptr->next->next != root){
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }

    //listede çift düğüm varsa fast_ptr'yi fast_ptr->next'ne taşır
    if(fast_ptr->next->next == root)
        fast_ptr = fast_ptr->next;

    *root1_ref = root;//İlk yarıdaki düğümleri root işaretçisini ayarlama

    //İkinci yarıdaki düğümleri root işaretçisini ayarlama
    if(root->next != root)
        *root2_ref = slow_ptr->next;

    fast_ptr->next = slow_ptr->next;//İkinci yarıdaki düğümleri dairesel liste yapar

    slow_ptr->next = root;//İlk yarıdaki düğümleri dairesel liste yapar
}

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
    Node *root1 = NULL;
    Node *root2 = NULL;

    // 12->56->2->11
    node.basaEkle(&root, 12);//listenin başına 12,56,2,11 düğümleri eklenir
    node.basaEkle(&root, 56);
    node.basaEkle(&root, 2);
    node.basaEkle(&root, 11);

    cout << "Dairesel baglantili liste:";
    node.yazdir(root);//liste yazdırılır

    node.listeyiBol(root, &root1, &root2);//liste ikiye bölünür

    cout << "\nIlk dairesel baglantili liste:";
    node.yazdir(root1);//ilk dairesel bağlı liste yazdırılır

    cout << "\nIkinci dairesel baglantili liste:";
    node.yazdir(root2);//ikinci dairesel bağlı liste yazdırılır
    return 0;
}