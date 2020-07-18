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
        return true;}
        return false;
    }
};

std::ostream& operator<<(std::ostream& out, const Sinif& rhs)
{
    out << rhs.veri;
    return out;
}

template  <typename T>
class Stack {
    struct  node{
        T veri;
        node *onceki;
        node()= default;
        node(T gelenVeri): veri(gelenVeri) {
        }
        node(node&&)= default;
        node(const node&)= default;
        ~node()= default;
    };

    node *root;
    node *SP;
    int boyut;
    int kapasite;

public :
    Stack(int gelenBoyut){
    this->root=nullptr;
    this->boyut=gelenBoyut;
    this->SP=this->root;
    this->kapasite=this->boyut;
}

~Stack(){
    delete root;
}

    void push(T gelenVeri) {
        if (this->isFull()) {
            std::cout << "Yigin tasmasi!"<< endl;
        }
        else {
            node* temp = new node(gelenVeri);
            temp->onceki = this->SP;
            this->SP = temp;
            this->kapasite--;
        }
    }
    T pop() {
        if (this->isEmpty()) {
            cout << "Yigin bos!"<< endl;
            return NULL;
        }
        else {
            node* temp = this->SP;
            this->SP = this->SP->onceki;
            this->kapasite++;
            return temp->veri;
        }
    }
    void display() {
        this->stackPrinter(this->SP);
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
    void stackPrinter(node* temp) {
        if (temp == nullptr) {
            return;
        }
        cout<<temp->veri << endl;
        temp = temp->onceki;
        this->stackPrinter(temp);
    }
    T peek() {
        if (this->SP == nullptr)
            return 0;
        return this->SP->veri;
    }
};

int main() {
    Stack<Sinif> test(300000);
    for (int i = 0; i < 30; i++)
    {
        test.push(Sinif(i + 1));
    }
    cout<<test.peek() << endl;
    for (int i = 0; i < 30; i++)
    {
        test.pop();
    }
    test.display();
    cout<< test.peek() << endl;
    return 0;
}
