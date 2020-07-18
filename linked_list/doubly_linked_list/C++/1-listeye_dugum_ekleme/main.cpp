#include <iostream>
#include <stdlib.h>

using namespace std;

//Çift yönlü bağlı liste ile düğüm ekleme...

class Node//bir sınıf oluşturulur. Bu sınıf üzerinde data ve düğümün sonraki elemanlarını gösteren bir işaretçi ve fonksiyonları tutulur.
{
public:
    int data;
    Node *next;  //sonraki
    Node *prev;  //onceki
    void basaEkle(Node** , int);
    void sonaEkle(Node**, int);
    void dugumdenOnceEkle(Node** , Node* , int);
    void dugumdenSonraEkle(Node* , int);
    void yazdir(Node *);
};

void Node::basaEkle(Node** root_ref, int new_data){
    Node* new_node = new Node();//yeni bir bağlı liste oluşturulur

    new_node->data = new_data;//new_data değişkeni bağlı listeye eklenir

    new_node->next = (*root_ref);//root_ref' i bağlı listenin sonuna atar
    new_node->prev = NULL;//bağlı listenin önceki işaretçisine NULL atar

    if ((*root_ref) != NULL)
        (*root_ref)->prev = new_node;//root_ref'in prev konumunu new_node ile değiştirir

    (*root_ref) = new_node;//yeni düğümü(new_node) root_ref' eşitler
}

void Node::sonaEkle(Node** root_ref, int new_data)
{
    Node* new_node = new Node();//yeni bir bağlı liste  oluşturulur
    Node* last = *root_ref;//bir bağlı liste  daha oluşturulur(last) ve fonksiyondan gelen liste(root_ref) bu listeye atılır

    new_node->data = new_data;//gelen veri(new_data) oluşturulan bağlı listenin data'sına atılır
    new_node->next = NULL;//istenin next'i yeni elemanlar eklemek için NULL'a eşitlenir

    if (*root_ref == NULL)//bağlı liste boşsa
    {
        new_node->prev = NULL;//new_node'un önceki düğümüne NULL değeri atanır
        *root_ref = new_node;//new_node root_ref'e eşitlenerek return edilir
        return;
    }

    while (last->next != NULL)//bağlı liste boş değilse
        last = last->next;//tüm bağlı liste dolaşılır

    last->next = new_node;//new_node last listesinin en sonuna atılır
    new_node->prev = last;//ve last listesi new_node listesinin önceki düğümüne bağlanır
    return;
}

void Node::dugumdenOnceEkle(Node** root_ref, Node* next_node, int new_data)
{
    if (next_node == NULL) {
        cout<<"Sonraki node NULL olamaz"<< endl;
        return;
    }

    Node* new_node = new Node();//yeni bir bağlı liste  oluşturulur

    new_node->data = new_data;//new_data değişkeni bağlı liste  eklenir

    new_node->prev = next_node->prev;//next_node'un önceki düğümünü new_node'un önceki düğümüne atar

    next_node->prev = new_node;//new_node'u next_node'un prev'ine atar

    new_node->next = next_node;//next_node'u yeni oluşturulan bağlı listenin sonraki düğümüne atar

    if (new_node->prev != NULL)//new_node'un önceki düğümü  NULL değilse
        new_node->prev->next = new_node;//new_node'un önceki düğümünün sonuna new_node'u ekler

    else
        (*root_ref) = new_node;//new_node'un önceki düğümü  NULL değil ise new_node'u kök düğümün işaretçisine atar

}

void Node::dugumdenSonraEkle(Node* prev_node, int new_data)
{
    if (prev_node == NULL)//verilen prev_node düğümünün NULL olup olmadığını kontrol eder
    {
        cout<<"Onceki node NULL olamaz\n";
        return;
    }

    Node* new_node = new Node();//yeni bir bağlı liste  oluşturulur

    new_node->data = new_data;//new_data değişkeni bağlı listeye eklenir

    new_node->next = prev_node->next;//prev_node'un sonraki düğümünü new_node'un sonraki düğümüne atar

    prev_node->next = new_node;//new_node'u prev_node'un next'ine atar

    new_node->prev = prev_node;//prev_node'u yeni oluşturulan bağlı listenin önceki düğümüne atar

    if (new_node->next != NULL)
        new_node->next->prev = new_node;//new_node'un bir sonraki düğümüne new_node'u ekler
}

void Node::yazdir(Node *node)//yazdir() metodu ile düğümün tüm elemanları yazdırılır
{
    Node *last;
    cout<<"\nİleri yonde gecis \n";
    while (node != NULL)
    {
        cout<<" "<<node->data<<" ";//düğümdeki veriyi yazdırır
        last = node;//bağlı listeyi ters yonde yazdırmak için last isimli listede node listesini tutar
        node = node->next;//kök işaretçisi sonraki düğümü işaret eder
    }

    cout<<"\nTers yonde gecis \n";
    while (last != NULL)
    {
        cout<<" "<<last->data<<" ";//last düğümündeki veriyi yazdırır
        last = last->prev;//kök işaretçisi önceki düğümü işaret eder
    }
}


int main()
{
    Node node;//fonksiyonları çağırmak için bir nesne oluşturulur
    Node *root = NULL;//düğüm oluşturulur

    node.sonaEkle(&root,5);//düğümün sonuna 5,6 değerleri eklenir
    node.sonaEkle(&root,6);
    node.dugumdenOnceEkle(&root,root->next,15);//root->next'inin önceki düğümüne 15 değerini ekler
    node.sonaEkle(&root,7);//düğümün sonuna 7 değeri eklenir
    node.dugumdenSonraEkle(root->next,12);//root->next'inin sonraki düğümüne 12 değerini ekler
    node.sonaEkle(&root,8);//düğümün sonuna 8 değeri eklenir

    cout << "Bagli Liste: ";
    node.yazdir(root);//bağlı liste yazdırılır

    return 0;
}

