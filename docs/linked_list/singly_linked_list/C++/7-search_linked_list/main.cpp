#include <iostream>

using namespace std;

//Bağlı listede düğüm arama...
class Node//bir sınıf oluşturulur. Bu sınıf üzerinde data ve düğümün sonraki elemanlarını gösteren bir işaretçi ve fonksiyonlar tutulur.
{
public:
    int data;
    Node *next;
    void basaEkle(Node **, int);
    bool ara(Node *, int);
    void yazdir(Node *);
};

void Node::basaEkle(Node **root_ref, int new_data){
    Node* new_node = new Node();//Düğüm oluşturulur
    new_node->data = new_data;//Oluşturulan düğümün datasına gelen veri atanır
    new_node->next = (*root_ref);//Yeni düğümün next'ini kök olarak atar.
    (*root_ref) = new_node;//Kökü yeni düğümün işaretçisi olarak atar
}

bool Node::ara(Node *root, int aranan)
{
    while (root != NULL) {
        if (root->data == aranan)//eğer root'ta tutulan veri aranan değere eşit ise
            return true;//true döndür
        root = root->next;//eşit değilse bir sonraki düğüme geç
    }
    return false;//aranan değer bağlı listede yoksa false döndür
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
    int arananDeger = 11;

    node.basaEkle(&root, 10);//node nesnesi ile basaEkle() fonksiyonu çağırılarak root'un başına 10,30,11,21,14 değerleri eklenir
    node.basaEkle(&root, 30);
    node.basaEkle(&root, 11);
    node.basaEkle(&root, 21);
    node.basaEkle(&root, 14);
    node.yazdir(root);//bağlı liste yazdırılır

    node.ara(root, arananDeger)? cout<<"\nAranan deger "<< arananDeger <<" : Listede vardir" : cout<<"\nAranan deger "<< arananDeger <<": Listede yoktur";
   // ara() fonksiyonuna aranacak olan değer gönderilip true ise var false ise yok olarak mesaj yazdırılır
    return 0;
}