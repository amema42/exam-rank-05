#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

enum cell_state { EMPTY = 0, OBSTACLE = 1, FULL = 2 };

typedef struct {
    int x, y, size;
} t_bsq;

typedef struct {
    int width, height;
    t_bsq bsq;
    char empty, obstacle, full;
    int **map;
    int **dp;
} t_data;

void free_data(t_data *data) {
    if (data->map) {
        for (int i = 0; i < data->height; i++) {
            free(data->map[i]);
        }
        free(data->map);
        data->map = NULL;
    }
    if (data->dp) {
        for (int i = 0; i < data->height; i++) {
            free(data->dp[i]);
        }
        free(data->dp);
        data->dp = NULL;
    }
}

int allocate_arrays(t_data *data) {
    data->map = malloc(data->height * sizeof(int*));
    data->dp = malloc(data->height * sizeof(int*));
    
    if (!data->map || !data->dp) {
        free_data(data);
        return 0;
    }
    
    for (int i = 0; i < data->height; i++) {
        data->map[i] = malloc(data->width * sizeof(int));
        data->dp[i] = calloc(data->width, sizeof(int));
        
        if (!data->map[i] || !data->dp[i]) {
            free_data(data);
            return 0;
        }
    }
    return 1;
}

int min3(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

int read_map(FILE *file, t_data *data) {
    memset(data, 0, sizeof(t_data));
    
    if (fscanf(file, "%d %c %c %c\n", &data->height, &data->empty, &data->obstacle, &data->full) != 4) {
        return 0;
    }
    
    if (data->height < 1) {
        return 0;
    }
    
    if (!isprint(data->empty) || !isprint(data->obstacle) || !isprint(data->full)) {
        return 0;
    }
    
    if (data->empty == data->obstacle || data->empty == data->full || data->obstacle == data->full) {
        return 0;
    }

    char *line = NULL;
    size_t len = 0;
    int y = 0;

    while (getline(&line, &len, file) != -1) {
        int read_len = strlen(line);
        
        if (line[read_len - 1] == '\n') {
            line[--read_len] = '\0';
        }
        
        if (read_len == 0) {
            free(line);
            return 0;
        }
        
        if (y == 0) {
            data->width = read_len;
        } 
        else if (read_len != data->width) {
            free(line);
            return 0;
        }
        
        y++;
        
        if (y > data->height) {
            free(line);
            return 0;
        }
    }
    
    free(line);
    
    if (y != data->height) {
        return 0;
    }
    
    if (!allocate_arrays(data)) {
        return 0;
    }
    
    fseek(file, 0, SEEK_SET);
    
    line = NULL;
    len = 0;
    getline(&line, &len, file);
    free(line);
    
    line = NULL;
    len = 0;
    y = 0;
    
    while (y < data->height && getline(&line, &len, file) != -1) {
        int read_len = strlen(line);
        if (line[read_len - 1] == '\n') {
            line[--read_len] = '\0';
        }
        
        for (int x = 0; x < data->width; x++) {
            if (line[x] == data->empty) {
                data->map[y][x] = EMPTY;
            } else if (line[x] == data->obstacle) {
                data->map[y][x] = OBSTACLE;
            } else {
                free(line);
                free_data(data);
                return 0;
            }
        }
        y++;
    }
    
    free(line);
    return 1;
}

void find_bsq(t_data *data) {
    data->bsq.size = 0;
    data->bsq.x = 0;
    data->bsq.y = 0;

    for (int y = 0; y < data->height; y++) {
        for (int x = 0; x < data->width; x++) {
            if (data->map[y][x] == OBSTACLE) {
                data->dp[y][x] = 0;
            } else {
                if (x == 0 || y == 0) {
                    data->dp[y][x] = 1;
                } else {
                    data->dp[y][x] = 1 + min3(
                        data->dp[y-1][x],
                        data->dp[y][x-1],
                        data->dp[y-1][x-1]
                    );
                }
                
                if (data->dp[y][x] > data->bsq.size) {
                    data->bsq.size = data->dp[y][x];
                    data->bsq.x = x - data->dp[y][x] + 1;
                    data->bsq.y = y - data->dp[y][x] + 1;
                }
            }
        }
    }
    
    for (int y = 0; y < data->bsq.size; y++) {
        for (int x = 0; x < data->bsq.size; x++) {
            data->map[data->bsq.y + y][data->bsq.x + x] = FULL;
        }
    }
}

void print_map(t_data *data) {
    for (int y = 0; y < data->height; y++) {
        for (int x = 0; x < data->width; x++) {
            if (data->map[y][x] == EMPTY) {
                fputc(data->empty, stdout);
            } else if (data->map[y][x] == OBSTACLE) {
                fputc(data->obstacle, stdout);
            } else {
                fputc(data->full, stdout);
            }
        }
        fputc('\n', stdout);
    }
}

void process_map(FILE *file) {
    t_data data;
    
    if (!read_map(file, &data)) {
        fprintf(stderr, "map error\n");
        return;
    }
    
    find_bsq(&data);
    print_map(&data);
    
    free_data(&data);
}

int main(int argc, char **argv) {
    if (argc == 1) {
        process_map(stdin);
    } else {
        for (int i = 1; i < argc; i++) {
            FILE *file = fopen(argv[i], "r");
            if (!file) {
                fprintf(stderr, "map error\n");
                if (i < argc - 1) {
                    fputc('\n', stdout);
                }
                continue;
            }
            
            process_map(file);
            fclose(file);
            
            if (i < argc - 1) {
                fputc('\n', stdout);
            }
        }
    }
    
    return 0;
}
