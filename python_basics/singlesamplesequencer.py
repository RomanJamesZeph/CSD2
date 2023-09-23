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

# Creates timestamps_16th list and fills it from note durations
timestamps_16th = [0.0]
for note_dur in note_durations:
	timestamps_16th.append(timestamps_16th[-1] + (note_dur * 4))
print(timestamps_16th)

# Calculates sixteenth note duration
sixteenthNoteDuration = 15.0 / bpm

# Creates timestamps_ms list and fills it from timestamps_16th
timestamps_ms = []
for timestamp in timestamps_16th:
	timestamps_ms.append(timestamp * sixteenthNoteDuration)
print(timestamps_ms)

# First timestamp
if timestamps_ms:
    ts = timestamps_ms.pop(0)
else:
    # list contains no items
    print("no timestamps --> exit")
    exit()

# Loads sample
sampleBoing = sa.WaveObject.from_wave_file("/Library/Audio/Samples/Sound Kits/cartoon/boing.wav")

# store the current time
time_zero = time.time()

# iterate through time sequence and play sample when time lines up with timestamp
while True:
	now = time.time() - time_zero
	if (now >= ts):
		sampleBoing.play()
		if timestamps_ms:
			ts = timestamps_ms.pop(0)
		else:
			break
	time.sleep(0.001)