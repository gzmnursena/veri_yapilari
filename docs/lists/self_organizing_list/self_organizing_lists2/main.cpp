#include <iostream>
using namespace std;

//move to front yöntemi ile aranan düğümü başa alma

//self organizing list sınıfı
class self_list {
public:
    int value;
    self_list* next;

    self_list(int value)//constructor
    {
        this->value = value;
        next = NULL;
    }
};

//head ve rear listenin başlangıcını ve sonunu gösterir.
self_list *head = NULL, *rear = NULL;


// eleman ekleme fonksiyonu
void insert_self_list(int number)
{
    //dugum olusturma
    self_list* temp = new self_list(number);

    //oluşturulan düğüme değer atama
    temp->value = number;
    temp->next = NULL;

    if (head == NULL)// listenin ilk elemanı ise
        head = rear = temp;


    else {//listenin geri kalan elemanları
        rear->next = temp;
        rear = temp;
    }
}

//fonksiyonu listesinde anahtar arama ve yeniden düzenlemek için self-organizing list
bool search_self_list(int key)
{
    self_list* current = head;//geçerli düğüme işaretçi atar

    self_list* prev = NULL;//önceki düğüme işaretçi atar

    // anahtar arama
    while (current != NULL) {

        if (current->value == key) {//anahtar bulunursa

            if (prev != NULL) {//anahtar ilk öğe değilse

                /* elemanların yeniden düzenlenir*/
                prev->next = current->next;
                current->next = head;
                head = current;
            }
            return true;
        }
        prev = current;
        current = current->next;
    }

    //anahtar bulunamadı
    return false;
}


//listenin yazdırılması
void display()
{
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    // head'i gösteren geçici işaretçi
    self_list* temp = head;
    cout << "List: ";

    //sırayla düğümleri görüntüleme
    while (temp != NULL) {
        cout << temp->value;
        if (temp->next != NULL)
            cout << " --> ";

        // sonraki düğümleri gösteren işaretçi
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    /* listeye 5 tane eleman ekler */
    insert_self_list(1);
    insert_self_list(2);
    insert_self_list(3);
    insert_self_list(4);
    insert_self_list(5);

    // listeyi yazdırır
    display();

    // 4'ü arar ve bulunursa yeniden düzenler
    if (search_self_list(4))
        cout << "Searched: 4" << endl;
    else
        cout << "Not Found: 4" << endl;

    // listeyi yazdırır
    display();

    // 2'yi arar ve bulunursa yeniden düzenler
    if (search_self_list(2))
        cout << "Searched: 2" << endl;
    else
        cout << "Not Found: 2" << endl;
    display();

    return 0;
}