import nedreader
import os
import glob
 
path = 'songs/'
for infile in glob.glob( os.path.join(path, '*.mp3') ):
    id3 = nedreader.Reader(infile)
    print "title: " + id3.getValue('title')
    print "artist: " + id3.getValue('performer')
    print "album: " + id3.getValue('album')
    print "year: " + id3.getValue('year') + '\n'