#include "AudioMan.h"

typedef struct {
	float frequency;
	float interval;
	void (*func)(void);
} Task;

Task booper;
void checkTask(Task *t, float delta);

void game();
void exitLoop(void *p, float val);
void playBoop();

Sound *boop = 0;

int main(int args, char **argv) {
	initAudio();

	boop = processAudioFile("boop.wav");
	boop->loop = false;
	scheduleAudio(boop, 120.0);
	while (true) {}
}

void playBoop() {
	playAudio(boop);
}
/*

void checkTask(Task *t, float delta) {
	t->interval += delta;
	float frequency = 1.0 / t->frequency;
	int compound = t->interval / frequency;
	for (int i = 0; i < compound; i++) {
		if (t->interval >= frequency) {
			t->func();
			t->interval -= frequency;
		}
	}
}

void game() {
	float delta = deltaTime();
	checkTask(&booper, delta);
}

void exitLoop(void *p, float val) {
	if (val == 1) {
		stopLoop();
	}
}
*/
