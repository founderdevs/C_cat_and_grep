#include <stdio.h>
#include <stdlib.h>

#define FIELD_WIDTH 80
#define FIELD_HEIGHT 25
#define RACKET_HEIGHT 3
#define WIN_SCORE 5

#define BALL_SYMBOL 'O'
#define RACKET_SYMBOL '|'
#define BORDER_SYMBOL '-'
#define SIDE_BORDER_SYMBOL '|'

int init_racket_y() { return FIELD_HEIGHT / 2; }
int init_ball_x() { return FIELD_WIDTH / 2; }
int init_ball_y() { return FIELD_HEIGHT / 2; }
int init_dx() { return 1; }
int init_dy() { return 1; }
int init_score() { return 0; }

int move_racket(int y, int dir) {
    if (dir == -1 && y - 1 > 1)
        y--;
    else if (dir == 1 && y + 1 < FIELD_HEIGHT - 2)
        y++;
    return y;
}

int move_ball_x(int bx, int dx) { return bx + dx; }
int move_ball_y(int by, int dy) { return by + dy; }

int bounce_dy(int by, int dy) {
    if (by <= 1 || by >= FIELD_HEIGHT - 2) dy = -dy;
    return dy;
}

int bounce_dx_left(int bx, int by, int ly, int dx) {
    if (bx == 3 && (by == ly - 1 || by == ly || by == ly + 1)) dx = 1;
    return dx;
}

int bounce_dx_right(int bx, int by, int ry, int dx) {
    if (bx == FIELD_WIDTH - 4 && (by == ry - 1 || by == ry || by == ry + 1)) dx = -1;
    return dx;
}

int check_goal_left(int bx) { return bx >= FIELD_WIDTH - 1; }
int check_goal_right(int bx) { return bx <= 0; }

int reset_ball_x() { return FIELD_WIDTH / 2; }
int reset_ball_y() { return FIELD_HEIGHT / 2; }

void draw_field(int ly, int ry, int bx, int by, int sl, int sr) {
    system("clear");
    printf("Score: %d - %d\n", sl, sr);
    for (int y = 0; y < FIELD_HEIGHT; y++) {
        for (int x = 0; x < FIELD_WIDTH; x++) {
            if (y == 0 || y == FIELD_HEIGHT - 1)
                printf("%c", BORDER_SYMBOL);
            else if (x == 0 || x == FIELD_WIDTH - 1)
                printf("%c", SIDE_BORDER_SYMBOL);
            else if (x == bx && y == by)
                printf("%c", BALL_SYMBOL);
            else if (x == 2 && (y == ly - 1 || y == ly || y == ly + 1))
                printf("%c", RACKET_SYMBOL);
            else if (x == FIELD_WIDTH - 3 && (y == ry - 1 || y == ry || y == ry + 1))
                printf("%c", RACKET_SYMBOL);
            else if (x == FIELD_WIDTH / 2)
                printf("|");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int main() {
    int ly = init_racket_y();
    int ry = init_racket_y();
    int bx = init_ball_x();
    int by = init_ball_y();
    int dx = init_dx();
    int dy = init_dy();
    int sl = init_score();
    int sr = init_score();

    draw_field(ly, ry, bx, by, sl, sr);

    while (sl < WIN_SCORE && sr < WIN_SCORE) {
        char input = getchar();
        if (input == 'a')
            ly = move_racket(ly, -1);
        else if (input == 'z')
            ly = move_racket(ly, 1);
        else if (input == 'k')
            ry = move_racket(ry, -1);
        else if (input == 'm')
            ry = move_racket(ry, 1);
        else if (input != ' ')
            continue;

        bx = move_ball_x(bx, dx);
        by = move_ball_y(by, dy);
        dy = bounce_dy(by, dy);
        dx = bounce_dx_left(bx, by, ly, dx);
        dx = bounce_dx_right(bx, by, ry, dx);

        if (check_goal_right(bx)) {
            sr++;
            bx = reset_ball_x();
            by = reset_ball_y();
            dx = 1;
            dy = 1;
        }
        if (check_goal_left(bx)) {
            sl++;
            bx = reset_ball_x();
            by = reset_ball_y();
            dx = -1;
            dy = 1;
        }

        draw_field(ly, ry, bx, by, sl, sr);
    }

    if (sl >= WIN_SCORE)
        printf("Left Player Wins!\n");
    else
        printf("Right Player Wins!\n");

    return 0;
}