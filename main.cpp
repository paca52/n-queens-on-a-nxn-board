#include <iostream>
#include <vector>
#include <math.h>

#define MAX 100
#define REP(i, a, b) for(int i=a; i<b; i++)

int n;
int mat[MAX][MAX];
int br_kraljica = 0;
std::vector<std::pair<int, int>> kraljice;

void make_kraljice() {
    REP(i, 0, n) {
        kraljice.push_back(std::pair<int, int> { -1, -1 });
    }
}

int num_of_sol = 0;
void pisi() {
    std::cout << "Solution " << ++num_of_sol << ":\n";
    REP(i, 0, n) {
        std::cout << "\t";
        REP(j, 0, n)
            std::cout << mat[i][j] << " ";
        std::cout << "\n";
    }
}

bool check(int k, int p) {
    REP(i, 0, n) {
        if(kraljice[i] == std::pair<int,int>{ -1, -1 })
            continue;

        if(
            kraljice[i].first == k ||
            kraljice[i].second == p ||
            ( abs( kraljice[i].first - k ) == abs( kraljice[i].second - p ) )
        ) return false;
    }

    return true;
}

void print_kraljice() {
    std::cout << "Kraljice:\n";
    for( std::pair<int, int>& p : kraljice ) 
        std::cout << "\t" << p.first << " " << p.second << "\n";
}

void solve(int k) {

        // std::cout << "\tpocetak funkcije\n";

    // std::cout << "br_kraljica: " << br_kraljica << "\n";
    // std::cout << "k = " << k << "\n";
    // print_kraljice();

    if(br_kraljica == n) pisi();
    else {
        REP(i, 0, n) {
            if(check(i, k)) {
                mat[i][k] = 1;
                kraljice[k] = { i, k };
                br_kraljica++;
                solve(k + 1);
                mat[i][k] = 0;
                kraljice[k] = { -1, -1 };
                br_kraljica--;
            }
        }
    }
    // std::cout << "\tkraj funkcije\n";

}

int main(void) {
    std::cin >> n;    

    make_kraljice();
    print_kraljice();


    REP(i, 0, n) {
        REP(j, 0, n) {
            mat[i][j] = 0;
        }
    }

    solve(0);

    return 0;
}