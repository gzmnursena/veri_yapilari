#include <iostream>
#include <vector>
using namespace std;

//Heap agacına dugum ekleme-dugum silme
class Heap{
public:
    void swap(int *, int *);
    void heapify(vector<int> &, int);
    void insert(vector<int> &, int);
    void deleteNode(vector<int> &, int);
    void printArray(vector<int> &);
};

void Heap::swap(int *a, int *b)//agactaki düğümlerin yerlerini değiştirmek için oluşturulan fonksiyon
{
  int temp = *b;
  *b = *a;
  *a = temp;
}
void Heap::heapify(vector<int> &heap, int i)//eklenen düğümün agaçta nerede duracağını belirleyen fonksiyon
{
  int size = heap.size();
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < size && heap[l] > heap[largest])
    largest = l;
  if (r < size && heap[r] > heap[largest])
    largest = r;

  if (largest != i)
  {
    swap(&heap[i], &heap[largest]);
    heapify(heap, largest);
  }
}
void Heap::insert(vector<int> &heap, int newNum)//agaca yeni dugum ekler
{
  int size = heap.size();//vectorun boyutunu bulur
  if (size == 0)//boyut 0 ise direkt agaca ekler
  {
      heap.push_back(newNum);//vektorun sonuna yeni dugumu ekler
  }
  else//boyut 0'dan farklı ise
  {
      heap.push_back(newNum);//vektorun sonuna yeni dugumu ekler
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(heap, i);//dugumun agactaki konumunu belirler
    }
  }
}
void Heap::deleteNode(vector<int> &heap, int num)
{
  int size = heap.size();//vectorun boyutunu bulur
  int i;
  for (i = 0; i < size; i++)
  {
    if (num == heap[i])//silinecek düğüm vektorun bir elemanı ise
      break;
  }
  swap(&heap[i], &heap[size - 1]);//vektorun elemanını en sona alır

  heap.pop_back();//vektorun sondaki elemanını siler
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapify(heap, i);//agacı düzenler
  }
}
void Heap::printArray(vector<int> &heap)//agacı yazdıran fonksiyon
{
  for (int i = 0; i < heap.size(); ++i)
    cout << heap[i] << " ";
  cout << endl;
}

int main()
{
    Heap tree;
    vector<int> heapTree;//agactaki elemanları tutmak için vector

    tree.insert(heapTree, 3);//ağaca düğümler eklenir
    tree.insert(heapTree, 4);
    tree.insert(heapTree, 9);
    tree.insert(heapTree, 5);
    tree.insert(heapTree, 2);

    cout << "Max-Heap: ";//max heap agacı oluşturur
    tree.printArray(heapTree);

    tree.deleteNode(heapTree, 4);//agactan 4 numaralı dugumu siler

    cout << "Düğüm silindikten sonra:  ";
    tree.printArray(heapTree);//agaci tekrar yazdırır
}