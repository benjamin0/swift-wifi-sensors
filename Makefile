# Convenience Makefile.

.PHONY: help login temperature

define announce-begin
	@echo
	@echo "$1 ..."
	@echo
endef

define announce-end
	@echo
	@echo "$1"
	@echo
endef

help:
	@echo
	@echo "Helper for updating Photon devices @ Swift Navigation."
	@echo
	@echo "(Please read before using!)"
	@echo
	@echo "Please use \`make <target>' where <target> is one of"
	@echo "  help          to display this help message"
	@echo "  setup         to install dependencies"
	@echo "  temperature   to build/deploy thermometer firmware image"


setup:
	$(call announce-begin, "Logging into Particle")
	particle login

temperature:
	$(call announce-begin, "Deploying thermometer firmware image!")
	particle flash thermo0 src/TemperatureDS18B20.ino \
		src/OneWire.cpp src/OneWire.h \
		src/spark-dallas-temperature.cpp src/spark-dallas-temperature.h \
		src/SparkFunMAX17043.cpp src/SparkFunMAX17043.h
