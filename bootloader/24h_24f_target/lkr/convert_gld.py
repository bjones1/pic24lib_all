
#convert GLD files

import os, sys, string, re

def makeAppGld(infileName, bootGldName, vectorList, startAddr):
	
	#open input file
	try:
		infile = open(infileName,'r')
	except:
		print "Cannot open file ",infileName
		sys.exit(-1)
	
	#open output file
	try:
		outfile = open(bootGldName,'w')
	except:
		print "Cannot open file ",bootGldName
		sys.exit(-1)
	outfile.write("/* GLD file for PIC24 application using the Bully bootloader */\n");

	state = 0;
	for line in infile.readlines():
		words = line.split()
		if (state == 0):
			outfile.write(line)
			if (len(words) == 1 and words[0] == 'MEMORY'):
				state +=1
				continue
				
		if (state == 1):
			if (len(words) > 3 and words[0] == 'program'):
				s = '  j_ivt          : ORIGIN = 0x%x,   	   LENGTH = 0x200\n' % (startAddr-2)
				outfile.write(s)
				origin = words[5]
				origin = origin.replace(',','')
				origin = int(origin,16)
				length = int(words[8],16)
				progStart = startAddr + 0x200 -2;
				delta = progStart - origin
				newLength = length - delta
				s = '  program (xr)   : ORIGIN = 0x%x,         LENGTH = 0x%x\n' % (progStart,newLength)
				outfile.write(s);
				state +=1
				continue
			else:
				outfile.write(line)
				
		if (state == 2):
			outfile.write(line)
			if (len(words) == 1 and words[0] == '}'):
				state +=1
				#write out vector
				s = '__JIVT_BASE          = 0x%x;\n' % (startAddr-2)
				outfile.write(s);
				for vector in vectorList:
					s = "%s = 0x%x;\n" % ('J'+vector, startAddr)
					startAddr += 4
					outfile.write(s)
				continue
				
		if (state == 3):
			outfile.write(line)
			if (len(words) == 2 and words[0] == '}' and words[1] == '>reset'):
				state += 1
				continue
		
		if (state == 4):
			outfile.write(line)
			if (len(words) == 1 and words[0] == '*/'):
				state +=1
				outfile.write('.j_ivt __JIVT_BASE :\n')
				outfile.write(' {\n');
				outfile.write(' SHORT(0x02);  /* timeout value */\n');
				outfile.write(' SHORT(0x00);\n');
				for vector in vectorList:
					s = '    SHORT(DEFINED(%s) ? ABSOLUTE(%s) : \n' % (vector,vector)
					outfile.write(s)
					outfile.write('     ABSOLUTE(__DefaultInterrupt));\n');
					outfile.write('     SHORT(0x04);\n');
					s = '    SHORT(((DEFINED(%s) ? ABSOLUTE(%s) : \n' % (vector,vector)
					outfile.write(s)
					outfile.write("     ABSOLUTE(__DefaultInterrupt)) >> 16) & 0x7F);\n");
					outfile.write('     SHORT(0);\n')
					outfile.write('\n')
				outfile.write(' } >j_ivt\n');
					
				continue
		
		if (state == 5):
			outfile.write(line)
			if (len(words) >=2 and words[0] == '.ivt'):
				state += 1
				outfile.write('{\n')
				for vector in vectorList:
					s = "LONG(%s);\n" % ('J'+vector)
					outfile.write(s)
				continue

		if (state == 6):
			if (len(words) == 2 and words[0] == '}'):
				outfile.write(line)
				state += 1
				continue
			
				
		if (state == 7):
			outfile.write(line)
			if (len(words) >=2 and words[0] == '.aivt'):
				state += 1
				outfile.write('{\n')
				for vector in vectorList:
					s = "LONG(%s);\n" % ('J'+vector)
					outfile.write(s)
				continue
				
		if (state == 8):
			if (len(words) == 2 and words[0] == '}'):
				outfile.write(line)
				state += 1
				continue
				
		if (state == 9):
			outfile.write(line)	
	
	
	
			
						
		
		
		
	outfile.close()
	infile.close()	
	return
	

def makeBootGld(infileName, bootGldName, vectorList, startAddr):
	
	#open input file
	try:
		infile = open(infileName,'r')
	except:
		print "Cannot open file ",infileName
		sys.exit(-1)
	
	#open output file
	try:
		outfile = open(bootGldName,'w')
	except:
		print "Cannot open file ",bootGldName
		sys.exit(-1)
		
	outfile.write("/* GLD file for Bully bootloader firmware */\n");

	state = 0;
	for line in infile.readlines():
		words = line.split()
		if (state == 0):
			outfile.write(line)
			if (len(words) == 1 and words[0] == 'MEMORY'):
				state +=1
				continue
				
		if (state == 1):
			outfile.write(line)
			if (len(words) == 1 and words[0] == '}'):
				state +=1
				#write out vector

				for vector in vectorList:
					s = "%s = 0x%x;\n" % ('J'+vector, startAddr)
					startAddr += 4
					outfile.write(s)
				continue
				
		if (state == 2):
			outfile.write(line)
			if (len(words) >=2 and words[0] == '.ivt'):
				state += 1
				outfile.write('{\n')
				for vector in vectorList:
					s = "LONG(%s);\n" % ('J'+vector)
					outfile.write(s)
				continue
				
		if (state == 3):
			if (len(words) == 2 and words[0] == '}'):
				outfile.write(line)
				state += 1
				continue
		
		if (state == 4):
			outfile.write(line)
			if (len(words) >=2 and words[0] == '.aivt'):
				state += 1
				outfile.write('{\n')
				for vector in vectorList:
					s = "LONG(%s);\n" % ('J'+vector)
					outfile.write(s)
				continue
				
		if (state == 5):
			if (len(words) == 2 and words[0] == '}'):
				outfile.write(line)
				state += 1
				continue
				
		if (state == 6):
			outfile.write(line)
		
				
					
	
	outfile.close()
	infile.close()
	return
	

def parseGldFile(infileName, bootGldName, appGldName):

	
	#first read all vectors
	try:
		infile = open(infileName,'r')
	except:
		print "Cannot open file ",infileName
		sys.exit(-1)
	
	vectorList=[];
	
	state = 0;
	maptable = string.maketrans('()','  ')
	for line in infile.readlines():
		line = line.translate(maptable)
		words = line.split()
		if (state == 0 and len(words) >= 2):
			if (words[0] == '.ivt' and words[1] == '__IVT_BASE'):
				state = 1
				continue
		if (state == 1 and len(words) >= 2):
			if (words[0] == '.aivt'):
				break
			if (words[0] == 'LONG' and words[1] == 'DEFINED'):
				vectorList.append(words[2])
	
	infile.close()
	# now create the bootloader GLD file
	startAddr = 0xC02;
	makeBootGld(infileName, bootGldName, vectorList, startAddr)
	makeAppGld(infileName, appGldName, vectorList, startAddr)
	
	return
	
	
	
	
def convertDir(srcdir, dstdir):
	for infile in os.listdir(srcdir):
		(root,ext) = os.path.splitext(infile)
		if (ext == ".gld"):
			appfile = root + "_bootldr.gld"
			apppath = os.path.join(dstdir,appfile)
			srcpath = os.path.join(srcdir,infile)
			bootfile = infile;
			print "Converting: ",bootfile
			parseGldFile(srcpath,infile,apppath)

	

	
C30_homedir = "C:\Program Files (x86)\Microchip\MPLAB C30\support";

if (os.path.exists(C30_homedir) == False):
	C30_homedir = "C:\Program Files\Microchip\MPLAB C30\support";
	if (os.path.exists(C30_homedir) == False):
		print "Cannot determine Microchip C30 home directory, exiting.\n"
		exit(0);
		

dstdir = os.path.join("..","..","..","lkr");

tdir = 	os.path.join(C30_homedir,"PIC24H","gld");
convertDir(tdir, dstdir);

tdir = 	os.path.join(C30_homedir,"PIC24F","gld");
convertDir(tdir, dstdir);

tdir = 	os.path.join(C30_homedir,"dsPIC33F","gld");
convertDir(tdir, dstdir);

















#parseGldFile(sys.argv[1])


	