#include "FormNetwork.h"

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

float deltaTime() {
	static double lastFrame = 0;
	double currentFrame = glfwGetTime();
	float elapsed = (currentFrame - lastFrame);// * 1000.0;
	lastFrame = currentFrame;
	return elapsed;
}

Sound *boop = 0;

int main(int args, char **argv) {
	initFormGlfw();
	initAudio();
	Player *GM = makePlayer(0, 1, 0);
	addPlayer(GM);
	addControl(GM, "K0!", exitLoop);

	boop = processAudioFile("boop.wav");
	boop->loop = false;
	booper.frequency = 12;
	booper.interval = 0;
	booper.func = playBoop;
	FormLoop(game);
	exitGame();
}

void playBoop() {
	playAudio(boop);
}

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
