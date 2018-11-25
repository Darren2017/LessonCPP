#include<iostream>
#include <iomanip>
#include<cstring>

using namespace std;

class Student{
    private:
        long ID;
        string Name;
        double Score1, Score2, Score3, Total;
        int Rank;;
    public:
        Student(long id = 0, string name = "", double s1 = 0.0, double s2 = 0.0, double s3 = 0.0){
            ID = id;
            Name = name;
            Score1 = s1;
            Score2 = s2;
            Score3 = s3;
            Total = s1 + s2 + s3;
            Rank = 0;
        }

        double GetTotal(){
            return Total;
        }

        void SetRank(int rank){
            Rank = rank;
        }

        int GetRank(){
            return Rank;
        }

        void show(){
            cout.setf(ios::left);
            cout << "排名" << setw(3) << Rank <<  "名字：" << setw(8) << Name << "学号：" << setw(13) << ID << "总成绩：" << setw(3) << Total << endl;
        }
};

void swap(Student s[], int i, int j);
void quicksort(Student s[], int low, int hign);

int main()
{
    int num;
    string name;
    long id;
    double s1, s2, s3;
    Student students[100];
    for(num = 0; true; num++){
        cout << "请分别输入第" << num + 1 << "位同学的学号，名字，第一门成绩，第二门成绩，第三门成绩。" << endl;
        cin >> id >> name >> s1 >> s2 >> s3;
        if(id == 0){
            break;
        }
        students[num] = Student(id, name, s1, s2, s3);
    }

    quicksort(students, 0, num - 1);
    students[0].SetRank(1);
    double SumScore = students[0].GetTotal();
    for(int i = 1; i < num; i++){
        SumScore += students[i].GetTotal();
        if(students[i].GetTotal() == students[i - 1].GetTotal()){
            students[i].SetRank(students[i - 1].GetRank());
        }else{
            students[i].SetRank(i + 1);
        }
    } 

    for(int i = 0; i < num; i++){
        students[i].show();
    }
    cout << "班级平均成绩为：" << SumScore / num << endl;

    return 0;
}

void quicksort(Student s[], int low, int hign){
    int i;
    int last;
    if(low < hign){
        last = low;
        for(i = low + 1; i <= hign; i++){
            if(s[i].GetTotal() > s[low].GetTotal()){
                swap(s, ++last, i);
            }
        }
        swap(s, last, low);
        quicksort(s, low, last - 1);
        quicksort(s, last + 1, hign);
    }
}

void swap(Student s[], int i, int j){
    Student temp;
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}