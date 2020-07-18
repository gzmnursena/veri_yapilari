#include <iostream>
#include <stdlib.h>

using namespace std;
//Listedeki sıralanmamış-tekrarlı düğümleri silme
class Node
{
public:
    int data;
    Node *next;
    void removeDuplicates(Node *);
    void yazdir(Node *);
    Node *newNode(int);
};

Node  *Node::newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void Node::removeDuplicates(Node *root)
{
    Node *ptr, *dup;

    while (root != NULL && root->next != NULL)
    {
        ptr = root;//oluşturulan ptr düğümüne root düğümünü atıyor

        while (ptr->next != NULL)
        {
            if (root->data == ptr->next->data)//eğer root düğümünün verisi ile ptr düğümünün sonraki elemanının verisi aynı ise
            {
                dup = ptr->next;//ptr düğümündeki elemanları dup isimli düğümde tutar
                ptr->next = ptr->next->next;//ptr düğümünü kopartıp ptr->next->next 'teki değeri ptr->next'e ekler
                delete(dup);//ptr->next; 'teki değeri siler
            }
            else
                ptr = ptr->next;//eğer root düğümünün verisi ile ptr düğümünün sonraki elemanının verisi aynı değilse düğümü ilerletir
        }
        root = root->next;
    }
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
    //10->12->11->11->12->11->10
    Node node;
    Node *root = node.newNode(10);//düğüme sırasıyla 10,12,11,11,12,11,10 değerlerini ekler
    root->next = node.newNode(12);
    root->next->next = node.newNode(11);
    root->next->next->next = node.newNode(11);
    root->next->next->next->next = node.newNode(12);
    root->next->next->next->next->next =node.newNode(11);
    root->next->next->next->next->next->next =node.newNode(10);

    cout<<"Bağlantılı Liste:\n";
    node.yazdir(root);//bağlı listeyi yazdırır

    node.removeDuplicates(root);//sıralanmamış bağlı listeden tekrarlı elemanları siler

    cout<<"\nYeni Bağlantılı Liste:\n";
    node.yazdir(root);//bağlı listenin son halini yazdırır

    return 0;
}