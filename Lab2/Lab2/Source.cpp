#include <mutex>
#include <thread>
#include <atomic>
#include <chrono>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
mutex g_lockprint;
void print(string text)
{
	lock_guard<mutex> cout_lock(g_lockprint);
	cout << text << endl;
}
void Timer() {
	int a;
	bool flag = true;
	while (flag) {
	this_thread::sleep_for(chrono::seconds(5));
	print("continue calculation");
	print("enter 1 - Yes");
	print("enter 2 - No");
	cin >> a;
	if (a == 2) {
		flag = false;
		exit(1);
	}
}
}
int Fx(int x) {
	this_thread::sleep_for(chrono::seconds(20));
	return x + 1;
	
}
int Fy(int y) {
	this_thread::sleep_for(chrono::seconds(10));
	return y + 2;
}
int main() {
	bool flag=true;
	int Fxx; int Fyy;
	int result;
	print("enter the first number");
	cin >> Fxx;
	print("enter the second number");
	cin >> Fyy;
	thread th1([&Fxx](){
		Fxx = Fx(Fxx);
		});
	thread th2([&Fyy]() {
		Fyy = Fx(Fyy);
		});
    thread th(Timer);
	th1.join();
	th2.join();
	cout<<"Fx*Fy= ";
	result = Fxx * Fyy;
	cout << result;
	th.detach();
	return 0;
}