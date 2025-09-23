#include<iostream>
#include<iomanip>
#include<sstream>
#include<stdio.h>
#include<unistd.h>
#include<sys/ioctl.h>
#include<termios.h>
#include<unistd.h>

std::string green(std::string a) {
    return "\033[1;32m" + a + "\033[0m";
}

namespace ProgressBar {
	std::string flags = "-\\|/";
	char finish = '#';
	std::string progress;
	ushort current_progress = 0; // 万进制
	clock_t start;

    int progress_visiable_chars = 100;

    void init_progress_visiable_chars() {
        struct winsize info;
        ioctl(STDIN_FILENO,TIOCGWINSZ,&info);
        progress_visiable_chars = info.ws_col-35;
        // std::cout<<progress_visiable_chars<<std::endl;
    }

	void init() {
        init_progress_visiable_chars();
		current_progress = 0;
		progress = std::string(progress_visiable_chars, '.');
		start = clock();
	}

    int show_flag = 0;

	void print_bar(long long now_cnt, long long total_cnt) {
        if(++show_flag < 100000) return ;
        show_flag = 0;
		// if(now_cnt * 500 * progress_visiable_chars / total_cnt <= current_progress) return ;
		for(int i = current_progress/100;i<=now_cnt * progress_visiable_chars / total_cnt;i++) {
			progress[i] = finish;
		}
		current_progress = now_cnt * 100 * progress_visiable_chars / total_cnt;

		std::string prefix, suffix;
		if(now_cnt>=total_cnt) {
			prefix = green("O");
			suffix = green("100%");
		} else {
			prefix = flags[current_progress%4];
			std::stringstream ss;
			ss << std::setfill('0') << std::setw(2)<< current_progress / progress_visiable_chars << "." << std::setfill('0') << std::setw(2) << (now_cnt*10000/total_cnt)%100 << "%";
			ss >> suffix;
		}

		std::cout<<std::unitbuf
			<<"["<<prefix<<"]"
			<<"["<<progress<<"]"
			<<"["<<suffix<<"] "<< (1.0*(clock()-start) / CLOCKS_PER_SEC)<<"s        "<<'\r';

		if(now_cnt>=total_cnt) std::cout<<std::endl;
	}
}
