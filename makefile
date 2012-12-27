CFLAGS = 
LIBS = 

% : %.cpp
	g++ -Wall -o $@ $< $(CFLAGS) $(LIBS)
