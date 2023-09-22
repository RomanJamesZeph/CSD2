import simpleaudio as sa
import time


# Asks for bpm
try:
	bpm = float(input("Standard BPM is 100, leave empty to continue or type your own BPM"))
except ValueError:
	bpm = 100

# Asks for playback times
num_playback_times = int(input("How many times do you want to play the sample?"))

# Creates note durations list and fils it with user input
note_durations = []
for i in range(num_playback_times):
	note_durations.append(float(input("Note duration?")))

# Calculates quarternote duration
quarternote_duration = 60.0 / bpm

# Creates time durations list and fills it from note durations
time_durations = []
for note in note_durations:
	time_durations.append(quarternote_duration * note)

# Creates timestamp sequence list and fills it from time durations
timestamp_seq = []
sum = 0
for time_dur in time_durations:
    timestamp_seq.append(sum)
    sum = sum + time_dur

if timestamp_seq:
    ts = timestamp_seq.pop(0)
else:
    # list contains no items
    print("no timestamps --> exit")
    exit()

# store the current time
time_zero = time.time()


# Loads sample
sampleBoing = sa.WaveObject.from_wave_file("/Library/Audio/Samples/Sound Kits/cartoon/boing.wav")


# iterate through time sequence and play sample when time lines up with timestamp
while True:
	now = time.time() - time_zero
	if (now >= ts):
		sampleBoing.play()
		if timestamp_seq:
			ts = timestamp_seq.pop(0)
		else:
			break
	time.sleep(0.001)

# Durations To Timestamps16th
timestamps_16th = [0.]
for note_dur in note_durations:
	timestamps_16th.append(timestamps_16th[-1] + (note_dur * 4))
print(timestamps_16th)

# wait till last sample is done playing before exit
time.sleep(time_durations[-1])