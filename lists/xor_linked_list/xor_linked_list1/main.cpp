#include <bits/stdc++.h>
#include <inttypes.h>
using namespace std;

//XOR linked list oluşturma...

/*bellek verimli çift bağlantılı bir listenin
(memory efficient doubly linked list) düğüm yapısı*/
class Node
{
public:
    int data;
    Node* npx; //sonraki ve önceki düğümün XOR değeri
};

//düğüm adreslerinin XORed değerini döndürür
Node* XOR (Node *a, Node *b)
{
    return (Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}

/*XORed bağlantılı listesinin başına bir düğüm ekler
 ve yeni eklenen düğümü head_ref olarak yapar*/
void insert(Node **head_ref, int data)
{
    //yeni düğüm için bellek ayırma
    Node *new_node = new Node();
    new_node->data = data;

    /* Yeni düğüm başlangıçta eklendiğinden, yeni düğümün
    npx değeri her zaman geçerli başlığın XOR ve NULL olur */
    new_node->npx = XOR(*head_ref, NULL);

    /* Bağlantılı liste boş değilse, geçerli baş düğümün npx değeri,
     yeni başlığın ve yeni başlığın yanındaki düğümün XOR değeri olacaktır. */
    if (*head_ref != NULL)
    {
        // *(head_ref)->npx  XOR, NULL ve next.
        //  XOR'u NULL ile yaparsak,
        Node* next = XOR((*head_ref)->npx, NULL);
        (*head_ref)->npx = XOR(new_node, next);
    }

    *head_ref = new_node;  // head_ref'i new_node olarak değiştirir
}

//çift bağlantılı listeyi ileri yönde yazdırır
void printList (Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *next;

    cout << "XOR Linked List: \n";

    while (curr != NULL)
    {
        // current düğümünün datasını yazdırır
        cout<<curr->data<<" ";

        /*sonraki düğümün adresini al: curr-> npx next ^ prev, bu yüzden curr-> npx ^ prev olacak next ^ prev ^ prev sonraki olan*/
        next = XOR (prev, curr->npx);

        // sonraki yinelemeler için prev ve next değerlerini guncelle
        prev = curr;
        curr = next;
    }
}

int main ()
{
    /* çift bağlı liste oluşturulur
    head-->40<-->30<-->20<-->10 */
    Node *head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);

    // oluşturulan listeyi yazdırılır
    printList (head);

    return (0);
}
