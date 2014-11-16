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

FRAMEWORKS = -framework Allegro-5.0 \
	-framework AllegroMain-5.0 \
	-framework AllegroFont-5.0 \
	-framework AllegroTTF-5.0

all:
	gcc $(FRAMEWORKS) $(INCLUDE) -o test allegro_temp.c