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
    "timestamp": [],
    "instrumentname": "hihat",
    "instrument": hihat,
    "velocity": 82,
    "duration": 100,
}

snare_event = {
    "timestamp": [],
    "instrumentname": "snare",
    "instrument": snare,
    "velocity": 82,
    "duration": 100,
}

kick_event = {
    "timestamp": [],
    "instrumentname": "kick",
    "instrument": kick,
    "velocity": 82,
    "duration": 100,
}

# Timestamp input for hihat
correctInput = False
while not correctInput:
    try:
        timestamp_input = float(input("Give timestamps for hihat:"))
        hihat_event["timestamp"].append(timestamp_input)
    except ValueError:
        correctInput = True

# Timestamp input for snare
correctInput = False
while not correctInput:
    try:
        timestamp_input = float(input("Give timestamps for snare:"))
        snare_event["timestamp"].append(timestamp_input)
    except ValueError:
        correctInput = True

# Timestamp input for kick
correctInput = False
while not correctInput:
    try:
        timestamp_input = float(input("Give timestamps for kick:"))
        kick_event["timestamp"].append(timestamp_input)
    except ValueError:
        correctInput = True


# fuction to play event
def event_handler(event):
    event["instrument"].play()


# stores all events into a list
events = [kick_event, hihat_event, snare_event]

# Creates a list of all timestamps from every event and sorts them
all_timestamps = []
for event in events:
    all_timestamps.extend(event["timestamp"])
all_timestamps.sort()

# stores current time in ms
current_time = time.time() * 1000

# Iterate through each timestamp and calculates time to sleep (in seconds) for each timestamp,
for timestamp in all_timestamps:
    time_to_sleep = (timestamp - current_time) / 1000.0
    if time_to_sleep > 0:
        time.sleep(time_to_sleep)
    # Iterate through each event and check if the current timestamp is present in the timestamps list
    for event in events:
        if timestamp in event["timestamp"]:
            event_name = event["instrumentname"]
            print(f"Current Time: {timestamp / 1000} seconds, Instrument: {event_name}")
            event_handler(event)
    # updates current_time to the current timestamp
    current_time = timestamp

time.sleep(1)
