#include <iostream>
#include<cassert>
using namespace std;

// Queue using circular array (dynamic size)
// Functions: { isEmpty, isFull, enQueue, deQueue, getFront, getRear, disp, itemPosition}

//LIFO "index starts from 0"

template<class T>
class Queue {
private:
	int front, rear;
	int numberOfElements;
	T*arr;
	int MAX_LENGTH;
public:
	Queue(int givenSize)
	{
		front = 0;
		rear = givenSize - 1;
		numberOfElements = 0;

		this->MAX_LENGTH = givenSize;
		arr = new T[givenSize];
	}

	bool isEmpty()
	{
		return numberOfElements == 0;
	}

	bool isFull()
	{
		return numberOfElements == MAX_LENGTH;
	}

	void enQueue(T element) //deals with rear 
	{
		if (isFull())
		{
			cout << "Can't enqueue it's full\n";
		}
		else
		{
			rear = (rear + 1) % MAX_LENGTH;//the optimal way to move the rear index
			// to ensure that the index is in range off array length to make a circular array
			arr[rear] = element;
			numberOfElements++;
		}
	}

	void deQueue()
	{
		if (isEmpty())
		{
			cout << "Queue is empty Can't dequeue\n";
		}
		else
		{
			front = (front + 1) % MAX_LENGTH;//the optimal way to move the front index
			// to ensure that the index is in range off array length to make a circular array
			numberOfElements--;
		}
	}

	T getFront()
	{
		assert(!isEmpty()); //I used this instead of an if condition
		// must include <cassert> library 
		// if it's not empty the program works fine else it emmits a warning
		return arr[front];
	}

	T getRear()
	{
		assert(!isEmpty());
		return arr[rear];
	}

	void disp()
	{
		//to display a circular array
		cout << "Queue elements: [ ";
		for (size_t i = front; i != rear; i = (i + 1) % MAX_LENGTH)
		{

			cout << arr[i] << " , ";
		}
		cout << arr[rear] << " ]\n";
	}

	

	int itemPosition(T requiredItem)//to search for item's position.
	{
		int position = -1;

		if (!isEmpty())
		{

			// to iterate through a circular array
			for (int i = front; i != rear; i = (i + 1) % MAX_LENGTH)
			{
				if ((arr[i] == requiredItem))
				{
					position = i;
					break;
				}
			}

			// for the last item.
			if (position == -1)
			{
				((arr[rear] == requiredItem) ? position = rear : position = position);
			}
		}

		else
			cout << "The Queue is empty!\n";

		//return (position == -1) ? -1 : position - 1;
		return position-1;
	}

};


int main()
{
	Queue<int> Trail(8);
	Trail.enQueue(100);
	cout << Trail.getFront() << endl;
	Trail.enQueue(200);
	Trail.enQueue(300);
	Trail.enQueue(400);
	cout << Trail.getFront() << endl;
	cout << Trail.getRear() << endl;
	Trail.deQueue();
	Trail.disp();
	cout<<Trail.itemPosition(400)<<endl;

	return 0;
}
