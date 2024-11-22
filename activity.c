#include <stdio.h>

void activitySelection(int start[], int finish[], int n) {
    printf("Selected activities are:\n");

    int lastFinishTime = finish[0];
    printf("Activity [Start: %d, Finish: %d]\n", start[0], finish[0]);

    for (int i = 1; i < n; i++) {
        if (start[i] >= lastFinishTime) {
            printf("Activity [Start: %d, Finish: %d]\n", start[i], finish[i]);
            lastFinishTime = finish[i];
        }
    }
}

int main() {
    int n = 6;

    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};

    activitySelection(start, finish, n);

    return 0;
}
