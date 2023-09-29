#include <iostream>
#include <future>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
    Array<int, 10> arr = {11,25,3,14,58,16,7,28,9};
	
	// создали фьючерс   
    future<void> f = async(launch::async, []() {
        std::thread t(&arr, int l, int r);
    });
    
    int m = (l + r - 1) / 2;
    f.wait();
    
    // проверка готовности и валидности после метода wait()
    f.valid() << endl;
    
    f.get();
    
    // проверка валидности после get()
    if (l > r) f.valid() << endl;

    return 0;
}