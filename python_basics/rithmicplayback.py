import simpleaudio as sa
import time

noteDuration = []

numPlaybackTimes = int(input("Aantal keren dat de sample wordt afgespeeld?"))

for _ in range(numPlaybackTimes):
	noteDuration.append(float(input("note duration?")))

bpm = float(input("BPM?"))

wave_obj = sa.WaveObject.from_wave_file("/Library/Audio/Samples/Sound Kits/cartoon/boing.wav")
for duration in noteDuration:
	play_obj = wave_obj.play()
	time.sleep((60 / bpm) * duration)