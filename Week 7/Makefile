all: quicksort_lomoto quicksort_hoare quicksort_median quicksort_modified quicksort_random

quicksort_lomoto: quicksort_lomoto.cpp
	g++ -o quicksort_lomoto quicksort_lomoto.cpp
	./quicksort_lomoto

quicksort_hoare: quicksort_hoare.cpp
	g++ -o quicksort_hoare quicksort_hoare.cpp
	./quicksort_hoare

quicksort_median: quicksort_median.cpp
	g++ -o quicksort_median quicksort_median.cpp
	./quicksort_median

quicksort_modified: quicksort_modified.cpp
	g++ -o quicksort_modified quicksort_modified.cpp
	./quicksort_modified

quicksort_random: quicksort_random.cpp
	g++ -o quicksort_random quicksort_random.cpp
	./quicksort_random

clean:
	rm -f *.o quicksort_lomoto quicksort_hoare quicksort_median quicksort_modified quicksort_random

