gcc -c count_vowels.c
gcc -c search_main.c
gcc -o count_vowels_exe count_vowels.o search_main.o
./count_vowels_exe