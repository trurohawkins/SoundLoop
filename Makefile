soundTest: main.c libAudioMan.a
	gcc main.c libAudioMan.a libHelper.a -lportaudio -lsndfile -lm -o SoundLoop

libs:
	$(MAKE) -C ../FormNetwork
	cp ../FormNetwork/libAudioMan.a .
	cp ../FormNetwork/AudioMan.h .
	cp ../FormNetwork/libHelper.a .
	$(MAKE)
