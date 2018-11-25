#include<iostream>
#include <unistd.h>
#include<vector>
#include <iomanip>

using namespace std;

class Clock{
    private:
        int H_, M_, S_;
    public:
        Clock(int H = 0, int M = 0, int S = 0){
            this -> H_ = H;
            this -> M_ = M;
            this -> S_ = S;
        }

        void ShowTime(){
            cout << H_ << ":" << M_ << ":" << S_ << endl;
        }

        void SetTime(int H = 0, int M = 0, int S = 0){
            this -> H_ = H;
            this -> M_ = M;
            this -> S_ = S;
        }

        int GetH(){
            return H_;
        }

        int GetM(){
            return M_;
        }

        int GetS(){
            return S_;
        }
};

class AlarmClock: public Clock{
    private:
        vector<int> AH_;
        vector<int> AM_;
        vector<int> AS_;
        int nc;
    public:
        AlarmClock(int H, int M, int S): Clock(H, M, S){
        }

        void setAlarmTime(int AH, int AM, int AS){
            AH_.push_back(AH);
            AM_.push_back(AM);
            AS_.push_back(AS);
        }

        void nowtime(int &nh, int &nm, int &ns){
            int a = time(0) - nc;       //time(0)读取时间戳计算时间
            nh =(GetH() + (GetM() + (GetS() + a) / 60) / 60) % 24;
            nm = (GetM() + (GetS() + a) / 60) % 60;
            ns = (GetS() + a) % 60;
        }

        void start(){
            nc = time(0);       //time(0)读取时间戳保存开始时间
            int nh, nm, ns;
            while(true){
                nowtime(nh, nm, ns);
                if(find(AH_.begin(), AH_.end(), nh) != AH_.end() && find(AM_.begin(), AM_.end(), nm) != AM_.end() && find(AS_.begin(), AS_.end(), ns) != AS_.end()){
                    for(int i = 0; i < 5; i++){
                        cout << setw(2) << setfill('0') << nh << ":" << setw(2) << setfill('0') << nm << ":" << setw(2) << setfill('0') << ns << "bbb" << endl;
                        usleep(1000000);    //次处并没用usleep()计算时间，只是用于把线程挂起，注释掉也没关系
                        system("clear");
                        nowtime(nh, nm, ns);
                    }
                    continue;
                }else{
                    cout << setw(2) << setfill('0') << nh << ":" << setw(2) << setfill('0') << nm << ":" << setw(2) << setfill('0') << ns << endl;
                }
                usleep(1000000);        //次处并没用usleep()计算时间，只是用于把线程挂起，注释掉也没关系
                system("clear");
            }
        }
};

int main()
{
    AlarmClock myclock(10, 10, 58);
    myclock.setAlarmTime(10, 11, 03);
    myclock.setAlarmTime(10, 11, 13);
    myclock.start();
    return 0;
}