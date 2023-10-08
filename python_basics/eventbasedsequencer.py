import simpleaudio as sa
import time

hihat = sa.WaveObject.from_wave_file(
    "/Users/romanjameszeph/HKU/Jaar2/CSD2/CSD_23-24/blok2a/assets/hihat.wav"
)
snare = sa.WaveObject.from_wave_file(
    "/Users/romanjameszeph/HKU/Jaar2/CSD2/CSD_23-24/blok2a/assets/snare.wav"
)
kick = sa.WaveObject.from_wave_file(
    "/Users/romanjameszeph/HKU/Jaar2/CSD2/CSD_23-24/blok2a/assets/kick.wav"
)

hihat_event = {
    "noteDurations": [],
    "timestamps16th": [0.0],
    "timestampsMs": [],
    "instrumentname": "hihat",
    "instrument": hihat,
    "velocity": 82,
    "duration": 100,
}

snare_event = {
    "noteDurations": [],
    "timestamps16th": [0.0],
    "timestampsMs": [],
    "instrumentname": "snare",
    "instrument": snare,
    "velocity": 82,
    "duration": 100,
}

kick_event = {
    "noteDurations": [],
    "timestamps16th": [0.0],
    "timestampsMs": [],
    "instrumentname": "kick",
    "instrument": kick,
    "velocity": 82,
    "duration": 100,
}

# stores all events in list
events = [kick_event, hihat_event, snare_event]

# bpm input
try:
    bpm = float(
        input("Standard BPM is 100, leave empty to continue or type your own BPM")
    )
except ValueError:
    bpm = 100

# note duration input
for event in events:
    correctInput = False
    while not correctInput:
        try:
            event_name = event['instrumentname']
            noteDurationInput = float(input(f"Give note duration for {event_name}"))
            event["noteDurations"].append(noteDurationInput)
        except ValueError:
            print(event['instrumentname'], "note durations:")
            print(event["noteDurations"])
            correctInput = True
print("\n")

# note duration to timestamps16th
for event in events:
    for noteDuration in event["noteDurations"]:
        event["timestamps16th"].append(event["timestamps16th"][-1] + noteDuration * 4)
    event["timestamps16th"].pop(0)
    print(event["instrumentname"], "timestamps in 16th:")
    print(event["timestamps16th"])
print("\n")

# Calculates sixteenth note duration
sixteenthNoteDuration = 15.0 / bpm

# timestamps16th to timestampsMs
for event in events:
    for timestamp16th in event["timestamps16th"]:
        event["timestampsMs"].append(timestamp16th * sixteenthNoteDuration)
    print(event["instrumentname"], "timestamps in ms")
    print(event["timestampsMs"])
print("\n")

# fuction to play event
def event_handler(event):
    event["instrument"].play()

# Creates a list of all timestamps from every event and sorts them
all_timestamps = []
for event in events:
    all_timestamps.extend(event["timestampsMs"])
all_timestamps.sort()

# stores current time in ms
current_time = time.time()

# Initialize a dictionary to keep track of played events
played_events = {}

# Iterate through each timestamp and calculate time to sleep
for timestamp in all_timestamps:
    time_to_sleep = timestamp - current_time

    if time_to_sleep > 0:
        time.sleep(time_to_sleep)

    # Iterate through each event and check if the current timestamp is present in the timestamps list
    for event in events:
        if timestamp in event["timestampsMs"]:
            event_name = event["instrumentname"]
            
            # Check if this event has already been played at this timestamp
            if event_name not in played_events or timestamp not in played_events[event_name]:
                print(f"Current Time: {timestamp} seconds, Instrument: {event_name}")
                event_handler(event)
                
                # Mark the event as played at this timestamp
                if event_name not in played_events:
                    played_events[event_name] = set()
                played_events[event_name].add(timestamp)

    # Update current_time to the current timestamp
    current_time = timestamp

time.sleep(1)