#include "funcs.h"

long answer1() {
	long scores[465] = {};
	node* head = new node;
	head->val = 0;
	head->next = head;
	head->prev = head;
	for (int i = 1; i <= 7194000; ++i) {
		if (i % 23) {
			node* temp = new node;
			temp->val = i;
			temp->next = head->next->next;
			temp->prev = head->next;
			head->next->next->prev = temp;
			head->next->next = temp;
			head = temp;
		}
		else {
			scores[i % 465] += i;
			for (int j = 0; j < 7; ++j) {
				head = head->prev;
			}
			scores[i % 465] += head->val;
			head->prev->next = head->next;
			head->next->prev = head->prev;
			//node* temp = head;
			head = head->next;
			//delete temp;
		}
	}
	long max = 0;
	for (int i = 0; i < 465; ++i) {
		if (scores[i] > max) {
			max = scores[i];
		}
	}
	return max;
}

long answer2() {
	return 0;
}























//
