#include <iostream>

using namespace std;

class Team {
    private:
        int score;

    public:
        Team(){}
        Team(int score): score(score) {}
        
        int getScore() {
            return this->score;
        }

        void PrintScore() {
            cout << "Score: " << this->score << endl;
        }

        Team operator+ (const Team& another) {
            return Team(this->score + another.score);
        }

        Team operator- (const Team& another) {
            return Team(this->score - another.score);
        }

        Team &operator++ (int) {
            this->score++;
            return *this;
        }

        Team operator++ () {
            ++this->score;
            return Team(this->score);
        }

        void operator-- (int) {
            this->score--;
        }

        void operator-- () {
            --this->score;
        }
};

int main() {
    Team t1(1);
    Team t2(2);
    Team t3(3);
    Team summation;
    Team subtraction;
    Team mix;

    summation = t1 + t2;
    summation.PrintScore();

    subtraction = t2 - t1;
    subtraction.PrintScore();

    mix = t1 + t2 - t3;
    mix.PrintScore();

    putchar('\n');

    summation--;
    summation.PrintScore();
    subtraction++;
    subtraction.PrintScore();
    ++mix;
    --mix;
    mix.PrintScore();
    return 0;
}