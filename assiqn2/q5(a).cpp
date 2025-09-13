#include<iostream>
using namespace std;

class diagonal_matrix{
    int *A,n;
    public:
        diagonal_matrix(int k){
            this->n = k;
            A = new int[k];
        }
        void create(void);
        void display(void);
};
void diagonal_matrix :: create(void){
    cout<<"enter non - zero no. : "<<endl;
    for(int i=0;i<this->n;i++){
        cin>>A[i];
    }
    display();
}
void diagonal_matrix :: display(void){
    cout<<"["<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            (i==j) ? cout<<A[i] : cout<<"0" ;
        }
        cout<<endl;
    }
    cout<<"]"<<endl;
}
int main(){
diagonal_matrix A(3);
A.create();
    return 0;
}
