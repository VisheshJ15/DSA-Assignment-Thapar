#include <iostream>
using namespace std;
#define MAX 100
int stack[MAX],top=-1,mn;
void push(int x){
    if(top==-1){stack[++top]=0;mn=x;}
    else{stack[++top]=x-mn;if(x<mn)mn=x;}
}
int pop(){
    if(top<0)return -1;
    int t=stack[top--];
    if(t<0){int v=mn;mn=mn-t;return v;}
    else return mn+t;
}
int getMin(){return mn;}
int main(){
    push(3);push(5);cout<<getMin()<<endl;push(2);push(1);cout<<getMin()<<endl;pop();cout<<getMin()<<endl;pop();cout<<pop()<<endl;
}
