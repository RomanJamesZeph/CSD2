import simpleaudio as sa

playback_amount = int(input("Hoe vaak wil je het geluid horen?"))

wave_obj = sa.WaveObject.from_wave_file("/Library/Audio/Samples/Sound Kits/cartoon/boing.wav")
for _ in range(playback_amount):
	play_obj = wave_obj.play()
	play_obj.wait_done()