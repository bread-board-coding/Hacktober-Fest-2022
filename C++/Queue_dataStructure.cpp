#include<iostream>
using namespace std;

class Queue
{
	int front, rear;
	int arr[5];
	
	public:
		
		Queue()
		{
			front=-1;
			rear=-1;
			for(int i=0;i<5;i++)
			{
				arr[i]=0;
			}
		}
		
		bool isFull()
		{
			if(rear==4)
			return true;
			else
			return false;
		}
		
		bool isEmpty()
		{
			if(front==-1 && rear==-1)
			return true;
			else
			return false;
		}
		
		void enqueue(int val)
		{
			if(isFull())
			cout<<"Queue is Full"<<endl;
			else if(isEmpty())
			{
			  front++;
			  rear++;
			  arr[rear]=val;
			  cout<<"Value inserted"<<endl;
			}
			else
			{
				rear++;
				arr[rear]=val;
				cout<<"Value inserted"<<endl;
			}
		}
		
		int dequeue()
		{ 
			int x = arr[front];
			arr[front]=0;
			front++;
			return x;
		}
		
		void display()
		{
			if(isEmpty())
			cout<<"Queue is Empty"<<endl;
			else
			{
				for(int i=front;i<=rear;i++)
				{
					cout<<arr[i]<<" ";
				}
				
				cout<<endl;
			}
		}
		
		void change(int pos, int val)
		{
			if(pos<=rear)
			{
				arr[pos]=val;
				cout<<"Value changed"<<endl;
			}
			else
			cout<<"Element does not exist"<<endl;
		}
		
		int peek(int pos)
		{
			return arr[pos];
		}
		
};

int main()
{
	Queue q;
	
	cout<<"Menu"<<endl<<endl;
	cout<<"1. IsEmpty()"<<endl;
	cout<<"2. IsFull()"<<endl;
	cout<<"3. Enqueue()"<<endl;
	cout<<"4. Dequeue()"<<endl;
	cout<<"5. Display()"<<endl;
	cout<<"6. Peek()"<<endl;
	cout<<"7. Change()"<<endl;
	cout<<"8. Exit()"<<endl;
	
	int n;
	
	
	do{
	cin>>n;
	
	switch(n)
	{
		case 1: if(q.isEmpty())
		        cout<<"Queue is empty"<<endl;
		        else 
		        cout<<"Queue is not empty"<<endl;
	            break;
	            
	    case 2: if(q.isFull())
		        cout<<"Queue is full"<<endl;
		        else 
		        cout<<"Queue is not full"<<endl;
	            break;
				
		case 3: 
		      int val;
		      cout<<"Enter the value : ";
		      cin>>val;
		      cout<<endl;
		      q.enqueue(val);
		      break;
			  
	    case 4: cout<<"Value Dequeued : "<<q.dequeue();
	    break;
			  
	    case 5: q.display();
	    break;
	    
	    case 6: int pos;
	            cout<<"Enter the position of the element : ";
	            cin>>pos;
	            cout<<endl;
	            cout<<"Value : "<<q.peek(pos);
	            break;
		
		case 7: int num,value;
		        cout<<"Enter the position of the value to be changed : ";
				cin>>num; 
				cout<<endl;    
				cout<<"Enter the new value : ";
				cin>>value;
				cout<<endl;
				
				q.change(num,value);
				break;
		
		
		case 8: cout<<"Exit()"<<endl;
		        break;
		        
		default: cout<<"Wrong choice"<<endl;
		         break;
	};
}while(n!=8);
	
	return 0;
}
