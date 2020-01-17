#include <bits/stdc++.h>
#include <conio.h>
void usage() {
    printf("Usage: kwcode <command> [<args>]\n");
    printf("\n");
    printf("There are all kwcode command used: \n");
    printf("   help       help information\n");
    printf("   version    version information\n");
    printf("   clear      clear all unnecessary files in this directory\n");
    printf("   run        compile and run a source code\n");
    printf("   compile    compile a source code\n");
    printf("\n");
    printf("Type `kwcode help <command>` for more information.\n");
}
void version() {
    printf("KwCode version 0.1.5\n");
    printf("Copyright WeKw team.\n");
}
void help(std::string str) {

}
void clear() {
    system("rm -rf *.in /s");
    system("rm -rf *.out /s");
    system("rm -rf *.gch /s");
    system("rm -rf *.exe /s");
    system("rm -rf *.ans /s");
    system("rm -rf tmp /s");
    system("rm -rf tmp* /s");
    system("rm -rf *tmp /s");
    system("rm -rf *tmp* /s");
    system("rm -rf test /s");
    system("rm -rf test* /s");
    system("rm -rf *test /s");
    system("rm -rf *test* /s");
}
std::pair<std::string, std::string> decFileName(std::string x) {
    if (x[x.size() - 1] != '.') {
        for (int i = x.size() - 2; ~i; --i) {
            if (x[i] == '.') {
                return std::make_pair(x.substr(0, i), x.substr(i + 1));
            }
        }
    }
    return std::make_pair(x, (std::string)(""));
}
void compile(std::string first, std::string seconed) {
    if (seconed == (std::string)("cpp")) {
        
    } else {
        printf("\033[33mError: KwCode doesn't support \"%s\" language.\033[0m\n", seconed);
    }
}
void run(std::string first, std::string seconed) {

}
int main(int n, char* a[]) {
    int f = 0;
    if (n == 1) {
        usage();
        return 0;
    }
    std::string tmp = a[1];
    if (tmp == (std::string)("help")) {
        if (n == 2) {
            usage();
        } else if (n == 3) {
            help((std::string)(a[2]));
        } else {
            printf("\033[33mError: Unknown \"%s\" for command \"help\".\033[0m\n", a[2]);
        }
    } else if (tmp == (std::string)("version")) {
        if (n == 2) {
            version();
        } else {
            printf("\033[33mError: Unknown \"%s\" for command \"version\".\033[0m\n", a[2]);
        }
    } else if (tmp == (std::string)("clear")) {
        if (n == 2) {
            clear();
        } else {
            printf("\033[33mError: Unknown \"%s\" for command \"clear\".\033[0m\n", a[2]);
        }
    } else if (tmp == (std::string)("run")) {
        if (n == 2) {
            printf("\033[33mError: Miss file name.\003[0m\n");
        } else if (n == 3) {
            std::pair<std::string, std::string> pair = decFileName((std::string)(a[2]));
            run(pair.first, pair.second);
        } else {
            printf("\033[33mError: Unknown \"%s\" for command \"run\".\033[0m\n", a[3]);
        }
    } else if (tmp == (std::string)("compile")) {
        if (n == 2) {
            printf("\033[33mError: Miss file name.\003[0m\n");
        } else if (n == 3) {
            std::pair<std::string, std::string> pair = decFileName((std::string)(a[2]));
            compile(pair.first, pair.second);
        } else {
            printf("\033[33mError: Unknown \"%s\" for command \"compile\".\033[0m\n", a[3]);
        }
    }
    else if (n == 3) {
        if (op(a[1], (char*)"run")) {
            std::string s = (std::string)"g++ -o " + (std::string)a[2] + (std::string)" " + (std::string)a[2] + (std::string)".cpp -lm -O3";
            system(s.data());
            printf("Complie is over.\n");
            s = (std::string)a[2];
            int c = clock();
            system(s.data());
            printf("The program is over in %dms.\n", clock() - c);
            while (_kbhit()) {
                getchar();
            }
            printf("Press any key to continue . . .");
            _getch();
            return 0;
        } else if (op(a[1], (char*)"compile")) {
            std::string s = (std::string)"g++ -o " + (std::string)a[2] + (std::string)" " + (std::string)a[2] + (std::string)".cpp -lm -O3";
            system(s.data());
            return 0;
        }
    }
    return 0;
}