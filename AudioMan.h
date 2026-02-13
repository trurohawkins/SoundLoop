#pragma once
#ifndef HELP
#define HELP
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include<stdbool.h>
#include<string.h>
#include <math.h>
#include <limits.h>
//#include "file.h"

void initDirections();
void freeDirections();
int **getDirs();
int **getDirs8();
float getAngle(int dir);
int *getDir8(int dir);
int *getDir4(int dir);
int d8Tod4(int);
int xyToDir4(int *xy);
int xyToDir8(int x, int y);
int convertInvert(bool inv);
float randPercent();
int randomInt(int upper);
int randRange(int mmin, int max);
int coinFlip(int a, int b);
int clamp(int, int, int);
double clampF(double, double, double);
float max(float a, float b);
float min(float a, float b);
int sign(int);
int signF(float num);
bool equal(float a, float b);
float lerp(float a, float b, float t);
float slerp(float a, float b, float t);
//int abs(int);
float distance(float x1, float y1, float x2, float y2);
char *fileToString(char *txt);
bool strCompare(char *str1, char *str2);
void printArray(int**, int, int);
bool compareColor(void *c1, void *c2);
int decPlace(int d);
float intToFrac(int i, int pow);

void testFunc();
#endif
#ifndef LL
#define LL
typedef struct linkedList
{
	void *data;
	struct linkedList *next;
	struct LinkedList *prev;
} linkedList;

#include <stdio.h>
#include <stdlib.h>

linkedList *makeList();

void addToList(linkedList **head, void *item);
bool addToListSingle(linkedList **head, void *item);
void printList(linkedList **head, char *listName, void (*print)(void*));
void listPrint(linkedList *head);
void *findList(linkedList **head, void *item, bool (*cmp)(void*, void*));
bool cmpList(linkedList **head, void *item, bool (*cmp)(void*, void*));
void *checkList(linkedList **head, bool (*chk)(void*));
bool isInList(linkedList **head, void *item);
bool isInListInt(linkedList **head, int item);
void *indexList(linkedList **head, int index);
void *removeFromList(linkedList **head, void *item);
bool checkAndDelete(linkedList **head, bool (*chk)(void*), void (*del)(void*));
void *removeFromListCheck(linkedList **head, bool (*chk)(void*));
void *removeFromListInt(linkedList **head, int item);
void checkAndRemove(linkedList **head, bool (*chk)(void*));
void **getContents(linkedList **head, int num);
int countContents(linkedList *head);
void freeList(linkedList **ll);
void deleteList(linkedList **ll, void (*deleteFunc)(void*));
void freeListSaveObj(linkedList **ll);
void *popList(linkedList **head);
#endif
#ifndef IL
#define IL

typedef struct intList
{
	int data;
	struct intList *next;
} intList;

intList *makeIntList(int data);
void addToIntList(intList **head, int item);
bool addToIntListSingle(intList **head, int item);
int removeFromIntList(intList **head, int item);
void checkAndRemoveInt(intList **head, bool (*chk)(int));
int countList(intList *head);
void freeIntList(intList **head);
#endif
#ifndef SORTEDLIST
#define SORTEDLIST

typedef struct SortedList {
	void *data;
	int val;
	struct SortedList *pre;
	struct SortedList *next;
} SortedList;

SortedList *makeSlist(void *data, int val);
void sortedAdd(SortedList **head, void *item, int val);
void *searchSlist(SortedList *cur, int val);
bool isInSlist(SortedList *cur, void *data);
void freeSlist(SortedList *head);
void printSlist(SortedList *head);
#endif
#ifndef BINARYWRITER
#define BINARYWRITER

#include <stdio.h>
#include <stdlib.h>
bool writeBinaryInt(char *file, int *val, int num);
int fput32le(int x, char *file);
int *readBinaryInt(FILE *fptr, int num);

#endif
#include <portaudio.h>
#include <sndfile.h>

//Frames PerBuffer
#define FPB 4096

typedef struct Sound {
	char *file;
	float *buff;
	long totalFrames;

	long readFrames;
	bool loop;
	int volume;
	bool active;

	//timing scheduling
	long long nextTriggerFrame;
	long long intervalFrames;
	long long bufferOffset;
	bool scheduled;
} Sound;

typedef struct AudioManager {
	linkedList *mix;
	int mixCount;
	float *volumes;
	int vGroups;
	linkedList *sounds;
	PaStream *stream;

	long long currentFrame;
	double sampleRate;
	double bpm;
} AudioManager;

extern AudioManager *aMan;

int initAudio();
void endAudio();
static int paLibsndfileCb(const void *inputBuffer, void *outputBuffer,
                          unsigned long framesPerBuffer,
                          const PaStreamCallbackTimeInfo* timeInfo,
                          PaStreamCallbackFlags statusFlags,
                          void *userData);
void cleanUpPlayedAudio();
void changeVolume(int group, float vol);
Sound *processAudioFile(char *file);
void changeVolGroup(Sound *s, int group);
void playAudio(Sound *s);
void stopAudio(Sound *s);
void scheduleAudio(Sound *s, double frequency);
int addVolGroup();
void freeSound(void *snd);
void freeAudioManager();

