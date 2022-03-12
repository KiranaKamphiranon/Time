#include <iostream>
#include <iomanip>

using namespace std;

struct Time{
  int m,h,s;
};

void getTime(struct Time&);
struct Time subtract(struct Time, struct Time);

int main() {
  struct Time t1,t2,t3;
  cout<<"What time was it? "<<endl<<"-> ";
  getTime(t1);
  cout<<"What time is it now? "<<endl<<"-> ";
  getTime(t2);
  t3=subtract(t2,t1); //t3=t2-t1
  cout<<"Time diff is ";
  cout<<setfill('0')<<setw(2)<<t3.h<<":";
  cout<<setfill('0')<<setw(2)<<t3.m<<":";        
  cout<<setfill('0')<<setw(2)<<t3.s;
  //std::cout << "Hello World!\n";
  return 0;
}

void getTime(struct Time& T){
  cin >> T.h >> T.m >> T.s;
  //cout<<T.h<<" "<<T.m<<" "<<T.s<<endl;
}

struct Time subtract(struct Time T2, struct Time T1){
  struct Time T3;
  T3.s=(T2.s-T1.s+60)%60;
  T3.m=(T2.m-T1.m+60-((T3.s-(T2.s-T1.s))/60))%60;
  T3.h=((((T2.h*60*60)+(T2.m*60)+(T2.s)-((T1.h*60*60)+(T1.m*60)+(T1.s)))/60/60)+24)%60;
  return T3;
}
