#include <stdio.h>

int checkscore(const char std[], const char keys[], int n);
int countCorrectQ1(char ans[][10], char keys[], int nStd);


int main() {
    char ans[8][10] = {
        {'A','B','A','C','C','D','E','E','A','D'},
        {'D','B','A','B','C','A','E','E','A','D'},
        {'E','D','D','A','C','B','E','E','A','D'},
        {'C','B','A','E','D','C','E','E','A','D'},
        {'A','B','D','C','C','D','E','E','A','D'},
        {'B','B','E','C','C','D','E','E','A','D'},
        {'B','B','A','C','C','D','E','E','A','D'},
        {'E','B','E','C','C','D','E','E','A','D'}
    };

    char keys[10] = {'D','B','D','C','C','D','A','E','A','D'};

    for (int i = 0; i < 8; i++) {
        int score = checkscore(ans[i], keys, 10);
        printf("std %d => %d\n", i + 1, score);
    }

    int q1correct = countCorrectQ1(ans, keys, 8);
    printf("\nQuestion 1 correct = %d people\n", q1correct);

    int hardest = hardestQuestion(ans, keys, 8, 10);
    printf("Hardest question = Question %d\n", hardest);

    return 0;
}

int checkscore(const char std[], const char keys[], int n) {
    int score = 0;
    for (int j = 0; j < n; j++) {
        if (std[j] == keys[j]) score++;
    }
    return score;
}

int countCorrectQ1(char ans[][10], char keys[], int nStd) {
    int count = 0;
    for (int i = 0; i < nStd; i++) {
        if (ans[i][0] == keys[0]) count++;
    }
    return count;
}



    int min = correctCount[0];
    int hardest = 0;

    for (int q = 1; q < nQ; q++) {
        if (correctCount[q] < min) {
            min = correctCount[q];
            hardest = q;
        }
    }

    return hardest + 1;
}
