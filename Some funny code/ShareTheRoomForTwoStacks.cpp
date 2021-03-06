#include <iostream>
#include <windows.h>
using namespace std;
#define MAX 100

template <class T>
class SqStack{

private:
	T* base;
	int top1;
	int top2;
	int stacksize;
public:
	SqStack(int m){
		base = new T[m];
		stacksize = m;
		top1 = -1;
		top2 = m;
	}
	~SqStack(){
		delete[] base; 
		top1 = -1; 
		top2 = -1;
		stacksize = 0;
	}
	void Push1(T x);
	void Push2(T x);
	T pop1();
	T pop2();
	T GetTop1();
	T GetTop2();
	int StackEmpty1();
	int StackEmpty2();
	void ClearStack1();
	void ClearStack2();
	T* StackTop1(); //return the point of stack top
	T* StackTop2();
	void StackTranverse1();
	void StackTranverse2();
};

template <class T>
void SqStack<T>::Push1(T x){
	if (top1 == top2)
	{
		cout<<"Stack1 overflow!"<<endl;
		exit(3);
	}
	base[++top1] = x;

	return;
}
template <class T>
void SqStack<T>::Push2(T x){
	if (top1 == top2)
	{
		cout<<"Stack2 overflow!"<<endl;
		exit(3);
	}
	base[--top2] = x;
	
	return;
}

template <class T>
T SqStack<T>::pop1(){
	if (top1 == -1){
		cout<<"Stack1 underflow!"<<endl;
		exit(3);
	}
	return base[top1--];
}

template <class T>
T SqStack<T>::pop2(){
	if (top2 == stacksize){
		cout<<"Stack2 underflow!"<<endl;
		exit(3);
	}
	return base[top2++];
}

template <class T>
T SqStack<T>::GetTop1(){
	if (top1 == -1){
		cout<<"Stack1 underflow"<<endl;
		exit(3);
	}
	return base[top1];
}

template <class T>
T SqStack<T>::GetTop2(){
	if (top2 == stacksize){
		cout<<"Stack2 underflow"<<endl;
		exit(3);
	}
	return base[top2];
}

template <class T>
int SqStack<T>::StackEmpty1(){
	if (top1 == -1)
		return 1;
	else return 0;
} 

template <class T>
int SqStack<T>::StackEmpty2(){
	if (top2 == stacksize)
		return 1;
	else return 0;
} 

template <class T>
void SqStack<T>::ClearStack1(){
	top1 = -1;
	return;
}

template <class T>
void SqStack<T>::ClearStack2(){
	top2 = stacksize;
	return;
}

//return the pointer of stack top
template <class T>
T* SqStack<T>::StackTop1(){
	if (top1 == -1){
		cout<<"The stack1 underflow!"<<endl;
		exit(3);
	}
	return &base[top1];
}

template <class T>
T* SqStack<T>::StackTop2(){
	if(top2 == stacksize){
		cout<<"The stack2 underflow!"<<endl;
		exit(3);
	}
	return &base[top2];
}

template <class T>
void SqStack<T>::StackTranverse1(){
	if (top1 == -1){
		cout<<"There is none element in the stack1 now"<<endl;
		return;
	}
	cout<<"The element in stack1 is belowing:"<<endl;
	cout<<"The elements in the stack1 is:"<<endl;
	int q = top1;
	while (q > -1){
		cout<<base[q]<<endl;
		q--;
	}

	return;
}

template <class T>
void SqStack<T>::StackTranverse2(){
	if (top2 == stacksize){
		cout<<"There is none element in the stack2 now"<<endl;
		return;
	}
	cout<<"The elements in the stack2 is:"<<endl;
	int p = top2;
	while(p < stacksize){
		cout<<base[p]<<endl;
		p++;
	}
	return;
}
template <class T>
void run(SqStack<T>& tester){
	int num_p1;
	int num_p2;
	int tag = 0;
	printf("---------------Hello Sir, Welcome to Double Stacks System!---------------\n");
	while (true){
		printf("Please choose which stack to be used 1 or 2 or 0(just enter the number, 0 means quit!): ");
		if(!tag){
			while(cin>>num_p1){
				if (num_p1 == 1 || num_p1 == 2 || num_p1 == 0)
					break;
				else
					cout<<"Please enter the valid number (like 1 or 2 or 0)-->";
			}
			if (!num_p1)
				break;
		}
		printf("\n<--Which function do you want to use-->");
		printf("\n\t1.push the element\n\t2.pop the element\n");
		printf("\t3.get the top element without pop\n\t4.know whether the stack is empty\n");
		printf("\t5.clear all the element in this stack\n\t6.get the pointer of the element\n");
		printf("\t7.show all elements in this stack\n");
		printf("please choose the number and enter it(0 means quit!)-->");
		while(cin>>num_p2){
				if (num_p2 == 1 || num_p2 == 2 ||num_p2 == 3||num_p2 == 4||num_p2 == 5||num_p2 == 6 ||num_p2 == 7 || num_p2 == 0)
					break;
				else
					cout<<"Please enter the valid number (integer between 1 and 7)-->";
			}
		if (!num_p2)
			break;	
		int num = num_p1 + 10*num_p2;
		switch(num){
			case 11:
				cout<<"Please enter the element wants to push-->";
				T e;
				cin>>e;
				tester.Push1(e);
				cout<<"The element '"<<e<<"' has pushed into stack1 successfully!"<<endl;
				break;
			case 12:
				cout<<"Please enter the element wants to push-->";
				T e2;
				cin>>e2;
				tester.Push2(e2);
				cout<<"The element '"<<e2<<"' has pushed into stack2 successfully!"<<endl;
				break;
			case 21:
				cout<<"The popped element is:"<<tester.pop1()<<endl;
				cout<<"The pop programme is finished!"<<endl;
				break;
			case 22:
				cout<<"The popped element is:"<<tester.pop2()<<endl;
				cout<<"The pop programme is finished!"<<endl;
				break;
			case 31:
				cout<<"The top element is:"<<tester.GetTop1()<<endl;
				break;
			case 32:
				cout<<"The top element is:"<<tester.GetTop2()<<endl;
				break;
			case 41:
				if(tester.StackEmpty1())
					cout<<"The stack1 is empty!"<<endl;
				else
					cout<<"The stack1 is not empty!"<<endl;
				break;
			case 42:
				if(tester.StackEmpty2())
					cout<<"The stack2 is empty!"<<endl;
				else
					cout<<"The stack2 is not empty!"<<endl;
				break;
			case 51:
				cout<<"Programme is clear the stack1, please wait";
				for(int i = 0; i < 5; i++)
				{
					cout<<'.';
					Sleep(1000);
				}
				cout<<endl;
				tester.ClearStack1();
				cout<<"The stack1 is cleared successfully!"<<endl;
				break;
			case 52:
				cout<<"Programme is clear the stack2, please wait";
				for(int i = 0; i < 5; i++)
				{
					cout<<'.';
					Sleep(1000);
				}
				cout<<endl;
				tester.ClearStack2();
				cout<<"The stack2 is cleared successfully!"<<endl;
				break;
			case 61:
				cout<<"The pointer of stack1's top is pointed to the address '"<<tester.StackTop1()<<"'."<<endl;
				break;
			case 62:
				cout<<"The pointer of stack2's top is pointed to the address '"<<tester.StackTop1()<<"'."<<endl;
				break;
			case 71:
				tester.StackTranverse1();
				break;
			case 72:
				tester.StackTranverse2();
				break;
			default:
				cout<<"Perhaps there is no choice like that..."<<endl;
				break;
		}
		cout<<"Do you want to quit? Enter 'q' to quit the programme, other keys to continue>>>";
		char c;
		getchar();
		c = getchar();
		if (c == 113)
			break;		
		switch(num_p1){
			case 1:
				cout<<"Would you like to go on manipulating the stack1?(Y/N)>>>";
				char a2;
				while(cin>>a2){
					if (a2 == 121 || a2 == 89)
						{tag = 1;break;}
					else if(a2 == 78 || a2 == 110)
						{tag = 0;break;}
					else{
						cout<<"Please enter the valid char(Y/N)>>>";
					}
				}
				break;
			case 2:
				cout<<"Would you like to go on manipulating the stack2?(Y/N)>>>";
				char a;
				while(cin>>a){
					if (a == 121 || a == 89)
						{tag = 1;break;}
					else if(a == 78 || a == 110)
						{tag = 0;break;}
					else{
						cout<<"Please enter the valid char(Y/N)>>>";
					}
				}
				break;
			default:
				cout<<"Someting wrong!"<<endl;
				break;
		}
	}

}

int main(int argc, char const *argv[])
{
	// cout<<"hello world"<<endl;
	SqStack<int>aSqStack(MAX);
	run(aSqStack);
	cout<<"You haven't saved the data yet, Do you want to save it to location?(Y/N)>>>";
	char a;
	//add the save file code here
	cout<<endl;
	cout<<"Thanks for your using, wish you have a good day!"<<endl;
	return 0;
}

