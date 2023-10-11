#include <stdio.h>


#define TD_PLUS_2PT 8
#define TD_PLUS_FG 7
#define TD 6
#define FG 3
#define SAFETY 2


int main() {

    int score;


    printf("Enter 0 or 1 to stop\n");
    do {
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        if (score <= 1) {
            printf("Goodbye...\n");
            return 0;
        }
        printf("possible combinations of scoring plays\n");


        for(int tdplus2pt = 0; tdplus2pt * TD_PLUS_2PT <= score; tdplus2pt++) {
            for(int tdplusfg = 0; tdplusfg * TD_PLUS_FG <= score; tdplusfg++) {
                for(int td = 0; td * TD <= score; td++) {
                    for(int fg = 0; fg * FG <= score; fg++) {
                        for(int safety = 0; safety * SAFETY <= score; safety++) {
                            if((tdplus2pt * TD_PLUS_2PT) + (tdplusfg * TD_PLUS_FG) + (td * TD)
                            + (fg * FG) + (safety * SAFETY) == score) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                tdplus2pt, tdplusfg, td, fg, safety);
                            }
                        }
                    }
                }
            }   
        }   

    } 
        while(score > 1);

        return 0;
}
