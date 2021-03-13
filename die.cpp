#include<fstream>
#include<thread>
#include<string>
using namespace std;

void killer (int thread){
    ofstream data;
    data.open("data" + to_string(thread) + ".txt");
    while(1) data << "Hello World!" << endl;
}
int main(){
    int num_threads = 10000;
    auto* threads = new thread[num_threads];
    for(int i = 0; i < num_threads; i++) threads[i] = thread(&killer, i);
    for(int i = 0; i < num_threads; i++) threads[i].join();
}
