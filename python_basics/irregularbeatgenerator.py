import simpleaudio as sa
import time
import random
import os
from midiutil import MIDIFile

# Function to gather user input for BPM, measures, time signature, and sample choice
def customInput():
    # Bpm input
    try:
        bpm = float(input("What BPM do you want? \nYour choice:"))
    except ValueError:
        print("wrong input, BPM: 120")
        bpm = 120
    
    # Measures input
    try:
        measures = int(input("How many measures do you want? \nYour choice:"))
    except ValueError:
        print("wrong input, measures: 4")
        measures = 4

    # Timesignature input
    try:
        time_signature_str = input("What time signature do you want? \nYour choice:")
        time_signature_parts = time_signature_str.split('/')
        numerator = int(time_signature_parts[0])
        denominator = int(time_signature_parts[1])
    except (ValueError, IndexError):
        print("wrong input, timesignature: 4/4")
        numerator = 4
        denominator = 4

    # Filepaths options for the different samples
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

    # Prompts the user to choose from the sample options
    sample_choice = input("Which samples do you want? \n1) Acoustic\n2) Lofi\n3) Trap\nYour choice: ")
    if sample_choice not in ["1", "2", "3"]:
        print("wrong input, sample choice: 1")
        sample_choice = "1"

    # Retrieves the filepaths based on userinput
    hihat_path = sample_options[sample_choice]['hihat_path']
    snare_path = sample_options[sample_choice]['snare_path']
    kick_path = sample_options[sample_choice]['kick_path']
        
    return bpm, measures, numerator, denominator, hihat_path, snare_path, kick_path

# Function to load audio samples from file paths
def loadSamples(hihat_path, snare_path, kick_path):
    # Loads each samples based on file path
    hihat = sa.WaveObject.from_wave_file(hihat_path)
    snare = sa.WaveObject.from_wave_file(snare_path)
    kick = sa.WaveObject.from_wave_file(kick_path)
    return hihat, snare, kick

# Function to define tracks for different instruments (hihat, snare, kick)
def defineTracks(hihat, snare, kick):
    # Defines high_track dictionary
    high_track = { 
        "instrument": hihat,
        "instrumentname": "hihat",
        "noteDurations": [],
        "timestamps16th": [0],
        "timestampsMs": [],
        "velocity": 82,
        "midi_pitch": 41,
        "note_offset": 0
    }
    # defines mid_track dictionary, withrandom 1 or 2 quarter notes as snare offset
    snare_offset = random.choice([1, 2])
    mid_track = {
        "instrument": snare,
        "instrumentname": "snare",
        "noteDurations": [],
        # times 4 to account for 16th notes
        "timestamps16th": [snare_offset * 4],
        "timestampsMs": [],
        "velocity": 82,
        "midi_pitch": 38,
        "note_offset": snare_offset
    }

    # defines low_track dictionary
    low_track = {
        "instrument": kick,
        "instrumentname": "kick",
        "noteDurations": [],
        "timestamps16th": [0],
        "timestampsMs": [],
        "velocity": 82,
        "midi_pitch": 35,
        "note_offset": 0
    }

    # stores all tracks in tracks list
    tracks = [high_track, mid_track, low_track]

    return tracks

# Function to generate the base rhythm sequence
def baseRhythmGeneration(measures, numerator): #derived from Ciska's example
    # creates an empty list to store base sequence
    base_seq = []

    # Calculate the total number of beats based on measures and numerator
    num_beats = numerator * measures

    while num_beats:
        # Add 2's and 3's in a random manner
        if num_beats >= 3:
            dur = random.randint(2, 3)
            num_beats -= dur
            base_seq.append(dur)
        else:
            if num_beats == 2:
                base_seq.append(2)
                num_beats -= 2
            elif num_beats == 1:
                if base_seq[-1] == 2:
                    base_seq[-1] += 1  # Extend the last note with +1
                else:
                    base_seq[-1] -= 1  # Change the last note into a 2 and add a 2
                    base_seq.append(2)
                num_beats -= 1
    return base_seq

# Function to fill note durations for each instrument track
def noteDurationFiller(tracks, base_seq):
    for track in tracks:
        if track["instrumentname"] == "hihat":
            for note in base_seq * 4:
                # Fills the note durations of the hihat to be four times faster than those in the base sequence
                track["noteDurations"].append(note / 4)

        if track["instrumentname"] == "snare": 
            for note in base_seq:
                # Applies the base sequence to the snare's note durations
                track["noteDurations"].append(note)
            # Adjusts the final note by subtracting 1 or 2 beats based on the note offset.
            if track["note_offset"] == 1:
                track["noteDurations"][-1] -= 1
            elif track["note_offset"] == 2:
                track["noteDurations"][-1] -= 2

        if track["instrumentname"] == "kick":
            for note in base_seq * 2:
                # fills the note durations of the kick to be two times faster than those in the base sequence
                track["noteDurations"].append(note/2)

    return tracks

# Function to convert note durations to 16th note timestamps
def noteDurationToTimestamps16th(tracks):
    # Calculate timestamps in 16th notes for each track based on note durations (times 4 to account for 16th notes)
    for track in tracks:
        for noteDuration in track["noteDurations"]:
            track["timestamps16th"].append(track["timestamps16th"][-1] + noteDuration * 4)

    # removes same 16th timestamps as the snare from the kick
    for ts in tracks[1]["timestamps16th"]:
        if ts in tracks[2]["timestamps16th"]:
            tracks[2]["timestamps16th"].remove(ts)

    return tracks

# Function to convert 16th note timestamps to milliseconds
def timestamps16thToTimestampsMs(tracks, bpm):
    # Calculates sixteenth note duration in miliseconds
    sixteenthNoteDuration = (60/4) / bpm

    # Convert 16th note timestamps to milliseconds for each track
    for track in tracks:
        for timestamp16th in track["timestamps16th"]:
            track["timestampsMs"].append(timestamp16th * sixteenthNoteDuration)

    return tracks

# Function to create a sorted list of all timestamps in milliseconds
def allTimestampsList(tracks):
    # Creates an empty list to store all timestamps
    all_timestamps = []

    # fills the all_timestamps list with all the timestamps in ms from each track
    for track in tracks:
        all_timestamps.extend(track["timestampsMs"])
    
    # Sorts the all_timestamps list
    all_timestamps.sort()

    return all_timestamps

# Function to iterate through timestamps and play the beat
def iterateThroughTimestamps(tracks, all_timestamps): #derived from Ciska's example
    # Get the start time
    time_zero = time.time()

    # Create a dictionary to keep track of played timestamps
    played_timestamps = {ts: [] for ts in all_timestamps}

    # prints "♪ Playing Your Beat ♪" to indicate to the user that the beat is playing
    print("♪ Playing Your Beat ♪")

    while all_timestamps:
        now = time.time() - time_zero
        ts = all_timestamps[0]

        if now >= ts:
            # Find the corresponding timestamp and play it if it hasn't been played yet
            for track in tracks:
                if ts in track["timestampsMs"] and track["instrumentname"] not in played_timestamps[ts]:
                    # Find the corresponding instrument and play it
                    track_name = track["instrumentname"]
                    track["instrument"].play()
                    played_timestamps[ts].append(track_name)
            # Remove the processed timestamp from the list
            all_timestamps.pop(0)
        # Sleep briefly to avoid excessive CPU usage while waiting for the next timestamp
        time.sleep(0.001)

    # Print "Done playing your beat" to indicate to the user that the beat is done playing
    print("Done playing your beat")

# Function to convert note duration data to a MIDI file
def durationToMidi(tracks, bpm): #derived from Ciska's example
    # Create the MIDIfile object, to which we can add notes
    mf = MIDIFile(1)

    # Set name and tempo
    mf.addTrackName(0, 0, "Beat Sample Track")
    mf.addTempo(0, 0, bpm)

    # Adds the notes from each track to the MIDIFile
    for track in tracks:
        time = track["note_offset"]
        for noteDuration in track["noteDurations"]:
            mf.addNote(0, 9, track["midi_pitch"], time, noteDuration, track["velocity"])
            # increment time based on the duration of the added note
            time = time + noteDuration

    # Specifies the output path
    output = os.path.abspath("/Users/romanjameszeph/HKU/Jaar2/CSD2/python_basics/exports/beat.mid")

    # Writes midi file to output path
    with open(output,'wb') as output_file:
        mf.writeFile(output_file)

    # Prints output location of the created midifile
    print('Created midifile in:', output)

# The main function that orchestrates the beatmaking process
def main():
    print ("Welcome to Roman-James's Beatmaker!\n")

    onOff = True;
    saveToMidi = True;
    while onOff:
        bpm, measures, numerator, denominator, hihat_path, snare_path, kick_path = customInput()
        hihat, snare, kick = loadSamples(hihat_path, snare_path, kick_path)
        tracks = defineTracks(hihat, snare, kick)
        base_seq = baseRhythmGeneration(measures, numerator)
        tracks = noteDurationFiller(tracks, base_seq)
        tracks = noteDurationToTimestamps16th(tracks)
        tracks = timestamps16thToTimestampsMs(tracks, bpm)
        all_timestamps = allTimestampsList(tracks)
        iterateThroughTimestamps(tracks, all_timestamps)
        saveToMidi = input("Do you want to save your beat to midi? Press y and enter: ") == 'y'
        if saveToMidi:
            durationToMidi(tracks, bpm)
        else:
            print("Didn't save your beat to midi")
        onOff = input("Do you want to create another beat? Press y and enter: ") == 'y'
        print("Creating another beat \n")

    print("Quiting program...")

if __name__ == "__main__":
    main()