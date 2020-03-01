#include <iostream>
#include <string>
using namespace std;


int main(){
	int n;
	cin >> n;
	string s;
	int *arr = new int[n+1];
	int rear = -1;
	int head = -1;
	do{
		cin >> s;
		if(s == "push"){
			int element;
			cin >> element;
			arr[++rear] = element;
			if(head < 0) //처음 들어올때만 head 증가
				++head;
		}else if(s == "pop"){
			if(head < 0 && rear < 0)
				printf("-1\n");
			else if(head == rear){ //only 1 element
				printf("%d\n",arr[head]);
				head = -1; //empty queue
				rear = -1;
			}else if(rear > head){
				printf("%d\n",arr[head]);
				++head; // pop 하면 head는 다음 인덱스를 가리킴
			}
		}else if(s == "size"){
			if(head < 0 && rear < 0)
				printf("0\n");
			else if(head == rear)
				printf("1\n");
			else if(rear > head){
				printf("%d\n",rear - head + 1);
			}
		}else if(s == "empty"){
			if(head < 0 && rear < 0)
				printf("1\n");
			else
				printf("0\n");
		}else if(s == "front"){
			if(head < 0 && rear < 0)
				printf("-1\n");
			else
				printf("%d\n",arr[head]);
		}else if(s == "back"){
			if(head < 0 && rear < 0)
				printf("-1\n");
			else
				printf("%d\n",arr[rear]);
		}
		--n;
	}while(n > 0);


}
