#include <iostream>

using namespace std;

class Sinif{
public:
    int veri;
    Sinif()= default;

    Sinif(int gelenVeri): veri(gelenVeri) {
    }

    bool operator==(const Sinif& rhs){
        if(this->veri== rhs.veri){
            return true;
        }
        return false;
    }
};

std::ostream& operator<<(std::ostream& out, const Sinif& rhs)
{
    out << rhs.veri;
    return out;
}

template  <typename T>
class Queue {
    struct  node{
        T veri;
        node *onceki= {};
        node()= default;
        node(T gelenVeri): veri(gelenVeri) {
        }
        node(node&&)= default;
        node(const node&)= default;
        ~node()= default;
    };

    node *front;
    node *rear;
    int boyut;
    int kapasite;

public :
    Queue(int gelenBoyut){
        this->boyut = gelenBoyut;
        this->front = this->rear = nullptr;
        this->kapasite = this->boyut;

    }

    ~Queue(){
        delete front;
    }


    void enqueue(T gelenVeri) {
        if (this->isFull()) {
            cout << "Queue is Full!\n";
        }
        else if (this->isEmpty()) {
            this->front = new node(gelenVeri);
            this->rear = this->front;
            this->kapasite--;
        }
        else {
            node* temp = new node(gelenVeri);
            this->rear->onceki = temp;
            this->rear = temp;
            this->kapasite--;
        }
    }
    T dequeue() {
        if (this->isEmpty()) {
            cout << "Queue is Empty!\n";
            return NULL;
        }
        else {
            node* temp = this->front;
            this->front = this->front->onceki;
            this->kapasite++;
            return temp->veri;
        }
    }
    void display() {
        this->queuePrinter(this->front);
    }
    bool isFull() {
        if (this->kapasite == 0) {
            return true;
        }
        else
            return false;
    }
    bool isEmpty() {
        if (this->kapasite == this->boyut)
            return true;
        else
            return false;
    }
    void queuePrinter(node* temp) {
        if (temp == nullptr) {
            return;
        }
        cout << temp->veri << "\n";
        temp = temp->onceki;
        this->queuePrinter(temp);
    }
    T peek() {
        if (this->front == nullptr)
            return NULL;
        return this->front->veri;
    }
};

int main() {
    Queue<Sinif> test(300000);
    for (int i = 0; i < 300001; i++)
    {
        test.enqueue(Sinif(i + 1));
    }
    cout<<test.peek() << endl;
    for (int i = 0; i < 300001; i++)
    {
        test.dequeue();
    }
    test.display();
    cout<< test.peek() << endl;
    return 0;
}
