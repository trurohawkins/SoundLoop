#include "FormNetwork.h"

void game();
void exitLoop(void *p, float val);

Sound *boop = 0;

int main(int args, char **argv) {
	initFormGlfw();
	initAudio();
	Player *GM = makePlayer(0, 1, 0);
	addPlayer(GM);
	addControl(GM, "K0!", exitLoop);

	boop = processAudioFile("boop.wav");
	boop->loop = false;
	FormLoop(game);
	exitGame();
}

int timer = 0;
int frequency = 30;

void game() {
	if (timer > frequency) {
		playAudio(boop);
		timer = 0;
	} else {
		timer++;
	}
}

void exitLoop(void *p, float val) {
	if (val == 1) {
		stopLoop();
	}
}
