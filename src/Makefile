#
include makedefs

PGM = uav

OBJS = main.o

LDFLAGS += -lmixr_models -lmixr_simulation -lmixr_terrain -lmixr_base -lJSBSim -lpthread 

all: edl $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

edl:
	cpp configs/config.epp > config.edl $(EPPFLAGS)

clean:
	-rm -f *.o
	-rm -f *.edl
	-rm -f $(PGM)
