#include <thread>
#include <mutex>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

std::mutex my_lock;

void add(int &num, int &sum){
    while(true){
        std::lock_guard<std::mutex> lock(my_lock);  
      
        if (num < 100){ //运行条件
            num += 1;
            sum += num;
        }   
        else {  //退出条件
            break;
        }   
    }   
}


#include <iostream>
#include <condition_variable>
#include <thread>
#include <chrono>
 
std::condition_variable cv;
std::mutex cv_m; // This mutex is used for three purposes:
                 // 1) to synchronize accesses to i
                 // 2) to synchronize accesses to std::cerr
                 // 3) for the condition variable cv
int i = 0;
 
void waits()
{
    while(true)
    {
        std::cout << this_thread::get_id() << " start\n";
         std::unique_lock<std::mutex> lk(cv_m);
    std::cerr <<  this_thread::get_id() << "Waiting... \n";
    cv.wait(lk, []{
        std::cerr <<  this_thread::get_id() << " get notified" << endl;
        return (i %2 ==1);
        });
    std::cerr <<  this_thread::get_id() <<"...finished waiting and sleep. i == 1\n";
     std::this_thread::sleep_for(std::chrono::seconds(3));
    }
   
}
 
void signals()
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(4));
        {
            std::lock_guard<std::mutex> lk(cv_m);
            std::cerr << "Notifying...\n";
        }
        cv.notify_all();
    
        std::this_thread::sleep_for(std::chrono::seconds(4));
    
        {
            std::lock_guard<std::mutex> lk(cv_m);
            i++;
            std::cerr <<  this_thread::get_id() << "Notifying again...\n";
        }
        cv.notify_all();
    }
    
   
}
 
int main11()
{
    std::thread t1(waits), t2(waits), t3(waits), t4(signals);
    t1.join(); 
    t2.join(); 
    t3.join();
    //t4.join();
    return 0;
}

std::mutex cv_m123; 
void testLock()
{
    std::lock_guard<std::mutex> lk1(cv_m123);
     std::cout << "lk1...\n";
    std::lock_guard<std::mutex> lk2(cv_m123);
    std::cout << "lk2...\n";
    std::lock_guard<std::mutex> lk3(cv_m123);
    std::cout << "lk3...\n";
    std::lock_guard<std::mutex> lk4(cv_m123);
     std::cout << "lk4...\n";
}
int main(){
    int sum = 0;
    int num = 0;
    std::vector<std::thread> ver;   //保存线程的vector
    for(int i = 0; i < 20; ++i){
        std::thread t = std::thread(add, std::ref(num), std::ref(sum));
        ver.emplace_back(std::move(t)); //保存线程
    }   

    std::for_each(ver.begin(), ver.end(), std::mem_fn(&std::thread::join)); //join
    std::cout << sum << std::endl;


    main11();
    testLock();
}