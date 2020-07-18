#include <iostream>
#include <stdlib.h>

using namespace std;

//quick sort ile bağlı listeyi sıralama
class Node{
public:
    int data;
    Node *next;
    Node *prev;
    void swap ( int*, int*);
    Node *lastNode(Node *);
    Node *bol(Node *, Node *);
    void _quickSort(Node *, Node *);
    void quickSort(Node *);
    void yazdir(Node *);
    void basaEkle(Node **, int);
};

//İki işaretçiyi değiştirmek etmek için kullanılan fonksiyon
void Node::swap ( int* a, int* b ){
    int t = *a; *a = *b; *b = t;
}

//Bağlantılı listenin son düğümünü bulmak için bir yardımcı fonksiyon
Node *Node::lastNode(Node *root){
    while (root && root->next)
        root = root->next;
    return root;
}


/*Son öğeyi pivot olarak değerlendirir, pivot öğesini sıralanmış dizideki doğru konumuna yerleştirir ve tüm küçük
 (pivot'tan daha küçük) pivotun soluna ve tüm büyük öğelerin pivotun sağına yerleştirir*/
Node *Node::bol(Node *l, Node *h){
   int x = h->data;//pivotu h elemanı olarak ayarla
    Node *i = l->prev;

    for (Node *j = l; j != h; j = j->next)
    {
        if (j->data <= x)
        {
            i = (i == NULL)? l : i->next;//dizi için i++' ya benzer

            swap(&(i->data), &(j->data));
        }
    }
    i = (i == NULL)? l : i->next;
    swap(&(i->data), &(h->data));
    return i;
}

//Bağlantılı liste için quicksort'un recursive ile olan fonksiyon uygulaması
void Node::_quickSort(Node *node, Node *lastNode)
{
    if (lastNode != NULL && node != lastNode && node != lastNode->next)
    {
        Node *p = bol(node, lastNode);
        _quickSort(node, p->prev);
        _quickSort(p->next, lastNode);
    }
}
//Bağlantılı bir listeyi sıralamak için ana fonksiyon. _quicksort() fonksiyonunu çağırır
void Node::quickSort(Node *root)
{
    Node *r= lastNode(root);

    _quickSort(root, r);
}

void Node::basaEkle(Node** root_ref, int new_data){
    Node* new_node = new Node();//yeni bir bağlı liste oluşturulur

    new_node->data = new_data;//new_data değişkeni bağlı listeye eklenir

    new_node->next = (*root_ref);//root_ref' i bağlı listenin sonuna atar
    new_node->prev = NULL;//bağlı listenin önceki işaretçisine NULL atar

    if ((*root_ref) != NULL)
        (*root_ref)->prev = new_node;//root_ref'in prev konumunu new_node ile değiştirir

    (*root_ref) = new_node;//yeni düğümü(new_node) root_ref' eşitler
}


void Node::yazdir(Node *node)//yazdir() metodu ile düğümün tüm elemanları yazdırılır
{
    while (node != NULL)
    {
        cout<<" "<<node->data<<" ";//düğümdeki veriyi yazdırır
        node = node->next;//kök işaretçisi sonraki düğümü işaret eder
    }
}

int main()
{
    Node node;//fonksiyonları çağırmak için bir nesne oluşturulur
    Node *root = NULL;//düğüm oluşturulur

    node.basaEkle(&root, 5);//bağlı listeye 5,20,4,3,30 değerleri eklenir
    node.basaEkle(&root, 20);
    node.basaEkle(&root, 4);
    node.basaEkle(&root, 3);
    node.basaEkle(&root, 30);

    cout << "Sıralamadan once baglantili liste \n";
    node.yazdir(root);//listeyi yazdırır

    node.quickSort(root);//listeyi quick sort ile sıralar

    cout << "Sıralamadan sonra baglantili liste \n";
    node.yazdir(root);

    return 0;
}