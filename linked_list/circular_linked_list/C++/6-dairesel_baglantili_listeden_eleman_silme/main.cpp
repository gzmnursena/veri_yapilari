#include <iostream>

using namespace std;
//Dairesel bağlı listeden düğüm silme...
class Node {
public:
    int data;
    Node *next;
    void basaEkle(Node **, int);
    void dugumSil(Node **, int);
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
    if (root != NULL) {
        do {
            cout << temp->data << " ";//düğümdeki veriyi yazdırır
            temp = temp->next;//kök işaretçisi sonraki düğümü işaret eder
        } while (temp != root);
    }

}

void Node::dugumSil(Node **root, int silinecekDeger)
{
    if (*root == NULL)//liste boş ise return edilir
        return;

    if((*root)->data==silinecekDeger && (*root)->next==*root) {//listede bir tane düğüm varsa ve o düğümde silinecek düğüm ise
        free(*root);//bellekten o düğümü siler
        *root=NULL;//root'u temizler
    }

    Node *last=*root,*d;

    if((*root)->data==silinecekDeger) {//silinecek düğüm root->data ise

        while(last->next!=*root)//last isimli listeyi root kadar düğüm ekler
            last=last->next;

        last->next=(*root)->next;
        free(*root);//root'u siler
        *root=last->next;
    }

    while(last->next!=*root && last->next->data!=silinecekDeger) {
        last=last->next;
    }

    if(last->next->data==silinecekDeger) {//last listesinin sonraki düğümünün datası silinecek düğüm ise
        d=last->next;//listeyi doldurur
        last->next=d->next;
        free(d);////bellekten o düğümü siler
    }
    else//silinecek düğümü bulamaz
        cout<<"Bulunamadi"<< endl;
}

int main()
{
    Node node;
    Node *root = NULL;

    node.basaEkle(&root, 2);//listenin başına 2,5,7,8,10 değerleri eklenir
    node.basaEkle(&root, 5);
    node.basaEkle(&root, 7);
    node.basaEkle(&root, 8);
    node.basaEkle(&root, 10);

    cout << "Silmeden once liste:"<< endl;
    node.yazdir(root);//bagli liste yazdırılır

    node.dugumSil(&root, 7);//bağlı listeden 7 değeri silinir

    cout << "\nSildikten sonra liste:"<< endl;
    node.yazdir(root);//yeni oluşan bagli liste yazdırılır

    return 0;
}