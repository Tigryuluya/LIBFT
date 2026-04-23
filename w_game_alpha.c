#include "libft.h"

#define H 16
#define W 36

void ft_printchar (char c) {
    write(1, &c, 1);
}

void ft_putstr (char *str) {
	int i = 0;

	while (str[i] != '\0') {
		ft_printchar(str[i]);
		i++;
	}
}

//disable enter press
void enable_raw_mode () {
    struct termios t;

    tcgetattr(0, &t);
    t.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &t);
}

void buildMapGameOver (char map[H][W]) {
    char tmp[H][W] = {
		"####################################",
		"#                                  #",
        "#   #####    ##    #   #  ######   #",
        "#  #       ##  ##  ## ##  ##       #",
        "#  #   ##  ######  # # #  #####    #",
        "#  #    #  ##  ##  #   #  ##       #",
        "#   #####  ##  ##  #   #  ######   #",
		"#                                  #",
        "#   ####   ##  ##  ######  #####   #",
        "#  #    #  ##  ##  ##      ##   #  #",
        "#  #    #  ##  ##  ####    #####   #",
        "#  #    #  ##  ##  ##      ## ##   #",
        "#   ####     ##    ######  ##   #  #",
		"#                                  #",
		"#            Heilbron 42           #",
		"####################################",
    };

	int i = 0;
	int j = 0;

	while (i < H) {
		j = 0;

		while (j <= W) {
			map[i][j] = tmp[i][j];

			j++;
		}

		i++;
	}
}

void buildMap (char map[H][W]) {
    char tmp[H][W] = {
		"####################################",
		"#........#.........#...............#",
		"#.#######.#.#####.#.#.#######..#...#",
		"#.#.....#.#.....#.#.#.#.....#..#.#.#",
		"#.#.###.#.#####.#.#.#.#.###.#..#...#",
		"#.#.#.#.#.......#.#.#.#.#.#.#..#.#.#",
		"#.#.#.#.#########.#.#.#.#.#.#..#...#",
		"#...#.#...........#...#.#.#....#.#.#",
		"###.#.#############.###.#.######.#.#",
		"#...#.......Y.......#...#......#...#",
		"###.#.#############.###.#.######.###",
		"#...#.#...........#...#.#......#.#.#",
		"#.#.#.#.#########.#.#.#.#.#....#.#.#",
		"#.#.#.#.......#.#.#.#.#.#.#....#...#",
		"#Y........#.........#............#.#",
		"####################################",
    };

	int i = 0;
	int j = 0;

	while (i < H) {
		j = 0;

		while (j <= W) {
			map[i][j] = tmp[i][j];

			j++;
		}

		i++;
	}
}

typedef struct s_entity {
	int y;
	int x;
	int dy;
	int dx;
	int next_dy;
	int next_dx;
	int points;
	int anim;
	int anim_state;
	int type;
	float speed;
	float acc;
	int good;
	int isLive;
} t_entity;

void handleInput (char key, t_entity *p) {
	if (key == 'w')      { p->next_dy = -1; p->next_dx = 0;  }
	else if (key == 's') { p->next_dy = 1;  p->next_dx = 0;  }
	else if (key == 'a') { p->next_dy = 0;  p->next_dx = -1; }
	else if (key == 'd') { p->next_dy = 0;  p->next_dx = 1;  }   
}

void animation (t_entity *p) {
    if (p->anim_state == 1) {
		p->anim = '<';
	}
    else {
		p->anim = 'C';
	}

    p->anim_state = !(p->anim_state);
}

int dirs[4][2] = {
    {0, -1}, // left
    {0, 1},  // right
    {-1, 0}, // up
    {1, 0}   // down
};

t_entity initPlayer (int y, int x) {
	t_entity player;

	player.y          = y;
	player.x          = x;
	player.dy         = 0;
	player.dx         = 0;
	player.next_dy    = 0;
	player.next_dx    = 0;
	player.points     = 0;
	player.anim       = 'C';
	player.anim_state = 0;
	player.type       = 1;
	player.speed      = 0.5;
	player.acc        = 0;
	player.good       = 0;
	player.isLive     = 1;

	return player;
}

void initBots (t_entity *bots) {
    bots[0] = (t_entity) { 10, 5,  0, 0, 0, 0, 0, 'B', 0, 2, 0.35, 0, 0, 1 };
    bots[1] = (t_entity) { 14, 7,  0, 0, 0, 0, 0, 'B', 0, 2, 0.35, 0, 0, 1 };
    bots[2] = (t_entity) { 14, 10, 0, 0, 0, 0, 0, 'B', 0, 2, 0.35, 0, 0, 1 };
    bots[3] = (t_entity) { 5,  20, 0, 0, 0, 0, 0, 'B', 0, 2, 0.35, 0, 0, 1 };
    bots[4] = (t_entity) { 14, 30, 0, 0, 0, 0, 0, 'B', 0, 2, 0.35, 0, 0, 1 };
}

void killEntity (t_entity *entity) {
	entity->y          = -1;
	entity->x          = -1;
	entity->dy         = 0;
	entity->dx         = 0;
	entity->next_dy    = 0;
	entity->next_dx    = 0;
	entity->points     = 0;
	entity->anim_state = 0;
	entity->type       = 0;
	entity->speed      = 0;
	entity->acc        = 0;
	entity->good       = 0;
	entity->isLive     = 0;
}

void updatePlayer (char map[H][W], t_entity *entity) {
	entity->acc += entity->speed;

	animation(entity);

	if (entity->acc >= 1.0) {
		// simylator Turn
			int try_y = entity->y + entity->next_dy;
			int try_x = entity->x + entity->next_dx;

			if (try_x < 0 || try_x >= W || try_y < 0 || try_y >= H) {
				return;
			}

			// if not wall
			if (map[try_y][try_x] != '#') {
				entity->dy = entity->next_dy;
				entity->dx = entity->next_dx;
			}

		// main logic
		int new_y = entity->y + entity->dy;
		int new_x = entity->x + entity->dx;

		// if food then points
		if (entity->type == 1 && map[new_y][new_x] == 'Y') {
			entity->good = 1;

			map[new_y][new_x] = ' ';
			entity->points += 42;
		}

		// if food then points
		if (entity->type == 1 && map[new_y][new_x] == '.') {
			map[new_y][new_x] = ' ';

			entity->points++;
		}

		// if not wall
		if (map[new_y][new_x] != '#') {
			entity->y = new_y;
			entity->x = new_x;
		}

		entity->acc = 0;
	}
}

void renderMap (char map[H][W], t_entity p, t_entity bots[5]) {
    int y = 0;
    int x = 0;
	int i = 0;
	int printed;

	int b;
	static char buffer[20000];

	write(1, "\033[H\033[J", 6);

    while (y < H) {
        x = 0;

        while (x < W) {
			printed = 0;
			b = 0;

			while (b < 5) {
				// if (bots[b].isLive == 0) {
				// 	break;
				// }

				if (y == bots[b].y && x == bots[b].x) {
					buffer[i++] = '\033';
					buffer[i++] = '[';
					buffer[i++] = '3';
					buffer[i++] = '1';
					buffer[i++] = 'm';

					buffer[i++] = 'B';

					buffer[i++] = '\033';
					buffer[i++] = '[';
					buffer[i++] = '0';
					buffer[i++] = 'm';

					printed = 1;
					break;
				}

				b++;
			}

			if (printed) {
				x++;
				continue;
			}

			if (y == p.y && x == p.x) {
				buffer[i++] = '\033';
				buffer[i++] = '[';
				buffer[i++] = '3';
				buffer[i++] = '3';
				buffer[i++] = 'm';

				buffer[i++] = p.anim;

				buffer[i++] = '\033';
				buffer[i++] = '[';
				buffer[i++] = '0';
				buffer[i++] = 'm';
			}
			else if (map[y][x] == '.') {
				buffer[i++] = '\033';
				buffer[i++] = '[';
				buffer[i++] = '3';
				buffer[i++] = '3';
				buffer[i++] = 'm';

				buffer[i++] = map[y][x];

				buffer[i++] = '\033';
				buffer[i++] = '[';
				buffer[i++] = '0';
				buffer[i++] = 'm';
			}
			else if (map[y][x] == 'Y') {
				buffer[i++] = '\033';
				buffer[i++] = '[';
				buffer[i++] = '3';
				buffer[i++] = '2';
				buffer[i++] = 'm';

				buffer[i++] = map[y][x];

				buffer[i++] = '\033';
				buffer[i++] = '[';
				buffer[i++] = '0';
				buffer[i++] = 'm';
			}
			else {
				buffer[i++] = map[y][x];
			}
			
            x++;
        }
        buffer[i++] = '\n';
        y++;
    }

	write(1, buffer, i);
}



// this function with ChatGTP, but logic is simpl
void botAI (char map[H][W], t_entity *bot, t_entity *player) {
    int best_dx = 0;
    int best_dy = 0;
    int best_dist = 999999;

    for (int i = 0; i < 4; i++) {
        int dx = dirs[i][1];
        int dy = dirs[i][0];

        int nx = bot->x + dx;
        int ny = bot->y + dy;

		// check border map, and check wall
		if (nx < 0 || nx >= W || ny < 0 || ny >= H) {
			continue;
		}
		else if (map[ny][nx] == '#') {
			continue;
		}

        if (dx == -bot->dx && dy == -bot->dy) {
			continue;
		}

        int dist = abs(player->x - nx) + abs(player->y - ny);

        if (dist < best_dist) {
            best_dist = dist;
            best_dx = dx;
            best_dy = dy;
        }
    }

    if (best_dist == 999999) {
        bot->next_dx = -bot->dx;
        bot->next_dy = -bot->dy;
    }
    else {
        bot->next_dx = best_dx;
        bot->next_dy = best_dy;
    }
}

int main () {
	int b;
	int move_tick = 0;
	int checkBot_i = 0;
    char map[H][W];

    fcntl(0, F_SETFL, O_NONBLOCK);
    enable_raw_mode();

    t_entity player = initPlayer(1, 1);
    t_entity bots[5];

    buildMap(map);
    initBots(bots);

    while (1) {
        char key;

        if (read(0, &key, 1) > 0) {
			handleInput(key, &player);
		}

		move_tick++;
		if (move_tick % 5 == 0) {
			updatePlayer(map, &player);

			b = 0;
			while (b < 5) {
				if (bots[b].isLive != 0) {
					botAI(map, &bots[b], &player);
					updatePlayer(map, &bots[b]);
				}

				b++;
			}
		}

		checkBot_i = 0;

		while (checkBot_i < 5) {
			if (bots[checkBot_i].isLive == 0) {
				checkBot_i++;
				break;
			}

			if (player.x == bots[checkBot_i].x && player.y == bots[checkBot_i].y) {
				if (player.good == 1) {
					killEntity(&bots[checkBot_i]);
				}
				else {
					buildMapGameOver(map);

					int tt = 0;
					while (tt < 5) {
						killEntity(&bots[tt]);
						tt++;
					}

					killEntity(&player);

					renderMap(map, player, bots);

					printf("Your points: %d\n", player.points);
					break;
				}
			}

			checkBot_i++;
		}

        renderMap(map, player, bots);

        printf("\nYour points: %d\n", player.points);

        usleep(16000);
    }
}