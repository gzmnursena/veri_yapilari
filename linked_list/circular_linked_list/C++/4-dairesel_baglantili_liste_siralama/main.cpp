#include <iostream>

using namespace std;
//Dairesel bağlı listeyi sıralama...
class Node{//bir sınıf oluşturulur. Bu sınıf üzerinde data ve düğümün sonraki elemanlarını gösteren bir işaretçi ve fonksiyonları tutulur.
public:
    int data;
    Node *next;
    void siraliEkle(Node **, Node *);
    void yazdir(Node *);
};

//bir listeye sıralı bir şekilde yeni düğüm eklemek için kullanılan fonksiyon

void Node::siraliEkle(Node **root_ref, Node *new_node)
{
    Node *current = *root_ref;//Bu fonksiyon, giriş bağlantılı listenin başını değiştirebileceğinden, root düğümüne bir işaretçi bekler

    if (current == NULL){//bagli liste boş ise
        new_node->next = new_node;//yeni düğümü ekler
        *root_ref = new_node;
    }

    else if (current->data >= new_node->data){//
       //yeni düğümdeki veri, root'ta bulunan veriden daha küçükse veya eşitse, son düğümün yanında değişiklik yapmamız gerekir
        while(current->next != *root_ref)
            current = current->next;
        current->next = new_node;//son düğüme eklenecek olan yeni düğüm bağlanır
        new_node->next = *root_ref;
        *root_ref = new_node;
    }

    else{//yeni düğümdeki veri, root'ta bulunan veriden daha büyükse
        //eklemeden önce yeni düğümün bağlanacağı düğüm bulunur
        while (current->next!= *root_ref &&
               current->next->data < new_node->data)
            current = current->next;

        new_node->next = current->next;
        current->next = new_node;//yeni düğüme değer eklenir
    }
}

void Node::yazdir(Node *root)//yazdir() metodu ile düğümün tüm elemanları yazdırılır
{
    Node *temp = root;//dairesel bagli listede düğümlerin tekrarlanmaması için temp isimli düğümde root düğümü saklanır
    if (root != NULL){
        do{
            cout << temp->data << " ";//düğümdeki veriyi yazdırır
            temp = temp->next;//kök işaretçisi sonraki düğümü işaret eder
        }while (temp != root);
    }
}

int main()
{
    int arr[] = {12, 56, 2, 11, 1, 90};

    Node node;
    Node *root = NULL;
    Node *temp;


    //1 ->2->11->12->56->90
    for (int i = 0; i< 6; i++)
    {
        temp = new Node();//Dinamik olarak bir düğüm oluşturulur
        temp->data = arr[i];//oluşturulan düğümün datasına dizinin i.elemanı eklenir
        node.siraliEkle(&root, temp);//eklenen elemanlar arttıkça düğümlerin sirali eklenmesini siraliEkle() fonksiyonu sağlar.
    }

    node.yazdir(root);//bağlı liste yazdırılır

    return 0;
}