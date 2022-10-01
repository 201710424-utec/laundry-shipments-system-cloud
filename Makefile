.PHONY: all

CXX = g++ -std=c++17
source_path = src/
assets_source = $(source_path)assets
objects = $(source_path)laundry-shipments-system.cpp

target_path = laundry-shipments-system/
assets_target = $(target_path)assets
target = $(target_path)laundry-shipments-system.exe

all: laundry-shipments-system

laundry-shipments-system: $(objects) $(target_path)
	$(CXX) $(objects) -o $(target)

$(target_path): $(assets_target)

$(assets_target):
	mkdir -p $(target_path)
	cp -r $(assets_source) $(assets_target)

clean:
	rm -fr $(target_path)
