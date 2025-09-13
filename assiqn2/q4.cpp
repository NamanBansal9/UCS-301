#include<iostream>
#include<string>
using namespace std;

/*
(a) Write a program to concatenate one string to another string. 
(b) Write a program to reverse a string. 
(c) Write a program to delete all the vowels from the string. 
(d) Write a program to sort the strings in alphabetical order. 
(e) Write a program to convert a character from uppercase to lowercase
*/

string str1 = "Hello ";
string str2 = "Mr.H";
string str;
void conca(void);
void rev(void);
void vowel(void);
void sort(void);
void uplo(void);
int main(){
    conca();
    rev();
    vowel();
    sort();
    uplo();
    return 0;
}

void conca(void){
   str = str1 + str2;
   cout<<str<<endl;
}
void rev(void){
    string kt = "";
    for(int j = (str1.length())-1;j>=0;j--){
        kt += str1[j] ;
    }
    cout<<kt<<endl;
}

void vowel(void){
 string non_vowel = "";
    for (char c : str1)
    {
        if (!(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U'))
        {
            non_vowel += c;
        }
    }

    cout << "String without vowels :" << non_vowel << endl;

}
void sort(void){
    string str = "kali";
    char temp;
    for(int i=0;i<str.length()-1;i++){
        for(int j=0;j<(str.length()-1-i);j++){
            if(str[j+1]<str[j]){
                temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    }
        cout<<str<<endl;  
}
void uplo(void){
    char p;
    cout<<"enter the uppercase letter : "<<endl;
    cin>>p;
    p += 32;
    cout<<"the lower case letter is : "<<p<<endl;
}
