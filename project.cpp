#include <iostream>
#include <Windows.h>
#include <thread>
#include <chrono>
#include <thread>
#include <cstdlib>
using namespace std;
bool running = false;

void mouseClick() {
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}
void checker() {
	while (true) {
		if (GetAsyncKeyState('C') & 0x8000) {
			running = true;
			Sleep(150);
		}
		if (GetAsyncKeyState('X') & 0x8000) {
			running = false;

		}
	}
}
thread checkerThread(checker);

	int main() {
		std::srand(std::time(0));

	std::cout << "press p to activate autoclicker and L to stop it" << endl;
	while (true) {
		if (running) {
			int interval = 25 + (rand() % 55);

			mouseClick();
			Sleep(interval);

		}
	}
}
