# makefile
all: rm cm

rm: avg_mat_rm.c main.c init_rm.c init.h avg_mat.h
	gcc -O3 -o rm main.c init_rm.c avg_mat_rm.c

cm: avg_mat_cm.c main.c init_cm.c init.h avg_mat.h
	gcc -O3 -o cm main.c init_cm.c avg_mat_cm.c

clean:
	rm -f rm rc *.o
