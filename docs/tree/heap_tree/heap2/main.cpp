#include<iostream>
#include<climits>
using namespace std;

//Heap agacında indekse gore düğüm silme

//agactaki düğümlerin yerlerini değiştirmek için oluşturulan fonksiyon
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

class Min_Heap
{
    int *heaparr; // agactaki elemanları tutmak için işaretci
    int capacity; // agacın kapasitesi
    int heap_size; // agacın boyutu
public:
    Min_Heap(int cap){
        heap_size = 0;
        capacity = cap;
        heaparr = new int[capacity];

    }

    // bir alt ağacı, belirli bir dizinde kök ile yığınlamak için
    void MinHeapify(int );

    int parent(int i) { return (i-1)/2; }

    //sol alt düğüm  i
    int left(int i) { return (2*i + 1); }

    //sag alt dugum i
    int right(int i) { return (2*i + 2); }


    int extractMin();  //yığının kökü

    // anahtar değerini i'de newKey'e düşür
    void decreaseKey(int i, int newKey);

    //agactaki min köku dondurur
    int getMin() { return heaparr[0]; }

    //i.dugumu siler
    void deleteKey(int i);

    //yeni dugum ekler
    void insertKey(int key);
    void displayHeap(){
        for(int i = 0;i<heap_size;i++)
            cout<<heaparr[i]<<" ";

        cout<<endl;

    }
};

//yeni bir dugum ekler
void Min_Heap::insertKey(int key)
{
    if (heap_size == capacity)  {
        cout << "\nAgacta Taşma\nDüğüm Eklenemedi\n";
        return;
    }
    // önce yeni dugumu sona ekler
    heap_size++;
    int i = heap_size - 1;
    heaparr[i] = key;

    while (i != 0 && heaparr[parent(i)] > heaparr[i])
    {
       swap(&heaparr[i], &heaparr[parent(i)]);//
       i = parent(i);
    }
}

void Min_Heap::decreaseKey(int i, int newKey) {
    heaparr[i] = newKey;
    while (i != 0 && heaparr[parent(i)] > heaparr[i])  {
       swap(&heaparr[i], &heaparr[parent(i)]);
       i = parent(i);
    }
}
  int Min_Heap::extractMin(){
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)   {
        heap_size--;
        return heaparr[0];
    }
    // Minimum dğümdeki değeri saklar, düğümden siler
    int root = heaparr[0];
    heaparr[0] = heaparr[heap_size-1];
    heap_size--;
    MinHeapify(0);

    return root;
}

void Min_Heap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

void Min_Heap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int min = i;
    if (l < heap_size && heaparr[l] < heaparr[i])
        min = l;
    if (r < heap_size && heaparr[r] < heaparr[min])
        min = r;
    if (min != i)
    {
        swap(&heaparr[i], &heaparr[min]);
        MinHeapify(min);
    }
}

int main()
{
    Min_Heap heap(11);//agacın kapasitesi constructor ile belirlenir
    heap.insertKey(2);//agaca dugumler ekelr
    heap.insertKey(4);
    heap.insertKey(6);
    heap.insertKey(8);
    heap.insertKey(10);
    heap.insertKey(12);
    cout<<"Düğüm eklendiktan sonra Head-Ağacı: ";
    heap.displayHeap();//
    cout<<"Agacın kök(root) elemanı: "<<heap.getMin()<<endl; //agactaki kök elemanını döndürür.
    heap.deleteKey(2);
    cout<<"Düğüm silindikten sonra Head-Ağacı: ";
    heap.displayHeap();
    cout <<"Agaçtaki minimum değerli düğüm: "<< heap.extractMin() <<endl;//Minimum düğümü agactan kaldırır.
    heap.decreaseKey(1, 1);
    cout <<"yeni kök:  "<< heap.getMin()<<endl; //agactaki kök elemanını döndürür.

    return 0;
}