#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Person {
	char name[16];
	int height;
};

/* compare function for sorting people - first according to their heights, then their names if there is a tie */
bool cmp(const Person &a, const Person &b) {
	if (a.height != b.height)
		return a.height > b.height;
	return strcmp(a.name, b.name) < 0;
}

int main() {
	int num_person, num_row, num_col;
	scanf("%d %d", &num_person, &num_row);
	num_col = num_person / num_row;
	Person *people = new Person[num_person];
	for (int i = 0; i < num_person; i++)
		scanf("%s %d", people[i].name, &people[i].height);
	sort(people, people + num_person, cmp);

	int idx_head = 0;	// the first person that has not been placed
	for (int i = 0; i < num_row; i++) {
		int cur_size = num_col;
		if (i == 0)
			cur_size += num_person % num_row;
		for (int j = idx_head + (cur_size / 2) * 2 - 1; j > idx_head; j -= 2)	// left to right: head + 2k + 1, ..., head + 1
			printf("%s ", people[j].name);
		printf("%s", people[idx_head].name);									// ...head
		for (int j = idx_head + 2; j < idx_head + cur_size; j += 2)				// ...head + 2, ..., head + 2k
			printf(" %s", people[j].name);
		printf("\n");
		idx_head += cur_size;
	}

	return 0;
}