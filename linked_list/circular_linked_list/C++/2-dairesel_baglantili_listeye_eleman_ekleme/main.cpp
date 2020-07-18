#include <iostream>

using namespace std;
//Dairesel bağlı listeye düğüm ekleme...
class Node{//bir sınıf oluşturulur. Bu sınıf üzerinde data ve düğümün sonraki elemanlarını gösteren bir işaretçi ve fonksiyonları tutulur.
public:
    int data;
    Node *next;
    Node *bosListeyeEkle(Node *, int);
    Node *basaEkle(Node *, int);
    Node *sonaEkle(Node *, int);
    Node *dugumunSonunaEkle(Node *, int , int);
    void yazdir(Node *);
};

//Bu fonksiyon sadece boş liste için kullanılır
Node *Node::bosListeyeEkle(Node *son, int data)
{
    if (son != NULL)
        return son;

    Node *temp = new Node();//Dinamik olarak bir düğüm oluşturulur
    //Verileri atama
    temp -> data = data;
    son = temp;

    son -> next = son;//Bağlı liste oluşturulur
    return son;
}

Node *Node::basaEkle(Node *son, int data)
{
    if (son == NULL)//ilk düğümü eklerken; boş listeye eklendiği için bosListeyeEkle() fonksiyonunu çağırıyoruz
        return bosListeyeEkle(son, data);

    Node *temp = new Node();//Dinamik olarak bir düğüm oluşturulur

    //Verilerin atanması
    temp -> data = data;
    //Düğüm bağlantılarının ayarlanması
    temp -> next = son -> next;
    son -> next = temp;
    return son;
}

Node *Node::sonaEkle(Node *son, int data)
{
    if (son == NULL)//ilk düğümü eklerken; boş listeye eklendiği için bosListeyeEkle() fonksiyonunu çağırıyoruz
        return bosListeyeEkle(son, data);

    Node *temp = new Node();//Dinamik olarak bir düğüm oluşturulur
    //Verilerin atanması
    temp -> data = data;

    //Düğüm bağlantılarının ayarlanması
    temp -> next = son -> next;
    son -> next = temp;
    son = temp;
    return son;
}

Node *Node::dugumunSonunaEkle(Node *son, int data, int item)
{
    if (son == NULL)
        return NULL;

    Node *temp, *p;
    p = son -> next;
    //Sonuna veri eklenecek düğümü arar
    do{
        if (p ->data == item){
            temp = new Node();//Dinamik olarak bir düğüm oluşturulur
            //Verilerin atanması
            temp -> data = data;
            //Düğüm bağlantılarının ayarlanması
            temp -> next = p -> next;
            //Oluşturulan düğümün sonuna yeni düğüm ekleniyor
            p -> next = temp;

            if (p == son)//Son düğüm kontrolu yapılıyor
                son = temp;
            return son;
        }
        p = p -> next;//tüm düğümler dolaşılır
    }while(p != son -> next);

    cout << item << " listede yok\n" << endl;
    return son;

}

void Node::yazdir(Node *son)
{
    Node *p;

    if (son == NULL){//liste boşsa, return edilir
        cout << "liste bos\n" << endl;
        return;
    }

    p = son -> next;//bagli listenin ilk düğümünü işaret eder

    //bagli listede dolaşmayı sağlar
    do{
        cout << p -> data << " ";
        p = p -> next;

    }while(p != son->next);

}

int main()
{
    /*İlk olarak boş olan bağlı listeye bir düğüm eklenir.
    Daha sonra listenin başına,sonuna,ve bir düğümden sonra veri eklenerek dairesel bağlı liste yazdırılır*/
    Node node;
    Node *son = NULL;
    son = node.bosListeyeEkle(son, 6);
    son = node.basaEkle(son, 4);
    son = node.basaEkle(son, 2);
    son = node.sonaEkle(son, 8);
    son = node.sonaEkle(son, 12);
    son = node.dugumunSonunaEkle(son, 10, 8);
    node.yazdir(son);

    return 0;
}