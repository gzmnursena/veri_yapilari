#include <iostream>
#include <bits/stdc++.h>

using namespace std;
//Çift yönlü bağlı listeyi sıralama
class Node {
public:
    int data;
    Node *next;
    Node *prev;
    struct compare;
    Node *sirala(Node *, int);
    void basaEkle(Node **, int);
    void yazdir(Node *);
};

struct Node::compare {
    bool operator()(Node *p1, Node *p2) {
        return p1->data > p2->data;
    }
};

Node *Node::sirala(Node *root, int dugumSayisi)
{
    if (root == NULL)//bağlı liste NULL ise hiçbir işlem yapmadan fonksiyondan çıkar
        return root;

    priority_queue<Node*, vector<Node*>, compare> pq;

    Node *newRoot = NULL, *last;

    for (int i = 0; root != NULL && i <= dugumSayisi; i++) {//priority_queue'ye bağlı listenin elemanları eklenir
        pq.push(root);
        root = root->next;
    }

    while (!pq.empty()) {//priority_queue boş değilse

        if (newRoot == NULL) {//newRoot baglı listesi NULL ise
            newRoot = pq.top();//pq'deki en yüksek elemanı newRoot'a eşitler
            newRoot->prev = NULL;//newRoot'un önceki düğümüne NULL atar
            last = newRoot;//last listesine newRoot listesini atar
        }

        else {//newRoot baglı listesi NULL değilse
            last->next = pq.top();//pq'deki en yüksek elemanı last listesinin son düğümüne ekler
            pq.top()->prev = last;//last listesini pq'deki en yüksek elemanın önündeki düğüme ekler
            last = pq.top();//pq'deki en yüksek elemanı last listesine atar
        }

        pq.pop();//pq'nun başındaki elemanı siler

        if (root != NULL) {
            pq.push(root);//root'u priority_queue(pq)'ya ekler
            root = root->next;
        }
    }
    last->next = NULL;

    return newRoot;//doldurulan bağlı liste return edilir
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
    if (node == NULL)
        cout << "Cift katli bagli liste bos!!!";
    while (node != NULL)
    {
        cout<<" "<<node->data<<" ";//düğümdeki veriyi yazdırır
        node = node->next;//kök işaretçisi sonraki düğümü işaret eder
    }
}

int main()
{
    Node node;
    Node *root = NULL;

    //3<->6<->2<->12<->56<->8
    node.basaEkle(&root, 8);//bağlı listenin  başına 8,56,12,2,6,3 değerleri eklenir
    node.basaEkle(&root, 56);
    node.basaEkle(&root, 12);
    node.basaEkle(&root, 2);
    node.basaEkle(&root, 6);
    node.basaEkle(&root, 3);

    int dugumSayisi = 5;

    cout << "Bagli liste:\n";
    node.yazdir(root);//bağlı listeyi yazdırır

    root = node.sirala(root, dugumSayisi);//bağlı liste sirala fonksiyonu ile sıralanır

    cout << "\nSirali bagli liste:\n";
    node.yazdir(root);

    return 0;
}