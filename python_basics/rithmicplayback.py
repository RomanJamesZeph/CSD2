import simpleaudio as sa
import time

noteDuration = []

numPlaybackTimes = int(input("Aantal keren dat de sample wordt afgespeeld?"))

for _ in range(numPlaybackTimes):
	noteDuration.append(float(input("noteDuration?")))

bpm = float(input("BPM?"))

wave_obj = sa.WaveObject.from_wave_file("/Library/Audio/Samples/Sound Kits/cartoon/boing.wav")
for i in range(numPlaybackTimes):
	play_obj = wave_obj.play()
	play_obj.wait_done()