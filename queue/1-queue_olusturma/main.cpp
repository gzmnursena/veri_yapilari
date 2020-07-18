#include <iostream>

using namespace std;
#define INT_MIN 100

//Queue ilk giren ilk çıkar mantığı ile çalışır

class Queue{
public:
    int on, arka, boyut;
    int kapasite;
    int *dizi;
    Queue* createQueue(int);
    int isFull(Queue*);
    int isEmpty(Queue*);
    void enqueue(Queue *, int);
    int dequeue(Queue*);
    int front(Queue*);
    int rear(Queue*);
};

Queue* Queue::createQueue(int kapasite){
    Queue* kuyruk = new Queue();//yeni bir kuyruk oluşturur
    kuyruk->kapasite = kapasite;//kuyruğun kapasitesine fonksiyondan gelen kapasite değerini atar
    kuyruk->on = kuyruk->boyut = 0;
    kuyruk ->arka = kapasite - 1;
    kuyruk->dizi = new int[(kuyruk->kapasite * sizeof(int))];
    return kuyruk;
}

int Queue::isFull(Queue* kuyruk){//kuyruğun dolu olup olmadığını kontrol eder
    return (kuyruk->boyut == kuyruk->kapasite); //kuyruk dolu ise boyutunu kapasite değeri döndürür
}

int Queue::isEmpty(Queue* kuyruk){//kuyruğun boş olup olmadığını kontrol eder
    return (kuyruk->boyut == 0); //kuyruk boş ise boyutu 0 döndürür
}


void Queue::enqueue(Queue *kuyruk, int item){//kuyruğun arkasına yeni bir eleman ekler
    if (isFull(kuyruk))
        return;
    kuyruk->arka = (kuyruk->arka + 1) % kuyruk->kapasite;
    kuyruk->dizi[kuyruk->arka] = item;
    kuyruk->boyut = kuyruk->boyut + 1;
    cout << item << " kuyruga eklendi"<< endl;
}

int Queue::dequeue(Queue* kuyruk){//kuyruğun önündeki elemanı kaldırır
    if (isEmpty(kuyruk))
        return INT_MIN;
    int item = kuyruk->dizi[kuyruk->on];
    kuyruk->on = (kuyruk->on + 1) % kuyruk->kapasite;
    kuyruk->boyut = kuyruk->boyut - 1;
    return item;
}

int Queue::front(Queue* kuyruk){//front(): kuyrukta en öndeki elemanı tutar
    if (isEmpty(kuyruk))
        return INT_MIN;
    return kuyruk->dizi[kuyruk->on];//kuyruk boş değilse en öndeki elemanı döndürür
}


int Queue::rear(Queue* kuyruk){//rear(): kuyruğun en sonundaki elemanı tutar
    if (isEmpty(kuyruk))
        return INT_MIN;
    return kuyruk->dizi[kuyruk->arka];//kuyruk boş değilse en sondaki elemanı döndürür
}


int main()
{
    Queue queue;
    Queue* kuyruk = queue.createQueue(1000);//dinamik ve 1000 kapasiteli bir kuyruk oluşturur

    queue.enqueue(kuyruk, 10);//kuyruğun arkasına sırasıyla 10,20,30,40 değerlerini ekler
    queue.enqueue(kuyruk, 20);
    queue.enqueue(kuyruk, 30);
    queue.enqueue(kuyruk, 40);

    cout<<queue.dequeue(kuyruk)<<" kuyruktan kaldirildi"<< endl;//kuyruğun önündeki elemanı kaldırır

    cout << "ondeki(front) eleman " << queue.front(kuyruk) << endl;//kuyrukta en öndeki elemanı verir
    cout << "arkadaki(rear) eleman " << queue.rear(kuyruk) << endl;//kuyruğun en sonundaki elemanı verir

    return 0;
}
