#include <iostream>

using namespace std;
//Bağlı listenin dairesel mi olduğunu kontrol eden program...
class Node{
public:
    int data;
    Node *next;
    bool daireselmi(Node *);
    Node *newNode(int);
};

bool Node::daireselmi(Node *root)
{
    if (root == NULL)//bagli liste boş ise return edilir
       return true;

    Node *node = root->next;

    while (node != NULL && node != root)
       node = node->next;//node listesini root listesine göre doldurur

    return (node == root);
    //iki liste eşitse (root dairesel liste oldugu için node'da elemanlar eklenince dairesel liste oluyorsa) true değerini döndürür
}

Node *Node::newNode(int data)
{
    Node *temp = new Node;//dinamik olarak bir düğüm oluşturulur
    temp->data = data;//düğümün datasına değeri atanır
    temp->next = NULL;//düğümün sonuna başka bir düğüm eklemek için
    return temp;
}

int main()
{
    Node node;
    Node* root = node.newNode(1);
    root->next = node.newNode(2);
    root->next->next = node.newNode(3);
    root->next->next->next = node.newNode(4);//root listesine yeni düğümler oluşturarak değer eklenir

    node.daireselmi(root)? cout << "Yes"<< endl ://liste dairesel mi?
                      cout << "No"<< endl ;

    root->next->next->next->next = root;

    node.daireselmi(root)? cout << "Yes"<< endl :
                      cout << "No"<< endl ;

    return 0;
}