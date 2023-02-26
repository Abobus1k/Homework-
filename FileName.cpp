#include <fstream>
#include <iostream>
using namespace std;

const int MAX_SIZE = 52; 

class Queue {
private:
    int front; 
    int rear;  
    int arr[MAX_SIZE]; 

public:
    Queue() { 
        front = -1;
        rear = -1;
        for (int i = 0; i < MAX_SIZE; i++) {
            arr[i] = 0;
        }
    }

    bool isEmpty() const {
        return (front == -1 && rear == -1);
    }

    bool isFull() const {
        return ((rear + 1) % MAX_SIZE == front);
    }

    void inqueue(int val) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
            arr[rear] = val;
        }
        else {
            rear = (rear + 1) % MAX_SIZE;
            arr[rear] = val;
        }
    }

    int outqueue() {
        int x;
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return 0;
        }
        if (front == rear) {
            x = arr[front];
            arr[front] = 0;
            front = -1;
            rear = -1;
        }
        else {
            x = arr[front];
            arr[front] = 0;
            front = (front + 1) % MAX_SIZE;
        }
        return x;
    }
};

void Game(Queue& q1, Queue& q2)
{
    int n = 0;
    Queue debate;
    while (n < 1000000)
    {
        int card1 = q1.outqueue();
        int card2 = q2.outqueue();
        if ((card1 == 2) && (card2 == 14))
        {
            q1.inqueue(card1);
            q1.inqueue(card2);
        }
        else if ((card2 == 2) && (card1 == 14))
        {
            q2.inqueue(card1);
            q2.inqueue(card2);
        }
        else if (card1 > card2) {
            q1.inqueue(card1);
            q1.inqueue(card2);
        }
        else if (card2 > card1) {
            q2.inqueue(card1);
            q2.inqueue(card2);
        }
        else {
            debate.inqueue(card1);
            debate.inqueue(card2);
            while (true) {
                if (q1.isEmpty() && q2.isEmpty())
                {
                    break;
                }
                if ((q1.isEmpty() || q2.isEmpty()))
                {
                    break;
                }                
                int new_card1 = q1.outqueue();
                int new_card2 = q2.outqueue();
                debate.inqueue(new_card1);
                debate.inqueue(new_card2);
                if ((new_card1 == 2) && (new_card2 == 14)) {
                    while (!debate.isEmpty()) {
                        q1.inqueue(debate.outqueue());
                    }
                    break;
                }
                if ((new_card2 == 2) && (new_card1 == 14)) {
                    while (!debate.isEmpty()) {
                        q2.inqueue(debate.outqueue());
                    }
                    break;
                }
                if (new_card1 > new_card2) {
                    while (!debate.isEmpty()) {
                        q1.inqueue(debate.outqueue());
                    }
                    break;
                }
                if (new_card2 > new_card1) {
                    while (!debate.isEmpty()) {
                        q2.inqueue(debate.outqueue());
                    }
                    break;
                }              
            }
        }
        if (q1.isEmpty() && q2.isEmpty())
        {
            cout << "draw";
            break;
        }
        if (q1.isEmpty())
        {
            cout << "second";
            break;
        }
        if (q2.isEmpty())
        {
            cout << "first";
            break;
        }
        n += 1;
    }
    if ((!q1.isEmpty() && !q2.isEmpty()))
    {
        cout << "unknown";
    }
}


int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Error";
        return 1;
    }
    ifstream infile(argv[1]);
    if (!infile.is_open()) {
        cout << "Error";
        return 1;
    }
    Queue q1;
    Queue q2;
    string card;
    string suit;
    int count = 0;
    bool first_half = true;
    while (infile >> card >> suit) {
        if (first_half)
        {
            if (card[0] == '1')
            {
                q1.inqueue(10);
            }
            else if (card[0] == 'J')
            {
                q1.inqueue(11);
            }
            else if (card[0] == 'Q')
            {
                q1.inqueue(12);
            }
            else if (card[0] == 'K')
            {
                q1.inqueue(13);
            }
            else if (card[0] == 'A')
            {
                q1.inqueue(14);
            }
            else
            {
                int ich = card[0] - '0';
                q1.inqueue(ich);
            }
            count += 1;
        }
        else
        {
            if (card[0] == '1')
            {
                q2.inqueue(10);
            }
            else if (card[0] == 'J')
            {
                q2.inqueue(11);
            }
            else if (card[0] == 'Q')
            {
                q2.inqueue(12);
            }
            else if (card[0] == 'K')
            {
                q2.inqueue(13);
            }
            else if (card[0] == 'A')
            {
                q2.inqueue(14);
            }
            else
            {
                int ich = card[0] - '0';
                q2.inqueue(ich);
            }
            count += 1;
        }
        if (count == 26)
        {
            first_half = !first_half;
        }

    }
    Game(q1, q2);
    infile.close();
    return 0;
}