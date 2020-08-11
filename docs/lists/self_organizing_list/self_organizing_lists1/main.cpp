#include <iostream>
using namespace std;

//count yöntemi ile aranan düğümün sayısını arttırma

//self organizing list sınıfı
class self_list {
public:
    int value;
    int count;
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
    temp->count = 0;
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

            current->count = current->count + 1;//düğüm sayısını artırır

            if (current != head) {///eğer ilk eleman değilse
                self_list* temp = head;
                self_list* temp_prev = NULL;

                while (current->count < temp->count) {//aranan düğümü düzenlemek için yerini bulur
                    temp_prev = temp;
                    temp = temp->next;
                }

                // aranan düğümü düzenlemek için yer bulmak
                if (current != temp) {
                    prev->next = current->next;
                    current->next = temp;

                    if (temp == head)//eğer başlangıca yerleştirilecekse
                        head = current;
                    else
                        temp_prev->next = current;
                }
            }
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

// listenin yazdırılması
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
        cout << temp->value << "(" << temp->count << ")";
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

    //listeyi yazdırır
    display();

    search_self_list(4);
    search_self_list(2);
    display();

    search_self_list(4);
    search_self_list(4);
    search_self_list(5);
    display();

    search_self_list(5);
    search_self_list(2);
    search_self_list(2);
    search_self_list(2);
    display();
    return 0;
}