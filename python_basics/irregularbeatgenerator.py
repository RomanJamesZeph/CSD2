import simpleaudio as sa
import time
import random
import os
from midiutil import MIDIFile

def customInput():
    # bpm input
    try:
        bpm = float(input("Standard BPM is 100, leave empty to continue or type your own BPM"))
    except ValueError:
        bpm = 200
    
    # measures input
    try:
        measures = float(input("How many measures do you want?"))
    except ValueError:
        measures = 2

    # timesignature input
    try:
        time_signature_str = input("Enter the time signature (e.g., 4/4): ")
        time_signature_parts = time_signature_str.split('/')
        numerator = int(time_signature_parts[0])
        denominator = int(time_signature_parts[1])
    except (ValueError, IndexError):
        numerator = 4
        denominator = 4

    # samples input
    sample_options = {
        '1': {
            'hihat_path': "/Users/romanjameszeph/HKU/Jaar2/CSD2/python_basics/assets/acoustic_hat.wav",
            'snare_path': "/Users/romanjameszeph/HKU/Jaar2/CSD2/python_basics/assets/acoustic_snare.wav",
            'kick_path': "/Users/romanjameszeph/HKU/Jaar2/CSD2/python_basics/assets/acoustic_kick.wav"
        },
        '2': {
            'hihat_path': "/Users/romanjameszeph/HKU/Jaar2/CSD2/python_basics/assets/lofi_hat.wav",
            'snare_path': "/Users/romanjameszeph/HKU/Jaar2/CSD2/python_basics/assets/lofi_snare.wav",
            'kick_path': "/Users/romanjameszeph/HKU/Jaar2/CSD2/python_basics/assets/lofi_kick.wav"
        },
        '3': {
            'hihat_path': "/Users/romanjameszeph/HKU/Jaar2/CSD2/python_basics/assets/trap_hat.wav",
            'snare_path': "/Users/romanjameszeph/HKU/Jaar2/CSD2/python_basics/assets/trap_snare.wav",
            'kick_path': "/Users/romanjameszeph/HKU/Jaar2/CSD2/python_basics/assets/trap_kick.wav"
        }
    }

    # prompts the user to choose form the sample options
    user_input = ''
    while user_input not in sample_options:
        user_input = input("Pick an option:\n1) Acoustic\n2) Boombap\n3) Trap\nYour choice: ")

    # retrieves the sample paths based on userinput
    hihat_path = sample_options[user_input]['hihat_path']
    snare_path = sample_options[user_input]['snare_path']
    kick_path = sample_options[user_input]['kick_path']
        

    return bpm, measures, numerator, denominator, hihat_path, snare_path, kick_path

def loadSamples(hihat_path, snare_path, kick_path):
    hihat = sa.WaveObject.from_wave_file(hihat_path)
    snare = sa.WaveObject.from_wave_file(snare_path)
    kick = sa.WaveObject.from_wave_file(kick_path)
    return hihat, snare, kick

def defineTracks(hihat, snare, kick):
    high_track = {
        "noteDurations": [],
        "timestamps16th": [0.0],
        "timestampsMs": [],
        "instrumentname": "hihat",
        "instrument": hihat,
        "velocity": 82,
        "duration": 100,
        "midi_pitch": 41,
        "note_offset": 0
    }

    mid_track = {
        "noteDurations": [],
        "timestamps16th": [0.0],
        "timestampsMs": [],
        "instrumentname": "snare",
        "instrument": snare,
        "velocity": 82,
        "duration": 100,
        "midi_pitch": 38,
        "note_offset": 1
    }

    low_track = {
        "noteDurations": [],
        "timestamps16th": [0.0],
        "timestampsMs": [],
        "instrumentname": "kick",
        "instrument": kick,
        "velocity": 82,
        "duration": 100,
        "midi_pitch": 35,
        "note_offset": 0
    }

    # stores all tracks in events list
    events = [high_track, mid_track, low_track]

    return events

def rythmGeneration(events, measures, numerator, denominator):
    for event in events:
        # Adjust note durations based on the time signature
        num_pulses = numerator * measures
        while num_pulses:
            # Add 2's and 3's in a random manner
            if num_pulses >= 3:
                dur = random.randint(2, 3)
                num_pulses -= dur
                event["noteDurations"].append(dur)
            else:
                if num_pulses == 2:
                    event["noteDurations"].append(2)
                    num_pulses -= 2
                elif num_pulses == 1:
                    if event["noteDurations"][-1] == 2:
                        event["noteDurations"][-1] += 1  # Extend the last note with +1
                    else:
                        event["noteDurations"][-1] -= 1  # Change the last note into a 2 and add a 2
                        event["noteDurations"].append(2)
                    num_pulses -= 1

    for event in events:
        print(event["instrumentname"], "notedurations:")
        print(event["noteDurations"])
        print("\n")

    return events

def noteDurationToTimestamps16th(events):
    for event in events:
        for noteDuration in event["noteDurations"]:
            event["timestamps16th"].append(event["timestamps16th"][-1] + noteDuration * 4)
        event["timestamps16th"].pop(0)
        print(event["instrumentname"], "timestamps in 16th:")
        print(event["timestamps16th"])
    print("\n")
    return events

def timestamps16thToTimestampsMs(events, bpm):
    sixteenthNoteDuration = 15.0 / bpm
    for event in events:
        for timestamp16th in event["timestamps16th"]:
            event["timestampsMs"].append(timestamp16th * sixteenthNoteDuration)
        print(event["instrumentname"], "timestamps in ms")
        print(event["timestampsMs"])
    print("\n")
    return events

def allTimestampsList(events):
    all_timestamps = []
    for event in events:
        all_timestamps.extend(event["timestampsMs"])
    all_timestamps.sort()
    return all_timestamps

def iterateThroughTimestamps(events, all_timestamps):
    # Get the start time
    time_zero = time.time()

    # Create a dictionary to keep track of played events for each timestamp
    played_events = {ts: [] for ts in all_timestamps}

    while all_timestamps:
        now = time.time() - time_zero
        ts = all_timestamps[0]

        if now >= ts:
            # Find the corresponding event and play it if it hasn't been played yet
            for event in events:
                if ts in event["timestampsMs"] and event["instrumentname"] not in played_events[ts]:
                    event_name = event["instrumentname"]
                    # print(f"Current Time: {ts} seconds, Instrument: {event_name}")
                    event["instrument"].play()
                    played_events[ts].append(event_name)
            all_timestamps.pop(0)
        time.sleep(0.001)

def durationToMidi(events, bpm):
    # create the MIDIfile object, to which we can add notes
    mf = MIDIFile(1)

    track = 0
    channel = 9  # corresponds to channel 10 drums

    # set name and tempo
    time_beginning = 0
    mf.addTrackName(track, time_beginning, "Beat Sample Track")
    mf.addTempo(track, time_beginning, bpm)

    # add the notes for the different tracks
    for event in events:
        time = event["note_offset"]
        for noteDuration in event["noteDurations"]:
            mf.addNote(track, channel, event["midi_pitch"], time, noteDuration, event["velocity"])
            # increment time based on the duration of the added note
            time = time + noteDuration
    
    # specifies the output path
    output = os.path.abspath("/Users/romanjameszeph/HKU/Jaar2/CSD2/python_basics/exports/coolrythm.midi")

    with open(output,'wb') as output_file:
        mf.writeFile(output_file)

def main():
    onOff = True;
    while onOff:
        bpm, measures, numerator, denominator, hihat_path, snare_path, kick_path = customInput()
        hihat, snare, kick = loadSamples(hihat_path, snare_path, kick_path)
        events = defineTracks(hihat, snare, kick)
        events = rythmGeneration(events, measures, numerator, denominator)
        events = noteDurationToTimestamps16th(events)
        events = timestamps16thToTimestampsMs(events, bpm)
        all_timestamps = allTimestampsList(events)
        iterateThroughTimestamps(events, all_timestamps)
        durationToMidi(events, bpm)
        onOff = input("do you want to continue? Press y and enter: ") == 'y'

if __name__ == "__main__":
    main()