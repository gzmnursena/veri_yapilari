#include <iostream>

using namespace std;
//merge sort ile bağlı listeyi sıralama
class Node
{
public:
    int data;
    Node *next, *prev;
    Node *split(Node *);
    Node *merge(Node *, Node *);
    Node *mergeSort(Node *);
    void insert(Node **, int);
    void yazdir(Node *);
    void swap(int *, int *);
};

//bağlı iki listeyi birleştiren fonksiyon
Node *Node::merge(Node *first, Node *second)
{
    if (!first)//ilk bağlı liste boşsa
        return second;

    if (!second)//ikinci bağlı liste boşsa
        return first;

    if (first->data < second->data)//ilk bağlı listedeki değer ikinci bağlı listedeki değerden daha küçük ise
    {
        first->next = merge(first->next,second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else//ikinci bağlı listedeki değer ilk bağlantılı listedeki değerden daha küçük ise
    {
        second->next = merge(first,second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}
//mergeSort sıralaması yapan fonksiyon
Node *Node::mergeSort(Node *root)
{
    if (!root || !root->next)
        return root;
    Node *second = split(root);

    //Sol ve sağ yarılar için tekrar aynı işlemleri yapar
    root = mergeSort(root);
    second = mergeSort(second);

    //Sıralanan iki yarıyı birleştirir
    return merge(root,second);
}
//çift bağlı listenin başında yeni bir düğüm eklemek için oluşturulan fonksiyon
void Node::insert(Node **root, int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = temp->prev = NULL;
    if (!(*root))
        (*root) = temp;
    else
    {
        temp->next = *root;
        (*root)->prev = temp;
        (*root) = temp;
    }
}

void Node::yazdir(Node *root)
{
    Node *temp = root;
    cout<<"kucukten->buyuge\n";
    while (root)
    {
        cout << root->data << " ";
        temp = root;
        root = root->next;
    }
    cout  << "\nbuyukten->kucuge\n";
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
}

//iki tamsayıyı değiştirmek için fonksiyon
void Node::swap(int *A, int *B)
{
    int temp = *A;
    *A = *B;
    *B = temp;
}

//çift katlı bağlı listeyi bölmek için fonksiyon
Node *Node::split(Node *head)
{
    Node *fast = head,*slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *temp = slow->next;
    slow->next = NULL;
    return temp;
}

int main(void)
{
    Node node;
    Node *root = NULL;

    node.insert(&root, 5);//bağlı listeye 5,0,4,3,30,10 değerlerini ekler
    node.insert(&root, 20);
    node.insert(&root, 4);
    node.insert(&root, 3);
    node.insert(&root, 30);
    node.insert(&root, 10);
    cout << "Bagli liste\n";
    node.yazdir(root);//listeyi yazdırır
    root = node.mergeSort(root);//bağlı listeyi merge sort ile sıralar
    cout << "\nSiralamadan sonra bagli liste\n";
    node.yazdir(root);
    return 0;
}