#include<fstream>
#include<thread>
#include<string>
#include<iostream>

using namespace std;

void killer (int thread){
    ofstream data;
    string f_str = "data" + to_string(thread) + ".txt";
    data.open(f_str);
    while(1) data << "Hello World! Hello World! Hello World! Hello World! Hello World!" << endl;
}
int main(){
    int num_threads = 10000;
    auto* threads = new thread[num_threads];
    for(int i = 0; i < num_threads; i++) threads[i] = thread(&killer, i);
    for(int i = 0; i < num_threads; i++) threads[i].join();
}