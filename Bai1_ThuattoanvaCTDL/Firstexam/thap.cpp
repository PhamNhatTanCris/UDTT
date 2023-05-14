
#include<iostream>
#define max 100

struct Stack{
    char a[max];
    int top;
};

int empty_stack(Stack S) {
    if(S.top == 0) {
    	return 1;
	} else {
		return 0;
	}
}

void push(char c, Stack &S){
    if(S.top==max){
    	cout<<"ngan xep day";	
	} else {
        S.top = c;
        top++
    }
}

char pop(Stack S){
	if(empty_stack(S)){
		cout<<"Ngan xep rong";
	} else {
		return S.a[top];
	}
}

int main(){
	
}

