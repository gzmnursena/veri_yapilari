#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;



// XOR bağlantılı listenin düğümü için veri yapısı
struct Node
{
	int data;
	Node* link;
};

//X ve y'nin XOR değerini döndürmek için fonksiyon
Node* XOR(Node *x, Node *y)
{
	return (Node*)((uintptr_t)(x) ^ (uintptr_t)(y));
}

// Listeyi ileri yönde hareket ettirmek için fonksiyon
void traverse(Node *head)
{
	Node *curr = head;
	Node *prev = nullptr;
	Node *next;

	while (curr != nullptr)
	{
		cout << curr->data << " -> ";

		// next düğüm, prev düğümün ve geçerli düğüm bağlantısının adresinden xor olur
		next = XOR(prev, curr->link);

		// döngünün bir next yinelemesi için prev ve curr işaretleyicilerini günceller
		prev = curr;
		curr = next;
	}

	cout << "nullptr";
}

//XOR bağlantılı listenin başına bir düğüm eklemek için fonksiyon
void push(Node* &headRef, int data)
{
	Node* newNode = new Node();//yeni bir liste düğümü oluşturur ve
	newNode->data = data;//düğümün verilerini atar

    /*yeni düğümün bağlantı alanı, başlangıçta yeni düğüm eklendiğinden
     geçerli başlığın XOR ve nullptr değeridir.*/
	newNode->link = XOR(headRef, nullptr);

	// bağlantılı liste boş değilse, geçerli headRef düğümünün değerini günceller
	if (headRef)
	{
       /* headRef-> link nullptr'in XOR ve bir sonraki düğümün adresidir
        Bir sonraki düğümün adresini almak için nullptr ile XOR*/
		headRef->link = XOR(newNode, XOR(headRef->link, nullptr));
	}

	// headRef işaretçisini günceller ve newNode düğüm değerini atar
	headRef = newNode;
}

int main()
{
	vector<int> keys = { 1, 2, 3, 4, 5 };//vector

	Node *head = nullptr;
	for (int i = keys.size() - 1; i >=0; i--)
		push(head, keys[i]);//listenin başına düğüm ekler

	traverse(head);//listeyi ileri yönde hareket ettirmeyi sağlar

	return 0;
}
