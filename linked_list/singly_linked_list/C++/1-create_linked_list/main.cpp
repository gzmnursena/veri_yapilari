#include <iostream>
#include <stdlib.h>

using namespace std;

//Bağlı liste oluşturma...
class Node { //bir düğüm oluşturulur. Bu düğüm üzerinde data ve düğümün sonraki elemanlarını gösteren bir işaretçi ve fonksiyonlar tutulur.
public:
    int data;
    Node* next;
    void yazdir(Node *);
};


void Node::yazdir(Node *node) //yazdir() metodu ile düğümün tüm elemanları yazdırılır
{
    while (node != NULL) {
        cout << node->data << "  ";//düğümdeki veriyi yazdırır
        node = node->next;//kök işaretçisi sonraki düğümü işaret eder
    }
}

int main()
{
    //Düğüm ile root oluşturma:
    Node *root1 = NULL;//3 tane root tanımlandı ve şimdilik biryeri işeret etmiyorlar
    Node *root2 = NULL;
    Node *root3 = NULL;

    root1 = new Node();//root'lar için bellekten yer ayrıldı
    root2 = new Node();
    root3 = new Node();

    root1->data = 1;//root1'in datasına değer atandı
    root1->next = root2;//root1'in next'i artık root2'yi işaret ediyor

    root2->data = 2;//root2'nin datasına değer atandı
    root2->next = root3;//root2'nin next'i artık root3'ü işaret ediyor

    root3->data = 3;//root3'ün datasına değer atandı
    root3->next = NULL;//bir daha değer ataması yapılmadığı için son root'un next'i NULL'dur

    Node nesne;
    nesne.yazdir(root1);//oluşturulan düğüm Node sınıfından nesne oluşturularak yazdir() metodu ile yazdırılır


    cout<<endl;
    cout<<root1->data<<"  ";
    cout<<root1->next->data<<"  ";
    cout<<root1->next->next->data<<endl;
    //düğümü yazdırırken başlangıç root'unun datasını yazdırıp daha sonra root'un sonraki düğümünün datasını yazdırabiliriz

    Node *iter=root1;//yada başlangıç root'unu(root1) iter adında bir Node tipindeki değişkene atarak
    while(iter!=NULL){//son düğüme kadar
        cout<<iter->data<<"  ";//iter'in datasını yazdırabiliriz
        iter=iter->next;//iter'i her yazdırdığımızda next ile sonraki düğümü işaret etmemiz gerekir
    }

    return 0;
}