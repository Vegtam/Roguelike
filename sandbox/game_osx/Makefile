LIB_CODE = ../../src
INC_PATH = ../../inc
BIN_PATH = ../../bin
CPP_FLAGS = -std=c++11 -stdlib=libc++ -Wall -pedantic

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
	-I$(INC_PATH)

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
	$(LIB_CODE)/Image.cpp \
	$(LIB_CODE)/TileMap.cpp \
	$(LIB_CODE)/TileSet.cpp \
	$(LIB_CODE)/TitleView.cpp \
	$(LIB_CODE)/CreditsView.cpp \
	$(LIB_CODE)/WorldView.cpp \
	$(LIB_CODE)/Player.cpp \
	$(LIB_CODE)/Creature.cpp \
	$(LIB_CODE)/Object.cpp \
	$(LIB_CODE)/World.cpp \
	$(LIB_CODE)/Model.cpp \
	$(LIB_CODE)/BiomeTile.cpp \
	$(LIB_CODE)/Tile.cpp \
	$(LIB_CODE)/TextEntry.cpp \
	$(LIB_CODE)/CharacterCreationNameView.cpp \
	$(LIB_CODE)/Biome.cpp \
	$(LIB_CODE)/BiomeView.cpp \
	$(LIB_CODE)/RegionTile.cpp \
	$(LIB_CODE)/Random.cpp \
	$(LIB_CODE)/main.cpp \

game: $(LIB_SRC)
	clang++ $(CPP_FLAGS) $(FRAMEWORKS) $(INCLUDE) -o $(BIN_PATH)/game $(LIB_SRC)