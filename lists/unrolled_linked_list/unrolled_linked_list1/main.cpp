#include <bits/stdc++.h>
using namespace std;
#define maxElements 4

//3 düğüm ile bir Unrolled Linked List oluşturan program...

// Unrolled Linked List Node
class Node
{
    public:
    int numElements;
    int array[maxElements];
    Node *next;
};

/* Unrolled Linked List yazdırma fonksiyonu
ve tüm elemanlarını yazdırır*/
void printUnrolledList(Node *n)
{
    while (n != NULL)
    {
        // geçerli düğümdeki elemanları yazdırma
        for (int i=0; i<n->numElements; i++)
            cout<<n->array[i]<<" ";

        //sonraki düğüme git
        n = n->next;
    }
}

int main()
{
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    // beklekten 3 düğüm tahsis eder
    head = new Node();
    second = new Node();
    third = new Node();

   /* ilk düğüme bazı değerler koyalım
    (Değer sayısı maxElement değerinden küçük veya ona eşit olmalıdır)*/
    head->numElements = 3;
    head->array[0] = 1;
    head->array[1] = 2;
    head->array[2] = 3;

    //ilk düğümü ikinci düğüme bağlar
    head->next = second;

    /*ikinci düğüme bazı değerler koyalım
     (Değer sayısı maxElement değerinden küçük veya ona eşit olmalıdır)*/
    second->numElements = 3;
    second->array[0] = 4;
    second->array[1] = 5;
    second->array[2] = 6;

    //ikinci düğümü üçüncü düğüme bağlar
    second->next = third;

    /*üçüncü düğüme bazı değerler koyalım
     (Değer sayısı, maksimum Öğe'den küçük veya ona eşit olmalıdır)*/
    third->numElements = 3;
    third->array[0] = 7;
    third->array[1] = 8;
    third->array[2] = 9;
    third->next = NULL;

    printUnrolledList(head);

    return 0;
}
