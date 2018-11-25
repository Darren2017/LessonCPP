#include<iostream>
#include <iomanip>

# define ElemType int       //可以修改为double型

using namespace std;

void initmatrix(ElemType &r, ElemType &p, ElemType &q);     //初始化三个矩阵
void applymemory(ElemType *matrix_a[], ElemType *matrix_b[], ElemType *matrix_ans[], ElemType r, ElemType p, ElemType q);       //申请内存
void inputdata(ElemType *matrix_a[], ElemType *matrix_b[], ElemType r, ElemType p, ElemType q);     //读入数据
void mul(ElemType *matrix_a[], ElemType *matrix_b[], ElemType *matrix_ans[], ElemType r, ElemType p, ElemType q);       //乘法运算
void print(ElemType *matrix_ans[], ElemType r, ElemType q);     //打印输出
void destroymatrix(ElemType *matrix_a[], ElemType *matrix_b[], ElemType *matrix_ans[], ElemType r, ElemType p, ElemType q);     //释放内存

ElemType main()
{
    ElemType r, p, q;
    initmatrix(r, p, q);
    ElemType *matrix_a[r], *matrix_b[p], *matrix_ans[r];
    applymemory(matrix_a, matrix_b, matrix_ans, r, p, q);
    inputdata(matrix_a, matrix_b, r, p, q);
    mul(matrix_a, matrix_b, matrix_ans, r, p, q);
    print(matrix_ans, r, q);
    destroymatrix(matrix_a, matrix_b, matrix_ans, r, p, q);
    return 0;
}

void initmatrix(ElemType &r, ElemType &p, ElemType &q){
    cout << "请输入矩阵1的行数：";
    cin >> r;
    cout << "请输入矩阵1的列数：";
    cin >> p;
    cout << "请输入矩阵2的列数：";
    cin >> q; 
}

void applymemory(ElemType *matrix_a[], ElemType *matrix_b[], ElemType *matrix_ans[], ElemType r, ElemType p, ElemType q){
    for(ElemType i = 0; i < r; i++){
        matrix_a[i] = new ElemType[p];
    }
    for(ElemType i = 0; i < p; i++){
        matrix_b[i] = new ElemType[q];
    }
    for(ElemType i = 0; i < r; i++){
        matrix_ans[i] = new ElemType[q];
    }
}

void inputdata(ElemType *matrix_a[], ElemType *matrix_b[], ElemType r, ElemType p, ElemType q){
    cout << "请输入一个" << r << "行" << p << "列的行列式" << endl;
    for(ElemType i = 0; i < r; i++){
        for(ElemType j = 0; j < p; j++){
            cin >> matrix_a[i][j];
        }
    }
    cout << "请输入一个" << p << "行" << q << "列的行列式" << endl;
    for(ElemType i = 0; i < p; i++){
        for(ElemType j = 0; j < q; j++){
            cin >> matrix_b[i][j];
        }
    }
}

void mul(ElemType *matrix_a[], ElemType *matrix_b[], ElemType *matrix_ans[], ElemType r, ElemType p, ElemType q){
    for(ElemType i = 0; i < r; i++){
        for(ElemType j = 0; j < q; j++){
            matrix_ans[i][j] = 0;
            for(ElemType l = 0; l < p; l++){
                matrix_ans[i][j] += matrix_a[i][l] * matrix_b[l][j];
            }
        }
    }
}

void print(ElemType *matrix_ans[], ElemType r, ElemType q){
    cout << "矩阵相乘得：" << endl;
    for(ElemType i = 0; i < r; i++){
        for(ElemType j = 0; j < q; j++){
            cout << left << setw(6) << matrix_ans[i][j];
        }
        cout << endl;
    }
}

void destroymatrix(ElemType *matrix_a[], ElemType *matrix_b[], ElemType *matrix_ans[], ElemType r, ElemType p, ElemType q){
    for(ElemType i = 0; i < r; i++){
        delete []matrix_a[i];
    }
    for(ElemType i = 0; i < p; i++){
        delete []matrix_b[i];
    }
    for(ElemType i = 0; i < r; i++){
        delete []matrix_ans[i];
    }
}