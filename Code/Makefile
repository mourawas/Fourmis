OUT = projet
CXX = g++
CXXFLAGS = -Wall -std=c++11
LINKING = `pkg-config --cflags gtkmm-3.0`
LDLIBS = `pkg-config --libs gtkmm-3.0`
OFILES = squarecell.o error_squarecell.o projet.o simulation.o fourmiliere.o fourmis.o nourriture.o message.o gui.o graphic.o

all: $(OUT)

gui.o: gui.cc gui.h simulation.h graphic.h
	$(CXX) $(CXXFLAGS) $(LINKING) -c $< -o $@ $(LINKING)

graphic.o: graphic.cc graphic.h
	$(CXX) $(CXXFLAGS) $(LINKING) -c $< -o $@ $(LINKING)

squarecell.o: squarecell.cc squarecell.h error_squarecell.h graphic.h
	$(CXX) $(CXXFLAGS) $(LINKING) -c $< -o $@ $(LINKING)

error_squarecell.o: error_squarecell.cc error_squarecell.h
	$(CXX) $(CXXFLAGS) $(LINKING) -c $< -o $@ $(LINKING)

projet.o: projet.cc simulation.h squarecell.h error_squarecell.h \
 graphic.h nourriture.h constantes.h message.h fourmiliere.h fourmis.h \
 gui.h
	$(CXX) $(CXXFLAGS) $(LINKING) -c $< -o $@ $(LINKING)

simulation.o: simulation.cc simulation.h squarecell.h \
 error_squarecell.h graphic.h nourriture.h constantes.h message.h \
 fourmiliere.h fourmis.h
	$(CXX) $(CXXFLAGS) $(LINKING) -c $< -o $@ $(LINKING)

fourmiliere.o: fourmiliere.cc fourmiliere.h squarecell.h \
 error_squarecell.h graphic.h fourmis.h message.h nourriture.h \
 constantes.h
	$(CXX) $(CXXFLAGS) $(LINKING) -c $< -o $@ $(LINKING)

fourmis.o: fourmis.cc fourmis.h error_squarecell.h \
 graphic.h message.h nourriture.h constantes.h
	$(CXX) $(CXXFLAGS) $(LINKING) -c $< -o $@ $(LINKING)

nourriture.o: nourriture.cc nourriture.h constantes.h message.h \
 squarecell.h error_squarecell.h graphic.h
	$(CXX) $(CXXFLAGS) $(LINKING) -c $< -o $@ $(LINKING)

message.o: message.cc message.h
	$(CXX) $(CXXFLAGS) $(LINKING) -c $< -o $@ $(LINKING)

$(OUT): $(OFILES)
	$(CXX) $(CXXFLAGS) $(LINKING) $(OFILES) -o $@ $(LDLIBS)

clean:
	@echo "Cleaning compilation files"
	@rm *.o $(OUT) *.cc~ *.h~
