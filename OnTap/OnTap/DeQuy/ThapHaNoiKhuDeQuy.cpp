#include<bits/stdc++.h>
using namespace std;
#define max 100

//dinh nghi loi goi
struct Call{
	int n;
	char a;
	char b;
	char c;
};

//dinh nghia stack
struct Stack{
    Call *e;
    int top;
};

//khoi tao stack
void init(Stack &s){
	s.top = -1;
	s.e = NULL;
}

//kiem tra stack rong
bool empty(Stack s) {
    return s.top == -1;
}

//day 1 loi goi vao stack
void push(Stack &s, Call call_in){
	if(empty(s)){
		//neu stack rong thi cap phat 1 vi tri de push loi goi vao stack
		s.e = new Call[1];
	} else {
		//neu stack khong rong thi cap phat lai stack them 1 vi tri nho so voi stack ban dau
		s.e = (Call*)realloc(s.e, (s.top + 2) * sizeof(Call));
	}
	//tang top len 1
	s.top++;
	//day loi goi vao stack
	s.e[s.top] = call_in;
}

//lay 1 loi goi ra khoi stack
void pop(Stack &s, Call &call_out){
	//neu stack rong, khong tra ve
	if(empty(s)) return;
	
	//gan loi goi can lay ra la phan tu tren cung cua 
	call_out = s.e[s.top];
	
	//sau khi lay loi goi ra khoi stack
	if(s.top == 0){ //neu stack chi co 1 phan tu
		delete []s.e; //khoi tao lai stack voi 0 phan tu
		init(s);
	} else {
		//neu stack co nhieu hon 1 phan tu thi thu hoi 1 vi tri nho so voi stack ban dau
		s.e = (Call*)realloc(s.e, s.top * sizeof(Call));
		//giam chi so cua phan tu tren cung di 1
		s.top--; 
	}
}

//ham thap ha noi, truyen vao 1 loi goi dau tien
void thapHaNoi(Call first_call){
	//khai bao call_in, call out
	Call call_in, call_out;
	//khai bao va khoi tao stack
	Stack s;
	init(s);
	
	call_in = first_call;
	//day loi goi dau tien vao stack
	push(s, call_in);
	
	while(!empty(s)){ //neu stack khong trong
		//lay 1 loi goi ra khoi stack
		pop(s, call_out);
		if(call_out.n == 1){ //neu chi con 1 dia
			//chuyen truc tiep tu dia ban dau den dia muc tieu
			cout<<"Chuyen 1 dia tu coc "<<call_out.a<<" sang coc "<<call_out.c<<endl;
		} else { //neu nhieu hon 1 dia
			//gan 1 loi goi de chuyen n - 1 dia tu A sang B
			call_in.n = call_out.n - 1;
			call_in.a = call_out.b;
			call_in.b = call_out.a;
			call_in.c = call_out.c;
			push(s, call_in); //day loi goi vao ngan xep
			
			//gan 1 loi goi de chuyen 1 dia tu A sang C
			call_in = call_out;
			call_in.n = 1;
			push(s, call_in); //day loi goi vao ngan xep
			
			//gan 1 loi goi de chuyen n - 1 dia tu B sang C
			call_in.n = call_out.n - 1;
			call_in.a = call_out.a;
			call_in.b = call_out.c;
			call_in.c = call_out.b;
			push(s, call_in); //day loi goi vao ngan xep
		}
	}
}

int main(){
	Call first_call = {3, 'A', 'B', 'C'};
	thapHaNoi(first_call);
}
 
 

