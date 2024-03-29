Brendan Bower

Designed for use on a Linux OS
Compilation: run "make" from command line

running: "./test" 

General Overview:
	This program mimics a podcast streaming software. The audio and video files are just text files for the purposes of this asisgnment. The user can search, add and remove podcasts from their playlist. The user can also "stream" the podcast.

Notes: There are memory leaks in this program. Almost all of the destructors are not implimented, though I plan to in the near future.

Classes:

Podcast (Entity / Container object):
	Contains Podcast meta-data as well as a collection of Episodes.
	
Episode (Entity):
	Contains Episode meta-data and content.
	
Search (Behaviour object): Virtual base class of all Search objects.
	H_Search (Behaviour object): Matches Episodes by the Podcast host.
	C_Search (Behaviour object): Matches Episodes by the Podcast category.
	HorC_Search (Behaviour object): Matches Episodes by the Podcast host or category.
	
Array (Container object):
	A simple (templated) data structure.
	
Podify (Control object):
	Stores Podcasts along with their Episodes, allows them to be queried.
	PodcastPlayer (Behaviour object): Determines how to play an Episode (either "audio" only, or "audio and
	video", both of which are simply text).
	AudioPlayer: Displays the audio of an Episode.
	VideoPlayer: Displays the audio of an Episode and some ASCII art which is loaded from a file at
	runtime.
	
View (View object):
	Collects user input and displays Podcasts, Episodes and other information.
	
Control (Control object):
	Manages the interactions of Podify, PodcastFactory, and View. Stores the Episode playlist.
	
TestControl (Control object):
	Test framework for Podify.
	
Tester:
	Provides some common test functionality.
