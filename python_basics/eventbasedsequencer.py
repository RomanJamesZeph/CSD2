import simpleaudio as sa
import time

hihat = sa.WaveObject.from_wave_file("/Users/romanjameszeph/HKU/Jaar2/CSD2/CSD_23-24/blok2a/assets/hihat.wav")
snare = sa.WaveObject.from_wave_file("/Users/romanjameszeph/HKU/Jaar2/CSD2/CSD_23-24/blok2a/assets/snare.wav")
kick = sa.WaveObject.from_wave_file("/Users/romanjameszeph/HKU/Jaar2/CSD2/CSD_23-24/blok2a/assets/kick.wav")

# hihat_event = {
#     'timestamp': 500,
#     'instrumentname': "hihat",
#     'instrument': hihat,
#     'velocity': 82,
#     'duration': 100
# }

# snare_event = {
#     'timestamp': 1000,
#     'instrumentname': "snare",
#     'instrument': snare,
#     'velocity': 82,
#     'duration': 100
# }

# kick_event = {
#     'timestamp': 0,
#     'instrumentname': "kick",
#     'instrument': kick,
#     'velocity': 82,
#     'duration': 100
# }

def getTimestamp(event):
    return event['timestamp']

events = [{'instrument': kick, 'timestamp': 0},
          {'instrument': snare, 'timestamp': 1000},
          {'instrument': hihat, 'timestamp': 500}]

events.sort(key=getTimestamp)

def handle_note_event(event):
    if(events.get('instrument') == kick):
        events[event].play()
        time.sleep(events[kick].get('timestamp'))
    if(events.get('instrument') == snare):
        events[event].play()
        time.sleep(events[snare].get('timestamp'))
    if(events.get('instrument') == hihat):
        events[event].play()
        time.sleep(events[event].get('timestamp'))

handle_note_event(kick)
handle_note_event(hihat)
handle_note_event(snare)

time.sleep(1)