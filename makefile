DED_FLAGS=-Wall -Wextra -Weffc++ -Wcast-align -Wcast-qual -Iinclude -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-security -Wformat=2 -Wignored-qualifiers -Winit-self -Winline -Wlogical-op -Wmain -Wmissing-declarations -Wno-missing-field-initializers -Wmissing-include-dirs -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wredundant-decls -Wshadow -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wswitch-default -Wswitch-enum -Wtype-limits -Wundef -Wunreachable-code -Wwrite-strings -fexceptions -g -pipe -D_DEBUG -D_EJUDGE_CLIENT_SIDE -D_EJC
EXE_NAME=List
src_prefix=src/
build_prefix=Build/
#PATH=C:/Windows/System32/cmd.exe
#putsubstr
#variab

HUI = $(addprefix ${src_prefix}, main.cpp addrem.cpp dumps.cpp Tors.cpp insdel.cpp)
OBJ = $(addprefix ${build_prefix}, main.o addrem.o dumps.o Tors.o insdel.o)


all : $(EXE_NAME)

$(EXE_NAME): $(OBJ)
	@echo "[LD] Linking"
	@g++ $^ ${DED_FLAGS} -o $(EXE_NAME)

${build_prefix}%.o: $(src_prefix)%.cpp
	@echo "[CXX] $@"
	@g++ -c $^ ${DED_FLAGS} -o $@

clean:
	rm -rf *.o *.exe