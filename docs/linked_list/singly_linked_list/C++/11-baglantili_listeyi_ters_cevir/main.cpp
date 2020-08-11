#include <iostream>
#include<stdlib.h>

using namespace std;
//Listenin tersini bulan program...
class Node {
public:
    int data;
    Node* next;

    Node(int data)//constructor
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList {
    Node *root;
    LinkedList()
    {
        root = NULL;
    }

    void tersCevir()
    {
        Node *kok = root;
        Node *onceki = NULL, *sonraki = NULL;

        while (kok != NULL) {//son eleman ile bir önceki elemanın yerlerini değiştirerek bağlı listeyi tamamlar.
            sonraki = kok->next;

            kok->next = onceki;

            onceki = kok;
            kok = sonraki;
        }
        root = onceki;
    }

    void yazdir()//yazdir() metodu ile düğümün tüm elemanları yazdırılır
    {
        Node* temp = root;
        while (temp != NULL) {
            cout << temp->data << " ";//düğümdeki veriyi yazdırır
            temp = temp->next;//kök işaretçisi sonraki düğümü işaret eder
        }
    }

    void basaEkle(int data)
    {
        Node* temp = new Node(data);//Düğüm oluşturulur
        temp->next = root;//Oluşturulan düğümüe root'u atar
        root = temp;//Kökü yeni düğümün işaretçisi olarak atar
    }
};


int main()
{
    LinkedList liste;
    liste.basaEkle(20);//listenin başına 20,4,15,85 değerleri ekler
    liste.basaEkle(4);
    liste.basaEkle(15);
    liste.basaEkle(85);

    cout << "Bağlantılı Liste:\n";
    liste.yazdir();//bağlantılı listeyi yazdırır

    liste.tersCevir();//tersCevir() metodunu çağırır

    cout << "\nTers Bağlantılı Liste:\n";
    liste.yazdir();
    return 0;
}