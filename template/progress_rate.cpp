#include<iostream>
#include<iomanip>
#include<sstream>
#include<stdio.h>
#include<unistd.h>

namespace ProgressBar {
	std::string flags = "-\\|/";
	char finish = '#';
	std::string progress;
	ushort current_progress = 0; // 万进制
	clock_t start;

	void init() {
		current_progress = 0;
		progress = std::string(100, '.');
		start = clock();
	}
	void print_bar(long long now_cnt, long long total_cnt) {
		if(now_cnt * 10000 / total_cnt <= current_progress) return ;
		for(int i = current_progress/100;i<=now_cnt * 100 / total_cnt;i++) {
			progress[i] = finish;
		}
		current_progress = now_cnt * 10000 / total_cnt;

		std::string prefix, suffix;
		if(now_cnt>=total_cnt) {
			prefix = "\e[1;32mO\e[m";
			suffix = "\e[1;32m100%\e[m";
		} else {
			prefix = flags[current_progress%4];
			std::stringstream ss;
			ss << std::setfill('0') << std::setw(2)<< current_progress / 100 << "." << std::setfill('0') << std::setw(2) << current_progress%100 << "%";
			ss >> suffix;
		}

		std::cout<<std::unitbuf
			<<"["<<prefix<<"]"
			<<"["<<progress<<"]"
			<<"["<<suffix<<"] "<< (1.0*(clock()-start) / CLOCKS_PER_SEC)<<"s        "<<'\r';

		if(now_cnt>=total_cnt) std::cout<<std::endl;
	}
}
