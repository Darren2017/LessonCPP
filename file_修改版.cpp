#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    char **pp_a, **pp_b, **pp;
    pp_a = new char * [300];
    pp_b = new char * [300];
    int len_a = 0, len_b = 0, cnt_a = 0, cnt_b = 0;
    cout << "请输入第一篇短文，最后一行以“#”结束：" << endl;
    for(; ; len_a++){
        pp_a[len_a] = new char [200];
        cin >> pp_a[len_a];
        if(pp_a[len_a][0] == '#'){
            break;
        }
    }
    cout << "请输入第二篇短文，最后一行以“#”结束：" << endl;
    for(; ; len_b++){
        pp_b[len_b] = new char [200];
        cin >> pp_b[len_b];
        if(pp_b[len_b][0] == '#'){
            break;
        }
    }
    pp = new char * [len_a + len_b];
    int cnt = 0, i = 0;
    for( ; cnt_a < len_a && cnt_b < len_b; cnt_a++, cnt_b++, i++, cnt += 2){
        pp[cnt] = new char [strlen(pp_a[i])];
        memcpy(pp[cnt], pp_a[i], strlen(pp_a[i]));
        delete []pp_a[i];
        pp[cnt + 1] = new char [strlen(pp_b[i])];
        memcpy(pp[cnt + 1], pp_b[i], strlen(pp_b[i]));
        delete []pp_b[i];
    }
    for( ; cnt_a < len_a; cnt_a++, cnt++, i++){
        pp[cnt] = new char [strlen(pp_a[i])];
        memcpy(pp[cnt], pp_a[i], strlen(pp_a[i]));
        delete []pp_a[i];
    }
    for( ; cnt_b < len_b; cnt_b++, cnt++, i++){
        pp[cnt] = new char [strlen(pp_b[i])];
        memcpy(pp[cnt], pp_b[i], strlen(pp_b[i]));
        delete []pp_b[i];
    }
    delete []pp_a;
    delete []pp_b;

    cout << "合并后的结果是：" << endl;
    for(int i = 0; i < len_a+len_b; i++){
        cout << pp[i] << endl;
        delete []pp[i];
    }
    delete []pp;


    return 0;
}