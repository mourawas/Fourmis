# Definitions de macros

CXX     = g++
CXXFLAGS = -g -Wall -std=c++11
CXXFILES = squarecell.cc error_squarecell.cc projet.cc simulation.cc fourmiliere.cc fourmis.cc nourriture.cc message.cc
OFILES = $(CXXFILES:.cc=.o)

# Definition de la premiere regle

projet: $(OFILES)
	$(CXX) $(OFILES) -o projet

# Definitions de cibles particulieres

depend:
	@echo " *** MISE A JOUR DES DEPENDANCES ***"
	@(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	  $(CXX) -MM $(CXXFLAGS) $(CXXFILES) | \
	  egrep -v "/usr/include" \
	 ) >Makefile.new
	@mv Makefile.new Makefile

clean:
	@echo " *** EFFACE MODULES OBJET ET EXECUTABLE ***"
	@/bin/rm -f *.o *.x *.cc~ *.h~ projet

#
# -- Regles de dependances generees automatiquement
#
# DO NOT DELETE THIS LINE
squarecell.o: squarecell.cc squarecell.h error_squarecell.h
error_squarecell.o: error_squarecell.cc error_squarecell.h
projet.o: projet.cc simulation.h squarecell.h error_squarecell.h \
 nourriture.h constantes.h message.h fourmiliere.h fourmis.h
simulation.o: simulation.cc simulation.h squarecell.h error_squarecell.h \
 nourriture.h constantes.h message.h fourmiliere.h fourmis.h
fourmiliere.o: fourmiliere.cc fourmiliere.h squarecell.h \
 error_squarecell.h fourmis.h message.h nourriture.h constantes.h
fourmis.o: fourmis.cc fourmis.h squarecell.h error_squarecell.h message.h \
 nourriture.h constantes.h
nourriture.o: nourriture.cc nourriture.h constantes.h message.h \
 squarecell.h error_squarecell.h
message.o: message.cc message.h
