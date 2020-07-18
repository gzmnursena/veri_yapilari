#include <iostream>
#include<stdlib.h>
#include <assert.h>
using namespace std;
//Bağlı listede indekse göre eleman arama...
class Node//bir sınıf oluşturulur. Bu sınıf üzerinde data ve düğümün sonraki elemanlarını gösteren bir işaretçi ve fonksiyonlar tutulur.
{
public:
    int data;
    Node *next;
    void basaEkle(Node **, int);
    int arananIndex(Node *, int);
    void yazdir(Node *);
};

void Node::basaEkle(Node **root_ref, int new_data){
    Node* new_node = new Node();//Düğüm oluşturulur
    new_node->data = new_data;//Oluşturulan düğümün datasına gelen veri atanır
    new_node->next = (*root_ref);//Yeni düğümün next'ini kök olarak atar.
    (*root_ref) = new_node;//Kökü yeni düğümün işaretçisi olarak atar
}

int arananIndex(Node *root, int index)
{
    int sayac = 0;//döndürülecek index sayac değişkeninde tutulur
    while (root != NULL)
    {
        if (sayac == index)
            return(root->data);//sayac değişkeni aranan index değerine eşit ise düğümdeki veriyi return eder
        sayac++;//sayac değişkeni aranan index değerine eşit değilse sayac döngü her döndüğünde arttırılır
        root = root->next;//root'ta bir sonraki düğümü gösterir
    }
    assert(0); // aranan index yoksa ekrana hata mesajını yazar.
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
    Node node;//fonksiyonları çağırmak için bir nesne oluşturulur
    Node *root = NULL;//düğüm oluşturulur
    int index=1;//aranacak olan index
    int index2=5;

    node.basaEkle(&root, 5);//node nesnesi ile basaEkle() fonksiyonu çağırılarak root'un başına 5,4,3,2,1 değerleri eklenir
    node.basaEkle(&root, 4);
    node.basaEkle(&root, 3);
    node.basaEkle(&root, 2);
    node.basaEkle(&root, 1);
    cout<<"Bağlı Liste"<<endl;
    node.yazdir(root);//oluşturulan linked list yazdırılır

    cout << "\n"<< index <<". indexteki eleman= " << arananIndex(root, index);
    cout << "\n"<< index2 <<". indexteki eleman= " << arananIndex(root, index2);
    //aranan index var ise o indexteki elemanı yazar yok ise assert(0); ile hata mesajı verir
    return 0;
}
