LIB_CODE = ../..
CPP_FLAGS = -std=c++11 -stdlib=libc++ 

INCLUDE = -I/Library/Frameworks/Allegro-5.0.framework/Versions/Current/Headers \
	-I/Library/Frameworks/AllegroMain-5.0.framework/Versions/Current/Headers \
	-I/Library/Frameworks/AllegroAcodec-5.0.framework/Versions/Current/Headers \
	-I/Library/Frameworks/AllegroAudio-5.0.framework/Versions/Current/Headers \
	-I/Library/Frameworks/AllegroColor-5.0.framework/Versions/Current/Header \
	-I/Library/Frameworks/AllegroDialog-5.0.framework/Versions/Current/Headers \
	-I/Library/Frameworks/AllegroFont-5.0.framework/Versions/Current/Headers \
	-I/Library/Frameworks/AllegroImage-5.0.framework/Versions/Current/Headers \
	-I/Library/Frameworks/AllegroPhysfs-5.0.framework/Versions/Current/Headers \
	-I/Library/Frameworks/AllegroMemfile-5.0.framework/Versions/Current/Headers \
	-I/Library/Frameworks/AllegroPrimitives-5.0.framework/Versions/Current/Headers \
	-I/Library/Frameworks/AllegroTTF-5.0.framework/Versions/Current/Headers \
	-I$(LIB_CODE)

FRAMEWORKS = -framework Allegro-5.0 \
	-framework AllegroMain-5.0 \
	-framework AllegroFont-5.0 \
	-framework AllegroTTF-5.0 \
	-framework AllegroImage-5.0 \
	-framework AllegroPrimitives-5.0 \

LIB_SRC = $(LIB_CODE)/Allegro.cpp \
	$(LIB_CODE)/Display.cpp \
	$(LIB_CODE)/Font.cpp \
	$(LIB_CODE)/TextPane.cpp \

test: main.cpp $(LIB_SRC)
	clang++ $(CPP_FLAGS) $(FRAMEWORKS) $(INCLUDE) -o test main.cpp $(LIB_SRC)