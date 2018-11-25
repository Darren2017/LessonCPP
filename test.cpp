// #include<iostream>

// using namespace std;

// class String{
//     public:
//         char * Str;
//         int len;
//         void ShowStr(){
//             cout << Str << endl;
//         }
//         String(){
//             len = 0;
//             Str = NULL;
//         }
//         String(const char *p){
//             len = strlen(p);
//             Str = new char[len + 1];
//             strcpy(Str, p);
//         }
//         String(String &s2){
//             Str = new char[s2.len + 1];
//             strcpy(Str, s2.Str);
//             len = s2.len;
//         }
//         ~String(){
//             cout << "     ";
//             delete Str;
//         }
// };

// int main()
// {
//     String s1("123456");
//     String s2;
//     s2=s1;
//     s1.Str[0] = 'd';
//     s1.ShowStr();
//     s2.ShowStr();

//     return 0;
// }
#include<iostream>
    
using namespace std;

int main()
{
    char a;
    while(cin >> noskipws >> a){    
        cout << a;
    }

    return 0;
}