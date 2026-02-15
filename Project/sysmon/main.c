#include <stdio.h>
#include <unistd.h>

int main() {
    double uptime;
    int hours, minutes, seconds, total_seconds;
    
    unsigned long mem_total, mem_available;
    double total_gb, avail_gb;
    
    while (1) {
        FILE *uptime_file = fopen("/proc/uptime", "r");
        if (uptime_file == NULL) {
            printf("Nie można otworzyć /proc/uptime\n");
            return 1;
        }
        fscanf(uptime_file, "%lf", &uptime);
        fclose(uptime_file);

        total_seconds = (int) uptime;
        hours = total_seconds / 3600;
        minutes = (total_seconds % 3600) / 60;
        seconds = total_seconds % 60;

        FILE *ram_file = fopen("/proc/meminfo", "r");
        if (ram_file == NULL) {
            printf("Nie można otworzyć /proc/meminfo\n");
            return 1;
        }
        fscanf(ram_file, "MemTotal: %lu kB\nMemAvailable: %lu kB\n", &mem_total, &mem_available);
        fclose(ram_file);

        total_gb = mem_total / (1024.0 * 1024.0);
        avail_gb = mem_available / (1024.0 * 1024.0);

        printf("\033[H\033[J"); 
        printf("Working time: %02d:%02d:%02d\n", hours, minutes, seconds);
        printf("RAM: %.1f GB / %.1f GB\n", avail_gb, total_gb);

        sleep(1);
    }

    return 0;
}

